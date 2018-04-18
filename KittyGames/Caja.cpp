/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caja.cpp
 * Author: pedro
 * 
 * Created on 18 de abril de 2018, 17:33
 */

#include "Caja.h"

Caja::Caja(String nombre) {

    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);
    
}

Caja::Caja(const Caja& orig) {
}

Caja::~Caja() {
}

void Caja::setBody(b2World * mundo, float x, float y){
    
    bdydef_.type = b2_dynamicBody;
    bdydef_.position = b2Vec2(x, y);

    bdy = mundo->CreateBody(&bdydef_);

}


void Caja::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fix_ = bdy->CreateFixture(&fixdef_);


    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(caja);

}



