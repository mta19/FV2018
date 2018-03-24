/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoPersonaje.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 16:11
 */

#ifndef ESTADOPERSONAJE_H
#define ESTADOPERSONAJE_H

#include <cstdlib>
#include <sstream>
#include <iostream>

#include "SFML/Graphics.hpp"
#include "Personaje.h"
#include "Nivel.h"
//#include "EstadoStanding.h"

class EstadoStanding;
class EstadoJumping;
using namespace sf;
class EstadoPersonaje {
public:
    EstadoPersonaje();
    EstadoPersonaje(const EstadoPersonaje& orig);
    virtual ~EstadoPersonaje();
    virtual EstadoPersonaje* handleInput(Personaje& persona, Event* tecla, Nivel * nivel)=0;
    virtual void accion(Personaje& personaje, Nivel* nivel, Event * tecla)=0;
public:
    
   static EstadoStanding parado;
   static EstadoJumping saltando;
    
private:

     
    
};



#endif /* ESTADOPERSONAJE_H */

