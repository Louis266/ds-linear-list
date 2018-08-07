//
// Created by 蔡亦华 on 2018/8/5.
//

#ifndef DS_LINEAR_LIST_LINEARLIST_H
#define DS_LINEAR_LIST_LINEARLIST_H

#endif //DS_LINEAR_LIST_LINEARLIST_H

typedef char ElemType;

typedef struct lnode LNode;

struct lnode {
    ElemType data;
    LNode *next;
};

typedef LNode *LinkedList;


void InitList(LinkedList *);

void DestroyList(LinkedList);

void ListDelete(LinkedList, int);

int ListInsert(LinkedList, int, ElemType);

void ListTravels(LinkedList, void (*visit)(int, ElemType));
