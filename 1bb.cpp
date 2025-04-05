Stack bằng danh sách liên kết (Linked List-based Stack)
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedStackInt {
private:
    Node* top;
public:
    LinkedStackInt() : top(nullptr) {}
    
    ~LinkedStackInt() {
        clear();
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return top->data;
    }
    
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};
b)Ứng dụng ngăn xếp để đảo số
int daoSo(int n) {
    StackInt s;
    while (n != 0) {
        s.push(n % 10);
        n /= 10;
    }
    
    int dao = 0;
    int muoi = 1;
    while (!s.isEmpty()) {
        dao = dao * 10 + s.pop();
    }
    return dao;
}
c)
bool laXauDoiXung(string str) {
    StackInt s;
    int n = str.length();
    
    // Đẩy nửa đầu vào stack
    for (int i = 0; i < n/2; i++) {
        s.push(str[i]);
    }
    
    // Bỏ qua ký tự giữa nếu độ dài lẻ
    int start = (n % 2 == 0) ? n/2 : n/2 + 1;
    
    // So sánh với nửa sau
    for (int i = start; i < n; i++) {
        if (s.pop() != str[i]) {
            return false;
        }
    }
    return true;
}
d)
void inNhiPhan(int n) {
    StackInt s;
    if (n == 0) {
        cout << "0";
        return;
    }
    
    while (n > 0) {
        s.push(n % 2);
        n /= 2;
    }
    
    while (!s.isEmpty()) {
        cout << s.pop();
    }
}
e)
#include <stack>
#include <cctype>

int doUuTien(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string trungToSangHauTo(string trungTo) {
    stack<char> s;
    string hauTo = "";
    
    for (char c : trungTo) {
        if (isalnum(c)) {
            hauTo += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                hauTo += s.top();
                s.pop();
            }
            s.pop(); // Xóa '(' khỏi stack
        }
        else {
            while (!s.empty() && doUuTien(s.top()) >= doUuTien(c)) {
                hauTo += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while (!s.empty()) {
        hauTo += s.top();
        s.pop();
    }
    
    return hauTo;
}
int tinhHauTo(string hauTo) {
    stack<int> s;
    
    for (char c : hauTo) {
        if (isdigit(c)) {
            s.push(c - '0');
        }
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': {
                    int ketQua = 1;
                    for (int i = 0; i < b; i++) ketQua *= a;
                    s.push(ketQua);
                    break;
                }
            }
        }
    }
    
    return s.top();
}
