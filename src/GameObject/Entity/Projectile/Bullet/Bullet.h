//
//  Bullet.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 19/11/2015.
//
//

#ifndef __UltraCrateBox__Bullet__
#define __UltraCrateBox__Bullet__

#include "../Projectile.h"
#include <stdio.h>

class Bullet: public Projectile{
public:
    Bullet();
    Bullet(ofVec2f _pos, int &_dir);
};

#endif /* defined(__UltraCrateBox__Bullet__) */
