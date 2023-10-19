#include <algorithm>
#include "Player.h"
float Player::SPEED = .005;

Player::Player( float _x, float _y, std::string _spriteName, UCHAR _leftVK, UCHAR _rightVK, UCHAR _upVK, UCHAR _downVK, UCHAR _bombVK ) //constructor
    : Entity( _x, _y, _spriteName ), leftVK( _leftVK ), rightVK( _rightVK ), upVK( _upVK ), downVK( _downVK ), bombVK( _bombVK ), orientation( 0 ), playerName ( _spriteName )
{}

void Player::Update( std::vector<Transform*> &_entityList, Grid &_grid ) {
    isWalking = false;
    if ( GetAsyncKeyState( downVK ) ) {
        if ( !_grid.HasCollision( floor( position.x ), floor( position.y ) + 1, _entityList ) ) {
        	position.y += ( SPEED * NYTimer::deltaTime );
            orientation = 0;
            isWalking = true;
        } else {
            position.y = floor( position.y );
        }
    }
    if ( GetAsyncKeyState( upVK ) ) {
        if ( !_grid.HasCollision( floor( position.x ), floor( position.y ) - 1, _entityList ) ) {
        	position.y -= ( SPEED * NYTimer::deltaTime );
            orientation = 2;
            isWalking = true;
        } else {
            position.y = floor( position.y );
        }
    }
    if ( GetAsyncKeyState( rightVK ) ) {
        lookingLeft = false;
        if ( !_grid.HasCollision( floor(position.x ) + 1, floor( position.y ), _entityList ) ) {
        	position.x += ( SPEED * NYTimer::deltaTime );
        	orientation = 1;
            isWalking = true;
        } else {
            position.x = floor( position.x );
        }
    }
    if ( GetAsyncKeyState( leftVK ) ) {
        lookingLeft = true;
        if ( !_grid.HasCollision( floor( position.x ) - 1, floor( position.y ), _entityList ) ) {
        	position.x -= ( SPEED * NYTimer::deltaTime );
        	orientation = 3;
            isWalking = true;
        } else {
            position.x = floor( position.x );
        }
    }

    if ( GetAsyncKeyState( bombVK ) ) {
        PlantBomb( _entityList, _grid );
    }

    if ( bombCooldown > 0 ) bombCooldown -= NYTimer::deltaTime;

    if (damageBlinkTimer > 0) {
        damageBlinkTimer -= NYTimer::deltaTime;
        if (damageBlinkTimer <= 0) {
            spriteName = playerName;
        }
    } else {
        if (isWalking) {
            if (lookingLeft) {
                spriteName = playerName + "-LEFT" + "-WALKING";
            } else {
                spriteName = playerName + "-WALKING";
            }
        } else {
            if (lookingLeft) {
                spriteName = playerName + "-LEFT";
            } else {
                spriteName = playerName;
            }
            animFrame = 0;
        }

        if (walkAnimTimer > 0 && isWalking) {
            walkAnimTimer -= NYTimer::deltaTime;
            if (walkAnimTimer <= 0) {
                if (animFrame == 2) animFrame = 0;
                else animFrame++;
                walkAnimTimer = 100;
            }
        }
    }


}

void Player::PlantBomb( std::vector<Transform*> &_entityList, Grid &_grid ) {
    if ( bombCooldown > 0 ) return;
    AudioEngine::Init();
    AudioEngine::PlayOneShot("music\\DropBomb.wav");
    int bombX = position.x;
    int bombY = position.y;
    switch ( orientation )
    {
    case 0:
        bombY = floor( position.y ) + 1;
        break;
    case 1:
        bombX = floor( position.x ) + 1;
        break;
    case 2:
        bombY = floor( position.y ) - 1;
        break;
    case 3:
        bombX = floor( position.x ) - 1;
        break;
    default:
        break;
    }
    int bombPosition = _grid.GetGridCoordinates( bombX, bombY );
    if( !_grid.HasCollision( bombX, bombY, _entityList ) ) {
        bombCooldown = 2000;
        _entityList.push_back( new Bomb( bombX, bombY, "BOMB" ) );
    }
}

void Player::ExplosionReaction( std::vector<Transform*>& _entityList ) {
    life -= 1;
    UpdateHearts();
    if (life > 0) {
        return;
    }
    std::vector<Transform*>::iterator ptr;
    Explosion* _nextExplosion = new Explosion( position.x, position.y, "EXPLOSION" );
    _entityList.push_back( _nextExplosion );
    for ( ptr = _entityList.begin(); ptr < _entityList.end(); ptr++ ) {
        if ( *ptr == this ) {
            _entityList.erase( ptr );
            break;
        }
    }
    UISystem::OpenEndMenu();
    delete this;
}

void Player::UpdateHearts() {
    for (auto i = playerUI.Hearts.begin(); i < playerUI.Hearts.end(); ++i)
    {
        UIWindow* heart = *i;
        heart->spriteName = (std::distance(playerUI.Hearts.begin(), i)) >= life ? "HEART1" : "HEART";
        std::string damnDaniel = heart->spriteName;
    }
    spriteName = playerName + "-DAMAGE";
    damageBlinkTimer = 300;
}
