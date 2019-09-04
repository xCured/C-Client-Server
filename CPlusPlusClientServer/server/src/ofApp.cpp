#include "ofApp.h"




//--------------------------------------------------------------
void ofApp::setup() {
	receiver.setup(PORT);
	ofBackground(0, 0, 0);

	if (PewPews.size() == 0) {

		for (int i = 0; i < 4; i++) {

			PewPews.push_back(new rocket(200 * ofRandom(1, 4), ofGetWindowHeight() / 3));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	// check for waiting messages
	while (receiver.hasWaitingMessages()) {
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);
		std::cout << "Got a message! " << m.getAddress() << std::endl;
		// check for rocket message
		if (m.getAddress() == "/rocket") {
			// call your addRocket function here!
			addRocket();
		}
	}

	for (int j = 0; j < PewPews.size(); j++) {
		PewPews[j]->update();
	}
}
//--------------------------------------------------------------
void ofApp::draw() {
	for (int j = 0; j < PewPews.size(); j++) {
		PewPews[j]->draw();
	}
}
void ofApp::addRocket()
{
	for (int i = 0; i < 4; i++) {

		PewPews.push_back(new rocket(200 * ofRandom(1, 4), ofGetWindowHeight() / 3));
	}
}


