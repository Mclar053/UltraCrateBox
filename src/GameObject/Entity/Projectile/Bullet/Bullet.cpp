//
//  Bullet.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 19/11/2015.
//
//

#include "Bullet.h"

Bullet::Bullet(){
    gameSprite = Sprite(0,0,0,0,"sprites/entities/projectiles/bullet/");
    getSize();
}

Bullet::Bullet(ofVec2f _pos, int &_dir):Projectile(_pos,_dir){
    gameSprite = Sprite(0,0,0,0,"sprites/entities/projectiles/bullet/");
    getSize();
}