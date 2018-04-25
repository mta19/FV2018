/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marta
 *
 * Created on 14 de marzo de 2018, 14:51
 */
#include <iostream>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Estado.h"
#include "Nivel.h"
#include "Partida.h"
using namespace sf;

#include "Ventana.h"
#include "Evento.h"
#include "Sprite2D.h"

/*
 * 
 */
int main(int argc, char** argv) {

    Estado * partida=new Partida({1920,1080},"Empieza la partida");

    delete partida;
    
    Ventana window = Ventana(600,600,"Hola que tal");
    
    Sprite2D sprite = Sprite2D("suelo.jpg", 0, 0, 50,50);
    
    while(window.isOpen()){
        
        Evento* event = new Evento();
        
        while(window.pollEvent(event)){
        
            if(event->isClosed())
                window.close();
        }
        
        window.clear();
        sprite.draw(window);
        window.display();
    }
    
    return 0;
}

