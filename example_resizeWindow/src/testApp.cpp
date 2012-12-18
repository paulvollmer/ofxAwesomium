#include "testApp.h"


void testApp::setup(){
	isResizing = false;
	
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
	webView->loadURL("http://www.google.com");
	
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
	
	isResizing = false;
}


void testApp::draw(){
    ofSetColor(255);
	if (isResizing == false) {
		webTex.draw(0, 0);
	}
	
    if (webView->isLoadingPage()) {
        ofSetColor(0);
        ofDrawBitmapString("Loading...", 10, ofGetHeight()-20);
    }
}


void testApp::windowResized(int w, int h){
	isResizing = true;
	webTexWidth = w;
	webTexHeight = h;
	webTex.allocate(w, h, GL_RGBA);
	
	webView->resize(w, h);
	webCore->update();
}
