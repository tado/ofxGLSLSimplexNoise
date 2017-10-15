#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
    ofBackground(0);
	showGui = true;

	//gui
	gui.setup();
	gui.add(freqRX.setup("Freq R X", 0.5, 0.0, 2.0));
	gui.add(freqRY.setup("Freq R Y", 0.5, 0.0, 2.0));
	gui.add(freqGX.setup("Freq G X", 0.5, 0.0, 2.0));
	gui.add(freqGY.setup("Freq G Y", 0.5, 0.0, 2.0));
	gui.add(freqBX.setup("Freq B X", 0.5, 0.0, 2.0));
	gui.add(freqBY.setup("Freq B Y", 0.5, 0.0, 2.0));
	gui.add(speedR.setup("speed R", 0.5, 0.0, 1.0));
	gui.add(speedG.setup("speed G", 0.5, 0.0, 1.0));
	gui.add(speedB.setup("speed B", 0.5, 0.0, 1.0));
	gui.add(mulR.setup("multiple R", 1.0, 0.0, 2.0));
	gui.add(mulG.setup("multiple G", 1.0, 0.0, 2.0));
	gui.add(mulB.setup("multiple B", 1.0, 0.0, 2.0));
	gui.add(addR.setup("add R", 1.0, 0.0, 2.0));
	gui.add(addG.setup("add G", 1.0, 0.0, 2.0));
	gui.add(addB.setup("add B", 1.0, 0.0, 2.0));
	gui.add(colorRR.setup("color RR", 0.5, 0.0, 1.0));
	gui.add(colorRG.setup("color RG", 0.5, 0.0, 1.0));
	gui.add(colorRB.setup("color RB", 0.5, 0.0, 1.0));
	gui.add(colorGR.setup("color GR", 0.5, 0.0, 1.0));
	gui.add(colorGG.setup("color GG", 0.5, 0.0, 1.0));
	gui.add(colorGB.setup("color GB", 0.5, 0.0, 1.0));
	gui.add(colorBR.setup("color BR", 0.5, 0.0, 1.0));
	gui.add(colorBG.setup("color BG", 0.5, 0.0, 1.0));
    gui.add(colorBB.setup("color BB", 0.5, 0.0, 1.0));
    gui.add(alpha.setup("alpha", 1.0, 0.0, 1.0));

	gui.loadFromFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::update() {
	noise.freqR.set(freqRX, freqRY);
	noise.freqG.set(freqGX, freqGY);
	noise.freqB.set(freqBX, freqBY);
	noise.speed.set(speedR, speedG, speedB);
	noise.mul.set(mulR, mulG, mulB);
	noise.add.set(addR, addG, addB);
	noise.colorR.set(colorRR, colorRG, colorRB);
	noise.colorG.set(colorGR, colorGG, colorGB);
	noise.colorB.set(colorBR, colorBG, colorBB);
    noise.alpha = alpha;
}

//--------------------------------------------------------------
void ofApp::draw() {
	noise.draw();
	if (showGui) {
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'g') {
		if (showGui) {
			showGui = false;
		}
		else {
			showGui = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
