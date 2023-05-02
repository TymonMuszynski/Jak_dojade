//
// Created by Tymon Muszynski on 01/05/2023.
//

#pragma once
#include "HashTable.h"
#include "String.h"

struct PQnode{
    unsigned long long int time;
    bool visited;
    rootCityNode *startCity;
    rootCityNode *previousCity;
    PQnode *next;
};

class Dijkstra {
private:
    int numberOfCities;
    HashTable *hashTableClass;
    PQnode *headPQ;
    PQnode *minCity;
public:
    Dijkstra(HashTable *hashTableClass, int numberOfCities, String *startCity, String *endCity);
    void dijkstraAlgorith();
    void showPQ();
    void getMinCity();
    rootCityNode *findRootCity(int key);
};

