/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ensamblador.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 20:01
 */
#include <iostream>
#include "Ensamblador.h"

Ensamblador::Ensamblador(b2Body * cuerpo, Sprite * sprite) {
    
    
    bdy_actor=cuerpo;

    spr_actor=sprite;
    
  
    posicion=bdy_actor->GetPosition();
    spr_actor->setOrigin(spr_actor->getTexture()->getSize().x/2.f, spr_actor->getTexture()->getSize().y/2.f);
    
    spr_actor->setPosition(posicion.x,posicion.y);
    spr_actor->setRotation(rad2deg(bdy_actor->GetAngle()));
 
    
    b2AABB dimension;
    
    dimension.upperBound= b2Vec2(-FLT_MAX,FLT_MAX);
    dimension.lowerBound=b2Vec2(FLT_MAX,FLT_MAX);
    
    for(b2Fixture *f =bdy_actor->GetFixtureList(); f;f=f->GetNext()){
        
        dimension=f->GetAABB(0);
          
    }
      std::cout<<"Por ahora funciona7"<<std::endl;
    spr_actor->setScale(dimension.GetExtents().x*2/spr_actor->getTexture()->getSize().x, dimension.GetExtents().y*2/spr_actor->getTexture()->getSize().y);
    
  
}

Ensamblador::Ensamblador(const Ensamblador& orig) {
}

Ensamblador::~Ensamblador() {
}

float Ensamblador::rad2deg(float radianes){
    
    return radianes * 100 / 3.14;
}

void Ensamblador::dibujar(RenderWindow& r){
    
    
    posicion=bdy_actor->GetPosition();
    spr_actor->setPosition(posicion.x,posicion.y);
    
    spr_actor->setRotation(rad2deg(bdy_actor->GetAngle()));
    r.draw(*spr_actor);
}
