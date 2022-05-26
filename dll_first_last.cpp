//
// Created by Ariq Heritsa on 20/05/22.
//

#include "dll_first_last.h"

// 1305213031 • Ariq Heritsa Maalik
void createList(List &L) {
  first(L) = nil;
  last(L) = nil;
}

// 1305213031 • Ariq Heritsa Maalik
address createElement(infotype dataBaru) {
  address P = new elmList;

  info(P) = dataBaru;
  next(P) = nil;
  prev(P) = nil;

  return P;
}

// 1305213031 • Ariq Heritsa Maalik
void insertFirst(List &L, address P) {
  if (first(L) == nil) {
    first(L) = P;
    last(L) = P;
  } else {
    next(P) = first(L);
    prev(first(L)) = P;
    first(L) = P;
  }
}

// 1305213031 • Ariq Heritsa Maalik
void insertLast(List &L, address P) {
  if (first(L) == nil) {
    first(L) = P;
    last(L) = P;
  } else {
    next(last(L)) = P;
    prev(P) = last(L);
    last(L) = P;
  }
}

// 1305213031 • Ariq Heritsa Maalik
void insertAfter(address Prec, address P) {
  next(P) = next(Prec);
  prev(next(Prec)) = P;
  next(Prec) = P;
  prev(P) = Prec;
}

// 1305213031 • Ariq Heritsa Maalik
void insertAscending(List &L, infotype dataBaru) {
  address P = createElement(dataBaru);

  if (first(L) == nil) {
    first(L) = P;
    last(L) = P;
  } else if (info(first(L)) > info(P)) {
    insertFirst(L, P);
  } else {
    address Q = first(L);

    while (next(Q) != nil && info(next(Q)) <= info(P)) {
      Q = next(Q);
    }

    if (last(L) == Q) {
      insertLast(L, P);
    } else {
      insertAfter(Q, P);
    }
  }
}

// 1305213031 • Ariq Heritsa Maalik
void deleteFirst(List &L, address &P) {
  P = first(L);

  if (next(first(L)) == nil) {
    first(L) = nil;
    last(L) = nil;
  } else {
    first(L) = next(first(L));
    prev(first(L)) = nil;
    next(P) = nil;
  }
}

// 1305213031 • Ariq Heritsa Maalik
void deleteLast(List &L, address &P) {
  P = last(L);
  last(L) = prev(P);
  next(prev(P)) = nil;
  prev(P) = nil;
}

// 1305213031 • Ariq Heritsa Maalik
void deleteAfter(address Prec, address &P) {
  P = next(Prec);
  next(Prec) = next(P);
  prev(next(P)) = Prec;
  next(P) = nil;
  prev(P) = nil;
}

// 1305213031 • Ariq Heritsa Maalik
void deleteElm(List &L, infotype dataHapus) {
  address P, Q;

  if (first(L) == nil && last(L) == nil) {
    cout << "List kosong" << endl;
  } else if (info(first(L)) == dataHapus) {
    deleteFirst(L, P);
  } else if (info(last(L)) == dataHapus) {
    deleteLast(L, P);
  } else {
    Q = first(L);

    while (next(Q) != nil && info(next(Q)) != dataHapus) {
      Q = next(Q);
    }

    deleteAfter(Q, P);
  }
}

// 1305213031 • Ariq Heritsa Maalik
void printList(List L) {
  if (first(L) == nil && last(L) == nil) {
    cout << "List kosong!" << endl;
  } else {
    address P = first(L);

    while (P != nil) {
      cout << info(P) << " ";
      P = next(P);
    }

    cout << endl;
  }
}

// 1305213031 • Ariq Heritsa Maalik
int findElement(List &L, infotype dataDicari) {
  if (first(L) == nil) {
    return 0;
  }

  address P = first(L);

  while (P != nil) {
    if (info(P) == dataDicari) {
      return 1;
    }

    P = next(P);
  }

  return 0;
}

// 1305213031 • Ariq Heritsa Maalik
int frequencyofElm(List L, infotype dataDicari) {
  if (first(L) == nil) {
    return 0;
  }

  if (!findElement(L, dataDicari)) {
    return 0;
  }

  address P = first(L);
  int count = 0;

  while (P != nil) {
    if (info(P) == dataDicari) {
      count += 1;
    }

    P = next(P);
  }

  return count;
}
