#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int number;
    struct _node* next;
} Node;

typedef struct {
    Node* root;
    Node* top;
    int count;
} List;

List* list_new() {
    List* lst = calloc(1, sizeof(List));
    lst->count = 0;
    lst->root = NULL;
    lst->top = NULL;

    return lst;
}

void list_add(List* lst, int num) {
    if(lst == NULL) {
        printf("ERROR\n");
    }

    Node* n = calloc(1, sizeof(Node));
    n->number = num;

    if(lst->count == 0) {
        lst->root = n;
        lst->top = n;
    } else {
        lst->top->next = n;
        lst->top = n;
    }

    lst->count++;
}

void list_print(List* lst) {
    if(lst != NULL) {
        int i;
        Node* tempNode = lst->root;
        for(i = 0; i < lst->count; i++) {
            printf("Node-Number: %d\n", tempNode->number);
            tempNode = tempNode->next;
        }
    }
}

int main(int argc, char* argv[]) {
    List* myList = list_new();
    list_add(myList, 1);
    list_add(myList, 0);
    list_add(myList, 0);
    list_add(myList, 1);
    list_add(myList, 1);
    list_add(myList, 0);
    list_add(myList, 1);
    list_print(myList);

    return 0;
}