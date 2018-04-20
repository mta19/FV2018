/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entidad.cpp
 * Author: pedro
 * 
 * Created on 25 de marzo de 2018, 13:17
 */

#include "Entidad.h"

Entidad::Entidad() {

}

Entidad::Entidad(const Entidad& orig) {
}

Entidad::~Entidad() {
}

void Entidad::setPosition(float  x, float  y) {

    this->spr->setPosition(x, y);

}


