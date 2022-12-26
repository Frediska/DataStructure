#pragma once

//TODO: comments

/// @brief Реализация структуры по представлению узла списка.
struct Node
{
	/// @brief Значение узла списка.
	int Value;
	/// @brief Указетль следующего узла списка.
	Node* Next;
	/// @brief Указатель предыдущий узла списка.
	Node* Previous;
};

/// @brief Реализация структуры по представлению двусвязного списка.
struct DoubleLinkedList
{
	/// @brief Длина двусвязного списка.
	int Length;
	/// @brief Указатель начала двусвязного спсика.
	Node* Head;
	/// @brief Указатель конца двусвзяного спсика.
	Node* Tail;
	
	void List()
	{
		Length = 0;
		Head = nullptr;
		Tail = nullptr;
	}
};

/// @brief Инициализация двусвязного списка.
/// @param list Двусвязный список.
void InitDoubleLinkedList(DoubleLinkedList* list);

/// @brief Добавить новый элемент в двусвязный список.
/// @param list Двусвязный список.
/// @param element Добавляемый элемент.
void AddNewElement(DoubleLinkedList* list, int element);

/// @brief Удалить элементы из двусвязного списка по его индексу.
/// @param list Двусвязный список.
/// @param index Индекс удаляемого элемента.
/// @return Возвращение true или false.
bool RemoveElement(DoubleLinkedList* list, int index);

/// @brief Вставка элемента в начало списка.
/// @param list Двусвязный список.
/// @param element Вставляемый элемент.
void InsertInBeginOfList(DoubleLinkedList* list, int element);

/// @brief Вставка элемента после другого элемента.
/// @param list Двусвязный список.
/// @param index Индекс элемента, после которого вставляется новый.
/// @param element Вставляемый элемент
/// @return Возвращение true или false.
bool InsertAfterOfElement(DoubleLinkedList* list, int index, int element);

/// @brief Вставка элемента перед другим элементом.
/// @param list Двусвязный список.
/// @param index Индекс элемента, перед которым вставляется другой.
/// @param element Вставляемый элемент.
/// @return Возвращение true или false.
bool InsertBeforeOfElement(DoubleLinkedList* list, int index, int element);

/// @brief Перестановка элементов, используется для сортировки.
/// @param list Двусвязный список.
/// @param first Первый узел.
/// @param second Второй узел.
void SwapElements(DoubleLinkedList* list, Node* first, Node* second);

/// @brief Сортировка двусвязного списка вставками.
/// @param list Двусвязный список.
void InsertionSort(DoubleLinkedList* list);

/// @brief Линейный поиск элемента в двусвязном списке.
/// @param list Двусвязный список.
/// @param element Искомый элемент.
/// @return Возвращение индекса искомого элемента или -1, если элемент не найден.
int LinearSearch(DoubleLinkedList* list, int element);

/// @brief Очистка дусвязного списка.
/// @param list Двусвязный список.
void RemoveList(DoubleLinkedList* list);

/// @brief Заполнение списка случайными значениями.
/// @param list Двусвязный список.
/// @param count Количество значений.
void RandomValues(DoubleLinkedList* list, int count);




