#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int pilihmenu, inputjumlahdata, totaldata = 0, pilihmenupencarian, carihargabarang ;
    int jumlahbarang[100], hargabarang[100], temp;
    string namabarang[100], carinamabarang;
    bool found = false;
do
{   
    cout << setfill('-') << setw(44) << "-" << setfill(' ') << endl;
    cout << "SELAMAT DATANG DI SISTEM TOKO KELONTONG B-2" << endl;
    cout << setfill('-') << setw(44) << "-" << setfill(' ') << endl;
    cout << "Silahkan memilih menu yang tersedia :3" << endl;
    cout << "----- MENU ----- : " << endl;
    cout <<"1. INPUT DATA BARANG " << endl;
    cout <<"2. TAMPILKAN DATA BARANG" << endl;
    cout <<"3. CARI BARANG" << endl;
    cout <<"0. exit" << endl;
    cout << "pilih : "; cin >> pilihmenu;
    system("pause");
    system("cls");
    if (cin.fail()|| pilihmenu > 3|| pilihmenu < 0) {
        cout << "ERROR!!!: Anda memilih menu yang TIDAK ADA!!" << endl;
        cout << "\n";
        system("pause");
        system("cls");
    }
    switch (pilihmenu) {
    case 1:
            cout << setfill('-') << setw(39) << "-" << setfill(' ') << endl;
            cout << "MENU INPUT DATA BARANG" << endl;
            cout << setfill('-') << setw(39) << "-" << setfill(' ') << endl;
            cout << "BANYAK BARANG YANG INGIN DIMASUKKAN : "; cin >> inputjumlahdata;
            cout << "\n";

            if (cin.fail()|| inputjumlahdata < 0) {
                cout << "ERROR!!!: Masukkan angka yang VALID!!!" << endl;
                cout << "\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("pause");
                system("cls");
            }
            for (int i = 0; i < inputjumlahdata; i++) {
                cout << setfill('-') << setw(39) << "-" << setfill(' ') << endl;
                cin.ignore();
                cout << i + 1 << ". Nama barang   : "; getline(cin, namabarang[totaldata]);
                cout << "  " << " Jumlah barang : "; cin >> jumlahbarang[totaldata];
                cout << "  " << " Harga barang  : "; cin >> hargabarang[totaldata];
                cout <<"\n";
                totaldata++;
            }
            system("cls");
            break;
    case 2:
            cout << "MENU TAMPILKAN BARANG" << endl;
            cout << "*urut berdasarkan huruf depan" << endl;
            for (int i = 0; i < totaldata - 1 ; i++)
            {
                for (int j = 0; j < totaldata - 1 - i ; j++){
                    if (namabarang[j]>namabarang[j+1]){
                        swap(namabarang[j], namabarang[j+1]);
                        swap(jumlahbarang[j], jumlahbarang[j+1]);
                        swap(hargabarang[j], hargabarang[j+1]);
                    }
                }
            }
            for (int i = 0; i < totaldata; i++) {
                namabarang[i][0] = toupper(namabarang[i][0]);
            }
            cout << setfill('=') << setw(50) << "=" << setfill(' ') << endl;
            cout << setw(5) << left << "No"
            << setw(21) << left << "Nama Barang"
            << setw(15) << left << "Jumlah"
            << setw(15) << left << "Harga" << endl;
            cout << setfill('=') << setw(50) << "=" << setfill(' ') << endl;
            for (int i = 0; i < totaldata; i++) {
                cout << setw(5) << left << i + 1
                << setw(23) << left << namabarang[i]
                << setw(13) << left << jumlahbarang[i]
                << left << "Rp." << hargabarang[i] << endl;
            }
            cout << setfill('=') << setw(50) << "=" << setfill(' ') << endl;
            cout << "\n";
            system("pause");
            system("cls");
            break;
    case 3:
            cout << "MENU PENCARIAN BARANG" << endl;
            cout <<"1. BERDASARKAN NAMA (BINARY) " << endl;
            cout <<"2. BERDASARKAN HARGA (SEQUENTIAL)" << endl;
            cout << "pilih : "; cin >> pilihmenupencarian;
            if (cin.fail()|| pilihmenupencarian < 0) {
                cout << "ERROR!!!: Menu yang anda pilih untuk mencari barang TIDAK VALID!!" << endl;
                cout << "\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("pause");
                system("cls");
            }
            switch (pilihmenupencarian)
            {
            case 1 :
                int awal , tengah, akhir;
                found = false;
                cin.ignore();
                cout << "Masukkan nama barang yang dicari *huruf awal kapital : "; getline(cin, carinamabarang);
                awal = 0;
                akhir = totaldata - 1;
                while (awal <= akhir) {
                    tengah = (awal + akhir)/2;
                    if (namabarang[tengah] == carinamabarang) {
                        found = true;
                        cout << "\n";
                        cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
                        cout << setw(21) << left << "Nama Barang"
                        << setw(15) << left << "Jumlah"
                        << setw(15) << left << "Harga" << endl;
                        cout << setfill('=') << setw(45) << "=" << setfill(' ') << endl;
                        cout << setw(23) << left << namabarang[tengah]
                        << setw(13) << left << jumlahbarang[tengah]
                        << left << "Rp." << hargabarang[tengah] << endl;
                    }
                    if (carinamabarang < namabarang[tengah]) {
                        akhir = tengah -1;
                    } else {
                        awal = tengah + 1;
                    }
                } if (!found) {
                    cout << "barang '"<< carinamabarang << "' tidak ditemukan" << endl;
                }
                cout <<"\n";
                system("pause");
                system("cls");
                break;
            case 2:
                found = false;
                cout << "masukkan harga dari barang yang dicari : "; cin >> carihargabarang;
                for (int i = 0; i < totaldata; i++) {
                    if (hargabarang[i] == carihargabarang) {
                        found = true;
                        cout <<"\n";
                        cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;
                        cout << setw(21) << left << "Nama Barang"
                        << setw(15) << left << "Jumlah"
                        << setw(15) << left << "Harga" << endl;
                        cout << setfill('=') << setw(45) << "=" << setfill(' ') << endl;
                        cout << setw(23) << left << namabarang[i]
                        << setw(13) << left << jumlahbarang[i]
                        << left << "Rp." << hargabarang[i] << endl;
                        cout <<"\n";
                    } 
                } if (!found) {
                    cout << "barang dengan harga Rp."<< carihargabarang << " tidak ditemukan" << endl;
                }
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
        break;
    default:
        break;
    }
} while (pilihmenu !=0);
    cout << "TERIMAKASIH SUDAH MENGGUNAKAN SISTEM TOKO KELONTONG B-2" << endl;
    return 0;
}
