#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string namaAnda;
    int usiaAnda;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// Tambah Data di Depan Linked List
void insertDepan(string namaAnda, int usiaAnda) {
    Node* newNode = new Node;
    newNode->namaAnda = namaAnda;
    newNode->usiaAnda = usiaAnda;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
}

// Tambah Data di Belakang Linked List
void insertBelakang(string namaAnda, int usiaAnda) {
    Node* newNode = new Node;
    newNode->namaAnda = namaAnda;
    newNode->usiaAnda = usiaAnda;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

// Tambah Data di Tengah Linked List
void insertTengah(string namaAnda, int usiaAnda, string posisi) {
    Node* newNode = new Node;
    newNode->namaAnda = namaAnda;
    newNode->usiaAnda = usiaAnda;
    Node* temp = head;
    while (temp != nullptr && temp->namaAnda != posisi) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data " << posisi << " tidak ditemukan" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Hapus Data dari Linked List
void hapusData(string namaAnda) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->namaAnda != namaAnda) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Data " << namaAnda << " tidak ditemukan" << endl;
        return;
    }
    if (prev == nullptr) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }
    if (current == tail) {
        tail = prev;
    }
    delete current;
}

// Ubah Data di Linked List
void ubahData(string namaAnda, int usiaAnda, string namaBaru, int usiaBaru) {
    Node* current = head;
    while (current != nullptr && current->namaAnda != namaAnda) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Data " << namaAnda << " tidak ditemukan" << endl;
        return;
    }
    current->namaAnda = namaBaru;
    current->usiaAnda = usiaBaru;
}

// Tampilkan Seluruh Data dalam Linked List
void tampilkanData() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->namaAnda << "\t" << current->usiaAnda << endl;
        current = current->next;
    }
}

int main() {
    // Masukkan data pertama
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan namaAnda Anda: ";
    cin >> namaAnda;
    cout << "Masukkan usiaAnda Anda: ";
    cin >> usiaAnda;
    insertDepan(namaAnda, usiaAnda);

    // Masukkan data sesuai urutan
    insertBelakang("John", 19);
    insertBelakang("Jane", 20);
    insertTengah("Futaba", 18, "John");
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

    // Hapus data Akechi
    hapusData("Akechi");

    // Tambahkan data Igor di awal
    insertDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn
    ubahData("Michael", 18, "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Data Mahasiswa:" << endl;
    tampilkanData();

    return 0;
}
