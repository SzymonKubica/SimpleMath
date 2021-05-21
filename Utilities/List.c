#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct List {
	int size;
	int *list;
	int maxSize;
};

void initialize(struct List *list) {
	(*list).size = 0;
	(*list).maxSize = 20;
	(*list).list = malloc((*list).maxSize * sizeof(int)); 
}

void resize(struct List *list) {
	(*list).maxSize *= 2;
	int	*oldList = (*list).list;
	int *newList = malloc((*list).maxSize * sizeof(int));
	for (int i = 0; i < (*list).size; i++) {
		*(newList + i) = *(oldList + i);
	}
	oldList = newList;
	free(newList);
}

void freeList(struct List *list) {
	free((*list).list);
}

/* Shifts all of the elements left starting from index + 1 to list.size index.
 * It is used in removeAt function as it overwrites the element at index.
 */ 
void shiftLeft(struct List *list, int index) {
	for (int i = index; i < (*list).size; i++) {
			(*list).list[i] = (*list).list[i + 1];
	}
}

/* Shifts all elements one position to the right starting from index to list.size.
 * It is used bu addAt function as it creates an empty place at index.	
 */
void shiftRight(struct List *list, int index) {
	for (int i = (*list).size; i > index; i--) {
			(*list).list[i] = (*list).list[i - 1];
	}
}

void add(struct List *list, int element) {
	if ((*list).size == (*list).maxSize)
		resize(list);
	(*list).list[(*list).size] = element;
	(*list).size++;
}

void addAt(struct List *list, int element, int index) {
	if ((*list).size == (*list).maxSize)
		resize(list);
	shiftRight(list, index);
	(*list).list[index] = element;
	(*list).size++;
}


int get(struct List list, int index) {
	return list.list[index];
}

int removeAt(struct List *list, int index) {
	int result = get(*list, index);
	shiftLeft(list, index);
	(*list).size--;
	return result;
}

int pop(struct List *list) {
	return removeAt(list, (*list).size);
}

void printList(struct List list) {
	printf("[");
	if (list.size > 0) {
		for (int i = 0; i < list.size - 1; i++) {
				printf("%d, ", get(list, i));
		}
		printf("%d", get(list, list.size - 1));
	}
	printf("]\n");
}

int main(void) {
	struct List list;
	initialize(&list);

	printList(list);

	for (int i = 0; i < 4; i++) {
		add(&list, i);
	}

	printList(list);

	removeAt(&list, 3);

	printList(list);

	addAt(&list, 5, 1);

	printList(list);

	for (int i = 0; i < 20; i++) {
		add(&list, i);		
	}

	printList(list);

	freeList(&list);
}
