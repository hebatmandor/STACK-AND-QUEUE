#include <iostream>

using namespace std;

int menupilihan(){
    int pilihan;
    do{
        cout << "Program Stack" << endl;
        cout << "_____________" << endl;
        cout << "1. tampilkan stack." << endl;
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

void tampilkanstack(int data[], int size){
    cout << "Data stack: ";
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
    	system("CLEAR");
        int pilihan = menupilihan();
        if(pilihan == 1){
            tampilkanstack(data, next);
        }
        else if(pilihan == 2){
            if(next < max){
                tambahdata(data, next);
            }
            else{
                cout << "Stack penuh" << endl;
            }
            tampilkanstack(data, next);
        }
        else if(pilihan == 3){
            if(next>0){
                hapusdata(data, next);
            }
            else{
                cout << "Stack kosong" << endl;
            }
            tampilkanstack(data, next);
        }


        ulangi = menuulangi();
    }while(ulangi == true);

    return 0;
}
