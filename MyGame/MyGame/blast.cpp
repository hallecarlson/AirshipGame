#include "blast.h"
#include "explosion.h"
#include "blastspawner.h"
#include "GameScene.h"

const float SPEED = 0.25f;

Blast::Blast(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("blast");
	setCollisionCheckEnabled(true);
}

void Blast::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Blast::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRectBlast::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Blast::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
		ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
		GAME.getCurrentScene().addGameObject(explosion);

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
	}

	makeDead();
}