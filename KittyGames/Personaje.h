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


#include "SpawnerMonstruo.h"
#include "SFML/Graphics.hpp"
#include "Animacion.h"
using namespace sf;

class Personaje {
public:

    Personaje();
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    virtual void setSprite() = 0;
    virtual Sprite getSprite() = 0;
    virtual Texture* getTextura() = 0;
    virtual void setAnimacion()= 0;
    virtual Animacion * getAnimacion()=0;
    virtual void setFrame(Sprite &spr)=0;
    
private:


protected:



    int vida;
    int vidaActual;
    int velocidad;
    int defensa;

};

#endif /* PERSONAJE_H */

