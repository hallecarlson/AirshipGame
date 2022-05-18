#include "temp_blastspawner.h"

/*
//the number of milliseconds between meteor spawns
const int SPAWN_DELAY = 1000;

void Blast_tSpawner::update(sf::Time& elapsed)
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
		float temp_blastX = (float)(size.x + 100);

		//spawn the meteor somewhere along the height of the window, randomly
		float temp_blastY = (float)(rand() % size.y);

		//create a meteor and add it to the scene
		Blast_tPtr meteor = std::make_shared<Blast_t>(sf::Vector2f(temp_blastX, temp_blastY));
		GAME.getCurrentScene().addGameObject(temp_blast);
	}
}
*/