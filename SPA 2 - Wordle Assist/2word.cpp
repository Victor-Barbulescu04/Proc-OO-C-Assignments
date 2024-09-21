#include <cassert>
#include <iostream>
using namespace std;

// Max words in the dictionary is 3000
constexpr int MAX_WORDS = 3000;
// Max Guesses is 10, but a guess consists of two inputs,
// so for simplicity’s sake the max guesses are listed as 20
constexpr int MAX_GUESSES = 20;

// Function prototypes
void run_checks();
string* read_word_list();
string* read_guesses();
string* possible_answers(string* dictionary, string* guesses);
int count_possible_matches(string* possible_matches);
string build_output(string* guessesArray);

int main() {
    run_checks();
    string* wordsArrayPtr = read_word_list();
    string* guessesArrayPtr = read_guesses();
    string* possible_matches = possible_answers(wordsArrayPtr, guessesArrayPtr);

    int possible_matches_count = count_possible_matches(possible_matches);
    string guessesOutput = build_output(guessesArrayPtr);
    guessesOutput += to_string(possible_matches_count);
    cout << guessesOutput << endl;
    for (int j = 0; j < MAX_GUESSES; j++) {
        if (!possible_matches[j].empty()) {
            cout << possible_matches[j] << endl;
        }
    }
    return 0;
}

string* read_word_list() {
    static string wordsArray[MAX_WORDS];
    int size = 0; // Initialize the size
    while (true) {
        string input;
        cin >> input; // Read a word at a time

        if (input == "END") {break;} // Stop reading when "END" is entered
        if (size >= MAX_WORDS) {break;}

        wordsArray[size] = input;
        size++;
    }
    return wordsArray;
}


string* read_guesses() {
    static string guessesArray[MAX_GUESSES];
    string guess;
    string letter_matches;
    int i = 0;
    while (i < MAX_GUESSES && cin >> guess >> letter_matches) {
        guessesArray[i] = guess;
        guessesArray[i + 1] = letter_matches;
        i = i + 2;
    }
    return guessesArray;
}


bool can_match(string possible_answer, string guess, string letter_matches) {
    for (int i = 0; i < letter_matches.length(); i++) {
        switch (letter_matches[i]) {
            case '.': // If character does not exactly match position, return false
                if (possible_answer[i] != guess[i]) {return false;}
                break;
            case '?': // If possible answer does not contain character, return false
                if (possible_answer.find(guess[i]) == string::npos) {return false;}
                break;
            case '-': // If possible answer contains character, return false
                if (possible_answer.find(guess[i]) != string::npos) {return false;}
                break;
            default: break;
        }
    }
    return true;
}

string* possible_answers(string* dictionary, string* guesses) {
    string *possible_matches = dictionary;

    for (int i = 0; i < 10; i++) {
        string guess = guesses[2 * i]; // Even numbered indexes
        string letter_matches = guesses[2 * i + 1]; // Odd numbered indexes
        for (int j = 0; j < MAX_WORDS; j++) {
            if (!can_match(possible_matches[j], guess, letter_matches)) {
                possible_matches[j] = "";
            }
        }
    }

    return possible_matches;
}

void run_checks() {
    // test can_match function
    assert(can_match("abcde", "axbxf", ".-\?--"));
    assert(!can_match("abcde", "axbxd", ".-\?--"));
    assert(can_match("abcde", "easty", "\?\?---"));
    assert(!can_match("abcde", "abcdf", "....."));
    assert(can_match("abcde", "uvwxy", "-----"));
}

int count_possible_matches(string* possible_matches) {
    // Count the number of possible matches
    int possible_matches_count = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (!possible_matches[i].empty()) {
            possible_matches_count++;
        }
    }

    return possible_matches_count;
}

string build_output(string* guessesArray) {
    // Build string for output
    string guessesOutput = "Possible guesses after ";
    for (int i = 0; i < MAX_GUESSES; i += 2) {
        if (!guessesArray[i].empty()) {
            string guess = guessesArray[i];
            guessesOutput += guess + ", ";
        } else {
            // replace the last comma with a colon
            guessesOutput[guessesOutput.find_last_of(',')] = ':';
            break;
        }
    }

    return guessesOutput;
}



