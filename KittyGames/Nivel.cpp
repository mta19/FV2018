/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 19:54
 */
#include <iostream>
#include "Partida.h"
#include "Nivel.h"
#include "Entidad.h"
#include <cstdint>

#include "Box2D/Box2D.h"


#define SCALE 30.0f


int Nivel::contadorEn = 0;

Nivel::Nivel() {

    spr_ = new Sprite*[10];

    //creamos el mundo

    b2Vec2 gravity(0, 15.0f); //normal earth gravity, 9.8 m/s/s straight down!

    mundo = new b2World(gravity);

    procesadorColisiones = new Collision();

    mundo->SetContactListener(procesadorColisiones);

    ensambladores = new Ensamblador*[10];
    bdy = new b2Body*[10];
    /*  float32 timeStep = 1 / 20.0; //the length of time passed to simulate (seconds)
      int32 velocityIterations = 8; //how strongly to correct velocity
      int32 positionIterations = 3; //how strongly to correct position

      mundo->Step(timeStep, velocityIterations, positionIterations);*/

}

Nivel::Nivel(const Nivel& orig) {
}

Nivel::~Nivel() {
}

void Nivel::anyadirObjetoDinamico(float x, float y, float weight, float height) {

    txt_ = new Texture;
    txt_->loadFromFile("caja.jpg");

    spr_[Nivel::contadorEn] = new Sprite(*txt_);


    bdydef_[Nivel::contadorEn].type = b2_dynamicBody;
    bdydef_[Nivel::contadorEn].position = b2Vec2(x, y);

    bdy[Nivel::contadorEn] = mundo->CreateBody(&bdydef_[Nivel::contadorEn]);


    shp_[contadorEn].SetAsBox(weight, height);

    weight = spr_[Nivel::contadorEn]->getTexture()->getSize().x;
    height = spr_[Nivel::contadorEn]->getTexture()->getSize().y;

    fixdef_[Nivel::contadorEn].shape = &shp_[contadorEn];
    fixdef_[Nivel::contadorEn].density = 1.f;
    fixdef_[Nivel::contadorEn].restitution = 0.f;
    fixdef_[Nivel::contadorEn].friction = 0.3f;


    fix_[Nivel::contadorEn] = bdy[Nivel::contadorEn]->CreateFixture(&fixdef_[Nivel::contadorEn]);


    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy[Nivel::contadorEn], spr_[Nivel::contadorEn], weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(caja);


}

void Nivel::anyadirEscalera(float x, float y, float weight, float height) {

    txt_ = new Texture;
    txt_->loadFromFile("stairs.png");

    spr_[Nivel::contadorEn] = new Sprite(*txt_);

    IntRect posicion(0, 0, spr_[Nivel::contadorEn]->getTexture()->getSize().x / 7, spr_[Nivel::contadorEn]->getTexture()->getSize().y / 5);
    spr_[Nivel::contadorEn]->setTextureRect(posicion);

    bdydef_[Nivel::contadorEn].type = b2_staticBody;
    bdydef_[Nivel::contadorEn].position = b2Vec2(x, y);

    bdy[Nivel::contadorEn] = mundo->CreateBody(&bdydef_[Nivel::contadorEn]);

    b2PolygonShape shp_caja;

    
    shp_[contadorEn].SetAsBox(weight, height);

    weight = spr_[Nivel::contadorEn]->getTextureRect().width;
    height = spr_[Nivel::contadorEn]->getTextureRect().height;

    fixdef_[Nivel::contadorEn].shape = &shp_[contadorEn];
    fixdef_[Nivel::contadorEn].density = 1.f;
    fixdef_[Nivel::contadorEn].restitution = 0.f;
    fixdef_[Nivel::contadorEn].friction = 0.3f;

    fixdef_[Nivel::contadorEn].filter.categoryBits = entityCategory::STAIRS;
    fixdef_[Nivel::contadorEn].filter.maskBits = entityCategory::FRIENDLY_PLAYER;
    fixdef_[Nivel::contadorEn].isSensor = true;

    fix_[Nivel::contadorEn] = bdy[Nivel::contadorEn]->CreateFixture(&fixdef_[Nivel::contadorEn]);


    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy[Nivel::contadorEn], spr_[Nivel::contadorEn], weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(caja);


}

void Nivel::anyadirPlataforma(float x, float y, float weight, float height) {

    txt_ = new Texture;
    txt_->loadFromFile("suelo.jpg");

    spr_[Nivel::contadorEn] = new Sprite(*txt_);

    bdydef_[Nivel::contadorEn].type = b2_staticBody;
    bdydef_[Nivel::contadorEn].position = b2Vec2(x, y);

    bdy[Nivel::contadorEn] = mundo->CreateBody(&bdydef_[Nivel::contadorEn]);


    shp_[contadorEn].SetAsBox(weight, height);



    weight = spr_[Nivel::contadorEn]->getTexture()->getSize().x;
    height = spr_[Nivel::contadorEn]->getTexture()->getSize().y;

    fixdef_[Nivel::contadorEn].shape = &shp_[contadorEn];
    fixdef_[Nivel::contadorEn].density = 0.f;
    fixdef_[Nivel::contadorEn].restitution = 0.01f;
    fixdef_[Nivel::contadorEn].friction = 1.f;

    fix_[Nivel::contadorEn] = bdy[Nivel::contadorEn]->CreateFixture(&fixdef_[Nivel::contadorEn]);

    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy[Nivel::contadorEn], spr_[Nivel::contadorEn], weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(plataforma);


}

void Nivel::anyadirPersonaje(float x, float y, Sprite *sprite) {



    bdydef_[Nivel::contadorEn].type = b2_dynamicBody;
    bdydef_[Nivel::contadorEn].position = b2Vec2(x, y);
     bdydef_[Nivel::contadorEn].fixedRotation=true;
    
    bdy[Nivel::contadorEn] = mundo->CreateBody(&bdydef_[Nivel::contadorEn]);



    float weight = (sprite->getTextureRect().width * sprite->getScale().x);
    float height = (sprite->getTextureRect().height * sprite->getScale().y);

    b2PolygonShape shp_personaje;
    shp_personaje.SetAsBox(weight, height);


    weight = sprite->getTexture()->getSize().x / 3;
    height = sprite->getTexture()->getSize().y / 7;




    fixdef_[Nivel::contadorEn].shape = &shp_personaje;
    fixdef_[Nivel::contadorEn].density = 0.05f;

    fixdef_[Nivel::contadorEn].restitution = 0.0f;
    fixdef_[Nivel::contadorEn].friction = 0.f;
    fixdef_[Nivel::contadorEn].filter.categoryBits = entityCategory::FRIENDLY_PLAYER;
    fixdef_[Nivel::contadorEn].filter.maskBits = entityCategory::BOUNDARY | entityCategory::STAIRS;

    fix_[Nivel::contadorEn] = bdy[Nivel::contadorEn]->CreateFixture(&fixdef_[Nivel::contadorEn]);

    b2PolygonShape polygonShape;

    
    shp_personaje.SetAsBox(4.3, 4.3, b2Vec2(0,8.f), 0);
    
    fixdef_[Nivel::contadorEn].isSensor=false;
    fixdef_[Nivel::contadorEn].friction=1.f;
    bdy[Nivel::contadorEn]->CreateFixture(&fixdef_[Nivel::contadorEn]);
    

    bdy[Nivel::contadorEn]->SetGravityScale(1.5f);

    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy[Nivel::contadorEn], sprite, weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(identificador::jugador);
    
    intptr_t aux=3;
    ensambladores[Nivel::contadorEn]->getBody()->GetFixtureList()->SetUserData((void*)aux);
    

}

void Nivel::actualizar_fisica() {

    mundo->Step(0.06f, 8, 8);

    mundo->ClearForces();

}
