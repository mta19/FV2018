/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LanzaCohetes.cpp
 * Author: pedro
 * 
 * Created on 26 de abril de 2018, 18:25
 */

#include "LanzaCohetes.h"
#include "Ensamblador.h"

LanzaCohetes::LanzaCohetes(String nombre) {
    
    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);

    //IntRect posicion(0, 0, spr->getTexture()->getSize().x / 4, spr->getTexture()->getSize().y / 6.8);
    //spr->setTextureRect(posicion);

    cadencia = 100;
}

LanzaCohetes::LanzaCohetes(const LanzaCohetes& orig) {
}

LanzaCohetes::~LanzaCohetes() {
}

void LanzaCohetes::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fixdef_.isSensor = true;


    fixdef_.filter.categoryBits = entityCategory::WEAPON;
    fixdef_.filter.maskBits = entityCategory::FRIENDLY_PLAYER | entityCategory::BOUNDARY;
    
    fix_ = bdy->CreateFixture(&fixdef_);


    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(identificador::lanzaCohetes);


    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);

}