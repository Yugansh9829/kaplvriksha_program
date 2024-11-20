#include<stdio.h>
#include<string.h>
#define Max_Size 100

struct user_schema{
    char name[Max_Size];
    char id[Max_Size];
    int age;   
};

//unique id will be serial number of line.
int exists(char a[]){
    FILE * fp = fopen("practice.txt", "r");
    char buffer[100];
    char id[Max_Size];
    int found =0 ;
    while(fgets(buffer, 100, fp)){
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
    //first check if user already exists or not, if not exists then append it in file else show message that user already exists. 
    struct user_schema user;
    //check if any user already exists with this id or not if exists then return with message else continue;
    char another = 'y';

    while(another=='y'){
        fflush(stdin);
        printf("\nEnter id of user : ");
        gets(user.id);

        while(exists(user.id)){
            printf("\nuser already exists with this id please enter different id here : ");
            gets(user.id);
        }
    
        printf("\nEnter name of user : ");
        gets(user.name);


        printf("\nEnter age of user : ");
        scanf("%d", &user.age);
    
        FILE *fp;
        fp = fopen("practice.txt", "a");
        fprintf(fp,"{ id : %s, name : %s, age : %d }\n", user.id, user.name, user.age);

        printf("Add another user(y/n): ");
        fflush(stdin);//to clear input buffer.
        scanf("%c",&another);

        fclose(fp);
    }
    printf("\n------------------------------------\n");
    return;
}

void display_users(){
    FILE *fp = fopen("practice.txt", "r");

    if(fp==NULL){
        printf("No user exists in database\n");
        return;
    }
    struct user_schema user;
    printf("id        name          age \n\n");
    char buffer[100];
    while(fgets(buffer, 100, fp)){
        if(sscanf(buffer, "{ id : %[^,], name : %[^,], age : %d }", user.id, user.name, &user.age)==3){ //%[^,] This will read string untill the next comma.
            printf("%-8s %-15s %-3d\n", user.id, user.name, user.age);
        }
    }
    //here we are storing each line in buffer and then we are scanning buffer to get our desired output.
    printf("\n");
    fclose(fp);
    printf("\n--------------------------------------\n");
    return;
}

int delete_user(char id[]){
    if(exists(id)){
        FILE *fp = fopen("practice.txt", "r");
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
        remove("practice.txt");
        rename("temp.txt","practice.txt");

    }else{
        printf("No such user exists in our database \n");
        return 0;
    }

    return 1;
}


void update_user(char id[]){

    if(!delete_user(id)) return;
    
    FILE*fp = fopen("practice.txt", "a");

    if(!fp){
        printf("Error Opening file.");
        return;
    }

    char name[Max_Size];
    int age;
    printf("Enter new name : ");
    gets(name);
    printf("Enter new age : ");
    scanf("%d",&age);

    fprintf(fp, "{ id : %s, name : %s, age : %d }", id, name, age);
    fclose(fp);
    printf("--------------------------------------\n");
}


int main(){

    int flag = 1;
    int operation;//initialize operation with random value;
    do{
        printf("\nselect the operation you want to perform : \n");
        printf("Press 1 to add new user(which does not exists in our database)\n");
        printf("Press 2 to display all users which exists in our database\n");
        printf("Press 3 to update a specific user in our database\n");
        printf("Press 4 to delete a user from our database\n");
        printf("Press 0 to exit the program\n");
        scanf("%d", &operation);
        
        if(operation==1){
            fflush(stdin);//to clear the input buffer.
            add_user();
        }
        else if(operation==2){
            display_users();
        }
        else if(operation==3){

            char id[Max_Size];
            char another = 'y';
            while(another == 'y'){
                fflush(stdin);
                printf("Please enter the id of user you want to update : ");
                gets(id);
                printf("\n");
                update_user(id);
                printf("Update another user (y/n) : ");
                fflush(stdin);
                scanf("%c",&another);
            }
            
        }
        else if(operation==4){
            char id[Max_Size];
            char another = 'y';
            while(another=='y'){
                fflush(stdin);
                printf("Please enter the id of user you want to delete : ");
                gets(id);
                printf("\n");
                delete_user(id);
                printf("Delete another user (y/n) : ");
                fflush(stdin);
                scanf("%c", &another);
            }
            
        }
        else if(operation==0){
            flag = 0;
            printf("\nExiting..");
        }
        else printf("Please select correct operation to perform\n");

    }while(flag);

    return 0;
}


//remaining portion : 
//1.delete practice file anbd rename temp file as practice file.
//2. organize the code and optimize it.