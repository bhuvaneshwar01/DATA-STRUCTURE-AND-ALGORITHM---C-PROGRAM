#include<stdio.h>
#define size 100

struct student 
{
    int id;
    char name[20];
    float percentage;
};
 
 
int main() 
{
    struct student record[size];
    int i,n;

    printf("Enter the number of students :-\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the Student's rollno. :-\n");
        scanf("%d",&record[i].id);

        printf("Enter the Student's name :-\n");
        scanf("%s",&record[i].name);

        printf("Enter the Student's percentage :-\n");
        scanf("%f",&record[i].percentage);
    }      

    for(i=0;i<n;i++){
        printf(" Id is: %d \n", record[i].id);
        printf(" Name is: %s \n", record[i].name);
        printf(" Percentage is: %f \n", record[i].percentage);
    }
    return 0;
}
 
