#include <vector>
#include "Card.h"

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


	void drawPacks();

private:
	vector<Card> playingCards;
	RGBpixmap pixmap;
	int score;
	vector<Card> packPlayer;
	vector<Card> packDiller;

	//aux
	float x_init;

	void drawPackPlayer();
	void drawPackDiller();


};

