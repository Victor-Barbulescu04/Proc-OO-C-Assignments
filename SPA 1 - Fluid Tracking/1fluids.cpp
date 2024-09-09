#include <iostream>
using namespace std;

int main() {
    string time, item;
    int amount = 0;
    int totalAmount = 0;

    // Read first user input
    cin >> time >> item >> amount;

    // Process and continue reading inputs
    while(cin.good()) {
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

        cin >> time >> item >> amount;
    }

    cout << "the final fluid differential is " << totalAmount << " ml" << endl;
}
