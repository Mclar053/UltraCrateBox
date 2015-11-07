//
//  Entity.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Entity.h"

Entity::Entity(){
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
    vel+=acc;
    speedControl();
    yControl();
    pos+=vel;
    wallWrap();
}

void Entity::moveX(int _dir){
    direction = _dir;
    if(moving){
        acc.set(_dir*0.5,acc.y);
    }
}

void Entity::yControl(){
    if(pos.y<500){
        applyGravity();
        hitFloor = false;
    }
    else if(pos.y>501 && !hitFloor){
        action = false;
        hitFloor = true;
        vel.y=0;
        acc.y = 0;
        pos.y=500.5;
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

void Entity::checkCollision(){
    
}

void Entity::wallWrap(){
    if(pos.x<-10){
        pos.x=ofGetWidth()+10;
    }
    else if(pos.x>ofGetWidth()+10){
        pos.x=-10;
    }
}