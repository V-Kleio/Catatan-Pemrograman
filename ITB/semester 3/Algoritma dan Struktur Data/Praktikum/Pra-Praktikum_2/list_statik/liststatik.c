#include "liststatik.h"

void CreateListStatik(ListStatik *l)
/* 
    I.S. l sembarang
    F.S. Terbentuk List l kosong dengan kapasitas CAPACITY
    Proses: Inisialisasi semua elemen List l dengan MARK 
*/
{
    // Mengisi semua elemen List l dengan MARK
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++)
    {
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l)
/* 
    Mengirimkan banyaknya elemen efektif List
    Mengirimkan nol jika List kosong 
*/  
{
    // Menghitung banyaknya elemen efektif List
    IdxType i = IDX_MIN;
    while (i < CAPACITY && ELMT(l, i) != MARK)
    {
        i++;
    }
    return i;
}

IdxType getFirstIdx(ListStatik l)
/* 
    Prekondisi : List l tidak kosong
    Mengirimkan indeks elemen l pertama 
*/
{
    // Penempatan elemen pada list selalu rata kiri
    // Elemen pertama selalu index minimum
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l)
/* 
    Prekondisi : List l tidak kosong
    Mengirimkan indeks elemen l terakhir 
*/
{
    // Mengirimkan indeks elemen l terakhir
    return listLength(l) - 1;
}

boolean isIdxValid(ListStatik l, IdxType i)
/* 
    Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l
    yaitu antara indeks yang terdefinisi utk container
*/
{
    // Mengecek apakah indeks berada di antara indeks minimum
    // dan kapasitas 
    return i >= IDX_MIN && i < CAPACITY;
}

boolean isIdxEff(ListStatik l, IdxType i)
/* 
    Mengirimkan true jika i adalah indeks yang terdefinisi utk List l
    yaitu antara 0..length(l)-1 
*/
{
    // Mengecek apakah indeks berada di antara indeks minimum
    // dan indeks terakhir
    return i >= IDX_MIN && i <= getLastIdx(l);
}

boolean isEmpty(ListStatik l)
// Mengirimkan true jika List l kosong, mengirimkan false jika tidak
{
    // Mengirimkan true jika List l kosong
    return listLength(l) == 0;
}

boolean isFull(ListStatik l)
// Mengirimkan true jika List l penuh, mengirimkan false jika tidak
{
    // Mengirimkan true jika List l penuh
    return listLength(l) == CAPACITY;
}

void readList(ListStatik *l)
/* 
    I.S. l sembarang
    F.S. List l terdefinisi
    Proses: membaca banyaknya elemen l dan mengisi nilainya
    1. Baca banyaknya elemen diakhiri enter, misalnya n
        Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY
        Jika n tidak valid, tidak diberikan pesan kesalahan
    2. Jika 0 < n <= CAPACITY; Lakukan n kali:           
        Baca elemen mulai dari indeks 0 satu per satu diakhiri enter  
    Jika n = 0; hanya terbentuk List kosong 
*/
{
    // Membaca banyaknya elemen l dan mengisi nilainya
    IdxType n;
    do
    {
        scanf("%i", &n);  
    } while (n < 0 || n > CAPACITY);
    CreateListStatik(l);

    // Jika n = 0; hanya terbentuk List kosong
    if (n == 0)
    {
        return;
    }
    // Mengisi elemen list l 
    else
    {
        IdxType i;
        for (i = 0; i < n; i++)
        {
            scanf("%i", &ELMT(*l, i));
        }
    }    
}

void printList(ListStatik l)
/* 
    Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter
    I.S. l boleh kosong
    F.S. Jika l tidak kosong: [e1,e2,...,en]
    Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
    Jika List kosong : menulis [] 
*/
{
    // List kosong print []
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        IdxType i;
        printf("[");
        for (i = IDX_MIN; i < listLength(l); i++)
        {
            printf("%i", ELMT(l, i));
            // print tanda koma setelah tiap elemen sampai elemen dengan indeks sebelum terakhir
            if (i < listLength(l) - 1)
            {
                printf(",");
            }
        }
        printf("]");
    }
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
/* 
    Prekondisi : l1 dan l2 berukuran sama dan tidak kosong
    Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
        indeks yang sama dijumlahkan
    Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
        elemen l2 pada indeks yang sama 
*/
{
    // Mengirimkan l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan
    // atau l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama
    ListStatik l;
    CreateListStatik(&l);
    IdxType i;
    if(plus)
    {
        for (i = IDX_MIN; i < listLength(l1); i++)
        {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else
    {
        for (i = IDX_MIN; i < listLength(l1); i++)
        {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2)
/* 
    Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
    elemennya sama 
*/
{
    // Mengecek kesamaan size kedua list
    if (listLength(l1) != listLength(l2))
    {
        return false;
    }
    else
    {
        IdxType i;
        // Mengecek kesamaan elemen tiap indeks
        for (i = IDX_MIN; i < listLength(l1); i++)
        {
            if (ELMT(l1, i) != ELMT(l2, i))
            {
                return false;
            }
        }
        return true;
    }
}

int indexOf(ListStatik l, ElType val)
/* 
    Search apakah ada elemen List l yang bernilai val 
    Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val
    Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF
    Skema Searching yang digunakan bebas 
*/
{
    // Mencari indeks elemen dengan nilai val
    IdxType i = IDX_MIN;
    while (i < listLength(l) && ELMT(l, i) != val)
    {
        i++;
    }
    // Jika elemen tidak ditemukan
    if (i == listLength(l))
    {
        return IDX_UNDEF;
    }
    else
    {
        return i;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min)
/* 
    I.S. List l tidak kosong
    F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l
*/
{
    IdxType i;
    // Inisialisasi max dan min dengan elemen pertama
    *max = ELMT(l, IDX_MIN);
    *min = ELMT(l, IDX_MIN);
    // Mencari nilai terbesar dan terkecil
    for (i = 0; i < listLength(l); i++)
    {
        if (ELMT(l, i) > *max)
        {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min)
        {
            *min = ELMT(l, i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val)
/* 
    Proses: Menambahkan val sebagai elemen pertama List
    I.S. List l boleh kosong, tetapi tidak penuh
    F.S. val adalah elemen pertama l yang baru
*/
{
    // Memindahkan semua elemen ke kanan list (indeks + 1)
    IdxType i;
    for (i = listLength(*l); i > IDX_MIN; i--)
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }
    // Memasukkan val ke index pertama
    ELMT(*l, IDX_MIN) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx)
/* 
    Proses: Menambahkan val sebagai elemen pada index idx List 
    I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l
    F.S. val adalah elemen yang disisipkan pada index idx l 
*/
{
    // Memindahkan semua elemen berindeks setelah idx ke kanan list (indeks + 1)
    IdxType i;
    for (i = listLength(*l); i > idx; i--)
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }
    // Memasukkan val ke indeks idx
    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val)
/* 
    Proses: Menambahkan val sebagai elemen terakhir List
    I.S. List l boleh kosong, tetapi tidak penuh
    F.S. val adalah elemen terakhir l yang baru
*/
{
    // Mengisi indeks terakhir + 1 dengan val
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val)
/* 
    Proses : Menghapus elemen pertama List
    I.S. List tidak kosong
    F.S. val adalah nilai elemen pertama l sebelum penghapusan,
        Banyaknya elemen List berkurang satu
        List l mungkin menjadi kosong 
*/
{
    // Menghapus elemen pertama List
    *val = ELMT(*l, IDX_MIN);
    IdxType i;
    // Menggeser tiap elemen ke kiri (indeks - 1)
    for (i = IDX_MIN; i < listLength(*l) - 1; i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    // Mengosongkan indeks terakhir
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx)
/* 
    Proses : Menghapus elemen pada index idx List
    I.S. List tidak kosong, idx adalah index yang valid di l
    F.S. val adalah nilai elemen pada index idx l sebelum penghapusan,
        Banyaknya elemen List berkurang satu
        List l mungkin menjadi kosong 
*/
{
    // Menghapus elemen pada index idx List
    *val = ELMT(*l, idx);
    IdxType i;
    // Menggeser tiap elemen berindeks setelah idx ke kiri (indeks - 1)
    for (i = idx; i < listLength(*l) - 1; i++)
    {
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    // Mengosongkan indeks terakhir
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val)
/* 
    Proses : Menghapus elemen terakhir List
    I.S. List tidak kosong
    F.S. val adalah nilai elemen terakhir l sebelum penghapusan,
        Banyaknya elemen List berkurang satu
        List l mungkin menjadi kosong 
*/
{
    // Menghapus elemen terakhir List
    *val = ELMT(*l, listLength(*l) - 1);
    // Mengosongkan indeks terakhir
    ELMT(*l, listLength(*l) - 1) = MARK;
}

void sortList(ListStatik *l, boolean asc)
/* 
    I.S. l boleh kosong
    F.S. Jika asc = true, l terurut membesar
        Jika asc = false, l terurut mengecil
    Proses : Mengurutkan l dengan salah satu algoritma sorting,
    algoritma bebas 
*/
{
    if(asc)
    {
        // Bubble sort ascending
        IdxType i, j;
        for (i = IDX_MIN; i < listLength(*l) - 1; i++)
        {
            for (j = IDX_MIN; j < listLength(*l) - i - 1; j++)
            {
                if (ELMT(*l, j) > ELMT(*l, j + 1))
                {
                    ElType temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    }
    else
    {
        // Bubble sort descending
        IdxType i, j;
        for (i = IDX_MIN; i < listLength(*l) - 1; i++)
        {
            for (j = IDX_MIN; j < listLength(*l) - i - 1; j++)
            {
                if (ELMT(*l, j) < ELMT(*l, j + 1))
                {
                    ElType temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                }
            }
        }
    }
}

