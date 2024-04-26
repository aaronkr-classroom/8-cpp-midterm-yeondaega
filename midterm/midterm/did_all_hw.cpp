#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 학생 정보를 담는 클래스
class Student {
public:
    string name;
    double midterm;
    double final;
    vector<double> homework;
};

// 파일에서 학생 정보를 읽어오는 함수
vector<Student> read_students(const string& filename) {
    vector<Student> students;
    ifstream file(filename);

    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        return students;
    }

    Student student;
    string line;
    while (getline(file, line)) {
        istringstream record(line);
        record >> student.name >> student.midterm >> student.final;
        double grade;
        while (record >> grade) {
            student.homework.push_back(grade);
        }
        students.push_back(student);
        student.homework.clear(); // Clear homework vector for next student
    }

    return students;
}

// 성적의 평균값을 계산하는 함수
double average_grade(const Student& student) {
    double total = student.midterm + student.final;
    for (double grade : student.homework) {
        total += grade;
    }
    return total / (2 + student.homework.size());
}

int main() {
    // grades.txt 파일에서 학생 정보를 읽어옵니다.
    vector<Student> students = read_students("grades.txt");

    // 각 학생의 성적의 평균값을 계산하고 출력합니다.
    for (const auto& student : students) {
        double average = average_grade(student);
        cout << student.name << "의 성적 평균: " << average << endl;
    }

    return 0;
}
