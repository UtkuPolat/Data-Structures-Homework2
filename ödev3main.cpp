#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include "header.h"
using namespace std;

class Word{
	public:
		string threechar;
		LL<string> list;
		bool operator==(Word &item){
			return threechar==item.threechar;
		}
		bool operator<(Word &item){
			return threechar<item.threechar;
		}
};
string lower(string s)
{
	for(int i=0;i<s.length();i++)
	{
		s[i]=tolower(s[i]);
	}
	return s;
}
main(){
	BST<Word> tree;
	Word tmp;
	node<Word> *p;
	string expr,threeDigit,wrd,threechr;

	ifstream inp("BinarySearch.txt");
	inp>>expr;
	threeDigit=expr.substr(0,3);
	tmp.threechar=threeDigit;
	tree.insert(tmp);
	p=tree.search(tmp);
	if(p->info.list.search(expr)==NULL){
		p=tree.search(tmp);
		p->info.list.insertLast(expr);
	}
		
	while (!inp.eof())
	{
		inp>>expr;
		threeDigit=expr.substr(0,3);
		tmp.threechar=threeDigit;
		p=tree.search(tmp);
		if(p==NULL){
			tree.insert(tmp);
	    	p=tree.search(tmp);
			if(p->info.list.search(expr)==NULL)
				p->info.list.insertLast(expr);
		}
		else{ 
			if(p->info.list.search(expr)==NULL)
				p->info.list.insertLast(expr);
		}
		
	}
	cout<<"!...Please Input 'Quit or quit' for Finish to Search...!"<<endl;
	cout<<"Enter a word:";
	cin>>wrd;
	wrd=lower(wrd);
	do{
		threechr=wrd.substr(0,3);
		tmp.threechar=threechr;
		p=tree.search(tmp);
		if(p!=NULL){
			if(p->info.list.search(wrd))
				cout<<wrd;
			else{
				cout<<"Did you mean ";
				cout<<p->info.list;
			}
				
		}
		else{
			for(int i=0;i<wrd.length();++i){

			}
		}
		cout<<endl;
		cout<<"Enter a word:";
		cin>>wrd;
		wrd=lower(wrd);
	}while(wrd!="Quit" && wrd!="quit");
	
	return 0;
}
