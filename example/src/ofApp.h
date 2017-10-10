#pragma once

#include "ofMain.h"
#include "ofxGLSLSimplexNoise.h"
#include "ofxGui.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxGLSLSimplexNoise noise;    
	ofxPanel gui;
	ofxFloatSlider freqRX;
	ofxFloatSlider freqRY;
	ofxFloatSlider freqGX;
	ofxFloatSlider freqGY;
	ofxFloatSlider freqBX;
	ofxFloatSlider freqBY;
	ofxFloatSlider speedR;
	ofxFloatSlider speedG;
	ofxFloatSlider speedB;
	ofxFloatSlider mulR;
	ofxFloatSlider mulG;
	ofxFloatSlider mulB;
	ofxFloatSlider addR;
	ofxFloatSlider addG;
	ofxFloatSlider addB;
	ofxFloatSlider colorRR;
	ofxFloatSlider colorRG;
	ofxFloatSlider colorRB;
	ofxFloatSlider colorGR;
	ofxFloatSlider colorGG;
	ofxFloatSlider colorGB;
	ofxFloatSlider colorBR;
	ofxFloatSlider colorBG;
	ofxFloatSlider colorBB;

	bool showGui;
};
