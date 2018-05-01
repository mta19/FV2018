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

    tiempoRonda = 60;
    tiempoPrep = 5;
    eliminadas=false;

    ventana = new RenderWindow(VideoMode(resolucion.x, resolucion.y), titulo);
    ventana->setFramerateLimit(fps);

    set_camera();

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

    camara1 = new View({225.f, 192.f},
    {
        448.f, 384.f
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

                if (evento->key.code == Keyboard::R && !this->niveles->getEmpezado()) {
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



                    if (evento->joystickButton.button == 3 && !this->niveles->getEmpezado()) {
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
        textopantalla[pos].setPosition(120, 25);
        if (this->niveles->getEmpezado() == false) {
            if (clock2.getElapsedTime().asSeconds() >= 1) {
                textopantalla[0].setString(" Preparate: " + std::to_string((int) trunc(--tiempoPrep)));
                if(tiempoPrep==0) this->niveles->setEmpezado(true);
                if(tiempoPrep<=3) textopantalla[0].setColor(Color::Red);
                clock2.restart();
            }
        } else {
            if (clock2.getElapsedTime().asSeconds() >= 1) {
                if(tiempoRonda>3) textopantalla[0].setColor(Color::White);
                textopantalla[0].setString("Fin Ronda: "+std::to_string((int) trunc(--tiempoRonda)));
                if(tiempoRonda<=3) textopantalla[0].setColor(Color::Red);
                clock2.restart();
            }
        }
    }

    if (pos == 13) {

        textopantalla[pos].setFont(this->fuente);
        textopantalla[pos].setScale(2.f, 2.f);
        textopantalla[pos].setPosition(350, 75);
        textopantalla[pos].setString(texto);
    }


}

void Partida::configurarTexto(int pos, float x, float y, String texto) {

    if (pos > 0 && pos <= ((sizeof (textopantalla) / sizeof (Text)) - 1)) {
        textopantalla[pos].setPosition(x, y);
        textopantalla[pos].setString(texto);
        textopantalla[pos].setColor(Color::Green);
   
        

    }

    if (pos == 13) {

        textopantalla[pos].setPosition(x, y);
        textopantalla[pos].setString(texto);
        textopantalla[pos].setColor(Color::Red);

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

    }


    for (int p = 0; p < personajes.size(); p++) {
        for (int i = 0; i < personajes[p]->getBalas().size(); i++) {
            if (personajes[p]->getBalas().size() > 0 && personajes[p]->getBalas()[i] != NULL) {
                personajes[p]->getBalas()[i]->getCuerpo()->dibujar(*ventana, 0, 0);

            }
        }

    }

}

void Partida::Update() {

    int encendido = 0;
    //fin del testeo
    deltaTime = clock.restart().asSeconds();
    *tiempo1 = reloj1->getElapsedTime();

    if (tiempo2 + frameRate < tiempo1->asSeconds()) {

        tiempo2 = tiempo1->asSeconds();

        ventana->clear();

        this->niveles->actualizar_fisica();
        for (int i = 0; i < personajes.size(); i++) {

            if (personajes[i] != NULL && personajes[i]->getCuerpo()->getBody()->IsActive()) {
                encendido++;
            }

            personajes[i]->getAnimacion()->UpdateAnimacion(personajes[i]->getFila(), deltaTime, personajes[i]->getSprite(), personajes[i]->getface());



            if (personajes[i]->getArma() != NULL) {

                personajes[i]->updateArma();
            }


            personajes[i]->borrarBala();

            if (personajes[i]->getVida() <= 0) {

                this->personajes[i]->getCuerpo()->getBody()->SetActive(false);

            }
            if (Keyboard::isKeyPressed(Keyboard::P)) {

                this->personajes[i]->setVida(100);

                this->personajes[i]->getCuerpo()->getBody()->SetActive(true);

            }

        }



        dibujar();



        if (encendido == 1 || tiempoRonda == 0) {

            //PONER WINNER Y EL NOMBRE DE JUGADOR, EN VEZ DE CERRARSE LA VENTANA.

            if (encendido == 1) {



                for (int i = 0; i < personajes.size(); i++) {

                    if (personajes[i]->getCuerpo()->getBody()->IsActive()) {

                        definirTexto(13, "Hola");

                        configurarTexto(13, 50, 100, "WINNER");

                        configurarTexto(i + 1, 105, 200, personajes[i]->getNombre());
                        textopantalla[i + 1].setScale(0.8f, 0.8f);
                        textopantalla[i + 1].setColor(Color::Blue);

                        ventana->draw(textopantalla[13]);
                        ventana->draw(textopantalla[i + 1]);


                    }

                }
            }
                
                if(tiempoRonda==0){
                    
                    std::cout<<"ENTRO AQUI O QUE"<<std::endl;
                
                    Personaje * ganador=personajes[0];
                    
                     for (int i = 0; i < personajes.size()-1; i++) {
                     
                     
                         if(personajes[i]->getVida()<personajes[i+1]->getVida()){
                         
                             ganador=personajes[i+1];
                             
                         }
                     
                     
                     }
                    
                       definirTexto(13, "Hola");
                       definirTexto(14, "Hola");
                        configurarTexto(13, 50, 100, "WINNER");

                        configurarTexto(14, 105, 200, ganador->getNombre());
                        textopantalla[14].setScale(0.8f, 0.8f);
                        textopantalla[14].setColor(Color::Blue);

                        ventana->draw(textopantalla[13]);
                        ventana->draw(textopantalla[14]);
                    
                    
                
                
                }



            


        } else dibujarTexto();

        ventana->display();

    }

}

void Partida::dibujarTexto() {

    definirTexto(0, "NULL");
    //textopantalla[0].setString(std::to_string ( (sizeof(textopantalla)/sizeof(Text)) -1) );
    ventana->draw(textopantalla[0]);


    for (int i = 1; i <= 4; i++) {
        int aux = 115;

        definirTexto(i, "Hola");

        if (i <= personajes.size()) {
            configurarTexto(i, 20 + aux * (i - 1), 330, personajes[i - 1]->getNombre());
        } else {
            configurarTexto(i, 20 + aux * (i - 1), 330, "PLAYER " + std::to_string(i));
        }
        ventana->draw(textopantalla[i]);
    }


    for (int i = 5; i <= 8; i++) {
        int aux = 115;

        definirTexto(i, "Hola");

        std::string vidaString;
        std::ostringstream convert;


        if (i - 4 <= personajes.size()) {
            convert << personajes[i - 5]->getVida();
            vidaString = convert.str();
            configurarTexto(i, 20 + aux * (i - 5), 350, vidaString);
        } else {
            configurarTexto(i, 20 + aux * (i - 5), 350, "0 ");
        }
        ventana->draw(textopantalla[i]);
    }
}