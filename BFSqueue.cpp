//
// Created by Tymon Muszynski on 29/04/2023.
//

#include "BFSqueue.h"
#include <iostream>
using namespace std;

BFSqueue::BFSqueue(){
    head = new bfsQueueNode;
    head->coordinates = -1;
    head->next = nullptr;
    head->prev = nullptr;
}

BFSqueue::BFSqueue(bfsQueueNode *ptr){
    head = ptr;
}

BFSqueue::~BFSqueue()
{
    bfsQueueNode* current = head;
    while (current != nullptr) {
        bfsQueueNode* next = current->next;
        delete current;
        current = next;
    }
}

void BFSqueue::endPush( int coordinates )
{
    if (head->coordinates == -1 ) {
        head->coordinates = coordinates;
    }
    else {
        bfsQueueNode* tmp = head;
        bfsQueueNode* cur = new bfsQueueNode;
        cur->coordinates = coordinates;
        cur->next = nullptr;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        cur->prev = tmp;
        tmp->next = cur;
    }
}
int BFSqueue::frontDelete() {
    int tmp;
    if (head == nullptr) {
        cout << "The list is empty!" << endl;
        return ' ';
    }
    if(head->next == nullptr){
        tmp = head->coordinates;
        head->coordinates = -1;
        return tmp;
    }
    bfsQueueNode* current = head;
    head = current->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    tmp = current->coordinates;
    delete current;
    return tmp;
}

void BFSqueue::showList(){
    bfsQueueNode *tmp;
    tmp = head;
    int i = 0;
    cout<<" Koordynat: "<<i<<" ";
    cout<<tmp->coordinates<<endl;
    while(tmp->next != nullptr){
        tmp = tmp->next;
        i++;
        cout<<" Koordynat: "<<i<<" ";
        cout<<tmp->coordinates<<endl;
    };
}

int BFSqueue::countNodes(){
    bfsQueueNode *tmp;
    tmp = head;
    int i = 1;
    while(tmp->next != nullptr){
        tmp = tmp->next;
        i++;
    }
    return i;
}

bfsQueueNode *BFSqueue::getListPtr(){
    return head;
}
