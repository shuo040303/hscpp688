#include<iostream>
#include<cstring>
using namespace std;
class students {
public:
    int id;
    string name;
    string gender;
    int score;
public:
    students(int id, string name, string gender, int score) {
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->score = score;
    }
    students(const students& s) {
        this->id = s.id;
        this->name = s.name;
        this->gender = s.gender;
        this->score = s.score;
    }
};
int main() {
    int i, j, num=0;
    students a[5] = { students(001,"李华","男",79),students(002,"小葵","女",85),students(003,"张三","男",76),students(004,"王五","男",54),students(005,"小崔","男",68) };
    for (i = 0;i < 5;i++) {
        for (j = 0;j < 5 - i - 1;j++) {
            if (a[j].score > a[j + 1].score) {
                students t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (i = 0;i < 5;i++) {
        cout << a[i].id << a[i].name << a[i].gender << a[i].score << endl;
    }
    for (i = 0;i < 5;i++) {
        if (a[i].gender == "男")cout << a[i].id << a[i].name << a[i].gender << a[i].score << endl;
    }
    for (i = 0;i < 5;i++) {
        num += a[i].score;
    }
    cout << "学生的平均成绩为:" << num / 5 << endl;
}