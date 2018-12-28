#pragma once
#include "entity.hh"
#include "character.hh"


class Character;
class Shot : public Entity {

	private:
		Character* m_author;	//Shooter
		Direction_t m_direction;	//Direction of the shot


	public:
		static constexpr std::size_t m_shot_size = 5;	//Size of a Shot object (value to modify)
		static constexpr int m_shot_velocity = 5;		//Velocity of a Shot object (value to modify)

		Shot(int x, int y, Character* author, Direction_t direction);
		virtual ~Shot();
        
        Character* get_author() const;
        
		virtual void move();
};