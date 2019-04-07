

#include "ParticleSystem.hpp"

namespace example
{
	template <class PARTICLE>
	Particle_System<PARTICLE>::Particle_System(Scene * scene, b2Vec2 pos, size_t particles_count, float emission_rate)
		: Entity(scene), particles(particles_count), position(pos), initial_particles(particles_count), emission_rate(emission_rate), current_time(0.f)
	{

	}

	template<class PARTICLE>
	void Particle_System<PARTICLE>::update(float deltaTime)
	{
		
		for (auto & particle : particles)
		{
			Part & p = particle;
			if (!p.update(deltaTime))
			{
				particles.free_object(&p);
			}
		}
	}
	template<class PARTICLE>
	void Particle_System<PARTICLE>::render(sf::RenderWindow & renderer)
	{
		
		for (auto & particle : particles)
		{
			Part & p = particle;
			p.render(renderer);
		}
	}
	template<class PARTICLE>
	void Particle_System<PARTICLE>::emission(float deltaTime)
	{
		current_time += deltaTime;

		if (current_time >= emission_rate)
		{
			Part * p = particles.get_free_object();
			p->reset(sf::Vector2f(100.f, 100.f));
		}
	}
}