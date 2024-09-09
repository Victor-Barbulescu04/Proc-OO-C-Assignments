// SPA 1, Fall 2024, Victor Barbulescu
#include <iostream>
using namespace std;

int main() {
    string time, item;
    int amount = 0;
    int totalAmount = 0;

    // Read and process inputs
    while (cin >> time) {
        // If the user enters exit, break out of the loop
        if (time == "exit") break;

        // Continue to read item and amount only if time is not "exit"
        cin >> item >> amount;

        // Add the amount to the correct running total
        if (item == "urine" || item == "bloodloss" || item == "diarrhea") {
            totalAmount -= amount;
        } else {
            totalAmount += amount;
            // If our total fluid amount is above 1000ml, print time, item, and the current total
            if (totalAmount >= 1000) {
                cout << "after consuming " << item << " at "<< time << ", intake exceeds output by " << totalAmount << " ml" << endl;
            }
        }
    }

    cout << "the final fluid differential is " << totalAmount << " ml" << endl;
}
