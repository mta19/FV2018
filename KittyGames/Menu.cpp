/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Audio/AlResource.hpp>

#include "Menu.h"
#include "Alien.h"
#include "Partida.h"

Menu::Menu(float width, float height){
    if(!font.loadFromFile("arial.ttf")){
        //handle error
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Jugar");
    menu[0].setPosition(sf::Vector2f(width / 2, height/(MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Opciones");
    menu[1].setPosition(sf::Vector2f(width / 2, height/(MAX_NUMBER_OF_ITEMS + 1) * 2));
    
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setPosition(sf::Vector2f(width / 2, height/(MAX_NUMBER_OF_ITEMS + 1) * 3));
    
    selectedItemIndex = 0;
}


Menu::~Menu(){
    
}

void Menu::draw(sf::RenderWindow &window){
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
}

void Menu::MoveUp(){
    if(selectedItemIndex - 1 >= 0){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::Jugar(){
    Estado * partida=new Partida({1920,1080},"Empieza la partida");

    delete partida;
    
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
    }*/
}


