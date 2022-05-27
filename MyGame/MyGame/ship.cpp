#include "ship.h"
#include <memory>
#include "laser.h"
#include "explosion.h"
#include "blast.h"
#include "GameScene.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/Airship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));

	setCollisionCheckEnabled(true);
}


void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Ship::update(sf::Time& elapsed)
{
	int direction = 3;
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))		y -= SPEED * msElapsed;	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))		y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))		x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))	x += SPEED * msElapsed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = 3;
	}

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && fireTimer_ <= 0) //up W
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY), direction);
		GAME.getCurrentScene().addGameObject(laser);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && fireTimer_ <= 0) //left A
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY), direction);
		GAME.getCurrentScene().addGameObject(laser);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && fireTimer_ <= 0) //down S
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY), direction);
		GAME.getCurrentScene().addGameObject(laser);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && fireTimer_ <= 0) //right D
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY), direction);
		GAME.getCurrentScene().addGameObject(laser);
	}
}

sf::FloatRect Ship::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Ship::handleCollision(GameObject& otherGameObject) //check that GameObject code doesn't need to be changed to AnimatedSprite
//void Ship::handleCollision(GameObject& AnimatedSprite)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	if (otherGameObject.hasTag("blast"))
	//if (AnimatedSprite.hasTag("blast"))
	{
		otherGameObject.makeDead();
		//AnimatedSprite.makeDead();
		//ExplosionPtr explosion = std::make_shared<Explosion>(AnimatedSprite::getPosition());
		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float explosionX = x + (bounds.width / 2.0f);
		float explosionY = y + (bounds.height / 2.0f);

		//ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
		ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(explosionX, explosionY));
		GAME.getCurrentScene().addGameObject(explosion);

		//GameScene& scene = (GameScene&)GAME.getCurrentScene();
		//scene.increaseScore();
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
	}
	//makeDead();
}