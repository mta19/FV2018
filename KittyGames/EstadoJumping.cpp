/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoJumping.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 17:40
 */

#include "EstadoJumping.h"
#include "Box2D/Box2D.h"

#include "EstadoMoving.h"
#include "EstadoMoving.h"
#include "EstadoStanding.h"

EstadoJumping::EstadoJumping() {

}

EstadoJumping::EstadoJumping(const EstadoJumping& orig) {
}

EstadoJumping::~EstadoJumping() {
}

EstadoPersonaje* EstadoJumping::handleInput(Personaje& persona, Event* tecla, Nivel * nivel) {


    b2Body * body = nivel->getPersonaje()->getBody();

    b2Vec2 vel = body->GetLinearVelocity();

    if (nivel->getColisiones()->getId() == 1) {



        if (Keyboard::isKeyPressed(Keyboard::D)) {


            vel.x = 20;

            body->SetLinearVelocity(vel);
            persona.setface(true);


            persona.setFila(5);

            return new EstadoMoving();

        } else if (Keyboard::isKeyPressed(Keyboard::A)) {

            vel.x = -20;


            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }


        persona.setFila(0);

        return new EstadoStanding;

    } else {

        if (Keyboard::isKeyPressed(Keyboard::D)) {

            vel.x = 20;

            body->SetLinearVelocity(vel);
            persona.setface(true);

            persona.setFila(5);
            return new EstadoJumping();

        } else if (Keyboard::isKeyPressed(Keyboard::A)) {

            vel.x = -20;

            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoJumping();
        }

    }

    return new EstadoJumping();
}

void EstadoJumping::accion(Personaje& personaje, Nivel* nivel, Event * tecla) {


}

