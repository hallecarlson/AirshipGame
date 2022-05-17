/*

if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && fireTimer_ <= 0) //right D
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY), direction);
		GAME.getCurrentScene().addGameObject(laser);
	}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && fireTimer_ <= 0) //up W
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY), direction);
		GAME.getCurrentScene().addGameObject(laser);
	}



if (direction == 3) //right D
	{
		if (pos.x > GAME.getRenderWindow().getSize().x)
		{
			makeDead();
		}
		else
		{
			sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
		}
	}

if (direction == 0) //up W
	{
		if (pos.y > GAME.getRenderWindow().getSize().y)
		{
			makeDead();
		}
		else
		{
			sprite_.setPosition(sf::Vector2f(pos.x, pos.y - SPEED * msElapsed));
		}
	}
*/