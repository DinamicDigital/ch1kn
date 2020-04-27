#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS(x) (sizeof(x) / sizeof(x[0]))

typedef uint8_t  u8;
typedef int8_t   s8;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint32_t u32;
typedef int32_t  s32;
typedef uint64_t u64;
typedef int64_t  s64;

#define DECLARE_DYNARRAY(FORMAL_NAME, INTERNAL_NAME, TYPE) \
typedef struct INTERNAL_NAME {                \
    TYPE* data;                          \
    u32 size;                            \
                                         \
    u32 elements;                        \
    u32 roof;                            \
                                         \
} FORMAL_NAME;

DECLARE_DYNARRAY(Char_Array, darr_c, char);
DECLARE_DYNARRAY(U8_Array, darr_u8, u8);
DECLARE_DYNARRAY(U16_Array, darr_u16, u16);
DECLARE_DYNARRAY(U32_Array, darr_u32, u32);
DECLARE_DYNARRAY(U64_Array, darr_u64, u64);
DECLARE_DYNARRAY(S8_Array, darr_s8, s8);
DECLARE_DYNARRAY(S16_Array, darr_s16, s16);
DECLARE_DYNARRAY(S32_Array, darr_s32, s32);
DECLARE_DYNARRAY(S64_Array, darr_s64, s64);

void init_dynarr_s32(S32_Array* arr, s32 first_value)
{
	arr->size = sizeof(u32);
	arr->data = malloc(arr->size);
	arr->data[0] = first_value;
	arr->elements = 1;
	arr->roof = 2;
}

void append_dynarr_s32(S32_Array* arr, s32 value)
{
	printf("append %d\n", value);

	if (arr->elements == arr->roof)
	{
		printf("resizing to %d\n", arr->size + (arr->size * 50 / 100));
		// Handle resizing
		arr->data = realloc(arr->data, arr->size + (arr->size * 50 / 100));
		arr->roof = arr->roof + (arr->roof * 50 / 100);
		printf("roof size: %d\n", arr->roof);
	}


	// we dont need to add one to arr->elements because dynarr's start with 1 element. 
	// (we are working with array indexes, so 0 is the 1st element.
	arr->data[arr->elements] = value;
	arr->elements += 1;
	arr->size += sizeof(s32);
	printf("array data: %d\n", arr->data[arr->elements]);
	printf("elements: %d\n", arr->elements);
	printf("size: %d\n\n", arr->size);

}

void pop_dynarr_s32(S32_Array* arr)
{
	//arr->data[arr->elements] = 0xCCCCCC;
	
	
	arr->data = realloc(arr->data, arr->size - sizeof(s32));
	arr->elements -= 1;
	arr->size -= sizeof(s32);
	
}

/*
// NOTE: Free buffer when done with it.
char* read_entire_file(char* file)
{
	FILE* source_file = fopen(file, "rb");
	if (!source_file)
	{
		perror("ch1kn.h");
		return 0;
	}

	fseek(source_file, 0, SEEK_END);
	long src_size = ftell(source_file);
	fseek(source_file, 0, SEEK_SET);

	char* buffer = malloc(src_size + 1);

	fread(buffer, 1, src_size, source_file);
	fclose(source_file);
	buffer[src_size] = 0;

	return buffer;
}*/