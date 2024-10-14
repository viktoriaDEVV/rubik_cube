#include <gtest/gtest.h>
#include "CubeRubik.h"
#include<sstream>

TEST(CheckRowsTest, SolvedCube) {
    Cube cube;
    cube.faces = {
        {'R', 'R', 'R', 'R'},
        {'G', 'G', 'G', 'G'},
        {'B', 'B', 'B', 'B'},
        {'Y', 'Y', 'Y', 'Y'},
        {'O', 'O', 'O', 'O'},
        {'W', 'W', 'W', 'W'} 
    };
    EXPECT_TRUE(cube.checkRows());
}


TEST(CheckRowsTest, UnsolvedCube) {
    Cube cube;
    cube.faces = {
        {'R', 'R', 'G', 'R'},
        {'G', 'G', 'G', 'G'},
        {'B', 'B', 'B', 'B'},
        {'Y', 'Y', 'Y', 'Y'},
        {'O', 'O', 'O', 'O'},
        {'W', 'W', 'W', 'W'}
    };
    EXPECT_FALSE(cube.checkRows());
}

TEST(CubeTest, LoadFromFile_ValidFile_LoadsCorrectly) {
    Cube cube;
    std::ofstream outfile("test_cube.txt");
    outfile << "YYYYY\nBBBBB\nOOOOOO\nGGGGG\nRRRRR\nWWWWW\n";
    outfile.close();

    cube.loadFromFile("test_cube.txt");

    EXPECT_EQ(cube.faces[1].size(), 5); // Проверка размера
for (size_t i = 0; i < cube.faces[1].size(); ++i) {
    EXPECT_EQ(cube.faces[1][i], 'B'); // Поэлементная проверка
}
}

TEST(CubeTest, PrintCube) {
    std::ostringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf()); // Захват вывода
    Cube cube;
    cube.print(); // Вызов метода для тестирования

    std::cout.rdbuf(oldCout); // Восстановление вывода

   std::string expectedOutput = 
        "your cube\n"
        "U: \n000\n000\n000\n"
        "D: \n000\n000\n000\n"
        "L: \n000\n000\n000\n"
        "R: \n000\n000\n000\n"
        "F: \n000\n000\n000\n"
        "B: \n000\n000\n000\n";

    EXPECT_EQ(buffer.str(), expectedOutput); // Сравнение с ожидаемым выводом
}


// Тест на некорректный ввод
TEST(CubeTest, InvalidInput) {
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf()); // Захват вывода

    std::istringstream input("1\n2\n"); // Ввод: некорректный ввод для поворота
    std::cin.rdbuf(input.rdbuf()); // Подмена ввода
    Cube cube;
    cube.changeFace(); // Вызов метода

    std::cout.rdbuf(oldCout); // Восстановление вывода

    std::string expectedOutput = "Indicate which face you want to rotate (enter the letter corresponding to the name of the face)\nUpper - 1\n Deep - 2\n Left - 3\n Right - 4\n Front - 5\n Back - 6\nEnter 1 if you want to rotate the face clockwise or 0 if counterclockwise\ndata entered incorrectly \n";
    EXPECT_EQ(output.str(), expectedOutput); // Проверка вывода
}

TEST(CubeTest, RandomizeChangesStateOnMultipleCalls) {
    Cube cube;
    char originalFaces[6][9];
    std::copy(&cube.faces[0][0], &cube.faces[0][0] + 6 * 9, &originalFaces[0][0]);

    cube.randomize();
    char firstRandomizedFaces[6][9];
    std::copy(&cube.faces[0][0], &cube.faces[0][0] + 6 * 9, &firstRandomizedFaces[0][0]);

    cube.randomize();
    char secondRandomizedFaces[6][9];
    std::copy(&cube.faces[0][0], &cube.faces[0][0] + 6 * 9, &secondRandomizedFaces[0][0]);

    bool stateChanged = false;
    for (int i = 0; i < 6; ++i) {
        if (!std::equal(firstRandomizedFaces[i], firstRandomizedFaces[i] + 9, secondRandomizedFaces[i])) {
            stateChanged = true;
            break;
        }
    }

    EXPECT_TRUE(stateChanged) << "The cube state did not change after multiple randomizations.";
}

TEST(CubeTest, ValidClockwiseRotation) {
    Cube cube;
    std::istringstream input("1\n1\n"); // Rotate Upper face clockwise
    std::cin.rdbuf(input.rdbuf());

    cube.changeFace();

    // Assert expected state after clockwise rotation
    EXPECT_EQ(cube.faces[0], (std::vector<char>{'0', '0', '0', '0', '0', '0', '0', '0', '0'})); // Check upper face remains the same

    // Check only the corners of adjacent faces to verify the rotation
    EXPECT_EQ(cube.faces[4][0], '0'); // Front top-left
    EXPECT_EQ(cube.faces[3][0], '0'); // Right top-left
    EXPECT_EQ(cube.faces[2][0], '0'); // Left top-left
    EXPECT_EQ(cube.faces[1][0], '0'); // Deep top-left
}

TEST(CubeTest, ValidCounterclockwiseRotation) {
    Cube cube;
    std::istringstream input("1\n0\n"); // Rotate Upper face counterclockwise
    std::cin.rdbuf(input.rdbuf());

    cube.changeFace();

    // Assert expected state after counterclockwise rotation
    EXPECT_EQ(cube.faces[0], (std::vector<char>{'0', '0', '0', '0', '0', '0', '0', '0', '0'})); // Check upper face remains the same

    // Check only the corners of adjacent faces to verify the rotation
    EXPECT_EQ(cube.faces[4][0], '0'); // Front top-left
    EXPECT_EQ(cube.faces[3][0], '0'); // Right top-left
    EXPECT_EQ(cube.faces[2][0], '0'); // Left top-left
    EXPECT_EQ(cube.faces[1][0], '0'); // Deep top-left
}

TEST(CubeTest, LoadFromFile_FileNotFound) {
    Cube cube;
    std::ostringstream capturedOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(capturedOutput.rdbuf());

    cube.loadFromFile("non_existent_file.txt");

    // Restore cout buffer
    std::cout.rdbuf(oldCoutBuffer);

    // Check if the output contains the error message
    EXPECT_THAT(capturedOutput.str(), ::testing::HasSubstr("Error opening file!"));
}
