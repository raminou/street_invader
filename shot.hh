#pragma once
#include "entity.hh"
#include "character.hh"


typedef enum Direction_t {UP, DOWN} Direction_t;


class Character;
class Shot : public Entity {

	private:
		Character* m_author;		//Shooter
		Direction_t m_direction;	//Direction of the shot


	public:
		static constexpr int m_shot_size = 5;			//Size of a Shot object (value to modify)
		static constexpr int m_shot_velocity = 5;		//Size of a Shot object (value to modify)


		Shot(int x, int y, Character* author, Direction_t direction);
		virtual ~Shot();
		virtual void move(Direction_t direction);
};