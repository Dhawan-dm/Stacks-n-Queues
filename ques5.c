


typedef struct {
    int top;
    int mini;
    int a[10000];
    int min[10000];
    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack)*1);
    
    stack->min[0] = INT_MAX;
    stack->top = -1;
    stack->mini = -1;
    
    return stack;
    
}

void minStackPush(MinStack* obj, int x) {
    
    int min = obj->min[obj->mini];
    
    if((x <= min) || (obj->mini == -1))
    {
        obj->mini = obj->mini + 1;
        obj->min[obj->mini] = x;
    }
    
    obj->top = obj->top + 1;
    
    obj->a[obj->top] = x;
  
}

void minStackPop(MinStack* obj) {
    
  if(obj->a[obj->top] == obj->min[obj->mini])
  {
      
      obj->mini = obj->mini - 1;
      
  }
    
  obj->top = obj->top - 1;
  
}

int minStackTop(MinStack* obj) {
  
     return obj->a[obj->top];
    
}

int minStackGetMin(MinStack* obj) {
  
    return obj->min[obj->mini];
    
}

void minStackFree(MinStack* obj) {
    
    free(obj);
    
}


