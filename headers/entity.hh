#pragma once
#include <iostream>
#include <typeinfo>
#include <SFML/Graphics.hpp>

typedef enum Direction_t {UP, DOWN, LEFT, RIGHT} Direction_t;

class Entity {

	protected:
		int m_x;					//x position (top-left)
		int m_y;					//y position (top-left)
		std::size_t m_size;			//size of the object (square shape)
		//sf::Texture m_texture; 	//Texture of the entity
        //sf::Sprite m_sprite;    	//Sprite of the entity


	public:
        // Constructor and destructor
		Entity(int x, int y, std::size_t size);
		virtual ~Entity();
        
        // Getters
        int get_x() const;
        int get_y() const;
		std::size_t get_size() const;
		//sf::Sprite get_sprite() const;
        
        bool check_hit(const Entity& en, bool inverse=true) const;
        
		//virtual void move() const = 0;
};


