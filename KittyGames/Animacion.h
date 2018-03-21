/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 2:04
 */

#ifndef ANIMACION_H
#define ANIMACION_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Animacion {
public:
    Animacion(Texture *texture, Vector2u imageCount, float switchTime);
    Animacion(const Animacion& orig);
    virtual ~Animacion();
    void Update (int row, float deltaTime, Sprite * sprite);
private:

    Vector2u imageCount;
    Vector2u currentImage;
    
    float totalTime;
    float switchTime;
    
    
public:
    
    IntRect uvRect;
};

#endif /* ANIMACION_H */

