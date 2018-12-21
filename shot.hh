#pragma once
#include "entity.hh"
#include "character.hh"

class Character;
class Shot : public Entity {

	private:
		Character* m_author;		//Shooter
		char m_direction;			//Direction of the shot (up = 1 or down = -1)


	public:
		Shot(int x, int y, Character* author, char direction);
		virtual ~Shot();
		virtual void move(char direction);
};