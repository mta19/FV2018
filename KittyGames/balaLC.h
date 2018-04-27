/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   balaLC.h
 * Author: pedro
 *
 * Created on 26 de abril de 2018, 18:25
 */

#ifndef BALALC_H
#define BALALC_H

#include "Bala.h"

class balaLC: public Bala {
public:
    balaLC(String nombre, int i);
    balaLC(const balaLC& orig);
    virtual ~balaLC();
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* BALALC_H */

