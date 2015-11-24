//
//  Projectile.cpp
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#include "Projectile.h"

Projectile::Projectile(ofVec2f _pos, int &_dir, string _type, int _damage):Entity(_pos){
    gameSprite = Sprite(0,0,0,0,"sprites/entities/projectiles/"+_type+"/");
    getSize();
    moving = true;
    direction = _dir;
    gravity = 0;
    action = true;
    MAX_VEL.set(10, 0);
    vel.set(direction*2, 0);
    moveX(direction);
    explosionRadius = checkExplodeRadius(_type);
}

void Projectile::sineMe(){
    vel.y = sin(ofGetFrameNum())*5;
}

int Projectile::checkExplodeRadius(string _type){
    if(_type=="bullet"){return 1;}
    else if(_type=="explosive"){return 50;}
    else if(_type=="laser"){return 5;}
    else{return 0;}
}
