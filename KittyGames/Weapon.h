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

#include "Bala.h";
class Weapon {
public:
    Weapon();
    Weapon(const Weapon& orig);
    virtual ~Weapon();
private:

    Bala bala;
    
    int cargador;
    
    int rango;
    
    
    
};

#endif /* WEAPON_H */

