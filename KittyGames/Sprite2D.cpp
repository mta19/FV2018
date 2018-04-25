/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite2D.cpp
 * Author: alejandro
 * 
 * Created on 24 de abril de 2018, 18:38
 */

#include "Sprite2D.h"

Sprite2D::Sprite2D(std::string textRoute, int rectLeft, int rectTop, int rectWidth, int rectHeight) {
    
    if(!this->textura.loadFromFile(textRoute)){
       
    }
        
    sprite = new sf::Sprite(this->textura,sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
      
}


Sprite2D::~Sprite2D() {
}

void Sprite2D::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight){
    sprite->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}

void Sprite2D::draw(Ventana& window){

    window.draw(sprite);
}