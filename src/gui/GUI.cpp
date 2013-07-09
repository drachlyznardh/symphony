#include "GUI.hpp"
#include "../MissionManager.hpp"
#include "../Layer.hpp"
#include "../Input.hpp"
#include "Cursor.hpp"
#include "HPMonitor.hpp"
using namespace tbd;

GUI::GUI(MissionManager* mm) : missionmanager(mm){
}

void GUI::Init(){
    layer=new Layer();
    cursor=new Cursor();
    layer->addEntity(cursor);
    label=new HPMonitor(missionmanager->spaceship);
    layer->addEntity(label);
}

void GUI::Update(double elapsed){
    cursor->Update(elapsed);
    label->Update(elapsed);
}

GUI::~GUI(){
    delete cursor;    
    delete layer;
}