#include "ofxGLSLSimplexNoise.h"

ofxGLSLSimplexNoise::ofxGLSLSimplexNoise(){   
    shader.load("../../../shaders/simplexnoise.vert", "../../../shaders/simplexnoise.frag");
    freq.set(1.0, 1.0);
    mul = 1.0;
    add = 0.0;
    shift.set(0.0, 0.0);
}

void ofxGLSLSimplexNoise::draw(){
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform3f("freq", freq.x, freq.y, 1.0);
    shader.setUniform1f("mul", mul);
    shader.setUniform1f("add", add);
    shader.setUniform2f("shift", shift.x, shift.y);
    ofScale(ofGetWidth(), ofGetWidth());
    ofRect(0, 0, 1.0, 1.0);
    shader.end();
}
