#include "stdio.h"

void function(int a, int b, int c) {
	 // let us have some pointer which we want later to point to that location in stack we are searching.
	 int *ret = 33;
   // find the address in stack where the function return address is stored.
   ret =  ;
	 // when you found it you have to modify it.
	 // whati is X? change the address in a way that "x = 1" will never be executed.
   (*ret) = 
}

void main() {
  int x;

  x = 0;
  function(1,2,3);
  x = 1;
  printf("%d\n",x);
}
