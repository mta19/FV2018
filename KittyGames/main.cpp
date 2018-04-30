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
#include "Menu.h"

using namespace sf;

#include "Ventana.h"
#include "Evento.h"
#include "Sprite2D.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Funciona!!");
    
    Menu menu(window.getSize().x, window.getSize().y);
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            switch(event.type){
                
                case sf::Event::KeyReleased:switch(event.key.code){
                    case sf::Keyboard::Up:menu.MoveUp();
                    break;
                    
                    case sf::Keyboard::Down:menu.MoveDown();
                    break;
                    
                    case sf::Keyboard::Return:switch(menu.GetPressedItem()){
                        case 0:
                            std::cout << "El boton de JUGAR ha sido pulsado" << std::endl;
                            
                            menu.Jugar();
                            //La ventana sigue abierta porque luego si sales es como si volvieras al menú, se puede cambiar.
                        break;
                        
                        case 1:
                            std::cout << "El boton de OPCIONES ha sido pulsado" << std::endl;
                        break;
                        
                        case 2:
                            std::cout << "El boton de SALIR ha sido pulsado" << std::endl;
                            window.close();
                        break;
                    }
                    break;
                }
                break;
                
                case sf::Event::Closed:window.close();
                break;
            }
        }
        
        window.clear();
        
        menu.draw(window);
        
        window.display();
    }
    
    return 0;
    
    /*Estado * partida=new Partida({1920,1080},"Empieza la partida");

    delete partida;
    
    Ventana window = Ventana(600,600,"Hola que tal");
    
    Sprite2D sprite = Sprite2D("suelo.jpg", 0, 0, 50,50);
    
    while(window.isOpen()){
        
        Evento* event = new Evento();
        
        while(window.pollEvent(event)){
        
            if(event->isClosed())
                window.close();
        }
        
        window.clear();
        sprite.draw(window);
        window.display();
    }
    
    return 0;*/
}

