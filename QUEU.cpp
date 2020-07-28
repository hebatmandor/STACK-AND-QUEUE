#include <iostream>

using namespace std;

int menupilihan(){
    int pilihan;
    do{
        cout << "Program Queue" << endl;
        cout << "_____________" << endl;
        cout << "1. tampilkan queue." << endl;
        cout << "2. tambah data." << endl;
        cout << "3. hapus data." << endl;
        cout << endl << "Masukkan pilihan: ";
        cin >> pilihan;
    }while(pilihan < 1 || pilihan > 3);

    return pilihan;
}

bool menuulangi(){
    char ulangi = 'n';
    cout << endl << "Continue (y/n)? ";
    cin >> ulangi;
    if(ulangi == 'y' || ulangi == 'Y'){
        return true;
    }
    else{
        return false;
    }
}

void tampilkanqueue(int data[], int size){
    cout << "Data queue: ";
    for(int i = 0; i < size; i++){
        cout << data[i] << "   ";
    }
}

void tambahdata(int data[], int & index){
    int databaru = 0;
    cout << "Data baru: ";
    cin >> data[index];
    index++;
}

void hapusdata(int data[], int & index){
    index--;
    for(int i = 0; i < index; i++){
        data[i] = data[i+1];
    }
    data[index] = 0;
}

int main(){
    int max = 0;
    cout << "Masukkan jumlah data: ";
    cin >> max;
    int data[max];
    int next = 0;
    bool ulangi = false;

    do{
        int pilihan = menupilihan();
        if(pilihan == 1){
            tampilkanqueue(data, next);
        }
        else if(pilihan == 2){
            if(next < max){
                tambahdata(data, next);
            }
            else{
                cout << "Queue penuh" << endl;
            }
            tampilkanqueue(data, next);
        }
        else if(pilihan == 3){
            if(next>0){
                hapusdata(data, next);
            }
            else{
                cout << "Queue kosong" << endl;
            }
            tampilkanqueue(data, next);
        }


        ulangi = menuulangi();
    }while(ulangi == true);

    return 0;
}
