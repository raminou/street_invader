#pragma once
#include "entity.hh"
#include "character.hh"


class Character;

/*
 * Class Shot
 * Class which manage shot
 */
class Shot : public Entity {

	private:
		Character* m_author;		// Shooter
		Direction_t m_direction;	// Direction of the shot

	public:
		static constexpr std::size_t m_shot_size = 5;	//Size of a Shot object
		static constexpr int m_shot_velocity = 5;		//Velocity of a Shot object

		// Constructor and destructor
		Shot(int x, int y, Character* author, Direction_t direction);
		virtual ~Shot();
	
		// Getters
		Character* get_author() const;

		// Debug method
		friend std::ostream& operator<<(std::ostream& , const Character&);
	
		// Make the shot moves
		virtual void move();
};