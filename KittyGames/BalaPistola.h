/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalaPistola.h
 * Author: pedro
 *
 * Created on 19 de abril de 2018, 13:07
 */

#ifndef BALAPISTOLA_H
#define BALAPISTOLA_H


#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Bala.h"


class BalaPistola : public Bala {
public:
    BalaPistola(String nombre);
    BalaPistola(const BalaPistola& orig);
    virtual ~BalaPistola();
     void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* BALAPISTOLA_H */

