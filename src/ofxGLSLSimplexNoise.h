#pragma once

#define STRINGIFY(A) #A
#include "ofMain.h"

class ofxGLSLSimplexNoise {
public:
	ofxGLSLSimplexNoise();
	void draw();

	string frag;
	string vert;

	ofShader shader;
	ofVec2f freqR, freqG, freqB;
	ofVec3f speed;
	ofVec3f mul;
	ofVec3f add;
	ofVec3f colorR, colorG, colorB;
	ofFbo fbo;

	//ofVec2f shiftR, shiftG, shiftB;
};