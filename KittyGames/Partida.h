/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:36
 */

#include "SFML/Graphics.hpp"
#include "Nivel.h"
#include "Estado.h"
#include "Personaje.h"
#include "Alien.h"
#include <iostream>
#include "Bala.h"
using namespace sf;

#ifndef PARTIDA_H
#define PARTIDA_H

#include "Collision.h"

class Partida : public Estado {
public:
    //Patron Singleton --Mirar PDF Sesion 6
    static Partida* Instance(Vector2i resolucion, std::string titulo);
    
    Partida(Vector2i resolucion, std::string titulo);
    Partida(const Partida& orig);
    virtual ~Partida();

    void definirTexto(int pos, String texto);
    void configurarTexto(int pos, float x, float y, String texto);
    void set_camera();
    void set_Nivel(Nivel* nivel);
    void gameLoop();
    void dibujar();
    Nivel get_Nivel();
    void Update();

    void dibujarTexto();
private:
    //Singleton --Mirar PDF Sesion 6
    static Partida* pinstance;

    Nivel * niveles;
    int numRondas;
    int tiempoRonda;
    int tiempoPrep;
    Collision procesadorColisiones;

    Event * evento;
    Event * evento2;
    
    Font fuente;
    Text textopantalla[20];
    Clock clock;
    Clock clock2;
    bool eliminadas;
    float deltaTime;
  
    std::vector<Joystick*> mandos;
    
    std::vector<Personaje*> personajes;
    int numJ;
};



#endif /* PARTIDA_H */

