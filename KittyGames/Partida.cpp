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
Partida* Partida::Instance(Vector2i resolucion, std::string titulo){
    if(pinstance==0){
        pinstance = new Partida(resolucion, titulo);
    }
    
    return pinstance; //Retomamos la direccion de la instancia
}

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
    personajes.push_back(new Alien());
    personajes[0]->setSprite();
    this->niveles->anyadirPersonaje(personajes[0]);
    
    //Cargamos la fuente
    if(fuente.loadFromFile("fonts/PrStart.ttf")==false){
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

        if (evento->type == Event::JoystickConnected) {
            personajes.push_back(new AlienRojo());
            personajes[1]->setSprite();
            this->niveles->anyadirPersonaje(personajes[1]);

        }
        
        
        
        
        
        //cosas aparte

       
        //b2Vec2 vel = this->niveles->getPersonaje()->getBody()->GetLinearVelocity();

        for (int i = 0; i < personajes.size(); i++) {
            b2Vec2 vel= personajes[i]->getCuerpo()->getBody()->GetLinearVelocity();
            
             if (vel.x <= 1 && vel.x >= -1) this->personajes[i]->setFila(0);
        if (!this->personajes[i]->getCuerpo()->getisOnstair()) personajes[i]->getCuerpo()->getBody()->SetGravityScale(1.5f);
        }

        
        this->Update();

    }

}

void Partida::definirTexto(int pos, String texto){
    
    
    
    if(pos>0 && pos<= sizeof(textopantalla)-1){
    textopantalla[pos].setFont(this->fuente);
    textopantalla[pos].setScale(0.5, 0.5);
    textopantalla[pos].setPosition(350, 75);
    textopantalla[pos].setString(texto);
    }
    else if(pos==0){
    textopantalla[pos].setFont(this->fuente);
    textopantalla[pos].setScale(0.5, 0.5);
    textopantalla[pos].setPosition(350, 75);
         textopantalla[0].setString(  std::to_string((int)trunc(reloj1->getElapsedTime().asSeconds())));
    }
}

void Partida::configurarTexto(int pos, float x, float y, String texto){
    
     if(pos>0 && pos<= sizeof(textopantalla)-1){
         textopantalla[pos].setPosition(x, y);
         textopantalla[pos].setString(texto);
     }
}

void Partida::dibujar() {

    bool aux = false;

    for (int i = 0; i < niveles->getEntidades().size(); i++) {
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
        for (int i = 0; i < personajes.size(); i++) {

            if (personajes[i] != NULL) {
            }

            personajes[i]->getAnimacion()->UpdateAnimacion(personajes[i]->getFila(), deltaTime, personajes[i]->getSprite(), personajes[i]->getface());

        }

        if (personajes[0]->getArma() != NULL) {
            this->niveles->getPistola()->UpdateArma(personajes[0]->getCuerpo()->getBody()->GetLinearVelocity(), personajes[0]->getface());

        }

        personajes[0]->borrarBala();

       //Contador de tiempo original
        definirTexto(0, "NULL");
        ventana->draw(textopantalla[0]);
        
        
        //Resto de textos en pantalla
        definirTexto(1, "Hola");
        configurarTexto(1, 50, 50 , "GUAY");
        ventana->draw(textopantalla[1]);
        
        
        dibujar();


        ventana->display();

    }

}