#pragma once

#include "Engine/GameEngine.h"

class Cloud : public GameObject
{
public:
	//makes our clouds
	Cloud(sf::Vector2f pos);

	//functions overriden from game object
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Cloud> CloudPtr;