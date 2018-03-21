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


Personaje::Personaje(){
    vida= 100;
    vidaActual= vida;
    puntuacion= 0;
    
}

Personaje::Personaje(const Personaje& orig) {
}


Personaje::~Personaje() {
}

int Personaje::getVida(){
    return vida;
}


int Personaje::getVidaActual(){
    return vidaActual;
}

void Personaje::updateVidaActual(int cambio){
    //Si recibe un entero negativo, se le resta por signo
    vidaActual+= cambio;
    if(vidaActual<=0){
        morir();
    }
}

void Personaje::morir(){
    //(?)
    //Eliminar Textura, Sprite y Personaje (Alien) -- (???)
}

int Personaje::getPuntuacion(){
    return puntuacion;
}

void Personaje::updatePuntuacion(int cambio){
    if(puntuacion>=cambio){
        puntuacion+= cambio;
    }
}
