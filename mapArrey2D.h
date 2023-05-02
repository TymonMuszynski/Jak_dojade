//
// Created by Tymon Muszynski on 29/04/2023.
//
#pragma once
#include <cstdio>
#include <iostream>
using namespace std;

class mapArrey2D {
protected:
    int numberOfCities;
    char **map;
    bool **mapVisited;
    int sizeX;
    int sizeY;
public:
    mapArrey2D(int x, int y);
    ~mapArrey2D();
    void showMap();
    char **getPtrChar();
    bool **getPtrBool();
    void resetBoolArr();
    int getNumberOfCities();
};
