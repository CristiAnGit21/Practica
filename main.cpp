#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Point {
    double x, y;
};

void quickSort(vector<Point> &arr, int low, int high) {
    if (low >= high) return;

    Point pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].x < pivot.x) {
            i++;
            Point temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Point temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int p = i + 1;
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main() {
    int n = 20000000;
    vector<Point> points;

    srand(time(0));

    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        double x = (rand() % 36000) / 100.0;
        double y = (rand() % 36000) / 100.0;
        points.push_back({x, y});
    }
    clock_t end = clock();
    double genTime = double(end - start) / CLOCKS_PER_SEC;

    int index = 12345;
    cout << "Point number " << index << ": (" << points[index].x << ", " << points[index].y << ")" << endl;

    start = clock();
    quickSort(points, 0, points.size() - 1);
    end = clock();
    double sortTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Number of points: " << points.size() << endl;
    cout << "Vector capacity: " << points.capacity() << endl;
    cout << "Generation time: " << genTime << " seconds" << endl;
    cout << "Sort time: " << sortTime << " seconds" << endl;
    cout << "First point after sorting: (" << points.front().x << ", " << points.front().y << ")" << endl;
    cout << "Last point after sorting: (" << points.back().x << ", " << points.back().y << ")" << endl;

    return 0;
}