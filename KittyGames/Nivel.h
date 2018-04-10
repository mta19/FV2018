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
#include "Collision.h"

using namespace sf;

class Nivel {
public:
    Nivel();
    Nivel(const Nivel& orig);
    virtual ~Nivel();

    void actualizar_fisica();
    void anyadirPlataforma(float x, float y, float weight, float height);
    void anyadirObjetoDinamico(float x, float y, float weight, float height);
    void anyadirPersonaje(float x, float y, Sprite * personaje);

    Ensamblador** getEnsambladores() {
        return ensambladores;
    };

    Ensamblador* getPersonaje() {
          
    for (int i = 0; i < 10; i++) {
        
        if(this->getEnsambladores()[i]!=NULL && this->getEnsambladores()[i]->get_id_id()==identificador::jugador)
       
            return this->getEnsambladores()[i];
    }
        return NULL;
    };
    
    Collision* getColisiones(){
        
        return procesadorColisiones;
    }
    
    b2World* getMundo(){
        
        return mundo;
    }
    
    static int contadorEn;

private:

    Ensamblador ** ensambladores;
    int marcadores;

    Texture * txt_suelo;
    Texture * txt_caja;

    Sprite **spr_suelo;
    Sprite * spr_caja;


    //fisicas de los distintos objetos del mapa

    b2World * mundo;

    b2Body ** bdy;
    b2BodyDef bdydef_suelo[10];
    b2Fixture * fix_suelo[10];
    b2FixtureDef fixdef_suelo[10];
    
    b2PolygonShape shp_suelo[3];
    
    b2Body * bdy_caja;
    b2BodyDef bdydef_caja;
    b2Fixture * fix_caja;
    b2FixtureDef fixdef_caja;

    b2Body * bdy_personaje;
    b2BodyDef bdydef_personaje;
    b2Fixture * fix_personaje;
    b2FixtureDef fixdef_personaje;

    Collision * procesadorColisiones;

};


#endif /* NIVEL_H */

