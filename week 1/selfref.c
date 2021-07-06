#include<stdio.h>
#include<stdlib.h>

struct cricket{
    int jerno;
    char name[20];
    struct cricket *next;
};

void display_node(struct cricket *stu)
{
 
	printf("%d\t \t %s \n", stu->jerno, stu->name);
}


struct cricket *get_detail(){
    struct cricket *new;
    new = (struct cricket *)malloc(sizeof(struct cricket));
    if(new==NULL)
        return NULL;

    printf("Enter the jersey no:- (till you enter the number '0')\n");
    scanf("%d",&(new->jerno));

    if(new->jerno == 0){
        return NULL;
    }
    printf("Enter player's name :-\n");
    scanf("%s",&(new->name));

    return new;
}

void ins_node(struct cricket *x, struct cricket *y){
    y->next = x->next;
    x->next=y;
}

void display_list(struct cricket *p)
{
	for(p= p->next; p; p = p->next)
	{
		display_node(p);
	}

}


void main(){
    struct cricket start,*p;
    start.next=NULL;
    printf("\nInsert initial data\n");
    while(p=get_detail()){
        ins_node(&start,p);
    }
    printf(".............INDIAN SQUAD.............\n");
    printf("\nThe details are :- \n");
    printf("Jersey No:\t Player's name \n");
    display_list(&start);
}
