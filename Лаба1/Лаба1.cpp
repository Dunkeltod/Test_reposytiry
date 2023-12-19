#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Ввод размеров матрицы
    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;

    // Проверка, что количество строк не равно 0
    while (n <= 0) {
        cout << "Количество строк должно быть больше 0. Введите количество строк еще раз: ";
        cin >> n;
    }

    cout << "Введите количество столбцов: ";
    cin >> m;

    // Проверка, что количество столбцов не равно 0
    while (m <= 0) {
        cout << "Количество столбцов должно быть больше 0. Введите количество столбцов еще раз: ";
        cin >> m;
    }

    // Создание и ввод матрицы
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[m];
        for (int j = 0; j < m; j++) {
            cout << "Элемент [" << i << ", " << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "Матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(10) << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    // Инициализация массива для хранения наличия нулевых элементов в столбцах
    bool* nonzeroColumns = new bool[m];
    for (int i = 0; i < m; i++) {
        nonzeroColumns[i] = false;
    }

    // Проверка наличия нулевых элементов в каждом столбце
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                nonzeroColumns[j] = true;
                break;
            }
        }
    }

    // Инициализация переменной для хранения суммы элементов
    double sum = 0;

    // Суммирование элементов в столбцах с хотя бы одним нулевым элементом
    for (int i = 0; i < m; i++) {
        if (nonzeroColumns[i]) {
            for (int j = 0; j < n; j++) {
                sum += matrix[j][i];
            }
        }
    }

    // Вывод суммы
    cout << "Сумма элементов в столбцах с хотя бы одним нулевым элементом: " << sum << endl;

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] nonzeroColumns;

    return 0;
}