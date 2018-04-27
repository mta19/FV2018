/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LanzaCohetes.h
 * Author: pedro
 *
 * Created on 26 de abril de 2018, 18:25
 */

#ifndef LANZACOHETES_H
#define LANZACOHETES_H

#include "Weapon.h"

class LanzaCohetes : public Weapon {
public:
    LanzaCohetes(String nombre);
    LanzaCohetes(const LanzaCohetes& orig);
    virtual ~LanzaCohetes();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* LANZACOHETES_H */

