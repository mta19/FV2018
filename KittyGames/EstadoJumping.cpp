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


    b2Body * body = persona.getCuerpo()->getBody();

    b2Vec2 vel = body->GetLinearVelocity();
   
    std::cout<<persona.getCuerpo()->getNumFoot()<<std::endl;
    
    if (vel.x <= 1 && vel.x >= -1) persona.setFila(0);

   
    if (/*nivel->getColisiones()->getId() == 1*/ /*vel.y<1 && vel.y>-1*/ persona.getCuerpo()->getNumFoot()>= 1 ) {



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



        if (persona.getCuerpo()->getisOnstair() == true) {

            if (Keyboard::isKeyPressed(Keyboard::W)) {

                vel.x = 0;
                vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*100;

                persona.setface(true);

                body->SetLinearVelocity(-vel);

                persona.setFila(2);

                body->SetGravityScale(0);

                return new EstadoJumping();


            }
            
            else   body->SetGravityScale(1.5f);
        }

        return new EstadoJumping();

    }

    return new EstadoJumping();
}


EstadoPersonaje* EstadoJumping::handleInputJoystick(Personaje& persona, Event* tecla, Nivel * nivel, int mando){
    
   
    b2Body * body = persona.getCuerpo()->getBody();


    b2Vec2 vel = body->GetLinearVelocity();
   
    std::cout<<persona.getCuerpo()->getNumFoot()<<std::endl;
    
    if (vel.x <= 1 && vel.x >= -1) persona.setFila(0);

   
    if (/*nivel->getColisiones()->getId() == 1*/ /*vel.y<1 && vel.y>-1*/ persona.getCuerpo()->getNumFoot()>= 1 ) {



        if (Joystick::isButtonPressed(mando, 5)) {


            vel.x = 20;

            body->SetLinearVelocity(vel);
            persona.setface(true);


            persona.setFila(5);

            return new EstadoMoving();

        } else if (Joystick::isButtonPressed(mando, 4)) {

            vel.x = -20;


            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }


        persona.setFila(0);

        return new EstadoStanding;

    } else {

        if (Joystick::isButtonPressed(mando, 5)) {

            vel.x = 20;

            body->SetLinearVelocity(vel);
            persona.setface(true);

            persona.setFila(5);
            return new EstadoJumping();

        } else if (Joystick::isButtonPressed(mando, 4)) {

            vel.x = -20;

            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoJumping();
        }



        if (persona.getCuerpo()->getisOnstair() == true) {

            if (Joystick::isButtonPressed(mando, 0)) {

                vel.x = 0;
                vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*100;

                persona.setface(true);

                body->SetLinearVelocity(-vel);

                persona.setFila(2);

                body->SetGravityScale(0);

                return new EstadoJumping();


            }
            
            else   body->SetGravityScale(1.5f);
        }

        return new EstadoJumping();

    }

    return new EstadoJumping();
    
}

void EstadoJumping::accion(Personaje& personaje, Nivel* nivel, Event * tecla) {


}

