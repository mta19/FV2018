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


int Nivel::contadorEn = 0;

Nivel::Nivel() {

    txt_suelo = new Texture;
    txt_suelo->loadFromFile("suelo.jpg");

    txt_caja = new Texture;
    txt_caja->loadFromFile("caja.jpg");

    spr_suelo = new Sprite*[3];
    for (int i = 0; i < 3; i++) {
        spr_suelo[i] = new Sprite(*txt_suelo);

    }

    spr_caja = new Sprite(*txt_caja);


    b2Vec2 gravity(0, 9.8); //normal earth gravity, 9.8 m/s/s straight down!
    bool doSleep = true;

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


    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy_caja, spr_caja, weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(caja);

    Nivel::contadorEn++;

}

void Nivel::anyadirPlataforma(float x, float y, float weight, float height) {

    bdydef_suelo[Nivel::contadorEn].type = b2_staticBody;
    bdydef_suelo[Nivel::contadorEn].position = b2Vec2(x, y);

    bdy[Nivel::contadorEn] = mundo->CreateBody(&bdydef_suelo[Nivel::contadorEn]);


    shp_suelo[contadorEn].SetAsBox(weight, height);



    weight = spr_suelo[Nivel::contadorEn]->getTexture()->getSize().x;
    height = spr_suelo[Nivel::contadorEn]->getTexture()->getSize().y;

    fixdef_suelo[Nivel::contadorEn].shape = &shp_suelo[contadorEn];
    fixdef_suelo[Nivel::contadorEn].density = 0.f;
    fixdef_suelo[Nivel::contadorEn].restitution = 0.01f;
    fixdef_suelo[Nivel::contadorEn].friction = 1.f;

    fix_suelo[Nivel::contadorEn] = bdy[Nivel::contadorEn]->CreateFixture(&fixdef_suelo[Nivel::contadorEn]);

    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy[Nivel::contadorEn], spr_suelo[Nivel::contadorEn], weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(plataforma);


}

void Nivel::anyadirPersonaje(float x, float y, Sprite *sprite) {



    bdydef_suelo[Nivel::contadorEn].type = b2_dynamicBody;
    bdydef_suelo[Nivel::contadorEn].position = b2Vec2(x, y);

    bdy[Nivel::contadorEn] = mundo->CreateBody(&bdydef_suelo[Nivel::contadorEn]);



    float weight = (sprite->getTextureRect().width * sprite->getScale().x);
    float height = (sprite->getTextureRect().height * sprite->getScale().y);

    b2PolygonShape shp_personaje;
    shp_personaje.SetAsBox(weight, height);


    weight = sprite->getTexture()->getSize().x / 3;
    height = sprite->getTexture()->getSize().y / 7;



    fixdef_suelo[Nivel::contadorEn].shape = &shp_personaje;
    fixdef_suelo[Nivel::contadorEn].density = 0.05f;

    fixdef_suelo[Nivel::contadorEn].restitution = 0.0f;
    fixdef_suelo[Nivel::contadorEn].friction = 0.3f;


    fix_suelo[Nivel::contadorEn] = bdy[Nivel::contadorEn]->CreateFixture(&fixdef_suelo[Nivel::contadorEn]);

    bdy[Nivel::contadorEn]->SetGravityScale(1.5f);

    ensambladores[Nivel::contadorEn] = new Ensamblador(bdy[Nivel::contadorEn], sprite, weight, height);
    ensambladores[Nivel::contadorEn]->set_id_id(identificador::jugador);

}

void Nivel::actualizar_fisica() {

    mundo->Step(0.06f, 8, 8);

    mundo->ClearForces();

}
