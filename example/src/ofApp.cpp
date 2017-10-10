#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

	//gui
	gui.setup();
	gui.add(freqRX.setup("Freq R X", 0.5, 0.0, 1.0));
	gui.add(freqRY.setup("Freq R Y", 0.5, 0.0, 1.0));
	gui.add(freqGX.setup("Freq G X", 0.5, 0.0, 1.0));
	gui.add(freqGY.setup("Freq G Y", 0.5, 0.0, 1.0));
	gui.add(freqBX.setup("Freq B X", 0.5, 0.0, 1.0));
	gui.add(freqBY.setup("Freq B Y", 0.5, 0.0, 1.0));
	gui.add(speedR.setup("speed R", 0.5, 0.0, 1.0));
	gui.add(speedG.setup("speed G", 0.5, 0.0, 1.0));
	gui.add(speedB.setup("speed B", 0.5, 0.0, 1.0));
	gui.add(mulR.setup("multiple R", 1.0, 0.0, 2.0));
	gui.add(mulG.setup("multiple G", 1.0, 0.0, 2.0));
	gui.add(mulB.setup("multiple B", 1.0, 0.0, 2.0));

	gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	noise.freqR.set(freqRX, freqRY);
	noise.freqG.set(freqGX, freqGY);
	noise.freqB.set(freqBX, freqBY);
	noise.speed.set(speedR, speedG, speedB);
	noise.mul.set(mulR, mulG, mulB);
}

//--------------------------------------------------------------
void ofApp::draw(){
    noise.draw();
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
