#include <iostream>
#include "dll_first_last.h"

using namespace std;

int main() {
  List L;

  createList(L);
  printList(L);
  insertAscending(L, 25);
  printList(L); // 25
  insertAscending(L, 10);
  printList(L); // 10 25
  insertAscending(L, 32);
  printList(L); // 10 25 32
  insertAscending(L, 3);
  printList(L);
  deleteElm(L, 32);
  printList(L);
  deleteElm(L, 3);
  printList(L);
  deleteElm(L, 10);
  printList(L);
  deleteElm(L, 25);
  printList(L);

  insertAscending(L, 25);
  printList(L);
  insertAscending(L, 10);
  printList(L);
  insertAscending(L, 10);
  printList(L);
  insertAscending(L, 25);
  printList(L);
  insertAscending(L, 25);
  printList(L);

  if (findElement(L, 10)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  cout << frequencyofElm(L, 10) << endl;
  cout << frequencyofElm(L, 25) << endl;
  cout << frequencyofElm(L, 2) << endl;

  return 0;
}
