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

#include "EstadoMoving.h"
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


    persona.setFila(0);

    
    b2Body * body = persona.getCuerpo()->getBody();

    b2Vec2 vel = body->GetLinearVelocity();

    

    
    if(vel.x<=1 && vel.x>=-1) persona.setFila(0);
    
    if (tecla->type == Event::KeyPressed) {
        
        if(persona.getCuerpo()->getisOnstair()==true){
            
              if (Keyboard::isKeyPressed(Keyboard::W)) {

                vel.x=0;
                vel.y = body->GetWorld()->GetGravity().y*1.5;

                persona.setface(true);

                body->SetLinearVelocity(-vel);
           
                persona.setFila(2);
                
                body->SetGravityScale(0.f);
               
                return new EstadoJumping();


            }
             
            
        }
    

        if (tecla->key.code == Keyboard::Space && persona.getCuerpo()->getNumFoot() >= 1 ) {

        
            body->SetFixedRotation(true); //YOU WORK
            vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*1000;
            

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


            persona.setFila(5);
            body->ApplyForceToCenter({vel.x, -vel.y}, true);
           

   
            return new EstadoJumping();


        } else if (Keyboard::isKeyPressed(Keyboard::D)) {
            
            vel.x = 25;

            body->SetLinearVelocity(vel);
            persona.setface(true);
            /*if(persona.getArma()!=NULL)
            persona.getArma()->getCuerpo()->getBody()->SetLinearVelocity(vel);*/
            persona.setFila(5);
            return new EstadoMoving();

        } else if (Keyboard::isKeyPressed(Keyboard::A)) {

            vel.x = -25;

            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }

        return new EstadoStanding();

    } else {
        
        if (Keyboard::isKeyPressed(Keyboard::D)) {

            vel.x = 25;

            body->SetLinearVelocity(vel);
            persona.setface(true);

            persona.setFila(5);
            return new EstadoMoving();

        } else if (Keyboard::isKeyPressed(Keyboard::A)) {

            vel.x = -25;

            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }

    }

    return new EstadoStanding();

}

EstadoPersonaje* EstadoStanding::handleInputJoystick(Personaje& persona, Event* tecla, Nivel * nivel, int mando){
    
    
    persona.setFila(0);

    b2Body * body = persona.getCuerpo()->getBody();

    
    b2Vec2 vel = body->GetLinearVelocity();

    

    
    if(vel.x<=1 && vel.x>=-1) persona.setFila(0);
    
    if (Event::JoystickButtonPressed) {
        
        if(persona.getCuerpo()->getisOnstair()==true){
            
              if (Joystick::isButtonPressed(mando, 0)) {
                  
                  std::cout<<"entro aqui1"<<std::endl;

                vel.x=0;
                vel.y = body->GetWorld()->GetGravity().y*1.5;

                persona.setface(true);

                body->SetLinearVelocity(-vel);
           
                persona.setFila(2);
                
                body->SetGravityScale(0.f);
               
                return new EstadoJumping();


            }
             
            
        }
    

        if (Joystick::isButtonPressed(mando, 1) && persona.getCuerpo()->getNumFoot() >= 1 ) {

             std::cout<<"entro aqui2"<<std::endl;
        
            body->SetFixedRotation(true); //YOU WORK
            vel.y = body->GetWorld()->GetGravity().y * body->GetMass()*1000;
            

            if (Joystick::isButtonPressed(mando, 5)) {

                vel.x = body->GetMass()*5000;
                vel.y = vel.y;

                persona.setface(true);

                body->ApplyForceToCenter({vel.x, -vel.y}, true);
               

                persona.setFila(5);
                return new EstadoJumping();


            }

            if (Joystick::isButtonPressed(mando, 4)) {

                vel.x = -body->GetMass()*5000;
                vel.y = vel.y;

                persona.setface(false);
                body->ApplyForceToCenter({vel.x, -vel.y}, true);

                persona.setFila(5);

                return new EstadoJumping();

            }


            persona.setFila(5);
            body->ApplyForceToCenter({vel.x, -vel.y}, true);
           

   
            return new EstadoJumping();


        } else if (Joystick::isButtonPressed(mando, 5)) {
            
         
            vel.x = 25;

            body->SetLinearVelocity(vel);
            persona.setface(true);
            /*if(persona.getArma()!=NULL)
            persona.getArma()->getCuerpo()->getBody()->SetLinearVelocity(vel);*/
            persona.setFila(5);
            return new EstadoMoving();

        } else if (Joystick::isButtonPressed(mando, 4)) {

            vel.x = -25;

            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }

        return new EstadoStanding();

    } else {
        
        if (Joystick::isButtonPressed(mando, 5)) {

            vel.x = 25;

            body->SetLinearVelocity(vel);
            persona.setface(true);

            persona.setFila(5);
            return new EstadoMoving();

        } else if (Joystick::isButtonPressed(mando, 4)) {

            vel.x = -25;

            persona.setFila(5);
            persona.setface(false);
            body->SetLinearVelocity(vel);
            return new EstadoMoving();
        }

    }

    return new EstadoStanding();

    
}

void EstadoStanding::accion(Personaje& personaje, Nivel* nivel, Event * tecla) {


}

