/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EstadoMoving.cpp
 * Author: pedro
 * 
 * Created on 26 de marzo de 2018, 0:39
 */

#include "EstadoMoving.h"

EstadoMoving::EstadoMoving() {

 

}

EstadoMoving::EstadoMoving(const EstadoMoving& orig) {
}

EstadoMoving::~EstadoMoving() {
}

EstadoPersonaje* EstadoMoving::handleInput(Personaje& persona, Event* tecla, Nivel * nivel) {

    b2Body * body = nivel->getPersonaje()->getBody();



    b2Vec2 vel = body->GetLinearVelocity();

    if (tecla->type == Event::KeyPressed) {


        if (tecla->key.code == Keyboard::X) {


            body->SetFixedRotation(true); //YOU WORK
            vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*100;


            if (Keyboard::isKeyPressed(Keyboard::D)) {

                vel.x = body->GetMass()*1000;
                vel.y = vel.y;

                persona.setface(true);

                body->ApplyForceToCenter({vel.x, -vel.y}, true);



                return new EstadoJumping();


            }

            if (Keyboard::isKeyPressed(Keyboard::A)) {

                vel.x = -body->GetMass()*1000;
                vel.y = vel.y;

                persona.setface(false);
                body->ApplyForceToCenter({vel.x, -vel.y}, true);

                return new EstadoJumping();

            }


            body->ApplyForceToCenter({vel.x, -vel.y}, true);


            return new EstadoJumping();


        } else if (Keyboard::isKeyPressed(Keyboard::D)) {

            vel.x = 20;

            body->SetLinearVelocity(vel);
            persona.setface(true);

            return new EstadoMoving();

        } else if (Keyboard::isKeyPressed(Keyboard::A)) {

            vel.x = -20;

            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }



    }

}

void EstadoMoving::accion(Personaje& personaje, Nivel* nivel, Event * tecla) {


}
