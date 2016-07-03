template <typename valType>
class BinaryTree;

template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;

    public:
        BTnode( const valTyped &val): _val(val){
	    _cnt = 1;
	    _lchild = 0;
	    _rchild = 0;
	}
        
    private:
        vlaType _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;
}
