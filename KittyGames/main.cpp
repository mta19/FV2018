/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marta
 *
 * Created on 14 de marzo de 2018, 14:51
 */
#include <iostream>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Estado.h"
#include "Nivel.h"
#include "Partida.h"
using namespace sf;



/*
 * 
 */
int main(int argc, char** argv) {

    Estado * partida=new Partida({720,480},"Empieza la partida");

    delete partida;
    
    
    
    return 0;
}

