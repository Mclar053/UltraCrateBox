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

//Displays the gamesprite and places the sprite into the correct position on the screen
void GameObject::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        gameSprite.display();
    glPopMatrix();
}

//Gets size of gamesprite and sets the size to gamesprites current size
void GameObject::getSize(){
    size.set(gameSprite.sprite[gameSprite.currentFrame].getWidth(), gameSprite.sprite[gameSprite.currentFrame].getHeight());
}