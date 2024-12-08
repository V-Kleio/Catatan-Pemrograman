/* Bagian 1 */
/* Deklarasi Fakta */
pria(qika).
pria(panji).
pria(shelby).
pria(barok).
pria(aqua).
pria(eriq).
pria(francesco).


wanita(hinatsuru).
wanita(makio).
wanita(suma).
wanita(frieren).
wanita(yennefer).
wanita(roxy).
wanita(ruby).
wanita(suzy).
wanita(aihoshino).
wanita(eve).


usia(hinatsuru, 105).
usia(qika, 109).
usia(makio, 96).
usia(suma, 86).
usia(panji, 124).
usia(frieren, 90).
usia(shelby, 42).
usia(yennefer, 61).
usia(barok, 59).
usia(roxy, 70).
usia(aqua, 66).
usia(ruby, 63).
usia(eriq, 69).
usia(suzy, 23).
usia(francesco, 25).
usia(aihoshino, 48).
usia(eve, 5).


menikah(hinatsuru, qika).
menikah(qika, hinatsuru).
menikah(qika, makio).
menikah(qika, suma).
menikah(makio, qika).
menikah(suma, qika).
menikah(panji, frieren).
menikah(frieren, panji).
menikah(barok, roxy).
menikah(roxy, barok).
menikah(ruby, eriq).
menikah(eriq, ruby).
menikah(suzy, francesco).
menikah(francesco, suzy).


anak(shelby, hinatsuru).
anak(shelby, qika).
anak(yennefer, hinatsuru).
anak(yennefer, qika).
anak(barok, qika).
anak(barok, makio).
anak(aqua, panji).
anak(aqua, frieren).
anak(ruby, panji).
anak(ruby, frieren).
anak(suzy, barok).
anak(suzy, roxy).
anak(aihoshino, ruby).
anak(aihoshino, eriq).
anak(eve, suzy).
anak(eve, francesco).



/* Deklarasi Rules */
saudara(X, Y) :-
    anak(X, Orangtua),
    anak(Y, Orangtua),
    X \== Y.


saudaratiri(X, Y) :-
    anak(X, Orangtua1),
    anak(Y, Orangtua1),
    X \== Y,
    anak(X, Orangtua2),
    \+ anak(Y, Orangtua2),
    Orangtua1 \== Orangtua2.

saudaratiri(X, Y) :-
    anak(X, Orangtua1),
    anak(Y, Orangtua1),
    X \== Y,
    anak(Y, Orangtua2),
    \+ anak(X, Orangtua2),
    Orangtua1 \== Orangtua2.


kakak(X, Y) :-
    saudara(X, Y),
    usia(X, Umurx),
    usia(Y, Umury),
    Umurx > Umury.


keponakan(X, Y) :-
    saudara(Y, Orang),
    anak(X, Orang).


mertua(X, Y) :-
    menikah(Y, Orang),
    anak(Orang, X).


nenek(X, Y) :-
    wanita(X),
    anak(Anak, X),
    anak(Y, Anak).


keturunan(X, Y) :-
    anak(X, Y).

keturunan(X, Y) :-
    anak(Anak, Y),
    keturunan(X, Anak).


lajang(X) :-
    pria(X),
    \+ menikah(X, _).

lajang(X) :-
    wanita(X),
    \+ menikah(X, _).


anakbungsu(X):-
    anak(X, Orangtua),
    usia(X, UsiaX),
    \+ (anak(Y, Orangtua), usia(Y, UsiaY), UsiaX > UsiaY).


anaksulung(X):-
    anak(X, Orangtua),
    usia(X, UsiaX),
    \+ (anak(Y, Orangtua), usia(Y, UsiaY), UsiaX < UsiaY).


yatimpiatu(X) :-
    pria(X),
    \+ anak(X, _).

yatimpiatu(X) :-
    wanita(X),
    \+ anak(X, _).


/* Bagian 2 */
/* Deklarasi Rules */
/* Exponent*/
exponent(_, 0, 1).

exponent(A, B, X):-
    B > 0,
    B1 is B - 1,
    exponent(A, B1, X1),
    X is X1 * A.


/* Growth*/
dibagi(N, X):-
    X * X =< N,
    (
        N mod X =:= 0;
        X1 is X + 1,
        dibagi(N, X1)
    ).

prima(2).
prima(N):-
    N > 2,
    \+ dibagi(N, 2).

growth(I, _, _, 0, I).
growth(I, G, H, T, X):-
    T > 0,
    (
        prima(T)->
        T1 is T - 1,
        growth(I, G, H, T1, X1),
        X is X1 + G;
        T1 is T - 1,
        growth(I, G, H, T1, X1),
        X is X1 - H
    ).


/* Si Imut Anak Nakal*/
harvestFruits(_, Total, _, FinalFruits) :-                       
    Total =< 0,
    FinalFruits is 0,
    write('Si Imut pulang sambil menangis :(').

harvestFruits(X, Fruits, Y, Fruits) :-
    X + 1 =:= Y.

harvestFruits(N, Fruits, TreeNumber, FinalFruits) :-
    Fruits > 0,
    TreeNumber < N + 1,
    updateFruits(TreeNumber, Fruits, NewFruits),
    NextTree is TreeNumber + 1,
    harvestFruits(N, NewFruits, NextTree, FinalFruits).

updateFruits(TreeNumber, Fruits, NewFruits) :-
    (TreeNumber mod 3 =:= 0 -> Fruits1 is Fruits + 2 ; Fruits1 = Fruits),
    (TreeNumber mod 4 =:= 0 -> Fruits2 is Fruits1 - 5 ; Fruits2 = Fruits1),
    (TreeNumber mod 5 =:= 0 -> Fruits3 is Fruits2 + 3 ; Fruits3 = Fruits2),
    (prima(TreeNumber) -> Fruits4 is Fruits3 - 10 ; Fruits4 = Fruits3),
    NewFruits is Fruits4.


/* KPK*/
gcd(Number1, 0, Number1).

gcd(Number1, Number2, X):-
    Number2 > 0,
    Remainder is Number1 mod Number2,
    gcd(Number2, Remainder, X).

kpk(Number1, Number2, X):-
    gcd(Number1, Number2, GCD),
    X is Number1 * Number2 // GCD.


/* Factorial*/
factorial(0, 1).

factorial(X, Y):-
    X > 0,
    X1 is X - 1,
    factorial(X1, Y1),
    Y is X * Y1.


/* Make Pattern*/
makePattern(N) :-
    makeRows(N, 1).

makeRows(N, Row) :-
    Row > N, !.

makeRows(N, Row) :-
    makeCols(N, Row, 1),
    nl,
    NextRow is Row + 1,
    makeRows(N, NextRow).

makeCols(N, _, Col) :-
    Col > N, !.

makeCols(N, Row, Col) :-
    DepthY is N - (Row - 1),
    DepthX is N - (Col - 1),
    smaller(DepthX, DepthY, Depth1),
    smaller(Row, Col, Depth2),
    smaller(Depth1, Depth2, Depth),
    write(Depth),
    (Col < N -> write(' ') ; true),
    NextCol is Col + 1,
    makeCols(N, Row, NextCol), !.

smaller(A, B, B) :- B =< A.
smaller(A, B, A) :- A < B.


/* Bagian III*/
/* 1. List Statistic*/
/* min*/
min([Head], Head).

min([Head|Tail], Head) :-
    min(Tail, Number),
    Head =< Number.

min([Head|Tail], Number):-
  min(Tail, Number),
  Head > Number.


/* max*/
max([Head], Head).

max([Head|Tail], Head):-
    max(Tail, Number),
    Head >= Number.

max([Head|Tail], Number):-
    max(Tail, Number),
    Head < Number.


/* range*/
range([Head|Tail], X) :-
    max([Head|Tail], Max),
    min([Head|Tail], Min),
    X is Max - Min.


/* count*/
count([], 0).

count([_|Tail], Counter) :-
    count(Tail, Counter1),
    Counter is Counter1 + 1.


/* sum*/
sum([], 0).

sum([Head|Tail], Sum) :-
    sum(Tail, Sum1),
    Sum is Sum1 + Head.


/* 2. List Manipulation*/
/* mergeSort*/
mergeSort([], [], _Result).

mergeSort([], List, List).

mergeSort(List, [], List).

mergeSort([Head1|Tail1], [Head2|Tail2], [Head1|MergedTail]) :-
    Head1 =< Head2,
    mergeSort(Tail1, [Head2|Tail2], MergedTail).

mergeSort([Head1|Tail1], [Head2|Tail2], [Head2|MergedTail]) :-
    Head1 > Head2,
    mergeSort([Head1|Tail1], Tail2, MergedTail).


/* filterArray*/
filterArray([], _Element1, _Element2, []):- !.

filterArray([Head|Tail], Element1, Element2, [Head|Tail1]) :-
    Head > Element1,
    (Head mod Element2) =:= 0,
    filterArray(Tail, Element1, Element2, Tail1).

filterArray([Head|Tail], Element1, Element2, Result):-
    Head =< Element1,
    filterArray(Tail, Element1, Element2, Result).

filterArray([Head|Tail], Element1, Element2, Result):-
    (Head mod Element2) =\= 0,
    filterArray(Tail, Element1, Element2, Result).


/* reverse*/
move([], Result, Result) :- !.

move([Head|Tail], [], Result) :-
    move(Tail, [Head], Result).

move([Head|Tail], List, Result) :-
    move(Tail, [Head|List], Result).

reverseList(List, Reverse) :-
    move(List, [], Result),
    Reverse = Result, !.


/* cekPalindrom*/
cekPalindrom(List) :-
    reverseList(List, Reversed),
    cekPalindrom(List, Reversed).

cekPalindrom([],[]).

cekPalindrom([Head1|_Tail1], [Head2|_Tail2]) :-
    Head1 =\= Head2,
    !,
    fail.

cekPalindrom([_Head1|Tail1], [_Head2|Tail2]) :-
    cekPalindrom(Tail1, Tail2).


/* rotate*/
insert([], X, X).

insert([Head|Tail], X, [Head|Result]) :- insert(Tail, X, Result).

rotate(NewList, 0, NewList).
rotate([], _, []).

rotate([Head|Tail], N, Result) :-
    count([Head|Tail], Count),
    (NewN is (N mod Count)), 
    insert(Tail, [Head], NewList),
    N1 is NewN - 1,
    rotate(NewList, N1, Result).


/* Mapping */
grade(Score, 'A') :- Score >= 80, ! .
grade(Score, 'B') :- Score >= 70, ! .
grade(Score, 'C') :- Score >= 60, ! .
grade(Score, 'D') :- Score >= 50, ! .
grade(Score, 'E') :- Score < 50.

mappingScore([], []).
mappingScore([Head|Tail], [Head1|Tail1]) :-
    grade(Head, Head1),
    mappingScore(Tail, Tail1).

average([], 0).
average(List, Avg) :-
    sum(List, Sums),
    count(List, Length),
    Avg is Sums / Length.

passing(List, 'Pass'):-
    average(List, Avg), Avg >= 80, !.

passing(List, 'Fail'):- average(List, Avg), Avg < 80.

prosesMahasiswa(Name, Grades, Result) :-
    mappingScore(Grades, GradesValue),
    average(Grades, Avg),
    passing(Grades, Status),
    Result = [Name, GradesValue, Avg, Status].