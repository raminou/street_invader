#pragma once


class Entity {

	protected:
		int m_x;		//x position (top-left)
		int m_y;		//y position (top-left)
		int m_size;		//size of the object (square shape)


	public:
		Entity(int x, int y, int size);
		virtual ~Entity();
		virtual void move() const = 0;  	
};


