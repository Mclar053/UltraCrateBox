//
//  Bullet.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#ifndef __UltraCrateBox__Bullet__
#define __UltraCrateBox__Bullet__

#include "../Projectile.h"
#include <stdio.h>

class Bullet: public Projectile{
public:
    Bullet(ofVec2f _pos, int &_dir, int _damage);
};

#endif /* defined(__UltraCrateBox__Bullet__) */
