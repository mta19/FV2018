/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collision.cpp
 * Author: pedro
 * 
 * Created on 24 de marzo de 2018, 12:57
 */

#include "Collision.h"
#include "Ensamblador.h"
#include "EstadoStanding.h"
#include "EstadoMoving.h"

Collision::Collision() {
    id = 0;
}

Collision::Collision(const Collision& orig) {
}

Collision::~Collision() {
}

void Collision::BeginContact(b2Contact* contacto) {



    if (Ensamblador * cuerpoA = (Ensamblador*) contacto->GetFixtureA()->GetBody()->GetUserData()) {


        if (Ensamblador * cuerpoB = (Ensamblador*) contacto->GetFixtureB()->GetBody()->GetUserData()) {

            checkaabb(*cuerpoA, *cuerpoB);
            checkaabb(*cuerpoB, *cuerpoA);
            

        }
    }


}

void Collision::checkaabb(Ensamblador& a, Ensamblador& b) {

    if (a.get_id_id() == identificador::jugador) {

        switch (b.get_id_id()) {

            case identificador::plataforma:

                id = 1;

                break;

            case identificador::caja:
                
                id=1;
                
                break;
            default:
                id = 0;
                break;

        }
    }
}


