//
//  Projectile.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Projectile.h"

Projectile::Projectile(){
    gameSprite = Sprite(0,0,0,0,"sprites/entities/projectiles/bullet/");
    getSize();
    moving = true;
    direction = 1;
    gravity = 0;
    action = true;
    MAX_VEL.set(50, 0);
    moveX(direction);
}

Projectile::Projectile(ofVec2f _pos, int &_dir):Entity(_pos){
    gameSprite = Sprite(0,0,0,0,"sprites/entities/projectiles/bullet/");
    getSize();
    moving = true;
    direction = _dir;
    gravity = 0;
    action = true;
    MAX_VEL.set(50, 0);
    moveX(direction);
}