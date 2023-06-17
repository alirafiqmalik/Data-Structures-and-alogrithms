#include <iostream>
using namespace std;


struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int val)
  {
      data = val;
      left = NULL;
      right = NULL;
  }
  
};
 void addleft(Node *ptr , int a){
      ptr->left=new Node(a);
      
  }
  void addright(Node *ptr , int a){
      ptr->right=new Node(a);
      
  }
  
  void inorder (Node* ptr){
      if (ptr == NULL)
        { return; }
      else{
      inorder(ptr->left);
      cout<<ptr->data<<endl;
      inorder(ptr->right);}
  }
  void preorder (Node* ptr)
  {
      if (ptr == NULL)
      {
          return;
      }
      else
      {
          cout <<ptr->data<<endl;
          preorder(ptr->left);
          preorder(ptr->right);
      }
  }
  
  void postorder (Node* ptr)
  {
      if (ptr == NULL)
      {
          return;
      }
      else
      {
          postorder(ptr->left);
          postorder(ptr->right);
          cout <<ptr->data<<endl;
      }
  }
int main() {
	//root Node
	
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	
	//cout<<"root node: "<<root->data<<endl;
	//cout<<"left node: "<<root->left->data<<endl;
	//cout<<"right node: "<<root->right->data<<endl;
	addleft(root->left , 4);
	//cout<<"left left node: "<<root->left->left->data<<endl;
	addright(root->left , 5);
	//cout<<"left right node: "<<root->left->right->data<<endl;
	inorder(root);
	preorder(root);
	postorder(root);
	return 0;
}