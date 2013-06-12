/* 
 * File:   GUI.cpp
 * Author: alessio
 * 
 */

#include "GUI.hpp"
#include "../MissionManager.hpp"
#include "../Layer.hpp"
#include "../Input.hpp"
#include "Cursor.hpp"
using namespace tbd;

GUI::GUI(MissionManager* mm) : missionmanager(mm){
}

void GUI::Init(){
    layer=new Layer();
    cursor=new Cursor();
    layer->addEntity(cursor);
}

void GUI::Update(double elapsed){
    cursor->Update(elapsed);
}

GUI::~GUI(){
    delete cursor;    
    delete layer;
}