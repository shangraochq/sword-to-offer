template <class T> class BSTNode{
	public:
		T key;
		BSTNode * left;
		BSTNode * right;
		BSTNode * parent;
		BSTNode(T value, BSTNode * p, BSTNode * l, BSTNode * r);
}

template <class T> class BSTree{
	private:
		BSTNode<T> *mRoot;

	public:
		BSTree();
		~BSTree();


		// 前序遍历"二叉树"
        void preOrder(BSTNode<T>* tree);
        // 中序遍历"二叉树"
        void inOrder(BSTNode<T>* tree);
        // 后序遍历"二叉树"
        void postOrder(BSTNode<T>* tree);

        // (递归实现)查找"二叉树x"中键值为key的节点
        BSTNode<T>* search(BSTNode<T>* x, T key);
        // (非递归实现)查找"二叉树x"中键值为key的节点
        BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key);

        // 查找最小结点：返回tree为根结点的二叉树的最小结点。
        BSTNode<T>* minimum(BSTNode<T>* tree);
        // 查找最大结点：返回tree为根结点的二叉树的最大结点。
        BSTNode<T>* maximum(BSTNode<T>* tree);

        // 将结点(z)插入到二叉树(tree)中
        void insert(BSTNode<T>* &tree, BSTNode<T>* z);

        // 删除二叉树(tree)中的结点(z)，并返回被删除的结点
        BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);

        // 销毁二叉树
        void destroy(BSTNode<T>* &tree);

        // 打印二叉树
        void print(BSTNode<T>* tree, T key, int direction);
}

template <class T> void BSTree <T> :: preOrder(BSTNode<T>* tree){
	if (tree != NULL)
	{
		cout<<tree->key<<"  ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

//循环实现
template <class T> void BSTree <T>:: preOrder(BSTNode<T>* tree){
	stack <BSTNode<T> *> st;
	BSTNode * currentNode = tree;

	while(!st.empty() || currentNode != NULL){
		while(p != NULL){
			cout<< currentNode->value<< " ";
			st.push(currentNode);
			currentNode = currentNode->left
		}
		if (!st.empty())	
		{
			currentNode = st.top();
			st.pop();
			currentNode = currentNode->right;
		}
	}	
}


template <class T> void BSTree <T> :: inOrder(BSTNode<T>* tree){
	if (tree != NULL)
	{
		preOrder(tree->left);
		cout<<tree->key<<"  ";
		preOrder(tree->right);
	}
}

//循环实现
template <class T> void BSTree <T>:: inOrder(BSTNode<T>* tree){
	stack <BSTNode<T> *> st;
	BSTNode * currentNode = tree;

	while(!st.empty() || currentNode != NULL){
		while(p != NULL){
			st.push(currentNode);
			currentNode = currentNode->left;
		}
		if (!st.empty())	
		{
			currentNode = st.top();
			cout<<currentNode->value<<" ";
			st.pop();
			currentNode = currentNode->right;
		}
	}	
}

template <class T> void BSTree <T> :: postOrder(BSTNode<T>* tree){
	if (tree != NULL)
	{
		preOrder(tree->left);
		preOrder(tree->right);
		cout<<tree->key<<"  ";
	}
}

//循环实现
template <class T> void BSTree <T>:: postOrder(BSTNode<T>* tree){
	//答案看不懂,答案在算法学习文件夹里	
}

template <class T> BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key){
	if (x == NULL || x->key == key)		
	{
		return x;
	}

	if (key < x->key)
	{
		return search(x->left, key);
	}
	else {
		return search(x->right, key);
	}

}
template <class T> BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T>* x, T key)
{
    while ((x!=NULL) && (x->key!=key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}


template <class T> BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T> BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->left;
    return tree;
}


template <class T> BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *pNode){
	if (pNode == NULL)
	{
		return NULL;
	}
	if (pNode->left != NULL)	
	{
		return maximum(pNode->left);
	}
	BSTNode<T> * parentNode = pNode->parent;
	if (parentNode->right == pNode)
	{
		return parentNode;
	}
	while(){
		parentNode = parentNode->parent;
		if (parentNode->key < pNode.key)
		{
			return parentNode;
		}
	}
}


template <class T> void BSTree<T>::insert(BSTNode<T>* tree, BSTNode<T>* insertNode){
	if (tree == NULL)
	{
		tree = insertNode;//tree为根节点
		return;
	}
	BSTNode<T> * currentNode = tree;
	while(true){
		if (insertNode->key < currentNode->key)
		{
			if (currentNode->left == NULL)
			{
				insertNode->parent = currentNode;
				currentNode->left = insertNode;
				return;
			}
			currentNode = currentNode->left;
		}
		else {
			if (currentNode->right == NULL)
			{
				insertNode->parent = currentNode;
				currentNode->right = insertNode;
				return;
			}
			currentNode = currentNode->right;
		}
			
	}
}

template <class T> void BSTree<T>::insert(T key){
	BSTNode <T> * z = NULL;
	z = new BSTNode<T>(key, NULL, NULL, NULL);
	insert(mRoot, z);
}


//面试题23 从上往下打印二叉树，即宽度优先遍历
void printFromTopToBottom(Node * pRoot){
	if (pRoot == NULL)
	{
		return;
	}
	std::deque<Node*> dequeNodes;
	dequeNodes.push_back(pRoot);
	while(dequeNodes.size()){
		Node * currentNode = dequeNodes.front();
		dequeNodes.pop_front();
		cout<<currentNode->value>>" ";
		if (currentNode->left != NULL)
		{	
			dequeNodes.push_back(dequeNodes->left);
		}
		if (currentNode->right != NULL)
		{
			dequeNodes.push_back(dequeNodes->right);
		}
	}
}
