#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// in order to make sure that the h file is present and created and if not create it

struct Node
{
    int value;
    int count;
    Node *next;
};

class LinkedList
{
public:
    LinkedList();
    void addNode(int value, int count);
    void removeNode(int value);
    void printLinkedList();
    int sumOfNodes();

private:
    Node *head;
    // pointer to the head (start of linked list)
    Node *tail;
    // pointer to the tail (end of linked list)
};

#endif