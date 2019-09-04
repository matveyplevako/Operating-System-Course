#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    struct node_struct *next;
    int value;
} node;

typedef struct linked_list_struct {
    node *head;
} linked_list;

node *create_node(int value) {
    node *res = malloc(sizeof(node));
    res->value = value;
    res->next = NULL;
    return res;
}

void insert_node(linked_list *list, node *node_to_insert) {
    if (list->head == NULL) {
        list->head = node_to_insert;
    } else {
        node *cur_node = list->head;
        while ((cur_node->next) != NULL) {
            cur_node = (node *) cur_node->next;
        }
        cur_node->next = node_to_insert;
    }
}

void delete_node(linked_list *list, node *node_to_delete) {
    if (list->head == node_to_delete) {
        list->head = node_to_delete->next;
    } else {
        node *cur_node = list->head;
        while ((cur_node->next) != node_to_delete) {
            cur_node = cur_node->next;
        }
        if (cur_node->next == NULL) {
            printf("List does not contain this node\n");
        }
        cur_node->next = node_to_delete->next;
    }
}

void print_list(linked_list *list) {
    printf("-^-\n");
    node *cur_node = list->head;
    while ((cur_node) != NULL) {
        printf("<%d>\n", cur_node->value);
        cur_node = cur_node->next;
    }
    printf("---\n");
}

int main() {
    node *node1 = create_node(2);
    node *node2 = create_node(15);
    node *node3 = create_node(-3);

    linked_list *list = malloc(sizeof(linked_list));
    list->head = NULL;

    insert_node(list, node1);
    insert_node(list, node3);
    insert_node(list, node2);
    print_list(list);


    delete_node(list, node3);
    free(node3);
    print_list(list);
    delete_node(list, node1);
    free(node1);
    print_list(list);
    delete_node(list, node2);
    free(node2);
    print_list(list);

    free(list);

    return 0;

}

