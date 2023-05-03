//
// Created by Tymon Muszynski on 01/05/2023.
//

#pragma once
#include "HashTable.h"
#include "String.h"


class Dijkstra {
private:
    int numberOfCities;
    rootCityNode **hashTable;
    rootCityNode *minCity;
    rootCityNode *cityToCheck;
public:
    Dijkstra(HashTable *hashTableClass, int numberOfCities, String *startCity, String *endCity);
    void dijkstraAlgorithm();
    void showPQ();
    void getMinCity();
    void findRootCity(String *cityName);
};

