#ifndef QUEUEHEADER_H
#define QUEUEHEADER_H
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
class Queue{
	int front,rear;
	int count,max;
	T *lst;
	public:
		Queue(int s=100);
		~Queue(){delete []lst;}
		bool isEmpty(){return count==0;}
		bool isFull(){return count==max;}
		int getCount(){return count;}
		void destroyQ();
		T frontQ(){
			assert(!isEmpty());
			return lst[front];
		}
		T rearQ(){
			assert(!isEmpty());
			return lst[rear];
		}
		void insert(T &);
		T deleteQ();
};
template <class T>
Queue<T>::Queue(int size){
	lst=new T[size];
	max=size;
	count=0;
	front=0;
	rear=max-1;
}
template <class T>
T Queue<T>::deleteQ(){
	assert(!isEmpty());
	T x;
	x=lst[front];
	front=(front+1)%max;
	count--;
	return x;
}
template <class T>
void Queue<T>::insert(T &item){
	if(!isFull()){
		rear=(rear+1)%max;
		lst[rear]=item;
		count++;
	}
	else
		cerr<<"No Space In Queue";
}
template <class T>
void Queue<T>::destroyQ(){
	front=count=0;
	rear=max-1;
}

#endif
