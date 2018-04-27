/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ensamblador.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 20:01
 */

#ifndef ENSAMBLADOR_H
#define ENSAMBLADOR_H

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

enum identificador {
    jugador, enemigo, caja, plataforma, escalera, pistola, balaPistola, escopeta, balaEscopeta, lanzaCohetes, balaCohete, m4, balaM4
};

using namespace sf;

class Ensamblador {
public:
    Ensamblador(b2Body * cuerpo, Sprite * sprite, float width, float height);
    Ensamblador(const Ensamblador& orig);
    virtual ~Ensamblador();

    float rad2deg(float radianes);
    void dibujar(RenderWindow& r, float x, float y);

    b2Body* getBody();

    void set_id_id(identificador id) {
        id_id = id;
    };

    identificador get_id_id() {
        return id_id;
    };

    void isOnStair(bool aux) {
        onStair = aux;
    };

    bool getisOnstair() {
        return onStair;
    };

    //pistola

    void isOnWeapon(bool aux) {
        onWeapon = aux;
    };

    bool getisOnWeapon() {
        return onWeapon;
    };


    //M4

    void isOnWeaponM4(bool aux) {
        onWeaponM4 = aux;
    };

    bool getisOnWeaponM4() {
        return onWeaponM4;
    };


    //Escopeta

    void isOnWeaponSG(bool aux) {
        onWeaponSG = aux;
    };

    bool getisOnWeaponSG() {
        return onWeaponSG;
    };


    //LanzaCohetes

    void isOnWeaponRL(bool aux) {
        onWeaponRL = aux;
    };

    bool getisOnWeaponRL() {
        return onWeaponRL;
    };

    int getNumFoot() {
        return numFootContacts;
    };

    void subirNumFoot() {
        numFootContacts++;
    };

    void bajarNumFoot() {
        numFootContacts--;
    };


private:


    Sprite * spr_actor;
    b2Body * bdy_actor;

    b2Vec2 posicion;

    identificador id_id;


    int numFootContacts;

    bool onStair = false;
    bool onWeapon = false;
    bool onWeaponSG = false;
    bool onWeaponRL = false;
    bool onWeaponM4 = false;


};

#endif /* ENSAMBLADOR_H */

