#include "Cursor.hpp"
#include "../graphics/SimpleSprite.hpp"
#include "../Input.hpp"

using namespace tbd;

Cursor::Cursor(): DrawableEntity(new tbd::SimpleSprite(RESOURCE(cursor.png),0.05)) {
}

void Cursor::Update(double elapsed){
    x=Input::get()->X();
    y=Input::get()->Y();
}
