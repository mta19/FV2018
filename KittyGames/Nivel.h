/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:54
 */

#ifndef NIVEL_H
#define NIVEL_H

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Ensamblador.h"
#include "SpawnerMonstruo.h"
using namespace sf;

class Nivel {
public:
    Nivel();
    Nivel(const Nivel& orig);
    virtual ~Nivel();
   
    void actualizar_fisica();
    void anyadirPlataforma(float x, float y);
    void anyadirObjetoDinamico(float x, float y);
    Ensamblador* getSuelo(){return ensambladorSuelo;};
    Ensamblador* getCaja(){return ensambladorCaja;};
    
private:

    Ensamblador * ensambladorSuelo;
    Ensamblador * ensambladorCaja;
    
    SpawnerMonstruo * spawnerMonstruo;
    
    int marcadores;
    
    Texture * txt_suelo;
    Texture * txt_caja;
    
    Sprite * spr_suelo;
    Sprite * spr_caja;
    
    
    //fisicas de los distintos objetos del mapa
    
    b2World * mundo;
    
    b2Body * bdy_suelo;
    b2BodyDef  bdydef_suelo;
    b2Fixture * fix_suelo;
    b2FixtureDef  fixdef_suelo;
    
    b2Body * bdy_caja;
    b2BodyDef  bdydef_caja;
    b2Fixture * fix_caja;
    b2FixtureDef  fixdef_caja;
    
};

#endif /* NIVEL_H */
