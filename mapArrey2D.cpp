//
// Created by Tymon Muszynski on 29/04/2023.
//

#include "mapArrey2D.h"

mapArrey2D::mapArrey2D(int x, int y) {
    char tmp;
    sizeX = x;
    sizeY = y;
    map = new char*[sizeY];
    mapVisited = new bool*[sizeY];
    for(int i = 0; i < sizeY; i++)
    {
        map[i] = new char[sizeX];
        mapVisited[i] = new bool[sizeX];
        for(int j= 0; j < sizeX; j++)
        {
            mapVisited[i][j] = false;
            tmp = getchar();
            if(tmp == '*'){
                numberOfCities++;
            }
            map[i][j] = tmp;
        }
        getchar();
    }
}

int mapArrey2D::getNumberOfCities() {
    return numberOfCities;
}

mapArrey2D::~mapArrey2D() {
    for(int i = 0; i < sizeY; i++)
    {
        delete [] mapVisited[i];
        delete [] map[i];
    }
    delete [] mapVisited;
    delete [] map;
}
void mapArrey2D::resetBoolArr(){
    for(int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            mapVisited[i][j] = false;
        }
    }
}

void mapArrey2D::showMap() {
    for(int i = 0; i < sizeY; i++)
    {
        for(int j= 0; j < sizeX; j++)
        {
            std::cout<<map[i][j];
        }
        std::cout<<std::endl;
    }
}

char **mapArrey2D::getPtrChar() {
    return map;
}
bool **mapArrey2D::getPtrBool() {
    return mapVisited;
}