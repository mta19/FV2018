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

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::escopeta) {

                    std::cout << "hay sensor escopeta" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeaponSG(sensorA);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::escopeta) {

                    std::cout << "hay sensor escopeta" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeaponSG(sensorB);

                }

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::m4) {

                    std::cout << "hay sensor m4" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeaponM4(sensorA);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::m4) {

                    std::cout << "hay sensor m4" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeaponM4(sensorB);

                }

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {

                    std::cout << "hay sensor lanzaCohetes" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeaponRL(sensorA);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {

                    std::cout << "hay sensor lanzaCohetes" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeaponRL(sensorB);

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

                //no se si esta bien

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::escopeta) {

                    std::cout << "hay sensor escopeta" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeaponSG(false);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::escopeta) {

                    std::cout << "hay sensor escopeta" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeaponSG(false);

                }

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::m4) {

                    std::cout << "hay sensor m4" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeaponM4(false);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::m4) {

                    std::cout << "hay sensor m4" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeaponM4(false);

                }

                if (cuerpoA->getCuerpo()->get_id_id() == identificador::jugador && cuerpoB->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {

                    std::cout << "hay sensor lanzaCohetes" << std::endl;

                    cuerpoA->getCuerpo()->isOnWeaponRL(false);

                }

                if (cuerpoB->getCuerpo()->get_id_id() == identificador::jugador && cuerpoA->getCuerpo()->get_id_id() == identificador::lanzaCohetes) {

                    std::cout << "hay sensor lanzaCohetes" << std::endl;

                    cuerpoB->getCuerpo()->isOnWeaponRL(false);

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

     int auxiliar;
    
    if (a->getCuerpo()->get_id_id() == identificador::jugador) {

        switch (b->getCuerpo()->get_id_id()) {

            case identificador::plataforma:

                id = 1;



                break;

            case identificador::caja:
                
                
                if(b->getCuerpo()->getBody()->GetLinearVelocity().y>30 ){
                    
                    auxiliar=a->getVida()-100;
                    a->setVida(auxiliar);
                }
                

                break;


            case identificador::balaPistola:

               
                
                auxiliar=a->getVida()-b->getDamage();
                
                a->setVida(auxiliar);

                break;

            case identificador::balaCohete:

                
                
                
                auxiliar=a->getVida()-b->getDamage();
                
                a->setVida(auxiliar);


                break;

            case identificador::balaEscopeta:

       
                
                auxiliar=a->getVida()-b->getDamage();
                
                a->setVida(auxiliar);


                break;

            case identificador::balaM4:

                auxiliar=a->getVida()-b->getDamage();
                
                a->setVida(auxiliar);

                break;

            default:
                id = 0;
                break;

        }
    }

    if (a->getCuerpo()->get_id_id() == identificador::balaPistola || a->getCuerpo()->get_id_id() == identificador::balaCohete || a->getCuerpo()->get_id_id() == identificador::balaEscopeta
            || a->getCuerpo()->get_id_id() == identificador::balaM4) {

        a->setDestroy(true);
        
    }

}


