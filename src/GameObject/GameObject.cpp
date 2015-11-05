//
//  GameObject.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "GameObject.h"

GameObject::GameObject(){
    size.set(gameSprite.sprite[0].getWidth(), gameSprite.sprite[0].getHeight());
}

void GameObject::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        gameSprite.display();
    glPopMatrix();
}