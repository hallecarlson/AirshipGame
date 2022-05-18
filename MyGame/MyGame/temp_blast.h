#pragma once

#include "Engine/GameEngine.h"

class Blast_t : public GameObject
{
public:
	//creates our meteor
	Blast_t(sf::Vector2f pos);

	//functions overriden from GameObject
	void draw();
	void update(sf::Time& elapsed);
	//sf::FloatRect getCollisionRect();
	//void handleCollision(GameObject& otherGameObject);

private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Blast_t> Blast_tPtr;