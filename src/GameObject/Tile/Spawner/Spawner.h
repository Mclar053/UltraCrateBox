//
//  Spawner.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 18/11/2015.
//
//

#ifndef __UltraCrateBox__Spawner__
#define __UltraCrateBox__Spawner__

#include "../Tile.h"
#include <stdio.h>

class Spawner: public Tile{
public:
    Spawner();
    Spawner(ofVec2f _pos);
};

#endif /* defined(__UltraCrateBox__Spawner__) */
