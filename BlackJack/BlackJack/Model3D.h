#include <map>

#include <vector>
#include "tiny_obj_loader.hpp"
#include <iostream>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace tinyobj;
using namespace std;



struct Vec {
	double x;
	double y;
	double z;
	Vec(double x=0.0,double y=0.0,double z=0.0) {
		this->x=x;this->y=y;this->z=z;
	}
};

struct Triangle {
	Vec vertex[3];
	Vec normal[3];
	Vec uvw[3];
	string material;
};

struct Material {
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float transmittance[4];
	float emission[4];
	float shininess[1];
	Material() {
		ambient[0]  = 0.7;
		ambient[1]  = 0.7;
		ambient[2]  = 0.7;
		ambient[3]  = 1.0;
		diffuse[0]  = 0.9;
		diffuse[1]  = 0.9;
		diffuse[2]  = 0.9;
		diffuse[3]  = 1.0;
		specular[0]  = 0.3;
		specular[1]  = 0.3;
		specular[2]  = 0.3;
		specular[3]  = 1.0;
		shininess[0] = 0.5;
	}
};

class Model3D
{
private:
	map<string,Material> materials;

	vector<Triangle> triangles;
	vector<tinyobj::shape_t> shapes;
	string lastUsed;

public:
	Model3D(){}
	Model3D(string file);
	~Model3D(void);
	void addMaterial(string name, Material m);

	void load();
	void applyMaterial(string name);
	void addMaterial(Material m);
	void render();
};

