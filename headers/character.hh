#pragma once
#include "entity.hh"
#include "shot.hh"

class Shot;
class Character : public Entity {

	protected:
		int m_hp;				//Health-point of the character
		sf::Texture m_texture; 	//Texture of the character
        sf::Sprite m_sprite;    //Sprite of the character


	public:
		Character(int x, int y, std::size_t size, int hp);
		virtual ~Character();
        
        int get_hp() const;
        sf::Sprite get_sprite() const;
		virtual void move(Direction_t direction, int min_x, int max_x) = 0;  
		virtual Shot* shoot() const = 0;
};