//
//  Projectile.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Projectile.h"

Projectile::Projectile(ofVec2f _pos, int &_dir, int _damage):Entity(_pos){
    moving = true;
    direction = _dir;
    gravity = 0;
    action = true;
    MAX_VEL.set(10, 0);
    vel.set(direction*2, 0);
    moveX(direction);
}

void Projectile::sineMe(){
    vel.y = sin(ofGetFrameNum())*5;
}