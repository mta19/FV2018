/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 15:47
 */

#ifndef BALA_H
#define BALA_H


#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Entidad.h"


class Bala : public Entidad {
public:
    Bala();
    Bala(const Bala& orig);
    virtual ~Bala();
    
    void setBody(b2World * mundo, float x, float y);
    virtual void setFixture(b2PolygonShape * forma, float density, float restitution, float friction)=0;
    Time& getlifetime(){return lifeTime;};
    Clock* getReloj(){return reloj;};
   
protected:

    Clock * reloj;
    Time lifeTime;

    
};

#endif /* BALA_H */

