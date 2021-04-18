

#include "AppDelegate.h"
#include "MainGame.h"

// #define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#endif
}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};
    GLView::setGLContextAttrs(glContextAttrs);
}


bool AppDelegate::applicationDidFinishLaunching() {
    initOpenGL();
    initDirector();
    initMultiResolution();
    createAndRunScene();
    return true;
}


void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#endif
}


void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#endif
}
void AppDelegate::initMultiResolution() {
    auto director = Director::getInstance();
    auto glview= director->getOpenGLView();
    glview->setDesignResolutionSize(
            designResolutionSize.width,
            designResolutionSize.height,
            ResolutionPolicy::NO_BORDER
            );

    std::vector<std::string> searchPaths;
    float scaleFactor = 1.0f;
    Size frameSize= glview->getFrameSize();
    if(frameSize.height> mediumResolutionSize.height){
        searchPaths.push_back("res/HDR");
        scaleFactor = largeResolutionSize.height/designResolutionSize.height;
    } else if (frameSize.height > smallResolutionSize.height) {
        searchPaths.push_back("res/HD");
        scaleFactor = mediumResolutionSize.height / designResolutionSize.height;
    } else {
        searchPaths.push_back("res/SD");
        scaleFactor = smallResolutionSize.height / designResolutionSize.height;
    }
    director->setContentScaleFactor(scaleFactor);
    FileUtils::getInstance()->setSearchPaths(searchPaths);

}
void AppDelegate::initOpenGL() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) ||(CC_TARGET_PLATFORM == CC_PLATFORM_MAC) ||(CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("zghost",
            Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
        #else
        glview = GLViewImpl::create("ninj");
        #endif
        director->setOpenGLView(glview);
        }
}
void AppDelegate::initDirector() {
    auto director= Director::getInstance();
    director->setAnimationInterval(1 / 60);
    director->setDisplayStats(true);
}
void AppDelegate::createAndRunScene() {
    auto scene= MainGame::createScene();
    Director::getInstance()->runWithScene(scene);
}

