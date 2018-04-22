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


            checkaabb(cuerpoA, cuerpoB);
            checkaabb(cuerpoB, cuerpoA);

            sensorA = contacto->GetFixtureA()->IsSensor();
            sensorB = contacto->GetFixtureA()->IsSensor();

            if (sensorA == true || sensorB == true) {

                

                if (cuerpoA->get_id_id() == identificador::jugador && cuerpoB->get_id_id()==identificador::escalera) {
                    
                                   std::cout << "hay sensor " << std::endl;
                   
                    cuerpoA->isOnStair(sensorA);

                } 

                if (cuerpoB->get_id_id() == identificador::jugador && cuerpoA->get_id_id() == identificador::escalera) {
                    
                                   std::cout << "hay sensor " << std::endl;

                    cuerpoB->isOnStair(sensorB);

                }
                
                 if (cuerpoA->get_id_id() == identificador::jugador && cuerpoB->get_id_id()==identificador::pistola) {
                     
                     std::cout << "hay sensor Pistola" << std::endl;
                   
                    cuerpoA->isOnWeapon(sensorA);

                } 

                if (cuerpoB->get_id_id() == identificador::jugador && cuerpoA->get_id_id() == identificador::pistola) {
                    
                                   std::cout << "hay sensor Pistola" << std::endl;

                    cuerpoB->isOnWeapon(sensorB);

                }

            }

            void* fixtureUserData = contacto->GetFixtureA()->GetUserData();


            if ((intptr_t) fixtureUserData == 3 && cuerpoB->get_id_id()!=identificador::pistola) {
               
                    cuerpoA->subirNumFoot();
            }

            fixtureUserData = contacto->GetFixtureB()->GetUserData();

            if ((intptr_t) fixtureUserData == 3 && cuerpoA->get_id_id()!=identificador::pistola) {
                //std::cout << "sube" << std::endl;
           
                    cuerpoB->subirNumFoot();
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
                
                 if (cuerpoA->get_id_id() == identificador::jugador && cuerpoB->get_id_id()==identificador::escalera) {
                   
                    cuerpoA->isOnStair(false);

                } 

                if (cuerpoB->get_id_id() == identificador::jugador && cuerpoA->get_id_id() == identificador::escalera) {

                    cuerpoB->isOnStair(false);

                }
                 
                    if (cuerpoA->get_id_id() == identificador::jugador && cuerpoB->get_id_id()==identificador::pistola) {
                     
                     std::cout << "hay sensor Pistola" << std::endl;
                   
                    cuerpoA->isOnWeapon(false);

                } 

                if (cuerpoB->get_id_id() == identificador::jugador && cuerpoA->get_id_id() == identificador::pistola) {
                    
                                   std::cout << "hay sensor Pistola" << std::endl;

                    cuerpoB->isOnWeapon(false);

                }

            }

            void *fixtureUserData = contacto->GetFixtureA()->GetUserData();
            if ((intptr_t) fixtureUserData == 3 && cuerpoB->get_id_id()!=identificador::pistola) {
            //    std::cout << "baja" << std::endl;
                
                    cuerpoA->bajarNumFoot();

            }

            //check if fixture B was the foot sensor
            fixtureUserData = contacto->GetFixtureB()->GetUserData();
            if ((intptr_t) fixtureUserData == 3 && cuerpoA->get_id_id()!=identificador::pistola) {
              //  std::cout << "baja" << std::endl;
           
                    cuerpoB->bajarNumFoot();
            }

        }


        
    }



}

void Collision::checkaabb(Ensamblador* a, Ensamblador* b) {

    if (a->get_id_id() == identificador::jugador) {

        switch (b->get_id_id()) {

            case identificador::plataforma:

                id = 1;



                break;

            case identificador::caja:

                id = 1;

                break;
                
                
            case identificador::balaPistola:
                
                std::cout<<"hay colision"<<std::endl;
                break;
                
            default:
                id = 0;
                break;

        }
    }
}


