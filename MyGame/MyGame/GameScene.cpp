#include "GameScene.h"
#include "ship.h" 
#include "blastspawner.h"
#include "cloudspawner.h"
#include "score.h"
#include "explosion.h"
#include "gameoverscene.h"
#include "blast.h"

GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);

	//BlastSpawnerPtr blastSpawner = std::make_shared<BlastSpawner>();
	//addGameObject(blastSpawner);

	/*BlastPtr blast = std::make_shared<Blast>(sf::Vector2f(200.0f, 200.0f));
	GAME.getCurrentScene().addGameObject(blast);

	CloudSpawnerPtr cloudSpawner = std::make_shared<CloudSpawner>();
	addGameObject(cloudSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);*/
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	++score_;
}

int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;

	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}

}