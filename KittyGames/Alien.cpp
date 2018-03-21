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

Alien::Alien() {
}

Alien::Alien(const Alien& orig) {
}

Alien::~Alien() {
}


void Alien::setSprite(){
    
    textura= new Texture();
    textura->loadFromFile("alien_idle.png");
    sprite=new Sprite(*textura);
    

    setFrame(*sprite);
    sprite->setPosition(30.0f,80.0f);
    sprite->setScale(0.04f,0.04f);
    
     animacion= new Animacion(textura,Vector2u(3,1),0.3f);
}


Sprite* Alien::getSprite(){
    
    return sprite;
    
}

Texture* Alien::getTextura(){
    
    return textura;
    
}

void Alien::setAnimacion(){
    
    
}

void Alien::setFrame(Sprite& spr){
    
    IntRect posicion (0,0,spr.getTexture()->getSize().x/3,spr.getTexture()->getSize().y);
    spr.setTextureRect(posicion);
}


