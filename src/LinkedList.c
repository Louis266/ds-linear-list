//
// Created by 蔡亦华 on 2018/8/5.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void InitList(LinkedList *linked_list) {
    *linked_list = (LNode *) malloc(sizeof(LNode));
    (*linked_list)->next = NULL;
}

void ListDelete(LinkedList linkedlist, int position) {
    LNode *ptr = linkedlist;
    int i = 0;
    while (i != position) {
        ptr = ptr->next;
        i++;
    }
    ptr->data = ptr->next->data;
    LNode *temp;
    temp = ptr->next->next;
    free(ptr->next);
    ptr->next = temp;


}

void DestroyList(LinkedList linkedlist) {
    LNode *ptr = linkedlist;
    if (ptr->next != NULL) {
        DestroyList(linkedlist->next);
    } else {
        free(ptr);
    }
}

int ListInsert(LinkedList linked_list, int i, ElemType data) {
    LNode *ptr = linked_list;
    for (int j = 1; j <= i; j++) {
        if (j == i) {
            LNode *node = (LNode *) malloc(sizeof(LNode));
            node->data = data;
            node->next = ptr->next;
            ptr->next = node;
        } else {
            if (ptr->next == NULL) {
                return -1;
            }
            ptr = ptr->next;

        }
    }
    return 0;
}

void ListTravels(LinkedList linked_list, void (*visit)(int, ElemType)) {
    int index = 0;
    LNode *ptr = linked_list;
    while ((ptr = ptr->next) != NULL) {
        index++;
        (*visit)(index, ptr->data);
    }
}