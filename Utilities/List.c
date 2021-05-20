#include<stdio.h>
#include<stdlib.h>

struct List {
	int size;
	int list[20];
	int maxSize;
};

void add(struct List *list, int element);
void resize(struct List *list);
int get(struct List list, int index);
int removeElem(struct List *list, int index);
void shiftLeft(struct List *list, int index);
void printList(struct List list);

void add(struct List *list, int element) {
	if ((*list).size == (*list).maxSize)
		resize(list);
	(*list).list[(*list).size] = element;
	(*list).size++;
}

void resize(struct List *list) {
	(*list).maxSize *= 2;
	//int *ptr = realloc(list.list, list.maxSize * sizeof(int));
	//memcpy(*ptr, list.list);
}

int get(struct List list, int index) {
	return list.list[index];
}

int removeElem(struct List *list, int index) {
	int result = get(*list, index);
	shiftLeft(list, index);
	(*list).size--;
}
	
void shiftLeft(struct List *list, int index) {
	for (int i = index; i < (*list).size; i++) {
			(*list).list[i] = (*list).list[i + 1];
	}
}

void printList(struct List list) {
	for (int i = 0; i < list.size; i++) {
			printf("%d", get(list, i));
	}
}

int main(void) {
	struct List list;
	list.size = 0;
	list.maxSize = 20;

	printList(list);

	for (int i = 0; i < 4; i++) {
		add(&list, i);
	}

	printList(list);
	

}
