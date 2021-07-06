//1) Concatenate two SLL into one

#include<stdio.h>
#include<stdlib.h>

struct student{
    int rollno;
   
    struct student *next;
};
void display_node(struct student *stu){
    printf("RegNo. :\t%d\n",(stu->rollno));
}

struct student *get_detail(){
    struct student *new;

    new = (struct student *)malloc(sizeof(struct student));
    if(new==NULL){
        return NULL;
    }
    printf("\nEnter reg.no (Untill you entered '00') :\t");
    scanf("%d",&(new->rollno));
    if((new->rollno)==00){
        return NULL;
    }


    return new;
}

void ins_node(struct student *x, struct student *y){
    y->next=x->next;
    x->next = y;
}

void display_list(struct student *p){
    for(p=p->next;p;p=p->next){
        display_node(p);
    }
}

struct student *con(struct student *head1,struct student *head2){
    struct student *p;
    if(head1 == NULL)return head2;
    if(head2 == NULL)return head1;
    p=head1;
    while(p->next != NULL)
        p=p->next;

    p->next=head2;
    return head1;
}        

void main(){
    struct student head1 ,*p;
    struct student head2 ,*q;
    head1.next = NULL;
    head2.next = NULL;
    printf("Enter student's roll no.  in section A\n");
    while(p=get_detail()){
        ins_node(&head1,p);
    }
    printf("Enter student's roll no.  in section B\n");
    while(q=get_detail()){
        ins_node(&head2,q);
    }

    printf("the student details in section 'A' are : \n");
    display_list(&head1);
    printf("the student details in section 'B' are : \n");
    display_list(&head2);

    printf("Combining two section \n");
    con(&head1,&head2);
    display_list(&head1);
}