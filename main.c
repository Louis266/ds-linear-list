#include <stdio.h>
#include "LinkedList.h"

void print_node(int index, ElemType data) {
    printf("%d -> %c\n", index, data);
}

int main() {
    printf("Hello, World!\n");

    LinkedList link_list;

    InitList(&link_list);
    ListInsert(link_list, 1, 'A');
    ListInsert(link_list, 2, 'B');
    ListInsert(link_list, 1, 'C');
    ListTravels(link_list, print_node);
    ListDelete(link_list, 1);
    ListTravels(link_list, print_node);
    DestroyList(link_list);
    //ListTravels(link_list);
    return 0;
}