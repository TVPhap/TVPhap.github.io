Bài 1. Dùng stack khử đệ qui
(a) Viết chương trình đệ qui / khử đệ qui (dùng stack) cho bài toán tính số Fibonancy, đảo ngược số
(b) Viết chương trình đệ qui / khử đệ qui (dùng stack) cho bài toán đảo ngược số
(c) HanoiTower là một tháp có nhiều tầng, tầng nhỏ nằm trên tầng lớn. Sau đó viết phương thức di chuyển tháp này
từ vị trí 1 đến vị trí 3 thông qua vị trí trung gian 2; mỗi lần chỉ được di chuyển tầng trên cùng của tháp và tại mỗi
vị trí 1, 2, và 3 đều là tháp. Hãy viết chương trình đệ qui / khử đệ qui cho bài toán tháp Hà Nội.
#include <iostream>
#include <stack>
using namespace std;

// Phiên bản đệ quy
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// Phiên bản dùng stack để khử đệ quy
int fib_stack(int n) {
    if (n <= 1) return n;
    
    stack<int> s;
    s.push(n);
    int result = 0;
    
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        
        if (current <= 1) {
            result += current;
        } else {
            s.push(current - 1);
            s.push(current - 2);
        }
    }
    
    return result;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "Fibonacci (de quy): " << fib_recursive(n) << endl;
    cout << "Fibonacci (stack): " << fib_stack(n) << endl;
    
    return 0;
}
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Hàm đệ quy đảo ngược số
int reverse_recursive(int num, int rev = 0) {
    if (num == 0) return rev;
    return reverse_recursive(num / 10, rev * 10 + num % 10);
}

// Hàm dùng stack để đảo ngược số
int reverse_stack(int num) {
    if (num == 0) return 0;
    
    stack<int> s;
    while (num != 0) {
        s.push(num % 10);
        num /= 10;
    }
    
    int reversed = 0;
    int power = 1;
    while (!s.empty()) {
        reversed = reversed * 10 + s.top();
        s.pop();
    }
    
    return reversed;
}

int main() {
    int num;
    cout << "Nhap so: ";
    cin >> num;
    
    cout << "Dao nguoc (de quy): " << reverse_recursive(num) << endl;
    cout << "Dao nguoc (stack): " << reverse_stack(num) << endl;
    
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Cấu trúc lưu trữ một bước di chuyển
struct HanoiMove {
    int n;          // Số đĩa cần di chuyển
    char from;      // Cột nguồn
    char to;        // Cột đích
    char temp;      // Cột trung gian
};

// Phiên bản đệ quy
void hanoi_recursive(int n, char from, char to, char temp) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << from << " den " << to << endl;
        return;
    }
    hanoi_recursive(n-1, from, temp, to);
    cout << "Di chuyen dia " << n << " tu " << from << " den " << to << endl;
    hanoi_recursive(n-1, temp, to, from);
}

// Phiên bản dùng stack để khử đệ quy
void hanoi_stack(int n, char from, char to, char temp) {
    stack<HanoiMove> s;
    HanoiMove firstMove = {n, from, to, temp};
    s.push(firstMove);
    
    while (!s.empty()) {
        HanoiMove current = s.top();
        s.pop();
        
        if (current.n == 1) {
            cout << "Di chuyen dia 1 tu " << current.from << " den " << current.to << endl;
        } else {
            // Push các bước theo thứ tự ngược lại
            HanoiMove move3 = {current.n - 1, current.temp, current.to, current.from};
            s.push(move3);
            
            HanoiMove move2 = {1, current.from, current.to, current.temp};
            s.push(move2);
            
            HanoiMove move1 = {current.n - 1, current.from, current.temp, current.to};
            s.push(move1);
        }
    }
}

int main() {
    int n;
    cout << "Nhap so dia: ";
    cin >> n;
    
    cout << "Thap Ha Noi (de quy):" << endl;
    hanoi_recursive(n, 'A', 'C', 'B');
    
    cout << "\nThap Ha Noi (stack):" << endl;
    hanoi_stack(n, 'A', 'C', 'B');
    
    return 0;
}
