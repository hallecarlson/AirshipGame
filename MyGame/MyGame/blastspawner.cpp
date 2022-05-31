#include "blastspawner.h"
#include "blast.h"

//the number of milliseconds between blast spawns
const int SPAWN_DELAY = 1000;

void BlastSpawner::update(sf::Time& elapsed)
{
	//determine how much time has passed and adjust our timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	float blastX;
	float blastY;
	int directionb = 0;

	//if our timer has elapsed, reset it and spawn a meteor
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		directionb = rand() % (2);

		if (directionb == 0) //left to right >>
		{
			blastX = (float)(0); //FIX DIRECTION
			blastY = (float)(rand() % size.y);
		}
		else if (directionb == 1) //right to left <<
		{
			blastX = (float)(size.x + 100);
			blastY = (float)(rand() % size.y);
		}

		//sf::FloatRect bounds = AnimatedSprite::getGlobalBounds();

		//create a meteor and add it to the scene
		BlastPtr blast = std::make_shared<Blast>(sf::Vector2f(blastX, blastY), directionb);
		GAME.getCurrentScene().addGameObject(blast);
	}
}