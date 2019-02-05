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

void list_add(List *lst, int num) {
    if(lst == NULL) {
        printf("ERROR: list_add not added\n");
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

    lst->count += 1;
}

List* list_map(List *lst, int map_function(int)) {
    if(lst == NULL || map_function == NULL) {
        return NULL;
    }

    List* result = calloc(1, sizeof(List));
    result = list_new();

    if(lst->count == 0) {
        return result;
    }

    Node* current = lst->root;

    while(current != NULL) {
        list_add(result, map_function(current->number));
        current = current->next;
    }

    return result;
}

void list_do(List *lst, void do_function(int)) {
    if(lst == NULL || do_function == NULL) {
        return;
    }

    if(lst->count == 0) {
        return;
    }

    Node* current = lst->root;
    while(current != NULL) {
        do_function(current->number);
        current = current->next;
    }
}

void list_free(List *lst) {
    if(lst == NULL) {
        return;
    }

    if(lst->root == NULL) {
        free(lst);
        return;
    }

    Node* tmp = lst->root;

    while(tmp != NULL) {
        Node* del = tmp;
        tmp = tmp->next;
        free(del);
    }

    free(lst);
}

int quadrat(int zahl) {
    return zahl * zahl;
}

int kubik(int zahl) {
    return zahl * zahl * zahl;
}

void print(int zahl) {
    printf("%d; ", zahl);
}

int main(int argc, char* argv[]) {
    List* lst = list_new();

    int i;

    for(i = 0; i < 100; i++) {
        list_add(lst, i);
    }

    List* lst2 = list_map(lst, quadrat);
    List* lst3 = list_map(lst, kubik);

    list_do(lst2, print);

    list_free(lst);
    list_free(lst2);
    list_free(lst3);

    return 0;
}