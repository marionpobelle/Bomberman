#include "Entity.h"

Entity::Entity( float _x, float _y, std::string _spriteName) : Transform(_x, _y, _spriteName ) {

}

void Entity::Update( std::vector<Transform*>& _entityList, Grid& _grid ) {

}

void Entity::ExplosionReaction( std::vector<Transform*>& _entityList ) {
	std::cout << "EXPLOSION CONTACT" << std::endl;
}
