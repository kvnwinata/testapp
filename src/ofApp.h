#pragma once

#include "ofMain.h"

#include "ofxOpenNI.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void exit() override;
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    
    ofxOpenNI   openNIDevice;
    
    // local textures
    ofTexture localColorFrame;
    ofTexture localDepthFrame;
    
    // remote textures
    ofTexture remoteColorFrame;
    ofTexture remoteDepthFrame;

    
};
