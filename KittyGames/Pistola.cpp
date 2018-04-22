/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pistola.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 15:48
 */

#include "Pistola.h"
#include "SFML/Graphics.hpp"
Pistola::Pistola(String nombre) {
    
     txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);
    
    IntRect posicion(0, 0, spr->getTexture()->getSize().x / 4, spr->getTexture()->getSize().y / 6.8);
    spr->setTextureRect(posicion);

    cadencia=100;
}

Pistola::Pistola(const Pistola& orig) {
}

Pistola::~Pistola() {
}



void Pistola::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;

    
    fixdef_.filter.categoryBits = entityCategory::WEAPON;
    fixdef_.filter.maskBits = entityCategory::FRIENDLY_PLAYER | entityCategory::BOUNDARY;
    fixdef_.isSensor = true;
    
    bdy->SetGravityScale(200.f);
    
    fix_ = bdy->CreateFixture(&fixdef_);


    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(pistola);

}






