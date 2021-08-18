typedef struct {
        int index;
        int *top;
    
} MyStack;

MyStack* myStackCreate() {
    MyStack *result = (MyStack *)malloc(sizeof(MyStack));
    result->top = (int *)malloc(1000*sizeof(int));
    result->index = -1;
    return result;
}

void myStackPush(MyStack* obj, int x) {
    obj->index++;
    obj->top[obj->index] = x;  
}


int myStackPop(MyStack* obj) {
   return obj->top[obj->index--];
}

int myStackTop(MyStack* obj) {
   return obj->top[obj->index];
}

bool myStackEmpty(MyStack* obj) {
      if(obj->index < 0) return true;
      else return false;
}

void myStackFree(MyStack* obj) {
        free(obj->top);
        free(obj);
}
