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


#include "Box2D/Box2D.h"


#define SCALE 30.0f

Nivel::Nivel() {

    txt_suelo = new Texture;
    txt_suelo->loadFromFile("suelo.jpg");

    txt_caja = new Texture;
    txt_caja->loadFromFile("caja.jpg");

    spr_suelo = new Sprite(*txt_suelo);
    spr_caja = new Sprite(*txt_caja);

    
    b2Vec2 gravity(0, 25.8); //normal earth gravity, 9.8 m/s/s straight down!
    bool doSleep = true;

    mundo = new b2World(gravity);
    
    procesadorColisiones=new Collision();
    
    mundo->SetContactListener(procesadorColisiones);

  /*  float32 timeStep = 1 / 20.0; //the length of time passed to simulate (seconds)
    int32 velocityIterations = 8; //how strongly to correct velocity
    int32 positionIterations = 3; //how strongly to correct position

    mundo->Step(timeStep, velocityIterations, positionIterations);*/

}

Nivel::Nivel(const Nivel& orig) {
}

Nivel::~Nivel() {
}

void Nivel::anyadirPlataforma(float x, float y, float weight, float height) {

    bdydef_suelo.type = b2_staticBody;
    bdydef_suelo.position = b2Vec2(x, y);

    bdy_suelo = mundo->CreateBody(&bdydef_suelo);

    b2PolygonShape shp_suelo;
    shp_suelo.SetAsBox(weight, height);

    weight = spr_suelo->getTexture()->getSize().x;
    height = spr_suelo->getTexture()->getSize().y;

    fixdef_suelo.shape = &shp_suelo;
    fixdef_suelo.density = 1.f;
    fixdef_suelo.restitution = 0.01f;
    fixdef_suelo.friction = 0.7f;


    fix_suelo = bdy_suelo->CreateFixture(&fixdef_suelo);

    ensambladorSuelo = new Ensamblador(bdy_suelo, spr_suelo, &weight, &height);
    ensambladorSuelo->set_id_id(plataforma);

}

void Nivel::anyadirObjetoDinamico(float x, float y, float weight, float height) {



    bdydef_caja.type = b2_dynamicBody;
    bdydef_caja.position = b2Vec2(x, y);

    bdy_caja = mundo->CreateBody(&bdydef_caja);

    b2PolygonShape shp_caja;


    shp_caja.SetAsBox(weight, height);

    weight = spr_caja->getTexture()->getSize().x;
    height = spr_caja->getTexture()->getSize().y;

    fixdef_caja.shape = &shp_caja;
    fixdef_caja.density = 1.f;
    fixdef_caja.restitution = 0.5f;
    fixdef_caja.friction = 0.3f;

    fix_caja = bdy_caja->CreateFixture(&fixdef_caja);


    ensambladorCaja = new Ensamblador(bdy_caja, spr_caja, &weight, &height);
    ensambladorCaja->set_id_id(caja);

    
}

void Nivel::anyadirPersonaje(float x, float y, Sprite *sprite) {



    bdydef_personaje.type = b2_dynamicBody;
    bdydef_personaje.position = b2Vec2(x, y);

    bdy_personaje = mundo->CreateBody(&bdydef_personaje);



    float weight = (sprite->getTextureRect().width * sprite->getScale().x);
    float height = (sprite->getTextureRect().height * sprite->getScale().y);

    b2PolygonShape shp_personaje;
    shp_personaje.SetAsBox(weight, height);


    weight = sprite->getTexture()->getSize().x / 3;
    height = sprite->getTexture()->getSize().y / 7;



    fixdef_personaje.shape = &shp_personaje;
    fixdef_personaje.density = 1.f;

    fixdef_personaje.restitution = 0.0f;
    fixdef_personaje.friction = 0.1f;


    fix_personaje = bdy_personaje->CreateFixture(&fixdef_personaje);



    ensambladorPersonaje = new Ensamblador(bdy_personaje, sprite, &weight, &height);
    ensambladorPersonaje->set_id_id(identificador::jugador);
}

void Nivel::actualizar_fisica() {

    mundo->Step(0.06f, 8, 8);

    mundo->ClearForces();

}
