#include "cloud.h"
#include "cloudspawner.h"
#include "GameScene.h"

const float SPEED = 0.25f;

Cloud::Cloud(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/Cloud.png"));
	sprite_.setPosition(pos);
	assignTag("cloud");
}

void Cloud::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Cloud::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}