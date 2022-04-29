#pragma once

#include "Engine/GameEngine.h"

class GameOverScene : public Scene
{
public:
	//creates our scene
	GameOverScene(int score);

};

typedef std::shared_ptr<GameOverScene> GameOverScenePtr;