#include "blastspawner.h"

//the number of milliseconds between blast spawns
const int SPAWN_DELAY = 1000;

void BlastSpawner::update(sf::Time& elapsed)
{
	//determine how much time has passed and adjust our timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	//if our timer has elapsed, reset it and spawn a meteor
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		//spawn the meteor off the right side of the screen
		//we're assuming the meteor isn't more than 100 pixels wide
		//float meteorX = (float)(size.x + 100);
		float blastX = (float)(rand() % size.x);

		//spawn the meteor somewhere along the height of the window, randomly
		float blastY = (float)(size.y + 100);

		//create a meteor and add it to the scene
		BlastPtr blast = std::make_shared<Blast>(sf::Vector2f(blastX, blastY));
		GAME.getCurrentScene().addGameObject(blast);
	}
}