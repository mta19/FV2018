/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoJumping.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 17:40
 */

#include "EstadoJumping.h"
#include "Box2D/Box2D.h"

EstadoJumping::EstadoJumping() {
    
    std::cout<<"estoy saltando"<<std::endl;
    
}

EstadoJumping::EstadoJumping(const EstadoJumping& orig) {
}

EstadoJumping::~EstadoJumping() {
}

EstadoPersonaje* EstadoJumping::handleInput(Personaje& personaje, Event* tecla, Nivel * nivel) {

    return new EstadoJumping();
}

void EstadoJumping::accion(Personaje& personaje, Nivel* nivel, Event * tecla){
    
    
   
    b2Body * body= nivel->getPersonaje()->getBody();
     
    

    
    std::cout<<personaje.getSprite()->getPosition().y<<std::endl;
    std::cout<<nivel->getPersonaje()->getBody()->GetPosition().y<<std::endl;
}

