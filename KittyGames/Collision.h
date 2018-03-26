/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collision.h
 * Author: pedro
 *
 * Created on 24 de marzo de 2018, 12:57
 */

#ifndef COLLISION_H
#define COLLISION_H


#include "Box2D/Box2D.h"


class Ensamblador;

class Collision: public b2ContactListener {
public:
    Collision();
    Collision(const Collision& orig);
    virtual ~Collision();
    
    void BeginContact (b2Contact* contacto);
    void checkaabb(Ensamblador& ensambladorA, Ensamblador& ensambladorB);
    
    int getId(){return id;};
private:

    int id=0;
    
};

#endif /* COLLISION_H */

