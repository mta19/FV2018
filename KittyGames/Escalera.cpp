/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escalera.cpp
 * Author: pedro
 * 
 * Created on 18 de abril de 2018, 18:45
 */

#include "Escalera.h"

Escalera::Escalera(String nombre) {

    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);

    IntRect posicion(0, 0, spr->getTexture()->getSize().x / 7, spr->getTexture()->getSize().y / 5);
    spr->setTextureRect(posicion);

}

Escalera::Escalera(const Escalera& orig) {
}

Escalera::~Escalera() {
}

void Escalera::setBody(b2World * mundo, float x, float y) {

    bdydef_.type = b2_staticBody;
    bdydef_.position = b2Vec2(x, y);

    bdy = mundo->CreateBody(&bdydef_);

}

void Escalera::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {

    float weight = spr->getTextureRect().width;
    float height = spr->getTextureRect().height;


    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fixdef_.filter.categoryBits = entityCategory::STAIRS;
    fixdef_.filter.maskBits = entityCategory::FRIENDLY_PLAYER;
    fixdef_.isSensor = true;


    fix_ = bdy->CreateFixture(&fixdef_);


    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(escalera);
    
    
    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);

}