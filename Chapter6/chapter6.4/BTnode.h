#include <iostream>
#include <fstream>

using namespace std;

template <typename valType>
class BinaryTree;

template <typename valType>
class BTnode{
    friend class BinaryTree<valType>;

    public:
        BTnode( const valType &val): _val(val){
	    _cnt = 1;
	    _lchild = 0;
	    _rchild = 0;
	}

        void insert_value( const valType&);
	void remove_value( const valType&,BTnode*&);
	void display_val(const BTnode *,ostream &os = cout) const;
        void preorder(BTnode *,ostream &os = cout ) const;
        static void lchild_leaf( BTnode*,BTnode* );

       
    private:
        valType _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;

};

template<typename valType>
void BTnode<valType>::insert_value( const valType &val ){
    if ( _val == val ){
        _cnt++;
	return;
    }

    if( val < _val ){
        if( !_lchild )
	    _lchild = new BTnode( val );
	else
	    _lchild->insert_value(val);
    }
    else{
        if( !_rchild )
	    _rchild = new BTnode( val );
	else
	    _rchild->insert_value(val);
    
    }
}

template<typename valType>
void BTnode<valType>::lchild_leaf( BTnode *leaf,BTnode *subtree ){
    
    while(subtree->_lchild)
        subtree = subtree->_lchild;
    subtree->_lchild = leaf;
}
template<typename valType>
void BTnode<valType>::remove_value( const valType &val,BTnode *& prev){
    
    if(val < _val){
        if(!prev->_lchild)
	    return;
	remove_value(val,prev->_lchild);
    }

    else if(val > _val){
        if(!prev->_rchild)
	    return;
	remove_value(val,prev->_rchild);
    }
    else{
        if(_rchild){
	    prev = _rchild;
	    if(_lchild){
	        if( !prev->_lchild ) 
		    prev->_lchild = _lchild;
		else
		   BTnode<valType>::lchild_leaf( _lchild, prev->_lchild );
	    }
	}
	else{
	    prev = _lchild;
	}
	delete this;
    }
}

template<typename valType>
void BTnode<valType>::display_val(const BTnode *pt,ostream &os) const{
    os << pt->_val << " ";
}

template<typename valType>
void BTnode<valType>::preorder(BTnode *pt,ostream &os ) const{
    
    if(pt) {
        display_val(pt,os);
	if(pt -> _lchild)
	    preorder( pt -> _lchild, os );
	if(pt -> _rchild)
	    preorder( pt -> _rchild, os );
    }
}
