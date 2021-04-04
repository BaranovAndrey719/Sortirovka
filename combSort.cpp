#include <iostream>

using namespace std;

void comb_sort(int* left, int* right) {
    int size = right - left;
    if (size <= 1) 
        return;
    double k = 1.2473309;
    int step = size - 1;
    while (step > 1) {
        for (int* l = left; l + step < right; ++l) {
            if (*l > *(l + step))
                swap(*l, *(l + step));
        }
        step /= k;
    }

    bool flag = true;
    while (flag) {
        flag = false;
        for (int* l = left; l + 1 < right; ++l) {
            if (*l > *(l + 1)) {
                swap(*l, *(l + 1));
                flag = true;
            }
        }
    }

}

int main() {
    int N; // количество элементов массива
    cout << "Введите количество элементов: ";
    cin >> N; // считываем количество элементов
    int* array = new int[N];
    cout << "Введите элементы\n";
    for (int i = 0; i < N; ++i) {
        cin >> array[i]; // помещаем считанное число в массив
    }
    comb_sort(array, array + N); 
    cout << "Отсортированный массив: ";
    for (int i = 0; i < N; ++i) {
        cout << array[i] << ' ';
    }
    return 0;
}