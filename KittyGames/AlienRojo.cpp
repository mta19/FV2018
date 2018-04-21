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


    txt = new Texture();

    txt->loadFromFile("Rojo.png");
    spr = new Sprite(*txt);



    setFrame(*spr);
    spr->setPosition(300.0f, 200.0f);
    spr->setScale(28.f / spr->getTexture()->getSize().x, 80.f / spr->getTexture()->getSize().y);

    animacion = new Animacion(txt, Vector2u(3, 7), 0.3f);
}

Sprite* AlienRojo::getSprite() {

    return spr;

}

Texture* AlienRojo::getTextura() {

    return txt;

}

void AlienRojo::setAnimacion() {


}

void AlienRojo::setFrame(Sprite& spr) {

    IntRect posicion(0, 0, spr.getTexture()->getSize().x / 3, spr.getTexture()->getSize().y/7);
    spr.setTextureRect(posicion);
    
    
}



