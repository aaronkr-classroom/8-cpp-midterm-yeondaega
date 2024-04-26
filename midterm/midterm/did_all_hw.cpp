#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// �л� ������ ��� Ŭ����
class Student {
public:
    string name;
    double midterm;
    double final;
    vector<double> homework;
};

// ���Ͽ��� �л� ������ �о���� �Լ�
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

// ������ ��հ��� ����ϴ� �Լ�
double average_grade(const Student& student) {
    double total = student.midterm + student.final;
    for (double grade : student.homework) {
        total += grade;
    }
    return total / (2 + student.homework.size());
}

int main() {
    // grades.txt ���Ͽ��� �л� ������ �о�ɴϴ�.
    vector<Student> students = read_students("grades.txt");

    // �� �л��� ������ ��հ��� ����ϰ� ����մϴ�.
    for (const auto& student : students) {
        double average = average_grade(student);
        cout << student.name << "�� ���� ���: " << average << endl;
    }

    return 0;
}
