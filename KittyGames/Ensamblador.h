/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ensamblador.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 20:01
 */

#ifndef ENSAMBLADOR_H
#define ENSAMBLADOR_H

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
using namespace sf;

class Ensamblador {
public:
    Ensamblador(b2Body * cuerpo, Sprite * sprite);
    Ensamblador(const Ensamblador& orig);
    virtual ~Ensamblador();
    
    float rad2deg(float radianes);
    void dibujar (RenderWindow& r);
    
private:

    Sprite * spr_actor;
    b2Body * bdy_actor;
    
    b2Vec2 posicion;
    
};

#endif /* ENSAMBLADOR_H */

