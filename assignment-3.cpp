#include <iostream>
#include <cmath>

const double *aver(const double *arr, size_t size, double &average) {

    for (int i = 0; i < size; i++) {
        average += arr[i];
    }
    average = average / size;

    double element, min = average, res;
    for (int i = 0; i < size; i++) {
        res = abs(arr[i] - average);
        if (res < min) {
            min = res;
            element = arr[i];
        }
    }
    return &element;
}

int main() {
    using std::cout; using std::endl;
    double arr[] = {1, 2, -1.5, 3.25, 5.5, 7.75, -0.25, 5.75};
    size_t size = sizeof(arr) / sizeof(arr[0]); //size_t - unsigned int
    double average = 0;
    const double *p = aver(arr, size, average);
    cout << *p << " " << average << endl;
}
