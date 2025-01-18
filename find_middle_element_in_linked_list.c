#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;


typedef struct linked_list{
    Node* head;
    Node* tail;
}linked_list;

Node *create_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void insert_at_end(linked_list* link_list, int data){
    if(link_list->head==NULL){
        link_list->head = create_node(data);
        return;
    }

    Node *ptr = link_list->head;
    while(ptr->next) ptr = ptr->next;

    ptr->next = create_node(data);
    return;
}

void find_middle_element(linked_list* link_list){
    Node *slow = link_list->head;
    Node *fast = link_list->head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("%d", slow->data);
}

int main(){

    linked_list*link_list = (linked_list*)malloc(sizeof(link_list));
    link_list->head = NULL;
    link_list->tail = NULL;
    while(1){
        int data;
        scanf("%d", &data);
        if(data == -1) break;
        insert_at_end(link_list, data);
    }


    find_middle_element(link_list);



}