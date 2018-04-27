/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Personaje.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:12
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H


#include "SpawnerMonstruo.h"
#include "SFML/Graphics.hpp"
#include "Weapon.h"
#include "Animacion.h"
#include "Entidad.h"
#include "Box2D/Box2D.h"
#include "Bala.h"
#include "BalaPistola.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "BalaEscopeta.h"
#include "BalaM4.h"
#include "balaLC.h"

using namespace sf;

class EstadoPersonaje;
class Nivel;

class Personaje : public Entidad {
public:

    Personaje();
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    virtual void setSprite() = 0;
    Sprite* getSprite();
    Texture* getTextura();
    virtual Animacion * getAnimacion() = 0;
    void setFrame(Sprite &spr);
    virtual void handleInput(Event* tecla, Nivel* nivel);
    virtual void handleInput(Event * tecla, Nivel* nivel, int mando)=0;
    void setBody(b2World * mundo, float x, float y);
    void setArma(Entidad* weapon);
    void disparar();
    void dispararEscopeta();
    void dispararM4();
    void dispararLanzaCohetes();
    void tirarArma();

    b2Vec2 getspeed() {
        return speed;
    };

    void setSpeed(b2Vec2 vector) {
        speed = vector;
    }

    void setEstado(EstadoPersonaje* estado) {
        estado_ = estado;
    };

    EstadoPersonaje* getEstado() {
        return estado_;
    };
    //Sistema de vida y ataque

    //UpdateVida
    virtual void updateVidaActual(int);
    //GetVida
    virtual int getVida();
    virtual int getVidaActual();
    //Muerte (?)
    virtual void morir();
    //UpdatePuntuacion
    virtual void updatePuntuacion(int);
    //GetPuntuacion
    virtual int getPuntuacion();

    bool getface() {
        return faceRight;
    };

    void setface(bool f) {
        faceRight = f;
    };

    int getFila() {
        return row;
    };

    void setFila(int r) {
        row = r;
    };

    Entidad * getArma() {
        return arma;
    };
    void setFixture(b2PolygonShape * forma, float density, float restitution, float friction);

    std::vector<Bala*> getBalas(){
        
        return balas;
    }
    
    bool setFlag(bool aux){flagAux=aux;};
    
    
    void borrarBala();
    
    void updateArma();

private:



protected:


    EstadoPersonaje * estado_;

    int vida;
    int vidaActual;
    int velocidad;
    int puntuacion;
    int defensa;
    int row;
    //variables para las fisicas

    b2Vec2 speed;
    bool faceRight;
    Animacion * animacion;

    Entidad * arma;
    
    std::vector<Bala*> balas;    
    
    bool flagAux;
    float tiempoAux;
    float deltaTime;

    
    
    
};

#endif /* PERSONAJE_H */

