#include "BlackJack.h"


BlackJack::BlackJack(void)
{
	playingCards = vector<Card>();
	x_init = -30;
}


BlackJack::~BlackJack(void)
{
}

void BlackJack::loadCards(){

	pixmap.readBMPFile("cards/2_of_clubs.bmp");
	pixmap.setTexture(3);
	playingCards.push_back(Card(2,3));

	pixmap.readBMPFile("cards/2_of_diamonds.bmp");
	pixmap.setTexture(4);
	playingCards.push_back(Card(2,4));
	
	pixmap.readBMPFile("cards/2_of_hearts.bmp");
	pixmap.setTexture(5);
	playingCards.push_back(Card(2,5));

	pixmap.readBMPFile("cards/2_of_spades.bmp");
	pixmap.setTexture(6);
	playingCards.push_back(Card(2,6));


	pixmap.readBMPFile("cards/3_of_clubs.bmp");
	pixmap.setTexture(7);
	playingCards.push_back(Card(3,7));

	pixmap.readBMPFile("cards/3_of_diamonds.bmp");
	pixmap.setTexture(8);
	playingCards.push_back(Card(3,8));
	
	pixmap.readBMPFile("cards/3_of_hearts.bmp");
	pixmap.setTexture(9);
	playingCards.push_back(Card(3,9));

	pixmap.readBMPFile("cards/3_of_spades.bmp");
	pixmap.setTexture(10);
	playingCards.push_back(Card(3,10));


	pixmap.readBMPFile("cards/4_of_clubs.bmp");
	pixmap.setTexture(11);
	playingCards.push_back(Card(4,11));

	pixmap.readBMPFile("cards/4_of_diamonds.bmp");
	pixmap.setTexture(12);
	playingCards.push_back(Card(4,12));
	
	pixmap.readBMPFile("cards/4_of_hearts.bmp");
	pixmap.setTexture(13);
	playingCards.push_back(Card(4,13));

	pixmap.readBMPFile("cards/4_of_spades.bmp");
	pixmap.setTexture(14);
	playingCards.push_back(Card(4,14));

	pixmap.readBMPFile("cards/5_of_clubs.bmp");
	pixmap.setTexture(15);
	playingCards.push_back(Card(5,15));

	pixmap.readBMPFile("cards/5_of_diamonds.bmp");
	pixmap.setTexture(16);
	playingCards.push_back(Card(5,16));
	
	pixmap.readBMPFile("cards/5_of_hearts.bmp");
	pixmap.setTexture(17);
	playingCards.push_back(Card(5,17));

	pixmap.readBMPFile("cards/5_of_spades.bmp");
	pixmap.setTexture(18);
	playingCards.push_back(Card(5,18));


	pixmap.readBMPFile("cards/6_of_clubs.bmp");
	pixmap.setTexture(19);
	playingCards.push_back(Card(6,19));

	pixmap.readBMPFile("cards/6_of_diamonds.bmp");
	pixmap.setTexture(20);
	playingCards.push_back(Card(6,20));
	
	pixmap.readBMPFile("cards/6_of_hearts.bmp");
	pixmap.setTexture(21);
	playingCards.push_back(Card(6,21));

	pixmap.readBMPFile("cards/6_of_spades.bmp");
	pixmap.setTexture(22);
	playingCards.push_back(Card(6,22));

	
	pixmap.readBMPFile("cards/7_of_clubs.bmp");
	pixmap.setTexture(23);
	playingCards.push_back(Card(7,23));

	pixmap.readBMPFile("cards/7_of_diamonds.bmp");
	pixmap.setTexture(24);
	playingCards.push_back(Card(7,24));
	
	pixmap.readBMPFile("cards/7_of_hearts.bmp");
	pixmap.setTexture(25);
	playingCards.push_back(Card(7,25));

	pixmap.readBMPFile("cards/7_of_spades.bmp");
	pixmap.setTexture(26);
	playingCards.push_back(Card(7,26));


	pixmap.readBMPFile("cards/8_of_clubs.bmp");
	pixmap.setTexture(27);
	playingCards.push_back(Card(8,27));

	pixmap.readBMPFile("cards/8_of_diamonds.bmp");
	pixmap.setTexture(28);
	playingCards.push_back(Card(8,28));
	
	pixmap.readBMPFile("cards/8_of_hearts.bmp");
	pixmap.setTexture(29);
	playingCards.push_back(Card(8,29));

	pixmap.readBMPFile("cards/8_of_spades.bmp");
	pixmap.setTexture(30);
	playingCards.push_back(Card(8,30));


	pixmap.readBMPFile("cards/9_of_clubs.bmp");
	pixmap.setTexture(31);
	playingCards.push_back(Card(9,31));

	pixmap.readBMPFile("cards/9_of_diamonds.bmp");
	pixmap.setTexture(32);
	playingCards.push_back(Card(9,32));
	
	pixmap.readBMPFile("cards/9_of_hearts.bmp");
	pixmap.setTexture(33);
	playingCards.push_back(Card(9,33));

	pixmap.readBMPFile("cards/9_of_spades.bmp");
	pixmap.setTexture(34);
	playingCards.push_back(Card(9,34));

		
	pixmap.readBMPFile("cards/10_of_clubs.bmp");
	pixmap.setTexture(35);
	playingCards.push_back(Card(10,35));

	pixmap.readBMPFile("cards/10_of_diamonds.bmp");
	pixmap.setTexture(36);
	playingCards.push_back(Card(10,36));
	
	pixmap.readBMPFile("cards/10_of_hearts.bmp");
	pixmap.setTexture(37);
	playingCards.push_back(Card(10,37));

	pixmap.readBMPFile("cards/10_of_spades.bmp");
	pixmap.setTexture(38);
	playingCards.push_back(Card(10,38));

		
	pixmap.readBMPFile("cards/ace_of_clubs.bmp");
	pixmap.setTexture(39);
	playingCards.push_back(Card(1,39));

	pixmap.readBMPFile("cards/ace_of_diamonds.bmp");
	pixmap.setTexture(40);
	playingCards.push_back(Card(1,40));
	
	pixmap.readBMPFile("cards/ace_of_hearts.bmp");
	pixmap.setTexture(41);
	playingCards.push_back(Card(1,41));

	pixmap.readBMPFile("cards/ace_of_spades.bmp");
	pixmap.setTexture(42);
	playingCards.push_back(Card(1,42));


	pixmap.readBMPFile("cards/jacks_of_clubs2.bmp");
	pixmap.setTexture(43);
	playingCards.push_back(Card(10,43));

	pixmap.readBMPFile("cards/jacks_of_diamonds2.bmp");
	pixmap.setTexture(44);
	playingCards.push_back(Card(10,44));
	
	pixmap.readBMPFile("cards/jacks_of_hearts2.bmp");
	pixmap.setTexture(45);
	playingCards.push_back(Card(10,45));

	pixmap.readBMPFile("cards/jacks_of_spades2.bmp");
	pixmap.setTexture(46);
	playingCards.push_back(Card(10,46));

	
	pixmap.readBMPFile("cards/king_of_clubs2.bmp");
	pixmap.setTexture(47);
	playingCards.push_back(Card(10,47));

	pixmap.readBMPFile("cards/king_of_diamonds2.bmp");
	pixmap.setTexture(48);
	playingCards.push_back(Card(10,48));
	
	pixmap.readBMPFile("cards/king_of_hearts2.bmp");
	pixmap.setTexture(49);
	playingCards.push_back(Card(10,49));

	pixmap.readBMPFile("cards/king_of_spades2.bmp");
	pixmap.setTexture(50);
	playingCards.push_back(Card(10,50));


	
	pixmap.readBMPFile("cards/queen_of_clubs2.bmp");
	pixmap.setTexture(51);
	playingCards.push_back(Card(10,51));

	pixmap.readBMPFile("cards/queen_of_diamonds2.bmp");
	pixmap.setTexture(52);
	playingCards.push_back(Card(10,52));
	
	pixmap.readBMPFile("cards/queen_of_hearts2.bmp");
	pixmap.setTexture(53);
	playingCards.push_back(Card(10,53));

	pixmap.readBMPFile("cards/queen_of_spades2.bmp");
	pixmap.setTexture(54);
	playingCards.push_back(Card(10,54));

}


void BlackJack::initGame(){
	int random;

	random = rand()%playingCards.size();
	packDiller.push_back(playingCards[random]);
	playingCards.erase(playingCards.begin()+random);

	random = rand()%playingCards.size();
	packDiller.push_back(playingCards[random]);
	playingCards.erase(playingCards.begin()+random);

	random = rand()%playingCards.size();
	packPlayer.push_back(playingCards[random]);
	playingCards.erase(playingCards.begin()+random);

	random = rand()%playingCards.size();
	packPlayer.push_back(playingCards[random]);
	playingCards.erase(playingCards.begin()+random);
}

void BlackJack::resetGame(){
	for(int i = 0; i < packDiller.size(); i++){
		playingCards.push_back(packDiller[i]);
	}
	packDiller.clear();

	for(int i = 0; i < packPlayer.size(); i++){
		playingCards.push_back(packPlayer[i]);
	}
	packPlayer.clear();
}

void BlackJack::giveCardP(){
	int random;

	random = rand()%playingCards.size();
	packPlayer.push_back(playingCards[random]);
	playingCards.erase(playingCards.begin()+random);
}

void BlackJack::giveCardD(){
	int random;

	random = rand()%playingCards.size();
	packDiller.push_back(playingCards[random]);
	playingCards.erase(playingCards.begin()+random);
}


void BlackJack::drawPackDiller(){
	float comp = 25;
	for(int i = 0; i< packDiller.size(); i++){
		glPushMatrix();
		glTranslatef(x_init+((comp+5)*i),0.0,0.0);
		packDiller[i].drawCard(comp);
		glPopMatrix();
	}
}


void BlackJack::drawPackPlayer(){

}

void BlackJack::drawPacks(){
	glPushMatrix();
	glTranslatef(0,0.0,3.0);
	drawPackDiller();
	glPopMatrix();
}
