#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int group;
    int grades[5];

    double avg() const {
        double sum = 0;
        for (int i = 0; i < 5; i++) sum += grades[i];
        return sum / 5;
    }
};

bool isVowel(char c) {
    string vowels = "AEIOUYaeiouy";
    return vowels.find(c) != string::npos;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Group: ";
        cin >> students[i].group;
        cout << "Grades: ";
        for (int j = 0; j < 5; j++)
            cin >> students[i].grades[j];
    }

    bool found = false;
    for (auto &s : students) {
        if (s.avg() > 4.0) {
            cout << s.name << " " << s.group << endl;
            found = true;
        }
    }
    if (!found) cout << "No such students\n";

    cout << "\nStarts with vowel:\n";
    for (auto &s : students) {
        if (isVowel(s.name[0]))
            cout << s.name << endl;
    }

    sort(students.begin(), students.end(),
         [](Student a, Student b) {
             return a.avg() < b.avg();
         });

    cout << "\nSorted:\n";
    for (auto &s : students)
        cout << s.name << " " << s.avg() << endl;

    int minIndex = 0;
    for (int i = 1; i < n; i++)
        if (students[i].avg() < students[minIndex].avg())
            minIndex = i;

    if (minIndex + 1 < n)
        students.erase(students.begin() + minIndex + 1);

    cout << "\nAfter deletion:\n";
    for (auto &s : students)
        cout << s.name << endl;

    return 0;
}
