#include "Model3D.h"



Model3D::Model3D(string filename)
{
	//string filename = "assets/dispenser.obj";


	string folder="";
	size_t lastSlash=filename.find_last_of('/');
	if (lastSlash!=string::npos) {
		folder=filename.substr(0,lastSlash+1);
	}
	string err = tinyobj::LoadObj(shapes, filename.c_str(), folder.c_str());

	if (!err.empty()) {
		cout << err << endl;
		int a;
		cin >> a;
		exit(1);
	}

}


Model3D::~Model3D(void)
{
}


void Model3D::addMaterial(Material m) {
	materials["default"]=m;
}

void Model3D::addMaterial(string name, Material m)
{
	materials[name]=m;
}

void Model3D::load(){

	for (size_t i = 0; i < shapes.size(); i++) {
		Material mat;
		for (int j=0;j<3;++j) {
			mat.ambient[j]=shapes[i].material.ambient[j];
			mat.diffuse[j]=shapes[i].material.diffuse[j];
			mat.specular[j]=shapes[i].material.specular[j];
			mat.emission[j]=shapes[i].material.emission[j];
			mat.transmittance[j]=shapes[i].material.transmittance[j];
		}
		mat.ambient[3]=1.0f;
		mat.diffuse[3]=1.0f;
		mat.specular[3]=1.0f;
		mat.emission[3]=1.0f;
		mat.transmittance[3]=1.0f;
		mat.shininess[0]=shapes[i].material.shininess;

		addMaterial(shapes[i].material.name,mat);
		vector<float> positions = shapes[i].mesh.positions;
		vector<float> normals   = shapes[i].mesh.normals;
		vector<float> uvws       = shapes[i].mesh.texcoords;
		vector<unsigned int> indices   = shapes[i].mesh.indices;
		size_t numNorm = normals.size()/3;
		size_t numFaces = indices.size()/3;
		size_t numUvs = uvws.size()/2;
		for (size_t j=0;j<numFaces;++j) {
			Triangle t;
			t.material=shapes[i].material.name;
			for (size_t k=0;k<3;++k) {
				size_t index = indices[j*3+k];
				if (index<numNorm) {
					t.normal[k].x=normals[index*3+0];
					t.normal[k].y=normals[index*3+1];
					t.normal[k].z=normals[index*3+2];
				}
				else {
					t.normal[k]=Vec(0.0,0.0,1.0);
				}
				if (index<numUvs) {
					t.uvw[k].x=uvws[index*2+0];
					t.uvw[k].y=uvws[index*2+1];
				}
				else {
					t.uvw[k]=Vec(0.0,0.0,0.0);
				}
				t.vertex[k].x=positions[index*3+0];
				t.vertex[k].y=positions[index*3+1];
				t.vertex[k].z=positions[index*3+2];
			}
			triangles.push_back(t);
		}
	}
}

void Model3D::applyMaterial(string name) {
	if (name=="") {name="default";}
	if (name==lastUsed) {return;}
	lastUsed=name;
	Material mat = materials[name];
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat.ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat.diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat.specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat.shininess);
}


void Model3D::render(){
	lastUsed="";
	for (size_t i=0;i<triangles.size();++i) {
		applyMaterial(triangles[i].material);
		glBegin(GL_TRIANGLES);
		for (int j=0;j<3;++j) {
			glTexCoord2f(triangles[i].uvw[j].x,triangles[i].uvw[j].y);
			glNormal3f(triangles[i].normal[j].x,triangles[i].normal[j].y,triangles[i].normal[j].z);
			glVertex3f(triangles[i].vertex[j].x,triangles[i].vertex[j].y,triangles[i].vertex[j].z);
		}
		glEnd();
	}
}