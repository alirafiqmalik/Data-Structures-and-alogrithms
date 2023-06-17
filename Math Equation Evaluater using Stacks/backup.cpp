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





template <typename A>
struct stack {
Node<A> *head;
Node<A> *top;
};



template <typename B>
Node <B> *Create_Node(B data) {
    Node<B> *x=new Node<B>;
    x->data = data;
    x->next = NULL;
    return x;
}

template <typename C>
void init_stack(stack<C> *s) {
    s->head = NULL;
    s->top = NULL;
    }


template <typename D>
int IsEmpty(stack<D> *s) {
if(s->top == NULL)
  return 1;
return 0;
}

//push

template <typename E>
void push(stack<E> *s, E val) {

if(IsEmpty(s)) { //empty
  Node<E> *n;
  n=Create_Node(val);
  s->head = n;
  s->top = n;
}
else if (abs((s->top-s->head)/2)==MAX_Stack_size)
{
    printf("------------------------ Stack Overflow ------------------------\n");
}
else{
  Node<E> *n;
  n=Create_Node(val);
  s->top->next = n;
  s->top = n;
}
}


//pop
template <typename F>
F pop(stack<F> *s) {
if(IsEmpty(s)) {
  printf("------------------------ Stack Underflow ------------------------\n");
  
  return NULL;
}
else {
  F tmp = s->top->data;
  if(s->top == s->head) {
    delete s->top;
    s->top = NULL;
    s->head = NULL;
  }
  else {
    Node<F> *temp = s->head;
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



template <typename G>
void ReverseStack(stack<G> *s){
    stack <G> *r;
    init_stack(r);  
    while(s->head!=NULL){
        int tmpval=pop(s);
        push(r,tmpval);
    }
    *s=*r;
}


template <typename H>
void print_stack_val(stack<H> *s) {
    if(IsEmpty(s)){
        printf("Stack is Empty");
    }
    else{
    Node<H> *tmp=s->head;
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


int main()
{
    system("CLS");

    

    string text;
    cout<<"Enter Equation: ";
    cin>>text;

/*
    int validityCheck;
   
    validityCheck=CheckValidity(text);
    //cout<<validityCheck<<endl;
    if(!validityCheck){
    cout<<"ERROR INVALID STATEMENT";
    }

*/
    
    cout<<"HERE1"<<endl;
    //stack<int> *N;
    //init_stack(N);
    stack<int> *s2;
    init_stack(s2);  
    push(s2,7);
    //pop(s2);
    


    cout<<"HERE2\n";

    string tmpstr="";
    for(int i=0;i<text.length();i++){
        if(checkin(digits,text[i])){
            tmpstr=text[i];
            for (int j = i+1; j < text.length(); j++)
            {
                if(!checkin(digits,text[j])){i=j;break;}
                else{}//tmpstr+=text[j];}
            }
            //push(s2,tmpstr); 
            cout<<tmpstr<<endl;    
        }
    }

    //print_stack_val(s1);

    //cout<<"-----------"<<endl;
    //print_stack_val(s2);

 



//{[(12+3)-2]*((2*3)+9)/2}
//{[(12+3)]}

    return 0;
}

//closedbrackets+openbrackets






/*


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


*/