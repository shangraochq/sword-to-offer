template <class T> class BSTNode{
	public:
		T key;
		Node * left;
		Node * right;
		Node * parent;
		Node(T value, Node * p, Node * l, Node * r);
}

template <class T> class BSTree{
	private:
		Node<T> *mRoot;

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

//调下顺序即可
template <class T> void BSTree <T> :: inOrder(BSTNode<T>* tree){
	if (tree != NULL)
	{
		cout<<tree->key<<"  ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
template <class T> void BSTree <T> :: postOrder(BSTNode<T>* tree){
	if (tree != NULL)
	{
		cout<<tree->key<<"  ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
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