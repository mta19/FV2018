/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoJumping.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 17:40
 */

#ifndef ESTADOJUMPING_H
#define ESTADOJUMPING_H



#include <cstdlib>
#include <sstream>
#include <iostream>
#include "EstadoPersonaje.h"
#include "Personaje.h"
#include "SFML/Graphics.hpp"
#include "Nivel.h"
using namespace sf;
class EstadoJumping: public EstadoPersonaje{

 public:
     
    EstadoJumping();
    EstadoJumping(const EstadoJumping& orig);
    virtual ~EstadoJumping();
    EstadoPersonaje* handleInput(Personaje& personaje, Event* tecla, Nivel* nivel);
    EstadoPersonaje* handleInputJoystick(Personaje& persona, Event* tecla, Nivel * nivel, int mando);
    void accion(Personaje& personaje, Nivel* nivel, Event * tecla);

private:

};

#endif /* ESTADOJUMPING_H */

