/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:54
 */

#ifndef NIVEL_H
#define NIVEL_H

#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Ensamblador.h"
#include "Collision.h"
#include "Caja.h"
#include "Entidad.h"
#include "Personaje.h"
#include "Pistola.h"
#include "Escopeta.h"

using namespace sf;

class Nivel {
public:
    Nivel();
    Nivel(const Nivel& orig);
    virtual ~Nivel();

    void actualizar_fisica();
    void anyadirPlataforma(float x, float y, float weight, float height);
    void anyadirObjetoDinamico(float x, float y, float weight, float height);
    void anyadirEscalera(float x, float y, float weight, float height);
    void anyadirArma(float x, float y, float weight, float height);
    void anyadirEscopeta(float x, float y, float weight, float height);
    void anyadirPersonaje(Personaje * personaje);

    std::vector<Entidad*>& getEntidades() {
        return entidades;
    };

    /*Ensamblador* getPersonaje() {  //conseguimos el cuerpo

        for (int i = 0; i < 10; i++) {

            if (this->getEntidades()[i]!= NULL && this->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::jugador)

                return this->getEntidades()[i]->getCuerpo();
        }
        return NULL;
    };*/

    std::vector<Entidad*>& getPistola() { //conseguimos la entidad

        for (int i = 0; i < entidades.size(); i++) {

            if (this->getEntidades()[i] != NULL && this->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::pistola)
                armas.push_back(this->getEntidades()[i]);

        }

        return armas;
    }

    std::vector<Entidad*>& getEscopeta() { //conseguimos la entidad

        for (int i = 0; i < entidades.size(); i++) {

            if (this->getEntidades()[i] != NULL && this->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::escopeta)
                armas.push_back(this->getEntidades()[i]);

        }

        return armas;
    }

    std::vector<Entidad*>& getLanzaCohetes() { //conseguimos la entidad

        for (int i = 0; i < entidades.size(); i++) {

            if (this->getEntidades()[i] != NULL && this->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::lanzaCohetes)
                armas.push_back(this->getEntidades()[i]);

        }

        return armas;
    }

    std::vector<Entidad*>& getM4() { //conseguimos la entidad

        for (int i = 0; i < entidades.size(); i++) {

            if (this->getEntidades()[i] != NULL && this->getEntidades()[i]->getCuerpo()->get_id_id() == identificador::M4)
                armas.push_back(this->getEntidades()[i]);

        }

        return armas;
    }

    Collision* getColisiones() {

        return procesadorColisiones;
    }

    b2World* getMundo() {

        return mundo;
    }



    static int contadorEn;

private:

    std::vector<Entidad*> entidades;
    std::vector<Entidad*> armas;
    int marcadores;

    Texture * txt_;
    Sprite **spr_;


    //fisicas de los distintos objetos del mapa

    b2World * mundo;

    b2Body ** bdy;
    b2BodyDef bdydef_[10];
    b2Fixture * fix_[10];
    b2FixtureDef fixdef_[10];

    b2PolygonShape shp_[10];

    Collision * procesadorColisiones;

};


#endif /* NIVEL_H */

