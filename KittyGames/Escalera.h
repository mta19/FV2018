/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Escalera.h
 * Author: pedro
 *
 * Created on 18 de abril de 2018, 18:45
 */

#ifndef ESCALERA_H
#define ESCALERA_H

#include "Entidad.h"

class Escalera : public  Entidad {
public:
    Escalera(String nombre);
    Escalera(const Escalera& orig);
    virtual ~Escalera();
    void setBody(b2World * mundo, float x, float y);
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);
private:

};

#endif /* ESCALERA_H */

