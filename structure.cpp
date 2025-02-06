#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int marks[5];
};

double averageMark(const Student& student) {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student.marks[i];
    }
    return sum / 5;
}

Student* bestStudent(Student students[], int size) {
    if (size == 0) return nullptr;
    Student* best = &students[0];
    double maxAvg = averageMark(students[0]);

    for (int i = 1; i < size; i++) {
        double avg = averageMark(students[i]);
        if (avg > maxAvg) {
            maxAvg = avg;
            best = &students[i];
        }
    }
    return best;
}

int countAboveThreshold(Student students[], int size, double N) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (averageMark(students[i]) > N) {
            count++;
        }
    }
    return count;
}

int main() {

    Student students[] = 
    {
        {"Alyona", {90, 85, 88, 92, 89}},
        {"Antonina", {75, 80, 78, 74, 87}},
        {"Vladyslav", {95, 90, 96, 94, 88}},
        {"Danylo", {60, 65, 70, 68, 68}},
        {"Yaroslav", {95, 89, 86, 74, 70}},
        {"Vasylysa", {91, 90, 85, 84, 88}},
        {"Yuliia", {85, 70, 76, 64, 68}},
    };
    int size = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < size; i++) {
        cout << students[i].name << " average mark: " << averageMark(students[i]) << endl;
    }

    Student* topStudent = bestStudent(students, size);
    if (topStudent) {
        cout << "Best student is " << topStudent->name << " with average mark: " << averageMark(*topStudent) << endl;
    }
    double N = 80.0;
    cout << "Number of students with average mark above " << N << ": " << countAboveThreshold(students, size, N) << endl;

    return 0;
}
