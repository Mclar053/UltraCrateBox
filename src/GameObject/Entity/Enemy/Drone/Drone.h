//
//  Drone.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 29/11/2015.
//
//

#ifndef __UltraCrateBox__Drone__
#define __UltraCrateBox__Drone__

#include "../Enemy.h"
#include <stdio.h>

class Drone: public Enemy{
public:
    Drone(ofVec2f _pos);
};

#endif /* defined(__UltraCrateBox__Drone__) */
