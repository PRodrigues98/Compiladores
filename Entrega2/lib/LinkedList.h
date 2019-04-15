#ifndef __LinkedList_H__ 
#define __NODE_H__ 

typedef struct linkedList LinkedList;

typedef struct linkedList {
	int type;
	int size;
	char *id;
	LinkedList *next;
} LinkedList;


LinkedList *addElement(int type, char *id, LinkedList *l);
int compareLists(LinkedList *l1, LinkedList *l2);
void forEachElement(LinkedList *l, void (*f)(LinkedList*));


#endif /* __LinkedList_H__ */