//
//  Platform.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#ifndef __UltraCrateBox__Platform__
#define __UltraCrateBox__Platform__

#include "../Tile.h"
#include <stdio.h>

class Platform: public Tile{
public:
    Platform();
    Platform(ofVec2f);
};

#endif /* defined(__UltraCrateBox__Platform__) */
