#pragma once

#include "Engine/GameEngine.h"

class Laser : public GameObject
{
public:
	//creates our laser
	Laser(sf::Vector2f pos, int dir);

	//functions overriden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();

private:
	sf::Sprite sprite_;

	int direction;
};

typedef std::shared_ptr<Laser> LaserPtr;
