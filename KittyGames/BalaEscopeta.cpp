/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalaEscopeta.cpp
 * Author: pedro
 * 
 * Created on 25 de abril de 2018, 22:22
 */

#include "BalaEscopeta.h"

BalaEscopeta::BalaEscopeta(String nombre, int i) {

    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);

    // IntRect posicion(0, 0, spr->getTexture()->getSize().x, spr->getTexture()->getSize().y/4);
    //spr->setTextureRect(posicion);
    spr->setScale(2.f / spr->getTexture()->getSize().x, 2.f / spr->getTexture()->getSize().y);
    lifeTime = sf::seconds(0.2f);
    destroy = false;

    damage = 20;
}

BalaEscopeta::BalaEscopeta(const BalaEscopeta& orig) {

}

BalaEscopeta::~BalaEscopeta() {
    bdy->GetWorld()->DestroyBody(bdy);
}

void BalaEscopeta::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fixdef_.filter.categoryBits = entityCategory::BULLET_N;
    fixdef_.filter.maskBits = entityCategory::FRIENDLY_PLAYER | entityCategory::BOUNDARY;

    fix_ = bdy->CreateFixture(&fixdef_);

    bdy->SetGravityScale(0);

    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(balaPistola);





    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);
}



