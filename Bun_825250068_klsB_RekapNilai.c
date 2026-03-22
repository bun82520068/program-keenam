#include <stdio.h>

// fungsi untuk menginput jumlah mahasiswa dengan validasi
int inputJumlahMahasiswa() {
    int n;
    do {
        printf("Masukkan jumlah mahasiswa (maks 10): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);
    return n;
}
// Fungsi untuk input nilai tugas, UTS, dan UAS
void inputNilaiMahasiswa(int *tugas, int *uts, int *uas) {
    printf("Nilai Tugas : ");
    scanf("%d", tugas);

    printf("Nilai UTS   : ");
    scanf("%d", uts);

    printf("Nilai UAS   : ");
    scanf("%d", uas);
}

float hitungNilaiAkhir(int tugas, int uts, int uas) {
    return 0.3f * tugas + 0.3f * uts + 0.4f * uas;
}

// untuk mahasiswa yang nilai akhirnya < 60, berikan kesempatan remedial
float prosesRemedial(float nilaiAkhir) {
    if (nilaiAkhir < 60) {
        float remedial;
        printf("Nilai < 60, masukkan nilai remedial: ");
        scanf("%f", &remedial);

        if (remedial > nilaiAkhir) {
            return remedial;
        }
    }
    return nilaiAkhir;
}

//fungsi menentukan predikat berdasarkan nilai akhir dari A sampai D
char tentukanPredikat(float nilaiAkhir) {
    if (nilaiAkhir >= 80)
        return 'A';
    else if (nilaiAkhir >= 70)
        return 'B';
    else if (nilaiAkhir >= 60)
        return 'C';
    else
        return 'D';
}
// fungsi untuk memperbarui statistik kelas
void updatenilai(float nilaiAkhir, float *total, float *maks, float *min, int index) {

    *total += nilaiAkhir;

    if (index == 0) {
        *maks = nilaiAkhir;
        *min  = nilaiAkhir;
    } else {
        if (nilaiAkhir > *maks)
            *maks = nilaiAkhir;
        if (nilaiAkhir < *min)
            *min = nilaiAkhir;
    }
}

// fungsi untuk mencetak hasil akhir ke layar terminal
void Hasil(float rata, int A, int B, int C, int D, float maks, float min) {

    printf("\n===== HASIL AKHIR =====\n");
    printf("Rata-rata kelas  : %.2f\n", rata);
    printf("Jumlah A         : %d\n", A);
    printf("Jumlah B         : %d\n", B);
    printf("Jumlah C         : %d\n", C);
    printf("Jumlah D         : %d\n", D);
    printf("Nilai tertinggi  : %.2f\n", maks);
    printf("Nilai terendah   : %.2f\n", min);
}

// program utamanya

int main() {

    int n = inputJumlahMahasiswa();

    int tugas, uts, uas;
    float nilaiAkhir;

    float totalNA = 0;
    float maks = 0, min = 0;

    int jumlahA = 0, jumlahB = 0, jumlahC = 0, jumlahD = 0;

    for (int i = 0; i < n; i++) {

        printf("\nMahasiswa ke-%d\n", i + 1);

        inputNilaiMahasiswa(&tugas, &uts, &uas);// memanggil fungsi untuk user menginput nilai tugas, UTS, dan uas

        nilaiAkhir = hitungNilaiAkhir(tugas, uts, uas);// memanggil fungsi untuk menghitung nilai akhir
        nilaiAkhir = prosesRemedial(nilaiAkhir);// memanggil fungsi untuk memproses nilai remedial jika nilai akhir < 60

        updatenilai(nilaiAkhir, &totalNA, &maks, &min, i);// pemanggilan fungsi yang memperbarui statistik kelas (total nilai akhir, nilai maksimum, dan nilai minimum)

        char predikat = tentukanPredikat(nilaiAkhir);//memanggil fungsi untuk menentukan predikat berdasarkan nilai akhir dan menyimpan predikat tersebut dalam variabel char

        if (predikat == 'A') jumlahA++;
        else if (predikat == 'B') jumlahB++;
        else if (predikat == 'C') jumlahC++;
        else jumlahD++;
    }

    float rataKelas = totalNA / n;

    Hasil(rataKelas, jumlahA, jumlahB, jumlahC, jumlahD, maks, min);// pemanggilan fungsi untuk mencetak hasil akhir ke layar terminal

    return 0;
}
