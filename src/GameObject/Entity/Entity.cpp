//
//  Entity.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Entity.h"

Entity::Entity(){
    
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