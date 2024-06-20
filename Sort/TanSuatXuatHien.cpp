#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Struct để lưu trữ thông tin về phần tử và tần suất xuất hiện
struct ElementFrequency {
    int element;
    int frequency;
};

// Hàm so sánh để sắp xếp theo tần suất giảm dần
bool compare(const ElementFrequency& a, const ElementFrequency& b) {
    return a.frequency > b.frequency;
}

void sortByFrequency(int arr[], int n) {
    std::vector<ElementFrequency> frequencyCount;

    for (unsigned int i = 0; i < n; i++) {
        int element = arr[i];
        bool found = false;

        // Kiểm tra xem phần tử đã tồn tại trong danh sách tần suất hay chưa
        for (unsigned int j = 0; j < frequencyCount.size(); j++) {
            if (frequencyCount[j].element == element) {
                frequencyCount[j].frequency++;
                found = true;
                break;
            }
        }

        if (!found) {
            ElementFrequency ef;
            ef.element = element;
            ef.frequency = 1;
            frequencyCount.push_back(ef);
        }
    }

    // Sắp xếp danh sách tần suất theo tần suất giảm dần
    std::sort(frequencyCount.begin(), frequencyCount.end(), compare);

    int index = 0;
    for (unsigned int i = 0; i < frequencyCount.size(); i++) {
        for (int j = 0; j < frequencyCount[i].frequency; j++) {
            arr[index] = frequencyCount[i].element;
            index++;
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortByFrequency(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
