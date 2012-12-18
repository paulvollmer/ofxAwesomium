#include "testApp.h"


void testApp::setup(){
	webTexWidth = ofGetWindowWidth();
	webTexHeight = ofGetWindowHeight();
    webTex.allocate(webTexWidth, webTexHeight, GL_RGBA);
    
    // Disable scrollbars via the WebCoreConfig
    Awesomium::WebCoreConfig config;
    //config.setCustomCSS("::-webkit-scrollbar { display: none; }");
    
	// Create our WebCore singleton with the default options
	webCore = new Awesomium::WebCore(config);
	
	// Create a new WebView instance with a certain width and height, using the
	// WebCore we just created
	webView = webCore->createWebView(webTexWidth, webTexHeight);
	
	// Load a certain URL into our WebView instance
	webView->loadURL("http://www.codecademy.com/");
	
	webView->focus();
}


void testApp::exit(){
    // Destroy our WebView instance
	webView->destroy();
	delete webCore;
}


void testApp::update(){
    webCore->update();
    
    // Call our display func when the WebView needs rendering
	if (webView->isDirty()) {
        const Awesomium::RenderBuffer* renderBuffer = webView->render();
        if (renderBuffer) {
            webTex.loadData(renderBuffer->buffer, webTexWidth, webTexHeight, GL_BGRA);
        }
    }
}


void testApp::draw(){
    ofSetColor(255);
	webTex.draw(0, 0);
	
    if (webView->isLoadingPage()) {
        ofSetColor(0);
        ofDrawBitmapString("Loading...", 10, ofGetHeight()-20);
    }
	
	ofEnableAlphaBlending();
	ofSetColor(ofColor::black, 127);
	ofRect(0, 0, ofGetWindowWidth(), 30);
	ofDisableAlphaBlending();
	ofSetColor(ofColor::white);
	ofDrawBitmapString("Press 'c' for Copy, 'p' for Paste", 50, 20);
}


void testApp::keyPressed(int key){
	switch (key) {
		case 'c':
			webView->copy();
			break;
		case 'v':
			webView->paste();
			break;
	}
}


void testApp::keyReleased(int key){

}


void testApp::mouseMoved(int x, int y ){
    webView->injectMouseMove(x, y);
}


void testApp::mouseDragged(int x, int y, int button){
    webView->injectMouseMove(x, y);
}


void testApp::mousePressed(int x, int y, int button){
    webView->injectMouseDown(Awesomium::LEFT_MOUSE_BTN);
}


void testApp::mouseReleased(int x, int y, int button){
    webView->injectMouseUp(Awesomium::LEFT_MOUSE_BTN);
}


void testApp::windowResized(int w, int h){

}
