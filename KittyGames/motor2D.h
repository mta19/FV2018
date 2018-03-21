/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   motor2D.h
 * Author: pedro
 *
 * Created on 20 de marzo de 2018, 4:01
 */

#ifndef MOTOR2D_H
#define MOTOR2D_H

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Ensamblador.h"
#include "Personaje.h"
using namespace sf;

class motor2D {
public:
    motor2D();
    motor2D(const motor2D& orig);
    virtual ~motor2D();
    
    b2Body crearBody(int x, int y, b2BodyType tipo, b2World* mundo);
    void anyadirTextura(Texture *textura);
    void setSprite(Texture* texture,String nombre, Personaje * personaje);
    
private:

};

#endif /* MOTOR2D_H */

