//
//  GameObject.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__GameObject__
#define __UltraCrateBox__GameObject__

#include "../ofMain.h"
#include "../Sprite/Sprite.h"
#include <stdio.h>

class GameObject{
    
public:
    GameObject();
    //Methods
    void display();
    
    //Properties
    Sprite gameSprite;
    ofVec2f pos;
    ofVec2f size;
    int x;
    
};

#endif /* defined(__UltraCrateBox__GameObject__) */
