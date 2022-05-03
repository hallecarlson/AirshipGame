#include "Engine/GameEngine.h"
#include "GameScene.h"

/*
Maintenance Log

Date: 4/29/22	Done: 
				Cloned Williams Game Engine
				Created project
				Pushet to GitHub

Date: 5/2/22	Done:
				Tried to make meteors come from all sides
				Created sprites
				Pushed to GitHub

Date: 5/3/22	Done:
				Added code to replace the meteor with the blast
				Added sprites for the blast and the clouds
				Pushed to GitHub
*/

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const std::string WINDOW_TITLE = "Halle's Extremely Cool and Awesome Game";

int main()
{
	// Seed the random number generator.
	srand((int)time(NULL));

	// Initialize the game.
	GAME.initialize(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	// Create our scene.
	GameScenePtr scene = std::make_shared<GameScene>();
	GAME.setScene(scene);

	// Run the game loop.
	GAME.run();

	return 0;
}
