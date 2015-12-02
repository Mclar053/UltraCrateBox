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
    
    void display(ofTrueTypeFont *_font);
    void setText(string _text);
    void setFont(int _fontSize);
    
    bool clicked(float _mouseX, float _mouseY);
    
    ofVec2f pos;
    ofVec2f size;
    int fontSize;
    string text;
};

#endif /* defined(__UltraCrateBox__Button__) */
