#include <iostream>
#include <vector>

using namespace std;


template <typename E>
class Heap {
private:
    std::vector<E> data;

    //* đưa 1 phần tử về vị trí chính xác của nó để cập nhật heap
    //* tìm node cha của node hiện tại bằng công thức (index - 1) / 2 do này là cây gần hoàn thành
    //* kiểm tra node cha lớn hay nhỏ hơn node con nếu nhỏ hơn thì kết thúc nếu lớn hơn thì swap rồi di chuyển index lên node cha
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (data[index] > data[parent]) {
                swap(data[index], data[parent]);
                index = parent;
            } 
            else break;
        }
    }

    //* đưa 1 phần tử về vị trí chính xác của nó để cập nhật heap
    //* tìm node con trái phải xem nào lớn hơn
    //* nếu node cha lớn hơn thì break nếu trái phải nào lớn thì chọn nó rồi swap rồi cập nhật heapifyDown cho node con lớn nhất
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < data.size() && data[leftChild] > data[largest]) {
            largest = leftChild;
        }

        if (rightChild < data.size() && data[rightChild] > data[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(data[index], data[largest]);
            heapifyDown(largest);
        }
    }

public:
    //* Thêm một phần tử vào heap khi thêm thì thêm ở cuối array
    //* sau khi thêm thì heapifyUp phân tử đó với phần tử phía trên để cập nhật lại heap
    void push(const E& value) {
        data.push_back(value);
        heapifyUp(data.size() - 1);
    }

    //* Loại bỏ và trả về phần tử đầu tiên mảng (phần tử lớn nhất)
    //* khi xóa thì đưa phần tử đó về cuối rồi đưa cuối lên đầu
    //* sau khi thêm thì heapifyDown phân tử đó với phần tử phía dưới để cập nhật lại heap
    E pop() {
        if (data.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        E max = data[0];
        data[0] = data.back();
        data.pop_back();
        heapifyDown(0);

        return max;
    }

    // Kiểm tra xem heap có rỗng hay không
    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Heap<int> maxHeap;

    // Thêm các phần tử vào heap
    maxHeap.push(3);
    maxHeap.push(7);
    maxHeap.push(1);
    maxHeap.push(5);

    // In ra các phần tử lớn nhất từ heap
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.pop() << " ";
    }

    return 0;
}