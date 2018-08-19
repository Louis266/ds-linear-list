#include <stdio.h>
#include <stdbool.h>
#include "LinkedList.h"

void print_node(int index, ElemType data) {
    printf("%d -> %c\n", index, data);
}

int compare(ElemType a, ElemType b) {
    if (a == b) {
        return 1;
    } else {
        return 0;
    }

}

int main() {

    printf("step 0, test and create a new linked list: \n");
    printf("Hello, World!\n");

    LinkedList link_list;//create a new linked list

    InitList(&link_list);//initialize the new linked list

    if (ListEmpty(link_list)) {
        printf("This linked list is empty\n");//test empty list function
    }

    printf("===============================\n");

    printf("step 1 insert some nodes: \n");

    //insert some nodes
    ListInsert(link_list, 1, 'A');
    ListInsert(link_list, 2, 'B');
    ListInsert(link_list, 1, 'C');

    ListTravels(link_list, print_node);//print out all elements
    printf("Length of the list is: %d \n", ListLength(link_list));//print out the length of the list

    printf("===============================\n");

    printf("step 2 delete some nodes: \n");

    ListDelete(link_list, 1);//delete the first node in the list

    ListTravels(link_list, print_node);//print out all elements
    printf("Length of the list is: %d \n", ListLength(link_list));//print out the length of the list

    ListDelete(link_list, 1);//delete the first node in the list

    ListTravels(link_list, print_node);//print out all elements
    printf("Length of the list is: %d \n", ListLength(link_list));//print out the length of the list

    printf("===============================\n");

    printf("step 3 clear the list\n");

    ClearList(link_list);
    ListInsert(link_list, 1, 'D');
    ListInsert(link_list, 2, 'E');

    ListTravels(link_list, print_node);//print out all elements
    printf("Length of the list is: %d \n", ListLength(link_list));//print out the length of the list

    printf("===============================\n");

    printf("step 4: get element by its index: \n");

    printf("2nd elem is %c\n", GetElem(link_list, 2));//get the 2nd element

    printf("===============================\n");

    printf("step 5: get index by elements' data: \n");

    printf("E is the %dth element\n", LocateElem(link_list, 'E', compare));

    printf("===============================\n");

    printf("step : destroy the list and free storage: \n");

    //delete the list
    DestroyList(link_list);
    link_list = NULL;

    return 0;
}