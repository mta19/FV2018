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

Partida::Partida(Vector2i resolucion, std::string titulo) {

    evento = new Event;
    fps = 60;
    frameRate = 1 / fps;

    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), titulo);
    ventana->setFramerateLimit(fps);

    set_camera();


    //por ahora pondre que una partida tiene solo un personaje y un nivel
    niveles = new Nivel();
    personajes = new Alien();
    personajes->setSprite();
    niveles->anyadirObjetoDinamico(400.0f, 250.0f, 5.f, 5.f);

    niveles->anyadirPlataforma(340.f, 300.0f, 100.f, 12.f);
    niveles->anyadirPersonaje(personajes->getSprite()->getPosition().x, personajes->getSprite()->getPosition().y, personajes->getSprite());

    niveles->getPersonaje()->setEntidad(this->personajes);

    gameLoop();

}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::set_camera() {

    //camara1=new View({50.f,50.f},{1376.f,768.f});
    //ventana->setView(*camara1);any

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

    Animacion * animacion = personajes->getAnimacion();
    while (ventana->isOpen()) {

        while (ventana->pollEvent(*evento)) {

            if (evento->type == Event::Closed) {
                ventana->close();
            }

            if (evento->type == Event::KeyPressed) {

                this->personajes->handleInput(evento, this->niveles);

                if (this->niveles->getColisiones()->getId() == 1) {


                    this->personajes->handleInput(evento, this->niveles);

                    this->niveles->getColisiones()->setId(0);

                }
            }

        }

        //nuevo testeando
        if (this->niveles->getColisiones()->getId() == 1) {
            if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A)) {
                
                 this->personajes->handleInput(evento, this->niveles);
                
            }
        }
        
        
        
        

        //fin del testeo
        deltaTime = clock.restart().asSeconds();

        *tiempo1 = reloj1->getElapsedTime();

        if (tiempo2 + frameRate < tiempo1->asSeconds()) {

            tiempo2 = tiempo1->asSeconds();

            ventana->clear();

            this->niveles->actualizar_fisica();

            animacion->Update(personajes->getFila(), deltaTime, personajes->getSprite(), personajes->getface());

            dibujar();

            ventana->display();
        }

    }

}

void Partida::dibujar() {


    //nivel->dibujar
    //Personajes->dibujar
    niveles->getCaja()->dibujar(*ventana);

    niveles->getSuelo()->dibujar(*ventana);

    niveles->getPersonaje()->dibujar(*ventana);

}