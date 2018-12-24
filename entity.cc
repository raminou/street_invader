#include "entity.hh"

Entity::Entity(int x, int y, std::size_t size) : m_x(x), m_y(y), m_size(size) {}

Entity::~Entity() {}

int Entity::get_x() const {
    return m_x;
}

int Entity::get_y() const {
    return m_y;
}