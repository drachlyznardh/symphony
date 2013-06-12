/* 
 * File:   Cursor.cpp
 * Author: alessio
 * 
 */

#include "Cursor.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Input.hpp"
using namespace tbd;
Cursor::Cursor(): DrawableEntity(new tbd::SimpleSprite("cursor.png",0.05)) {
}

void Cursor::Update(double elapsed){
    x=Input::get()->X();
    y=Input::get()->Y();
}
