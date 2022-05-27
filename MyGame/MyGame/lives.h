#pragma once

#include "Engine/GameEngine.h"

class Lives : public GameObject
{
public:
	//creates the lives instance
	Lives(sf::Vector2f pos);

	//functions overriden from GameObject
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<Lives> LivesPtr;
