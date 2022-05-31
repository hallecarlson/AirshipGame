#include "blast.h"
#include "explosion.h"
#include "GameScene.h"
#include "score.h"
#include "laser.h"
//#include "blastspawner.h"

const float SPEED = 0.08f;

Blast::Blast(sf::Vector2f pos, int dirb)
	:AnimatedSprite (pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/Projectile.png"));
	//AnimatedSprite::setPosition(pos);	

	SetUpBlastAnimation();
	playAnimation("blast", AnimationMode::LoopForwards);

	assignTag("blast");

	directionb = dirb;

	setCollisionCheckEnabled(true);
}

void Blast::SetUpBlastAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 50, 50)); //frame 1
	frames.push_back(sf::IntRect(50, 0, 50, 50)); //2
	frames.push_back(sf::IntRect(100, 0, 50, 50)); //3
	frames.push_back(sf::IntRect(0, 50, 50, 50)); //4
	frames.push_back(sf::IntRect(50, 50, 50, 50)); //5
	frames.push_back(sf::IntRect(100, 50, 50, 50)); //6
	frames.push_back(sf::IntRect(0, 100, 50, 50)); //7
	frames.push_back(sf::IntRect(50, 100, 50, 50)); //8
	frames.push_back(sf::IntRect(100, 100, 50, 50)); //9
	frames.push_back(sf::IntRect(0, 150, 50, 50)); //10

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

	if (directionb == 0) //change to spawn left->right
	{
	//if (!isPlaying() || pos.x < AnimatedSprite::getCollisionRect().width * -1) 
	if (!isPlaying() || pos.x < 0)
	{
		makeDead();
	}
	else
	{
		//setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
		setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
	}
	else if (directionb == 1)
	{
		if (!isPlaying() || pos.x < AnimatedSprite::getCollisionRect().width * -1) 
		{
			makeDead();
		}
		else
		{
			setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
		}
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

		makeDead();
	}
}