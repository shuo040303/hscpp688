#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    Student(int id, string name, char gender, double score) {
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->score = score;
    }
    Student(const Student& other) {
        this->id = other.id;
        this->name = other.name;
        this->gender = other.gender;
        this->score = other.score;
    }
    void display() const {
        cout << "ID:" << id << ", Name:" << name << ", Gender:" << gender << ", Score:" << score << endl;
    }
    int getId() const {
        return id;
    }
    char getGender() const {
        return gender;
    }
    double getScore() const {
        return score;
    }
private:
    int id;
    string name;
    char gender;
    double score;
};

bool compareByScore(const Student& s1, const Student& s2) {
    return s1.getScore() > s2.getScore();
}

int main() {
    vector<Student> students;
    for (int i = 0; i < 5; i++) {
        int id;
        string name;
        char gender;
        double score;
        cout << "Enter student " << i+1 << "'s ID, name, gender(M/F), and score: ";
        cin >> id >> name >> gender >> score;
        students.push_back(Student(id, name, gender, score));
    }
    sort(students.begin(), students.end(), compareByScore);
    cout << "Sorted by score:" << endl;
    for (const auto& student : students) {
        student.display();
    }
    cout << "Male students:" << endl;
    for (const auto& student : students) {
        if (student.getGender() == 'M') {
            student.display();
        }
    }
    double sumScore = 0;
    for (const auto& student : students) {
        sumScore += student.getScore();
    }
    double averageScore = sumScore / students.size();
    cout << "Average score: " << averageScore << endl;
    return 0;
}
