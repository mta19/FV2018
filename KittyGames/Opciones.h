/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Opciones.h
 * Author: manjaro
 *
 * Created on 30 de abril de 2018, 21:02
 */

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Opciones{
    public:
        Opciones(float width, float height);
        ~Opciones();
        
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        void Audio();
        void Creditos();
        void Atras();
        int GetPressedItem() {return selectedItemIndex;}
        
        //Hacer un metodo nuevo para que empice la partida desde aqui
        
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text opciones[MAX_NUMBER_OF_ITEMS];
};
