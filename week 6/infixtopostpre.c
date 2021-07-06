#include <stdio.h>
#include <stdlib.h>

#define size 50

struct elem{
    char data;
    struct elem* next;
}typedef elem;

elem* head = NULL;

//stack operations

int isEmpty(){
    if(head==NULL)
        return 1;

    return 0;
}

void push(char data){

    elem *new = (elem *) malloc(sizeof(elem));
    if(!new){
        printf("\n Overflow\n");
        return;
    }

    new->data = data;
    new->next = NULL;

    if(isEmpty()){
        head = new;
    }else{
        new->next = head;
        head = new;
    }
}

char pop(){
    if(isEmpty()){
        printf("\nEmpty stack, Underflow");
        return '\0';
    }

    elem *temp = head;
    char tmp = head->data;
    head = head->next;
    free(temp);
    return tmp;
}

char peek(){
    if(isEmpty()){
        return '\0';
    }
    return head->data;
}

//general operations

int isOperand(char x){
    if((x>='a' && x<='z')||(x>='A' && x<='Z') || (x>='0' && x<='9'))
        return 1;
    else
        return 0;
}


int precedence(char x){
    switch(x){
        case '+':
        case '-':
                return 1;
                break;
        case '*':
        case '/':
                return 2;
                break;
        case '^':
                return 3;
                break;
        default :
                return 0;
    }
}


//conversion of infix to postfix
void infixtopostfix(char in[], char post[]){
    
    char *ch = in;
    char *po = post;
    while(*ch!='\0'){
        if(isOperand(*ch)){
            *po = *ch;
            po++;
        }else if(*ch=='('){
            push(*ch);
        }else if(*ch==')'){
            while(!isEmpty() && peek()!='('){
                *po = pop();
                po++;
            }
            pop();
        }else{
            if(precedence(*ch) > precedence(peek())){
                push(*ch);
            }else if(precedence(*ch) == precedence(peek()) && *ch=='^'){
                push(*ch);
            }else{
                while(!isEmpty() && (precedence(*ch)<=precedence(peek()))){
                    *po = pop();
                    po++;
                }
                push(*ch);
            }
        }
        ch++;
    }

    while(!isEmpty()){
        *po=pop();
        po++;
    }
    *po='\0';
}

//function to reverse string

void revstr(char *x){
    int i, n=0;
    char temp;
    for( i=0; x[i]!='\0'; i++)n++;

    for( i=0 ; i< n/2 ; i++){
        temp = x[i];
        x[i] = x[n-1-i];
        x[n-1-i] = temp;
    }
}

//conversion of infix to prefix
void infixtoprefix(char in[], char pre[]){
    //reversing the input

    revstr(in);

    //postfix method with slight changes

    char *ch = in;
    char *pr = pre;

    while(*ch!='\0'){
        if(isOperand(*ch)){
            *pr = *ch;
            pr++;
        }else if(*ch==')'){
            push(*ch);
        }else if(*ch=='('){
            while(!isEmpty() && peek()!=')'){
                *pr = pop();
                pr++;
            }
            pop();
        }else{
            if(precedence(*ch) > precedence(peek())){
                push(*ch);
            }else if(precedence(*ch) == precedence(peek())){

                //when the input order is reversed, the exponentiation order gets reversed,
                //to avoid that have changed that alone

                if(*ch=='^'){
                    while(!isEmpty() && ( precedence (*ch) <= precedence( peek()) ) ){
                        *pr = pop();
                        pr++;
                    }
                }
                push(*ch);
            }else{
                while(!isEmpty() && ( precedence (*ch) <= precedence( peek()) ) ){
                    *pr = pop();
                    pr++;
                }
                push(*ch);
            }
        }
        ch++;
    }

    while(!isEmpty()){
        *pr=pop();
        pr++;
    }
    *pr='\0';   

    //reversing the output
    revstr(pre);

    revstr(in);
}

//driver function

int main(){
    char infix[size], postfix[size], prefix[size], c;
    int i;
    printf("Enter the infix expression\n");
    for(i=0; i<size && (c=getchar())!='\n'; i++){
        infix[i] = c;
    }
    infix[i]='\0';

    infixtopostfix(infix, postfix);
    infixtoprefix(infix, prefix);
   printf("\n***infix expression***\n%s\n",infix);
    printf("\n***postfix expression***\n%s",postfix);
    printf("\n***prefix expression***\n%s\n",prefix);
    
    return 0;
}