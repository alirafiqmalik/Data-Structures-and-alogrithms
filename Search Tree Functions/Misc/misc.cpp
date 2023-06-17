
template <typename T>
class BST
	{
	public:
		// Constructor, destructor
		BST(T headval){
            //this->root=new Node(headval);
            
            //this->root=head;
        }
		~BST(){
            //delete head;
        };
    
		// Public interface
		bool isEmpty();
		bool find(const T & x);
		const T & findMin();
		const T & findMax();
		void insert(const T & x);
		void remove(const T & x);
		void makeEmpty();
		void printTree();
    private:
		    
		// Root node (Private)
		Node<T> *root;
		int numNodes;
	
		// Utility methods (Private)
		Node<T> * findNode(Node<T> * node, const T & x);
		Node<T> * findMinNode(Node<T> * node);
		Node<T> * findMaxNode(Node<T> * node);
		Node<T> * findSuccessor(Node<T> * node);
		Node<T> * findParentOf(const T & x);
		Node<T> * insertNode(Node<T> * node, const T & x);
		void removeAllNodes(Node<T> * node);
		void printNodesInOrder(Node<T> * node);
	};
