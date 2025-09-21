#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

		auto confPos = Mod::get()->getSettingValue<std::string>("version-position");
		auto confOpacity = Mod::get()->getSettingValue<double>("version-opacity");
		auto confDebug = Mod::get()->getSettingValue<bool>("debug-enabled");
		
		// Got some help in DMs with this, cpp really isnt that intuitive to me.
		auto curGDVer = "v" + Loader::get()->getGameVersion() + "\n" + "cocos: " + cocos2d::cocos2dVersion();
		auto verLabel = CCLabelBMFont::create(curGDVer.c_str(), "bigFont.fnt");
		
		auto menuHeight = getContentHeight();
		auto menuWidth = getContentWidth();

		// Here for making sure I actually got what values I wanted
		if (confDebug == true) {
			log::debug("Position: {}", confPos);
			log::debug("Main Menu Height: {}", menuHeight);
			log::debug("Main Menu Width: {}", menuWidth);
			log::debug("Opacity: {}", confOpacity);
			log::debug("Game Version: {}", curGDVer);
		}

		// There is probably a better way of implementing this but it works and doesnt look that bad (at least to me)
		if (confPos == "Top Left") {
			verLabel->setPosition(0, menuHeight);
			verLabel->setAnchorPoint({-0.05f, 1.05f});
		}
		if (confPos == "Top Right") {
			verLabel->setPosition(menuWidth, menuHeight);
			verLabel->setAnchorPoint({1.05f, 1.05f});
		}
		if (confPos == "Bottom Left") {
			verLabel->setPosition(0, 0);
			verLabel->setAnchorPoint({-0.05f, -0.2f});
		}
		if (confPos == "Bottom Right") {
			verLabel->setPosition(menuWidth, 0);
			verLabel->setAnchorPoint({1.05f, -0.2f});	
		}

		verLabel->setScale(0.25f);
		verLabel->setOpacity(confOpacity);
		verLabel->setID("game-version-label");
        this->addChild(verLabel);

        return true;
    }
};
