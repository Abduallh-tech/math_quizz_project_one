// Math Quiz Game - Professionally Refactored and Documented
// Author: [Your Name]
// Description: Console-based math quiz game with multiple difficulty levels and operation types.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to get the number of questions from the user
int get_number() {
    int number;
    do {
        cout << "How many questions do you want to solve?\n";
        cin >> number;
    } while (number <= 0);
    return number;
}

// Generate a random number in the range [from, to]
int generate_rand_number(int from, int to) {
    return rand() % (to - from + 1) + from;
}

// Ask the user to select a difficulty level
string question_level() {
    int level;
    cout << "Enter the question level [1]: Easy [2]: Med [3]: Hard [4]: Mix \n";
    cin >> level;
    switch (level) {
    case 1: return "Easy";
    case 2: return "Med";
    case 3: return "Hard";
    case 4: return "Mix";
    default: return question_level(); // Recursively prompt until valid
    }
}

// Ask the user to select an operation type
char sign_question() {
    int choice;
    string mix_operations[] = { "+", "-", "X", "/" };
    cout << "Enter operation type [1]: Add , [2]: Sub, [3]: Div , [4]: Mul, [5]: Mix\n";
    cin >> choice;
    switch (choice) {
    case 1: return '+';
    case 2: return '-';
    case 3: return '/';
    case 4: return 'X';
    case 5: return mix_operations[generate_rand_number(0, 3)][0];
    default: return sign_question();
    }
}

// Get the result based on operation
int get_result(int number1, int number2, char sign) {
    switch (sign) {
    case 'X': return number1 * number2;
    case '+': return number1 + number2;
    case '/': return number1 / number2;
    case '-': return number1 - number2;
    default: return 0;
    }
}

// Compare user's answer with correct result
bool check_result(int user_result, int number1, int number2, char sign) {
    return get_result(number1, number2, sign) == user_result;
}

// Easy level questions
void easy_questions(int& right, int& wrong, char& sign_q, int& number) {
    for (int i = 1; i <= number; i++) {
        int number1 = generate_rand_number(1, 10);
        int number2 = generate_rand_number(1, 10);

        cout << "Question [" << i << "/" << number << "]\n\n";
        cout << number1 << " " << sign_q << " " << number2 << " = ";

        int user_result;
        cin >> user_result;

        if (check_result(user_result, number1, number2, sign_q)) {
            right++;
            system("color 2f");
            cout << "Correct answer :-)\n\n";
        }
        else {
            wrong++;
            system("color 4f");
            cout << "Wrong answer :-(\n";
            cout << "Right answer: " << get_result(number1, number2, sign_q) << endl;
        }
    }
}

// Medium level questions
void med_questions(int& right, int& wrong, char& sign_q, int& number) {
    for (int i = 1; i <= number; i++) {
        int number1 = generate_rand_number(1, 30);
        int number2 = generate_rand_number(1, 30);

        cout << "Question [" << i << "/" << number << "]\n\n";
        cout << number1 << " " << sign_q << " " << number2 << " = ";

        int user_result;
        cin >> user_result;

        if (check_result(user_result, number1, number2, sign_q)) {
            right++;
            system("color 2f");
            cout << "Correct answer :-)\n\n";
        }
        else {
            wrong++;
            system("color 4f");
            cout << "Wrong answer :-(\n";
            cout << "Right answer: " << get_result(number1, number2, sign_q) << endl;
        }
    }
}

// Hard level questions
void hard_questions(int& right, int& wrong, char& sign_q, int& number) {
    for (int i = 1; i <= number; i++) {
        int number1 = generate_rand_number(10, 100);
        int number2 = generate_rand_number(10, 100);

        cout << "Question [" << i << "/" << number << "]\n\n";
        cout << number1 << " " << sign_q << " " << number2 << " = ";

        int user_result;
        cin >> user_result;

        if (check_result(user_result, number1, number2, sign_q)) {
            right++;
            system("color 2f");
            cout << "Correct answer :-)\n\n";
        }
        else {
            wrong++;
            system("color 4f");
            cout << "Wrong answer :-(\n";
            cout << "Right answer: " << get_result(number1, number2, sign_q) << endl;
        }
    }
}

// Mixed operations questions (random operator per question)
void mix_questions(int& right, int& wrong, char&, int& number) {
    char operators[] = { '+', '-', 'X', '/' };

    for (int i = 1; i <= number; i++) {
        char current_sign = operators[generate_rand_number(0, 3)];
        int number1, number2;

        if (current_sign == '/') {
            number2 = generate_rand_number(1, 10);
            number1 = number2 * generate_rand_number(1, 10); // Ensure divisibility
        }
        else {
            number1 = generate_rand_number(1, 100);
            number2 = generate_rand_number(1, 100);
        }

        cout << "Question [" << i << "/" << number << "]\n\n";
        cout << number1 << " " << current_sign << " " << number2 << " = ";

        int user_result;
        cin >> user_result;

        if (check_result(user_result, number1, number2, current_sign)) {
            right++;
            system("color 2f");
            cout << "Correct answer :-)\n\n";
        }
        else {
            wrong++;
            system("color 4f");
            cout << "Wrong answer :-(\n";
            cout << "Right answer: " << get_result(number1, number2, current_sign) << endl;
        }
    }
}

// Determine final result based on score
string final_result(int right, int wrong) {
    if (right > wrong) return "Pass";
    if (wrong > right) return "Fail";
    return "Equal";
}

// Dispatches the appropriate question set
void display_game(const string& level, char sign_q, int number, int& right, int& wrong) {
    if (level == "Easy") easy_questions(right, wrong, sign_q, number);
    else if (level == "Med") med_questions(right, wrong, sign_q, number);
    else if (level == "Hard") hard_questions(right, wrong, sign_q, number);
    else mix_questions(right, wrong, sign_q, number);
}

// Show user performance summary
void prompt_user(int right, int wrong, int number, char sign_q) {
    cout << "\n\n\n---------------------------------------------------------\n";
    cout << "\t\tFinal result: " << final_result(right, wrong) << endl;
    cout << "---------------------------------------------------------\n";
    cout << "Total Questions: " << number << endl;
    cout << "Operation Type: " << sign_q << endl;
    cout << "Correct Answers: " << right << endl;
    cout << "Wrong Answers: " << wrong << endl;
}

// Main game loop
void start_quiz() {
    char repeat = 'y';
    do {
        system("cls");
        system("color 07");

        int right = 0, wrong = 0;
        int number = get_number();
        char sign_q = sign_question();
        string level = question_level();

        display_game(level, sign_q, number, right, wrong);
        prompt_user(right, wrong, number, sign_q);

        cout << "\n\nDo you want to play again (Y/N)? ";
        cin >> repeat;

    } while (repeat == 'Y' || repeat == 'y');
}

// Entry point
int main() {
    srand(unsigned(time(0)));
    start_quiz();
    return 0;
}


