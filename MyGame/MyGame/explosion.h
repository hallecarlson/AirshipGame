#pragma once

#include "Engine/GameEngine.h"

class Explosion : public AnimatedSprite
{
public:
	//creates our explosion
	Explosion(sf::Vector2f pos);

	//functions overriden from GameObject
	void update(sf::Time& elapsed);

private:
	void SetUpExplosionAnimation();

	sf::Sound boom_;
};

typedef std::shared_ptr<Explosion> ExplosionPtr;