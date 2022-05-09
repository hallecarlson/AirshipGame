#pragma once

#include "Engine/GameEngine.h"

class Blast : public AnimatedSprite
{
public:
	//creates our blast
	Blast(sf::Vector2f pos);
	
	void draw();
	void update(sf::Time& elapsed);\

	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);

private:
	void SetUpBlastAnimation();
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Blast> BlastPtr;
