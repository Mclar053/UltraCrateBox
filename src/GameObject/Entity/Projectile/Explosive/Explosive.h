//
//  Explosive.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__Explosive__
#define __UltraCrateBox__Explosive__

#include "../Projectile.h"
#include <stdio.h>

class Explosive: public Projectile{
public:
    Explosive(ofVec2f _pos, int &_dir, int _damage);
};

#endif /* defined(__UltraCrateBox__Explosive__) */
