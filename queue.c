#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct _node* prev;
    struct _node* next;
} Node;

void add_list(Node* new, Node* head){
    head->prev->next = new;
    new->prev = head->prev;
    head->prev = new;
    new->next = head;
}

void __delete_list(Node* prev, Node* next){
    prev->next = next;
    next->prev = prev;
}

void delete_list(Node* entry){
    __delete_list(entry->prev, entry->next);
}

int list_empty(Node* head){
    return head->next == head;
}