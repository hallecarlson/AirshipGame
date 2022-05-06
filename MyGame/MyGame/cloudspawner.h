#pragma once

#include "Engine/GameEngine.h"
#include "cloud.h"

class CloudSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private: 
	int timer_ = 0;
};

typedef std::shared_ptr<CloudSpawner> CloudSpawnerPtr;