#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama_produk;
    int harga;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

// Tambah Data di Depan Linked List
void insertDepan(string nama_produk, int harga) {
    Node* newNode = new Node;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
}

// Tambah Data di Belakang Linked List
void insertBelakang(string nama_produk, int harga) {
    Node* newNode = new Node;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;
    newNode->next = nullptr;
    if (tail != nullptr) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    newNode->prev = tail;
    tail = newNode;
}

// Tambah Data di Tengah Linked List
void insertTengah(string nama_produk, int harga, string posisi) {
    Node* newNode = new Node;
    newNode->nama_produk = nama_produk;
    newNode->harga = harga;

    Node* temp = head;
    while (temp != nullptr && temp->nama_produk != posisi) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Produk " << posisi << " tidak ditemukan" << endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Hapus Data dari Linked List
void hapusData(string nama_produk) {
    Node* current = head;
    while (current != nullptr && current->nama_produk != nama_produk) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Produk " << nama_produk << " tidak ditemukan" << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;
}

// Ubah Data di Linked List
void ubahData(string nama_produk, int harga_baru) {
    Node* current = head;
    while (current != nullptr && current->nama_produk != nama_produk) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Produk " << nama_produk << " tidak ditemukan" << endl;
        return;
    }
    current->harga = harga_baru;
}

// Tampilkan Seluruh Data dalam Linked List
void tampilkanData() {
    cout << "Nama Produk\tHarga" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << current->nama_produk << "\t\t" << current->harga << endl;
        current = current->next;
    }
}

int main() {
    // Masukkan data awal
    insertBelakang("Originote", 60000);
    insertBelakang("Somethinc", 150000);
    insertBelakang("Skintific", 100000);
    insertBelakang("Wardah", 50000);
    insertBelakang("Hanasui", 30000);

    // Modifikasi operasi
    insertTengah("Azarine", 65000, "Somethinc");
    hapusData("Wardah");
    ubahData("Hanasui", 55000);

    // Tampilkan menu
    int choice;
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string nama_produk;
            int harga;
            cout << "Masukkan nama produk: ";
            cin >> nama_produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            insertBelakang(nama_produk, harga);
            break;
        }
        case 2: {
            string nama_produk;
            cout << "Masukkan nama produk yang ingin dihapus: ";
            cin >> nama_produk;
            hapusData(nama_produk);
            break;
        }
        case 3: {
            string nama_produk;
            int harga_baru;
            cout << "Masukkan nama produk yang ingin diubah: ";
            cin >> nama_produk;
            cout << "Masukkan harga baru: ";
            cin >> harga_baru;
            ubahData(nama_produk, harga_baru);
            break;
        }
        case 4: {
            string nama_produk, nama_setelah;
            int harga;
            cout << "Masukkan nama produk baru: ";
            cin >> nama_produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            cout << "Masukkan nama produk setelahnya: ";
            cin >> nama_setelah;
            insertTengah(nama_produk, harga, nama_setelah);
            break;
        }
        case 5: {
            string nama_produk;
            cout << "Masukkan nama produk yang ingin dihapus: ";
            cin >> nama_produk;
            hapusData(nama_produk);
            break;
        }
        case 6: {
            while (head != nullptr) {
                hapusData(head->nama_produk);
            }
            cout << "Seluruh data berhasil dihapus" << endl;
            break;
        }
        case 7: {
            tampilkanData();
            break;
        }
        case 8: {
            return 0;
        }
        default: {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    }

    return 0;
}
