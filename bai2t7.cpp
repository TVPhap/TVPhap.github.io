#include <bits/stdc++.h>
using namespace std;

// Cấu trúc SinhVien
struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    SinhVien* next;
};

// So sánh sinh viên theo từng tiêu chí
bool compareByName(const SinhVien* a, const SinhVien* b) {
    return strcmp(a->hoTen, b->hoTen) < 0;
}

bool compareByAddress(const SinhVien* a, const SinhVien* b) {
    return strcmp(a->diaChi, b->diaChi) < 0;
}

bool compareByClass(const SinhVien* a, const SinhVien* b) {
    return strcmp(a->lop, b->lop) < 0;
}

bool compareByYear(const SinhVien* a, const SinhVien* b) {
    return a->khoa < b->khoa;
}

// Nhập một sinh viên
void nhapSinhVien(SinhVien& sv) {
    cout << "Nhập họ tên: ";
    cin.ignore();
    cin.getline(sv.hoTen, 50);
    cout << "Nhập địa chỉ: ";
    cin.getline(sv.diaChi, 70);
    cout << "Nhập lớp: ";
    cin.getline(sv.lop, 10);
    cout << "Nhập khóa: ";
    cin >> sv.khoa;
}

// Xuất thông tin một sinh viên
void xuatSinhVien(const SinhVien& sv) {
    cout << "Họ tên: " << sv.hoTen << ", Địa chỉ: " << sv.diaChi 
         << ", Lớp: " << sv.lop << ", Khóa: " << sv.khoa << endl;
}

// Thêm sinh viên vào danh sách
void addStudent(SinhVien*& head, const SinhVien& sv) {
    SinhVien* newNode = new SinhVien(sv);
    newNode->next = head;
    head = newNode;
}

// Xóa sinh viên theo tiêu chí
void deleteStudentByName(SinhVien*& head, const char* name) {
    SinhVien* current = head;
    SinhVien* prev = nullptr;

    while (current && strcmp(current->hoTen, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    }
}

void deleteStudentByAddress(SinhVien*& head, const char* address) {
    SinhVien* current = head;
    SinhVien* prev = nullptr;

    while (current && strcmp(current->diaChi, address) != 0) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        delete current;
    }
}

// Xuất danh sách sinh viên
void printList(SinhVien* head) {
    while (head) {
        xuatSinhVien(*head);
        head = head->next;
    }
}

// Sắp xếp danh sách bằng Selection Sort
void selectionSort(SinhVien*& head, bool (*compare)(const SinhVien*, const SinhVien*)) {
    for (SinhVien* i = head; i && i->next; i = i->next) {
        SinhVien* minNode = i;
        for (SinhVien* j = i->next; j; j = j->next) {
            if (compare(j, minNode)) {
                minNode = j;
            }
        }
        // Hoán đổi dữ liệu
        swap(*i, *minNode);
        swap(i->next, minNode->next);
    }
}

// Giải phóng bộ nhớ danh sách
void clearList(SinhVien*& head) {
    while (head) {
        SinhVien* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    SinhVien* list = nullptr;

    // Nhập 10 sinh viên
    for (int i = 0; i < 10; ++i) {
        SinhVien sv;
        nhapSinhVien(sv);
        addStudent(list, sv);
    }

    // In danh sách
    cout << "Danh sách sinh viên: " << endl;
    printList(list);

    // Xóa sinh viên có tên "Nguyen Van Teo"
    deleteStudentByName(list, "Nguyen Van Teo");

    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    deleteStudentByAddress(list, "Nguyen Van Cu");

    // Thêm sinh viên mới
    SinhVien newSV = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009, nullptr};
    addStudent(list, newSV);

    // Sắp xếp danh sách theo tên
    selectionSort(list, compareByName);

    // In danh sách sau khi cập nhật
    cout << "Danh sách sinh viên sau khi cập nhật: " << endl;
    printList(list);

    return 0;
}
