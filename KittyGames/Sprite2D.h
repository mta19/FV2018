/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite2D.h
 * Author: alejandro
 *
 * Created on 24 de abril de 2018, 18:38
 */

#ifndef SPRITE2D_H
#define SPRITE2D_H

#include "SFML/Graphics.hpp"
#include "Ventana.h"

class Sprite2D {
public:
    Sprite2D(std::string textRouteint,int rectLeft, int rectTop, int rectWidth, int rectHeight);
    virtual ~Sprite2D();
    
    void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);
    void draw(Ventana& window);
private:
    
    sf::Sprite* sprite;
    sf::Texture textura;
};

#endif /* SPRITE2D_H */

