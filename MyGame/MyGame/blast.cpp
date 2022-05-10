#include "blast.h"
#include "explosion.h"
#include "blastspawner.h"
#include "GameScene.h"

const float SPEED = 0.25f;

Blast::Blast(sf::Vector2f pos)
	:AnimatedSprite (pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/Projectile.png"));
	//AnimatedSprite.setPosition(pos);
	//assignTag("blast");

	setCollisionCheckEnabled(true);

	SetUpBlastAnimation();
	playAnimation("blast", AnimationMode::LoopForwards);
}

void Blast::SetUpBlastAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 64, 64)); //frame 1
	frames.push_back(sf::IntRect(64, 0, 64, 64)); //2
	frames.push_back(sf::IntRect(128, 0, 64, 64)); //3
	frames.push_back(sf::IntRect(192, 0, 64, 64)); //4
	frames.push_back(sf::IntRect(256, 0, 64, 64)); //5
	frames.push_back(sf::IntRect(320, 0, 64, 64)); //6
	frames.push_back(sf::IntRect(384, 0, 64, 64)); //7
	frames.push_back(sf::IntRect(448, 0, 64, 64)); //8
	frames.push_back(sf::IntRect(512, 0, 64, 64)); //9
	frames.push_back(sf::IntRect(576, 0, 64, 64)); //10

	addAnimation("blast", frames);
}

/*void Blast::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}*/

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

sf::FloatRect Blast::getCollisionRect()
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
