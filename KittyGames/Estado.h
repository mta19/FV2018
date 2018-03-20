/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:26
 */

#include "SFML/Graphics.hpp"

using namespace sf;

#ifndef ESTADO_H
#define ESTADO_H

class Estado {
public:
    Estado();
    Estado(const Estado& orig);
    virtual ~Estado();
    virtual void set_camera()=0;
    virtual void gameLoop()=0;
    virtual void dibujar()=0;
protected:

    int fps;
    float frameRate;
    
    RenderWindow * ventana;
    View * camara1;

    Clock * reloj1;
    Time* tiempo1;
    
    float tiempo2;
};

#endif /* ESTADO_H */

