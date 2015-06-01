#pragma once
#include "ofMain.h"

class ofxGLSLSimplexNoise {
public:
    ofxGLSLSimplexNoise();
    void draw();
    
    ofShader shader;
    ofVec2f freqR, freqG, freqB;
    ofVec2f shiftR, shiftG, shiftB;
    ofVec3f mul;
    ofVec3f add;
    ofVec3f speed;
    ofFbo fbo;
};