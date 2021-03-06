//#include "BTnode.h"
#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    BinaryTree<string> bt;

    bt.insert("Piglet");
    bt.insert("Eeyore");
    bt.insert("Roo");
    bt.insert("Tigger");
    bt.insert("Chris");
    bt.insert("Pooh");
    bt.insert("Kanga");

    cout << "Preorder Traversal: \n";
    bt.preorder();

    bt.remove("Piglet");
    cout << "\n\nPreorder Traversal after Piglet removal: \n";
    bt.preorder();

    bt.remove("Eeyore");
    cout << "\n\nPreorder Traversal after Eeyore removal: \n";
    bt.preorder();
    cout << endl;

    return 0;
}
