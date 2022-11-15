#include <iostream>

using namespace std;

void Task1()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += add * i; /* 0.0, 1.1000000000000001, 3.5200000000000005, 
						7.5130000000000017, 13.369400000000004,
                        21.421950000000010, 32.051316000000014, 45.692335700000022, 
						62.841046180000035, 84.0626*/
        cout << "Current sum value is " << sum << endl;
        add *= 1.1;
    }
    cout << "Total sum is " << sum << endl;
}

void Task2()
{
	double add = 1.0;
	double sum = 0.0;
	for (int i = 0; i < 1000; i++)
	{
		sum += add * i; //Значение на 777 итерации: 3.2624579394327844
		if (i % 3 == 0)
		{
			add *= 1.1;
		}
		else
		{
			add /= 3.0;
		}
		if (i == 777)
		{
			break;
		}
	}
	cout << "Total sum is " << sum << endl;
}

void Task3()
{
	const int size = 10;

	int array[size] = { 10, 23, -12, 1, 6, -4, -32, 56, 8, 3 };
	
	cout << "Main array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	
	for (int startIndex = 0; startIndex < size - 1; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; currentIndex++)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(array[startIndex], array[smallestIndex]);
	}
	
	cout << "\nSorted array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

void Task4()
{
	const int size = 12;

	double array[size] = { 10.2, -12.41, 54.93, 23.8, -31.99, -1.23, 84.2, 
		3.3, 6.12, -12.56, -92.32, 9.1 };
	
	cout << "Main array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	double searchingValue;
	int countElements = 0;
	
	cout << "\nEnter your value: ";
	cin >> searchingValue;
	for (int i = 0; i < size; i++)
	{
		if (array[i] >= searchingValue)
			countElements += 1;
	}
	
	cout << "Count of array elements which greater or equal than " << 
		searchingValue << ": " << countElements;
}

void Task5()
{
	const int size = 8;

	char value;
	char array[size] = {};
	
	cout << "Enter " << size << " chars in your array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> value;
		array[i] = value;
	}
	
	cout << "Your array is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	
	cout << "\nAll letters in your array: " << endl;
	for (int i = 0; i < size; i++)
	{
		if (isalpha(array[i]))
		{
			cout << array[i] << " ";
		}
	}
}

double GetPower(double base, int exponent)
{
	double baseSave = base;
	if (exponent == 0)
	{
		cout << 1;
	}
	for (int i = 1; i < exponent; i++)
	{
		base *= baseSave;
	}
	return base;
}

void Task6()
{
	double base;
	int exponent;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter value wich you want exponentiate: ";
		cin >> base;
		cout << "Enter value of exponent: ";
		cin >> exponent;
		cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
	}
}

void DemoGetPower(double base, int exponent)
{
	cout << "Enter value wich you want exponentiate : " << base << endl;
	cout << "Enter value of exponent: " << exponent << endl;
	cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void Task7()
{
	DemoGetPower(2.0, 5);
	DemoGetPower(3.0, 3);
	DemoGetPower(0.5, 2);
}

void RoundToTens(int& value)
{
	int divider = 10;
	cout << "For " << value << " rounded value is ";
	int remainder = value % divider;
	if (remainder < 5)
	{
		value = value / divider;
		value = value * divider;
	}
	else
	{
		value = value + (divider - remainder);
	}
	cout << value << endl;
}

void Task8()
{
	int value = 25;
	int value1 = 23;
	int value2 = 37;
	RoundToTens(value);
	RoundToTens(value1);
	RoundToTens(value2);
}

void Task9()
{
	int a = 5;
	int b = 4;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	double c = 13.5;
	cout << "Address of c: " << &c << endl;
	bool d = true;
	cout << "Address of d: " << &d << endl;
}

void Task10()
{
	const int size = 10;

	int a[size] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
	
	cout << "Size of int type: " << sizeof(int) << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << "Address of a[" << i << "]: " << &a[i] << endl;
	}
	
	cout << endl;
	
	cout << "Size of double type: " << sizeof(double) << endl;
	
	double b[size] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };
	
	for (int i = 0; i < size; i++)
	{
		cout << "Address of b[" << i << "]: " << &b[i] << endl;
	}
}

void Task11()
{
	int a = 5;
	int& b = a;
	cout << "Address of a: " << &a << endl;
	cout << "Address of b: " << &b << endl;
	cout << endl;
	b = 7;
	cout << "Value of a: " << a << endl;
}

void Foo(double a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void Task12()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	Foo(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void Foo1(double& a)
{
	cout << "Address of a in Foo(): " << &a << endl;
	cout << "Value of a in Foo(): " << a << endl;
	a = 15.0;
	cout << "New value of a in Foo(): " << a << endl;
}

void Task13()
{
	double a = 5.0;
	cout << "Address of a in main(): " << &a << endl;
	cout << "Value of a in main(): " << a << endl;
	cout << endl;
	Foo1(a);
	cout << endl;
	cout << "Value of a in main(): " << a << endl;
}

void Task14()
{
	int a = 5;
	int* pointer = &a;
	cout << "Address of a: " << &a << endl;
	cout << "Address in pointer: " << pointer << endl;
	cout << "Address of pointer: " << &pointer << endl;
	cout << endl;
	*pointer = 7;
	cout << "Value in a: " << a << endl;
	cout << "Value by pointer address: " << *pointer << endl;
}

void Foo2(double* a)
{
	cout << "Address in pointer: " << a << endl;
	cout << "Address of pointer: " << &a << endl;
	cout << "Value in pointer address: " << *a << endl;
	*a = 15.0;
	cout << "New value in pointer address: " << *a << endl;
}


void Task15()
{
	double value = 5.0;
	double* pointer = &value;
	cout << "Address of value in main(): " << &value << endl;
	cout << "Address in pointer in main(): " << pointer << endl;
	cout << "Address of pointer in main(): " << &pointer << endl;
	cout << "Value of a in main(): " << value << endl;
	cout << endl;
	Foo2(pointer);
	cout << endl;
	cout << "Value of a in main(): " << value << endl;
}

void Task16()
{
	const int size = 8;

	double* arrayDouble = new double[size]{ 1.0, 15.0, -8.2, -3.5, 12.6, 38.4, -0.5, 4.5 };
	
	cout << "Array of double: " << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << arrayDouble[i] << " ";
	}
	
	delete[] arrayDouble;
}

void Task17()
{
	const int size = 8;

	bool* arrayBool = new bool[size]{true, false, true, true, false, true, false, false};
	
	cout << "Array of bool: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arrayBool[i] << " ";
	}
	
	delete[] arrayBool;
}

void Task18()
{
	int n;
	cout << "Enter size of your char array: ";
	cin >> n;
	char* arrayChar = new char[n] {};
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a[" << i << "] = ";
		cin >> arrayChar[i];
		cout << endl;
	}
	
	cout << "Your char array is: " << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << arrayChar[i] << " ";
	}
	delete[] arrayChar;
}

void Sorting(double* array, int size)
{
	for (int startIndex = 0; startIndex < size - 1; startIndex++)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; currentIndex++)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(array[startIndex], array[smallestIndex]);
	}
	
	cout << "\nSorted array: " << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

void Task19()
{
	const int size = 10;

	double* arrayDouble = new double[size]{ 13.0, 1.0, - 10.2, - 2.5, 32.6, 
		18.4, 0.5, - 4.5, 16.7, 9.5 };
	
	cout << "Array of double: " << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << arrayDouble[i] << " ";
	}
	Sorting(arrayDouble, size);
	
	delete[] arrayDouble;
}

void Task20()
{
	const int size = 10;

	int customValue;
	cout << "Enter searching value: ";
	cin >> customValue;
	int* arrayInt = new int[size]{ 10, 12, - 1, - 6, 1, 38, 0, 2, 16, 2 };
	
	for (int i = 0; i < size; i++)
	{
		if (arrayInt[i] == customValue)
		{
			cout << "Index of searching value " << customValue << " is: " << i << endl;
		}
	}
	
	delete[] arrayInt;
}

void Task21()
{
	const int size = 15;

	int countElements = 0;
	char* arrayChar = new char[size]{'a', '2', '?', 'v', '*', '5', 'k', 'l', ')', 
		'e', '9', '3', 'm', 'z', '('};
	cout << "Char array is:" << endl;
	
	for (int i = 0; i < size; i++)
	{
		cout << arrayChar[i] << " ";
	}
	
	cout << "\nAll letters in your array: " << endl;
	
	for (int i = 0; i < size; i++)
	{
		if (isalpha(arrayChar[i]))
		{
			cout << arrayChar[i] << " ";
			countElements += 1;
		}
	}
	
	delete[] arrayChar;
	cout << "\nCount of letter in char array is: " << countElements;
}

int* MakeRandomArray(int arraySize)
{
	int* arrayInt = new int[arraySize] {};
	int number;
	srand(time(0));
	
	for (int i = 0; i < arraySize; i++)
	{
		number = rand() % 100 + 1;
		arrayInt[i] = number;
	}
	
	cout << "\nRandom array of " << arraySize << ":" << endl;
	
	for (int i = 0; i < arraySize; i++)
	{
		cout << arrayInt[i] << " ";
	}
	return arrayInt;
}

void Task22()
{
	int* arrayOfFive = MakeRandomArray(5);
	int* arrayOfEight = MakeRandomArray(8);
	int* arrayOfThirteen = MakeRandomArray(13);
	
	delete[] arrayOfFive;
	delete[] arrayOfEight;
	delete[] arrayOfThirteen;
}

int* ReadArray(int count)
{
	int* values = new int[count];
	
	for (int i = 0; i < count; i++)
	{
		cin >> values[i];
	}
	return values;
}

int CountPositiveValues(int* values, int count)
{
	int result = 0;
	
	for (int i = 0; i < count; i++)
	{
		if (values[i] > 0)
		{
			result++;
		}
	}
	return result;
}

void Task23()
{
	int count = 3;
	int* values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;

	delete[] values;

	count = 5;
	values = ReadArray(count);
	cout << "Count is: " << CountPositiveValues(values, count) << endl;

	delete[] values;
}

int main()
{
	cout << "1. Task 1.1.1.1. \n2. Task 1.1.1.2. \n3. Task 1.1.2.1."
		"\n4. Task 1.1.2.2. \n5. Task 1.1.2.3. \n6. Task 1.1.3.1 - 1.1.3.2."
		"\n7. Task 1.1.3.3. \n8. Task 1.1.3.4. \n9. Task 1.1.4.1."
		"\n10. Task 1.1.4.2. \n11. Task 1.1.4.3. \n12. Task 1.1.4.4."
		"\n13. Task 1.1.4.5. \n14. Task 1.1.4.6. \n15. Task 1.1.4.8."
		"\n16. Task 1.1.5.1. \n17. Task 1.1.5.2. \n18. Task 1.1.5.3."
		"\n19. Task 1.1.5.4. \n20. Task 1.1.5.5. \n21. Task 1.1.5.5."
		"\n22. Task 1.1.5.6. \n23. Task 1.1.5.7.\n";
	
	while (true)
	{
		int taskNumber;
		cout << "\nEnter task number: ";
		cin >> taskNumber;
		cout << "\n";

		switch (taskNumber)
		{
		case 1:
		{
			cout << "Task 1.1.1.1:\n";
			Task1();
			break;
		}
		case 2:
		{
			cout << "Task 1.1.1.2:\n";
			Task2();
			break;
		}	
		case 3:
		{
			cout << "Task 1.1.2.1:\n";
			Task3();
			break;
		}		
		case 4:
		{
			cout << "Task 1.1.2.2:\n";
			Task4();
			break;
		}
		case 5:
		{
			cout << "Task 1.1.2.3:\n";
			Task5();
			break;
		}		
		case 6:
		{
			cout << "Task 1.1.3.1 - 1.1.3.2:\n";
			Task6();
			break;
		}	
		case 7:
		{
			cout << "Task 1.1.3.3:\n";
			Task7();
			break;
		}	
		case 8:
		{
			cout << "Task 1.1.3.4:\n";
			Task8();
			break;
		}
		case 9:
		{
			cout << "Task 1.1.4.1:\n";
			Task9();
			break;
		}	
		case 10:
		{
			cout << "Task 1.1.4.2:\n";
			Task10();
			break;
		}	
		case 11:
		{
			cout << "Task 1.1.4.3:\n";
			Task11();
			break;
		}		
		case 12:
		{
			cout << "Task 1.1.4.4:\n";
			Task12();
			break;
		}		
		case 13:
		{
			cout << "Task 1.1.4.5:\n";
			Task13();
			break;
		}	
		case 14:
		{
			cout << "Task 1.1.4.6:\n";
			Task14();
			break;
		}		
		case 15:
		{
			cout << "Task 1.1.4.8:\n";
			Task15();
			break;
		}	
		case 16:
		{
			cout << "Task 1.1.5.1:\n";
			Task16();
			break;
		}	
		case 17:
		{
			cout << "Task 1.1.5.2:\n";
			Task17();
			break;
		}
		case 18:
		{
			cout << "Task 1.1.5.3:\n";
			Task18();
			break;
		}	
		case 19:
		{
			cout << "Task 1.1.5.4:\n";
			Task19();
			break;
		}	
		case 20:
		{
			cout << "Task 1.1.5.5:\n";
			Task20();
			break;
		}	
		case 21:
		{
			cout << "Task 1.1.5.5:\n";
			Task21();
			break;
		}
		case 22:
		{
			cout << "Task 1.1.5.6:\n";
			Task22();
			break;
		}	
		case 23:
		{
			cout << "Task 1.1.5.7:\n";
			Task23();
			break;
		}	
		default:
		{
			cout << "Enter correct value!";
			break;
		}
		}
	}
}



