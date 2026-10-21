#include <iostream>
using namespace std;

int main() {
    int N;
    int K;
    int jumlah;
    int posisi = 0;


    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal (K): ";
    cin >> K;

    int* astronot = new int[N];
    jumlah = N;
    
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    cout << "\nUrutan eliminasi: ";
    while (jumlah > 1) {
        posisi = (posisi + K - 1) % jumlah;
        int korban = astronot[posisi];
        cout << korban << " ";
        for (int i = posisi; i < jumlah - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        jumlah--;
        if (korban % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }
        if (jumlah > 0) {
            posisi = posisi % jumlah;
        }
    }

    cout << "\nAstronot terakhir: " << astronot[0] << endl;

    delete[] astronot;

    return 0;
}