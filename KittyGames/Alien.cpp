/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alien.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 1:36
 */

#include "Alien.h"
#include "Animacion.h"
#include "EstadoPersonaje.h"

Alien::Alien() {
}

Alien::Alien(const Alien& orig) {
}

Alien::~Alien() {
}

void Alien::setSprite() {


    txt = new Texture();

    txt->loadFromFile("Verde.png");
    spr = new Sprite(*txt);



    setFrame(*spr);
    spr->setPosition(300.0f, 200.0f);
    spr->setScale(28.f / spr->getTexture()->getSize().x, 80.f / spr->getTexture()->getSize().y);

    animacion = new Animacion(txt, Vector2u(3, 7), 0.3f);
}

void Alien::handleInput(Event* tecla, Nivel* nivel) {

    EstadoPersonaje* estado = estado_->handleInput(*this, tecla, nivel);


    if (estado != NULL) {



        delete estado_;

        estado_ = estado;




        if (this->getArma() != NULL  && Keyboard::isKeyPressed(Keyboard::Q)  && flagAux == true) {

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::pistola) {
                disparar();
                flagAux = false;

            }

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::M4) {
                disparar();
                flagAux = false;

            }

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::escopeta) {
                dispararEscopeta();
                flagAux = false;

            }

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {
                disparar();
                flagAux = false;

            }
        }
    }

}

void Alien::handleInput(Event* tecla, Nivel* nivel, int mando) {

    EstadoPersonaje* estado = estado_->handleInputJoystick(*this, tecla, nivel, mando);

    if (estado != NULL) {

        delete estado_;

        estado_ = estado;

        if (this->getArma() != NULL && Joystick::isButtonPressed(mando, 2) && flagAux == true) {

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::pistola) {
                disparar();
                flagAux = false;
            }
            if (this->getArma()->getCuerpo()->get_id_id() == identificador::escopeta) {
                this->dispararEscopeta();
                flagAux = false;
            }
            if (this->getArma()->getCuerpo()->get_id_id() == identificador::M4) {
                disparar();
                flagAux = false;
            }
            if (this->getArma()->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {
                disparar();
                flagAux = false;
            }
        }
    }
}

void Alien::disparar() {


    Bala *bala = new BalaPistola("balasPistola.png",0);
    if (this->getface() == true)
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x + 20, this->getSprite()->getPosition().y + 5);
    else
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x - 25, this->getSprite()->getPosition().y + 5);


    b2PolygonShape shp_;
    shp_.SetAsBox(3.f, 6.f);
    bala->setFixture(&shp_, 1.f, 0.f, 0.f);
    if (this->getface() == true)
        bala->getCuerpo()->getBody()->SetLinearVelocity({90, 0});
    else {
        bala->getCuerpo()->getBody()->SetLinearVelocity({-90, 0});
    }

    balas.push_back(bala);

}

void Alien::dispararEscopeta() {


    Bala *bala = new BalaEscopeta("balasM4.png",1);
    if (this->getface() == true)
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x + 20, this->getSprite()->getPosition().y + 5);
    else
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x - 25, this->getSprite()->getPosition().y + 5);


    b2PolygonShape shp_;
    shp_.SetAsBox(3.f, 6.f);
    bala->setFixture(&shp_, 1.f, 0.f, 0.f);
    if (this->getface() == true)
        bala->getCuerpo()->getBody()->SetLinearVelocity({120, 0});
    else {
        bala->getCuerpo()->getBody()->SetLinearVelocity({-120, 0});
    }

    balas.push_back(bala);

}