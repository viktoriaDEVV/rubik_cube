#include<iostream>
#include "CubeRubik.h"

using namespace std;

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

