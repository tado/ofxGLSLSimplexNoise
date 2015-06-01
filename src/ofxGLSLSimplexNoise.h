#pragma once
#include "ofMain.h"

class ofxGLSLSimplexNoise {
public:
    ofxGLSLSimplexNoise();
    void draw();
    
    ofShader shader;
    float freq;
    float mul;
    float add;
    ofVec2f shift;
};