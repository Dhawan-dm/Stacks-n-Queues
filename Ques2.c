#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isFull(struct stack *s)
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s , char val)
{
    if(isFull(s))
    {
        printf("Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
char pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow");
    }
    else
    {   char val = s->arr[s->top];
        s->top--;
        return val;
    }
}
int isOperator( char a)
{
    if(a == '*' || a == '/' || a == '+' || a == '-'  )
    {
        return 1;
    }
    return 0;
}
int preference (char  a)
{
    if(a == '*' || a== '/')
    {
        return 3;
    }
    if(a == '+' || a== '-')
    {
        return 2;
    }
        return 1;
    
}
char stackTop (struct stack *s)
{
    return s->arr[s->top];
}

char *postfix(char *exp)
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char*)malloc(s->size*(sizeof(char)));
    int i = 0;
    int j = 0;
    char *post = (char*)malloc(strlen(exp)+1*(sizeof(char)));

    while(exp[i]!='\0'){

        if(!isOperator(exp[i]))
        {
            post[j] = exp[i];
            i++;
            j++;
        }
        else
        {
            if(preference(exp[i])>preference(stackTop(s)))
            {
                push(s , exp[i]);
                i++;  
            }
            else
            {
                post[j] = pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s))
    {
        post[j] = pop(s);
        j++;
    }
    post[j] = '\0';
    return post;
}


int main()
{
    char *exp = "x-y/z-k*d";
  printf("%s",postfix(exp));
}
