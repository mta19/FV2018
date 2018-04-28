/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   balaLC.cpp
 * Author: pedro
 * 
 * Created on 26 de abril de 2018, 18:25
 */

#include "balaLC.h"

balaLC::balaLC(String nombre, int i) {

    txt = new Texture;
    txt->loadFromFile(nombre);
    spr = new Sprite(*txt);

    IntRect posicion(i * spr->getTexture()->getSize().x / 4, 0, spr->getTexture()->getSize().x/4, spr->getTexture()->getSize().y );
    spr->setTextureRect(posicion);
    lifeTime=sf::seconds(5.f);
    destroy = false;

}

balaLC::balaLC(const balaLC& orig) {
}

balaLC::~balaLC() {
    
    bdy->GetWorld()->DestroyBody(bdy);
}

void balaLC::setFixture(b2PolygonShape* forma, float density, float restitution, float friction) {


    float weight = spr->getTexture()->getSize().x;
    float height = spr->getTexture()->getSize().y;

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fix_ = bdy->CreateFixture(&fixdef_);

    bdy->SetGravityScale(1.3f);

    cuerpo = new Ensamblador(bdy, spr, weight, height);
    cuerpo->set_id_id(identificador::balaCohete);



    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);
}
