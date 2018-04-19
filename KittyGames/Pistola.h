/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pistola.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 15:48
 */

#ifndef PISTOLA_H
#define PISTOLA_H

#include "Weapon.h"

class Pistola : public Weapon {
public:
    Pistola(String nombre);
    Pistola(const Pistola& orig);
    virtual ~Pistola();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* PISTOLA_H */

