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

    empezado=false;
    
    mundo->SetContactListener(procesadorColisiones);



    bdy = new b2Body*[10];




    this->anyadirArma(250.f, 240.f, 8.f, 6.f);

    this->anyadirLanzaCohetes(100.f, 245.f, 12.f, 8.f);

    this->anyadirM4(200.f, 245.f, 12.f, 8);

    this->anyadirEscopeta(150.f, 245.f, 12.f, 8.f);

    
    //this->anyadirEscalera(400.f, 220.f, 12.f, 105.f);

    
    //this->anyadirEscalera(273.f, 240.f, 12.f, 85.f);

    
    mapa = new Map("resources/mostrar.tmx");


    



    char k='p';
    for (int z = 0; z < mapa->_numPlats; z++) {
        
        
        float x = mapa->getX(k,z);
        float y = mapa->getY(k,z);
        float w = mapa->getWidth(k,z);
        float h = mapa->getHeight(k,z);
        this->anyadirPlataforma(x + w / 2, y + h / 2, w / 2, h / 2);

    }
    k='s';
    for (int o = 0; o < mapa->_numStairs; o++) {
        
        float x = mapa->getX(k,o);
        float y = mapa->getY(k,o);
        float w = mapa->getWidth(k,o);
        float h = mapa->getHeight(k,o);
        this->anyadirEscalera(x + w / 2, y + h / 2, w / 2, h / 2);

    }
    k='b';
    for (int i = 0; i < mapa->_numBoxes; i++) {
        
        float x = mapa->getX(k,i);
        float y = mapa->getY(k,i);
        float w = mapa->getWidth(k,i);
        float h = mapa->getHeight(k,i);
        this->anyadirObjetoDinamico(x + w / 2, y + h / 2, w / 2, h / 2);

    }

    
    this->anyadirObjetoDinamico(325.0f, 100.0f, 9.5f, 16.f);
    this->anyadirObjetoDinamico(120.0f, 100.0f, 9.5f, 16.f);
     
    //this->anyadirPlataforma(340.f, 300.0f, 80.f, 8.f);

    //this->anyadirPlataforma(347.f, 140.0f, 40.f, 8.f);

    //this->anyadirPlataforma(220.f, 177.0f, 40.f, 8.f);

    // this->anyadirPlataforma(500.f, 250.0f, 40.f, 8.f);


}

Nivel::Nivel(const Nivel& orig) {
}

Nivel::~Nivel() {
}

void Nivel::anyadirObjetoDinamico(float x, float y, float weight, float height) {


    Entidad* entidad = new Caja("caja.jpg");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 1.f, 0.f, 0.3f);

    entidades.push_back(entidad);


}

void Nivel::anyadirEscalera(float x, float y, float weight, float height) {



    Entidad* entidad = new Escalera("stairs.png");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 1.f, 0.f, 0.3f);

    entidades.push_back(entidad);

}

void Nivel::anyadirArma(float x, float y, float weight, float height) {

    Entidad* entidad = new Pistola("pistola.png");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 0.5f, 0.f, 0.3f);

    entidades.push_back(entidad);

}

void Nivel::anyadirEscopeta(float x, float y, float weight, float height) {



    Entidad* entidad = new Escopeta("escopeta.png");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 0.5f, 0.f, 0.3f);

    entidades.push_back(entidad);

}

void Nivel::anyadirLanzaCohetes(float x, float y, float weight, float height) {



    Entidad* entidad = new LanzaCohetes("lanzaCohetes.png");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 0.5f, 0.f, 0.3f);

    entidades.push_back(entidad);

}

void Nivel::anyadirM4(float x, float y, float weight, float height) {



    Entidad* entidad = new M4("M4.png");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 0.5f, 0.f, 0.3f);

    entidades.push_back(entidad);

}

void Nivel::anyadirPlataforma(float x, float y, float weight, float height) {




    
    Entidad* entidad = new Plataforma("");
    entidad->setBody(mundo, x, y);

    shp_[contadorEn].SetAsBox(weight, height); // esto estaba en el de antes

    entidad->setFixture(&shp_[contadorEn], 0.f, 0.01f, 1.f);

    entidades.push_back(entidad);


}

void Nivel::anyadirPersonaje(Personaje * personaje) {


    Entidad* entidad = personaje;
    entidad->setBody(mundo, personaje->getSprite()->getPosition().x, personaje->getSprite()->getPosition().y);

    float weight = (personaje->getSprite()->getTextureRect().width * personaje->getSprite()->getScale().x);
    float height = (personaje->getSprite()->getTextureRect().height * personaje->getSprite()->getScale().y);

    b2PolygonShape shp_personaje;
    shp_personaje.SetAsBox(weight, height);

    entidad->setFixture(&shp_personaje, 0.5f, 0.0f, 0.f);

    entidades.push_back(entidad);

}

void Nivel::actualizar_fisica() {

    mundo->Step(0.06f, 8, 8);

    mundo->ClearForces();

}
