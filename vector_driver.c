#include "vector.h"

VECDECL(vint, int)

int main(){
	vint myvec;
	myvec = create_vint();
	vint_reserve(&myvec, 5000);
	vint_push(&myvec, -1);
	vint_push(&myvec, 7);
	vint_push(&myvec, 8);
	vint_push(&myvec, 9);
	vint_push(&myvec, 9);
	vint_push(&myvec, 9);
	vint_push(&myvec, 9);
	vint_push(&myvec, 9);
	vint_push(&myvec, 9);
	vint_push(&myvec, 14);
	printf("%d\n", vint_pop(&myvec));
	printf("%d\n", vint_pop(&myvec));
	printf("%d\n", vint_pop(&myvec));
	printf("%d\n", vint_pop(&myvec));
	printf("%d\n", vint_pop(&myvec));

	vint_destroy(&myvec);
}
