#include<stdio.h>

struct student 
{
    int id;
    char name[20];
    float percentage;
};
 
void func(struct student *record);
 
int main() 
{
    struct student record;
    printf("Enter the Student's rollno. :-\n");
    scanf("%d",&record.id);

    printf("Enter the Student's name :-\n");
    scanf("%s",&record.name);

    printf("Enter the Student's percentage :-\n");
    scanf("%f",&record.percentage);      

    func(&record);
    return 0;
}
 
void func(struct student *record)
{
          printf(" Id is: %d \n", record->id);
          printf(" Name is: %s \n", record->name);
          printf(" Percentage is: %f \n", record->percentage);
}