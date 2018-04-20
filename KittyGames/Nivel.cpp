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
#include "Escalera.h"
#include "Caja.h"
#include "Pistola.h"
#include "Plataforma.h"
#include <cstdint>

#include "Box2D/Box2D.h"


#define SCALE 30.0f


int Nivel::contadorEn = 0;

Nivel::Nivel() {

    spr_ = new Sprite*[10];

    b2Vec2 gravity(0, 15.0f); //normal earth gravity, 9.8 m/s/s straight down!

    mundo = new b2World(gravity);

    procesadorColisiones = new Collision();

    mundo->SetContactListener(procesadorColisiones);

    entidades = new Entidad*[10];

    bdy = new b2Body*[10];

}

Nivel::Nivel(const Nivel& orig) {
}

Nivel::~Nivel() {
}

void Nivel::anyadirObjetoDinamico(float x, float y, float weight, float height) {
   

    entidades[Nivel::contadorEn] = new Caja("caja.jpg");
    entidades[Nivel::contadorEn]->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidades[Nivel::contadorEn]->setFixture(&shp_[contadorEn], 1.f, 0.f, 0.3f);
   

}

void Nivel::anyadirEscalera(float x, float y, float weight, float height) {



    entidades[Nivel::contadorEn] = new Escalera("stairs.png");
    entidades[Nivel::contadorEn]->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidades[Nivel::contadorEn]->setFixture(&shp_[contadorEn], 1.f, 0.f, 0.3f);


}

void Nivel::anyadirArma(float x, float y, float weight, float height) {



    entidades[Nivel::contadorEn] = new Pistola("Partlist2.png");
    entidades[Nivel::contadorEn]->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidades[Nivel::contadorEn]->setFixture(&shp_[contadorEn], 0.5f, 0.f, 0.3f);


}

void Nivel::anyadirPlataforma(float x, float y, float weight, float height) {




    entidades[Nivel::contadorEn] = new Plataforma("suelo.jpg");
    entidades[Nivel::contadorEn]->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidades[Nivel::contadorEn]->setFixture(&shp_[contadorEn], 0.f, 0.01f, 1.f);


}

void Nivel::anyadirPersonaje(Personaje * personaje) {


    entidades[Nivel::contadorEn] = personaje;
    entidades[Nivel::contadorEn]->setBody(mundo, personaje->getSprite()->getPosition().x, personaje->getSprite()->getPosition().y);

    float weight = (personaje->getSprite()->getTextureRect().width * personaje->getSprite()->getScale().x);
    float height = (personaje->getSprite()->getTextureRect().height * personaje->getSprite()->getScale().y);

    b2PolygonShape shp_personaje;
    shp_personaje.SetAsBox(weight, height);

    entidades[Nivel::contadorEn]->setFixture(&shp_personaje, 0.5f, 0.0f, 0.f);

}

void Nivel::actualizar_fisica() {

    mundo->Step(0.06f, 8, 8);

    mundo->ClearForces();

}
