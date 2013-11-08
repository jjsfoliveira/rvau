#include <vector>
#include "Card.h"
#include "Pattern.h"
#include <AR/gsub.h>
#include <AR/ar.h>
#include <AR/arMulti.h>
#include <stack>  
#include <iostream>
#include <time.h>
#include "Dispenser.h"

using namespace std;


class BlackJack
{

public:
	BlackJack(void);
	~BlackJack(void);
	const static int BlackJack::delta_time = 300;
	vector<Card> packPlayer;
	vector<Card> packDiller;

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
	ARMultiMarkerInfoT  *config;

	vector<double> posDiferPatterns(int marker1, int marker2);
//	void drawPacks();







private:
	stack<Card> playingCards;
	RGBpixmap pixmap;
	int score;
	Dispenser dispenser;
	vector<Pattern> patts;
	vector<int> buttonPick;
	char *multiPattern;
	Dispenser dispenser;


	//aux
	
	int index_diller;
	int index_dispenser;
	int index_player;

};


