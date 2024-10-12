#include <iostream>
#include <vector>
#include <random>

class Cube
{
public:
    std::vector<std::vector<char>> faces;

    //����������� ��� �������� ������ � ���������� ��� ���������� �������
    Cube(std::random_device rd) {

        // ������� ��� ����������
        std::vector<char> symbols = { 'W', 'Y', 'G', 'B', 'R', 'O' };

        // ������� ������ ��� �������� ��������
        std::vector<char> filledSymbols;

        // ������ ������ ����������� 9 ���
        for (char symbol : symbols) {
            for (int i = 0; i < 9; ++i) {
                filledSymbols.push_back(symbol);
            }
        }

        // ������������ �������
        std::mt19937 g(rd());
        std::shuffle(filledSymbols.begin(), filledSymbols.end(), g);

        // ��������� �������
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 9; ++j) {
                faces[i][j] = filledSymbols[i * 9 + j];
            }
        }
    }





    //����������� ��� �������� ������ � ���������� ��� ������� �� �����
    Cube(std::string filename) {
        faces = {
            {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}, // ������� ����� (�����)
            {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'}, // ������ ����� (������)
            {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'}, // ����� ����� (�������)
            {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}, // ������ ����� (�����)
            {'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'}, // �������� ����� (�������)
            {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}  // ������ ����� (���������)
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

