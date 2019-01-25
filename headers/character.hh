#pragma once
#include "entity.hh"
#include "shot.hh"

class Shot;

/*
 * Class Character
 * Class which make an entity shoot and move
 */
class Character : public Entity {

	protected:
		int m_hp;				// Health-point of the character
		sf::Texture m_texture;	// Texture of the character
		sf::Sprite m_sprite;	// Sprite of the character


	public:
		// Constructor and Destructor
		Character(int x, int y, std::size_t size, int hp);
		virtual ~Character();

		// Getters
		int get_hp() const;
		sf::Sprite get_sprite() const;
	
		// Move
		virtual void move(Direction_t direction, int min_x, int max_x) = 0;  
	
		// Shoot
		virtual Shot* shoot() const = 0;
};