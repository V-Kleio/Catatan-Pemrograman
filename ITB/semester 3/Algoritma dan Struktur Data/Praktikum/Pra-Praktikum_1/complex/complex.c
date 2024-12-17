#include "complex.h"
#include <math.h>
#include <stdio.h>

boolean IsCOMPLEXValid(float Re, float Im)
{
    /* 
    Mengirim true jika Re dan Im valid untuk membentuk COMPLEX
    Dalam konteks kompleks, semua bilangan real adalah valid
    */
    return true;
    /*
    Pada deklarasi parameter -> (float Re, float Im), penggunaan fungsi harus menyediakan tipe data float pada argumen.
    Penggunaan fungsi ini akan selalu bernilai true. 
    */
}

void CreateComplex(COMPLEX *C, float Re, float Im)
{
    /* 
    Membentuk sebuah COMPLEX dari komponen-komponennya 
    */
    Real(*C) = Re;
    Imag(*C) = Im;
    /*
    Hanya meng-assign value Re dan Im ke complex *C
    */
}

void BacaCOMPLEX(COMPLEX *C)
{
    /* 
    I.S. : C tidak terdefinisi
    F.S. : C terdefinisi
    Proses : Membaca komponen Re dan Im dari pengguna 
    */
    
    float real, imaginer;
    scanf("%f %f", &real, &imaginer);
    CreateComplex(C, real, imaginer);
    /*
    Meminta input dari user untuk bilangan kompleks
    */
}

void TulisCOMPLEX(COMPLEX C)
{
    /* 
    I.S. : C sembarang
    F.S. : Nilai C ditulis dengan format "a + bi" atau "a - bi" (tanpa spasi) dan diakhiri newline
    Proses : Menulis nilai Re dan Im ke layar 
    */
    if(Imag(C) < 0)
    {
        printf("%.2f-%.2fi\n", Real(C), -Imag(C));
    }
    else
    {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    }

    /*
    Fungsi untuk print bilangan kompleks. Perlu dicek apakah bagian imaginernya negatif atau positif.
    print sesuai bilangan imaginer positif atau negatif
    */
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    /*
    Mengirim hasil penjumlahan C1 + C2 
    */
    COMPLEX result;
    CreateComplex(&result, Real(C1) + Real(C2), Imag(C1) + Imag(C2));
    return result;
    /*
    Fungsi untuk menjumlahkan masing-masing komponen dalam tipe data COMPLEX.
    */
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    /* 
    Mengirim hasil pengurangan C1 - C2 
    */
    COMPLEX result;
    CreateComplex(&result, Real(C1) - Real(C2), Imag(C1) - Imag(C2));
    return result;
    /*
    Fungsi untuk mengurangkan masing-masing komponen dalam tipe data COMPLEX.
    */
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    /* 
    Mengirim hasil perkalian C1 * C2
    Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i 
    */
    COMPLEX result;
    CreateComplex(&result, Real(C1) * Real(C2) - Imag(C1) * Imag(C2), Real(C1) * Imag(C2) + Imag(C1) * Real(C2));
    return result;
    /*
    Fungsi menjalankan perintah matematis sesuai rumus yang disediakan.
    a = Real(C1)
    b = Imag(C1)
    c = Real(C2)
    d = Imag(C2)
    */
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2)
{
    /*
    Mengirim hasil pembagian C1 / C2
    Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2)
    Jika denominator pecahan bernilai 0, maka kembalikan nilai 0+0i  
    */
    COMPLEX result;
    float denominator = pow(Real(C2), 2) + pow(Imag(C2), 2);
    if (denominator == 0)
    {
        CreateComplex(&result, 0, 0);
        return result;
    }
    CreateComplex(&result, (Real(C1) * Real(C2) + Imag(C1) * Imag(C2)) / denominator, (Imag(C1) * Real(C2) - Real(C1) * Imag(C2)) / denominator);
    return result;
    /*
    Fungsi untuk membagi complex
    Menggunakan Multiply complex untuk mengalikan C1 dan C2
    C2 di-conjugate agar sesuai dengan rumus sebelum dikalikan
    Setiap Real dan Imaginer dari hasil kali akan dibagi dengan denominator
    */
}

float AbsCOMPLEX(COMPLEX C)
{
    /* 
    Mengirim nilai absolut (modulus) dari C
    Rumus: |C| = sqrt(Re^2 + Im^2) 
    */
    float result;
    result = sqrt(pow(Real(C), 2) + pow(Imag(C), 2));
    return result;
    // Cukup jelas, sesuai dengan rumus
}

COMPLEX ConjugateCOMPLEX(COMPLEX C)
{
    /* 
    Mengirim hasil konjugasi dari C
    Rumus: Conj(C) = Re - i*Im
    */
    COMPLEX result;
    CreateComplex(&result, Real(C), -Imag(C));
    return result;
    // Mengganti Imaginer dari positif ke negatif atau sebaliknya
}

boolean CEQ(COMPLEX C1, COMPLEX C2)
{
    // Mengirimkan true jika C1 = C2 (Re dan Im sama)
    return Real(C1) == Real(C2) && Imag(C1) == Imag(C2);
    // Mengecek kesamaan real dan imaginer
}

boolean CNEQ(COMPLEX C1, COMPLEX C2)
{
    // Mengirimkan true jika C1 tidak sama dengan C2
    return Real(C1) != Real(C2) || Imag(C1) != Imag(C2);
    // Mengecek ketidaksamaan real atau imaginer
}




