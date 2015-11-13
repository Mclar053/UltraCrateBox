//
//  Platform.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Platform.h"

Platform::Platform():Tile(){
    gameSprite = Sprite("sprites/tiles/platform/");
    getSize();
}

Platform::Platform(ofVec2f _pos):Tile(_pos){
    gameSprite = Sprite("sprites/tiles/platform/");
    getSize();
}