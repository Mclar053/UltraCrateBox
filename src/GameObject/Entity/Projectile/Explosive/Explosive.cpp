//
//  Explosive.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 24/11/2015.
//
//

#include "Explosive.h"

Explosive::Explosive(ofVec2f _pos, int &_dir, int _damage):Projectile(_pos, _dir, _damage){
    gameSprite = Sprite(0,0,0,0,"sprites/entities/projectiles/explosive/");
    getSize();
    explosionRadius = 30;
}