/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 15:46
 */

#include "Weapon.h"
#include "Box2D/Box2D.h"
#include <iostream>

Weapon::Weapon() {
   
    tiempo= new Time;
    reloj= new Clock;
    
    cogida=false;
   
    
}

Weapon::Weapon(const Weapon& orig) {
}

Weapon::~Weapon() {
}


void Weapon::setBody(b2World * mundo, float x, float y){
    
    bdydef_.type = b2_kinematicBody;
    bdydef_.position = b2Vec2(x, y);
    bdy = mundo->CreateBody(&bdydef_);

}

void Weapon::Update(b2Vec2 vector){
  
    
    
}

