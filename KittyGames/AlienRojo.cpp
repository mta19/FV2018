/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlienRojo.cpp
 * Author: pedro
 * 
 * Created on 10 de abril de 2018, 22:08
 */

#include "AlienRojo.h"
#include "EstadoPersonaje.h"

AlienRojo::AlienRojo() {
}

AlienRojo::AlienRojo(const AlienRojo& orig) {
}

AlienRojo::~AlienRojo() {
}


void AlienRojo::setSprite() {


    textura = new Texture();

    textura->loadFromFile("Rojo.png");
    sprite = new Sprite(*textura);



    setFrame(*sprite);
    sprite->setPosition(300.0f, 200.0f);
    sprite->setScale(28.f / sprite->getTexture()->getSize().x, 80.f / sprite->getTexture()->getSize().y);

    animacion = new Animacion(textura, Vector2u(3, 7), 0.3f);
}

Sprite* AlienRojo::getSprite() {

    return sprite;

}

Texture* AlienRojo::getTextura() {

    return textura;

}

void AlienRojo::setAnimacion() {


}

void AlienRojo::setFrame(Sprite& spr) {

    IntRect posicion(0, 0, spr.getTexture()->getSize().x / 3, spr.getTexture()->getSize().y/7);
    spr.setTextureRect(posicion);
    
    
}

void AlienRojo::handleInput(Event* tecla, Nivel* nivel) {


    EstadoPersonaje* estado = estado_->handleInput(*this, tecla, nivel);


    if (estado != NULL) {

        delete estado_;

        estado_ = estado;

    }


}

