#include <iostream>
#include <math.h>
#include <valarray>
using namespace std;

int main() {
    int side;

    cout << "Enter a number:";
    cin >> side;
    cout << "The size of your cube is: " << pow(side, 3);
    cout << endl;

    return 0;
}
