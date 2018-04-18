/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caja.h
 * Author: pedro
 *
 * Created on 18 de abril de 2018, 17:33
 */

#ifndef CAJA_H
#define CAJA_H


#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Entidad.h"

class Caja : public Entidad {
public:
    Caja(String nombre);
    Caja(const Caja& orig);
    virtual ~Caja();
    void setBody(b2World * mundo, float x, float y);
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
    
private:

    
    
};

#endif /* CAJA_H */

