#ofxAwesomium#
how to use [awesomium](http://awesomium.com/) framework with openFrameworks.  
this is not an addon, it is a collection of examples. everyone is invited to add new awesomiumish examples.  
inspired by Jeff Crouse [CodeForArt awesomiumExample](https://github.com/jefftimesten/CodeForArt/tree/master/Chapter011-web/020-awesomiumExample).  

**Install**  
clone the repository into the openFrameworks addons directory.
```
$ git clone git@github.com:WrongEntertainment/ofxAwesomium.git
```
download the awesomium framework.  
http://awesomium.com/download/  
add awesomium framework to repository root directory.  

OSX users:  You'll need to put this into project settings > Build Phases > Run Script  
It will copy the Awesomium.framework into the application bundle.  
```
cp -r "$TARGET_BUILD_DIR/../Awesomium.framework" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Frameworks/"
```
  
**Tested Frameworks**  
awesomium framework version 1.6.5  
openFrameworks version 0073  

**Tested Platforms**  
Mac OS 10.7  


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/WrongEntertainment/ofxawesomium/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

