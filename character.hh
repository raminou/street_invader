#pragma once
#include "entity.hh"
#include "shot.hh"

class Shot;
class Character : public Entity {

	protected:
		int m_hp;		//Health-point of the character


	public:
		Character(int x, int y, int size, int hp);
		virtual ~Character();
		virtual void move() const = 0;  
		virtual Shot* shoot() const = 0;	
};