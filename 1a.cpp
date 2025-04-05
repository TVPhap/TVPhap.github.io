#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class StackInt {
private:
    int data[MAX_SIZE];
    int top;

public:
    // Khởi tạo stack (InitStack)
    StackInt() : top(-1) {}

    // Kiểm tra stack rỗng (IsEmpty)
    bool isEmpty() {
        return top == -1;
    }

    // Kiểm tra stack đầy (IsFull)
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Thêm phần tử vào stack (PushStack)
    void push(int value) {
        if (isFull()) {
            cout << "Stack đầy!" << endl;
            return;
        }
        data[++top] = value;
    }

    // Lấy phần tử khỏi stack (PopStack)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rỗng!" << endl;
            return -1; // Giá trị mặc định nếu không có phần tử
        }
        return data[top--];
    }

    // Xem phần tử đỉnh (PeekStack)
    int peek() {
        if (isEmpty()) {
            cout << "Stack rỗng!" << endl;
            return -1;
        }
        return data[top];
    }

    // Xóa sạch stack (Clear)
    void clear() {
        top = -1;
    }
};
