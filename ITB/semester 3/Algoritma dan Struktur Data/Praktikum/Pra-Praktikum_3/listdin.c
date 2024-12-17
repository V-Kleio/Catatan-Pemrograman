#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>


void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
    BUFFER(*l) = malloc(sizeof(ElType) * CAPACITY(*l));
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return NEFF(l) - 1;
}

boolean isIdxValid(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= 0) && (i < CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    return (i >= 0) && (i < NEFF(l));
}

boolean isEmpty(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
    return NEFF(l) <= 0;
}

boolean isFull(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    return NEFF(l) == CAPACITY(l);
}

void readList(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    int numElementsInput;
    ElType elementValue;
    IdxType i;

    // Input
    do 
    {
        scanf("%d", &numElementsInput);
    } while (numElementsInput < 0 || numElementsInput > CAPACITY(*l));

    CreateListDin(l, numElementsInput);

    for (i = getFirstIdx(*l); i < numElementsInput; i++)
    {
        scanf("%d", &elementValue);
        insertLast(l, elementValue);
    }
}

void printList(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    IdxType i;

    printf("[");
    if (!isEmpty(l))
    {
        printf("%d", ELMT(l, getFirstIdx(l)));
        for (i = getFirstIdx(l) + 1; i < NEFF(l); i++)
        {
            printf(",%d", ELMT(l, i));
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    ListDin resultList;
    IdxType i;

    CreateListDin(&resultList, CAPACITY(l1) + CAPACITY(l2));
    
    for (i = getFirstIdx(l1); i < NEFF(l1); i++)
    {
        if (plus)
        {
            insertLast(&resultList, ELMT(l1, i) + ELMT(l2, i));
        }
        else
        {
            insertLast(&resultList, ELMT(l1, i) - ELMT(l2, i));
        }
    }

    return resultList;
}

boolean isListEqual(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    if (NEFF(l1) != NEFF(l2))
    {
        return false;
    }

    IdxType i;
    for (i = getFirstIdx(l1); i < NEFF(l1); i++)
    {
        if (ELMT(l1, i) != ELMT(l2, i))
        {
            return false;
        }
    }

    return true;
}

IdxType indexOf(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    IdxType i;
    for (i = getFirstIdx(l); i < NEFF(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            return i;
        }
    }

    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    IdxType i;
    ElType currentElement;

    *max = ELMT(l, getFirstIdx(l));
    *min = ELMT(l, getFirstIdx(l));

    for (i = getFirstIdx(l) + 1; i < NEFF(l); i++)
    {
        currentElement = ELMT(l, i);
        if (currentElement > *max)
        {
            *max = currentElement;
        }
        if (currentElement < *min)
        {
            *min = currentElement;
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    IdxType i;
    CreateListDin(lOut, CAPACITY(lIn));

    for (i = getFirstIdx(lIn); i < NEFF(lIn); i++)
    {
        insertLast(lOut, ELMT(lIn, i));
    }
}

ElType sumList(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    IdxType i;
    ElType sum = 0;

    for (i = getFirstIdx(l); i < NEFF(l); i++)
    {
        sum += ELMT(l, i);
    }

    return sum;
}

int countVal(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    IdxType i;
    int count = 0;

    for (i = getFirstIdx(l); i < NEFF(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            count++;
        }
    }

    return count;
}

void sort(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    // Bubble sort
    IdxType i, j;
    ElType temp;

    for (i = getFirstIdx(*l); i < NEFF(*l); i++)
    {
        for (j = NEFF(*l) - 1; j > i; j--)
        {
            if (asc)
            {
                if (ELMT(*l, j) < ELMT(*l, j - 1))
                {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j - 1);
                    ELMT(*l, j - 1) = temp;
                }
            }
            else
            {
                if (ELMT(*l, j) > ELMT(*l, j - 1))
                {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j - 1);
                    ELMT(*l, j - 1) = temp;
                }
            }
        }
    }
}


void insertLast(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMT(*l, NEFF(*l) - 1);
    NEFF(*l)--;
    
}

void expandList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    CAPACITY(*l) += num;
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType) * CAPACITY(*l));
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    CAPACITY(*l) -= num;
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType) * CAPACITY(*l));
}

void compressList(ListDin *l)
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    CAPACITY(*l) = NEFF(*l);
    BUFFER(*l) = realloc(BUFFER(*l), sizeof(ElType) * CAPACITY(*l));
}