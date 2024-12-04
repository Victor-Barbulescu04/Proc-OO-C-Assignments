#include <cstdint>
#include <iostream>

using namespace std;

int main() {
    float in = 0.0f;
    cout << "Enter a floating-point number: ";
    cin >> in;

    unsigned int hexValue = *reinterpret_cast<unsigned int*>(&in);

    cout << "Input: " << in << ", hex 0x";
    cout << hex << hexValue << dec << endl;

    // Extract the mantissa (lower 23 bits) using a bitmask
    // 0x7FFFFF is actually a 24 bit binary, with the leading bit being 0.
    // This leading bit will be ignored in further calculations
    uint32_t mantissa = hexValue & 0x007FFFFF;

    // If bit 23 is set and any subsequent bits are set, the mantissa is greater than a half.
    // Otherwise, the mantissa is half or less
    if ((mantissa & 0x00400000) != 0 && (mantissa & 0x003FFFFF) != 0) {
        cout << "mantissa is greater than a half\n";
    } else {
        cout << "mantissa is a half or less\n";
    }

    return 0;
}