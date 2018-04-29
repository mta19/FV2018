#ifndef MAP_H
#define MAP_H

#include "tinyxml2-master/tinyxml2.h"


#include <SFML/Graphics.hpp>

using namespace tinyxml2;

class Map {
    private:
       
        XMLElement* map;
        XMLElement* img;       
        XMLElement *layer;
        XMLElement **data;
        XMLElement *capas;
        int ***_tilemap;  
        //bool colisiona;
        
        XMLElement *plat;
        XMLElement *platas;
        XMLElement **dataPlat;
        
    public:
        XMLDocument doc;
        int _width, _height, _tileWidth, _tileHeight;
        const char *filename;
        int _numLayers;
        int _activeLayer;
        //Para saber si mostrar todo el mapa o solo una capa
        bool todo=true;
        sf::Sprite ****_tilemapSprite;
        
        int _numPlats;
        
        Map(const char* ruta); //ToDo: Sergio map
        
        //Almacenamos en cada posicion de data (cada posicion equivaldria a una capa) 
        //todas las etiquetas tile
        void dataTiles();
        
        //Hacer matriz de sprites (_tilesetSprite) 3D en la que a la hora de crear 
        //el sprite se mustiplicase el rect por el gid al que pertenece
        void matrizSprites();
        
        //Obtenemos nueva coordenada X para el sprite del tile
        int NewCoordX(int gid);
        //Obtenemos nueva coordenada Y para el sprite del tile
        int NewCoordY(int gid);
        
        //Seleccionar capa a mostrar, en caso de pasarle por parametro un número superior
        //al numero de capas almacenadas, se mostrará por defecto la capa 0
        void setActiveLayer(int layer);
        
        //Hacemos el draw del mapa y lo mostramos por pantalla
        void dibujarMapa(sf::RenderWindow *window);
        
        void dataPlats();
        
        float getX(int z);
        
        float getY(int z);
        
        float getWidth(int z);
        
        float getHeight(int z);
        
        //PROX HITO
        //Acceder al gid del tile en el que se encuentra el enemigo.
//        int getGid(Enemy *enemy, int id1, int id2);
        
        //Colocar las hitboxs
//        bool putHitbox(Player *rath);
};

#endif /* MAP_H */