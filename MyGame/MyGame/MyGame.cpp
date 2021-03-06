#include "Engine/GameEngine.h"
#include "GameScene.h"

/*

To-do List
	Finalize
 
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

Date: 5/4/22	Done:
				Added a file for sprites and more convinient organization
				Made significant progress on my game design document
				Pushed to GitHub

Date: 5/6/22	Done:
				Added code for scrolling clouds, which function the same as enemy projectiles, just without collision
				Pushed to GitHub

Date: 5/9/22	Done:
				Added code for sprites and animations
				Pushed to GitHub

Date: 5/10/22	Done:
				Added code for clouds, blasts, and lasers
				Got help from Mr. Miyoshi
				Pushed to GitHub

Date: 5/11/22	Done:
				Got help from Mr. Miyoshi but didn't fix the problem (yet)
				Added some code for laser directions
				Pushed to GitHub

Date: 5/13/22	Done:
				Got help from Mr. Miyoshi
				Got the game running
				Fixed ship movement
				Added code for lasers moving in all directions (which doesn't work yet because I'm likely missing an updating if statement)
				Filled out advanced goal sheet
				Pushed to GitHub

Date: 5/16/22	Done: 
				Tried to fix laser movement
				Got help from Mr. Miyoshi
				Fixed some lines of code
				Got the up and right lasers to move
				Tried to fix the left and down lasers
				Pushed to GitHub

Date: 5/17/22	Done:
				Tried to fix laser spawns
				Got help from Mr. Miyoshi
				Fixed laser multi-directional spawns!!
				Tried to fix cloud spawns, but didn't succeed (yet!!)
				Pushed to GitHub

				Pulled from GitHub
				Tried to fix clouds
				Some error prevented me from running the game
				Made temporary files for blasts using exact meteor code from the game engine tutorial
				Pushed to GitHub

Date: 5/18/22	Done:
				Pulled from GitHub
				Commented out temp blast files to work on clouds
				Clouds worked due to edits made last night
				Changed the speed and spawn rate of the clouds to be less distracting to the player and represent the speed of a blimp as apposed to the speed of an airplane
				Uncommented blast files to try and solve the errors
				Got help from Mr. Miyoshi
				Commented out some things to try and get the sprite on the screen
				Pushed to GitHub

Date: 5/20/22	Done:
				Got help from Mr. Miyoshi
				Fixed the errors with blast
				Fixed the dimensions of blast
				Blast worked!
				Pushed to GitHub

				Pulled from GitHub
				Played around with blast spawns and tried to figure out directions and how to spawn from different sides of screen
				Took a break because it got too confusing
				Pushed to GitHub

Date: 5/23/22	Done:
				Pulled from GitHub
				Got help from Mr. Miyoshi getting blasts to move across screen
				Uncommented collision code
				Had an error with blasts despawning
				Had an error with blasts spawning in the same place
				Pushed to GitHub

				Pulled from GitHub
				Edited list of tasks based on priority
				Pushed to GitHub

Date: 5/24/22	Done:
				Pulled from GitHub
				Got explosions (and collision laser->blast) working
				Clouds and blasts still despawning after entering screen (I'm pretty sure clouds were working before??)
				Fixed the despawning (changed spawn delay and it somehow fixed the issue)
				Pushed to GitHub

				Pulled from GitHub
				Added collision (blast->ship)
				Uncommented code for score
				Edited code for lives to decrease not when the blasts leave the screen, but when they collide with the ship
				(Laptop won't let me run code due to some graphical error)
				Pushed to GitHub

Date: 5/25/22:	Done:	
				Pulled from GitHub
				Got some help from Mr. Miyoshi
				Tried to make explosion spawn in middle of ship
				Pushed to GitHub

Date: 5/27/22	Done:
				Got ship explosion animation to play in center of sprite instead of top left
				Got lives to display next to score
				Tried to fix blasts spawning randomly on y-axis (didn't succeed YET)
				Pushed to GitHub

Date: 5/31/22	Done:
				Got help from Mr. Miyoshi
				Got blasts to spawn randomly on y-axis
				Got blasts to spawn from left side of screen
				Fixed error where blasts despawn in the wrong place
				Fixed error where blasts would disappear when they collided
				Resized blasts and changed spawn timer and speed
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
