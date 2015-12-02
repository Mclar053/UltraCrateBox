//
//  Button.h
//  UltraCrateBox
//
//  Created by Matthew Clark on 30/11/2015.
//
//

#ifndef __UltraCrateBox__Button__
#define __UltraCrateBox__Button__

#include "../ofMain.h"
#include <stdio.h>

class Button{
public:
    Button(){};
    Button(ofVec2f _pos, ofVec2f _size, string _text);
    Button(ofVec2f _pos, ofVec2f _size, string _text, ofColor _col);
    
    void display(ofTrueTypeFont *_font);
    
    bool clicked(float _mouseX, float _mouseY);
    
    ofVec2f pos;
    ofVec2f size;
    int fontSize;
    string text;
    ofColor colour;
};

#endif /* defined(__UltraCrateBox__Button__) */
