/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entidad.h
 * Author: pedro
 *
 * Created on 25 de marzo de 2018, 13:17
 */

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Ensamblador.h"

using namespace sf;

enum entityCategory {
    BOUNDARY = 0x0001,
    FRIENDLY_PLAYER = 0x0002,
    ENEMY_PLAYER = 0x0004,
    STAIRS = 0x0008,
    ENEMY_AIRCRAFT = 0x0010,
};



class Entidad {
public:
    Entidad();
    Entidad(const Entidad& orig);
 
    virtual ~Entidad();
    Ensamblador* getCuerpo(){return cuerpo;};
    void setCuerpo(Ensamblador * ensamblador){cuerpo=ensamblador;};
    void setPosition(float x, float y);
    virtual void setBody(b2World * mundo, float x, float y)=0;
    virtual void setFixture(b2PolygonShape * forma, float density, float restitution, float friction)=0;
protected:

    Texture * txt;
    Sprite * spr;

    Ensamblador * cuerpo;
    

    b2Body * bdy;
    b2BodyDef bdydef_;
    b2Fixture * fix_;
    b2FixtureDef fixdef_;

    b2PolygonShape shp_;

 
    
};

#endif /* ENTIDAD_H */

