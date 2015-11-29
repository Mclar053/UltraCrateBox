//
//  Tank.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 29/11/2015.
//
//

#ifndef __UltraCrateBox__Tank__
#define __UltraCrateBox__Tank__

#include "../Enemy.h"
#include <stdio.h>

class Tank: public Enemy{
public:
    Tank(ofVec2f _pos);
};

#endif /* defined(__UltraCrateBox__Tank__) */
