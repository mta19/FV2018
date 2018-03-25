/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoStanding.cpp
 * Author: pedro
 * 
 * Created on 21 de marzo de 2018, 17:04
 */

#include <SFML/Audio/AlResource.hpp>

#include "EstadoJumping.h"
#include "EstadoStanding.h"
#include "EstadoPersonaje.h"

EstadoStanding::EstadoStanding() {
}

EstadoStanding::EstadoStanding(const EstadoStanding& orig) {
}

EstadoStanding::~EstadoStanding() {
}

EstadoPersonaje* EstadoStanding::handleInput(Personaje& persona, Event* tecla, Nivel * nivel) {


    b2Body * body = nivel->getPersonaje()->getBody();


    b2Vec2 vel = body->GetLinearVelocity();

    if (tecla->type == Event::KeyPressed) {

        if (tecla->key.code == Keyboard::X) {



            std::cout << body->GetMass() << std::endl;

            body->SetFixedRotation(true); //YOU WORK
            vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*100;


            if (Keyboard::isKeyPressed(Keyboard::D)) {

                vel.x = body->GetMass()*1000;
                vel.y = vel.y;

                body->ApplyForceToCenter({vel.x, -vel.y}, true);

                return new EstadoJumping();


            }

            if (Keyboard::isKeyPressed(Keyboard::A)) {

                vel.x = -body->GetMass()*1000;
                vel.y = vel.y;


                body->ApplyForceToCenter({vel.x, -vel.y}, true);

                return new EstadoJumping();

            }


            body->ApplyForceToCenter({vel.x, -vel.y}, true);


            return new EstadoJumping();


        } else if (Keyboard::isKeyPressed(Keyboard::D)) {

            vel.x = 20;

            body->SetLinearVelocity(vel);


            return new EstadoStanding();
        } else if (tecla->key.code == Keyboard::A) {

            vel.x = -20;


            body->SetLinearVelocity(vel);

        }

        return new EstadoStanding();

    }

}

void EstadoStanding::accion(Personaje& personaje, Nivel* nivel, Event * tecla) {


}

