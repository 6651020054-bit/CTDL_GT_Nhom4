#include <iostream>
#include <string>
using namespace std;
struct LienHe {
    string ten;
    string sdt;
};
struct Node {
    LienHe duLieu;
    Node* prev;
    Node* next;
};
struct DanhBa {
    Node* head;
    Node* tail;
};
struct NodeLichSu {
    string sdt;
    NodeLichSu* next;
};
struct LichSuCuocGoi {
    NodeLichSu* head;
};
void KhoiTaoDanhBa(DanhBa &db) {
    db.head = NULL;
    db.tail = NULL;
}
Node* TaoNode(LienHe lh) {
    Node* nodeMoi = new Node;
    nodeMoi->duLieu = lh;
    nodeMoi->prev = NULL;
    nodeMoi->next = NULL;
    
    return nodeMoi;
}
void GiaiPhongBoNho(DanhBa &db) {
    Node* p = db.head;
    while (p != NULL) {
        Node* nodeCanXoa = p; 
        p = p->next;          
        delete nodeCanXoa;    
    }
    db.head = NULL;
    db.tail = NULL;
    cout << "[He thong] Da giai phong toan bo bo nho cua Danh Ba!\n";
}
int main() {
    DanhBa db;
    KhoiTaoDanhBa(db);
    cout << "Da khoi tao danh ba. Kiem tra Head: " << db.head << "\n";
    LienHe lh1 = {"Nguyen Van A", "0901234567"};
    Node* node1 = TaoNode(lh1); 
    if (node1 != NULL) {
        cout << "Da tao Node thanh cong: " << node1->duLieu.ten << " - " << node1->duLieu.sdt << "\n";
    }
    db.head = node1;
    db.tail = node1;
    GiaiPhongBoNho(db);
    cout << "Kiem tra lai Head sau khi xoa: " << db.head << "\n";
    return 0;
}