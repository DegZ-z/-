#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {
    int N, M, i, j;
    int min_val, max_val, temp;
    char choice_nm, mode, choice_range;
    int repeat;

    srand((unsigned)time(0));

    do {
        // Выбор размеров матрицы N x M (динамический двумерный массив)
        cout << "\nChoose mode for matrix size N x M:\n";
        cout << "1 - Default (3 x 4)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        choice_nm = (char)_getch();
        cout << choice_nm << "\n";

        if (choice_nm == '2') {
            cout << "Enter number of rows N: ";
            cin >> N;
            cout << "Enter number of columns M: ";
            cin >> M;
            if (N <= 0) N = 3;
            if (M <= 0) M = 4;
        }
        else {
            N = 3;
            M = 4;
        }

        // ВЫДЕЛЕНИЕ ДИНАМИЧЕСКОЙ ПАМЯТИ
        // Выделение массива указателей на строки
      int** a = new int* [N];
            for (i = 0; i < N; i++) {
            // Выделение памяти под каждую строку
            a[i] = new int[M];
       }
        // ВЫДЕЛЕНИЕ ПАМЯТИ
// Выделяем память под N указателей на строки. (int**) — приведение типа, обязательное в C++
       // int a = (int)malloc(N * sizeof(int*));

       // for (i = 0; i < N; i++) {
            // Выделяем память под M целых чисел для каждой строки
          //  a[i] = (int*)malloc(M * sizeof(int));
       // }
        // Выбор способа заполнения
        cout << "\nChoose fill mode:\n";
        cout << "1 - Random numbers (default)\n";
        cout << "2 - Enter manually\n";
        cout << "Choice [1/2] (default is 1): ";

        mode = (char)_getch();
        cout << mode << "\n\n";

        if (mode == '2') {
            cout << "Enter " << N * M << " elements of matrix (" << N << "x" << M << "):\n";
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    cin >> a[i][j];
                }
            }
        }
        else {
            // Выбор диапазона для случайных чисел
            cout << "Choose range for random numbers:\n";
            cout << "1 - Default (-20..20)\n";
            cout << "2 - Enter manually\n";
            cout << "Choice [1/2] (default is 1): ";

            choice_range = (char)_getch();
            cout << choice_range << "\n";

            if (choice_range == '2') {
                cout << "Enter min and max values (e.g. -20 20): ";
                cin >> min_val >> max_val;
                if (min_val > max_val) {
                    temp = min_val;
                    min_val = max_val;
                    max_val = temp;
                }
            }
            else {
                min_val = -20;
                max_val = 20;
            }

            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    a[i][j] = min_val + rand() % (max_val - min_val + 1);
                }
            }
        }

        // Вывод исходной матрицы
        cout << "\nOriginal Matrix (" << N << "x" << M << "):\n";
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

        // Упорядочивание строк по возрастанию их первых элементов (пузырьковая сортировка)
        cout << "Sorting rows by their first elements (ascending)...\n";
        for (i = 0; i < N - 1; i++) {
            for (j = 0; j < N - 1 - i; j++) {
                // Сравниваем первые элементы соседних строк
                if (a[j][0] > a[j + 1][0]) {
                    // Меняем местами указатели на строки целиком
                    int* temp_row = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp_row;
                }
            }
        }

        // Вывод отсортированной матрицы
        cout << "\n==================================================\n";
        cout << "Sorted Matrix (" << N << "x" << M << "):\n";
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cout << a[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "==================================================\n";
        // ОЧИСТКА ДИНАМИЧЕСКОЙ ПАМЯТИ
        // Освобождение памяти строк
        for (i = 0; i < N; i++) {
            delete[] a[i];
        }
        // Освобождение массива указателей
        delete[] a;

        cout << "\nDo you want to continue? [y/n]: ";
        repeat = _getch();
        cout << "\n";

    } while (repeat == 'y');

    return 0;
}