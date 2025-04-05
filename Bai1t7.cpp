#include <bits/stdc++.h>
using namespace std;

// Cấu trúc Node
struct Node {
    int data;
    Node* next;
};

// Thêm phần tử vào đầu danh sách
void addElement(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Xóa phần tử theo giá trị
void deleteElement(Node*& head, int value) {
    if (!head) return; // Danh sách rỗng

    // Nếu phần tử cần xóa nằm ở đầu danh sách
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Tìm và xóa phần tử
    Node* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// In danh sách với sắp xếp nhanh
void printSortedList(Node* head) {
    vector<int> vec;

    // Chuyển danh sách liên kết sang vector
    while (head) {
        vec.push_back(head->data);
        head = head->next;
    }

    // Sắp xếp vector
    sort(vec.begin(), vec.end());

    // In các phần tử
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

// Giải phóng bộ nhớ
void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* list1 = nullptr;

    cout << "Nhập 10 số nguyên: ";
    for (int i = 0; i < 10; ++i) {
        int value;
        cin >> value;
        addElement(list1, value);
    }

   
    cout << " ";
    printSortedList(list1);
    int k;
    cout << "Nhập số cần xóa: ";
    cin >> k;
    deleteElement(list1, k);

  
    cout << " ";
    printSortedList(list1);

    Node* list2 = nullptr;

    
    cout << "Nhập 5 số nguyên: ";
    for (int i = 0; i < 5; ++i) {
        int value;
        cin >> value;
        addElement(list2, value);
    }

    // Gộp 
    Node* temp = list2;
    while (temp) {
        addElement(list1, temp->data);
        temp = temp->next;
    }

    
    cout << " ";
    printSortedList(list1);

   
    return 0;
}
