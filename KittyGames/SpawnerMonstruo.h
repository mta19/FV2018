/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SpawnerMonstruo.h
 * Author: pedro
 *
 * Created on 19 de marzo de 2018, 19:21
 */

#ifndef SPAWNERMONSTRUO_H
#define SPAWNERMONSTRUO_H

class SpawnerMonstruo {
public:
    SpawnerMonstruo();
    SpawnerMonstruo(const SpawnerMonstruo& orig);
    virtual ~SpawnerMonstruo();
private:
    
    int posicionX;
    int posicionY;
    
    int tiempoRespawn;
    
};

#endif /* SPAWNERMONSTRUO_H */

