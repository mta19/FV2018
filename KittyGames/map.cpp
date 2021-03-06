#include "map.h"
#include <iostream>


using namespace std;

Map::Map(const char* ruta) {
   
    
    
    tiles=32;
    
    doc.LoadFile(ruta);

    map = doc.FirstChildElement("map");
    
    cout << "prueba:" << doc.FirstChild() << "\n";

    map->QueryIntAttribute("width", &_width);
    map->QueryIntAttribute("height", &_height);
    map->QueryIntAttribute("tilewidth", &_tileWidth);
    map->QueryIntAttribute("tileheight", &_tileHeight); 
    
    img = map->FirstChildElement("tileset")->FirstChildElement("image");
    filename = img->Attribute("source");

    layer = map->FirstChildElement("layer");
    _numLayers=0;
    
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer");
    }
    
    //Almacenamos las etiquetas tiles
    dataTiles();
    
    //Creamos el mapa de tiles
    _tilemap = new int**[_numLayers];
    
    
    //Reservamos memoria para el tilemap
    for(int i=0; i<_numLayers;i++){
        _tilemap[i] = new int*[_height];
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height;y++){
            _tilemap[l][y] = new int[_width];
        }
    }
    
    for(int l=0; l<_numLayers; l++){
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                data[l]->QueryIntAttribute("gid", &_tilemap[l][y][x]);
                
                data[l] = data[l]->NextSiblingElement("tile");
                
            }
        }
    }
    
    //creamos las plataformas
    plat=map->FirstChildElement("objectgroup")->FirstChildElement("object");
    _numPlats=0;
    
    while(plat){
        _numPlats++;
        plat = plat->NextSiblingElement("object");
    }
    
    dataPlats();
    //Cajas
    box=map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
    _numBoxes=0;
    
    while(box){
        _numBoxes++;
        box = box->NextSiblingElement("object");
    }
    
    dataBoxes();
    
    //escaleras
    stair=map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
    _numStairs=0;
    
    while(stair){
        _numStairs++;
        stair = stair->NextSiblingElement("object");
    }
    
    dataStairs();
    //Creamos el array de sprites
    matrizSprites();
    
}


void Map::dataTiles(){
            
    data = new XMLElement*[_numLayers];
    
    capas = map->FirstChildElement("layer");
    
    for(int i=0; i<_numLayers; i++){
        data[i] = capas->FirstChildElement("data")->FirstChildElement("tile");
        capas = capas->NextSiblingElement("layer");
    }
    
    
}

void Map::dataPlats(){
    dataPlat = new XMLElement*[_numPlats];
    
    platas = map->FirstChildElement("objectgroup")->FirstChildElement("object");
    
    for(int i=0; i<_numPlats; i++){
        dataPlat[i] = platas;
        
        
         platas= platas->NextSiblingElement("object");//NextSiblingElement("objectgroup");
    }
    
} 

void Map::dataStairs(){
    dataStair = new XMLElement*[_numStairs];
    
    stairs = map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
    
    for(int i=0; i<_numStairs; i++){
        dataStair[i] = stairs;
        
        
         stairs= stairs->NextSiblingElement("object");//NextSiblingElement("objectgroup");
    }
}  
 void   Map::dataBoxes(){
    dataBox = new XMLElement*[_numBoxes];
    
    boxes = map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
    
    for(int i=0; i<_numBoxes; i++){
        dataBox[i] = boxes;
        
        
         boxes= boxes->NextSiblingElement("object");//NextSiblingElement("objectgroup");
    }
    
} 
float Map::getX(char x,int z){
    float res=0;
    switch(x){
        case 'p':
           res= dataPlat[z]->FloatAttribute("x");
        break;
        
        case 's':
            res= dataStair[z]->FloatAttribute("x");
        break;
        
        case 'b':
           res= dataBox[z]->FloatAttribute("x");
        break;
    }
    return res;
    
}
  
float Map::getY(char x,int z){
    float res=0;
    switch(x){
        case 'p':
           res= dataPlat[z]->FloatAttribute("y");
        break;
        
        case 's':
            res= dataStair[z]->FloatAttribute("y");
        break;
        
        case 'b':
           res= dataBox[z]->FloatAttribute("y");
        break;
    }
    return res;
}

float Map::getWidth(char x,int z)  
{
    float res=0;
    switch(x){
        case 'p':
           res= dataPlat[z]->FloatAttribute("width");
        break;
        
        case 's':
            res= dataStair[z]->FloatAttribute("width");
        break;
        
        case 'b':
           res= dataBox[z]->FloatAttribute("width");
        break;
    }
    return res;
}

float Map::getHeight(char x,int z){
    float res=0;
    switch(x){
        case 'p':
           res= dataPlat[z]->FloatAttribute("height");
        break;
        
        case 's':
            res= dataStair[z]->FloatAttribute("height");
        break;
        
        case 'b':
           res= dataBox[z]->FloatAttribute("height");
        break;
    }
    return res;
}

void Map::matrizSprites(){
    //NEED PUNTERO
    sf::Texture *_tilesetTexture= new sf::Texture;
    
    _tilesetTexture->loadFromFile("resources/tileSdiminuto.png");
    
    //NEED PUNTERO
    sf::Rect <float> *medidas = new sf::Rect <float>(0, 0, tiles, tiles); 
    _tilemapSprite = new sf::Sprite***[_numLayers];
    //Rellenando el array de sprites
    for(int l=0; l<_numLayers; l++){
        _tilemapSprite[l] = new sf::Sprite**[_height];
        for(int y=0; y<_height; y++){
            _tilemapSprite[l][y] = new sf::Sprite*[_width];
            for(int x=0; x<_width; x++){
                int gid = _tilemap[l][y][x];               
                    
                if(gid>0){
//                    Coordinate* coord = new Coordinate (x*_tileWidth, y*_tileHeight);
                    
//                    mio int* coord[]= new int[x*_tileWidth,y*_tileHeight];
                    int newX, newY;                    
                    
                    //Obtenemos nueva coordenada x e y del rect medidas
                    newX = NewCoordX(gid);
                    newY = NewCoordY(gid);
                    
                    
                    medidas->left=newX-tiles;
                    medidas->top=newY;
                    medidas->width=tiles;
                    medidas->height= tiles;
                    
//                     
                    
                    _tilemapSprite[l][y][x]=new sf::Sprite(*_tilesetTexture);
                    
                    _tilemapSprite[l][y][x]->setTextureRect(sf::IntRect(medidas->left,medidas->top,medidas->width,medidas->height));
                    
                    _tilemapSprite[l][y][x]->setOrigin(0,0);
                    
                    _tilemapSprite[l][y][x]->setPosition(0,0);
                    
                    //_tilemapSprite[l][y][x]->scale(0.5,0.5);
                    
                    /*
                    _tilemapSprite[l][y][x] = new sf::Sprite(_tilesetTexture, 
                            //_tilesetSprite[gid]->getTextureRect());
                            *medidas);
                    */
                    //
                    
                    _tilemapSprite[l][y][x]->setPosition(x*_tileWidth,y*_tileHeight);
                    
                }else{             
                    _tilemapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}

int Map::NewCoordX(int gid){
    
    int newX = (gid/8);
                    
    if(gid%8==0){
        newX = newX-1;
    }

    if(newX>0){
        newX = tiles*(gid-(newX*8)); 
    }else{
        newX = (gid*tiles);
    }
    
    return newX;
}

int Map::NewCoordY(int gid){
    
    int newY;
    
    newY = (gid/8)*tiles;
                  
    if(gid%8==0){
        newY = newY-tiles;
    }
    
    return newY;
}

void Map::setActiveLayer(int layer){
    
    todo = false;
    
    if(_numLayers>layer){
        _activeLayer = layer;
    }else{
        _activeLayer = 0;
    }
}


void Map::dibujarMapa(sf::RenderWindow *window){
     
    if(todo==false){
        //Se muestra solo la capa seleccionada
        for(int y=0; y<_height; y++){
            for(int x=0; x<_width; x++){
                if(_tilemapSprite[_activeLayer][y][x]!=NULL){
                    //Dibujamos todas las capas
                    //Haciendo un metodo activeLayer podriamos elegir una sola capa
                    window->draw(*_tilemapSprite[_activeLayer][y][x]);
                    //window.draw(*(_tilemapSprite[_activeLayer][y][x]));
                }
            }
        }
    }else{
        //Se muestra todo el mapa
        
        for(int l=0; l<_numLayers; l++){
            for(int y=0; y<_height; y++){
                for(int x=0; x<_width; x++){
                    if(_tilemapSprite[l][y][x]!=NULL){
                        //Dibujamos todas las capas
                        //Con el metodo activeLayer podemos elegir una sola capa
                        //window->draw(_tilemapSprite[l][y][x]);
                        /*bool ex=false;
                        for(int p=l+1;p<_numLayers;p++){
                            if(_tilemapSprite[l][y][x]!=NULL)
                                ex=true;
                        }
                        if(ex==false)*/
                            window->draw(*(_tilemapSprite[l][y][x]));
                        
                    }
                }
            }
        }
    }
}

