#include"CubeRubik.h"
#include<iostream>

using namespace std;

Cube::Cube() {
        faces = {
            {'0', '0', '0', '0', '0', '0', '0', '0', '0'}, // Верхняя грань (белая)
            {'0', '0', '0', '0', '0', '0', '0', '0', '0'}, // Нижняя грань (желтая)
            {'0', '0', '0', '0', '0', '0', '0', '0', '0'}, // Левая грань (зеленая)
            {'0', '0', '0', '0', '0', '0', '0', '0', '0'}, // Правая грань (синяя)
            {'0', '0', '0', '0', '0', '0', '0', '0', '0'}, // Передняя грань (красная)
            {'0', '0', '0', '0', '0', '0', '0', '0', '0'}  // Задняя грань (оранжевая)
        };
}

    

    void Cube::print() {
        // Вывод кубика
        const char* faceNames[6] = { "U", "D", "L", "R", "F", "B" };
        cout << "your cube\n";
        for (int i = 0; i < 6; ++i) {
            cout << faceNames[i] << ": ";
            for (int j = 0; j < 9; ++j) {
                if (j==0 || j == 3 || j == 6) {
                    cout << "\n";
                }
                cout << faces[i][j];
            }
            
            cout << endl;
        }
    }

    bool Cube::checkRows() {
        for (const auto& row : faces) {
            char firstChar = row[0];
            for (const auto& ch : row) {
                if (ch != firstChar) {
                    cout << "cube is not solved\n"; // Если есть различия, возвращаем false
                    return false;
                }
            }
        }
        cout << "success! cube is solved\n"; // Все строки имеют одинаковые символы
        return true;
    }

    void Cube::changeFace() {
        cout << "Indicate which face you want to rotate (enter the letter corresponding to the name of the face)\n";
        cout << "Upper - 1\n Deep - 2\n Left - 3\n Right - 4\n Front - 5\n Back - 6\n";

        int faceName;
        cin >> faceName;
        faceName = --faceName;

        cout << "Enter 1 if you want to rotate the face clockwise or 0 if counterclockwise\n";
        int turn;
        cin >> turn;

        char buf;

        if (turn == 1) {
            vector<char> face = { faces[faceName][6], faces[faceName][3], faces[faceName][0], faces[faceName][7],
           faces[faceName][4], faces[faceName][1], faces[faceName][8], faces[faceName][5], faces[faceName][2] };

            faces[faceName] = face;

            vector<int> round;
            if (faceName == 0 or faceName == 1) {
                round = { 5, 3, 4, 2 };
            }
            else if (faceName == 2) {
                round = { 0, 4, 1, 5 };
            }
            else if (faceName == 3) {
                round = { 0, 5, 1, 4 };
            }
            else if (faceName == 4) {
                round = { 0, 3, 1, 2 };
            }
            else if (faceName == 5) {
                round = { 0, 2, 1, 3 };
            }

            buf = faces[round[0]][6];
            faces[round[0]][6] = faces[round[1]][0];
            faces[round[1]][0] = buf;

            buf = faces[round[0]][7];
            faces[round[0]][7] = faces[round[1]][3];
            faces[round[1]][3] = buf;

            buf = faces[round[0]][8];
            faces[round[0]][8] = faces[round[1]][6];
            faces[round[1]][6] = buf;



            buf = faces[round[0]][6];
            faces[round[0]][6] = faces[round[2]][0];
            faces[round[2]][0] = buf;

            buf = faces[round[0]][7];
            faces[round[0]][7] = faces[round[2]][1];
            faces[round[2]][1] = buf;

            buf = faces[round[0]][8];
            faces[round[0]][8] = faces[round[2]][2];
            faces[round[2]][2] = buf;



            buf = faces[round[0]][6];
            faces[round[0]][6] = faces[round[3]][2];
            faces[round[3]][2] = buf;

            buf = faces[round[0]][7];
            faces[round[0]][7] = faces[round[3]][5];
            faces[round[3]][5] = buf;

            buf = faces[round[0]][8];
            faces[round[0]][8] = faces[round[3]][8];
            faces[round[3]][8] = buf;
        }
        else if(turn == 0){
            vector<char> face = { faces[faceName][2], faces[faceName][5], faces[faceName][8], faces[faceName][1],
           faces[faceName][4], faces[faceName][7], faces[faceName][0], faces[faceName][3], faces[faceName][6] };

            faces[faceName] = face;

            vector<int> round;
            if (faceName == 0 or faceName == 1) {
                round = { 5, 2, 4, 3 };
            }
            else if (faceName == 2) {
                round = { 0, 5, 1, 4 };
            }
            else if (faceName == 3) {
                round = { 0, 4, 1, 5 };
            }
            else if (faceName == 4) {
                round = { 0, 2, 1, 3 };
            }
            else if (faceName == 5) {
                round = { 0, 3, 1, 2 };
            }

            buf = faces[round[0]][6];
            faces[round[0]][6] = faces[round[1]][2];
            faces[round[1]][2] = buf;

            buf = faces[round[0]][7];
            faces[round[0]][7] = faces[round[1]][5];
            faces[round[1]][5] = buf;

            buf = faces[round[0]][8];
            faces[round[0]][8] = faces[round[1]][8];
            faces[round[1]][8] = buf;



            buf = faces[round[0]][6];
            faces[round[0]][6] = faces[round[2]][0];
            faces[round[2]][0] = buf;

            buf = faces[round[0]][7];
            faces[round[0]][7] = faces[round[2]][1];
            faces[round[2]][1] = buf;

            buf = faces[round[0]][8];
            faces[round[0]][8] = faces[round[2]][2];
            faces[round[2]][2] = buf;



            buf = faces[round[0]][6];
            faces[round[0]][6] = faces[round[3]][0];
            faces[round[3]][0] = buf;

            buf = faces[round[0]][7];
            faces[round[0]][7] = faces[round[3]][3];
            faces[round[3]][3] = buf;

            buf = faces[round[0]][8];
            faces[round[0]][8] = faces[round[3]][6];
            faces[round[3]][6] = buf;
        }
        else {
            cout << "data entered incorrectly \n";
        }
    }


//заполнение кубика данными из файла
void Cube::loadFromFile(const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    for (int i = 0; i < 6; ++i) {
        string colors;
        file >> colors;
        faces[i] = vector<char>(colors.begin(), colors.end());
    }
    file.close();
}

void Cube::randomize()
{
    // Символы для заполнения
    vector<char> symbols = { 'W', 'Y', 'G', 'B', 'R', 'O' };

    // Создаем вектор для хранения символов
    vector<char> filledSymbols;

    // Каждый символ повторяется 9 раз
    for (char symbol : symbols) {
        for (int i = 0; i < 9; ++i) {
            filledSymbols.push_back(symbol);
        }
    }

    // Перемешиваем символы
    random_device rd;
    mt19937 g(rd());
    shuffle(filledSymbols.begin(), filledSymbols.end(), g);

    // Заполняем матрицу
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 9; ++j) {
            faces[i][j] = filledSymbols[i * 9 + j];
        }
    }
    // Проверяем, что б центральные квадратики на грани были нужного цвена
    char buf;
    //запускаем цикл, который перебирает все варианты символов для заполнения
    for (int i = 0; i < 6; ++i) {
        //если центральный символ грани не совпадает с символом для данной грани
        if (faces[i][4] != symbols[i]) {
            //запускаем циклы, которые перебирают все элементы кубика
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 9; ++k) {
                    //когда находим нужный цвет для данной грани
                    if (faces[j][k] == symbols[i]) {
                        //ставим нужный цвет в центр грани, меняя их местами
                        buf = faces[i][4];
                        faces[i][4] = faces[j][k];
                        faces[j][k] = buf;
                    }
                }
            }
        }
    }
}


/*
int main() {

    int a;
    cout << "enter number\n1 - create a random cube \n2 - load cube from file\n";
    cin >> a;
    if (a == 1 || a == 2) {
        Cube cube;
        if (a == 1) {
            cube.randomize();
        }
        else  {
            cube.loadFromFile("C:\\PPOIS\\rubik_cube\\cub.txt");
        }
        cube.print();
        while (a != 0) {
            cout << "enter number\n0 - end the program \n1 - rotate a cube face \n2 - check the cube for correctness\n3 - cube output\n";
            cin >> a;
            if (a == 1) {
                cube.changeFace();
                cube.print();
            }
            else if(a == 2){
                cube.checkRows();
            }
            else if (a == 3) {
                cube.print();
            }
        }
        
    }
    else {
        cout << "you entered the wrong number";
    }

    return 0;
}
*/
