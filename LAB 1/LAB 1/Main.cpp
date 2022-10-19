#include <iostream>

using namespace std;

struct DynamicArray
{
    int* array;
    int length;
    int capacity;
};

void CreateDynamicArray(DynamicArray* dynamicArray)
{
    int capacity = 8;

    dynamicArray->capacity = capacity;
    dynamicArray->length = 0;
    dynamicArray->array = new int[dynamicArray->capacity];
}

void AddNewElement(DynamicArray* dynamicArray, int element)
{
    dynamicArray->length++;

    //if (dynamicArray->length >= dynamicArray->capacity)
    //{
    //    ResizeArray(dynamicArray);
    //}

    dynamicArray->array[dynamicArray->length - 1] = element;
}

void RemoveElement(DynamicArray* dynamicArray, int index)
{
    if (index > dynamicArray->length - 1 || index < 0)
    {
        cout << "Incorrect value entered!" << endl;
        return;
    }
    else
    {
        for (int i = index; i < dynamicArray->length - 1; i++)
        {
            dynamicArray->array[i] = dynamicArray->array[i + 1];
        }

        dynamicArray->length--;
    }
}

void InsertElement(DynamicArray* dynamicArray, int element, int index)
{
    dynamicArray->length++;

    //if (dynamicArray->length >= dynamicArray->capacity)
    //{
    //    ResizeArray(dynamicArray);
    //}

    for (int i = dynamicArray->length - 1; i > index; i--)
    {
        dynamicArray->array[i] = dynamicArray->array[i - 1];
    }

    dynamicArray->array[index] = element;
}

void SortArray(DynamicArray* dynamicArray)
{
    for (int startIndex = 0; startIndex < dynamicArray->length - 1; startIndex++)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < dynamicArray->length; currentIndex++)
        {
            if (dynamicArray->array[currentIndex] < dynamicArray->array[smallestIndex])
                smallestIndex = currentIndex;
        }
        swap(dynamicArray->array[startIndex], dynamicArray->array[smallestIndex]);
    }
}

void LinearSearch(DynamicArray* dynamicArray, int element)
{
    bool flag = false;

    for (int i = 0; i < dynamicArray->length; i++)
    {
        if (dynamicArray->array[i] == element)
        {
            cout << "Index of this element: " << i << endl;
            flag = true;
            return;
        }
    }
    if (flag == false)
    {
        cout << "There is no such value in the array." << endl;
    }
}

int BinarySearch(DynamicArray* dynamicArray, int element)
{
    int first = 0;
    int last = dynamicArray->length - 1;
    int middle;

    while (first < last)
    {
        middle = (last + first) / 2;

        if (element <= dynamicArray->array[middle])
        {
            last = middle;
        }
        else
        {
            first = middle + 1;
        }
    }
    return (first == dynamicArray->length || dynamicArray->array[first] != element)
        ? -1 : first;
}

//void ResizeArray(DynamicArray* dynamicArray)
//{
//    dynamicArray->capacity += dynamicArray->capacity;
//
//    int* tempArray = new int[dynamicArray->capacity];
//
//    for (int i = 0; i < dynamicArray->length; i++)
//    {
//        tempArray[i] = dynamicArray->array[i];
//    }
//    
//    delete[] dynamicArray->array;
//    dynamicArray->array = tempArray;
//}

void GetRandomArray(DynamicArray* dynamicArray, int length)
{
    srand(time(0));

    for (int i = 0; i < length; i++)
    {
        AddNewElement(dynamicArray, rand());
    }
}

void ShowDynamicArray(DynamicArray* dynamicArray)
{
    for (int i = 0; i < dynamicArray->length; i++)
    {
        cout << dynamicArray->array[i] << " ";
    }

    cout << endl;
}

void ShowHowManyCapacityAndLength(DynamicArray* dynamicArray)
{
    cout << dynamicArray->capacity << endl;

    cout << dynamicArray->length << endl;
}

int main()
{
    DynamicArray* array = new DynamicArray;

    cout << "1. Create dynamic array. \n2. Initialize an dynamic array with random numbers. \n"
        "3. Add new element in dynamic array.\n4. Remove element of dynamic array.\n"
        "5. Insert element at index into dynamc array.\n6. Sort dynamic array.\n"
        "7. Linear Search.\n8. Binary search.\n"
        "9. Show dynamic array.\n" << endl;
    
    while (true)
    {
        int taskNumber;
        cout << "Enter number of action: ";
        cin >> taskNumber;
        cout << endl;

        switch (taskNumber)
        {
        case 1:
        {
            CreateDynamicArray(array);
            break;
        }  
        case 2:
        {
            int length;
            cout << "Enter length of your dynamic array: ";
            cin >> length;
            GetRandomArray(array, length);
            break;
        } 
        case 3:
        {
            int element;
            cout << "Enter which element you want to add: ";
            cin >> element;
            AddNewElement(array, element);
            break;
        }    
        case 4:
        {
            int index;
            cout << "Enter index which you want to remove: ";
            cin >> index;
            RemoveElement(array, index);
            break;
        }   
        case 5:
        {
            int index;
            int element;
            cout << "Enter the index of the element where you want to insert the element: ";
            cin >> index;
            cout << "Enter which element you want to add: ";
            cin >> element;
            InsertElement(array, element, index);
            break;
        }    
        case 6:
        {
            SortArray(array);
            break;
        }    
        case 7:
        {
            int element;
            cout << "Enter element which you want to find: ";
            cin >> element;
            LinearSearch(array, element);
            break;
        }    
        case 8:
        {
            int element;
            cout << "Enter element which you want to find: ";
            cin >> element;
            BinarySearch(array, element);
            break;
        }  
        case 9:
        {
            ShowDynamicArray(array);
            break;
        }
        case 10:
        {
            ShowHowManyCapacityAndLength(array);
            break;
        }
        default:
        {
            cout << "Enter correct value! \n";
            break;
        }
        }
    }
    delete array;
}

