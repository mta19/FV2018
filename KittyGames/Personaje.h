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
#include "Nivel.h"
#include "Entidad.h"

using namespace sf;

class EstadoPersonaje ;

class Personaje : public Entidad {
    
public:

    Personaje();
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    virtual void setSprite() = 0;
    virtual Sprite* getSprite() = 0;
    virtual Texture* getTextura() = 0;
    virtual void setAnimacion()= 0;
    virtual Animacion * getAnimacion()=0;
    virtual void setFrame(Sprite &spr)=0;
    virtual void handleInput(Event* tecla, Nivel* nivel);
    b2Vec2 getspeed(){return speed;};
    void setSpeed(b2Vec2  vector){ speed=vector;}
    
    EstadoPersonaje* setEstado(EstadoPersonaje* estado){estado_=estado;};
private:


protected:

    EstadoPersonaje * estado_;

    int vida;
    int vidaActual;
    int velocidad;
    int defensa;
    
    //variables para las fisicas
    
    b2Vec2  speed;

};

#endif /* PERSONAJE_H */

