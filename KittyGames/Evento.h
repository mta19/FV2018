/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Evento.h
 * Author: alejandro
 *
 * Created on 24 de abril de 2018, 17:30
 */

#ifndef EVENTO_H
#define EVENTO_H

#include "SFML/Graphics.hpp"

class Evento {
public:
    Evento();
    Evento(const Evento& orig);
    virtual ~Evento();
    
    sf::Event* getEvent();
    
    bool isClosed();
    bool isKeyPressed();
    std::string getKeyPressed();
    
private:
    
    sf::Event* event;

};

#endif /* EVENTO_H */

