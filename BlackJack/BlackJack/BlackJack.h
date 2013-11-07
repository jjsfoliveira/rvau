#include <vector>
#include "Card.h"
#include "Pattern.h"
#include <AR/ar.h>
#include <stack>  
#include <time.h>

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

	double* posDiferPatterns(int marker1, int marker2);
//	void drawPacks();







private:
	stack<Card> playingCards;
	RGBpixmap pixmap;
	int score;

	vector<Pattern> patts;

	//aux
	
	int index_diller;
	int index_dispenser;
	int index_player;
};

