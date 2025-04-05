#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class QueueInt {
private:
    int data[MAX_SIZE];
    int front, rear;
public:
    QueueInt() : front(-1), rear(-1) {}
    
    bool isEmpty() {
        return front == -1 && rear == -1;
    }
    
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }
    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Hang doi day!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        data[rear] = value;
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        int value = data[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return value;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        return data[front];
    }
    
    void clear() {
        front = rear = -1;
    }
};

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedQueueInt {
private:
    Node* front;
    Node* rear;
public:
    LinkedQueueInt() : front(nullptr), rear(nullptr) {}
    
    ~LinkedQueueInt() {
        clear();
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Hang doi rong!" << endl;
            return -1;
        }
        return front->data;
    }
    
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

void xepLichMua() {
    QueueInt nam, nu;
    int soNam, soNu;
    
    cout << "Nhap so nguoi nam: ";
    cin >> soNam;
    cout << "Nhap so nguoi nu: ";
    cin >> soNu;
    
    // Thêm người vào hàng đợi
    for (int i = 1; i <= soNam; i++) {
        nam.enqueue(i);
    }
    for (int i = 1; i <= soNu; i++) {
        nu.enqueue(i);
    }
    
    cout << "Cac cap mua:\n";
    while (!nam.isEmpty() && !nu.isEmpty()) {
        cout << "(" << nam.dequeue() << ", " << nu.dequeue() << ")" << endl;
    }
    
    cout << "Con lai:\n";
    if (!nam.isEmpty()) {
        cout << soNu << " nguoi nu da het, con " << nam.peek() << " nguoi nam cho" << endl;
    } else if (!nu.isEmpty()) {
        cout << soNam << " nguoi nam da het, con " << nu.peek() << " nguoi nu cho" << endl;
    } else {
        cout << "Khong con ai cho" << endl;
    }
}
(c) Thuật toán RadixSort sử dụng hàng đợi
#include <cmath>
#include <queue>

void radixSort(int arr[], int n) {
    const int RADIX = 10;
    queue<int> buckets[RADIX];
    int maxDigits = 0;
    
    // Tìm số chữ số lớn nhất
    for (int i = 0; i < n; i++) {
        int digits = arr[i] == 0 ? 1 : (int)log10(abs(arr[i])) + 1;
        if (digits > maxDigits) {
            maxDigits = digits;
        }
    }
    
    // Sắp xếp theo từng chữ số
    for (int d = 0; d < maxDigits; d++) {
        // Phân phối vào các bucket
        for (int i = 0; i < n; i++) {
            int digit = (abs(arr[i]) / (int)pow(10, d)) % 10;
            buckets[digit].push(arr[i]);
        }
        
        // Thu thập từ các bucket
        int index = 0;
        for (int i = 0; i < RADIX; i++) {
            while (!buckets[i].empty()) {
                arr[index++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    }
    
    // Xử lý số âm (nếu cần)
    queue<int> negative, positive;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negative.push(arr[i]);
        } else {
            positive.push(arr[i]);
        }
    }
    
    int i = 0;
    while (!negative.empty()) {
        arr[i++] = negative.front();
        negative.pop();
    }
    while (!positive.empty()) {
        arr[i++] = positive.front();
        positive.pop();
    }
    
    // Đảo ngược phần số âm
    for (int j = 0; j < i/2; j++) {
        swap(arr[j], arr[i-j-1]);
    }
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, -90, 802, 24, 2, 66, -23, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Mang truoc khi sap xep: ";
    inMang(arr, n);
    
    radixSort(arr, n);
    
    cout << "Mang sau khi sap xep: ";
    inMang(arr, n);
    
    return 0;
}
