#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    const int sizes[] = { 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000 };

    cout << "Arr size\ttime (average)\t        time (worst)\n";

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        const int size = sizes[i];
        int arr[1001];
        int result;

        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 1000;
        }
        double sumTime = 0;
        double sumTime1 = 0;
        int key = 1000;
        int m;
        do {
            m = rand() % size;
        } while (m == 0 || m == size);
        arr[m] = key;
        for (int i = 0; i < 50; i++); {
            clock_t start = clock();
            for (int j = 0; j < 100000; j++) {
                result = linearSearch(arr, size, key);
            }
            clock_t end = clock();
            sumTime += double(end - start) / CLOCKS_PER_SEC;


            start = clock();
            for (int j = 0; j < 100000; j++) {
                result = linearSearch(arr, size, -1);
            }
            end = clock();
            sumTime1 += double(end - start) / CLOCKS_PER_SEC;
        }
        cout << size << "\t\t" << sumTime / 50 << " sec\t\t" << sumTime1 / 50 << " sec\n";
    }

    return 0;
}