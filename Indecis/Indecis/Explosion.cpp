#include "Explosion.h"

Explosion::Explosion( float _x, float _y, std::string _spriteName ) : Transform( _x, _y, _spriteName ), timer( 500 ) {

}

void Explosion::Update( std::vector<Transform*>& _entityList, Grid& grid ) {
    timer -= NYTimer::deltaTime;

    if ( timer <= 250 && animFrame == 0 ) {
        animFrame++;
    }
    if ( timer <= 0 ) {
        std::vector<Transform*>::iterator ptr;
        for ( ptr = _entityList.begin(); ptr < _entityList.end(); ptr++ ) {
            if ( *ptr == this ) {
                _entityList.erase( ptr );
                break;
            }
        }
        delete this;
    }
}

void Explosion::ExplodeTowards_r( std::vector<Transform*>& _entityList, Grid& _grid, int _x, int _y, int _orientation, int currentCase ) {
    int maxCase = 1;

    int nextCaseX = _x;
    int nextCaseY = _y;
    switch ( _orientation )
    {
    case 0:
        nextCaseY = floor( position.y ) + 1;
        break;
    case 1:
        nextCaseX = floor( position.x ) + 1;
        break;
    case 2:
        nextCaseY = floor( position.y ) - 1;
        break;
    case 3:
        nextCaseX = floor( position.x ) - 1;
        break;
    default:
        break;
    }
    if (_grid.HasCollision(nextCaseX, nextCaseY, _entityList)) { //If there is a collision, check if it's a player
        Transform* _transform = _grid.HasTransformHere(nextCaseX, nextCaseY, _entityList);
        if (_transform != nullptr) {
            _transform->ExplosionReaction(_entityList);
        }
    }
    else { //If there isn't a collision, continue
        Explosion *_nextExplosion = new Explosion(nextCaseX, nextCaseY, "EXPLOSION");
        _entityList.push_back(_nextExplosion);
        if (currentCase < maxCase) {
            _nextExplosion->ExplodeTowards_r(_entityList, _grid, _x, _y, _orientation, currentCase+1);
        }
        else {
            return;
        }
        
    }
}
