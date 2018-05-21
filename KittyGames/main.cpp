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
#include "SFML/Audio.hpp"
#include "Box2D/Box2D.h"
#include "Estado.h"
#include "Nivel.h"
#include "Partida.h"
#include "Menu.h"

using namespace sf;

#include "Ventana.h"
#include "Evento.h"
#include "Sprite2D.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 0

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Crear la ventana del main!
    sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML Funciona!!");
    
    Menu menu(window.getSize().x, window.getSize().y);
    
    //Vamos a probar a poner una textura de fondo xD
    /*sf::Texture texture;
    if(!texture.loadFromFile("Recursos/FondoMenu.jpg")){
        std::cout <<"No carga la imagen de fondo" << std::endl;
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);*/
    
    //Creamos la textura
    sf::Texture texture_back;
    sf::Sprite background;
    //Cargamos la textura desde un archivo
    texture_back.loadFromFile("Recursos/FondoMenu.jpg");
    //Asignamos la textura al sprite de fondo
    background.setTexture(texture_back);
    
    
    
    //Sonido
        
        //Cargar la musica
        sf::Music music;
        music.setVolume(80);
        if(!music.openFromFile("Recursos/Concussive.wav"))
            return EXIT_FAILURE;
        
        //Que suene la musica!
        music.setLoop(true);
        music.play();
    
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
        
        //Terminar las cositas
        
        //Limpiar la ventana
        window.clear();
        
        //Dibujar la ventana y el sprite
        window.draw(background);
        menu.draw(window);
        
        //Actualizar la ventana
        window.display();
    }
    
    return EXIT_SUCCESS;
    
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

