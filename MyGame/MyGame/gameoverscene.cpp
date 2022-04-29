#include "gameoverscene.h"
#include "gameovermessage.h"

GameOverScene::GameOverScene(int score)
{
	GameOverMessagePtr gameOverMessage = std::make_shared<GameOverMessage>(score);
	addGameObject(gameOverMessage);
}