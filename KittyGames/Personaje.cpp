/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 19:12
 */

#include "Personaje.h"
#include "EstadoPersonaje.h"
#include <iostream>
#include "EstadoStanding.h"

Personaje::Personaje(){
    
    estado_=new EstadoStanding();
    
}

Personaje::Personaje(const Personaje& orig) {
}


Personaje::~Personaje() {
}

void Personaje::handleInput(Event* tecla, Nivel* nivel){
           std::cout<<"estoy apuntito de saltar"<<std::endl;
           
    EstadoPersonaje* estado= estado_->handleInput(*this, tecla, nivel);
    
    
    if(estado!=NULL){
       
 
        
        delete estado_;
        
        estado_=estado;
        
        
        estado_->accion(*this, nivel, tecla);
        
    }
   
}

