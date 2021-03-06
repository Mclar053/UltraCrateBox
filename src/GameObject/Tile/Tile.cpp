//
//  Tile.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Tile.h"

Tile::Tile():GameObject(ofVec2f(100,100)){
    
}

Tile::Tile(ofVec2f _pos):GameObject(_pos){
    
}

void Tile::getSize(){
    size.set(gameSprite.sprite[gameSprite.currentFrame].getWidth(), gameSprite.sprite[gameSprite.currentFrame].getHeight());
}


/*
 Detects if entity has hit the left side of the tile
 */
bool Tile::detectLeft(Entity *_entity){
    if(_entity->pos.x+_entity->size.x/2>pos.x-size.x/2 &&
       _entity->pos.x-_entity->size.x/2<pos.x-size.x/2+2 &&
       _entity->pos.y+_entity->size.y/2>pos.y-size.y/2+10 &&
       _entity->pos.y-_entity->size.y/2<=pos.y+size.y/2-5){
        return true;
    }
    return false;
}

/*
 Detects if entity has hit the right side of the tile
 */
bool Tile::detectRight(Entity *_entity){
    if(_entity->pos.x+_entity->size.x/2>pos.x+size.x/2-2 &&
       _entity->pos.x-_entity->size.x/2<pos.x+size.x/2 &&
       _entity->pos.y+_entity->size.y/2>pos.y-size.y/2+10 &&
       _entity->pos.y-_entity->size.y/2<=pos.y+size.y/2-5){
        return true;
    }
    return false;
}

/*
 Detects if entity has hit the top side of the tile
 */
bool Tile::detectTop(Entity *_entity){
    if(_entity->pos.x+_entity->size.x/2>pos.x-size.x/2 &&
       _entity->pos.x-_entity->size.x/2<=pos.x+size.x/2 &&
       _entity->pos.y+_entity->size.y/2>pos.y-size.y/2 &&
       _entity->pos.y-_entity->size.y/2<pos.y-size.y/2+10){
        return true;
    }
    return false;
}


/*
 Detects if entity has hit the bottom side of the tile
 */
bool Tile::detectBottom(Entity *_entity){
    if(_entity->pos.x+_entity->size.x/2>pos.x-size.x/2+5 &&
       _entity->pos.x-_entity->size.x/2<=pos.x+size.x/2-5 &&
       _entity->pos.y+_entity->size.y/2>pos.y+size.y/2-5 &&
       _entity->pos.y-_entity->size.y/2<pos.y+size.y/2){
        return true;
    }
    return false;
}


/*
 Detects if entity is above the top of the tile
 */
bool Tile::detectAboveTop(Entity *_entity){
    if(_entity->pos.x+_entity->size.x/2>pos.x-size.x/2 &&
       _entity->pos.x-_entity->size.x/2<pos.x+size.x/2 &&
       _entity->pos.y+_entity->size.y/2>pos.y-size.y/2-3 &&
       _entity->pos.y-_entity->size.y/2<pos.y-size.y/2-1){
        return true;
    }
    return false;
}
