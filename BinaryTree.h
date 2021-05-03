#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;
template <class T>
struct node{
    T info;
    node <T> *llink,*rlink;
};

template <class T>
class BinaryTree{
    protected:
        node<T> *root;
    private:
        void destroy(node<T> *&);
        void inordert(node<T> *);
        void preordert(node<T> *);
        void postordert(node<T> *);
        int height(node<T> *);
        int max(int , int);
        int nodecount(node<T> *);
        int leafcount(node<T> *);
    public:
        BinaryTree(){root=NULL;}
        ~BinaryTree(){destroy(root);}
        bool isEmpty(){return root=NULL;}
        void inorder(){inordert(root);}
        void preorder(){preodert(root);}
        void postorder(){postordert(root);}
        int treeHeight(){return height(root);}
        int countnodes(){return nodecount(root);}
        int countleaf(){return leafcount(root);}
};
	template <class T>
	void BinaryTree<T>::inordert(node<T> *p){
		if(p!=NULL){
    		inordert(p->llink);
    		cout<<p->info;
    		inordert(p->rlink);
		}
	}
	template <class T>
	void BinaryTree<T>::preordert(node<T> *p) {
    	if(p!=NULL){
       	 	cout<<p->info;
       	 	preordert(p->llink);
       		preordert(p->rlink);
		}
	}
	template <class T>
	void BinaryTree<T>::postordert(node<T> *p){
   		if(p!=NULL){
        	postordert(p->llink);
        	postordert(p->rlink);
        	cout<<p->info;
		}
	}   
	template <class T>
	int BinaryTree<T>::nodecount(node<T> *p){
    	if(p!=NULL)
        	return 0;
		else
        	return 1+nodecount(p->llink)+nodecount(p->rlink);
	}
	template <class T>
	int BinaryTree<T>::leafcount(node<T> *p){
    	if(p==NULL)
   	 		return 0;
    	else if((p->llink==NULL)&&(p->rlink==NULL))
    		return 1;
    	else 
			return leafcount(p->link)+leafcount(p->rlink);
	}                      
	template <class T>
	int BinaryTree<T>::max(int x,int y) {
    	if(x>=y) 
			return x;
    	else 
			return y;
	}
	template <class T>
	int BinaryTree<T>::height(node<T> *p){
    	if(p==NULL)
       		return 0;
    	else 
        	return 1+max(treeHeight(p->llink)) , treeHeight(p->rlink);
	}
	template <class T>
	void BinaryTree<T>::destroy(node<T> *&p){
		if(p!=NULL){
    		destroy(p->llink);
    		destroy(p->rlink);
    		delete p;
    		p=NULL;
		}
	}
#endif
