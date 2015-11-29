#pragma once

#include "ofMain.h"
#include "GameObject/Entity/Player/Player.h"
#include "GameObject/Entity/Enemy/Drone/Drone.h"
#include "GameObject/Entity/Enemy/Tank/Tank.h"
#include "GameObject/Entity/Pickup/Pickup.h"
#include "GameObject/Tile/Platform/Platform.h"
#include "GameObject/Tile/Fire/Fire.h"
#include "Level/Level.h"

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
    void drawMenu();
    void drawOptions();
    
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
    
    int score;

    //Text for testing purposes
    ofTrueTypeFont text;
    ofTrueTypeFont scoreText;

    //Vector of Tile type objects
    vector<Tile*> platforms;

    //Level
    Level level;

    //Position offset
    ofVec2f posOffset;
    ofVec2f enemySpawn;

    bool gameOver;
    int state;
    bool up;
};
