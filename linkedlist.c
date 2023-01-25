// Modify this file
// compile with: gcc linkedlist.c -o linkedlist.out

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// TODO: Create your node_t type here
typedef struct node_t { 
    int num_wins;
    int year;
    struct node_t* next;
} node_t;

node_t* new_node(int wins, int year, node_t* next) { 
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->num_wins = wins;
    newNode->year = year;
    newNode->next = next; 

    return newNode;
}

    node_t* build_list(int* wins, int* years, int size) {
        int i;
        node_t* head;
        struct node_t* current;
        for (i = 0; i < size; i++) {
            node_t* new = new_node(wins[i], years[i], NULL);
            if (i == 0) {
                current = new;
                head = new;
            }
            else {
                current->next = new;
                current = new;
            }
        }
        return head;
    }

// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

// node_t* build_list(int* wins, int* years, int size) {
//     node_t* newList = (nodt_t*) malloc(sizeof(node_t));
//     newList->wins = NULL;
//     newList->year = NULL;
//     newList->size = 0;
// }

void print_list(node_t* node) {
    node_t* itr = node;
    while(itr != NULL) {
        printf("%d, %d", itr->year, itr->num_wins);
    }
}

void freeNode(node_t* node) {
    free(node);
}

int main()
{
    // node_t* head;
    // head = new_node(2018, 5, NULL);
    // node_t* new = new_node(108, 2, NULL);
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};
    node_t* head;
    build_list(test_wins, test_years, 5);
    // print_list(build_list(test_wins, test_years, 5));

    // printf("%d, %d\n", head->year, head->num_wins);
    // printf("%d, %d\n", new->year, new->num_wins);

    // head->next = new;
    // printf("%d, %d\n", head->next->year, head->next->num_wins);
    // freeNode(node);
    // TODO: Implement me!

    return 0;
}