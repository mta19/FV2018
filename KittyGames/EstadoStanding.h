/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoStanding.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 17:04
 */

#ifndef ESTADOSTANDING_H
#define ESTADOSTANDING_H

#include "EstadoPersonaje.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Personaje.h"
#include "Nivel.h"

using namespace sf;

class EstadoStanding: public EstadoPersonaje{
public:
    EstadoStanding();
    EstadoStanding(const EstadoStanding& orig);
    virtual ~EstadoStanding();
    EstadoPersonaje* handleInput(Personaje& persona, Event* tecla, Nivel * nivel);
    void accion(Personaje& personaje, Nivel* nivel, Event * tecla);
private:

};

#endif /* ESTADOSTANDING_H */

