/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ventana.h
 * Author: alejandro
 *
 * Created on 24 de abril de 2018, 15:43
 */


#ifndef VENTANA_H
#define VENTANA_H

#include "SFML/Graphics.hpp"
#include "Evento.h"

class Ventana {
public:
    Ventana(int width, int height, std::string title);
    Ventana(const Ventana& orig);
    virtual ~Ventana();
    
    void clear();
    void close();
    void display();
    
    void draw(sf::Sprite* dibujable);
    
    bool isOpen();
    bool pollEvent(Evento* event);
    
    sf::RenderWindow* getVentana();
    
    
    
private:
    sf::RenderWindow* window;

};

#endif /* VENTANA_H */

