#pragma once
#include "entity.hh"
#include "shot.hh"

class Shot;
class Character : public Entity {

	protected:
		int m_hp;		//Health-point of the character


	public:
		Character(int x, int y, std::size_t size, int hp);
		virtual ~Character();
		virtual void move(Direction_t direction) = 0;  
		virtual Shot* shoot() const = 0;
};