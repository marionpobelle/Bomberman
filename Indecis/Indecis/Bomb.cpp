#include "Bomb.h"

Bomb::Bomb( float _x, float _y, std::string _spriteName ) //constructor
    : Transform( _x, _y, _spriteName ), timer( 3000 )
{}

void Bomb::Update( std::vector<Transform*> &_entityList, Grid &_grid ) {
    timer -= NYTimer::deltaTime;

    if ( timer <= 0 ) {
        std::vector<Transform*>::iterator ptr;
        for ( ptr = _entityList.begin(); ptr < _entityList.end(); ptr++ ) {
            if ( *ptr == this ) {
                _entityList.erase( ptr );
                break;
            }
        }
        Explode( _entityList, _grid );
        delete this;
    }
}

void Bomb::Explode( std::vector<Transform*>& _entityList, Grid& _grid ) {
    AudioEngine::Init();
    AudioEngine::PlayOneShot("music\\ExploBomb.wav");
    Explosion *_firstExplosion = new Explosion( position.x, position.y, "EXPLOSION" );
    _entityList.push_back( _firstExplosion );
    _firstExplosion->ExplodeTowards_r( _entityList, _grid, position.x - 1, position.y, 3 ); //left
    _firstExplosion->ExplodeTowards_r( _entityList, _grid, position.x + 1, position.y, 1 ); //right
    _firstExplosion->ExplodeTowards_r( _entityList, _grid, position.x, position.y + 1, 0 ); //up
    _firstExplosion->ExplodeTowards_r( _entityList, _grid, position.x, position.y - 1, 2 ); //down
}