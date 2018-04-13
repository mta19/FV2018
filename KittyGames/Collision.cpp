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
    sensorA = false;
    sensorB = false;
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

            sensorA = contacto->GetFixtureA()->IsSensor();
            sensorB = contacto->GetFixtureA()->IsSensor();

            if (sensorA == true || sensorB == true) {

                std::cout << "hay sensor" << std::endl;

                if (cuerpoA->get_id_id() == identificador::jugador) {
                       if(cuerpoA->getEntidad()!=NULL)
                    cuerpoA->getEntidad()->isOnStair(sensorA);

                }

                if (cuerpoB->get_id_id() == identificador::jugador) {

                       if(cuerpoB->getEntidad()!=NULL)
                    cuerpoB->getEntidad()->isOnStair(sensorB);

                }

            }

            void* fixtureUserData = contacto->GetFixtureA()->GetUserData();


            if ((intptr_t) fixtureUserData == 3) {
                if (cuerpoA->getEntidad() != NULL)
                    cuerpoA->getEntidad()->subirNumFoot();
            }

            fixtureUserData = contacto->GetFixtureB()->GetUserData();

            if ((intptr_t) fixtureUserData == 3) {
                std::cout << "sube" << std::endl;
                if (cuerpoB->getEntidad() != NULL)
                    cuerpoB->getEntidad()->subirNumFoot();
            }

        }

    }



}

void Collision::EndContact(b2Contact* contacto) {


    if (Ensamblador * cuerpoA = (Ensamblador*) contacto->GetFixtureA()->GetBody()->GetUserData()) {


        if (Ensamblador * cuerpoB = (Ensamblador*) contacto->GetFixtureB()->GetBody()->GetUserData()) {



            sensorA = contacto->GetFixtureA()->IsSensor();
            sensorB = contacto->GetFixtureA()->IsSensor();

            if (sensorA || sensorB) {
                   if(cuerpoA->getEntidad()!=NULL)
                cuerpoA->getEntidad()->isOnStair(false);
                      if(cuerpoB->getEntidad()!=NULL)
                cuerpoB->getEntidad()->isOnStair(false);

            }

            void *fixtureUserData = contacto->GetFixtureA()->GetUserData();
            if ((intptr_t) fixtureUserData == 3) {
                std::cout << "baja" << std::endl;
                if (cuerpoA->getEntidad() != NULL)
                    cuerpoA->getEntidad()->bajarNumFoot();

            }

            //check if fixture B was the foot sensor
            fixtureUserData = contacto->GetFixtureB()->GetUserData();
            if ((intptr_t) fixtureUserData == 3) {
                std::cout << "baja" << std::endl;
                if (cuerpoB->getEntidad() != NULL)
                    cuerpoB->getEntidad()->bajarNumFoot();
            }

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

                id = 1;

                break;
            default:
                id = 0;
                break;

        }
    }
}


