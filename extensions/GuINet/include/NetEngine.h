#include "engine/engine.h"
#include <vector>
#include <SFML/Graphics/CircleShape.hpp>
#include "engine/component.h"
#include <engine/transform.h>
#include <iostream>


namespace guinet
{
	
	const neko::EntityMask CIRCLESHAPE = 1u << 30u;

	class ShapeManager : public neko::ComponentManager<sf::CircleShape, CIRCLESHAPE>
	{
	public:

		void Draw();

	private:

	};

	class NetEngine : public neko::BasicEngine
	{
	public:

		void Init() override;

		void Update(float dt) override;
		


	private:

		ShapeManager shapeManager_;
		neko::EntityManager entityManager_;
		neko::Position2dManager positionManager_;

		int nmbOfEntity = 2;
	};


}
