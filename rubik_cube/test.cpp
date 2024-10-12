#include <gtest/gtest.h>
#include "Cube_Rubik.h" // Подключение файла с объявлением класса Cube

// Тест для решённого куба
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

// Тест для несостоявшегося куба
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

// Другие тесты аналогично...

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}