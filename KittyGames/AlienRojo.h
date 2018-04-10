/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlienRojo.h
 * Author: pedro
 *
 * Created on 10 de abril de 2018, 22:08
 */

#ifndef ALIENROJO_H
#define ALIENROJO_H

#include "Personaje.h"
#include "SFML/Graphics.hpp"
#include "Animacion.h"
#include <iostream>

class AlienRojo: public Personaje {
public:
    AlienRojo();
    AlienRojo(const AlienRojo& orig);
    virtual ~AlienRojo();
      void setSprite ();
    Sprite* getSprite();
    Texture* getTextura();
    void setAnimacion();
    Animacion * getAnimacion(){ return animacion;};
    void setFrame(Sprite &spr);
    void handleInput(Event* tecla, Nivel* nivel);
private:

    Animacion * animacion;
    Texture * textura;
    Sprite * sprite;
    
    
};

#endif /* ALIENROJO_H */

