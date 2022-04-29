#pragma once

#include "Engine/GameEngine.h"

class GameOverMessage : public GameObject
{
public:
	//creates the GameOverMessage instance
	GameOverMessage(int score);

	//functions overriden from GameObject
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Text text_;
};

typedef std::shared_ptr<GameOverMessage> GameOverMessagePtr;
