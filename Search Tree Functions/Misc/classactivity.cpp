#include <stdio.h>
#include <stdlib.h>

//Stack Programing with Pointers
// Code written by ALI HAMZA MALIK



int MAX_Stack_size=3;

struct Node{
    int data;
    Node *next;
};

struct stack {
struct Node *head;
struct Node *top;
};

Node* Create_Node(int data) {
    Node *x=new Node;
    x->data = data;
    x->next = NULL;
    return x;
}


stack* init_stack() {
    stack *s = new stack;
    s->head = NULL;
    s->top = NULL;
    return s;
    }


int IsEmpty(stack *s) {
if(s->top == NULL)
  return 1;
return 0;
}

//push
void push(stack *s, Node *n) {
if(IsEmpty(s)) { //empty
  s->head = n;
  s->top = n;
}
else if (abs((s->top-s->head)/2)==MAX_Stack_size)
{
    printf("------------------------ Stack Overflow ------------------------\n");
}
else{
  s->top->next = n;
  s->top = n;
}
}


//pop
int pop(stack *s) {
if(IsEmpty(s)) {
  printf("------------------------ Stack Underflow ------------------------\n");
  return -1;
}
else {
  int tmp = s->top->data;
  if(s->top == s->head) {
    delete s->top;
    s->top = NULL;
    s->head = NULL;
  }
  else {
    Node *temp = s->head;
    while(temp->next != s->top) 
      temp = temp->next;
    temp->next = NULL;
    delete s->top ;
    s->top = temp;
  }
  return tmp;
}
}




void ReverseStack(stack *s){
    stack *r=init_stack();  
    while(s->head!=NULL){
        int tmpval=pop(s);
        Node *tmp=Create_Node(tmpval);
        push(r,tmp);
    }
    *s=*r;
}



void print_stack_val(stack *s) {
    if(IsEmpty(s)){
        printf("Stack is Empty");
    }
    else{
    Node *tmp=s->head;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->next;
        }
    }
    printf("\n");
}

int main()
{
    system("CLS");

    stack *s=init_stack();  

   printf("COMMANDS-> 0: Exit | 1 :push | 2 :pop | 3 :Reverse Stack Values | 4 :Print Stack Values | 5: Print Top Value | 6: Change Max Stack Value  \n");
    int check =1;
    while(check!=0){
        
        printf("Enter Command: ");
        scanf("%d",&check);
        
        switch (check)
        {
        case 0:
            break;
        case 1:
            int tmp;
            printf("Enter Value: ");
            scanf("%d",&tmp);
            Node *t;
            t=Create_Node(tmp);
            push(s,t);
 
            break;
        case 2:
            pop(s);
            break;
        case 3:
            ReverseStack(s);
            break;
        case 4:
            printf("STACK Values Are:\n");
            print_stack_val(s);
            break;        
        case 5:
            printf("STACK Top Value is: %d\n",s->top->data);
            break;
        case 6:
            printf("Enter New Max Stack Value: ");
            scanf("%d",&tmp);
            MAX_Stack_size=tmp;
            break;                        
        default:
           printf("Invalid Command");
            break;
        }


    }

    return 0;
}





