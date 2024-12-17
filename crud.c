#include<stdio.h>
#include<string.h>
#define Max_Size 100

struct user_schema{
    char name[Max_Size];
    char id[Max_Size];
    int age;   
};

int exists(char a[]){
    FILE * fp = fopen("user.txt", "r");
    char buffer[Max_Size];
    char id[Max_Size];
    int found =0 ;
    while(fgets(buffer, Max_Size, fp)){
        if(sscanf(buffer, "{ id : %[^,]s", id)==1){
            if(strcmp(id, a)==0){
                found =1;
                break;
            }
        }
    }
    fclose(fp);
    return found;
}

void add_user(){
    struct user_schema user;
    char another = 'y';

    while(another=='y'){
        fflush(stdin);
        printf("\nEnter id of user : ");
        scanf("%[^\n]s", user.id);
        fflush(stdin);

        while(exists(user.id)){
            printf("\nuser already exists with this id please enter different id here : ");
            scanf("%[^\n]s", user.id);

        }
        fflush(stdin);
        printf("\nEnter name of user : ");
        scanf("%[^\n]s", user.name);


        printf("\nEnter age of user : ");
        scanf("%d", &user.age);
    
        FILE *fp;
        fp = fopen("user.txt", "a");
        fprintf(fp,"{ id : %s, name : %s, age : %d }\n", user.id, user.name, user.age);

        printf("Add another user(y/n): ");
        fflush(stdin);
        scanf("%c",&another);

        fclose(fp);
    }
    printf("\n------------------------------------\n");
    return;
}

void display_users(){
    FILE *fp = fopen("user.txt", "r");

    if(fp==NULL){
        printf("No user exists in database\n");
        return;
    }
    struct user_schema user;
    printf("id        name          age \n\n");
    char buffer[Max_Size];
    while(fgets(buffer, Max_Size, fp)){
        if(sscanf(buffer, "{ id : %[^,], name : %[^,], age : %d }", user.id, user.name, &user.age)==3){
            printf("%-8s %-15s %-3d\n", user.id, user.name, user.age);
        }
    }
    printf("\n");
    fclose(fp);
    printf("\n--------------------------------------\n");
    return;
}

int delete_user(char id[]){
    if(exists(id)){
        FILE *fp = fopen("user.txt", "r");
        FILE *ft = fopen("temp.txt", "w");

        char buffer[Max_Size];
        struct user_schema user;
        while(fgets(buffer, Max_Size, fp)){

            if(sscanf(buffer, "{ id : %[^,], name : %[^,], age : %d }", user.id, user.name, &user.age)==3){
                if(strcmp(user.id,id)!=0){
                    fprintf(ft,"{ id: %s, name : %s, age : %d }\n", user.id, user.name, user.age);
                }
            }
        }
        fclose(fp);
        fclose(ft);
        remove("user.txt");
        rename("temp.txt","user.txt");

    }else{
        printf("No such user exists in our database \n");
        return 0;
    }

    return 1;
}


void update_user(char id[]){

    if(!delete_user(id)) return;
    
    FILE*fp = fopen("user.txt", "a");

    if(!fp){
        printf("Error Opening file.");
        return;
    }

    char name[Max_Size];
    int age;
    fflush(stdin);
    printf("Enter new name : ");
    scanf("%[^\n]s", name);
    fflush(stdin);
    printf("Enter new age : ");
    scanf("%d",&age);

    fprintf(fp, "{ id : %s, name : %s, age : %d }", id, name, age);
    fclose(fp);
    printf("\n--------------------------------------\n");
}


int main(){

    int flag = 1;
    int operation;
    do{
        printf("\nselect the operation you want to perform : \n");
        printf("Press 1 to add new user(which does not exists in our database)\n");
        printf("Press 2 to display all users which exists in our database\n");
        printf("Press 3 to update a specific user in our database\n");
        printf("Press 4 to delete a user from our database\n");
        printf("Press 0 to exit the program\n");
        scanf("%d", &operation);
        
        if(operation==1){
            fflush(stdin);
            add_user();
        }
        else if(operation==2){
            display_users();
        }
        else if(operation==3){
            char id[Max_Size];
            fflush(stdin);

            printf("Please enter the id of user you want to update : ");
            scanf("%[^\n]s", id);
            printf("\n");
            update_user(id);
        }
        else if(operation==4){
            char id[Max_Size];
            fflush(stdin);
            printf("Please enter the id of user you want to delete : ");
            scanf("%[^\n]s", id);
            printf("\n");
            delete_user(id);
        }
        else if(operation==0) flag = 0;
        else printf("Please select correct operation to perform\n");

    }while(flag);

    return 0;
}


//remaining portion : 
//2. organize the code and optimize it.
