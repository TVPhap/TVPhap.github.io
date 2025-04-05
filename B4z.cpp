#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void xuLyDuLieu() {
    // Khởi tạo hàng đợi và ngăn xếp
    queue<int> hangDoi;
    stack<int> nganXep;

    // Dữ liệu đầu vào
    int duLieu[] = {4, 5, 2, 2, 1, 6};
    int kichThuoc = sizeof(duLieu) / sizeof(duLieu[0]);

    // Thêm dữ liệu vào hàng đợi và ngăn xếp
    for (int i = 0; i < kichThuoc; i++) {
        hangDoi.push(duLieu[i]);
        nganXep.push(duLieu[i]);
    }

    // Xuất kết quả từ hàng đợi
    cout << "Kết quả từ hàng đợi:\n";
    while (!hangDoi.empty()) {
        cout << hangDoi.front() << " ";
        hangDoi.pop();
    }
    cout << endl;

    // Xuất kết quả từ ngăn xếp
    cout << "Kết quả từ ngăn xếp:\n";
    while (!nganXep.empty()) {
        cout << nganXep.top() << " ";
        nganXep.pop();
    }
    cout << endl;
}

int main() {
    xuLyDuLieu();
    return 0;
}
