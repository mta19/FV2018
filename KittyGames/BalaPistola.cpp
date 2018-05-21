/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalaPistola.cpp
 * Author: pedro
 * 
 * Created on 19 de abril de 2018, 13:07
 */

#include <iostream>

#include "BalaPistola.h"

BalaPistola::BalaPistola(String nombre, int i) {
    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);

    IntRect posicion(0, i*spr->getTexture()->getSize().y/4, spr->getTexture()->getSize().x, spr->getTexture()->getSize().y / 4);
    spr->setTextureRect(posicion);

    lifeTime=sf::seconds(2.f);
    destroy = false;
    
    damage=9;
}

BalaPistola::BalaPistola(const BalaPistola& orig) {


}

BalaPistola::~BalaPistola() {

    bdy->GetWorld()->DestroyBody(bdy);

}

void BalaPistola::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;

    fixdef_.filter.categoryBits=entityCategory::BULLET_S;
    fixdef_.filter.maskBits=entityCategory::FRIENDLY_PLAYER;

    fix_ = bdy->CreateFixture(&fixdef_);

    bdy->SetGravityScale(0);

    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(balaPistola);



    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);
}



