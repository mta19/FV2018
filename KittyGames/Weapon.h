/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Weapon.h
 * Author: pedro
 *
 * Created on 21 de marzo de 2018, 15:46
 */

#ifndef WEAPON_H
#define WEAPON_H

#include "Bala.h"
#include "Entidad.h"
#include "SFML/Graphics.hpp"
class Weapon : public Entidad{
public:
    Weapon();
    Weapon(const Weapon& orig);
    virtual ~Weapon();
     void setBody(b2World * mundo, float x, float y);
    virtual void setFixture(b2PolygonShape * forma, float density, float restitution, float friction)=0;
    void Update(b2Vec2  vector);
    sf::Clock * getReloj(){return reloj;};
    sf::Time * getTiempo(){return tiempo;};
    float getCadencia(){return cadencia;};
    bool getCogida(){return cogida;};
    bool setCogida(bool aux){cogida=aux;};
 
protected:

    Bala * bala;
    
    int cargador;
    
    int rango;
    
    sf::Clock * reloj;
    
    sf::Time * tiempo;
    
    float cadencia;
    
    bool cogida;
    
    
};

#endif /* WEAPON_H */

