#pragma once

/// @brief Структура динамического массива.
struct DynamicArray
{
    int* Array;
    int Length;
    int Capacity;
};

/// @brief Создание динамического массива.
/// @param dynamicArray Динамический массив.
void CreateDynamicArray(DynamicArray* dynamicArray);

/// @brief Добавление нового элемента в конец динамического массива.
/// @param dynamicArray Динамический массив.
/// @param element Элемент.
void AddNewElement(DynamicArray* dynamicArray, int element);

/// @brief Удаление элемента из динамического массива по индексу.
/// @param dynamicArray Динамический масиив.
/// @param index Индекс элемента.
/// @param flag Флаг для выслеживания ошибки.
bool RemoveElement(DynamicArray* dynamicArray, int index);

/// @brief Добавление элемента в динамический массив по индексу.
/// @param dynamicArray Динамический массив.
/// @param element Элемент.
/// @param index Индекс элемента.
void InsertElement(DynamicArray* dynamicArray, int element, int index);

/// @brief Сортировка массива по возрастанию.
/// @param dynamicArray Динамический массив.
void SortArray(DynamicArray* dynamicArray);

/// @brief Линейный поиск элемента.
/// @param dynamicArray Динамический массив.
/// @param element Элемент.
/// @return Возвращение индекса найденного элемента.
int LinearSearch(DynamicArray* dynamicArray, int element);

/// @brief Бинарный поиск элемента.
/// @param dynamicArray Динамический массив.
/// @param element Элемент.
/// @param middle Индекс найденного элемента.
/// @param flag Флаг для выслеживания индекса.
int BinarySearch(DynamicArray* dynamicArray, int element);

/// @brief Изменение вместимости массива.
/// @param dynamicArray Динамический массив.
void ResizeArray(DynamicArray* dynamicArray);

/// @brief Запись слуйчайных элементов в динамический массив.
/// @param dynamicArray Динамический массив.
/// @param length Длинна массива.
void GetRandomArray(DynamicArray* dynamicArray, int length);



void Show(DynamicArray* dynamicArray);