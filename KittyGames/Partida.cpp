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
#include "Personaje.h"
#include "Alien.h"
#include "Animacion.h"

Partida::Partida(Vector2i resolucion, std::string titulo) {
    
    fps=60;
    frameRate=1/fps;
    
    ventana= new RenderWindow(VideoMode(resolucion.x,resolucion.y),titulo);
    ventana->setFramerateLimit(fps);
    
    set_camera();
    
    std::cout<<"Por ahora funciona0"<<std::endl;
    
    //por ahora pondre que una partida tiene solo un personaje y un nivel
    niveles=new Nivel();
    personajes= new Alien();
    personajes->setSprite();
    niveles->anyadirObjetoDinamico(50.0f,50.0f);
    niveles->anyadirPlataforma(50.0f,100.0f);
    
    
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
    
    Clock clock;
    float deltaTime=0.0f;
    
    Animacion * animacion = personajes->getAnimacion();
      while(ventana->isOpen()){
        
          deltaTime=clock.restart().asSeconds();
          
        *tiempo1=reloj1->getElapsedTime();
        
        if(tiempo2 + frameRate < tiempo1->asSeconds()){
        
            tiempo2=tiempo1->asSeconds();
            
            ventana->clear();
            
            this->niveles->actualizar_fisica();
            
            animacion->Update(0,deltaTime);
            std::cout<<animacion->uvRect.left<<std::endl;
            std::cout<<animacion->uvRect.width<<std::endl;
            personajes->getSprite().setTextureRect(animacion->uvRect);
            dibujar();
            
            ventana->display();
        }
        
    }
    
}

void Partida::dibujar(){
    
    niveles->getCaja()->dibujar(*ventana);
    
    niveles->getSuelo()->dibujar(*ventana);
    
    ventana->draw(personajes->getSprite());
    
}