#include "DoubleLinkedList.h"
#include "Service.h"
#include <iostream>
#include <chrono>

using namespace std;

void ShowDoubleLinkedList(DoubleLinkedList* list)
{
    Node* node = list->Head;

    cout << "Doublelinked list: " << endl;

    while (node != nullptr)
    {
        cout << node->Value << " ";

        node = node->Next;
    }

    cout << endl << "Length: " << list->Length << endl;
}

void TestOperations(DoubleLinkedList* list)
{
    for (int step = 20000; step <= 1000000; step += 20000)
    {
        RemoveList(list);
        int testValue = 10;
        RandomValues(list, step);
        auto start = chrono::steady_clock::now();
        //InsertBeforeOfElement(list, list->Length / 2, testValue);
        //InsertInBeginOfList(list, testValue);
        RemoveElement(list, list->Length / 2);
        auto end = chrono::steady_clock::now();

        cout << chrono::duration_cast<chrono::microseconds>(end - start).count()
            << ", " << step << endl;
    }
}