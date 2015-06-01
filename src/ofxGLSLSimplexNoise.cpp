#include "ofxGLSLSimplexNoise.h"

ofxGLSLSimplexNoise::ofxGLSLSimplexNoise(){   
    shader.load("../../../../../addons/ofxGLSLSimplexNoise/shaders/simplexnoise.vert", "../../../../../addons/ofxGLSLSimplexNoise/shaders/simplexnoise.frag");
    freqR.set(1.0, 1.0);
    freqG.set(1.0, 1.0);
    freqB.set(1.0, 1.0);
    shiftR.set(0.0, 0.0);
    shiftG.set(0.0, 0.0);
    shiftB.set(0.0, 0.0);
    mul.set(1.0, 1.0, 1.0);
    add.set(0.0, 0.0, 0.0);
    speed.set(1.0, 1.0, 1.0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
}

void ofxGLSLSimplexNoise::draw(){
    fbo.begin();
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform3f("freqR", freqR.x, freqR.y, 1.0);
    shader.setUniform3f("freqG", freqG.x, freqG.y, 1.0);
    shader.setUniform3f("freqB", freqB.x, freqB.y, 1.0);
    shader.setUniform2f("shiftR", shiftR.x, shiftR.y);
    shader.setUniform2f("shiftG", shiftG.x, shiftR.y);
    shader.setUniform2f("shiftB", shiftB.x, shiftR.y);
    shader.setUniform3f("mul", mul.x, mul.y, mul.z);
    shader.setUniform3f("add", add.x, add.y, add.z);
    shader.setUniform3f("speed", speed.x, speed.y, speed.z);

    ofScale(ofGetWidth(), ofGetWidth());
    ofRect(0, 0, 1.0, 1.0);
    shader.end();
    fbo.end();
    
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}
