#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cctype> // for toupper
using namespace std;

struct Question {
    string question;
    vector<string> options;
    char correctAnswer;
};

// Function to display the current question and options
void displayQuestion(const Question &q, int index) {
    cout << "\nQuestion " << index + 1 << ": " << q.question << endl;
    for (size_t i = 0; i < q.options.size(); i++) {
        cout << char('A' + i) << ". " << q.options[i] << endl;
    }
}

int main() {
    string playerName;
    int levelChoice;

    cout << "Welcome to the DSA Quiz Game!\n";
    cout << "Please enter your name: ";
    getline(cin, playerName);

    cout << "Hello, " << playerName << "! Please select the difficulty level:\n";
    cout << "1. Beginners\n2. Intermediate\n3. Pro\n";
    cout << "Enter the number corresponding to your choice: ";
    cin >> levelChoice;
    cin.ignore();  // To ignore the newline after the number input
    
    cout << "\n" << playerName << ", are you ready for the game? (yes/no): ";
    string ready;
    getline(cin, ready);
    if (ready != "yes" && ready != "Yes") {
        cout << "Okay, come back when you're ready!\n";
        return 0;
    }

    cout << "Great! Let's start the quiz.\n";
    cout << "Wishing you very good luck, " << playerName << "!\n\n";
    
    // Create a queue to store the questions
    queue<Question> quiz;

    // Add beginner-level questions about DSA to the queue using push_back to add options
    Question q1;
    q1.question = "What is the time complexity of accessing an element in an array?";
    q1.options.push_back("O(1)");
    q1.options.push_back("O(n)");
    q1.options.push_back("O(log n)");
    q1.options.push_back("O(n^2)");
    q1.correctAnswer = 'A';
    quiz.push(q1);

    Question q2;
    q2.question = "Which data structure is LIFO (Last In, First Out)?";
    q2.options.push_back("Queue");
    q2.options.push_back("Stack");
    q2.options.push_back("Array");
    q2.options.push_back("Linked List");
    q2.correctAnswer = 'B';
    quiz.push(q2);

    Question q3;
    q3.question = "What is the main difference between a stack and a queue?";
    q3.options.push_back("Stack follows FIFO, Queue follows LIFO");
    q3.options.push_back("Stack follows LIFO, Queue follows FIFO");
    q3.options.push_back("Both are the same");
    q3.options.push_back("None");
    q3.correctAnswer = 'B';
    quiz.push(q3);

    Question q4;
    q4.question = "Which algorithm is used for searching an element in a sorted array?";
    q4.options.push_back("Linear Search");
    q4.options.push_back("Binary Search");
    q4.options.push_back("Bubble Sort");
    q4.options.push_back("Selection Sort");
    q4.correctAnswer = 'B';
    quiz.push(q4);

    Question q5;
    q5.question = "What is the time complexity of inserting an element in a linked list (at the beginning)?";
    q5.options.push_back("O(1)");
    q5.options.push_back("O(n)");
    q5.options.push_back("O(log n)");
    q5.options.push_back("O(n^2)");
    q5.correctAnswer = 'A';
    quiz.push(q5);

    // Initialize a stack to store the answers
    stack<char> answers;

    int score = 0;
    char answer;
    int index = 0;

    // Process the quiz questions
    while (!quiz.empty()) {
        Question q = quiz.front();
        quiz.pop();  // Remove the question from the queue
        
        displayQuestion(q, index);  // Display the question and options
        
        cout << "Enter your answer (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);  // Convert to uppercase to handle both cases
        
        // Input validation: check if answer is one of A, B, C, or D
        if (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D') {
            cout << "Invalid input. Please enter A, B, C, or D.\n";
            continue;
        }
        
        // Push the answer into the stack
        answers.push(answer);

        // Check if the answer is correct
        if (answer == q.correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! The correct answer was " << q.correctAnswer << ".\n";
        }
        index++;
    }
    
    // Final score output
    cout << "\nQuiz Over, " << playerName << "! You scored " << score << " out of " << index << ".\n";
    
    return 0;
}

