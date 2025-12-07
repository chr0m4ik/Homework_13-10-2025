#include <iostream>

int* createArray(int size) {
    return new int[size];
}

void fillArray(int* arr, int size) {
    std::cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "Элемент [" << i << "]: ";
        std::cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* insertElement(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Ошибка: неверный индекс!\n";
        return arr;
    }

    int* newArr = new int[size + 1];

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    newArr[index] = value;

    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    size++;

    delete[] arr;

    return newArr;
}

int* deleteElement(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Ошибка: неверный индекс!\n";
        return arr;
    }

    if (size == 1) {
        delete[] arr;
        size = 0;
        return nullptr;
    }

    int* newArr = new int[size - 1];

    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }

    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }

    size--;

    delete[] arr;

    return newArr;
}

void deleteArray(int* arr) {
    delete[] arr;
}

void demonstrateFunctions() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = createArray(size);

    fillArray(arr, size);

    std::cout << "\nИсходный массив:\n";
    printArray(arr, size);

    std::cout << "\n--- Демонстрация вставки ---\n";
    int insertIndex, insertValue;
    std::cout << "Введите индекс для вставки: ";
    std::cin >> insertIndex;
    std::cout << "Введите значение для вставки: ";
    std::cin >> insertValue;

    arr = insertElement(arr, size, insertIndex, insertValue);
    std::cout << "После вставки:\n";
    printArray(arr, size);

    std::cout << "\n--- Демонстрация удаления ---\n";
    int deleteIndex;
    std::cout << "Введите индекс для удаления: ";
    std::cin >> deleteIndex;

    arr = deleteElement(arr, size, deleteIndex);
    std::cout << "После удаления:\n";
    printArray(arr, size);

    deleteArray(arr);
}

int main() {
    demonstrateFunctions();
    return 0;
}