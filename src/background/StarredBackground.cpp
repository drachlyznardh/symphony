/* 
 * File:   StarredBackground.cpp
 * Author: alessio
 * 
 */

#include "StarredBackground.hpp"
#include "StarEntity.hpp"
#include "StarDrawer.hpp"
#include "../Utilities.hpp"
#include "../Layer.hpp"
using namespace tbd;

tbd::StarredBackground::StarredBackground(Layer* l): Background(l) {
    remaining=0.0;
    layer=l;
    for(int i=0;i<40;i++){
        StarEntity* s=addStar();
        s->x=randomDouble(-xMargin,xMargin);
    }
}

StarEntity* tbd::StarredBackground::addStar(){
    double size=randomDouble(0.005,0.02);
    StarEntity* se=new StarEntity(new StarDrawer(size),xMargin+0.04);
    stars.push_back(se);
    layer->addEntity(se);
    return se;
}

void tbd::StarredBackground::Update(double elapsed){
    remaining-=elapsed;
    if(remaining<=0){
        addStar();
        remaining=period;
    }
    for(StarEntity* s:stars){
        s->Update(elapsed);
    }
    vector<StarEntity*> toDelete;
    for(StarEntity* s:stars){
        if(s->x<-xMargin-0.04){
            toDelete.push_back(s);
        }
    }
    for(StarEntity* s:toDelete){
        s->removeFromLayer();
        stars.erase(remove(stars.begin(),stars.end(),s),stars.end());
        delete s;
    }
}

