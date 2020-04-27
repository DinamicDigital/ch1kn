#include <stdlib.h>
#include "ch1kn.h"
#include <stdio.h>

typedef struct test {
	u8* hello;
	u32 goodbye;

} Test;

int notmain() {
	u32 s = sizeof(u32);
	return 0;
}

int main()
{


	S32_Array chickens;
	init_dynarr_s32(&chickens, 1);
	append_dynarr_s32(&chickens, 2);
	append_dynarr_s32(&chickens, 3);
	append_dynarr_s32(&chickens, 4);
	append_dynarr_s32(&chickens, 5);

	
	printf("\n");
	
	printf("%d\n", chickens.data[0]);
	printf("%d\n", chickens.data[1]);
	printf("%d\n", chickens.data[2]);
	printf("%d\n", chickens.data[3]);
	printf("%d\n", chickens.data[4]);
	printf("%d\n", chickens.data[5]);
	printf("%d\n", chickens.data[6]);
	printf("%d\n", chickens.data[7]);
	printf("%d\n", chickens.data[8]);
	printf("%d\n", chickens.data[9]);
	printf("%d\n", chickens.data[10]);
	

	free(chickens.data);
	return 0;
}