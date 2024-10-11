#include "point.h"
#include <stdio.h>
#include <math.h>

void CreatePoint (POINT *P, float X, float Y)
{
    // Membentuk sebuah POINT dari komponen-komponennya
    Absis(*P) = X;
    Ordinat(*P) = Y;
    // Assign x dan y ke tipe data point
}

void BacaPOINT (POINT *P)
{
    /* 
    Membaca nilai absis dan ordinat dari keyboard dan membentuk POINT P berdasarkan dari nilai absis dan ordinat tersebut
    Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi
    Contoh: 1 2 akan membentuk POINT <1,2>
    I.S. Sembarang
    F.S. P terdefinisi 
    */
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
    // Menerima user input lalu create point
}

void TulisPOINT (POINT P)
{
    /*
    Nilai P ditulis ke layar dengan format "(X,Y)" 
    tanpa spasi, enter, atau karakter lain di depan, belakang, 
    atau di antaranya 
    Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    I.S. P terdefinisi
    F.S. P tertulis di layar dengan format "(X,Y)"
    */
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
    // Cukup jelas, print sesuai format
}

boolean EQ (POINT P1, POINT P2)
{
    // Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
    // Mengecek kesamaan absis dan ordinat
}

boolean NEQ (POINT P1, POINT P2)
{
    // Mengirimkan true jika P1 tidak sama dengan P2
    return Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2);
    // mengecek ketidaksamaan absis atau ordinat
}

boolean IsOrigin (POINT P)
{
    // Menghasilkan true jika P adalah titik origin
    return Absis(P) == 0 && Ordinat(P) == 0;
    // titik origin adalah titik (0,0)
}

boolean IsOnSbX (POINT P)
{
    // Menghasilkan true jika P terletak Pada sumbu X
    return Ordinat(P) == 0;
    // berada pada sumbu x ketika ordinat = 0 -> (x,0)
}

boolean IsOnSbY (POINT P)
{
    // Menghasilkan true jika P terletak pada sumbu Y
    return Absis(P) == 0;
    // berada pada sumbu y ketika absis = 0 -> (0,y)
}

int Kuadran (POINT P)
{
    /*
    Menghasilkan kuadran dari P: 1, 2, 3, atau 4
    Prekondisi : P bukan titik origin,
    dan P tidak terletak di salah satu sumbu
    */
    if (Absis(P) > 0 && Ordinat(P) > 0)
    {
        return 1;
    } // Setelah if ini, kemungkinan: salah satu negatif atau keduanya
    else if (Ordinat(P) > 0) // Kemungkinan y positif (x dipastikan negatif)
    {
        return 2;
    }
    else if (Absis(P) > 0) // Kemungkinan x positif (y dipastikan negatif)
    {
        return 4;
    }
    else // Pasti keduanya negatif
    {
        return 3;
    }
}

POINT NextX (POINT P)
{
    // Mengirim salinan P dengan absis ditambah satu
    POINT result;
    CreatePoint(&result, Absis(P) + 1, Ordinat(P));
    return result;
    // Cukup jelas
}

POINT NextY (POINT P)
{
    // Mengirim salinan P dengan ordinat ditambah satu
    POINT result;
    CreatePoint(&result, Absis(P), Ordinat(P) + 1);
    return result;
    // Cukup jelas
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    // Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY
    POINT result;
    CreatePoint(&result, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return result;
    // Cukup jelas
}

POINT MirrorOf (POINT P, boolean SbX)
{
    /*
    Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu
    Jika SbX bernilai true, maka dicerminkan terhadap sumbu X
    Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y
    */
    POINT result;
    if (SbX)
    {
        CreatePoint(&result, Absis(P), -Ordinat(P));
    }
    else
    {
        CreatePoint(&result, -Absis(P), Ordinat(P));
    }
    return result;
    /*
    Pencerminan terhadap sumbu x atau bukan
    terhadap sumbu x -> inverse tanda ordinat, absis tetap
    terhadap sumbu y -> inverse tanda absis, ordinat tetap
    */
}

float Jarak0 (POINT P)
{
    // Menghitung jarak P ke (0,0)
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
    // cukup jelas, rumus pythagoras
}

float Panjang (POINT P1, POINT P2)
{
    /*
    Menghitung panjang garis yang dibentuk P1 dan P2 
    Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. 
    Tuliskan spec fungsi yang lebih tepat. 
    */
    float deltaX = Absis(P2) - Absis(P1);
    float deltaY = Ordinat(P2) - Ordinat(P1);
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    // cukup jelas, rumus pythagoras
}

void Geser (POINT *P, float deltaX, float deltaY)
{
    /*
    I.S. P terdefinisi 
    F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY 
    */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
    // Beda dengan PlusDelta, PlusDelta membuat salinan point sedangkan ini tidak
}

void GeserKeSbX (POINT *P)
{
    /*
    I.S. P terdefinisi 
    F.S. P berada pada sumbu X dengan absis sama dengan absis semula. 
    Proses : P digeser ke sumbu X. 
    Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) 
    */
    Ordinat(*P) = 0;
    // cukup jelas
}

void GeserKeSbY (POINT *P)
{
    /*
    I.S. P terdefinisi
    F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. 
    Proses : P digeser ke sumbu Y. 
    Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) 
    */
    Absis(*P) = 0;
    // cukup jelas
}

void Mirror (POINT *P, boolean SbX)
{
    /*
    I.S. P terdefinisi 
    F.S. P dicerminkan tergantung nilai SbX atau SbY 
    Jika SbX true maka dicerminkan terhadap sumbu X 
    Jika SbX false maka dicerminkan terhadap sumbu Y 
    */
    if (SbX)
    {
        Ordinat(*P) = -Ordinat(*P);
    }
    else
    {
        Absis(*P) = -Absis(*P);
    }
    // Berbeda dengan MirrorOf, MirrorOf membuat salinan sedangkan ini tidak

}

void Putar (POINT *P, float Sudut)
{
    /*
    I.S. P terdefinisi 
    F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) 
    */
    float radian, targetX, targetY;
    radian = Sudut / 180.f * acos(-1);
    targetX = Absis(*P) * cosf(radian) + Ordinat(*P) * sinf(radian);
    targetY = Absis(*P) * (-sinf(radian)) + Ordinat(*P) * cosf(radian);
    CreatePoint(P, targetX, targetY);
    // Memutar Point searah jarum jam
    // convert derajat ke radian -> sudut / 180 * arccos(-1)
    // arccos(-1) = Pi
    // rumus targetX = x cos(radian) + y sin(radian)
    // rumus targetY = -x sin(radian) + y cos(radian)
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2)
{
    /*
    I.S. P1 dan P2 terdefinisi 
    Prekondisi: dijamin a dan b merupaka bilangan bertipe integer 
    F.S. Dibentuk sebuah persamaan garis y = ax + b yang memenuhi untuk P1 dan P2 
    Keluarkan nilai a dan b 
    Output a dan b tercetak di layar sebagai bilangan bertipe integer dengan format "(a,b)" 
    */
    int a, b;
    a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    b = Ordinat(P2) - (a * Absis(P2));
    printf("(%i,%i)", a, b);
    // a adalah gradien dengan rumus (y2 - y1) / (x2 - x1)
    // y = ax + b -> b = y - ax
}





