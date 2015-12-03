#pragma once

#include "ofMain.h"
#include "GameObject/Entity/Player/Player.h"
#include "GameObject/Entity/Enemy/Drone/Drone.h"
#include "GameObject/Entity/Enemy/Tank/Tank.h"
#include "GameObject/Entity/Pickup/Pickup.h"
#include "GameObject/Tile/Platform/Platform.h"
#include "GameObject/Tile/Fire/Fire.h"
#include "Level/Level.h"
#include "Button/Button.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //Menu functions
    void drawButtons(int _buttonPos);
    void drawOptions();
    
    //Returns an image from the filepath provided
    ofImage getImage(string filepath);
    
    //Main control functions
    void entityControls();
    void collisions();

    //Checks collisions between entity and tiles
    void checkCollisions(Tile *_platform, Entity *_entity);
    void damageEnemies(Projectile &_projectile);

    //Creates objects in world from level
    void createLevel();
    
    //Resets the level
    void reset();

    //Signature of the player, enemies and pickup
    Player player;
    vector<Enemy*> enemies;
    Pickup pickup;
    
    int score; //Player score
    
    //Text for testing purposes
    ofTrueTypeFont optionsText;
    ofTrueTypeFont scoreText;
    ofTrueTypeFont *font;

    //Buttons for UI
    vector<vector<Button>> buttons;

    //Vector of Tile type objects
    vector<Tile*> platforms;

    //Level
    Level level;

    //Position offset
    ofVec2f posOffset;
    ofVec2f enemySpawn;

    bool gameOver;
    bool pause;
    int state; //Screen states
    bool up; //Allows player to jump
    
    ofSoundPlayer music; //Background music for the game
};
