//
// Created by 蔡亦华 on 2018/8/5.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void InitList(LinkedList *linked_list_ptr) {
    *linked_list_ptr = (LNode *) malloc(sizeof(LNode));
    (*linked_list_ptr)->next = NULL;
}

void DestroyList(LinkedList linked_list) {
    if (linked_list->next != NULL){
        DestroyList(linked_list->next);
        linked_list->next = NULL;
    }
    free(linked_list);
}

void ClearList(LinkedList linked_list) {
    DestroyList(linked_list->next);
    linked_list->next = NULL;
}

int ListEmpty(LinkedList linked_list){
    LNode *ptr = linked_list;
    if (ptr->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int ListLength(LinkedList linked_list){
    int index = 0;
    LNode *ptr = linked_list;
    while (ptr->next != NULL){
        ptr = ptr->next;
        index ++;
    }
    return index;

}

ElemType GetElem(LinkedList linked_list, int position){
    LNode *ptr = linked_list;
    int index = 0;
    while (index != position){
        ptr = ptr->next;
        index++;
    }
    return ptr->data;
}

int LocateElem(LinkedList linked_list, ElemType data, int (*compare)(ElemType, ElemType)){
    LNode *ptr = linked_list;
    ptr = ptr->next;
    int index = 1;
    while (!(*compare)(ptr->data, data)){
        ptr = ptr->next;
        index++;
    }
    return index;
}

void ListDelete(LinkedList linked_list, int position) {
    LNode *ptr = linked_list;
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
    //index++;
    //printf("%d -> end\n", index);
    //printf("\n");
}