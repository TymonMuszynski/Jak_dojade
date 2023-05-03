//
// Created by Tymon Muszynski on 01/05/2023.
//

#include "Dijkstra.h"

Dijkstra::Dijkstra(HashTable *hashTableClass, int numberOfCities, String *startCity, String *endCity){
hashTable = hashTableClass->getHashTable();
this->numberOfCities = numberOfCities;

    for(int i=0; i<numberOfCities; i++) {
        rootCityNode *cur = hashTable[i];
        if (cur->cityNameRoot != nullptr) {
            while (cur != nullptr) {
                cur->visited = false;
                cur->previousCity = nullptr;
                if(*cur->cityNameRoot == *startCity){
                    cur->shortDistance = 0;
                }
                else{
                    cur->shortDistance = 99999999999999;
                }
                cur = cur->next;
            }
        }
    }
    //hashTableClass->showHashTable();
}

void Dijkstra::showPQ(){

}

void Dijkstra::dijkstraAlgorithm() {
    for(int i=0; i<numberOfCities; i++) {
        getMinCity();

        neighbourCityNode *cur = minCity->neighbourCity;
        if (cur->cityNameNeighbour != nullptr) {
            while (cur != nullptr) {
                if(cur->cityNameNeighbour != nullptr){
                findRootCity(cur->cityNameNeighbour);
                if (cityToCheck->shortDistance > minCity->shortDistance + cur->time) {
                    cityToCheck->shortDistance = minCity->shortDistance + cur->time;
                    cityToCheck->previousCity = minCity;
                }
                }
                cur = cur->next;
            }
        }
    }

}

void Dijkstra::getMinCity(){
    minCity = nullptr;
    for(int i=0; i<numberOfCities; i++) {
            rootCityNode *cur = hashTable[i];
            if(cur->cityNameRoot != nullptr) {
                while (cur != nullptr) {
                    if(minCity == nullptr){
                        minCity = cur;
                        cur->visited = true;
                    }
                    else {
                        if (cur->visited == false) {
                            if (cur->shortDistance < minCity->shortDistance) {
                                minCity = cur;
                                cur->visited = true;
                            }
                        }
                    }
                    cur = cur->next;
                }
            }
    }
}

void Dijkstra::findRootCity(String *cityName) {
int hashkey = cityName->getKeyOfCity() % numberOfCities;
    rootCityNode *cur = hashTable[hashkey];
    if (cur->cityNameRoot != nullptr) {
        while (cur != nullptr) {
            if(*cur->cityNameRoot == *cityName){
                cityToCheck = cur;
            }
            cur = cur->next;
        }
    }
}


//            if (hashTable[i]->visited == false) {
//                if (hashTable[i]->shortDistance < minCity->shortDistance) {
//                    minCity = hashTable[i];
//                    hashTable[i]->visited = true;
//                }