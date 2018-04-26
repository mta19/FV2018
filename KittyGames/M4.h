/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   M4.h
 * Author: pedro
 *
 * Created on 26 de abril de 2018, 18:24
 */

#ifndef M4_H
#define M4_H

#include "Weapon.h"

class M4 : public Weapon {
public:
    M4(String nombre);
    M4(const M4& orig);
    virtual ~M4();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* M4_H */

