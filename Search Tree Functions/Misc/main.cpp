
#include <stdio.h>
#include <iostream>
using namespace std;


/*
IsEmpty: determine whether or not the list is empty
InsertNode: insert a new node at a particular position
FindNode: find a node with a given value
DeleteNode: delete a node with a given value
DisplayList: 
*/



    struct Node{
        int data;
        Node *next;
    };



    bool IsEmpty(Node *head){   
        if((head->next==NULL)&&(head->data==0)){
            return 1;
        }
        return 0;   
    }



    void InsertNode(Node *curr,Node *ptr,Node *prev){
        prev->next=ptr;
        ptr->next=curr;
    }

    void InsertNode(Node *head,Node *ptr,int pos){

        int count=0;

        for(Node *i=head;i!=NULL;i=i->next){
            cout<<i->data<<endl;
        }

    }


    void displayList(Node *head){
        cout<<"Printing List Values"<<endl;
        for(Node *i=head;i!=NULL;i=i->next){
            cout<<i->data<<endl;
        }
    }



int main()
{
    Node *ptr = new Node;
    ptr->data = 0;
    ptr->next = NULL;

    Node *tmp = new Node;
    tmp->data = 0;
    tmp->next = NULL;
    ptr->next=tmp;

    //InsertNode(ptr,tmp,0);

    displayList(ptr);

     

return 0;

}





/*

    Node *ptr = new Node;
	

    ptr->data = 1;
    ptr->next = NULL;


    
    Node *head = ptr;
    Node *last = ptr;
    
    for(int i = 2; i<11; i++)
    {
       Node *temp = new Node;
       temp->data = i;
       temp->next = NULL;
       last->next = temp;
       last = temp;
        
    }
    
    
    
    Node *temp = new Node;
    temp->data = 5;
    temp->next = NULL;
    
    Node *prev = head;
    Node *curr = head->next;
    
    while(curr->data < temp->data)
    {
        prev = prev->next;
        curr = curr->next;
    }
    
    temp->next = curr;
    prev->next = temp;
    
    
    
    temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    

*/