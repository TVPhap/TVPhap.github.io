#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedStackInt {
private:
    Node* top;

public:
    // Khởi tạo stack (InitStack)
    LinkedStackInt() : top(nullptr) {}

    // Kiểm tra stack rỗng (IsEmpty)
    bool isEmpty() {
        return top == nullptr;
    }

    // Thêm phần tử vào stack (PushStack)
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Lấy phần tử khỏi stack (PopStack)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rỗng!" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Xem phần tử đỉnh (PeekStack)
    int peek() {
        if (isEmpty()) {
            cout << "Stack rỗng!" << endl;
            return -1;
        }
        return top->data;
    }

    // Xóa sạch stack (Clear)
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Hủy đối tượng, giải phóng bộ nhớ
    ~LinkedStackInt() {
        clear();
    }
};
