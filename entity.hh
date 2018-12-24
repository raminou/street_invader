#pragma once
#include <iostream>

typedef enum Direction_t {UP, DOWN, LEFT, RIGHT} Direction_t;

class Entity {

	protected:
		int m_x;				//x position (top-left)
		int m_y;				//y position (top-left)
		std::size_t m_size;		//size of the object (square shape)


	public:
        // Constructor and destructor
		Entity(int x, int y, std::size_t size);
		virtual ~Entity();
        
        // Getters
        int get_x() const;
        int get_y() const;
        
		//virtual void move() const = 0;
};


