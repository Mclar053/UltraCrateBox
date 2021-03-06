//
//  Tile.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 05/11/2015.
//
//

#ifndef __UltraCrateBox__Tile__
#define __UltraCrateBox__Tile__

//Includes GameObject reference in Entity
#include "../GameObject.h"
#include "../Entity/Entity.h"
#include <stdio.h>

//Base class of all tiles

//Tile inherits from GameObject
class Tile: public GameObject{
public:
    /*Constructors*/
    Tile();
    Tile(ofVec2f _pos);
    
    /*Methods*/
    //Tile-Entity collision
    bool detectLeft(Entity *_entity);
    bool detectRight(Entity *_entity);
    bool detectTop(Entity *_entity);
    bool detectBottom(Entity *_entity);
    bool detectAboveTop(Entity *_entity);
    
    //Gets size of gamesprite (Seemed to not work with the GameObject version. Not sure why)
    void getSize();
    
    /*Properties*/
    ofVec2f size;
    
};

#endif /* defined(__UltraCrateBox__Tile__) */
