#include "TreeApp.h"
#include <iostream>

using namespace std;

void TreeApp::showMenu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить элемент\n";
    cout << "2. Удалить элемент\n";
    cout << "3. Поиск элемента\n";
    cout << "4. Вывод дерева\n";
    cout << "5. Подсчитать количество узлов\n";
    cout << "6. Очистить дерево\n";
    cout << "7. Выход\n";
    cout << "Выбeрите действие: ";
}

void TreeApp::run() {
    int choice, value;
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите значение для добавления: ";
            cin >> value;
            tree.add(value);
            break;
        case 2:
            cout << "Введите значение для удаления: ";
            cin >> value;
            tree.remove(value);
            break;
        case 3:
            cout << "Введите значение для поиска: ";
            cin >> value;
            tree.search(value);
            break;
        case 4:
            tree.display();
            break;
        case 5:
            cout << "Количество узлов в дереве: " << tree.countNodes() << endl;
            break;
        case 6:
            tree.clear();
            cout << "Дерево очищено.\n";
            break;
        case 7:
            cout << "Выход из программы.\n";
            return;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    }
}
