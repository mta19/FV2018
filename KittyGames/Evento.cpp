/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Evento.cpp
 * Author: alejandro
 * 
 * Created on 24 de abril de 2018, 17:30
 */

#include "Evento.h"

Evento::Evento() {
       event = new sf::Event();
}

Evento::Evento(const Evento& orig) {
}

Evento::~Evento() {
}

sf::Event* Evento::getEvent(){
    return event;   
}


bool Evento::isClosed(){
    bool closed = false;
    
    if(event->type == sf::Event::Closed)
        closed = true;
    
    return closed;
}

bool Evento::isKeyPressed(){
    bool key = false;
    
    if(event->type == sf::Event::KeyPressed)
        key = true;
    
    return key;
}


std::string Evento::getKeyPressed(){

    sf::Keyboard::Key key = event->key.code;
    
    std::string ret;
    switch(key){

    case sf::Keyboard::A :

        ret="A";
        break;
    case sf::Keyboard::B :

        ret="B";
        break;
    case sf::Keyboard::C :

        ret="C";
        break;
    case sf::Keyboard::D :

        ret="D";
        break;
    case sf::Keyboard::E :

        ret="E";
        break;
    case sf::Keyboard::F :

        ret="F";
        break;
    case sf::Keyboard::G :

        ret="G";
        break;
    case sf::Keyboard::H :

        ret="H";
        break;
    case sf::Keyboard::I :

        ret="I";
        break;
    case sf::Keyboard::J :

        ret="J";
        break;
    case sf::Keyboard::K :

        ret="K";
        break;
    case sf::Keyboard::L :

        ret="L";
        break;
    case sf::Keyboard::M :

        ret="M";
        break;
    case sf::Keyboard::N :

        ret="N";
        break;
    case sf::Keyboard::O :

        ret="O";
        break;
    case sf::Keyboard::P :

        ret="P";
        break;
    case sf::Keyboard::Q :

        ret="Q";
        break;
    case sf::Keyboard::R :

        ret="R";
        break;
    case sf::Keyboard::S :

        ret="S";
        break;
    case sf::Keyboard::T :

        ret="T";
        break;
    case sf::Keyboard::U :

        ret="U";
        break;
    case sf::Keyboard::V :

        ret="V";
        break;
    case sf::Keyboard::W :

        ret="W";
        break;
    case sf::Keyboard::X :

        ret="X";
        break;
    case sf::Keyboard::Y :

        ret="Y";
        break;
    case sf::Keyboard::Z :

        ret="Z";
        break;

    case sf::Keyboard::Space :

        ret="Space";
        break;

    case sf::Keyboard::Left  :

        ret="Left";
        break;
    case sf::Keyboard::Right :

        ret="Right";
        break;
    case sf::Keyboard::Up :

        ret="Up";
        break;
    case sf::Keyboard::Down :

        ret="Down";
        break;

    default:
        ret="Unknow";
        break;
        }
    return ret;
}

