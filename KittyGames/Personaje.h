/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:12
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Ensamblador.h"
#include "SpawnerMonstruo.h"
class Personaje {
public:
 
    virtual ~Personaje();
    
    
private:

    
protected:
    Ensamblador ensamblador;
    SpawnerMonstruo * respawn;
    int vida;
    int vidaActual;
    int velocidad;
    int defensa;
    
};

#endif /* PERSONAJE_H */

