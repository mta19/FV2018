/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ventana.cpp
 * Author: alejandro
 * 
 * Created on 24 de abril de 2018, 15:43
 */

#include "Ventana.h"

Ventana::Ventana(int width, int height, std::string title){
    
    window = new sf::RenderWindow(sf::VideoMode(width,height),title);
}

Ventana::Ventana(const Ventana& orig) {
}

Ventana::~Ventana() {
    
    delete window;
}

void Ventana::clear(){
    
    window->clear();
}

void Ventana::close(){
    window->close();
}

void Ventana::display(){
    window->display();
}

bool Ventana::isOpen(){
    return window->isOpen();
}

bool Ventana::pollEvent(Evento* event){
    return window->pollEvent(*event->getEvent());
}

sf::RenderWindow* Ventana::getVentana(){
    return window;
}

void Ventana::draw(sf::Sprite* dibujable){
    window->draw(*dibujable);
}



