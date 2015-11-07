//
//  Platform.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Platform.h"

Platform::Platform():Tile(){
    gameSprite = Sprite("sprites/misc/");
    getSize();
}

Platform::Platform(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite("sprites/misc/");
    getSize();
}