#include "blast.h"
#include "explosion.h"
#include "GameScene.h"
#include "score.h"
#include "laser.h"
//#include "blastspawner.h"

const float SPEED = 0.15f;

Blast::Blast(sf::Vector2f pos)
	:AnimatedSprite (pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/Projectile.png"));
	//AnimatedSprite::setPosition(pos);	

	SetUpBlastAnimation();
	playAnimation("blast", AnimationMode::LoopForwards);

	assignTag("blast");

	setCollisionCheckEnabled(true);
}

void Blast::SetUpBlastAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 192, 192)); //frame 1
	frames.push_back(sf::IntRect(192, 0, 192, 192)); //2
	frames.push_back(sf::IntRect(384, 0, 192, 192)); //3
	frames.push_back(sf::IntRect(0, 192, 192, 192)); //4
	frames.push_back(sf::IntRect(192, 192, 192, 192)); //5
	frames.push_back(sf::IntRect(384, 192, 192, 192)); //6
	frames.push_back(sf::IntRect(0, 384, 192, 192)); //7
	frames.push_back(sf::IntRect(192, 384, 192, 192)); //8
	frames.push_back(sf::IntRect(384, 384, 192, 192)); //9
	frames.push_back(sf::IntRect(0, 576, 192, 192)); //10

	addAnimation("blast", frames);
}

/*
void Blast::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
*/

void Blast::update(sf::Time& elapsed)
{
	AnimatedSprite::update(elapsed);
	
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = AnimatedSprite::getPosition();

	if (!isPlaying() || pos.x < AnimatedSprite::getCollisionRect().width * -1) //may need to be adjusted so that lives only decrease when ship is hit, but that may be done somewhere else
	{
		//GameScene& scene = (GameScene&)GAME.getCurrentScene();
		//scene.decreaseLives();
		
		makeDead();
	}
	else
	{
		setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Blast::getCollisionRect()
{
	return AnimatedSprite::getSprite().getGlobalBounds();
}

void Blast::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
		ExplosionPtr explosion = std::make_shared<Explosion>(AnimatedSprite::getPosition());
		GAME.getCurrentScene().addGameObject(explosion);

		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
	}
	makeDead();
}