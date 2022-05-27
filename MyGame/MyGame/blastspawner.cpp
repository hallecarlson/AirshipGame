#include "blastspawner.h"
#include "blast.h"

//the number of milliseconds between blast spawns
const int SPAWN_DELAY = 2000;

void BlastSpawner::update(sf::Time& elapsed)
{
	srand((unsigned)time(NULL));
	//determine how much time has passed and adjust our timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	//float blastX;
	//float blastY;

	//if our timer has elapsed, reset it and spawn a meteor
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		/*directionb = 1 + rand() % (2 - 1 + 1);

		if (directionb == 1) //left to right >>
		{
			//float blastX = (float)(size.x + 100); //FIX DIRECTION
			float blastY = (float)(rand() % size.y);
		}
		else if (directionb == 2) //right to left <<
		{
			float blastX = (float)(size.x + 100);
			float blastY = (float)(rand() % size.y);
		}*/


		//spawn the meteor off the right side of the screen
		//we're assuming the meteor isn't more than 100 pixels wide
		float blastX = (float)(size.x + 100);
		
		//float blastX = (float)(size.x / 2);

		//spawn the meteor somewhere along the height of the window, randomly
		float blastY = (float)(rand() % size.y);
		
		//float blastY = (float)(size.y / 2);
		
		//create a meteor and add it to the scene
		BlastPtr blast = std::make_shared<Blast>(sf::Vector2f(blastX, blastY));
		GAME.getCurrentScene().addGameObject(blast);
	}
}