/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 15:47
 */

#include "Bala.h"

Bala::Bala() {
}

Bala::Bala(const Bala& orig) {
}

Bala::~Bala() {
}


void Bala::setBody(b2World * mundo, float x, float y){
    
    bdydef_.type = b2_dynamicBody;
    bdydef_.position = b2Vec2(x, y);

    bdy = mundo->CreateBody(&bdydef_);

}



