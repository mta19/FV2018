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

class Personaje;

enum identificador {
    jugador, enemigo, caja, plataforma, escalera
};

using namespace sf;



class Ensamblador {
public:
    Ensamblador(b2Body * cuerpo, Sprite * sprite, float width, float height);
    Ensamblador(const Ensamblador& orig);
    virtual ~Ensamblador();

    float rad2deg(float radianes);
    void dibujar(RenderWindow& r);

    b2Body* getBody();

    void set_id_id(identificador id) {
        id_id = id;
    };

    identificador get_id_id() {
        return id_id;
    };
    
    void setEntidad(Personaje *e);
    
    void isOnStair(bool aux){onStair=aux;};
    bool getisOnstair(){return onStair;};
    Personaje* getEntidad();
 

private:
    

    Sprite * spr_actor;
    b2Body * bdy_actor;

    b2Vec2 posicion;

    identificador id_id;
    
    Personaje* entidad;

    bool onStair=false;
};

#endif /* ENSAMBLADOR_H */

