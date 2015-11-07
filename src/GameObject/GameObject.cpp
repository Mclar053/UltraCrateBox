//
//  GameObject.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "GameObject.h"

GameObject::GameObject(){
    
}

void GameObject::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        gameSprite.display();
    glPopMatrix();
}

void GameObject::getSize(){
    size.set(gameSprite.sprite[gameSprite.currentFrame].getWidth(), gameSprite.sprite[gameSprite.currentFrame].getHeight());
}