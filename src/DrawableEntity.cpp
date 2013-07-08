#include "DrawableEntity.hpp"
#include "graphics/Drawer.hpp"
#include "Layer.hpp"
#include <iostream>
#include <utility>
#include "Utilities.hpp"

using namespace tbd;
using namespace std;

pair<double, double> DrawableEntity::computeTotalPosition(DrawableEntity* father){
    double r=father->rotation;
    double r2=r*toRad;
    double x2=x*cos(r2)-y*sin(r2);
    double y2=x*sin(r2)+y*cos(r2);
    return make_pair(x2+father->x,y2+father->y);
}


DrawableEntity::DrawableEntity(Drawer* drawer) {
    drawer->myEntity = this;
    mydrawer = drawer;
}

void DrawableEntity::removeFromLayer() {
    if (mylayer) {
        mylayer->removeChild(mydrawer);
        mylayer = 0;
    }
}

DrawableEntity::~DrawableEntity(){
    removeFromLayer();
    delete mydrawer;
}

void DrawableEntity::copyPosition(DrawableEntity* other){
    x=other->x;
    y=other->y;
}