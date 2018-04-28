/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalaM4.cpp
 * Author: pedro
 * 
 * Created on 26 de abril de 2018, 18:24
 */

#include "BalaM4.h"

BalaM4::BalaM4(String nombre, int i) {

    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);

    IntRect posicion(0, i * spr->getTexture()->getSize().y / 4, spr->getTexture()->getSize().x, spr->getTexture()->getSize().y / 4);
    spr->setTextureRect(posicion);
    lifeTime=sf::seconds(1.f);
    destroy = false;
}

BalaM4::BalaM4(const BalaM4& orig) {
}

BalaM4::~BalaM4() {

    bdy->GetWorld()->DestroyBody(bdy);
}

void BalaM4::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fix_ = bdy->CreateFixture(&fixdef_);

    bdy->SetGravityScale(0);

    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(identificador::balaM4);



    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);
}

