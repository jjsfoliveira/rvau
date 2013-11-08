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
	const static int BlackJack::comp = 25;
	const static int BlackJack::x_init = -30;
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

	double* posDiferPatterns(int marker1, int marker2);
//	void drawPacks();







private:
	stack<Card> playingCards;
	RGBpixmap pixmap;
	int score;
	Dispenser dispenser;
	vector<Pattern> patts;
<<<<<<< HEAD
	vector<int> buttonPick;
	char *multiPattern;
=======
	Dispenser dispenser;
>>>>>>> 33af4e5d1a82bcaab599b1d13d2e9e2290984338

	//aux
	
	int index_diller;
	int index_dispenser;
	int index_player;
<<<<<<< HEAD

=======
	
>>>>>>> 33af4e5d1a82bcaab599b1d13d2e9e2290984338
};


