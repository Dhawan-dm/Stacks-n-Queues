typedef struct {
        int f;
        int r;
        int *arr;
        int size;
    
} MyStack;

MyStack *myStackCreate()
{
    MyStack *s = (MyStack *)malloc(sizeof( MyStack));
    s->f = s->r =-1;
    s->size = 1000;
    s->arr = (int *)malloc(s->size*(sizeof(int)));
    return s;
}
void myStackPush(MyStack* obj,int x)
{
     
    
     obj->f++;
     obj->arr[obj->f] = x;
}
int myStackPop(MyStack* obj)
{
    
    
     
     return obj->arr[obj->f--];
}
int myStackTop(MyStack* obj)
{
     
    
     
     return obj->arr[obj->f];
}
bool myStackEmpty(MyStack* obj)
{
     
    
     
     if(obj->r == obj->f)
     {
         return true;
     }
    return false;
}
void myStackFree(MyStack* obj) {
        free(obj->arr);
        free(obj);
}


