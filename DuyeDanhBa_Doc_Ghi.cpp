#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct LienHe {
    string hoTen;
    string soDienThoai;
};

struct Node {
    LienHe data;
    Node* next;
};

struct DanhBa {
    Node* head;
    Node* tail;

    DanhBa() {
        head = NULL;
        tail = NULL;
    }
};

Node* taoNode(string hoTen, string soDienThoai) {
    Node* newNode = new Node();
    newNode->data.hoTen = hoTen;
    newNode->data.soDienThoai = soDienThoai;
    newNode->next = NULL;
    return newNode;
}

void themCuoi(DanhBa& db, string hoTen, string soDienThoai) {
    Node* newNode = taoNode(hoTen, soDienThoai);
    if (db.head == NULL) {
        db.head = db.tail = newNode;
    } else {
        db.tail->next = newNode;
        db.tail = newNode;
    }
}


void duyetXuoi(const DanhBa& db) {
    if (db.head == NULL) {
        cout << "Danh ba rong!\n";
        return;
    }
    cout << "\n================ DANH SACH LIEN HE (DUYET XUOI) ================\n";
    Node* temp = db.head;
    int stt = 1;
    while (temp != NULL) {
        cout << stt++ << ". " << temp->data.hoTen << " - " << temp->data.soDienThoai << endl;
        temp = temp->next;
    }
}

void duyetNguocDeQuy(Node* node, int& stt) {
    if (node == NULL) return;
    
    duyetNguocDeQuy(node->next, stt);
    
    cout << stt-- << ". " << node->data.hoTen << " - " << node->data.soDienThoai << endl;
}

void duyetNguoc(const DanhBa& db) {
    if (db.head == NULL) {
        cout << "Danh ba rong!\n";
        return;
    }

    int count = 0;
    Node* temp = db.head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "\n================ DANH SACH LIEN HE (DUYET NGUOC) ================\n";
    duyetNguocDeQuy(db.head, count);
}


void ghiFile(const DanhBa& db, string fileName) {
    ofstream file(fileName.c_str());
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file de ghi!\n";
        return;
    }

    Node* temp = db.head;
    while (temp != NULL) {
        file << temp->data.hoTen << endl;
        file << temp->data.soDienThoai << endl;
        temp = temp->next;
    }

    file.close();
    cout << "-> Da ghi du lieu danh ba vao file '" << fileName << "' thanh cong!\n";
}

void docFile(DanhBa& db, string fileName) {
    ifstream file(fileName.c_str());
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file de doc!\n";
        return;
    }

    string hoTen, soDienThoai;
    int dem = 0;
    while (getline(file, hoTen) && getline(file, soDienThoai)) {
        if (!hoTen.empty() && !soDienThoai.empty()) {
            themCuoi(db, hoTen, soDienThoai);
            dem++;
        }
    }

    file.close();
    cout << "-> Da doc thanh cong " << dem << " lien he tu file '" << fileName << "'!\n";
}

void giaiPhong(DanhBa& db) {
    Node* temp = db.head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    db.head = db.tail = NULL;
}

int main() {
    DanhBa db;
    string fileName = "danhba.txt";
    cout << "1. KHOI TAO DU LIEU BAN DAU:\n";
    themCuoi(db, "Nguyen Van A", "0901234567");
    themCuoi(db, "Tran Thi B", "0987654321");
    themCuoi(db, "Le Van C", "0911223344");
    ghiFile(db, fileName);
    giaiPhong(db);
    cout << "\n2. NAP DU LIEU TU FILE:\n";
    DanhBa dbMoi;
    docFile(dbMoi, fileName);
    duyetXuoi(dbMoi);
    duyetNguoc(dbMoi);
    giaiPhong(dbMoi);
    return 0;
}
