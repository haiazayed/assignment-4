#include "linkedlistclass.h"
#include <iostream>
#include <vector>

using namespace std;

// constructor the allows the head of the linked list to be null as we start
LinkedList::LinkedList()
{
    head = NULL;
}

// adds a node to the linked list
void LinkedList::addNode(int value, int count)
{

    // create new node and intialize its value as well as count and the next pointer
    Node *newNode = new Node;
    newNode->value = value;
    newNode->count = 1;
    // set count to 1 since it's the first occurrence of the value
    newNode->next = NULL;

    // if the list is empty, set the head to the new node and return

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    // try to find the end and make that the new node
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::removeNode(int value)
{
    Node *current = head;
    Node *previous = NULL;

    // go through the linked list until current node is null
    while (current != NULL)
    {

        // if the value of the current node matches the input value  remove it
        if (current->value == value)
        {

            // if the node you want to remove is the first one
            if (previous == NULL)
            {
                head = current->next;
                // move the head to the next node and then remove
            }

            // if the node you want to remove  is nit the first one
            else
            {
                previous->next = current->next; // make the previous node the next node in order to be able to remove
            }
            delete current; // allows you to delete the current node you are on (learnt online)
            break;
        }
        else
        {
            previous = current;      // makes the previous node the current node
            current = current->next; // moves to the next node
        }
    }
}

void LinkedList::printLinkedList()
{
    Node *current = head;   // allows the current node to be the head of linked lisr
    while (current != NULL) // checks that the current node is not NULL
    {
        cout << current->value << " " << current->count << " "; // prints out the contents
        current = current->next;                                // makes the next node the current node
    }
    cout << endl;
}

int LinkedList::sumOfNodes()
{
    Node *current = head;
    // declares the current node and intiliazes it as the head of the linked list
    int sum = 0;
    // starts off with the sum variable =0
    while (current != NULL) // again checks that the current node is not null (good practice)
    {
        sum += current->value * current->count;
        //// adds the value of the current node multiplied by its count to the sum
        current = current->next;
        // mov to the next node in the linked list
    }
    return sum;
}

// This function  references to the  vector of integers as input and creates the linked list based on the elements of the vector.
LinkedList createLinkedList(vector<int> &v)
{
    LinkedList l; // creates an empty linked list

    for (int i = 0; i < v.size(); i++)
    // loop through the vector elements one by one
    {
        int count = 1;
        for (int j = i + 1; j < v.size(); j++) // again going through the vectore to see how many times an occurrence takes place
        {
            if (v[j] == v[i]) // if the current element is equal to the current value in the vector
            {
                count++; // add onto the couner intiliazed up
            }
        }
        l.addNode(v[i], count); // add the node with both the value and count to the linked list
    }
    return l; // returns the new formed linked list
}

void insertAfter(vector<int> &v, int firstValue, int secondValue)
{

    // going through the vector
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == firstValue) // if occurrence of first value is found
        {
            v.insert(v.begin() + i + 1, secondValue); // add the second value enetered by the user after the each occurrence of first value
            i++;                                      // in order to skip over the second element as we dont want  that checked
        }
    }
}