#include "character.hh"

Character::Character(int x, int y, std::size_t size, int hp) : Entity(x, y, size), m_hp(hp) {}



Character::~Character() {} 