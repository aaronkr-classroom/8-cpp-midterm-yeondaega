#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "grade.h"

using namespace std;

// 학생 정보를 저장할 구조체
struct Student {
    string name;
    double midterm, final;
    vector<double> homework;
};

// 파일에서 학생 정보를 읽어와서 벡터에 저장하는 함수
vector<Student> read_students(const string& filename) {
    vector<Student> students;
    ifstream file(filename);

    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        istringstream record(line);
        Student student;
        record >> student.name >> student.midterm >> student.final;
        double score;
        while (record >> score) {
            student.homework.push_back(score);
        }
        students.push_back(student);
    }

    return students;
}

int main() {
    // grades.txt 파일에서 학생 정보를 읽어옵니다.
    vector<Student> students = read_students("grades.txt");

    // 과제를 한 학생들의 수를 계산합니다.
    int did_homework_count = 0;
    for (const auto& student : students) {
        if (!student.homework.empty()) { // 과제를 했는지 확인
            did_homework_count++;
        }
    }

    // 과제를 한 학생들의 수를 출력합니다.
    cout << "과제를 한 학생들의 수: " << did_homework_count << endl;

    return 0;
}
