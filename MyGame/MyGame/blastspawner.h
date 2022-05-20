#pragma once

#include "Engine/GameEngine.h"
#include "blast.h"

class BlastSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);

private:
	int timer_ = 0;

};

typedef std::shared_ptr<BlastSpawner> BlastSpawnerPtr;
