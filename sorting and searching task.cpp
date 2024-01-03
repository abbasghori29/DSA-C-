#include <iostream>
#include <algorithm>
using namespace std;

class Course {
public:
    string name;
    string prerequisites[10]; // You can adjust the size as needed.
    int numPrerequisites;

    Course(string name) : name(name), numPrerequisites(0) {
        // Initialize prerequisites as an empty array.
    }

    Course(string name, string prerequisites[], int numPrerequisites) : name(name), numPrerequisites(numPrerequisites) {
        for (int i = 0; i < numPrerequisites; i++) {
            this->prerequisites[i] = prerequisites[i];
        }
    }

    string getName() {
        return name;
    }

    const string* getPrerequisites() {
        return prerequisites;
    }

    int getNumPrerequisites() {
        return numPrerequisites;
    }
};

class Student {
public:
    string name;
    string preferences[10]; // You can adjust the size as needed.
    int numPreferences;

    Student(string name, string preferences[], int numPreferences) : name(name), numPreferences(numPreferences) {
        for (int i = 0; i < numPreferences; i++) {
            this->preferences[i] = preferences[i];
        }
    }

    string getName() {
        return name;
    }

    const string* getPreferences() {
        return preferences;
    }

    int getNumPreferences() {
        return numPreferences;
    }
};

bool binarySearch(const string arr[], int size, const string& target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    Course courses[] = {
        Course("Math"),
        Course("Physics", {"Math"} ,1),
        Course("Chemistry", {"Math"}, 1),
        Course("Biology", {"Chemistry"}, 1),
        Course("History")
        // Add more courses and their prerequisites as needed.
    };

    Student students[] = {
        Student("Student1", {"Math", "Physics", "Chemistry"}, 3),
        Student("Student2", {"Math", "Chemistry", "Biology"}, 3),
        Student("Student3", {"History", "Math"}, 2)
        // Add more students and their preferences as needed.
    };

    string assignedCourses[10]; // Adjust the size as needed.
    int numAssignedCourses = 0;

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        for (int j = 0; j < sizeof(students) / sizeof(students[0]) - i - 1; j++) {
            if (students[j].getNumPreferences() > students[j + 1].getNumPreferences()) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        Student& student = students[i];
        for (int j = 0; j < student.getNumPreferences(); j++) {
            string course = student.getPreferences()[j];
            for (int k = 0; k < sizeof(courses) / sizeof(courses[0]); k++) {
                if (courses[k].getName() == course && !binarySearch(assignedCourses, numAssignedCourses, course)) {
                    bool prerequisitesMet = true;
                    for (int m = 0; m < courses[k].getNumPrerequisites(); m++) {
                        if (!binarySearch(assignedCourses, numAssignedCourses, courses[k].getPrerequisites()[m])) {
                            prerequisitesMet = false;
                            break;
                        }
                    }
                    if (prerequisitesMet) {
                        cout << "Enrolling " << student.getName() << " in " << course << endl;
                        assignedCourses[numAssignedCourses] = course;
                        numAssignedCourses++;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

