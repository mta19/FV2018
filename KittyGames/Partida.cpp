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

    evento = new Event;
    fps = 60;
    frameRate = 1 / fps;

    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), titulo);
    ventana->setFramerateLimit(fps);

    set_camera();

    niveles = new Nivel();
    personajes = new Personaje*[2];
    personajes[0] = new Alien();
    personajes[1] = new AlienRojo();

    personajes[0]->setSprite();
    personajes[1]->setSprite();

    niveles->anyadirEscalera(400.f, 200.f, 12.f, 115.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(340.f, 300.0f, 80.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(347.f, 140.0f, 40.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(200.f, 250.0f, 40.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirPlataforma(500.f, 250.0f, 40.f, 8.f);
    Nivel::contadorEn++;
    niveles->anyadirObjetoDinamico(350.0f, 250.0f, 12.5f, 8.f);
    Nivel::contadorEn++;

    niveles->anyadirPersonaje(personajes[0]->getSprite()->getPosition().x, personajes[0]->getSprite()->getPosition().y, personajes[0]->getSprite());


    Nivel::contadorEn++;
    niveles->anyadirPersonaje(personajes[1]->getSprite()->getPosition().x, personajes[1]->getSprite()->getPosition().y, personajes[1]->getSprite());

    niveles->getPersonaje()->setEntidad(this->personajes[0]);

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

    Clock clock;
    float deltaTime = 0.0f;

    Animacion * animacion = personajes[0]->getAnimacion();
    while (ventana->isOpen()) {

        while (ventana->pollEvent(*evento)) {

            if (evento->type == Event::Closed) {
                ventana->close();
            }

            if (evento->type == Event::KeyPressed) {




                this->personajes[0]->handleInput(evento, this->niveles);


                if (this->niveles->getColisiones()->getId() == 1) {


                    this->personajes[0]->handleInput(evento, this->niveles);


                    this->niveles->getColisiones()->setId(0);

                }
            }

        }
        
        //nuevo testeando
        if (this->niveles->getColisiones()->getId() == 1) {
            if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A)) {

                this->personajes[0]->handleInput(evento, this->niveles);

            }
        }

        b2Vec2 vel = this->niveles->getPersonaje()->getBody()->GetLinearVelocity();

  
        if (vel.x <= 1 && vel.x >= -1) this->personajes[0]->setFila(0);



        //fin del testeo
        deltaTime = clock.restart().asSeconds();

        *tiempo1 = reloj1->getElapsedTime();

        if (tiempo2 + frameRate < tiempo1->asSeconds()) {

            tiempo2 = tiempo1->asSeconds();

            ventana->clear();

            this->niveles->actualizar_fisica();

            animacion->Update(personajes[0]->getFila(), deltaTime, personajes[0]->getSprite(), personajes[0]->getface());

            dibujar();


            ventana->display();

        }

    }

}

void Partida::dibujar() {


    //nivel->dibujar
    //Personajes->dibujar
    /*niveles->getCaja()->dibujar(*ventana);

    niveles->getSuelo()[0]->dibujar(*ventana);

    niveles->getPersonaje()->dibujar(*ventana);
     */

    for (int i = 0; i <= Nivel::contadorEn; i++) {

        if (niveles->getEnsambladores()[i] != NULL)
            niveles->getEnsambladores()[i]->dibujar(*ventana);

    }

}