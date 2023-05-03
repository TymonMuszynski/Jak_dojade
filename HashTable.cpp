//
// Created by Tymon Muszynski on 01/05/2023.
//

#include "HashTable.h"

HashTable::HashTable(int numberOfCities) {
    this->numberOfCities = numberOfCities;
    hashTable = new rootCityNode*[numberOfCities];
    for(int i = 0; i < numberOfCities; i++){
        hashTable[i] = new rootCityNode;
        hashTable[i]->cityNameRoot = nullptr;
        hashTable[i]->neighbourCity = nullptr;
        hashTable[i]->next = nullptr;
    }
}

void HashTable::addRootCity(String *cityNameRoot) {
    rootCityNode *headRootCity;
    key = cityNameRoot->getKeyOfCity();
    hashKey = key % numberOfCities;
    headRootCity = hashTable[hashKey];
    // checkig if rootCity is empty struct
    if(headRootCity->cityNameRoot == nullptr){
        headRootCity->cityNameRoot = cityNameRoot;
        headRootCity->visited = false;
        headRootCity->shortDistance = 0;
        //add neighbourCity to rootCity that is empty now
        headRootCity->neighbourCity = new neighbourCityNode;
        //set headOfCurrentRootCity to because we now that after this we will need it for adding neighbourCity
        headOfCurrentRootCity = headRootCity;
    }
    else {
        rootCityNode *cur = new rootCityNode;
        cur->cityNameRoot = cityNameRoot;
        headRootCity->visited = false;
        headRootCity->shortDistance = 0;
        //add neighbourCity to rootCity that is empty now
        cur->neighbourCity = new neighbourCityNode;
        cur->next = headRootCity;
        hashTable[hashKey] = cur;
        //set headOfCurrentRootCity to because we now that after this we will need it for adding neighbourCity
        headOfCurrentRootCity = cur;
    }
}

void HashTable::addNeighbourCity(String *cityNameNeighbour, int time){
    neighbourCityNode *headNeighbourCity;
    headNeighbourCity = headOfCurrentRootCity->neighbourCity;
    if(headNeighbourCity->cityNameNeighbour == nullptr){
        headNeighbourCity->cityNameNeighbour = cityNameNeighbour;
        headNeighbourCity->time = time;
    }
    else{
        neighbourCityNode *cur = new neighbourCityNode;
        cur->cityNameNeighbour = cityNameNeighbour;
        cur->time = time;
        cur->next = headNeighbourCity;
        headOfCurrentRootCity->neighbourCity = cur;
    }
}
rootCityNode **HashTable::getHashTable(){
    return hashTable;
}

void HashTable::showHashTable(){
    for(int i=0; i<numberOfCities; i++){
        rootCityNode *cur = hashTable[i];
        cout<<"HashTable["<<i<<"]: "<<endl;
        if(cur->cityNameRoot != nullptr) {
            while (cur != nullptr) {
                cout <<"    Root City:"<< cur->cityNameRoot->c_str()<<" Visited: "<<cur->visited<<" Distance: "<<cur->shortDistance;
                if(cur->previousCity != nullptr){
                    cout<<" Previous City: "<<cur->previousCity->cityNameRoot->c_str()<<endl;
                }
                else{
                    cout<<" nullptr"<<endl;
                }
                neighbourCityNode *curNeighbour = cur->neighbourCity;
                if( curNeighbour->cityNameNeighbour != nullptr) {
                    while (curNeighbour != nullptr) {
                        cout << "        Neighbour City:" << curNeighbour->cityNameNeighbour->c_str() << " Time: "
                             << curNeighbour->time << endl;
                        curNeighbour = curNeighbour->next;
                    }
                }
                cur = cur->next;
            }
        }
    }
}

void HashTable::addFlight(String *departureCity, String *arrivalCity, int time) {
    rootCityNode *cur = hashTable[departureCity->getKeyOfCity() % numberOfCities];
    if (cur->cityNameRoot != nullptr) {
        while (cur != nullptr) {
            if (*cur->cityNameRoot == *departureCity) {
                neighbourCityNode *curNeighbour = cur->neighbourCity;
                if (curNeighbour->cityNameNeighbour != nullptr) {
                    while (curNeighbour != nullptr) {
                        if (*curNeighbour->cityNameNeighbour == *arrivalCity) {
                            if (curNeighbour->time > time) {
                                curNeighbour->time = time;
                                break;
                            }
                        }
                        if(curNeighbour->next == nullptr){
                            neighbourCityNode *tmp = new neighbourCityNode;
                            tmp->cityNameNeighbour = arrivalCity;
                            tmp->time = time;
                            tmp->next = nullptr;
                            curNeighbour->next = tmp;
                            break;
                        }
                        curNeighbour = curNeighbour->next;
                    }
                }
                break;
            }
            cur = cur->next;
        }
    }
}

void HashTable::testNo0(String *startCity, String *endCity) {
    rootCityNode *cur = hashTable[endCity->getKeyOfCity() % numberOfCities];
    if(cur->cityNameRoot != nullptr) {
        while (cur != nullptr) {
            if(*cur->cityNameRoot == *endCity){
                cout<<cur->shortDistance;
                cityThatEndsRout = cur;
                break;
            }
            cur = cur->next;
        }
    }

}

void HashTable::testNo1(String *startCity, String *endCity) {
    testNo0(startCity, endCity);
    rootCityNode *tmp;
    tmp = cityThatEndsRout->previousCity;
    while(!(*tmp->cityNameRoot == *startCity)){
        cout<<" ";
        cout<<tmp->cityNameRoot->c_str();
        tmp = tmp->previousCity;
    }

//    if(*cityThatEndsRout->previousCity->cityNameRoot == *startCity){
//        return;
//    }
//    else{
//        while()
//    }
}