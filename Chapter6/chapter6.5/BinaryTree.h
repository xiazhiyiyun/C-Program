#include <iostream>
#include <fstream>
#include "BTnode.h"

using namespace std;

template<typename valType>
class BTnode;


//template<typename elemType>
//ostream& operator<< (ostream&,const BinaryTree<elemType> &) ;

template<typename elemType>
class BinaryTree {

  //  friend class BTnode<elemType>;
      template<typename valType>
      friend ostream& operator<< ( ostream &,const BinaryTree<valType> & );

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

	void clear(){
	    if( _root ){
	        clear( _root );
		_root = 0;
	    }
	}


	void insert( const elemType &elem);
	void remove( const elemType &elem);
	void remove_root();
//	void preorder( BTnode<elemType> *, const ostream &os = cout ) const;
	void preorder(ostream &os = cout ) const;

    private:
        BTnode<elemType> *_root;

	void print(ostream &os) const{
	    preorder(os);
	}
	void clear( BTnode<elemType>*);
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
inline void BinaryTree<elemType>::insert( const elemType &elem ) {
    if( !_root ){
        _root = new BTnode<elemType>( elem );
    }
    else 
        _root->insert_value( elem );
}

template<typename elemType>
inline void BinaryTree<elemType>::remove( const elemType &elem ) {
    
    if(_root){
        if( _root->_val  == elem )
	    remove_root();
	else
	    _root->remove_value( elem,_root );
    }
}

template<typename elemType>
inline void BinaryTree<elemType>::remove_root() {
    
    if(!_root) 
        return;
    
    BTnode<elemType> *tmp = _root;

    if( _root->_rchild ) {

        _root = _root->_rchild;

	BTnode<elemType> *lc = tmp->_lchild;
	BTnode<elemType> *newlc = _root->_lchild;

	if( !newlc )
	    newlc = lc;
	else
	    BTnode<elemType>::lchild_leaf(lc,newlc);
    }
    else
        _root = _root->_lchild;

    delete tmp;
}


template<typename elemType>
void BinaryTree<elemType>::clear( BTnode<elemType>* pt){
    if(pt) {
        clear( pt->_lchild);
        clear( pt->_rchild);
	delete pt;
    } 
}
/*
template<typename elemType>
void BinaryTree<elemType>::preorder( BTnode<elemType> *pt, const ostream &os ) const{
    
    if(pt) {
        display_val(pt,os);
	if(pt -> _lchild)
	    preorder( pt -> _lchild, os );
	if(pt -> _rchild)
	    preorder( pt -> _rchild, os );
    }
}
*/
template<typename elemType>
void BinaryTree<elemType>::preorder(ostream &os ) const{
    _root->preorder(_root,os);    
}
