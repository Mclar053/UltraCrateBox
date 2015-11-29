//
//  Fire.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 07/11/2015.
//
//

#ifndef __UltraCrateBox__Fire__
#define __UltraCrateBox__Fire__

#include "../Tile.h"
#include <stdio.h>

//This is a placeholder. Will work on later

//Fire inherits from Tile
class Fire: public Tile{
public:
    Fire();
    Fire(ofVec2f _pos);
    
    void display();
};

#endif /* defined(__UltraCrateBox__Fire__) */
