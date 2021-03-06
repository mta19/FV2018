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
#include "Personaje.h"
#include "EstadoPersonaje.h"

Alien::Alien() {
    Personaje::setNombre("ALIEN VERDE");
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




        if (this->getArma() != NULL && Keyboard::isKeyPressed(Keyboard::J) && flagAux == true && nivel->getEmpezado()) {

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::pistola && clock.getElapsedTime() > sf::seconds(0.3f)) {
                disparar();
                flagAux = false;
                clock.restart();


            }

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::m4 && flagAux == true && clock.getElapsedTime() > sf::seconds(0.4f)) {
                dispararM4();
                flagAux = false;
                clock.restart();

            }

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::escopeta && clock.getElapsedTime() > sf::seconds(1.f)) {
                dispararEscopeta();
                flagAux = false;
                clock.restart();

            }

            if (this->getArma()->getCuerpo()->get_id_id() == identificador::lanzaCohetes && clock.getElapsedTime()>sf::seconds(1.2f)) {
                dispararLanzaCohetes();
                flagAux = false;
                clock.restart();
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
            if (this->getArma()->getCuerpo()->get_id_id() == identificador::m4) {
                dispararM4();
                flagAux = false;
            }
            if (this->getArma()->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {
                dispararLanzaCohetes();
                flagAux = false;
            }
        }
    }
}

void Alien::disparar() {


    Bala *bala = new BalaPistola("balasPistola.png", 0);
    if (this->getface() == true)
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x + 20, this->getSprite()->getPosition().y + 5);
    else
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x - 25, this->getSprite()->getPosition().y + 5);


    b2PolygonShape shp_;
    shp_.SetAsBox(3.f, 6.f);
    bala->setFixture(&shp_, 1.f, 0.f, 0.f);
    if (this->getface() == true)
        bala->getCuerpo()->getBody()->SetLinearVelocity({42, 0});
    else {
        bala->getCuerpo()->getBody()->SetLinearVelocity({-42, 0});
    }

    balas.push_back(bala);

}

void Alien::dispararEscopeta() {

    Bala **bala = new Bala*[2];

    int cont = 15;

    for (int i = 0; i < 2; i++) {

        bala[i] = new BalaEscopeta("balasEscopeta.png", 1);



        if (this->getface() == true)
            bala[i]->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x + cont, this->getSprite()->getPosition().y);
        else
            bala[i]->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x -cont, this->getSprite()->getPosition().y);


        b2PolygonShape shp_;
        shp_.SetAsBox(3.f, 4.f);
        bala[i]->setFixture(&shp_, 1.f, 0.f, 0.f);
        if (this->getface() == true)
            bala[i]->getCuerpo()->getBody()->SetLinearVelocity({210, 0});
        else {
            bala[i]->getCuerpo()->getBody()->SetLinearVelocity({-210, 0});
        }

        balas.push_back(bala[i]);

        cont = cont + 10;
    }

}

void Alien::dispararM4() {



    Bala **bala = new Bala*[3];

    int cont = 15;

    for (int i = 0; i < 3; i++) {

        bala[i] = new BalaM4("balasM4.png", 1);



        if (this->getface() == true)
            bala[i]->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x + cont, this->getSprite()->getPosition().y + 5);
        else
            bala[i]->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x - cont, this->getSprite()->getPosition().y + 5);


        b2PolygonShape shp_;
        shp_.SetAsBox(3.f, 6.f);
        bala[i]->setFixture(&shp_, 1.f, 0.f, 0.f);
        if (this->getface() == true)
            bala[i]->getCuerpo()->getBody()->SetLinearVelocity({210, 0});
        else {
            bala[i]->getCuerpo()->getBody()->SetLinearVelocity({-210, 0});
        }

        balas.push_back(bala[i]);

        cont = cont + 10;
    }


}

void Alien::dispararLanzaCohetes() {


    Bala *bala = new balaLC("balasLC.png", 2);
    if (this->getface() == true)
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x + 20, this->getSprite()->getPosition().y + 5);
    else
        bala->setBody(this->getArma()->getCuerpo()->getBody()->GetWorld(), this->getSprite()->getPosition().x - 20, this->getSprite()->getPosition().y + 5);


    b2PolygonShape shp_;
    shp_.SetAsBox(8.f, 4.f);
    bala->setFixture(&shp_, 1.f, 0.f, 0.f);
    if (this->getface() == true)
        bala->getCuerpo()->getBody()->SetLinearVelocity({150, 0});
    else {
        bala->getCuerpo()->getBody()->SetLinearVelocity({-150, 0});
    }

    balas.push_back(bala);

}

