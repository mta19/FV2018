/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 15:46
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "Bala.h"
#include "Entidad.h"
class Weapon : public Entidad{
public:
    Weapon();
    Weapon(const Weapon& orig);
    virtual ~Weapon();
     void setBody(b2World * mundo, float x, float y);
    virtual void setFixture(b2PolygonShape * forma, float density, float restitution, float friction)=0;
    void Update(b2Vec2  vector);
protected:

    Bala * bala;
    
    int cargador;
    
    int rango;
    
    
    
};

#endif /* WEAPON_H */

