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
#include "Entidad.h"
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




    if (Entidad * cuerpoA = (Entidad*) contacto->GetFixtureA()->GetBody()->GetUserData()) {


        if (Entidad * cuerpoB = (Entidad*) contacto->GetFixtureB()->GetBody()->GetUserData()) {


            checkaabb(cuerpoA, cuerpoB);
            checkaabb(cuerpoB, cuerpoA);

            sensorA = contacto->GetFixtureA()->IsSensor();
            sensorB = contacto->GetFixtureA()->IsSensor();

            if (sensorA == true || sensorB == true) {



                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::escalera) {

                    std::cout << "hay sensor " << std::endl;

                    cuerpoA->getCuerpo()->isOnStair(sensorA);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::escalera) {

                    std::cout << "hay sensor " << std::endl;

                    cuerpoB->getCuerpo()->isOnStair(sensorB);

                }

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::pistola) {

                    std::cout << "hay sensor Pistola" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeapon(sensorA);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::pistola) {

                    std::cout << "hay sensor Pistola" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeapon(sensorB);

                }

            }

            void* fixtureUserData = contacto->GetFixtureA()->GetUserData();


            if ((intptr_t) fixtureUserData == 3 && cuerpoB->getCuerpo()->get_id_id() != identificador::pistola) {

                cuerpoA->getCuerpo()->subirNumFoot();
            }

            fixtureUserData = contacto->GetFixtureB()->GetUserData();

            if ((intptr_t) fixtureUserData == 3 && cuerpoA->getCuerpo()->get_id_id() != identificador::pistola) {
                //std::cout << "sube" << std::endl;

                cuerpoB->getCuerpo()->subirNumFoot();
            }

        }

    }



}

void Collision::EndContact(b2Contact* contacto) {


    if (Entidad * cuerpoA = (Entidad*) contacto->GetFixtureA()->GetBody()->GetUserData()) {


        if (Entidad * cuerpoB = (Entidad*) contacto->GetFixtureB()->GetBody()->GetUserData()) {



            sensorA = contacto->GetFixtureA()->IsSensor();
            sensorB = contacto->GetFixtureA()->IsSensor();

            if (sensorA || sensorB) {

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::escalera) {

                    cuerpoA->getCuerpo()->isOnStair(false);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::escalera) {

                    cuerpoB->getCuerpo()->isOnStair(false);

                }

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::pistola) {

                    std::cout << "hay sensor Pistola" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeapon(false);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::pistola) {

                    std::cout << "hay sensor Pistola" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeapon(false);

                }

            }

            void *fixtureUserData = contacto->GetFixtureA()->GetUserData();
            if ((intptr_t) fixtureUserData == 3 && cuerpoB->getCuerpo()->get_id_id() != identificador::pistola) {
                //    std::cout << "baja" << std::endl;

                cuerpoA->getCuerpo()->bajarNumFoot();

            }

            //check if fixture B was the foot sensor
            fixtureUserData = contacto->GetFixtureB()->GetUserData();
            if ((intptr_t) fixtureUserData == 3 && cuerpoA->getCuerpo()->get_id_id() != identificador::pistola) {
                //  std::cout << "baja" << std::endl;

                cuerpoB->getCuerpo()->bajarNumFoot();
            }

        }



    }



}

void Collision::checkaabb(Entidad* a, Entidad* b) {

    if (a->getCuerpo()->get_id_id() == identificador::jugador) {

        switch (b->getCuerpo()->get_id_id()) {

            case identificador::plataforma:

                id = 1;



                break;

            case identificador::caja:

                id = 1;

                break;


            case identificador::balaPistola:

                std::cout << "hay colision" << std::endl;

                break;

            default:
                id = 0;
                break;

        }
    }
    
    if(a->getCuerpo()->get_id_id()==identificador::balaPistola){
        
       
       std::cout << "hay colision2" << std::endl;
        a->setDestroy(true);
    }
}


