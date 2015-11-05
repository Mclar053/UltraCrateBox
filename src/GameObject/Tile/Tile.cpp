//
//  Tile.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#include "Tile.h"

Tile::Tile(){
    pos.set(100, 100);
}

Tile::Tile(ofVec2f _pos){
    pos = _pos;
}