//ЗАДАНИЕ ЗА 13-10-2025

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int WAGONS = 18;
const int SEATS = 36;

void initializeEmpty(int train[WAGONS][SEATS]) {
    for (int i = 0; i < WAGONS; i++) {
        for (int j = 0; j < SEATS; j++) {
            train[i][j] = 0;
        }
    }
    std::cout << "Все места освобождены.\n";
}

void initializeRandom(int train[WAGONS][SEATS]) {
    srand(time(0));
    for (int i = 0; i < WAGONS; i++) {
        for (int j = 0; j < SEATS; j++) {
            train[i][j] = rand() % 2;
        }
    }
    std::cout << "Поезд заполнен случайным образом.\n";
}

void displaySeats(int train[WAGONS][SEATS]) {
    std::cout << "\n=== ТАБЛИЦА МЕСТ В ПОЕЗДЕ ===\n";
    std::cout << "Вагон\\Место ";

    for (int j = 0; j < SEATS; j++) {
        std::cout << std::setw(3) << j + 1;
    }
    std::cout << "\n";

    for (int i = 0; i < WAGONS; i++) {
        std::cout << "Вагон " << std::setw(2) << i + 1 << ":   ";
        for (int j = 0; j < SEATS; j++) {
            std::cout << std::setw(3) << train[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "0 - свободно, 1 - занято\n";
}

void reserveSeat(int train[WAGONS][SEATS]) {
    int wagon, seat;

    std::cout << "Введите номер вагона (1-" << WAGONS << "): ";
    std::cin >> wagon;

    std::cout << "Введите номер места (1-" << SEATS << "): ";
    std::cin >> seat;

    if (wagon < 1 || wagon > WAGONS || seat < 1 || seat > SEATS) {
        std::cout << "Ошибка: неверный номер вагона или места!\n";
        return;
    }

    if (train[wagon - 1][seat - 1] == 1) {
        std::cout << "Место уже занято!\n";
    }
    else {
        train[wagon - 1][seat - 1] = 1;
        std::cout << "Место успешно забронировано!\n";
    }
}

void freeSeat(int train[WAGONS][SEATS]) {
    int wagon, seat;

    std::cout << "Введите номер вагона (1-" << WAGONS << "): ";
    std::cin >> wagon;

    std::cout << "Введите номер места (1-" << SEATS << "): ";
    std::cin >> seat;

    if (wagon < 1 || wagon > WAGONS || seat < 1 || seat > SEATS) {
        std::cout << "Ошибка: неверный номер вагона или места!\n";
        return;
    }

    if (train[wagon - 1][seat - 1] == 0) {
        std::cout << "Место уже свободно!\n";
    }
    else {
        train[wagon - 1][seat - 1] = 0;
        std::cout << "Место успешно освобождено!\n";
    }
}

void countFreeInWagon(int train[WAGONS][SEATS]) {
    int wagon;

    std::cout << "Введите номер вагона (1-" << WAGONS << "): ";
    std::cin >> wagon;

    if (wagon < 1 || wagon > WAGONS) {
        std::cout << "Ошибка: неверный номер вагона!\n";
        return;
    }

    int freeCount = 0;
    for (int j = 0; j < SEATS; j++) {
        if (train[wagon - 1][j] == 0) {
            freeCount++;
        }
    }

    std::cout << "В вагоне " << wagon << " свободно " << freeCount
        << " мест из " << SEATS << "\n";
}

void countTotalFree(int train[WAGONS][SEATS]) {
    int totalFree = 0;

    for (int i = 0; i < WAGONS; i++) {
        for (int j = 0; j < SEATS; j++) {
            if (train[i][j] == 0) {
                totalFree++;
            }
        }
    }

    int totalSeats = WAGONS * SEATS;
    std::cout << "Всего свободно " << totalFree << " мест из "
        << totalSeats << "\n";
}

void showMenu(int train[WAGONS][SEATS]) {
    int choice;

    do {
        std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ ===\n";
        std::cout << "1. Показать таблицу мест\n";
        std::cout << "2. Забронировать место\n";
        std::cout << "3. Освободить место\n";
        std::cout << "4. Посчитать свободные места в вагоне\n";
        std::cout << "5. Посчитать общее количество свободных мест\n";
        std::cout << "0. Выйти из программы\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            displaySeats(train);
            break;
        case 2:
            reserveSeat(train);
            break;
        case 3:
            freeSeat(train);
            break;
        case 4:
            countFreeInWagon(train);
            break;
        case 5:
            countTotalFree(train);
            break;
        case 0:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    int train[WAGONS][SEATS];
    int initChoice;

    setlocale(LC_ALL, "Russian");

    std::cout << "=== СИСТЕМА УПРАВЛЕНИЯ БРОНИРОВАНИЕМ МЕСТ ===\n";
    std::cout << "Поезд имеет " << WAGONS << " вагонов по " << SEATS << " мест в каждом\n";
    std::cout << "\nВыберите режим инициализации:\n";
    std::cout << "1. Заполнить случайным образом\n";
    std::cout << "2. Оставить все места пустыми\n";
    std::cout << "Ваш выбор: ";
    std::cin >> initChoice;

    switch (initChoice) {
    case 1:
        initializeRandom(train);
        break;
    case 2:
        initializeEmpty(train);
        break;
    default:
        std::cout << "Неверный выбор. Инициализирую пустым поездом.\n";
        initializeEmpty(train);
    }

    showMenu(train);

    return 0;
}