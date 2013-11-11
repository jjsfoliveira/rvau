#include "BlackJack.h"



using namespace std;

BlackJack::BlackJack(void)
{

	multiPattern = "Data/multi/marker.dat";
	playingCards = stack<Card>();
	patts = vector<Pattern>();
	patts = vector<Pattern>();
	buttonPick.push_back(0);
	buttonPick.push_back(0);
	buttonPick.push_back(0);


	dispenser = Model3D("assets/dispenser.obj");
	button = Model3D("assets/button.obj");
	cout << "init dispenser" << endl;
	dispenser.load();
	cout << "init button" << endl;
	button.load();
	cout << "init patts" << endl;
	initPatts();
}


BlackJack::~BlackJack(void)
{
}

void BlackJack::loadCards(){

	vector<Card> Cards = vector<Card>();

	pixmap.readBMPFile("cards/2_of_clubs.bmp");
	pixmap.setTexture(3);
	Cards.push_back(Card(2,3));

	pixmap.readBMPFile("cards/2_of_diamonds.bmp");
	pixmap.setTexture(4);
	Cards.push_back(Card(2,4));
	
	pixmap.readBMPFile("cards/2_of_hearts.bmp");
	pixmap.setTexture(5);
	Cards.push_back(Card(2,5));

	pixmap.readBMPFile("cards/2_of_spades.bmp");
	pixmap.setTexture(6);
	Cards.push_back(Card(2,6));


	pixmap.readBMPFile("cards/3_of_clubs.bmp");
	pixmap.setTexture(7);
	Cards.push_back(Card(3,7));

	pixmap.readBMPFile("cards/3_of_diamonds.bmp");
	pixmap.setTexture(8);
	Cards.push_back(Card(3,8));
	
	pixmap.readBMPFile("cards/3_of_hearts.bmp");
	pixmap.setTexture(9);
	Cards.push_back(Card(3,9));

	pixmap.readBMPFile("cards/3_of_spades.bmp");
	pixmap.setTexture(10);
	Cards.push_back(Card(3,10));


	pixmap.readBMPFile("cards/4_of_clubs.bmp");
	pixmap.setTexture(11);
	Cards.push_back(Card(4,11));

	pixmap.readBMPFile("cards/4_of_diamonds.bmp");
	pixmap.setTexture(12);
	Cards.push_back(Card(4,12));
	
	pixmap.readBMPFile("cards/4_of_hearts.bmp");
	pixmap.setTexture(13);
	Cards.push_back(Card(4,13));

	pixmap.readBMPFile("cards/4_of_spades.bmp");
	pixmap.setTexture(14);
	Cards.push_back(Card(4,14));

	pixmap.readBMPFile("cards/5_of_clubs.bmp");
	pixmap.setTexture(15);
	Cards.push_back(Card(5,15));

	pixmap.readBMPFile("cards/5_of_diamonds.bmp");
	pixmap.setTexture(16);
	Cards.push_back(Card(5,16));
	
	pixmap.readBMPFile("cards/5_of_hearts.bmp");
	pixmap.setTexture(17);
	Cards.push_back(Card(5,17));

	pixmap.readBMPFile("cards/5_of_spades.bmp");
	pixmap.setTexture(18);
	Cards.push_back(Card(5,18));


	pixmap.readBMPFile("cards/6_of_clubs.bmp");
	pixmap.setTexture(19);
	Cards.push_back(Card(6,19));

	pixmap.readBMPFile("cards/6_of_diamonds.bmp");
	pixmap.setTexture(20);
	Cards.push_back(Card(6,20));
	
	pixmap.readBMPFile("cards/6_of_hearts.bmp");
	pixmap.setTexture(21);
	Cards.push_back(Card(6,21));

	pixmap.readBMPFile("cards/6_of_spades.bmp");
	pixmap.setTexture(22);
	Cards.push_back(Card(6,22));

	
	pixmap.readBMPFile("cards/7_of_clubs.bmp");
	pixmap.setTexture(23);
	Cards.push_back(Card(7,23));

	pixmap.readBMPFile("cards/7_of_diamonds.bmp");
	pixmap.setTexture(24);
	Cards.push_back(Card(7,24));
	
	pixmap.readBMPFile("cards/7_of_hearts.bmp");
	pixmap.setTexture(25);
	Cards.push_back(Card(7,25));

	pixmap.readBMPFile("cards/7_of_spades.bmp");
	pixmap.setTexture(26);
	Cards.push_back(Card(7,26));


	pixmap.readBMPFile("cards/8_of_clubs.bmp");
	pixmap.setTexture(27);
	Cards.push_back(Card(8,27));

	pixmap.readBMPFile("cards/8_of_diamonds.bmp");
	pixmap.setTexture(28);
	Cards.push_back(Card(8,28));
	
	pixmap.readBMPFile("cards/8_of_hearts.bmp");
	pixmap.setTexture(29);
	Cards.push_back(Card(8,29));

	pixmap.readBMPFile("cards/8_of_spades.bmp");
	pixmap.setTexture(30);
	Cards.push_back(Card(8,30));


	pixmap.readBMPFile("cards/9_of_clubs.bmp");
	pixmap.setTexture(31);
	Cards.push_back(Card(9,31));

	pixmap.readBMPFile("cards/9_of_diamonds.bmp");
	pixmap.setTexture(32);
	Cards.push_back(Card(9,32));
	
	pixmap.readBMPFile("cards/9_of_hearts.bmp");
	pixmap.setTexture(33);
	Cards.push_back(Card(9,33));

	pixmap.readBMPFile("cards/9_of_spades.bmp");
	pixmap.setTexture(34);
	Cards.push_back(Card(9,34));

		
	pixmap.readBMPFile("cards/10_of_clubs.bmp");
	pixmap.setTexture(35);
	Cards.push_back(Card(10,35));

	pixmap.readBMPFile("cards/10_of_diamonds.bmp");
	pixmap.setTexture(36);
	Cards.push_back(Card(10,36));
	
	pixmap.readBMPFile("cards/10_of_hearts.bmp");
	pixmap.setTexture(37);
	Cards.push_back(Card(10,37));

	pixmap.readBMPFile("cards/10_of_spades.bmp");
	pixmap.setTexture(38);
	Cards.push_back(Card(10,38));

		
	pixmap.readBMPFile("cards/ace_of_clubs.bmp");
	pixmap.setTexture(39);
	Cards.push_back(Card(1,39));

	pixmap.readBMPFile("cards/ace_of_diamonds.bmp");
	pixmap.setTexture(40);
	Cards.push_back(Card(1,40));
	
	pixmap.readBMPFile("cards/ace_of_hearts.bmp");
	pixmap.setTexture(41);
	Cards.push_back(Card(1,41));

	pixmap.readBMPFile("cards/ace_of_spades.bmp");
	pixmap.setTexture(42);
	Cards.push_back(Card(1,42));


	pixmap.readBMPFile("cards/jacks_of_clubs2.bmp");
	pixmap.setTexture(43);
	Cards.push_back(Card(10,43));

	pixmap.readBMPFile("cards/jacks_of_diamonds2.bmp");
	pixmap.setTexture(44);
	Cards.push_back(Card(10,44));
	
	pixmap.readBMPFile("cards/jacks_of_hearts2.bmp");
	pixmap.setTexture(45);
	Cards.push_back(Card(10,45));

	pixmap.readBMPFile("cards/jacks_of_spades2.bmp");
	pixmap.setTexture(46);
	Cards.push_back(Card(10,46));

	
	pixmap.readBMPFile("cards/king_of_clubs2.bmp");
	pixmap.setTexture(47);
	Cards.push_back(Card(10,47));

	pixmap.readBMPFile("cards/king_of_diamonds2.bmp");
	pixmap.setTexture(48);
	Cards.push_back(Card(10,48));
	
	pixmap.readBMPFile("cards/king_of_hearts2.bmp");
	pixmap.setTexture(49);
	Cards.push_back(Card(10,49));

	pixmap.readBMPFile("cards/king_of_spades2.bmp");
	pixmap.setTexture(50);
	Cards.push_back(Card(10,50));


	
	pixmap.readBMPFile("cards/queen_of_clubs2.bmp");
	pixmap.setTexture(51);
	Cards.push_back(Card(10,51));

	pixmap.readBMPFile("cards/queen_of_diamonds2.bmp");
	pixmap.setTexture(52);
	Cards.push_back(Card(10,52));
	
	pixmap.readBMPFile("cards/queen_of_hearts2.bmp");
	pixmap.setTexture(53);
	Cards.push_back(Card(10,53));

	pixmap.readBMPFile("cards/queen_of_spades2.bmp");
	pixmap.setTexture(54);
	Cards.push_back(Card(10,54));

	pixmap.readBMPFile("cards/cardback.bmp");
	pixmap.setTexture(55);

	while(!Cards.empty()){
		srand (time(NULL));
		int random = rand()%Cards.size();
		playingCards.push(Cards[random]);
		Cards.erase(Cards.begin()+random);
	}
}


void BlackJack::initGame(){
	
	Card c = playingCards.top();
	
	vector<double> r;
	r = posDiferPatterns(0, 1);
	double rx = r[0];
	double ry = r[1];
	double rz = r[2];
	c.initCard_1(rx, ry, rz, 0);

	packDiller.push_back(c);
	playingCards.pop();

	c = playingCards.top();
	c.turnCard = false;
	packDiller.push_back(c);
	playingCards.pop();

	
	packPlayer.push_back(playingCards.top());
	playingCards.pop();

	packPlayer.push_back(playingCards.top());
	playingCards.pop();
}

void BlackJack::resetGame(){
	for(unsigned int i = 0; i < packDiller.size(); i++){
		playingCards.push(packDiller[i]);
	}
	packDiller.clear();

	for(unsigned int i = 0; i < packPlayer.size(); i++){
		playingCards.push(packPlayer[i]);
	}
	packPlayer.clear();
}

void BlackJack::giveCardP(){
	Card c = playingCards.top();
	vector<double> r;
	r = posDiferPatterns(3, 1);
	double rx = r[0];
	double ry = r[1];
	double rz = r[2];
	c.initCard_1(rx, ry, rz, packPlayer.size());
	packPlayer.push_back(c);
	playingCards.pop();
}

void BlackJack::giveCardD(){

	if(packDiller.size()==2 && !(packDiller[1].turnCard) ){
		packDiller[1].turnCard = true;
		return;
	}
	Card c = playingCards.top();
	vector<double> r;
	r = posDiferPatterns(0, 1);
	double rx = r[0];
	double ry = r[1];
	double rz = r[2];
	c.initCard_1(rx, ry, rz, packDiller.size());
	packDiller.push_back(c);
	playingCards.pop();
}


void BlackJack::drawPackDiller(){
	glPushMatrix();
	glTranslatef(0,0.0,3.0);
	for(int i = 0; i < packDiller.size(); i++){
		if(packDiller[i].st != WAIT){
			glPushMatrix();
			glTranslatef(packDiller[i].x,packDiller[i].y,packDiller[i].z);
			glRotated(packDiller[i].rot_y,0.0,1.0,0.0);
			glTranslated(-Card::comp/2, 0, 0);
			packDiller[i].drawCard(Card::comp);
			glPopMatrix();
		}
	}
	glPopMatrix();
	
}




void BlackJack::drawPackPlayer(){
	glPushMatrix();
	glTranslatef(0,0.0,3.0);
	for(int i = 0; i < packPlayer.size(); i++){
		if(packPlayer[i].st != WAIT){
			glPushMatrix();
			glTranslatef(packPlayer[i].x,packPlayer[i].y,packPlayer[i].z);
			glRotated(packPlayer[i].rot_y,0.0,1.0,0.0);
			glTranslated(-Card::comp/2, 0, 0);
			packPlayer[i].drawCard(Card::comp);
			glPopMatrix();
		}
	}
	glPopMatrix();
}






void  BlackJack::draw_aux( double trans1[3][4], double trans2[3][4], int mode )
{

	double    gl_para[16];
	GLfloat   mat_ambient[]     = {0.0, 0.0, 1.0, 1.0};
	GLfloat   mat_ambient1[]    = {1.0, 0.0, 0.0, 1.0};
	GLfloat   mat_flash[]       = {0.0, 0.0, 1.0, 1.0};
	GLfloat   mat_flash1[]      = {1.0, 0.0, 0.0, 1.0};
	GLfloat   mat_flash_shiny[] = {50.0};
	GLfloat   mat_flash_shiny1[]= {50.0};
	GLfloat   light_position[]  = {100.0,-200.0,200.0,0.0};
	GLfloat   ambi[]            = {0.1, 0.1, 0.1, 0.1};
	GLfloat   lightZeroColor[]  = {0.9, 0.9, 0.9, 0.1};

	argDrawMode3D();
	argDraw3dCamera( 0, 0 );
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glMatrixMode(GL_MODELVIEW);
	argConvGlpara(trans1, gl_para);
	glLoadMatrixd( gl_para );
	argConvGlpara(trans2, gl_para);
	glMultMatrixd( gl_para );

	if( mode == 0 ) {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_flash);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_flash_shiny);	
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	}
	else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_flash1);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_flash_shiny1);	
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	}
	glMatrixMode(GL_MODELVIEW);
	GLUquadricObj *quadratic;
	glPushMatrix();
	glScalef(1.5f,1.5f,1.5f);
	button.render();
	glPopMatrix();
	glDisable( GL_LIGHTING );

	glDisable( GL_DEPTH_TEST );
	
}


void BlackJack::drawButton(){
	for( unsigned int i = 0; i < config->marker_num; i++ ) {
		if( config->marker[i].visible >= 0 )
		{
			buttonPick[i] = 0;
			draw_aux( config->trans, config->marker[i].trans, 0 );
		}
		else     
		{
			buttonPick[i] += 1;
			//cout << buttonPick[i]<< endl;
			draw_aux( config->trans, config->marker[i].trans, 1 );
		}
		if(buttonPick[i] > 20)
		{
			cout << "Butao " << i << " foi carregado" << endl;
			buttonPick[i] = 0;
			switch (i)
			{
			case 1:
				pickButton1();
				break;
			case 2:
				pickButton2();
				break;
			case 3:
				pickButton3();
				break;
			default:
				break;
			}
		}
	}
}

void BlackJack::pickButton1()
{


}
void BlackJack::pickButton2()
{


}
void BlackJack::pickButton3()
{


}

vector<Pattern>& BlackJack::getPatts(){
	return patts;
}

void BlackJack::initPatts(){
	
	//patterns diller

	patts.push_back(Pattern("Data/patt.hiro", 80.0, 0.0,0.0, "simple"));

	index_diller = 0;
	//patterns dispenser
	patts.push_back(Pattern("Data/patt.b", 40.0, 0.0,0.0, "simple"));
	index_dispenser = 1;
	//patterns for buttons
	patts.push_back(Pattern("Data/multi/marker.dat", 40.0, 0.0,0.0, "multi"));
	index_dispenser = 2;
	//patterns for player
	patts.push_back(Pattern("Data/patt.kanji", 80.0, 0.0,0.0, "simple"));

}


void BlackJack::drawDispenser(){
	glPushMatrix();
	glScalef(45.f,45.f,45.f);
	dispenser.render();
	//glutSolidCube(25);
	glPopMatrix();
}


vector<double> BlackJack::posDiferPatterns(int marker1, int marker2){

	double wmat1[3][4], wmat2[3][4];

	arUtilMatInv(patts[marker1].trans, wmat1);
    arUtilMatMul(wmat1, patts[marker2].trans, wmat2);

	vector<double> r;
	r.push_back(wmat2[0][3]);
	r.push_back(wmat2[1][3]);
	r.push_back(wmat2[2][3]);
	return r;
}

int BlackJack::scorePlayer(){
	int s = 0;
	for(int i = 0; i < packPlayer.size(); i++){
		if(packPlayer[i].getScore() == 11){
			if(s > 10){
				s=s+1;
			}else{
				s=s+11;
			}
		}else{
			s = s + packPlayer[i].getScore();
		}
	}
	return s;
}
int BlackJack::scoreDiller(){

	int s = 0;
	for(int i = 0; i < packDiller.size(); i++){
		if(packDiller[i].getScore() == 11){
			if(s > 10){
				s=s+1;
			}else{
				s=s+11;
			}
		}else{
			s = s + packDiller[i].getScore();
		}
	}
	return s;
}


