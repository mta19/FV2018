/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nivel.cpp
 * Author: pedro
 * 
 * Created on 19 de marzo de 2018, 19:54
 */
#include <iostream>
#include "Nivel.h"
#include "Box2D/Box2D.h"

Nivel::Nivel() {
    
    txt_suelo=new Texture;
    txt_suelo->loadFromFile("suelo.jpg");
    
    txt_caja=new Texture;
    txt_caja->loadFromFile("caja.jpg");
    
    spr_suelo=new Sprite(*txt_suelo);
    spr_caja=new Sprite(*txt_caja);
    std::cout<<"Por ahora funciona2"<<std::endl;
    
    std::cout<<"Por ahora funciona3"<<std::endl;
    
     mundo= new b2World(b2Vec2(0.f,9.81f));
}

Nivel::Nivel(const Nivel& orig) {
}

Nivel::~Nivel() {
}


void Nivel::anyadirPlataforma(float x, float y){
    
     bdydef_suelo.type= b2_staticBody;
    bdydef_suelo.position=b2Vec2(x,y);
    
    bdy_suelo=mundo->CreateBody(&bdydef_suelo);
    
    b2PolygonShape shp_suelo;
    shp_suelo.SetAsBox(50.f,5.f);
    
    fixdef_suelo.shape= &shp_suelo;
    fixdef_suelo.density=1.f;
    fixdef_suelo.restitution=0.1f;
    fixdef_suelo.friction=0.3f;
    
    fix_suelo=bdy_suelo->CreateFixture(&fixdef_suelo);
    
      ensambladorSuelo=new Ensamblador (bdy_suelo,spr_suelo);
    
}

void Nivel::anyadirObjetoDinamico(float x, float y){
    
   
    bdydef_caja.type= b2_dynamicBody;
    bdydef_caja.position=b2Vec2(x,y);
    
    bdy_caja=mundo->CreateBody(&bdydef_caja);
    
    b2PolygonShape shp_caja;
    shp_caja.SetAsBox(2.5f,2.5f);
    
    fixdef_caja.shape= &shp_caja;
    fixdef_caja.density=1.f;
    fixdef_caja.restitution=0.1f;
    fixdef_caja.friction=0.3f;
    
    fix_caja=bdy_caja->CreateFixture(&fixdef_caja);
    
    
  
    ensambladorCaja= new Ensamblador (bdy_caja,spr_caja);
    
    
}


void Nivel::actualizar_fisica(){
    
    mundo->Step(0.06f,8,8);
    std::cout<<bdy_caja->GetPosition().y<<std::endl;
    mundo->ClearForces();
    
}
