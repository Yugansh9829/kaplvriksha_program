#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct linked_list{
    Node *head;
    Node *tail;
}linked_list;


Node *create_node(int data){
    Node* node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    return node;

}

void insert_element_at_end(linked_list*link_list, int data){
    if(link_list->head==NULL){
        link_list->head = create_node(data);
        return;
    }
    Node *ptr = link_list->head;
    while(ptr->next) ptr=ptr->next;
    ptr->next = create_node(data);
    return;
}

void insert_element_at_beginning(linked_list*link_list, int data){
    Node*node = create_node(data);
    node->next = link_list->head;
    link_list->head = node;
    return;
}

void insert_element_at_given_position(linked_list* linked_list, int data, int position){
    Node*ptr = linked_list->head;
    if(position==1){
        Node*temp = create_node(data);
        temp->next = ptr;
        linked_list->head = temp;
        return;
    }
    position-=2;

    while(position-- && ptr->next) ptr = ptr->next;

    if(!ptr->next){
        printf("invalid position entered \n");
        return;
    }
    Node*temp = ptr->next;
    ptr->next = create_node(data);
    ptr->next->next = temp;

    return;
}

void display_linked_list(Node *head){
    Node *ptr = head;
    while(ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

void update_at_position(linked_list *link_list, int position, int value){
    Node *ptr = link_list->head;
    
    if(position==1){
        ptr->data = value;
        return;
    } 

    while(--position && ptr->next) ptr = ptr->next;
    
    if(!ptr || !ptr->next){
        printf("***enter valid position***]n");
        return;
    }

    ptr->data = value;
    return;
}

void delete_first_element(linked_list*link_list){
    if(link_list->head == NULL){
        printf("*****No elements in linked list*****\n");
        return;
    }

    link_list->head = link_list->head->next;
    return;

}

void delete_last_element(linked_list*link_list){
    if(!link_list->head){
        printf("****No element in linked list***");
        return;
    }
    if(!link_list->head->next){
        link_list->head = link_list->head->next;
    }

    Node *ptr = link_list->head;
    while(ptr->next->next) ptr = ptr->next;
    ptr->next = ptr->next->next;
}

void delete_element_at_given_position(linked_list *link_list, int position){
    if(!link_list->head){
        printf("**no element exists in linked list**\n");
        return;
    }
    if(position==1){
        link_list->head = link_list->head->next;
        return;
    }

    position-=1;
    Node *ptr = link_list->head;
    while(--position && ptr->next)  ptr= ptr->next;
    
    if(!ptr->next){
        printf("Enter valid position\n");
        return;
    }
    ptr->next = ptr->next->next;
    return;
}

void take_input(int n){

    linked_list*link_list = (linked_list*)malloc(sizeof(linked_list));

    link_list->head = NULL;
    link_list->tail = NULL;

    while(n--){

        int operation;
        scanf("%d", &operation);

        if(operation==1){
            int x;
            scanf("%d", &x);
            insert_element_at_end(link_list, x); 
        }
        else if(operation==2){
            int x;
            scanf("%d", &x);
            insert_element_at_beginning(link_list, x);
        }
        else if(operation==3){
            int position;
            scanf("%d", &position);
            int data;
            scanf("%d", &data);
            
            if(position<1){
                printf("Invalid position : \n");
                return;
            }
            insert_element_at_given_position(link_list, data, position);
        }
        else if(operation==4)  display_linked_list(link_list->head);
        
        else if(operation==5){
            int position;
            scanf("%d", &position);
            int value;
            scanf("%d", &value);
            update_at_position(link_list, position, value);
        }
        else if(operation==6) delete_first_element(link_list);
        
        else if(operation==7) delete_last_element(link_list);
        
        else if(operation==8){
            int position;
            scanf("%d", &position);

            delete_element_at_given_position(link_list, position);
        }
        else{
            printf("enter valid operation.(wrong operation choosen.) \n");
            return;
        }

    }

}

int main(){

    int n;
    scanf("%d", &n);
    take_input(n);
 
    return 0;
}