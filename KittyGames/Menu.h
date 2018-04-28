/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: manjaro
 *
 * Created on 18 de abril de 2018, 16:21
 */

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu{
    public:
        Menu(float width, float height);
        ~Menu();
        
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        void Jugar();
        int GetPressedItem() {return selectedItemIndex;}
        
        //Hacer un metodo nuevo para que empice la partida desde aqui
        
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
};




