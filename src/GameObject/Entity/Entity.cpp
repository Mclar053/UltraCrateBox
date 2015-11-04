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
}

void Entity::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        glScalef(direction, 1, 1);
        gameSprite.display();
        if(!action){
            gameSprite.moveNextFrame();
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
    if(vel.x>0.1){
        acc.x=-0.1;
    }
    else if(vel.x<-0.1){
        acc.x=0.1;
    }
    else{
        stopMoveX();
    }
}

void Entity::move(){
    vel+=acc;
    pos+=vel;
}

void Entity::stopMoveX(){
    vel.x=0;
    acc.x=0;
}