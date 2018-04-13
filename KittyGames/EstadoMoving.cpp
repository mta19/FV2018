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


    persona.setFila(5);

    b2Body * body = nivel->getPersonaje()->getBody();


    b2Vec2 vel = body->GetLinearVelocity();
    
    
    if(vel.x<=1 && vel.x>=-1) persona.setFila(0);

    if (tecla->type == Event::KeyPressed) {

  body->SetFixedRotation(true); //YOU WORK
  
        if (tecla->key.code == Keyboard::X && persona.getNumFoot() >= 1 ) {

            nivel->getColisiones()->setId(0);

          
            vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*1000;

            std::cout<<body->GetMass()<<std::endl;

            if (Keyboard::isKeyPressed(Keyboard::D)) {

                vel.x = body->GetMass()*5000;
                vel.y = vel.y;

                persona.setface(true);

                body->ApplyForceToCenter({vel.x, -vel.y}, true);


                persona.setFila(5);

                return new EstadoJumping();


            }

            if (Keyboard::isKeyPressed(Keyboard::A)) {

                vel.x = -body->GetMass()*5000;
                vel.y = vel.y;

                persona.setface(false);
                body->ApplyForceToCenter({vel.x, -vel.y}, true);

                persona.setFila(5);

                return new EstadoJumping();

            }


            body->ApplyForceToCenter({vel.x, -vel.y}, true);



            persona.setFila(5);
            return new EstadoJumping();


        } else if (Keyboard::isKeyPressed(Keyboard::D)) {

            vel.x = 20;

            body->SetLinearVelocity(vel);
            persona.setface(true);


            persona.setFila(5);
            return new EstadoMoving();

        } else if (Keyboard::isKeyPressed(Keyboard::A)) {

            vel.x = -20;

            persona.setface(false);
            body->SetLinearVelocity(vel);

            persona.setFila(5);
            return new EstadoMoving();
        }
        else if (tecla->key.code == Keyboard::S) {

            vel.x = 0;

            body->SetLinearVelocity(vel);

            persona.setFila(0);
            return new EstadoStanding;
        }


    }else {
        
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

    }
    return new EstadoStanding;


}

void EstadoMoving::accion(Personaje& personaje, Nivel* nivel, Event * tecla) {


}
