/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 19:12
 */

#include "Personaje.h"
#include "EstadoPersonaje.h"
#include <iostream>
#include "EstadoStanding.h"
#include "Nivel.h"

Personaje::Personaje() {
    vida = 100;
    vidaActual = vida;
    puntuacion = 0;
    arma = NULL;
    row = 0;
    estado_ = new EstadoStanding();
    flagAux = true;
    tiempoAux = 0;
    
    //Cargamos la fuente
    if (fuente.loadFromFile("fonts/PrStart.ttf") == false) {
        std::cerr << "Error cargando la la fuente fonts/PrStart.ttf";
        exit(0);
    }
    
    nombre.setFont(fuente);
    nombre.setString("ALIEN COLOR");
    
    tiempo=clock.getElapsedTime();

}

Personaje::Personaje(const Personaje& orig) {
}

Personaje::~Personaje() {
}

void Personaje::handleInput(Event* tecla, Nivel* nivel) {

  
}


int Personaje::getVida() {
    return vida;
}

int Personaje::getVidaActual() {
    return vidaActual;
}

void Personaje::updateVidaActual(int cambio) {
    //Si recibe un entero negativo, se le resta por signo
    vidaActual += cambio;
    if (vidaActual <= 0) {
        morir();
    }
}

void Personaje::morir() {
    //(?)
    //Eliminar Textura, Sprite y Personaje (Alien) -- (???)
}

int Personaje::getPuntuacion() {

    return puntuacion;

}

void Personaje::updatePuntuacion(int cambio) {
    if (puntuacion >= cambio) {
        puntuacion += cambio;
    }
}

void Personaje::setBody(b2World * mundo, float x, float y) {

    bdydef_.type = b2_dynamicBody;
    bdydef_.position = b2Vec2(x, y);
    bdydef_.fixedRotation = true;


    bdy = mundo->CreateBody(&bdydef_);

}

Sprite* Personaje::getSprite() {

    return spr;

}

Texture* Personaje::getTextura() {

    return txt;

}

void Personaje::setFixture(b2PolygonShape * forma, float density, float restitution, float friction) {


    float weight = (this->getSprite()->getTexture()->getSize().x / 3);
    float height = (this->getSprite()->getTexture()->getSize().y / 7);

    fixdef_.shape = forma;
    fixdef_.density = density;
    fixdef_.restitution = restitution;
    fixdef_.friction = friction;


    fixdef_.filter.categoryBits = entityCategory::FRIENDLY_PLAYER;
    fixdef_.filter.maskBits = entityCategory::BOUNDARY | entityCategory::STAIRS | entityCategory::WEAPON;

    fix_ = bdy->CreateFixture(&fixdef_);



    forma->SetAsBox(4.3, 4.3, b2Vec2(0, 8.f), 0);



    fixdef_.isSensor = false;
    fixdef_.friction = 1.f;
    bdy->CreateFixture(&fixdef_);


    bdy->SetGravityScale(1.5f);

    cuerpo = new Ensamblador(bdy, this->getSprite(), weight, height);


    bdy->SetUserData((void*) this);
    bdy->GetFixtureList()->SetUserData((void*) this);

    cuerpo->set_id_id(identificador::jugador);

    intptr_t aux = 3;
    cuerpo->getBody()->GetFixtureList()->SetUserData((void*) aux);


}

void Personaje::setFrame(Sprite& spr) {

    IntRect posicion(0, 0, spr.getTexture()->getSize().x / 3, spr.getTexture()->getSize().y / 7);
    spr.setTextureRect(posicion);


}

void Personaje::setArma(Entidad* weapon) {

    arma = weapon;
    arma->getCuerpo()->getBody()->SetActive(false);




}

void Personaje::tirarArma() {

    delete arma;
    arma = NULL;

}

void Personaje::disparar() {



}

void Personaje::dispararEscopeta() {



}

void Personaje::borrarBala() {


    for (int i = 0; i < balas.size(); i++) {

        if (balas[i]->getDestroy() || balas[i]->getReloj()->getElapsedTime()>balas[i]->getlifetime()) {

            delete balas[i];

            balas[i] = NULL;

            balas.erase(balas.begin() + i);

        }

    }

}

void Personaje::updateArma() {

    IntRect uvRect;
    uvRect.width = this->getArma()->getTexture()->getSize().x;
    uvRect.height = this->getArma()->getTexture()->getSize().y;
    if (this->getface() == true) {

        uvRect.left = 0;
        uvRect.width = abs(uvRect.width);
    } else {
        uvRect.left = abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);

    }
    this->getArma()->getSprite()->setTextureRect(uvRect);

}

 void Personaje::setNombre(String nombre){
     this->nombre.setString(nombre);
}

String Personaje::getNombre(){
    return this->nombre.getString();
 }