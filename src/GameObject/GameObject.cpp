//
//  GameObject.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "GameObject.h"

GameObject::GameObject(){
//    Sprite gameSprite;
    
}

void GameObject::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        gameSprite.display();
        gameSprite.moveNextFrame();
    glPopMatrix();
}