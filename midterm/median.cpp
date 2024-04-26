// median.cpp

#include <algorithm>
#include <stdexcept>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::vector;
using std::domain_error;
using std::sort;

// vector<double>의 중앙값을 구함.
// 함수를 호출하면 인수로 제공된 백터를 통째로 복사
double median(vector<double> vec) {
    // 과제 점수의 입력 유무를 확인
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("Median of empty vector");
    }

    // 점수를 정렬
    sort(vec.begin(), vec.end());

    // 과제 점수의 중앙값을 구함
    vec_sz mid = size / 2;
    return size % 2 == 0
        ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
