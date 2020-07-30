
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

bool continuePrompt() {
    string answer;
    //prompt to start again
    cout << "Would you like to test again? (Yes/No)" << endl;
    while (true) {
        cin >> answer;
        if (answer == "yes" || answer == "Yes" || answer == "YES") {
            return true;
        }
        else if (answer == "no" || answer == "No" || answer == "NO") {
            return false;
        }
        else {
            cout << answer + " is not a valid answer. Try again." << endl;
        }
    }
    return true;
}

int sizePrompt() {
    int size;
    cout << "Enter size:" << endl;
    //check size
    while (true) {
        cin >> size;
        if (size < 5000) {
            cout << "Please enter a size greater than 5000" << endl;
        }
        else {
            break;
        }
    }
    cout << endl;
    return size;
}

void testVector(int size) {
    clock_t start;
    double duration;
    vector<int> vec;
    int r;

    //inserting vector
    start = clock();
    for (int i = 0; i < size; i++) {
        vec.push_back(i);
    }
    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Vector ADD: " << duration << "sec" << endl;

    //searching Vector
    r = rand() % size;
    start = clock();

    vector<int>::iterator vFind;
    vFind = find(vec.begin(), vec.end(), r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Vector Search: " << duration << "sec" << endl;

    //delete from Vector
    r = rand() % size;
    start = clock();

    vector<int>::iterator new_end;
    new_end = remove(vec.begin(), vec.end(), r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Vector Remove: " << duration << "sec" << endl;
    cout << endl;
}

void testLinkedList(int size) {
    clock_t start;
    double duration;
    LinkedList<int> linked;
    int r;

    //inserting linked
    start = clock();
    for (int i = 0; i < size; i++) {
        linked.add(i);
    }
    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "LinkedList ADD: " << duration << "sec" << endl;

    //searching Linked
    r = rand() % size;
    start = clock();

    int linkedSearch = linked.find(r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "Linked List Search: " << duration << "sec" << endl;

    //delete from linked
    r = rand() % size;
    start = clock();

    linked.remove(r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "LinkedList Remove: " << duration << "sec" << endl;
    cout << endl;
}

void testBST(int size) {
    clock_t start;
    double duration;
    BST<int> bst;
    int r;

    vector<int> bstAddList;
    for (int i = 0; i < size; i++) {
        bstAddList.push_back(i);
    }
    random_shuffle(bstAddList.begin(), bstAddList.end());

    //inserting bst
    start = clock();
    for (int i : bstAddList)
    {
        bst.add(i);
    }
    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "BST ADD: " << duration << "sec" << endl;

    //Searching BST
    r = rand() % size;
    start = clock();

    int bstSearch = bst.find(r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "BST Search: " << duration << "sec" << endl;

    //delete from BST
    start = clock();

    bst.remove(r);

    duration = ((double)clock() - (double)start) / (double)CLOCKS_PER_SEC;
    cout << "BST Remove: " << duration << "sec" << endl;
    cout << endl;
}

int main()
{
    bool run = true;
    while (run) {
        int size = sizePrompt();

        testBST(size);
        testVector(size);
        testLinkedList(size);

        run = continuePrompt();
    }

}