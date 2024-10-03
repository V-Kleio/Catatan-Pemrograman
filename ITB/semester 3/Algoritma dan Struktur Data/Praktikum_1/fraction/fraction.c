#include "fraction.h"

int gcd(int a, int b) 
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D)
/* Mengirim TRUE jika pecahan valid */
{
    return D != 0;
}

void CreateFRACTION(FRACTION *F, int N, int R)
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */
{
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F)
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */
{
    int N, D;
    do
    {
        scanf("%i %i", &N, &D);
        if (!IsFRACTIONValid(N, D)) 
        {
            printf("FRACTION tidak valid\n");
        }
    } while (!IsFRACTIONValid(N, D));
    
    CreateFRACTION(F, N, D);
}

void WriteFRACTION(FRACTION F)
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan, 
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */
{
    F = SimplifyFRACTION(F);
    printf("%d/%d", Numerator(F), Denominator(F));
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    Numerator(F1) = Numerator(F1) * Denominator(F2) + Numerator(F2) * Denominator(F1);
    Denominator(F1) = Denominator(F1) * Denominator(F2);
    return SimplifyFRACTION(F1);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    Numerator(F2) *= -1;
    return AddFRACTION(F1, F2);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    Numerator(F1) *= Numerator(F2);
    Denominator(F1) *= Denominator(F2);
    return SimplifyFRACTION(F1);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2)
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    Numerator(F1) *= Denominator(F2);
    Denominator(F1) *= Numerator(F2);
    return SimplifyFRACTION(F1);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1)
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */
{
    Numerator(F1) *= n;
    return SimplifyFRACTION(F1);
}

FRACTION SimplifyFRACTION(FRACTION F)
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */
{
    FRACTION simpleFraction;
    simpleFraction = F;
    int gcdValue = gcd(Numerator(F), Denominator(F));
    Numerator(simpleFraction) /= gcdValue;
    Denominator(simpleFraction) /= gcdValue;
    if (Denominator(simpleFraction) < 0)
    {
        Numerator(simpleFraction) *= -1;
        Denominator(simpleFraction) *= -1;
    }
    return simpleFraction;
}

float ToDecimal(FRACTION F)
/* Mengonversi FRACTION ke bentuk desimal */
{
    return Numerator(F) / (float) Denominator(F);
}