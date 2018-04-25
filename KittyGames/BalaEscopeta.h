/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BalaEscopeta.h
 * Author: pedro
 *
 * Created on 25 de abril de 2018, 22:22
 */

#ifndef BALAESCOPETA_H
#define BALAESCOPETA_H

#include "Bala.h"

class BalaEscopeta : public Bala {
public:
    BalaEscopeta(String nombre, int i);
    BalaEscopeta(const BalaEscopeta& orig);
    virtual ~BalaEscopeta();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* BALAESCOPETA_H */

