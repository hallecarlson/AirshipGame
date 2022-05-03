#pragma once

#include "Engine/GameEngine.h"

class Blast : public GameObject
{
public:
	//creates our blast
	Blast(sf::Vector2f pos);

	//functions overriden from GameObject
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);

private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Blast> BlastPtr;
