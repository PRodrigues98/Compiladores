#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *addElement(int type, char *id, LinkedList *l){

	LinkedList *newElement = (LinkedList *)malloc(sizeof(LinkedList));

	newElement->type = type;
	newElement->id = id;
	newElement->next = l;

	if(l == NULL){
		newElement->size = 1;
	}
	else{
		newElement->size = l->size + 1;
	}

	return newElement;
}

int compareLists(LinkedList *l1, LinkedList *l2){

	LinkedList *aux1 = l1, *aux2 = l2;

	if(aux1 == NULL && aux2 == NULL){
		return 1;
	}
	else if(aux1 == NULL || aux2 == NULL){
		return 0;
	}

	if(aux1->size != aux2->size){
		return 0;
	}

	while(aux1->next != NULL && aux2->next != NULL){
		if(aux1->type != aux2->type){
			return 0;
		}

		aux1 = aux1->next;
		aux2 = aux2->next;
	}

	return 1;
}

void forEachElement(LinkedList *l, void (*f)(LinkedList*)){
	LinkedList *aux = l;

	while(aux != NULL){
		f(aux);

		aux = aux->next;
	}
}