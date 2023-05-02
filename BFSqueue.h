//
// Created by Tymon Muszynski on 29/04/2023.
//

#pragma  once

struct bfsQueueNode
{
    int coordinates;
    struct bfsQueueNode *next;
    struct bfsQueueNode *prev;
};

class BFSqueue{
protected:
    struct bfsQueueNode *head = nullptr;
public:
    BFSqueue();
    BFSqueue(bfsQueueNode *ptr);
    ~BFSqueue();
    bfsQueueNode *getListPtr();
    int countNodes();
    void endPush(int coordinates);
    //tu zmiana na char
    int frontDelete();
    void showList();
};

