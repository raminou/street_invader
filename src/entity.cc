#include "entity.hh"
#include <typeinfo>

Entity::Entity(int x, int y, std::size_t size) : m_x(x), m_y(y), m_size(size) {}

Entity::~Entity() {}

int Entity::get_x() const {
    return m_x;
}

int Entity::get_y() const {
    return m_y;
}

std::size_t Entity::get_size() const {
	return m_size;
}

bool Entity::check_hit(const Entity& en, bool inverse) const {
	/*
	std::cout << "this size: " << this->get_size() << ",\tx:" << this->get_x() << ",\ty:" << this->get_y() << std::endl;
	std::cout << "en size: " << en.get_size() << ",\tx:" << en.get_x() << ",\ty:" << en.get_y() << std::endl;
	*/
    return (((m_x <= en.get_x() && (unsigned int)en.get_x() <= m_x + m_size) 
				|| ((unsigned int)m_x <= en.get_x() + en.get_size() && (unsigned int) en.get_x()+ en.get_size() <= m_x + m_size))
			&& ((m_y <= en.get_y() && (unsigned int)en.get_y() <= m_y + m_size) 
				|| ((unsigned int) m_y <= en.get_y() + en.get_size() && en.get_y() + en.get_size() <= m_y + m_size))) || (inverse && en.check_hit(*this, false));
}