#include <vector>
#include "Card.h"
#include "Pattern.h"
#include <AR/ar.h>
#include <stack>  
#include <time.h>
#include "Dispenser.h"

using namespace std;


class BlackJack
{

public:
	BlackJack(void);
	~BlackJack(void);
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

	double* posDiferPatterns(int marker1, int marker2);
//	void drawPacks();





private:
	stack<Card> playingCards;
	RGBpixmap pixmap;
	int score;
	vector<Card> packPlayer;
	vector<Card> packDiller;
	vector<Pattern> patts;
	Dispenser dispenser;

	//aux
	float x_init;
	double n_iterations; 
	int index_diller;
	int index_dispenser;
	int index_player;
};

