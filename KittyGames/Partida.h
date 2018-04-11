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
#include "motor2D.h"
#include "Personaje.h"
#include "Alien.h"
using namespace sf;

#ifndef PARTIDA_H
#define PARTIDA_H

#include "Collision.h"

class Partida : public Estado {
public:
    Partida(Vector2i resolucion, std::string titulo);
    Partida(const Partida& orig);
    virtual ~Partida();

    void set_camera();
    void set_Nivel(Nivel* nivel);
    void gameLoop();
    void dibujar();
    Nivel get_Nivel();


private:


    Personaje **personajes;
    Nivel * niveles;
    int numRondas;
    int tiempoRonda;
  
 Collision procesadorColisiones;

    Event * evento;
};



#endif /* PARTIDA_H */

