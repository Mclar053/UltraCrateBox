//
//  Sprite.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 03/11/2015.
//
//

#ifndef __UltraCrateBox__Sprite__
#define __UltraCrateBox__Sprite__

#include <stdio.h>
#include "../ofMain.h"

class Sprite{
    
public:
    //Constructors
    Sprite();
    
    //Methods
    void display();
    void createSprite();
    
    //Properties
    vector<ofImage> sprite;
    int actionImage; //frame where game object has a single action e.g. jumping
};

#endif /* defined(__UltraCrateBox__Sprite__) */
