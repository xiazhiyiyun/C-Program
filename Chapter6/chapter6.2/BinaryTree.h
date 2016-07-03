template<typename elemType>
class BinaryTree {
    public:
        BinaryTree():_root( 0 ) {}

	BinaryTree( const BinaryTree &rhs ){
            copy( _root ,rhs._root);
	}

	~BinaryTree() { 
	    clear(); 
	}

	BinaryTree& operator=(const BinaryTree&);

	bool empty() {
	    return _root == 0; 
	}

	void clear();

    private:
        BTnode<elemType> *_root;

	void copy( BTnode<elemType> *tar,BTnode<elemType> *src );
};

template<typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=( const BinaryTree &rhs) {
    if( this != &rhs ){
        clear();
	copy( _root ,rhs._root );
    }
}

template<typename elemType>
inline void BinaryTree<elemType>::clear( ) {
    
}

