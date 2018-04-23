/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plataforma.cpp
 * Author: pedro
 * 
 * Created on 18 de abril de 2018, 17:34
 */

#include "Plataforma.h"

Plataforma::Plataforma(String nombre) {
    
    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);
    
}

Plataforma::Plataforma(const Plataforma& orig) {
}

Plataforma::~Plataforma() {
}

void Plataforma::setBody(b2World * mundo, float x, float y){
    
    bdydef_.type = b2_staticBody;
    bdydef_.position = b2Vec2(x, y);

    bdy = mundo->CreateBody(&bdydef_);

}


void Plataforma::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fix_ = bdy->CreateFixture(&fixdef_);


    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(plataforma);
    
    
    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);

}

