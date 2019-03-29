


#include "Circle.hpp"

namespace example
{
	Circle::Circle(float x, float y, float radius, Scene * scene)
		:Entity(scene)
	{
		b2BodyDef body;
		body.type = b2_dynamicBody;

		float pixels_scaled = scene-> scale_pixels_to_sfml();

		position.x = x* pixels_scaled;
		position.y = y* pixels_scaled;
		body.position.Set(position.x, position.y);

		bodies["circle"] = scene->get_world().CreateBody(&body);

		b2CircleShape shape;
		b2FixtureDef fixture;
		shape.m_radius = radius * pixels_scaled;
		fixture.shape = &shape;
		fixture.density = 300.f;
		fixture.friction = 0.f;
		fixture.restitution = 0.1f;

		bodies["circle"]->CreateFixture(&fixture);

		set_color(sf::Color::Magenta);


	}

	void Circle::update(float deltaTime)
	{
		//nothing
	}
	void Circle::collision_enter()
	{
		//nothing
	}
	void Circle::collision_exit()
	{
		//nothing
	}
}