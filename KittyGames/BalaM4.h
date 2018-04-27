/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalaM4.h
 * Author: pedro
 *
 * Created on 26 de abril de 2018, 18:24
 */

#ifndef BALAM4_H
#define BALAM4_H

#include "Bala.h"

class BalaM4 : public Bala {
public:
    BalaM4(String nombre, int i);
    BalaM4(const BalaM4& orig);
    virtual ~BalaM4();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* BALAM4_H */

