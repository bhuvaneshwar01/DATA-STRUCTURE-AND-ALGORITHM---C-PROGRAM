#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

typedef struct Node{
    char c;
    struct Node* link;
}Node;

Node* createNode(char c){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->c=c;
    temp->link=NULL;
    return temp;
}

typedef struct{
    Node* top;
}stack;

void push(stack *s,char c){
    Node* temp=createNode(c);
    temp->link=s->top;
    s->top=temp; 
}

char pop(stack *s){
    if(s->top==NULL){
        printf("Stack Underflow:---");
        return '\0';
    }
    Node* temp=s->top;
    char c=temp->c;
    s->top=s->top->link;
    free(temp);
    return c;
}

char peek(stack *s){
    if(s->top==NULL){
        printf("Stack Underflow:---");
        return '\0';
    }
    return s->top->c;
}
int isEmpty(stack *s){
    return s->top==NULL;
}

int prece(char c){
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else 
        return -1;
}

void postfix(char s[],stack *con){
    con->top=NULL;
    int l=strlen(s),k=0;
    char b[size];
    for(int i=0;i<l;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            b[k++]=s[i];
        }
        else if(s[i]=='(')
            push(con,'(');
        else if(s[i]==')'){
            while(!isEmpty(con) && peek(con)!='('){
                b[k++]=peek(con);
                pop(con);
            }
            if(peek(con)=='(')
                pop(con);
        }
        else{
            while(!isEmpty(con) && prece(s[i])<=prece(peek(con)) ){
                b[k++]=peek(con);
                pop(con);
            }
            push(con,s[i]);
        }
    }
    while(!isEmpty(con)){
        b[k++]=peek(con);
        pop(con);
    }
    b[k++]='\0';
    printf("The Postfix form is:%s\n",b);
}

void prefix(char s[],stack *con){
    con->top=NULL;
    int l=strlen(s),k=0;
    char b[size];
    strrev(s);
    for(int i=0;i<l;i++){
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')')
            s[i]='(';
    }
    for(int i=0;i<l;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            b[k++]=s[i];
        }
        else if(s[i]=='(')
            push(con,'(');
        else if(s[i]==')'){
            while(!isEmpty(con) && peek(con)!='('){
                b[k++]=peek(con);
                pop(con);
            }
            if(peek(con)=='(')
                pop(con);
        }
        else{
            while(!isEmpty(con) && prece(s[i])<=prece(peek(con)) ){
                b[k++]=peek(con);
                pop(con);
            }
            push(con,s[i]);
        }
    }
    while(!isEmpty(con)){
        b[k++]=peek(con);
        pop(con);
    }
    b[k++]='\0';
    strrev(b);
    printf("The Prefix form is:%s\n",b);
}
int main(){
    char a[size];
    stack s={NULL};
    printf("Enter the Infix expression:");
    scanf("%s",a);
    postfix(a,&s);
    prefix(a,&s);
    return 0;
}