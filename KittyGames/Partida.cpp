/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 19:36
 */
#include <iostream>
#include "Partida.h"
#include "Personaje.h"
#include "Alien.h"
#include "Animacion.h"
#include "EstadoStanding.h"
#include "AlienRojo.h"
#include "AlienRojo.h"

Partida::Partida(Vector2i resolucion, std::string titulo) {

    numJ = 0;
    deltaTime = 0.0f;

    evento = new Event;
    fps = 60;
    frameRate = 1 / fps;

    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), titulo);
    ventana->setFramerateLimit(fps);

    set_camera();

    niveles = new Nivel();





    niveles->anyadirArma(350.f, 170.f, 40.f, 52.f);
    Nivel::contadorEn++;
    niveles->anyadirEscalera(400.f, 220.f, 12.f, 105.f);
    Nivel::contadorEn++;
    niveles->anyadirEscalera(273.f, 240.f, 12.f, 85.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(340.f, 300.0f, 80.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(347.f, 140.0f, 40.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(220.f, 177.0f, 40.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(500.f, 250.0f, 40.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirObjetoDinamico(350.0f, 250.0f, 12.5f, 8.f);
    Nivel::contadorEn++;

    int auxCont = 0;

    for (int i = 1; i < 4; i++) {
        if (sf::Joystick::isConnected(i - 1)) {
            auxCont++;
        }


    }

    switch (auxCont) {

        case 0:

            personajes = new Personaje*[1];

            personajes[0] = new Alien();


            personajes[0]->setSprite();

            niveles->anyadirPersonaje(personajes[0]);

            numJ = 1;

            break;

        case 1:

            personajes = new Personaje*[2];

            personajes[0] = new Alien();


            personajes[1] = new AlienRojo();


            personajes[0]->setSprite();

            personajes[1]->setSprite();


            niveles->anyadirPersonaje(personajes[0]);
            Nivel::contadorEn++;
            niveles->anyadirPersonaje(personajes[1]);

            numJ = 1;

            break;

        case 2:



            break;

        case 3:

            break;

    }






    gameLoop();

}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::set_camera() {

    camara1 = new View({349.f, 210.f},
    {
        450.f, 325.f
    });
    ventana->setView(*camara1);

}

void Partida::set_Nivel(Nivel *nivel) {

    niveles = nivel;

}

Nivel Partida::get_Nivel() {

    return *this->niveles;
}

void Partida::gameLoop() {



    while (ventana->isOpen()) {

        while (ventana->pollEvent(*evento)) {

            if (evento->type == Event::Closed) {
                ventana->close();
            }


            if (evento->type == Event::KeyPressed) {        

                this->personajes[0]->handleInput(evento, this->niveles);

                if (this->personajes[0]->getCuerpo()->getNumFoot() >= 1) {

                    this->personajes[0]->handleInput(evento, this->niveles);
                }

                if (evento->key.code == Keyboard::R) {
                    if (this->personajes[0]->getCuerpo()->getisOnWeapon()) {
                        this->personajes[0]->setArma(this->niveles->getPistola());
                    }
                }
                                            
            }

            if (evento->type == Event::KeyReleased && evento->key.code == Keyboard::Q) {

                this->personajes[0]->setFlag(true);

            }
        }

        if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A)) {

            this->personajes[0]->handleInput(evento, this->niveles);

        }
        
        if(evento->type == Event::JoystickConnected){
         
            
        }


        b2Vec2 vel = this->niveles->getPersonaje()->getBody()->GetLinearVelocity();


        if (vel.x <= 1 && vel.x >= -1) this->personajes[0]->setFila(0);
        if (!this->personajes[0]->getCuerpo()->getisOnstair()) this->niveles->getPersonaje()->getBody()->SetGravityScale(1.5f);

        this->Update();

    }

}

void Partida::dibujar() {

    bool aux = false;

    for (int i = 0; i <= Nivel::contadorEn; i++) {
        if (niveles->getEntidades()[i]->getCuerpo() != NULL) {
            //modificar para array de personajes
            if (personajes[0]->getArma() == NULL)
                niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, 0, 0);
            else {
                if (niveles->getEntidades()[i]->getCuerpo()->get_id_id() != identificador::pistola) {
                    niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, 0, 0);

                }
                aux = true;
            }
        }

    }

    for (int i = 0; i < personajes[0]->getBalas().size(); i++) {
        if (personajes[0]->getBalas().size() > 0 && personajes[0]->getBalas()[i] != NULL) {
            personajes[0]->getBalas()[i]->getCuerpo()->dibujar(*ventana, 0, 0);

        }
    }


    if (aux == true) {
        for (int i = 0; i <= Nivel::contadorEn; i++) {
            if (niveles->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::pistola)
                niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, personajes[0]->getCuerpo()->getBody()->GetPosition().x + 30, personajes[0]->getCuerpo()->getBody()->GetPosition().y + 50);
        }
    }


}

void Partida::Update() {




    //fin del testeo
    deltaTime = clock.restart().asSeconds();



    *tiempo1 = reloj1->getElapsedTime();

    if (tiempo2 + frameRate < tiempo1->asSeconds()) {

        tiempo2 = tiempo1->asSeconds();

        ventana->clear();

        this->niveles->actualizar_fisica();
        for (int i = 0; i < numJ; i++) {

            if (personajes[i] != NULL) {
            }

            personajes[i]->getAnimacion()->UpdateAnimacion(personajes[i]->getFila(), deltaTime, personajes[i]->getSprite(), personajes[i]->getface());

        }

        if (personajes[0]->getArma() != NULL) {
            this->niveles->getPistola()->UpdateArma(personajes[0]->getCuerpo()->getBody()->GetLinearVelocity(), personajes[0]->getface());

        }




        personajes[0]->borrarBala();





        dibujar();


        ventana->display();

    }

}