/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alien.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 1:36
 */

#ifndef ALIEN_H
#define ALIEN_H
#include "Personaje.h"
#include "SFML/Graphics.hpp"
#include "Animacion.h"
using namespace sf;
class Alien : public Personaje {
public:
    Alien();
    Alien(const Alien& orig);
    virtual ~Alien();
    void setSprite ();
    Sprite getSprite();
    Texture* getTextura();
    void setAnimacion();
    Animacion * getAnimacion(){ return animacion;};
    void setFrame(Sprite &spr);
private:
    
    Animacion * animacion;
    Texture * textura;
    Sprite * sprite;
    
    
    //Animacion * animacion;
};

#endif /* ALIEN_H */

