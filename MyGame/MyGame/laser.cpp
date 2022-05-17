#include "laser.h"

const float SPEED = 1.2f;

Laser::Laser(sf::Vector2f pos, int dir)
{
	sprite_.setTexture(GAME.getTexture("Resources/laser.png"));
	sprite_.setPosition(pos);
	assignTag("laser");

	direction = dir;
	//printf("%i\n", direction);
}

void Laser::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Laser::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (direction == 0) //up W
	{
		if (pos.y < 0)
		{
			makeDead();
		}
		else
		{
			sprite_.setPosition(sf::Vector2f(pos.x, pos.y - SPEED * msElapsed));
		}
	}	
	if (direction == 1) //left A
	{
		if (pos.x < 0)
		{
			makeDead();
		}
		else
		{
			sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
		}
	}
	if (direction == 2) //down S
	{
		if (pos.y > GAME.getRenderWindow().getSize().y)
		{
			makeDead();
		}
		else
		{
			sprite_.setPosition(sf::Vector2f(pos.x, pos.y + SPEED * msElapsed));
		}
	}
	if (direction == 3) //right D
	{
		if (pos.x > GAME.getRenderWindow().getSize().x)
		{
			makeDead();
		}
		else
		{
			sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
		}
	}
}

sf::FloatRect Laser::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}