/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plataforma.h
 * Author: pedro
 *
 * Created on 18 de abril de 2018, 17:34
 */

#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Entidad.h"
class Plataforma : public Entidad{
public:
    Plataforma(String nombre);
    Plataforma(const Plataforma& orig);
    virtual ~Plataforma();
    void setBody(b2World * mundo, float x, float y);
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* PLATAFORMA_H */

