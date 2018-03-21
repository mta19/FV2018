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
    sprite->setPosition(600.0f,550.0f-sprite->getTexture()->getSize().y*0.3);
    sprite->setScale(150.f/sprite->getTexture()->getSize().x,75.f/sprite->getTexture()->getSize().y);
    
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


