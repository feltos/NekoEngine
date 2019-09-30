#include "NetEngine.h"
namespace guinet
{


	//ERROR HERE
	void NetEngine::Init()
	{
		config.gameWindowSize = sf::Vector2u(1280, 720);
		config.bgColor = sf::Color::Black;
		BasicEngine::Init();

		for (int i = 0; i < nmbOfEntity; i++)
		{
			auto entity = entityManager_.CreateEntity();
			auto entityPos = sf::Vector2f(400, 400);
			shapeManager_.AddComponent(entityManager_, entity);
			shapeManager_.SetComponent(entity, sf::CircleShape(10, 30));

			positionManager_.AddComponent(entityManager_, entity);
			positionManager_.SetComponent(entity, entityPos);
		}

		renderWindow = std::make_unique<sf::RenderWindow>();
		if (renderWindow != nullptr)
		{
			std::cout << "Window exist ! ";
		}
	}
	//ERROR HERE

	void NetEngine::Update(float dt)
	{

	}

	void ShapeManager::Draw()
	{

	}
}
