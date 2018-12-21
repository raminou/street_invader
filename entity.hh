#pragma once
#include <iostream>

class Entity {

	protected:
		int m_x;				//x position (top-left)
		int m_y;				//y position (top-left)
		std::size_t m_size;		//size of the object (square shape)


	public:
		Entity(int x, int y, std::size_t size);
		virtual ~Entity();
		virtual void move() const = 0;
};


