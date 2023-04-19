#include "linkedlistclass.cpp"
#include "linkedlistclass.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Create a vector to stor the integers we want
    vector<int> vec;
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter number " << i + 1 << ": ";
        cin >> x;
        vec.push_back(x);
    }
    cout << "Vector before i: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // use the insert after function in order to insert the values you want inserted after the repeated values
    int firstValue, secondValue;
    cout << "Enter first value: ";
    cin >> firstValue;
    cout << "Enter second value: ";
    cin >> secondValue;

    // insert secondValue after each occurrence of firstValue in vec
    insertAfter(vec, firstValue, secondValue);
    cout << "Vector after: ";
    // outputs the vector after you the inserafter function (changed vector)
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    cout << endl;

    // create linked list based on the vector's elements elements
    LinkedList List = createLinkedList(vec);
    cout << "Linked list: ";

    // prints the linked list for us to see before the removl of any nodes
    List.printLinkedList();

    // remove node from linked list
    int removethis;
    // allows user to input which nide it would want removed
    cout << "Enter value to remove from linked list: ";
    cin >> removethis;
    List.removeNode(removethis);
    cout << "Linked list after removal of node " << removethis << ": ";
    List.printLinkedList();

    // get sum of all nodes in linked list
    int sum = List.sumOfNodes();
    cout << "Sum of all nodes in linked list " << sum << endl;
}
