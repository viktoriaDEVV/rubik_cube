#include <iostream>
#include <vector>
#include <random>

class Cube
{
public:
    std::vector<std::vector<char>> faces;

    //конструктор для создания кубика и заполнение его рандомными буквами
    Cube(std::random_device rd) {

        // Символы для заполнения
        std::vector<char> symbols = { 'W', 'Y', 'G', 'B', 'R', 'O' };

        // Создаем вектор для хранения символов
        std::vector<char> filledSymbols;

        // Каждый символ повторяется 9 раз
        for (char symbol : symbols) {
            for (int i = 0; i < 9; ++i) {
                filledSymbols.push_back(symbol);
            }
        }

        // Перемешиваем символы
        std::mt19937 g(rd());
        std::shuffle(filledSymbols.begin(), filledSymbols.end(), g);

        // Заполняем матрицу
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 9; ++j) {
                faces[i][j] = filledSymbols[i * 9 + j];
            }
        }
    }





    //конструктор для создания кубика и заполнение его буквами из файла
    Cube(std::string filename) {
        faces = {
            {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}, // Верхняя грань (белая)
            {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'}, // Нижняя грань (желтая)
            {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'}, // Левая грань (зеленая)
            {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}, // Правая грань (синяя)
            {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'}, // Передняя грань (красная)
            {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}  // Задняя грань (оранжевая)
        };
    }

    void printMatrix() {
        for (const auto& row : faces) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }
    }
};

