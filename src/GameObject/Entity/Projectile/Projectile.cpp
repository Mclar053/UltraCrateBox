//
//  Projectile.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Projectile.h"

Projectile::Projectile(ofVec2f _pos, int &_dir, int _damage):Entity(_pos),damage(_damage){
    moving = true;
    direction = _dir;
    gravity = 0;
    action = true;
    MAX_VEL.set(10, 0);
    vel.set(direction*2, 0);
    moveX(direction);
}

//Moves projectile in a sine wave
void Projectile::sineMe(){
    vel.y = sin(sinCount++)*10;
}