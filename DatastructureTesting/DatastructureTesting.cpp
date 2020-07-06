// DatastructureTesting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <time.h>
#include <algorithm>


using namespace std;

int main()
{
    //structures
    LinkedList<int> linked;
    BST<int> bst;
    vector<int> vec;

    int size;
    int r;
    cout << "Enter size: (recommended > 1,000)" << endl;
    cin >> size;
    vector<int> bstAddList;
    cout << "making add list for bst" << endl;
    for (int i = 0; i < size; i++) {
        bstAddList.push_back(i);
    }
    random_shuffle(bstAddList.begin(), bstAddList.end());
    cout << "done making add list for bst" << endl;
    cout << endl;

    clock_t start;
    double duration;

    //inserting vector
    cout << "Adding to Vector" << endl;
    start = clock();
    for (int i = 0; i < size; i++) {
        vec.push_back(i);
    }
    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Vector ADD: " << duration << "sec" << endl;
    cout << endl;

    //inserting linked
    cout << "Adding to Linked List" << endl;
    start = clock();
    for (int i = 0; i < size; i++) {
        linked.add(i);
    }
    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "LinkedList ADD: " << duration << "sec" << endl;
    cout << endl;

    //inserting bst
    cout << "Adding to BST" << endl;
    start = clock();
    for(int i : bstAddList)
    {
        bst.add(i);
    }
    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "BST ADD: " << duration << "sec" << endl;
    cout << endl;

    //searching Vector
    cout << "Searching Vector" << endl;
    r = rand() % size;
    start = clock();

    vector<int>::iterator vFind;
    vFind = find(vec.begin(), vec.end(), r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Vector Search: " << duration << "sec" << endl;
    cout << endl;

    //searching Linked
    //Searching BST

    //delete from Vector
    cout << "Removing from Vector" << endl;
    r = rand() % size;
    start = clock();

    vector<int>::iterator new_end;
    new_end = remove(vec.begin(), vec.end(), r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Vector Remove: " << duration << "sec" << endl;
    cout << endl;

    //delete from linked
    cout << "Removing from Linked List" << endl;
    r = rand() % size;
    start = clock();

    linked.remove(r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "LinkedList Remove: " << duration << "sec" << endl;
    cout << endl;

    //delete from BST
    cout << "Removing from BST" << endl;
    start = clock();

    bst.remove(r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "BST Remove: " << duration << "sec" << endl;
    cout << endl;

    //printing
    //bst.print();
    //linked.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
