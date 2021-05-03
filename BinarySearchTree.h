#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
#include "BinaryTree.h"
using namespace std;

template <class T>
class BST:public BinaryTree<T>{
	public:
		node<T>* search(T &);
		void insert(T&);
		void deleteNode(T&);
	private:
		void deletefromTree(node<T> *&);
};
template <class T>
node<T>* BST<T>::search(T &item){
	node<T> *p;
	bool found=false;
	if(BinaryTree<T>::root==NULL)
		cerr<<"No tree";
	else{
		p=BinaryTree<T>::root;
		while(!found && p!=NULL){
			if(p->info==item)
				found=true;
			else if(item < p->info)
				p=p->llink;
			else
				p=p->rlink;
		}
	}
	return p;
}
template <class T>
void BST<T>::insert(T &item){
	node<T> *p,*q,*r; 
	r=new node<T>;
	r->info=item;
	r->llink=r->rlink=NULL; 
	if(BinaryTree<T>::root==NULL){
		BinaryTree<T>::root=r; 
	}
	else{ 
		p=BinaryTree<T>::root;
		while(p!=NULL){
			q=p;
			if(item<p->info)
				p=p->llink;
			else
				p=p->rlink;
		}
		if(item<q->info)
			q->llink=r;
		else
			q->rlink=r;
	}
}
#endif
