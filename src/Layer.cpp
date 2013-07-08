#include "Layer.hpp"
#include "DrawableEntity.hpp"

using namespace tbd;

Layer::Layer() : Screen(){
    setNormalizedCoordinates(true,1);
    
}

void Layer::addEntity(DrawableEntity* de) {
    addChild((Polycode::ScreenEntity*)de->mydrawer);
    de->mylayer=this;
}

void Layer::removeEntity(DrawableEntity* de) {
    removeChild((Polycode::ScreenEntity*)de->mydrawer);
}
