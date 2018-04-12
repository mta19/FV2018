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
#include <cstdint>

enum entityCategory {
    BOUNDARY = 0x0001,
    FRIENDLY_PLAYER = 0x0002,
    ENEMY_PLAYER = 0x0004,
    STAIRS = 0x0008,
    ENEMY_AIRCRAFT = 0x0010,
};



class Ensamblador;

class Collision : public b2ContactListener {
public:
    Collision();
    Collision(const Collision& orig);
    virtual ~Collision();

    static int numFootContacts;
    void BeginContact(b2Contact* contacto);
    void EndContact(b2Contact* contacto);
    void checkaabb(Ensamblador& ensambladorA, Ensamblador& ensambladorB);

    int getId() {
        return id;
    };

    void setId(int i) {
        id = i;
    };
private:

    int id = 0;
    bool sensorA;
    bool sensorB;
};

#endif /* COLLISION_H */

