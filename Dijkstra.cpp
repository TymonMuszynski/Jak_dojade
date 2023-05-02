//
// Created by Tymon Muszynski on 01/05/2023.
//

#include "Dijkstra.h"

Dijkstra::Dijkstra(HashTable *hashTableClass, int numberOfCities, String *startCity, String *endCity){
    this->hashTableClass = hashTableClass;
    this->numberOfCities = numberOfCities;
    rootCityNode **hashTable = hashTableClass->getHashTable();
    headPQ = new PQnode;
//    int hashKey = startCity->getKeyOfCity() % numberOfCities;

    for(int i=0; i<numberOfCities; i++){
        rootCityNode *cur =  hashTable[i];
        if(cur->cityNameRoot != nullptr) {
            while (cur != nullptr) {
//                neighbourCityNode *curNeighbour = cur->neighbourCity;
//                if( curNeighbour->cityNameNeighbour != nullptr) {
                if (headPQ->startCity == nullptr) {
                    headPQ->startCity = cur;
                    headPQ->previousCity = nullptr;
                    headPQ->next = nullptr;
                } else {
                    PQnode *curPQ = new PQnode;
                    curPQ->startCity = cur;
                    curPQ->previousCity = nullptr;
                    curPQ->next = headPQ;
                    headPQ = curPQ;
                }
                if (*headPQ->startCity->cityNameRoot == *startCity) {
                    headPQ->time = 0;
                } else {
                    headPQ->time = 999999999999999999;
                }
//                }
                cur = cur->next;
            }
        }
    }
}

void Dijkstra::showPQ(){
    PQnode *cur = headPQ;
    while(cur != nullptr){
        cout << cur->startCity->cityNameRoot->c_str() << " " << cur->time << endl;
        cur = cur->next;
    }
}

void dijkstraAlgorith() {

}

void Dijkstra::getMinCity(){
    PQnode *cur = headPQ;
    PQnode *min = headPQ;
    while(cur != nullptr){
        if(cur->time < min->time && !cur->visited){
            min = cur;
        }
        cur = cur->next;
    }
    minCity = min;
}

rootCityNode *Dijkstra::findRootCity(int key){
    int hash = key % numberOfCities;

}
