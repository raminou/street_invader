#pragma once
#include <iostream>
#include <typeinfo>
#include <SFML/Graphics.hpp>

/*
 * Typedef to manage the direction
 */
typedef enum Direction_t {UP, DOWN, LEFT, RIGHT} Direction_t;

/*
 * Class Entity
 * Class to manage things which have a position and a size
 */
class Entity {
	protected:
		int m_x;					// x position (top-left)
		int m_y;					// y position (top-left)
		std::size_t m_size;			// size of the object (square shape)


	public:
		// Constructor and destructor
		Entity(int x, int y, std::size_t size);
		virtual ~Entity();

		// Getters
		int get_x() const;
		int get_y() const;
		std::size_t get_size() const;

		// Check if Entity en is in this
		// - inverse is to check the inverse
		bool check_hit(const Entity& en, bool inverse=true) const;
};


