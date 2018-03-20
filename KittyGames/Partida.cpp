/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Partida.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 19:36
 */
#include <iostream>
#include "Partida.h"

Partida::Partida(Vector2i resolucion, std::string titulo) {
    
    fps=60;
    frameRate=1/fps;
    
    ventana= new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
    ventana->setFramerateLimit(fps);
    
    set_camera();
    
    std::cout<<"Por ahora funciona0"<<std::endl;
    
    //por ahora pondre que una partida tiene solo un personaje y un nivel
    niveles=new Nivel();
    
    niveles->iniciar_fisica();
    
    std::cout<<"Por ahora funciona1"<<std::endl;
    
    gameLoop();
    
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
}

void Partida::set_camera(){
    
    camara1=new View({50.f,50.f},{100.f,100.f});
    ventana->setView(*camara1);
    
}

void Partida::set_Nivel(Nivel *nivel){
    
    niveles=nivel;
    
}

Nivel Partida::get_Nivel(){
    
    return *this->niveles;
}

void Partida::gameLoop(){
    
    
      while(ventana->isOpen()){
        
        *tiempo1=reloj1->getElapsedTime();
        
        if(tiempo2 + frameRate < tiempo1->asSeconds()){
            std::cout<<"hola"<<std::endl;
            tiempo2=tiempo1->asSeconds();
            
            ventana->clear();
            
            this->niveles->actualizar_fisica();
            
            dibujar();
            std::cout<<"hola"<<std::endl;
            ventana->display();
        }
        
    }
    
}

void Partida::dibujar(){
    
    niveles->getCaja()->dibujar(*ventana);
    
    niveles->getSuelo()->dibujar(*ventana);
    
}