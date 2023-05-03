//
// Created by Tymon Muszynski on 01/05/2023.
//

#pragma once
#include "String.h"
#include <iostream>
using namespace std;

struct neighbourCityNode{
    String *cityNameNeighbour;
    int time;
    struct neighbourCityNode *next;
};

struct rootCityNode{
    bool visited;
    unsigned long long int shortDistance;
    rootCityNode *previousCity;
    String *cityNameRoot;
    struct neighbourCityNode *neighbourCity;
    struct rootCityNode *next;
};

struct responseNode{
    String *cityName;
    struct responseNode *next;
};

class HashTable {
protected:
    int numberOfCities;
    int key;
    int hashKey;
    rootCityNode **hashTable;
    rootCityNode *headOfCurrentRootCity;
    rootCityNode *cityThatEndsRout;
public:
    HashTable(int numberOfCities);
    ~HashTable();
    void addRootCity(String *cityNameRoot);
    void addNeighbourCity(String *cityNameNeighbour, int time);
    void showHashTable();
    rootCityNode **getHashTable();
    void addFlight(String *departureCity, String *arrivalCity, int time);
    void testNo0(String *startCity, String *endCity);
    void testNo1(String *startCity, String *endCity);
};



