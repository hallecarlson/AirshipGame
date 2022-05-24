#pragma once
#include "Engine/GameEngine.h"

class Ship :public GameObject
{
public:
	//creates ship
	Ship();

	//function overriden from Game:Object
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();
	void handleCollision(GameObject& otherGameObject);

private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;
};

typedef std::shared_ptr<Ship> ShipPtr;