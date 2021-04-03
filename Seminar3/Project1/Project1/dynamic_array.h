#pragma once

typedef struct {
	unsigned int len, cap;
	void** data; // Dynamic array of void pointers (void*)
} DynamicArray;

DynamicArray* create(unsigned int initial_capacity);

void insert(DynamicArray* a, void* elem);

void deleteLast(DynamicArray* a);

void display(DynamicArray* a, void (*displayElement)(void*));

void release(DynamicArray* a);

int search(DynamicArray* a, bool (*condition)(void*));