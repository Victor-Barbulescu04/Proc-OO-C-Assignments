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
    uint32_t mantissa = hexValue & 0x007FFFFF;

    // Check if the mantissa is a half or less by checking the 22nd digit.
    // Also check if any of the following bits are 1.
    // 23rd digit is implicitly 1, so it's not important.
    bool is_half_or_less = (mantissa & 0x00400000);// && ((mantissa & 0x003FFFFF) == 0);

    // Print the appropriate message
    if (is_half_or_less) {
        std::cout << "mantissa is a half or less\n";
    } else {
        std::cout << "mantissa is greater than a half\n";
    }

    return 0;
}