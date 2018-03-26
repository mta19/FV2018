/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 2:04
 */

#include "Animacion.h"

using namespace sf;
Animacion::Animacion(Texture *texture, Vector2u imageCount, float switchTime) {
    
    this->imageCount=imageCount;
    this->switchTime=switchTime;
    totalTime=0.0f;
    currentImage.x=0;
    
    uvRect.width=texture->getSize().x/float(imageCount.x);
    uvRect.height=texture->getSize().y/float(imageCount.y);
}

Animacion::Animacion(const Animacion& orig) {
}

Animacion::~Animacion() {
}

void Animacion::Update (int row, float deltatime, Sprite *sprite, bool faceRight){
    
    
    currentImage.y=row;
    totalTime += deltatime;
    
    if(totalTime>=switchTime){
        
        totalTime-=switchTime;
        currentImage.x++;
        
        if(currentImage.x>=imageCount.x){
            
            currentImage.x=0;
        }
    }
    
    uvRect.left=currentImage.x*uvRect.width;
    uvRect.top=currentImage.y*uvRect.height;
    
    if(faceRight){
        
        uvRect.left= currentImage.x*uvRect.width;
        uvRect.width=abs(uvRect.width); 
    }
    else{
        uvRect.left= (currentImage.x+1) * abs(uvRect.width);
        uvRect.width=-abs(uvRect.width);
        
    }
    sprite->setTextureRect(uvRect);
    
    
}
