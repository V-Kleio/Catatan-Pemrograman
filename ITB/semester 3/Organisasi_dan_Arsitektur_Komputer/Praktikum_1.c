#include <stdio.h>

/*
Ubah statement "return" pada setiap fungsi dengan satu atau lebih baris kode C yang mengimplementasikan fungsi tersebut. Kode harus mengikuti style:

int fungsi(arg1, arg2, ...) {
    int var1 = Expr1;
    ...
    int varX = ExprX;

    varY = ExprY;
    ...
    varZ = ExprZ;
    return ExprR;
}

Setiap "Expr" adalah ekspresi HANYA menggunakan:
1. Konstanta integer 0 hingga 255 (0xFF), inklusif, Anda tidak diperbolehkan menggunakan konstanta besar seperti 0xffffffff kecuali dituliskan pada soal.
2. Argumen fungsi dan variabel lokal. (tidak ada variabel global).
3. Operasi integer uner ! ~
4. Operasi integer biner & ^ | + << >>

Beberapa soal merestriksi jumlah operator. Setiap "Expr" terdiri dari beberapa operator. Anda tidak dibatasi oleh 1 operator per baris.

Anda sangat dilarang untuk:
1. Menggunakan control constructs apapun, seperti if, do, while, for, switch, dll.
2. Menggunakan macro.
3. Membuat fungsi baru di file ini.
4. Memanggil fungsi lain.
5. Menggunakan operasi lain, seperti &&, ||, -, atau ?:
6. Menggunakan bentuk casting apapun.
7. Menggunakan tipe data selain int. Ini berarti Anda tidak diperbolehkan menggunakan array, struct, atau union.

Anda dapat berasumsi mesin Anda:
1. Menggunakan 2's complement untuk representasi bilangan 32-bit.
2. Menggunakan right shift secara aritmetik.
3. Memiliki perilaku unpredictable ketika menggeser integer lebih dari ukuran word.

Aturan Coding soal Float

Untuk soal yang membutuhkan operasi floating point, style koding lebih lenient. Anda diperbolehkan menggunakan ints dan unsigneds. Anda dapat menggunakan arbitrary integer dan konstanta unsigned.

Anda sangat dilarang untuk:
1. Menggunakan macro.
2. Membuat fungsi baru di file ini.
3. Memanggil fungsi lain.
4. Menggunakan bentuk casting apapun.
5. Menggunakan tipe data selain int atau unsigned. Ini berarti Anda tidak diperbolehkan menggunakan array, struct, atau union.
6. Menggunakan floating point apapun untuk tipe data, operasi, atau konstanta.

Notes:
Setiap fungsi memiliki jumlah operator maximum (! ~ & ^ | + << >>) yang boleh digunakan untuk mengimplementasikan fungsi.
NB: "=" tidak dihitung. Anda dapat menggunakan ini sebanyak apapun tanpa penalti.
*/

/*
[WAJIB]

chicken_or_beef = Ekstrak 4 bit kedua dari chicken dan ekstrak 4 bit pertama dari beef*2, kemudian gabungkan dengan bitwise OR.

(Di sini, 4 bit pertama artinya 4 bit paling kanan, yaitu bit ke-0 hingga bit ke-3, dan 4 bit kedua artinya 4 bit berikutnya, yaitu bit ke-4 hingga bit ke-7.)

Contoh:
chicken_or_beef(0b10010101, 0b11111000) = 0b1001
chicken_or_beef(0b01010000, ob10001101) = 0b1111
chicken_or_beef(0b01100000, 0b11111111) = 0b1110

Perhatikan bahwa nilai chicken dan beef tidak terbatas pada 8 bit pertama sehingga Anda harus pastikan bit lain mati.

Legal ops   : << >> | &
Max ops     : 5
Rating      : 1
*/
int chicken_or_beef(int chicken, int beef) {
    int maskingBit = 0xF;
    int bitChicken = chicken >> 4;
    int bitBeef = beef << 1;
    return (bitChicken | bitBeef) & maskingBit;
}
/*
PENJELASAN

Pertama, untuk mendapatkan 4 bit kedua dari chicken, perlu dilakukan right shift sebanyak 4 kali.

Contoh: 10010101 >> 4 = 00001001 (1001 bergeser ke kanan 4 kali)

Kemudian, untuk mendapatkan 4 bit pertama dari beef*2, perlu dilakukan left shift sebanyak 1 kali untuk mengalikan beef dengan 2.

Contoh: 00000110 << 1 = 00001100 (0110 bergeser ke kiri 1 kali)
pada 0110, bernilai 6 (0*8 + 1*4 + 1*2 + 0*1 = 6), 
digeser ke kiri 1 kali menjadi 1100, bernilai 12 (1*8 + 1*4 + 0*2 + 0*1 = 12)
(0*8 + 1*4 + 1*2 + 0*1) * 2 = (0*16 + 1*8 + 1*4 + 0*2)

Kemudian, hasil dari 4 bit kedua dari chicken dan 4 bit pertama dari beef*2 di-OR-kan. 

Untuk hanya mengambil 4 bit pertama saja, perlu dilakukan masking dengan 0xF (1111) agar bit selain 4 bit pertama lainnya menjadi 0.
*/


/*
[WAJIB]

masquerade - Kembalikan angka terkecil kedua dalam representasi integer two's complement.

Contoh:
(Untuk soal ini tidak diberikan contoh karena output hanya satu).

Legal ops   : ^ ~ >> <<
Max ops     : 4
Rating      : 1
*/
int masquerade() {
    int initialBit = 0x1;
    int min = 0x1 << 31;
    return min ^ initialBit;
}

/*
PENJELASAN

Pertama, kita perlu mendapatkan nilai terkecil dalam representasi two's complement 32-bit, yaitu 0x80000000. Ini dapat diperoleh dengan melakukan left shift pada 1 sebanyak 31 kali.

0x1 << 31 = 0x80000000

Kemudian, untuk mendapatkan angka terkecil kedua, kita perlu mengubah bit paling kanan dari 0 menjadi 1. Ini dapat dilakukan dengan operasi XOR dengan 0x1.

0x80000000 ^ 0x1 = 0x80000001

Jadi, hasil akhirnya adalah 0x80000001, yang merupakan angka terkecil kedua dalam representasi two's complement 32-bit.
*/


/*
[WAJIB]

airani_iofifteen - Kembalikan 1 apabila iofi == 15, dan 0 apabila tidak

Contoh:
airani_iofifteen(15) = 1
airani_iofifteen(-15) = 0
airani_iofifteen(13523015) = 0

Legal ops   : ! & >>
Max ops     : 15
Rating      : 1
*/
int airani_iofifteen(int iofi) {
    int isFifteen = !(iofi >> 4);
    isFifteen = (iofi >> 3) & 1; 
    isFifteen = isFifteen & ((iofi >> 2) & 1);
    isFifteen = isFifteen & ((iofi >> 1) & 1);
    isFifteen = isFifteen & (iofi & 1);

    return isFifteen;
}
/*
[PENJELASAN]

Pertama, kita perlu melakukan masking pada iofi dengan 0xF (1111) agar hanya 4 bit pertama yang diambil.

Contoh: 13523015 & 0xF = 7 (1111 & 1111 = 111)

Kemudian, kita perlu melakukan XOR antara hasil masking dengan 0xF (1111) untuk membandingkan apakah hasil masking sama dengan 0xF (1111) atau tidak.

Contoh: 7 ^ 0xF = 8 (111 ^ 1111 = 1000)

Jika hasil XOR sama dengan 0, maka fungsi akan mengembalikan 1, jika tidak, maka fungsi akan mengembalikan 0.

Contoh: 8 ^ 0xF = 0 (1000 ^ 1111 = 0000)

Sehingga, fungsi akan mengembalikan 0.
*/

/*
[WAJIB]

yobanashi_deceive - Kembalikan sqrt(sqrt(sqrt(f))) dengan pembulatan ke float terdekat ke bawah yang bisa direpresentasikan.

Parameter f adalah sebuah float dalam format 32 bits untuk Exponent dan 0 bits untuk Mantissa. Kembalikan dalam format yang sama.

Contoh:
yobanashi_deceive(0b0) = 0
yobanashi_deceive(0b001011) = 0b1
yobanashi_deceive(0b10011010001) = 0b10011010

Legal ops  : >>
Max ops   : 1
Rating    : 2
*/
unsigned yobanashi_deceive(unsigned f) {
    return f >> 3;
}
/*
[PENJELASAN]

Untuk menghitung akar pangkat 2 tiga kali dari f, kita perlu melakukan right shift pada f sebanyak 3 kali. 

Contoh: 0b10011010001 >> 3 = 0b10011010

Sehingga, fungsi akan mengembalikan 0b10011010.
*/


/*
[WAJIB]

snow_mix - kembalikan N + (2 ^ 23).

Ketentuan: dijamin berlaku untuk 0 <= N <= (2 ^ 24)

Contoh:
snow_mix(3) = 8388611
snow_mix(31) = 8388639
snow_mix(8650816) = 17039424

Legal ops   : ! ~ & ^ | << >>
Max ops     : 14
Rating      : 2
*/
int snow_mix(int N) {
    int power = 0x1 << 23;
    int carry = N & power;
    int result = N ^ power;
    carry = carry << 1;
    return result ^ carry;
}
/*
PENJELASAN

Pertama, kita perlu menghitung 2^23, yang dapat dilakukan dengan left shift pada 1 sebanyak 23 kali.

0x1 << 23 = 0x800000

Kemudian, kita perlu melakukan operasi AND antara N dan 2^23 untuk mendapatkan bit ke-23 dari N.

N & 0x800000

Selanjutnya, kita melakukan operasi XOR antara N dan 2^23 untuk membalik bit ke-23 dari N.

N ^ 0x800000

Setelah itu, kita melakukan left shift pada hasil operasi AND sebelumnya sebanyak 1 kali untuk menggeser bit ke-23 ke bit ke-24.

carry << 1

Terakhir, kita melakukan operasi XOR antara hasil operasi XOR sebelumnya dan hasil operasi left shift untuk mendapatkan hasil akhir.

(result ^ carry)

Dengan demikian, fungsi ini mengembalikan N + 2^23.
*/

/*
[WAJIB]

sky_hundred - Kembalikan hasil XOR dari 1 ke n.

Jika n bernilai negatif, kembalikan 0.

Contoh:
sky_hundred(33) = 1
sky_hundred(20) = 20
sky_hundred(-1) = 0

Legal ops   : ! ~ & ^ | + << >>
Max ops     : 30
Rating      : 2
*/
int sky_hundred(int n) {
    int remainder = n & 0x3;
    int mod0 = (!remainder << 31) >> 31;
    int mod1 = (!(remainder ^ 0x1) << 31) >> 31;
    int mod2 = (!(remainder ^ 0x2) << 31) >> 31;
    int mod3 = (!(remainder ^ 0x3) << 31) >> 31;

    return ((n & mod0) | (1 & mod1) | ((n + 1) & mod2) | (0 & mod3)) & (~(n >> 31));
}
/*
PENJELASAN
*/

/*
[WAJIB]

ganganji - Mengalikan x dengan 1.125 (bulatkan ke bawah) dengan ketentuan:
    - nilai x tidak negatif (tetapi bisa 0).
    - Jika terjadi overflow, kembalikan 0x7fffffff.

Contoh:
ganganji(7) = 7
ganganji(8) = 9
ganganji(101) = 113
ganganji(2000000000) = 2147483647

Legal ops   : ! ~ & ^ | + - << >>
Max ops     : 30
Rating      : 3
*/
int ganganji(int x) {
    int result = x + (x >> 3);
    int overflow = (result >> 31) ^ (x >> 31); // Check if overflow occurred
    int max = (1 << 31) + 1;
    return (overflow & max) | (~overflow & result);
}
/*
PENJELASAN
*/

/*
[WAJIB]

kitsch - Kembalikan x dikalikan dengan 17/64. Bulatkan menuju 0.

Contoh:
kitsch(400) = 106
kitsch(15) = 3
kitsch(-6) = -1
kitsch(-10) = -2

Legal ops   : ! ~ & | + << >>
Max ops     : 18
Rating      : 3
*/
int kitsch(int x) {
    int result = (x >> 2) + (x >> 6);
    int sign = x >> 31;

    return result + (sign & !!(x & 63));
}
/*
PENJELASAN
*/

/*
[WAJIB]

how_to_sekai_seifuku - Ubah tipe f ke format single precision floating point.

Parameter f adalah sebuah float dalam format half-precision floating-point, yaitu representasi IEEE 754 yang menggunakan sebanyak 5 bits untuk Exponent dan 10 bits untuk Mantissa (dan juga 1 bit untuk sign). Anda harus menginterpretasi f menjadi sebuah angka. Kemudian encode angka tersebut ke format float single precision biasa.

Peletakkan bits mentok kanan. Atau lebih spesifiknya:
1. Sejumlah 10 bits paling kanan untuk Mantissa
2. Sejumlah 5 bits setelah itu untuk Exponent
3. Satu bit setelah itu untuk sign bit
4. Semua bits setelah itu NOL.

Perhatikan kasus khusus inf, NaN, dan 0. Jika dalam half precision point, f adalah +inf atau -inf, output yang dihasilkan harus berupa +inf/-inf dalam representasi 32-bit. Logika yang sama berlaku juga untuk +0 dan -0.

KHUSUS UNTUK KASUS jika f adalah NaN:
Anda wajib kembalikan 0x7f800001, bukan NaN lain.

Contoh:
how_to_sekai_seifuku(0xFF00) = -inf
how_to_sekai_seifuku(0x80c3) = -0.00001162290573
how_to_sekai_seifuku(0x0000) = 0.0
how_to_sekai_seifuku(0x0001) = 0.000000059604645
how_to_sekai_seifuku(0x5B37) = 230.875
how_to_sekai_seifuku(0x7F10) = NaN

Perhatikan contoh 2 dan contoh 4 adalah contoh denormalized,
contoh 5 adalah contoh normalized, dan contoh 6 adalah contoh NaN.

Legal ops   : Konstanta Besar, Looping, Conditional, == >> << - + | & ^
Max ops     : 50
Rating      : 4
*/
unsigned how_to_sekai_seifuku(unsigned f) {
    return 2;
}
/*
PENJELASAN
*/

/*
[WAJIB]

mesmerizer - Mengembalikan bit-level equivalent dari ekspresi (int) f.

Argumen f merupakan representasi bit dari bilangan desimal dalam bentuk single precision floating point. Jika nilai float melebihi batasan (termasuk NaN dan infinity), kembalikan 0x80000000u.

Contoh:
mesmerizer(32.0) = 32
mesmerizer(-420.69) = -420
mesmerizer(0.000026) = 0
mesmerizer(88888888888) = max int

Legal ops   : Konstanta Besar, Looping, Conditional, Tipe Unsigned, all integer operations
Max ops     : 30
Rating      : 4
*/
int mesmerizer(unsigned uf) {
    return 2;
}
/*
PENJELASAN
*/


/*
Driver code for testing
*/
int main() {
    // Test for chicken_or_beef
    int answer1[] = {0b1001, 0b1111, 0b1110};
    int test1[][2] = {
        {0b10010101, 0b11111000},
        {0b01010000, 0b10001101},
        {0b01100000, 0b11111111}
    };

    for (int i = 0; i < 3; i++) {
        if (chicken_or_beef(test1[i][0], test1[i][1]) == answer1[i]) {
            printf("Test case %d: Passed\n", i + 1);
            printf("chicken_or_beef(0b%08b, 0b%08b) = 0b%08b\n", test1[i][0], test1[i][1], answer1[i]);
        } else {
            printf("Test case %d: Failed\n", i + 1);
            printf("chicken_or_beef(0b%08b, 0x%08b) = 0b%08b\n", test1[i][0], test1[i][1], chicken_or_beef(test1[i][0], test1[i][1]));
            printf("Expected: 0x%x\n", answer1[i]);
        }
    }

    // Test for masquerade
    int answer2 = 0x80000000 + 1;
    
    if (masquerade() == answer2) {
        printf("Test case 4: Passed\n");
        printf("masquerade() = %d\n", answer2);
    } else {
        printf("Test case 4: Failed\n");
        printf("masquerade() = %d\n", masquerade());
        printf("Expected: %d\n", answer2);
    }

    // Test for airani_iofifteen
    int answer3[] = {1, 0, 0};
    int test3[] = {15, -15, 13523015};

    for (int i = 0; i < 3; i++) {
        if (airani_iofifteen(test3[i]) == answer3[i]) {
            printf("Test case %d: Passed\n", i + 5);
            printf("airani_iofifteen(%d) = %d\n", test3[i], answer3[i]);
        } else {
            printf("Test case %d: Failed\n", i + 5);
            printf("airani_iofifteen(%d) = %d\n", test3[i], airani_iofifteen(test3[i]));
            printf("Expected: %d\n", answer3[i]);
        }
    }

    // Test for yobanashi_deceive
    unsigned answer4[] = {0, 0b1, 0b10011010};
    unsigned test4[] = {0b0, 0b001011, 0b10011010001};

    for (int i = 0; i < 3; i++) {
        if (yobanashi_deceive(test4[i]) == answer4[i]) {
            printf("Test case %d: Passed\n", i + 8);
            printf("yobanashi_deceive(0b%011b) = 0b%011b\n", test4[i], answer4[i]);
        } else {
            printf("Test case %d: Failed\n", i + 8);
            printf("yobanashi_deceive(0b%011b) = 0b%011b\n", test4[i], yobanashi_deceive(test4[i]));
            printf("Expected: 0b%011b\n", answer4[i]);
        }
    }

    // Test for snow_mix
    int answer5[] = {8388611, 8388639, 17039424};
    int test5[] = {3, 31, 8650816};

    for (int i = 0; i < 3; i++) {
        if (snow_mix(test5[i]) == answer5[i]) {
            printf("Test case %d: Passed\n", i + 11);
            printf("snow_mix(%d) = %d\n", test5[i], answer5[i]);
        } else {
            printf("Test case %d: Failed\n", i + 11);
            printf("snow_mix(%d) = %d\n", test5[i], snow_mix(test5[i]));
            printf("Expected: %d\n", answer5[i]);
        }
    }

    // Test for sky_hundred
    int answer6[] = {1, 20, 0};
    int test6[] = {33, 20, -1};

    for (int i = 0; i < 3; i++) {
        if (sky_hundred(test6[i]) == answer6[i]) {
            printf("Test case %d: Passed\n", i + 14);
            printf("sky_hundred(%d) = %d\n", test6[i], answer6[i]);
        } else {
            printf("Test case %d: Failed\n", i + 14);
            printf("sky_hundred(%d) = %d\n", test6[i], sky_hundred(test6[i]));
            printf("Expected: %d\n", answer6[i]);
        }
    }

    // Test for ganganji
    int answer7[] = {7, 9, 113, 2147483647};
    int test7[] = {7, 8, 101, 2000000000};

    for (int i = 0; i < 4; i++) {
        if (ganganji(test7[i]) == answer7[i]) {
            printf("Test case %d: Passed\n", i + 17);
            printf("ganganji(%d) = %d\n", test7[i], answer7[i]);
        } else {
            printf("Test case %d: Failed\n", i + 17);
            printf("ganganji(%d) = %d\n", test7[i], ganganji(test7[i]));
            printf("Expected: %d\n", answer7[i]);
        }
    }

    // Test for kitsch
    int answer8[] = {106, 3, -1, -2, 0};
    int test8[] = {400, 15, -6, -10, 0};

    for (int i = 0; i < 5; i++) {
        if (kitsch(test8[i]) == answer8[i]) {
            printf("Test case %d: Passed\n", i + 21);
            printf("kitsch(%d) = %d\n", test8[i], answer8[i]);
        } else {
            printf("Test case %d: Failed\n", i + 21);
            printf("kitsch(%d) = %d\n", test8[i], kitsch(test8[i]));
            printf("Expected: %d\n", answer8[i]);
        }
    }

    return 0;

}