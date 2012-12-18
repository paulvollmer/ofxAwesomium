#pragma once

#include "ofMain.h"
#include <Awesomium/WebCore.h>


class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void exit();
	void windowResized(int w, int h);
	
	
private:
	Awesomium::WebView* webView;
	Awesomium::WebCore* webCore;
	
	
	bool isResizing;
	
	int webTexWidth;
	int webTexHeight;
	ofTexture webTex;
};
