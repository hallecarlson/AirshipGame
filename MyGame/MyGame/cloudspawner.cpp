#include "cloudspawner.h"

//number of milliseconds between cloud spawns
const int SPAWN_DELAY = 5000;

void CloudSpawner::update(sf::Time& elapsed)
{
	//determines time passed and adjusts timer
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;

		sf::Vector2u size = GAME.getRenderWindow().getSize();

		//spawn on right screen
		//assume it isn't more than 100 pixels wide
		float cloudX = (float)(size.x + 100);

		//spawn on height of window randomly
		float cloudY = (float)(rand() % size.y);

		//create cloud and add to screen
		CloudPtr cloud = std::make_shared<Cloud>(sf::Vector2f(cloudX, cloudY));
		GAME.getCurrentScene().addGameObject(cloud);
	}
}