//
//  Entity.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Entity.h"

Entity::Entity():GameObject(ofVec2f(100, 100)){
    direction = 1;
    gravity = 0.5;
    action = true;
    MAX_VEL.set(5, 10);
}

Entity::Entity(ofVec2f _pos):GameObject(_pos){
    direction = 1;
    gravity = 0.5;
    action = true;
    MAX_VEL.set(5, 10);
}

void Entity::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        glScalef(direction, 1, 1);
        gameSprite.display();
        if(!action && moving){
            gameSprite.moveNextFrame();
        }
        else if(!action && !moving){
            gameSprite.currentFrame = gameSprite.stationaryFrame;
        }
        else{
            gameSprite.currentFrame = gameSprite.actionFrame;
        }
    glPopMatrix();
}

void Entity::applyGravity(){
    vel.y+=gravity;
}

//Applies friction in the x direction to slow down entity
void Entity::friction(){
    if(vel.x>0.3){
        acc.x=-0.3;
    }
    else if(vel.x<-0.3){
        acc.x=0.3;
    }
    else{
        stopMoveX();
    }
}

void Entity::move(){
    yControl(); //Controls gravity and y speed
    vel+=acc; //Adds acceleration to velocity
    speedControl(); //Ensuring entity doesn't move to fast in the x direction
    pos+=vel; //Adds velocity to position
    wallWrap(); //Moves entity to other side of screen if entity walks past the edge
}

void Entity::moveX(int _dir){
    direction = _dir;
    if(moving){
        acc.set(direction*0.5,acc.y);
    }
}

void Entity::yControl(){
    if(!onPlatform){
        applyGravity();
        onPlatform=false;
    }
}

void Entity::speedControl(){
    if(vel.x>MAX_VEL.x){
        vel.x = MAX_VEL.x;
    }
    else if(vel.x<-MAX_VEL.x){
        vel.x = -MAX_VEL.x;
    }
}

void Entity::stopMoveX(){
    vel.x=0;
    acc.x=0;
}

void Entity::wallWrap(){
    if(pos.x<-10){
        pos.x=ofGetWidth()-110;
    }
    else if(pos.x>ofGetWidth()-110){
        pos.x=-10;
    }
}

bool Entity::checkWall(){
    if(pos.x<-9 || pos.x>ofGetWidth()-111){
        return true;
    }
    return false;
}

bool Entity::checkEntity(Entity &_entity){
    if(_entity.pos.x+_entity.size.x/2>pos.x-size.x/2 &&
       _entity.pos.x-_entity.size.x/2<=pos.x+size.x/2 &&
       _entity.pos.y+_entity.size.y/2>pos.y-size.y/2 &&
       _entity.pos.y-_entity.size.y/2<pos.y+size.y/2){
        return true;
    }
    return false;
}