/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escopeta.h
 * Author: pedro
 *
 * Created on 25 de abril de 2018, 21:44
 */

#ifndef ESCOPETA_H
#define ESCOPETA_H

#include "Weapon.h"

class Escopeta : public Weapon {
public:
    Escopeta(String nombre);
    Escopeta(const Escopeta& orig);
    virtual ~Escopeta();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* ESCOPETA_H */

