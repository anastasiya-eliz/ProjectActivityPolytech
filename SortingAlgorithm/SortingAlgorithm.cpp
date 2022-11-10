// C++ implementation not of Shell Sort but more coool
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
 
void insertionSort(int *, int); // прототип функции сортировки вставками
 
int main(int argc, char* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    cout << "Введите размер массива: ";
    int size_array; // длинна массива
    cin >> size_array;
 
    int *sorted_array = new int [size_array]; // одномерный динамический массив
    for (int counter = 0; counter < size_array; counter++)
    {
        sorted_array[counter] = rand() % 100; // заполняем массив случайными числами
        cout << setw(2) << sorted_array[counter] << "  "; // вывод массива на экран
    }
    cout << "n";
 
    insertionSort(sorted_array, size_array); // вызов функции сортировки вставками
 
    for (int counter = 0; counter < size_array; counter++)
    {
        cout << setw(2) << sorted_array[counter] << "  "; // печать отсортированного массива
    }
    cout << "n";
    delete [] sorted_array; // высвобождаем память
    system("pause");
    return 0;
}
 
void insertionSort(int *arrayPtr, int length) // сортировка вставками
{
    int temp, // временная переменная для хранения значения элемента сортируемого массива
        item; // индекс предыдущего элемента
    for (int counter = 1; counter < length; counter++)
    {
        temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter-1; // запоминаем индекс предыдущего элемента массива
        while(item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
            arrayPtr[item] = temp;
            item--;
        }
    }
}
