#include "SimpleText.hpp"
#include "../DrawableEntity.hpp"
#include <PolyScreenLabel.h>
#include <iostream>
#include <PolyCoreServices.h>
using namespace Polycode;
using namespace std;

tbd::SimpleText::SimpleText(const std::string& text, int size): Drawer(){
    sl= new ScreenLabel(text,size);
    sl->setPositionMode(ScreenEntity::POSITION_CENTER);
    addChild(sl);
    setScale(0.004);
}


void tbd::SimpleText::setText(const std::string& text){
    sl->setText(text);
}
