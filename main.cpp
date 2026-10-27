
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Store 5 student names and their 3 marks
    char names[5][20];
    int marks[5][3];
    int total[5];
    float average[5];

    int i, j;
    int topStudent = 0;

    // Read student names and marks
    for (i = 0; i < 5; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin.getline(names[i], 20);

        total[i] = 0;

        for (j = 0; j < 3; j++) {
            cout << "Enter mark " << j + 1 << ": ";
            cin >> marks[i][j];

            total[i] = total[i] + marks[i][j];
        }

        // Calculate average
        average[i] = total[i] / 3.0;

        // Clear the input buffer before reading the next name
        if (i < 4) {
            cin.ignore(1000, '\n');
        }
    }

    // Find the top student using total marks
    for (i = 1; i < 5; i++) {
        if (total[i] > total[topStudent]) {
            topStudent = i;
        }
    }

    // Print the mark sheet
    cout << "\n\n";
    cout << "================ STUDENT MARK SHEET ================\n";

    cout << left
         << setw(20) << "Name"
         << setw(10) << "M1"
         << setw(10) << "M2"
         << setw(10) << "M3"
         << setw(10) << "Total"
         << setw(10) << "Avg" << endl;

    cout << "-----------------------------------------------------\n";

    for (i = 0; i < 5; i++) {
        cout << left
             << setw(20) << names[i]
             << setw(10) << marks[i][0]
             << setw(10) << marks[i][1]
             << setw(10) << marks[i][2]
             << setw(10) << total[i]
             << fixed << setprecision(1)
             << setw(10) << average[i] << endl;
    }

    cout << "-----------------------------------------------------\n";

    // Display the top student
    cout << "\nTop student: " << names[topStudent] << endl;
    cout << "Total marks: " << total[topStudent] << endl;
    cout << "Average: " << fixed << setprecision(1)
         << average[topStudent] << endl;

    return 0;
}
