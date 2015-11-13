#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    text.loadFont(OF_TTF_SANS,20);
    
    for(int i=0; i<10;i++){
        platforms.push_back(Platform(ofVec2f(i*60, 500)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(player.moving){
        if(player.right){
            player.moveX(1);
        }
        else{
            player.moveX(-1);
        }
    }
    else{
        player.friction();
    }
    
    if(up){
        player.jump();
    }
    
    ene.onPlatform=false;
    player.onPlatform=false;
    for(auto &_platform: platforms){
        checkCollisions(_platform,&player);
        checkCollisions(_platform,&ene);
    }
    
    ene.moveX(1);
    ene.move();
    player.move();
    cout<<ofGetFrameNum()<<endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto &_platform: platforms){
        _platform.display();
//        cout<<_platform.size.x<<" "<<_platform.size.y<<endl;
    }
    player.display();
    ene.display();
    
    text.drawString("VelX:"+to_string(player.vel.x) +"\nVelY:"+ to_string(player.vel.y) +"\nAccX:"+ to_string(player.acc.x)+"\nPosX:"+ to_string(player.pos.x)+"\nPosY:"+ to_string(player.pos.y),100,100);
    
    text.drawString("VelX:"+to_string(ene.vel.x) +"\nVelY:"+ to_string(ene.vel.y) +"\nAccX:"+ to_string(ene.acc.x)+"\nPosX:"+ to_string(ene.pos.x)+"\nPosY:"+ to_string(ene.pos.y),400,100);
    
    text.drawString("SizeX:"+to_string(player.size.x) +"\nSizeY:"+to_string(player.size.y),700,100);
    
    text.drawString("SizeX:"+to_string(platforms[0].size.x) +"\nSizeY:"+to_string(platforms[0].size.y)+"\nPosX:"+to_string(platforms[0].pos.x)+"\nPosY:"+to_string(platforms[0].pos.y),100,300);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT){
        player.right = true;
        player.moving = true;
    }
    else if(key == OF_KEY_LEFT){
        player.right = false;
        player.moving = true;
    }
    if(key == OF_KEY_UP || key == 'z'){
        up = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_UP || key == 'z'){
        up = false;
    }
    if(key == OF_KEY_RIGHT || key == OF_KEY_LEFT){
        player.moving = false;
    }
}


void ofApp::checkCollisions(Tile _platform, Entity *_entity){
    if(_platform.detectLeft(_entity)){
        _entity->pos.x-=5;
    }
    else if(_platform.detectRight(_entity)){
        _entity->pos.x+=5;
    }
    if(_platform.detectTop(_entity)){
        _entity->action = false;
        _entity->vel.y=0;
        _entity->acc.y=0;
        _entity->pos.y=_platform.pos.y-_platform.size.y/2-_entity->size.y/2;
    }
    else if(_platform.detectBottom(_entity)){
        cout<<"Bottom!! "<< _platform.pos.x <<endl;
    }
    
    if(_platform.detectAboveTop(_entity)){
        _entity->onPlatform=true;
        cout<<"Above"<<endl;
    }
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
