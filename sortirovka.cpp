#include <iostream>

using namespace std;

void selection_sort(int* array, int size) {
    int tmp; // переменная для перестановки местами элементов массива
    for (int i = 0; i < size - 1; ++i) {
        int min_pos = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min_pos]) { // ищем минимальный элемент в "хвосте" массива
                min_pos = j;
            }
        }
        if (min_pos != i) { // если минимальный не на позиции i, то меняем местами
            tmp = array[i];
            array[i] = array[min_pos];
            array[min_pos] = tmp;
        }
    }
}

int main() {
    int N; // количество элементов массива
    cout << "Введите количество элементов: ";
    cin >> N; // считываем количество элементов
    int* array = new int[N];
    cout << "Введите элементы: ";
    for (int i = 0; i < N; ++i) {
        cin >> array[i]; // помещаем считанное число в массив
    }
    selection_sort(array, N); 
    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; ++i) {
        cout << array[i] << ' ';
    }
    return 0;
}