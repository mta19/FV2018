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
#include <stdio.h>
#include "Partida.h"
#include "Personaje.h"
#include "Alien.h"
#include "Animacion.h"
#include "EstadoStanding.h"
#include "AlienRojo.h"
#include "AlienRojo.h"


Partida* Partida::pinstance = 0; //Inicializamos el puntero

//Metodo que controla la cantidad de instancias (Patron Singleton)

Partida* Partida::Instance(Vector2i resolucion, std::string titulo) {
    if (pinstance == 0) {
        pinstance = new Partida(resolucion, titulo);
    }

    return pinstance; //Retomamos la direccion de la instancia
}

Partida::Partida(Vector2i resolucion, std::string titulo) {

    numJ = 0;
    deltaTime = 0.0f;

    evento = new Event;
    evento = new Event;
    fps = 60;
    frameRate = 1 / fps;

    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), titulo);
    ventana->setFramerateLimit(fps);

    //set_camera();

    niveles = new Nivel();
    personajes.push_back(new Alien());
    personajes[0]->setSprite();
    this->niveles->anyadirPersonaje(personajes[0]);


    //Cargamos la fuente
    if (fuente.loadFromFile("fonts/PrStart.ttf") == false) {

        std::cerr << "Error cargando la la fuente fonts/PrStart.ttf";
        exit(0);

    }



    for (int i = 1; i < 4; i++) {
        if (sf::Joystick::isConnected(i - 1)) {
            std::cout << "conectado" << std::endl;
            personajes.push_back(new AlienRojo());
            personajes[i]->setSprite();
            this->niveles->anyadirPersonaje(personajes[i]);

        }
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
        480.f, 360.f
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
                    //el getIsOnWeaponPistola, getisOnEscopeta...
                    if (this->personajes[0]->getCuerpo()->getisOnWeapon()) {
                        if (this->personajes[0]->getArma() == NULL)
                            this->personajes[0]->setArma(this->niveles->getPistola());
                    }

                    if (this->personajes[0]->getCuerpo()->getisOnWeaponSG()) {
                        if (this->personajes[0]->getArma() == NULL)
                            this->personajes[0]->setArma(this->niveles->getEscopeta());
                    }

                    if (this->personajes[0]->getCuerpo()->getisOnWeaponM4()) {
                        if (this->personajes[0]->getArma() == NULL)
                            this->personajes[0]->setArma(this->niveles->getM4());
                    }

                    if (this->personajes[0]->getCuerpo()->getisOnWeaponRL()) {

                        if (this->personajes[0]->getArma() == NULL)
                            this->personajes[0]->setArma(this->niveles->getLanzaCohetes());
                    }
                }

            }


        }

        if (evento->type == Event::KeyReleased && evento->key.code == Keyboard::Q) {

            this->personajes[0]->setFlag(true);

        }

        if (evento->type == Event::JoystickButtonPressed) {

            for (int i = 0; i < personajes.size(); i++) {

                if (Joystick::isConnected(i)) {

                    this->personajes[evento->joystickButton.joystickId + 1]->handleInput(evento, this->niveles, evento->joystickButton.joystickId);

                    if (this->personajes[evento->joystickButton.joystickId + 1]->getCuerpo()->getNumFoot() >= 1) {

                        this->personajes[evento->joystickButton.joystickId + 1]->handleInput(evento, this->niveles, evento->joystickButton.joystickId);

                    }



                    if (evento->joystickButton.button == 3) {
                        std::cout << "entro aqui weys" << std::endl;
                        //hay que haber varios "getIsOn Weapon", uno para pistola, uno para la escopeta, uno para..)
                        if (this->personajes[evento->joystickButton.joystickId + 1]->getCuerpo()->getisOnWeapon()) {

                            if (this->personajes[evento->joystickButton.joystickId + 1]->getArma() == NULL)
                                this->personajes[evento->joystickButton.joystickId + 1]->setArma(this->niveles->getPistola());

                        }

                        if (this->personajes[i + 1]->getCuerpo()->getisOnWeaponSG()) {

                            if (this->personajes[evento->joystickButton.joystickId + 1]->getArma() == NULL)
                                this->personajes[evento->joystickButton.joystickId + 1]->setArma(this->niveles->getEscopeta());
                        }

                        if (this->personajes[i + 1]->getCuerpo()->getisOnWeaponM4()) {

                            if (this->personajes[evento->joystickButton.joystickId + 1]->getArma() == NULL)
                                this->personajes[evento->joystickButton.joystickId + 1]->setArma(this->niveles->getM4());

                        }

                        if (this->personajes[i + 1]->getCuerpo()->getisOnWeaponRL()) {
                            if (this->personajes[evento->joystickButton.joystickId + 1]->getArma() == NULL)
                                this->personajes[evento->joystickButton.joystickId + 1]->setArma(this->niveles->getLanzaCohetes());

                        }
                    }



                }

            }



        }

        for (int z = 0; z < personajes.size(); z++) {


            if (sf::Joystick::isConnected(z)) {

                if (evento->type == Event::JoystickButtonReleased && evento->joystickButton.button == 2) {

                    this->personajes[evento->joystickButton.joystickId + 1]->setFlag(true);

                }

            }

        }

        for (int i = 0; i < personajes.size(); i++) {

            if (sf::Joystick::isConnected(i)) {

                if (Joystick::isButtonPressed(i, 5) || Joystick::isButtonPressed(i, 4)) {

                    this->personajes[i + 1]->handleInput(evento, this->niveles, i);

                }

            }
        }

        if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::A)) {

            this->personajes[0]->handleInput(evento, this->niveles);

        }




        //b2Vec2 vel = this->niveles->getPersonaje()->getBody()->GetLinearVelocity();

        for (int i = 0; i < personajes.size(); i++) {
            b2Vec2 vel = personajes[i]->getCuerpo()->getBody()->GetLinearVelocity();

            if (vel.x <= 1 && vel.x >= -1) this->personajes[i]->setFila(0);
            if (!this->personajes[i]->getCuerpo()->getisOnstair()) personajes[i]->getCuerpo()->getBody()->SetGravityScale(1.5f);
        }


        this->Update();

    }
}

void Partida::definirTexto(int pos, String texto) {


    if (pos > 0 && pos <= ((sizeof (textopantalla) / sizeof (Text)) - 1)) {
        textopantalla[pos].setFont(this->fuente);
        textopantalla[pos].setScale(0.25, 0.25);
        textopantalla[pos].setPosition(350, 75);
        textopantalla[pos].setString(texto);
    }
    if (pos == 0) {
        textopantalla[pos].setFont(this->fuente);
        textopantalla[pos].setScale(0.5, 0.5);
        textopantalla[pos].setPosition(350, 75);
        textopantalla[0].setString(std::to_string((int) trunc(reloj1->getElapsedTime().asSeconds())));
    }
}

void Partida::configurarTexto(int pos, float x, float y, String texto) {

    if (pos > 0 && pos <= ((sizeof (textopantalla) / sizeof (Text)) - 1)) {
        textopantalla[pos].setPosition(x, y);
        textopantalla[pos].setString(texto);
    }



}

void Partida::dibujar() {

    bool aux = false;

    niveles->getMapa()->dibujarMapa(ventana);
    //modificar para array de personajes
    for (int z = 0; z < personajes.size(); z++) {
        if (personajes[z]->getArma() == NULL) aux = false;
        else aux = true;

    }

    for (int i = 0; i < niveles->getEntidades().size(); i++) {
        if (niveles->getEntidades()[i] != NULL) {
            if (niveles->getEntidades()[i]->getCogida() == false) {
                niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, 0, 0);
            }
        }


        for (int z = 0; z < personajes.size(); z++) {
            if (personajes[z]->getArma() != NULL)
                personajes[z]->getArma()->getCuerpo()->dibujar(*ventana, personajes[z]->getCuerpo()->getBody()->GetPosition().x + 1, personajes[z]->getCuerpo()->getBody()->GetPosition().y + 5);
        }




        /* if (aux == false)
             niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, 0, 0);
         else {
             if (niveles->getEntidades()[i]->getCuerpo()->get_id_id() != identificador::pistola) {
                 niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, 0, 0);


             }*/

    }


    for (int p = 0; p < personajes.size(); p++) {
        for (int i = 0; i < personajes[p]->getBalas().size(); i++) {
            if (personajes[p]->getBalas().size() > 0 && personajes[p]->getBalas()[i] != NULL) {
                personajes[p]->getBalas()[i]->getCuerpo()->dibujar(*ventana, 0, 0);

            }
        }

    }




    /* if (aux == true) {
         std::cout << "entro aqui?" << std::endl;
         for (int i = 0; i < this->niveles->getEntidades().size(); i++) {
             if (niveles->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::pistola) {
                 for (int z = 0; z < personajes.size(); z++) {
                     if (personajes[z]->getArma() != NULL)
                         niveles->getEntidades()[i]->getCuerpo()->dibujar(*ventana, personajes[z]->getCuerpo()->getBody()->GetPosition().x + 30, personajes[z]->getCuerpo()->getBody()->GetPosition().y + 50);
                 }

             }
         }
     }
     */


}

void Partida::Update() {

    //fin del testeo
    deltaTime = clock.restart().asSeconds();
    *tiempo1 = reloj1->getElapsedTime();

    if (tiempo2 + frameRate < tiempo1->asSeconds()) {

        tiempo2 = tiempo1->asSeconds();

        ventana->clear();

        this->niveles->actualizar_fisica();
        for (int i = 0; i < personajes.size(); i++) {

            if (personajes[i] != NULL) {
            }

            personajes[i]->getAnimacion()->UpdateAnimacion(personajes[i]->getFila(), deltaTime, personajes[i]->getSprite(), personajes[i]->getface());



            if (personajes[i]->getArma() != NULL) {

                personajes[i]->updateArma();
            }

        }



        for (int i = 0; i < personajes.size(); i++) {

            personajes[i]->borrarBala();


        }


        personajes[0]->borrarBala();

        //Contador de tiempo original
        definirTexto(0, "NULL");
        //textopantalla[0].setString(std::to_string ( (sizeof(textopantalla)/sizeof(Text)) -1) );
        ventana->draw(textopantalla[0]);



        //Resto de textos en pantalla de los jugadores

        for (int i = 1; i <= 4; i++) {
            int aux = 115;

            definirTexto(i, "Hola");

            if (i <= personajes.size()) {
                configurarTexto(i, 150 + aux * (i - 1), 325, personajes[i - 1]->getNombre());
            }
            else {
                configurarTexto(i, 150 + aux * (i - 1), 325, "PLAYER " + std::to_string(i));
            }

            ventana->draw(textopantalla[i]);

        }


        dibujar();


        ventana->display();

    }

}