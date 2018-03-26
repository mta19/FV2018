/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoMoving.h
 * Author: pedro
 *
 * Created on 26 de marzo de 2018, 0:39
 */

#ifndef ESTADOMOVING_H
#define ESTADOMOVING_H

#include "EstadoJumping.h"
#include "EstadoStanding.h"
#include "EstadoPersonaje.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Personaje.h"
#include "Nivel.h"
class EstadoMoving: public EstadoPersonaje {
public:
    EstadoMoving();
    EstadoMoving(const EstadoMoving& orig);
    virtual ~EstadoMoving();
     EstadoPersonaje* handleInput(Personaje& persona, Event* tecla, Nivel * nivel);
    void accion(Personaje& personaje, Nivel* nivel, Event * tecla);
private:

};

#endif /* ESTADOMOVING_H */

