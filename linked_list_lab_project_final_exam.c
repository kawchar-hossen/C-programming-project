#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char student_name[50];
    int student_id;
    float cgpa;
    struct node *p;
};

void insertion_at_last_position(struct node *head, char name[], int id, float cgpa);
void display(struct node *head);
int count(struct node *head);
void insertion_specific_position(struct node *head, char name[], int id, float cgpa, int pp);
void deletion(struct node *head, int pp);
void linear_search(struct node *head, int id);
void save_data(struct node *head);
void load_data(struct node *head);

int main(){
    struct node *list;
    list = (struct node*)malloc(1*sizeof(struct node));
    list->p = NULL;
    int choice, v, p, n;
    char name[50];
    int id;
    float cgpa;
    load_data(list);
    while(1){
        printf("\n\n1. Insertion at last position\n2. Insertion at specific position\n3. Display\n4. Deletion from specific position\n5. Count nodes\n6. Linear search\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nChoice = Insertion at last position\n");
                    printf("Enter student name: ");
                    scanf("%s", name);
                    printf("Enter student ID: ");
                    scanf("%d", &id);
                    printf("Enter student CGPA: ");
                    scanf("%f", &cgpa);
                    insertion_at_last_position(list, name, id, cgpa);
                    save_data(list);
                    break;
            case 2: printf("\nChoice = Insertion at specific position\n");
                    printf("Enter student name: ");
                    scanf("%s", name);
                    printf("Enter student ID: ");
                    scanf("%d", &id);
                    printf("Enter student CGPA: ");
                    scanf("%f", &cgpa);
                    if(list->p != NULL){
                        M: printf("\nEnter position between %d to %d: ", 1, count(list));
                        scanf("%d", &p);
                        if(p >= 1 && p <= count(list)){
                            insertion_specific_position(list, name, id, cgpa, p);
                            save_data(list);
                            printf("Data save successfully!");
                        }else{
                            printf("\nInvalid position\n");
                            goto M;
                        }
                    }else{
                        printf("\nPlease initialize the list first\n");
                    }
                    break;
            case 3: printf("\nChoice = Display\n\n");
                    if(list->p != NULL){
                        display(list);
                    }else{
                        printf("\nNo information to display\n");
                    }
                    break;
            case 4: printf("\nChoice = Deletion from specific position\n");
                    n = count(list);
                    if(n != 0){
                        K: printf("\nEnter position between %d to %d: ", 1, n);
                        scanf("%d", &p);
                        if(p >= 1 && p <= n){
                            deletion(list, p);
                            save_data(list);
                        }else{
                            printf("\nWrong position\n");
                            goto K;
                        }
                    }else{
                        printf("\nThe list is empty\n");
                    }
                    break;
            case 5: printf("\nChoice = Count nodes\n");
                    n = count(list);
                    printf("\nTotal nodes = %d", n);
                    break;
            case 6: printf("\nChoice = Linear search\n");
                    printf("\nEnter student ID to search: ");
                    scanf("%d", &id);
                    if(count(list) == 0){
                        printf("\nList is empty\n");
                    }else{
                        linear_search(list, id);
                    }
                    break;
            case 7: printf("\nExiting program...\n");
                    save_data(list);
                    exit(0);
            default: printf("\nInvalid choice\n");
                     break;
        }
    }
    return 0;
}

void insertion_at_last_position(struct node *head, char name[], int id, float cgpa){
    struct node *temp;
    while(head->p != NULL){
        head = head->p;
    }
    temp = (struct node*)malloc(1*sizeof(struct node));
    strcpy(temp->student_name, name);
    temp->student_id = id;
    temp->cgpa = cgpa;
    temp->p = head->p;
    head->p = temp;
}

void display(struct node *head){
    printf("\nStudent Name\tStudent ID\t\tCGPA\n");
    while(head->p != NULL){
        printf("%s\t\t%d\t\t%.2f\n", head->p->student_name, head->p->student_id, head->p->cgpa);
        head = head->p;
    }
}

int count(struct node *head){
    int t = 0;
    while(head->p != NULL){
        t += 1;
        head = head->p;
    }
    return t;
}

void insertion_specific_position(struct node *head, char name[], int id, float cgpa, int pp){
    int i = 0;
    struct node *temp;
    while(head->p != NULL){
        if(i == pp-1)
            break;
        head = head->p;
        i++;
    }
    temp = (struct node*)malloc(1*sizeof(struct node));
    strcpy(temp->student_name, name);
    temp->student_id = id;
    temp->cgpa = cgpa;
    temp->p = head->p;
    head->p = temp;
}

void deletion(struct node *head, int pp){
    struct node *temp;
    int i = 0;
    if(pp == 1){
        temp = head->p;
        head->p = temp->p;
        free(temp);
    }else{
        while(head->p != NULL){
            if(i == pp-1){
                break;
            }
            head = head->p;
            i++;
        }
        temp = head->p;
        head->p = temp->p;
        free(temp);
    }
   
}

void linear_search(struct node *head, int id){
    int c = 0;
    while(head->p != NULL){
        if(id == head->p->student_id){
            printf("\nStudent found: %s\n", head->p->student_name);
            c = 1;
            break;
        }else{
            head = head->p;
        }
    }
    if(c == 0){
        printf("\nStudent not found\n");
    }
}

void save_data(struct node *head){
    FILE *fp;
    fp = fopen("student_data.txt", "w");
    if(fp == NULL){
        printf("\nError opening file\n");
        return;
    }
    while(head->p != NULL){
        fprintf(fp, "%s %d %.2f\n", head->p->student_name, head->p->student_id, head->p->cgpa);
        head = head->p;
    }
    fclose(fp);
    printf("\nData saved successfully\n");
}

void load_data(struct node *head){
    FILE *fp;
    fp = fopen("student_data.txt", "r");
    if(fp == NULL){
        printf("\nError opening file\n");
        return;
    }
    char name[50];
    int id;
    float cgpa;
    while(fscanf(fp, "%s %d %f", name, &id, &cgpa) != EOF){
        insertion_at_last_position(head, name, id, cgpa);
    }
    fclose(fp);
    printf("\nData loaded successfully\n");
}