#include<iostream>
using namespace std;


struct Node{
    int data;
    Node* right;
    Node* left;
    
    Node(int val) {
      data = val;
      left = NULL;
      right = NULL;

    }
};

void addright(Node *x,int val){
  x->right=new Node(val);
}

void addleft(Node *x,int val){
  x->left=new Node(val);
}



/*
Inorder (Left, Root, Right)  :  
Preorder (Root, Left, Right) :
Postorder (Left, Right, Root):
*/

void inorder(Node* ptr){
  if(ptr==NULL){
    return;
  }
  else{
    inorder(ptr->left);
    cout<<ptr->data<<"  ";
    inorder(ptr->right);
  }
}


Node* search(Node* ptr,int data){
  if(ptr->data==data){
    return;
  }
  else if(ptr->data<=data){
    return search(ptr->left,data);
  }
  else if(ptr->data>data){
    return search(ptr->right,data);
  }
  return NULL;
}


void postorder(Node* ptr){
  if(ptr==NULL){
    return;
  }
  else{
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->data<<endl;
  }
}



void preorder(Node* ptr){
  if(ptr==NULL){
    return;
  }
  else{
    cout<<ptr->data<<endl;
    preorder(ptr->left);
    preorder(ptr->right);
  }
}




Node* insert(Node *head,int value){
    if(head==NULL){
      Node* tmp=new Node(value);
      return tmp;
    }
    else if(value>head->data){
        head->right=insert(head->right,value);
    }
    else if(value<head->data){
      head->left=insert(head->left,value);
    }
    return head;
}
Node* find_parent(Node * child){
  
  
}

Node* delete_node(Node *ptr,int data){
  if(search(ptr,data)){
    return ptr;
  }
}


int main(){

//time_t

int values[]={4,2,5,3};

Node *head=new Node(1);
for(int i=0;i<sizeof(values)/sizeof(int);i++){
    head=insert(head,values[i]);
    //cout<<values[i];
}
cout<<"IN"<<endl;
inorder(head);
cout<<search(head,4);



return 1;
}



/*
cout<<"POST"<<endl;
postorder(head);
cout<<"PRE"<<endl;
preorder(head);
*/
/*
DIP
CV
->Rob1
non linear cntrol

*/