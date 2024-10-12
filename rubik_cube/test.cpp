#include <gtest/gtest.h>
#include "Cube_Rubik.h" // ����������� ����� � ����������� ������ Cube

// ���� ��� ��������� ����
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

// ���� ��� ��������������� ����
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

// ������ ����� ����������...

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}