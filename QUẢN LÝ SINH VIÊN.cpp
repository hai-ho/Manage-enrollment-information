#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Student {
    std::string id;
    float score1, score2, score3;
};

std::vector<Student> readData(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    int n;
    file >> n;
    for (int i = 0; i < n; ++i) {
        Student student;
        file >> student.id >> student.score1 >> student.score2 >> student.score3;
        students.push_back(student);
    }
    file.close();
    return students;
}

float calculateTotalScore(const Student& student) {
    return student.score1 + student.score2 + student.score3;
}

bool isAdmitted(const Student& student) {
    float totalScore = calculateTotalScore(student);
    return totalScore >= 15 && student.score1 != 0 && student.score2 != 0 && student.score3 != 0;
}

void writeAdmittedStudents(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    int count = 0;
    for (const auto& student : students) {
        if (isAdmitted(student)) {
            ++count;
        }
    }
    file << count << "\n";
    for (const auto& student : students) {
        if (isAdmitted(student)) {
            file << student.id << " " << calculateTotalScore(student) << "\n";
        }
    }
    file.close();
}

int main() {
    std::vector<Student> students = readData("tuyensinh.dat");
    writeAdmittedStudents("trungtuyen.dat", students);
    return 0;
}

// Giải thích: file chứa dữ liệu của 3 thi sinh, thí sinh thứ nhất có số báo danh là 001, điểm môn 1=5, điểm môn 2 =6, điểm môn 3 = 8.
// Trong file dữ liệu, mỗi dòng sau dòng đầu tiên sẽ chứa thông tin về một thí sinh. Thông tin này bao gồm số báo danh, điểm môn 1, điểm môn 2 và điểm môn 3, mỗi giá trị được phân tách bằng ít nhất một khoảng trắng.

// Ví dụ, nếu file chứa dữ liệu của 3 thí sinh, nó có thể trông như sau :

// 3
// 001 5 6 8
// 002 7 8 9
// 003 6 7 8

// Trong đó :
// Dòng đầu tiên là số 3, cho biết có 3 thí sinh.
// Dòng thứ hai là 001 5 6 8, cho biết thí sinh có số báo danh 001 có điểm môn 1 là 5, điểm môn 2 là 6 và điểm môn 3 là 8.
// Tương tự, dòng thứ ba và thứ tư cho biết thông tin về thí sinh thứ hai và thứ ba.
