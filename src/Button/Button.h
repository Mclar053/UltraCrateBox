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
    Button(ofVec2f _pos, ofVec2f _size);
    Button(ofVec2f _pos, ofVec2f _size, string _text, int _fontSize);
    
    void display();
    void setText(string _text);
    void setFont(int _size);
    
    bool clicked(float _mouseX, float _mouseY);
    
    ofVec2f pos;
    ofVec2f size;
    ofTrueTypeFont font;
    string text;
};

#endif /* defined(__UltraCrateBox__Button__) */
