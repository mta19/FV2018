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
    
    

}

Personaje::Personaje(const Personaje& orig) {
}

Personaje::~Personaje() {
}

void Personaje::handleInput(Event* tecla, Nivel* nivel) {
    std::cout << "estoy apuntito de saltar" << std::endl;

    EstadoPersonaje* estado = estado_->handleInput(*this, tecla, nivel);


    if (estado != NULL) {



        delete estado_;

        estado_ = estado;


        if (this->getArma() != NULL && tecla->key.code == Keyboard::Q) {

            std::cout << "estoy disparando" << std::endl;
            disparar();
        }

    }

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

void Personaje::disparar() {

    std::cout<<"estoy disparando"<<std::endl;
    
    Bala *bala = new BalaPistola("balas.png");
    if(this->getface()==true)
    bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x, this->getSprite()->getPosition().y);
    else
            bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x-10, this->getSprite()->getPosition().y);


    b2PolygonShape shp_;
    shp_.SetAsBox(3.f, 3.f);
    bala->setFixture(&shp_, 1.f, 0.f, 0.f);
    if(this->getface()==true)
    bala->getCuerpo()->getBody()->SetLinearVelocity({30,0});
    else{
        bala->getCuerpo()->getBody()->SetLinearVelocity({-30,0});
    }
    
    balas.push_back(bala);

}