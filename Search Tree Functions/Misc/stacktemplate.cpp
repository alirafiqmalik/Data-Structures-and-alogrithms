//#include <stdio.h>
//#include <stdlib.h>
#include<iostream>
using namespace std;


string openbrackets="{[(";
string closedbrackets="}])";    
string digits="0123456789";
string operators="+-*/";


int MAX_Stack_size=100;


template <typename T>
struct Node{
    T data;
    Node<T> *next;
};





template <typename T>
struct stack {
Node<T> *head;
Node<T> *top;

};



template <typename T>
Node <T> *Create_Node(T data) {
    Node<T> *x=new Node<T>;
    x->data = data;
    x->next = NULL;
    return x;
}

template <typename T>
void init_stack(stack<T> *s) {
    s->head = NULL;
    s->top = NULL;
    }


template <typename T>
int IsEmpty(stack<T> *s) {
if(s->top == NULL)
  return 1;
return 0;
}

//push

template <typename T>
void push(stack<T> *s, T val) {

if(IsEmpty(s)) { //empty
  Node<T> *n;
  n=Create_Node(val);
  s->head = n;
  s->top = n;
}
else if (abs((s->top-s->head)/2)==MAX_Stack_size)
{
    printf("------------------------ Stack Overflow ------------------------\n");
}
else{
  Node<T> *n;
  n=Create_Node(val);
  s->top->next = n;
  s->top = n;
}
}


//pop
template <typename T>
int pop(stack<T> *s) {
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
    Node<T> *temp = s->head;
    while(temp->next != s->top) {
      temp = temp->next;
    }
    temp->next = NULL;
    delete s->top ;
    s->top = temp;
  }
  return tmp;
}
}



template <typename T>
void ReverseStack(stack<T> *s){
    stack <T> *r;
    init_stack(r);  
    while(s->head!=NULL){
        int tmpval=pop(s);
        push(r,tmpval);
    }
    *s=*r;
}


template <typename T>
void print_stack_val(stack<T> *s) {
    if(IsEmpty(s)){
        printf("Stack is Empty");
    }
    else{
    Node<T> *tmp=s->head;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->next;
        }
    }
    printf("\n");
}


bool checkin(string a,char b){
    for(int i=0;i<a.length();i++){
        if(a[i]==b){return 1;}     
    }
    return 0;
}


bool CheckValidity(string text){
    stack<char> *s;
    init_stack(s);

    for(int i=0;i<text.length();i++){
        if(checkin(openbrackets,text[i])){
            //cout<<"--"<<text[i]<<"--";
            push(s,text[i]);
        }

        if(checkin(closedbrackets,text[i])){
            char ch=pop(s);
            int xi;
            //cout<<"===>"<<ch<<"==== ";
            for(xi=0;xi<sizeof(closedbrackets);xi++){
                if(openbrackets[xi]==ch){
                    break;
                }
            }
            //cout<<closedbrackets[xi]<<" ---> "<<char(text[i])<<endl;

            if (text[i]!=closedbrackets[xi]){
                
                return 0;
            }
        }
    }
    if(!IsEmpty(s)){

        return 0;
    }
    

    return 1;



}

int main(){

    stack<int> *N;
    init_stack(N);

    Node<int> *a;
    a=Create_Node(1);

    push(N,1);






    return 0;
}