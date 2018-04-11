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


    textura = new Texture();

    textura->loadFromFile("Verde.png");
    sprite = new Sprite(*textura);



    setFrame(*sprite);
    sprite->setPosition(300.0f, 200.0f);
    sprite->setScale(28.f / sprite->getTexture()->getSize().x, 80.f / sprite->getTexture()->getSize().y);

    animacion = new Animacion(textura, Vector2u(3, 7), 0.3f);
}

Sprite* Alien::getSprite() {

    return sprite;

}

Texture* Alien::getTextura() {

    return textura;

}

void Alien::setAnimacion() {


}

void Alien::setFrame(Sprite& spr) {

    IntRect posicion(0, 0, spr.getTexture()->getSize().x / 3, spr.getTexture()->getSize().y/7);
    spr.setTextureRect(posicion);
    
    
}

void Alien::handleInput(Event* tecla, Nivel* nivel) {


    EstadoPersonaje* estado = estado_->handleInput(*this, tecla, nivel);


    if (estado != NULL) {

        delete estado_;

        estado_ = estado;

    }


}

