#include "BlackJack.h"


BlackJack::BlackJack(void)
{
	playingCards = stack<Card>();
	patts = vector<Pattern>();
	packPlayer = vector<Card>();
	packDiller = vector<Card>();
	patts = vector<Pattern>();
	dispenser.loadDispenser();
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

	while(!Cards.empty()){
		srand (time(NULL));
		int random = rand()%Cards.size();
		playingCards.push(Cards[random]);
		Cards.erase(Cards.begin()+random);
	}
}


void BlackJack::initGame(){
	
	Card c = playingCards.top();
	double *r;
	printf("%i", Card::n_iterations);
	r = posDiferPatterns(0, 1);
	double rx = *r;
	double ry = *(r+1);
	double rz = *(r+2);


	c.x = *r;
	c.y=*(r+1);
	c.z=*(r+2);
	c.st = MOVE;
	c.delta_x = *r/Card::n_iterations;
	c.delta_y = *(r+1)/Card::n_iterations;
	c.delta_z = *(r+2)/Card::n_iterations;
	packDiller.push_back(c);
	playingCards.pop();


	packDiller.push_back(playingCards.top());
	playingCards.pop();

	
	packPlayer.push_back(playingCards.top());
	playingCards.pop();

	packPlayer.push_back(playingCards.top());
	playingCards.pop();
}

void BlackJack::resetGame(){
	for(int i = 0; i < packDiller.size(); i++){
		playingCards.push(packDiller[i]);
	}
	packDiller.clear();

	for(int i = 0; i < packPlayer.size(); i++){
		playingCards.push(packPlayer[i]);
	}
	packPlayer.clear();
}

void BlackJack::giveCardP(){

	packPlayer.push_back(playingCards.top());
	playingCards.pop();
}

void BlackJack::giveCardD(){
	packDiller.push_back(playingCards.top());
	playingCards.pop();
}


void BlackJack::drawPackDiller(){
	glPushMatrix();
	glTranslatef(0,0.0,3.0);
	for(int i = 0; i < packDiller.size(); i++){
		if(packDiller[i].st != WAIT){
			glPushMatrix();
			glTranslatef(packDiller[i].x,packDiller[i].y,packDiller[i].z);
			packDiller[i].drawCard(comp);
			glPopMatrix();
		}
	}
	glPopMatrix();
	
}




void BlackJack::drawPackPlayer(){

}

vector<Pattern>& BlackJack::getPatts(){
	return patts;
}

void BlackJack::initPatts(){
	
	//patterns diller
	patts.push_back(Pattern("Data/patt.hiro", 80.0, -30.0,0.0));
	index_diller = 0;
	//patterns dispenser
	patts.push_back(Pattern("Data/patt.b", 40.0, 0.0,0.0));
	index_dispenser = 1;
}

void BlackJack::drawDispenser(){
	glPushMatrix();
	glScalef(45.f,45.f,45.f);
	dispenser.render();
	glPopMatrix();
}

double* BlackJack::posDiferPatterns(int marker1, int marker2){
	double wmat1[3][4], wmat2[3][4];

	arUtilMatInv(patts[marker1].trans, wmat1);
    arUtilMatMul(wmat1, patts[marker2].trans, wmat2);

	double r[3];
	r[0] = wmat2[0][3];
	r[1] = wmat2[1][3];
	r[2] = wmat2[2][3];

	printf("t- %f, tt- %f, ttt- %f", r[0], r[1], r[2]);
	return r;
}
