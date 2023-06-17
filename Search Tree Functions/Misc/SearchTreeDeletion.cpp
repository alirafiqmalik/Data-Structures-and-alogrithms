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
      cout<<ptr->data<<" ";
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
  
  
Node* insert(struct Node* root, int val)
{
    if(root == NULL)
    {
        struct Node* temp = new Node(val);
        return (temp);
    }
    else if(root->data <= val)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        root->left = insert(root->left, val);
    }
    return root;
}
  
  /* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->right != NULL)
        current = current->right;
 
    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left==NULL && root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            delete(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct Node* temp = minValueNode(root->left);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}
  
int main() {
	//root Node
	
	//struct Node* root = new Node(1);
	//root->left = new Node(2);
	//root->right = new Node(3);
	
	//cout<<"root node: "<<root->data<<endl;
	//cout<<"left node: "<<root->left->data<<endl;
	//cout<<"right node: "<<root->right->data<<endl;
	//addleft(root->left , 4);
	//cout<<"left left node: "<<root->left->left->data<<endl;
	//addright(root->left , 5);
	//cout<<"left right node: "<<root->left->right->data<<endl;
	
	struct Node* root = insert(root,7);
	
	root = insert(root,8);
	root = insert(root,3);
	root = insert(root,9);
	root = insert(root,2);
	root = insert(root,6);
	root = insert(root,27);
	root = insert(root,5);
	root = insert(root,1);
	root = insert(root,19);
	
	inorder(root);
	
	root = deleteNode(root, 3);
	
		inorder(root);
//	preorder(root);
//	postorder(root);
	return 0;
}
