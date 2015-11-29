//
//  Fire.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 07/11/2015.
//
//

#include "Fire.h"

Fire::Fire():Tile(){
    
}

Fire::Fire(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite(0, 0, 4, 0, "sprites/tiles/fire/");
    getSize();
}

void Fire::display(){
    glPushMatrix();
        glTranslated(pos.x, pos.y, 0);
        gameSprite.display();
        gameSprite.moveNextFrame();
    glPopMatrix();
}