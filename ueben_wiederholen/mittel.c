#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    struct _node* previous;
    struct _node* next;
    int value;
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

Node* list_append(List* list, int value) {
    if(list == NULL) {
        return NULL;
    }

    Node* node = calloc(1, sizeof(Node));
    node->value = value;

    if(list->root != NULL) {
        node->previous = list->top;
        list->top->next = node;
    } else {
        list->root = node;
    }

    list->top = node;

    list->count += 1;
    return node;
}

void list_print(List* list) {
    printf("List print\n");
    if(list == NULL) {
        return;
    }

    Node* currentNode = list->root;

    for(int i = 0; i < list->count; i++) {
        printf("Node %d: %d\n", i, currentNode->value);
        currentNode = currentNode->next;
    }
}

static void switch_position(Node* a, Node* b, List* list) {
    if(a == NULL || b == NULL || list == NULL) {
        printf("WARNING: encountered NULL pointer in switch position\n");
        return;
    }

    /*
    if(a == list->root) {
        list->root = b;
    }
    
    if(b == list->top) {
        list->top = a;

        // z.B. 1 2 3 4 5 printf("\n");
    }

    // (a->previous) -> (a) -> (b) -> (b->next) // zu
    // (a->previous) -> (b) -> (a) -> (b->next)*/
    if(a == list->root) {
        list->root = b;
    }

    if(b == list->top) {
        list->top = a;
    }

    Node* tempPrevious = a->previous;
    
    a->next = b->next;
    a->previous = b;

    b->next = a;
    b->previous = tempPrevious;

    if(b->previous != NULL) {
        b->previous->next = b;
    }

    if(a->next != NULL) {
        a->next->previous = a;
    }
}

void list_sort(List* list, int compare_fkt(int, int)) {
    if(list == NULL) { 
        return;
    }

    for(int i = 0; i < list->count; i++) {
        Node* n = list->root;
        while(n != NULL) {
            if(n->next != NULL) {
                if(compare_fkt(n->value, n->next->value) > 0) {
                    switch_position(n, n->next, list);
                }
            }

            n = n->next;
        }
    }
}

void list_free(List* list) {
    if(list == NULL) { 
        return;
    }

    Node* tmp;
    Node* tmp2;

    tmp = list->root;
    
    while(tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    } 
    
    free(list);
}

static int asc(int a, int b) {
    return a - b;
}

static int desc(int a, int b) { 
    return b - a;
}

int main(int argc, char* argv[]) {
    List* lst = list_new();
    
    list_append(lst, 5);
    list_append(lst, 3);
    list_append(lst, 2);
    list_append(lst, 1);
    list_append(lst, 4);
    list_print(lst);

    // Aufsteigend sortiert
    list_sort(lst, asc);
    list_print(lst);
    
    // Absteigend sortiert
    list_sort(lst, desc);
    list_print(lst);

    list_free(lst);
    return 0;
}