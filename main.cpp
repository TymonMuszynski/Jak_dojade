#include <iostream>
using namespace std;
#include "String.h"
#include "mapArrey2D.h"
#include "BFS.h"
#include "Dijkstra.h"
//#include "HashTable.h"
//#include <chrono>
//using namespace chrono;


int main()
{
    int x = 0, y= 0;
    int flightState = 0, nuberOfFlights = 0, flightTime = 0;
    int dijkstraState = 0, numberOfTests =0, typeOfTest = 0;

    char tmp = ' ';
    cin>>x>>y;
    getchar();
    mapArrey2D *mapClass = new mapArrey2D(x,y);

    // start point time tracking
//    auto start = high_resolution_clock::now();

    BFS *bfsClass = new BFS(x, y, mapClass->getPtrChar(), mapClass->getNumberOfCities());
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
             if(mapClass->getPtrChar()[i][j] == '*'){
                 bfsClass->findOptimalPath(j,i, mapClass->getPtrBool());
                 mapClass->resetBoolArr();
           }
        }
    }

    // time tracking end point
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//
//    double durationSeconds = static_cast<double>(duration.count()) / 1000000.0;
//    cout << "Time taken by function: " << durationSeconds << " seconds" << endl;

    Dijkstra *dijkstraClass;
//

    cin>>nuberOfFlights;
    getchar();
    for(int i=0; i<nuberOfFlights; i++){
        flightTime = 0;
        String *cityDeparture = new String(" ");
        String *cityArrival = new String(" ");
        while(tmp != '\n'){
            tmp = getchar();
            if(tmp == ' '){
                flightState += 1;
            }
            else{
                if(flightState == 0) {
                    cityDeparture->addChar(tmp);
                }
                else if(flightState == 1){
                    cityArrival->addChar(tmp);
                }
            }
            if(flightState == 2){
                cin>>flightTime;
                break;
            }
        }
        getchar();
        tmp = ' ';
        flightState = 0;
        cityArrival->removeSpaces();
        cityDeparture->removeSpaces();
       // cout<<cityDeparture->c_str()<<","<<cityArrival->c_str()<<","<<flightTime<<endl;
        bfsClass->getHashTable()->addFlight(cityDeparture, cityArrival, flightTime);
    }
    //bfsClass->getHashTable()->showHashTable();

    cin>>numberOfTests;
    getchar();
    for(int i=0; i<numberOfTests; i++) {
        typeOfTest = 0;
        String *startCity = new String(" ");
        String *endCity = new String(" ");
        while (tmp != '\n') {
            tmp = getchar();
            if (tmp == ' ') {
                flightState += 1;
            } else {
                if (flightState == 0) {
                    startCity->addChar(tmp);
                } else if (flightState == 1) {
                    endCity->addChar(tmp);
                }
            }
            if (flightState == 2) {
                cin >> typeOfTest;
                break;
            }
        }
        getchar();
        tmp = ' ';
        flightState = 0;
        startCity->removeSpaces();
        endCity->removeSpaces();
       // cout << startCity->c_str() << "," << endCity->c_str() << "," << typeOfTest << endl;
        dijkstraClass = new Dijkstra(bfsClass->getHashTable(), mapClass->getNumberOfCities(), startCity, endCity);
//        bfsClass->getHashTable()->showHashTable();
        dijkstraClass->dijkstraAlgorithm();

        if(typeOfTest == 1){
            bfsClass->getHashTable()->testNo1(startCity, endCity);
        }
        else{
            bfsClass->getHashTable()->testNo0(startCity, endCity);
        }
        cout<<endl;
        delete dijkstraClass;
 //       cout<<"test:" << i<<endl;
//        bfsClass->getHashTable()->showHashTable();
    }
}


