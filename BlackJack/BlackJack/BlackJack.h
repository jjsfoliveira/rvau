#include <vector>
#include "Card.h"
#include "Pattern.h"
#include <AR/gsub.h>
#include <AR/ar.h>
#include <AR/arMulti.h>
#include <stack>  
#include <iostream>
#include <time.h>
#include "Model3D.h"

using namespace std;


class BlackJack
{

public:
	BlackJack(void);
	~BlackJack(void);
	const static int BlackJack::delta_time = 300;
	vector<Card> packPlayer;
	vector<Card> packDiller;
	bool endGame;
	int winner;
	int stateGame;
	string buttonText[6];
	void loadCards();
	void initGame();
	void resetGame();
	void giveCardP();
	void giveCardD();
	vector<Pattern>& getPatts();
	void initPatts();
	void drawDispenser();
	void drawPackPlayer();
	void drawPackDiller();
	void drawButton();
	int scorePlayer();
	int scoreDiller();
	void draw_aux( double trans1[3][4], double trans2[3][4], int mode , int id);
	ARMultiMarkerInfoT  *config;
	vector<double> posDiferPatterns(int marker1, int marker2);

	void pickButton1();
	void pickButton2();
	void pickButton3();
	void drawText(double r, double g, double b, int x, int y, std::string text);

	float bet;
	float money;





private:
	stack<Card> playingCards;
	RGBpixmap pixmap;
	int score;
	Model3D dispenser;
	Model3D button;
	vector<Pattern> patts;
	vector<int> buttonPick;
	char *multiPattern;
	

	//aux
	
	int index_diller;
	int index_dispenser;
	int index_player;

};


