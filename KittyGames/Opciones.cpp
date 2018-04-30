/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <SFML/Audio/AlResource.hpp>

#include "Opciones.h"
#include "Alien.h"
#include "Partida.h"

Opciones::Opciones(float width, float height){
    if(!font.loadFromFile("Recursos/leadcoat.ttf")){
        //handle error
        std::cout <<"No carga el tipo de letra" << std::endl;
    }
    opciones[0].setFont(font);
    opciones[0].setColor(sf::Color::Blue);
    opciones[0].setCharacterSize(100);
    opciones[0].setString("Audio");
    opciones[0].setPosition(sf::Vector2f((width / 2) - 120, height/(MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    opciones[1].setFont(font);
    opciones[1].setColor(sf::Color::White);
    opciones[1].setCharacterSize(100);
    opciones[1].setString("Creditos");
    opciones[1].setPosition(sf::Vector2f((width / 2) - 120, height/(MAX_NUMBER_OF_ITEMS + 1) * 2));
    
    opciones[2].setFont(font);
    opciones[2].setColor(sf::Color::White);
    opciones[2].setCharacterSize(100);
    opciones[2].setString("Atras");
    opciones[2].setPosition(sf::Vector2f((width / 2) - 120, height/(MAX_NUMBER_OF_ITEMS + 1) * 3));
    
    selectedItemIndex = 0;
}


Opciones::~Opciones(){
    
}

void Opciones::draw(sf::RenderWindow &window){
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window.draw(opciones[i]);
    }
}

void Opciones::MoveUp(){
    if(selectedItemIndex - 1 >= 0){
        opciones[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        opciones[selectedItemIndex].setColor(sf::Color::Blue);
    }
}

void Opciones::MoveDown(){
    if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){
        opciones[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        opciones[selectedItemIndex].setColor(sf::Color::Blue);
    }
}

void Opciones::Audio(){
    
}

void Opciones::Atras(){
    
}

void Opciones::Creditos(){
    
}