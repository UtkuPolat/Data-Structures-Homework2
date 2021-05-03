#include <iostream>
#include <fstream>												/*Made by Utku POLAT-160302001*/
#include <queue>
#include <assert.h>
#include "QueueHeader.h"

using namespace std;

class Purchase{
	public:
		string place;
		int amount;
		int instalment;
		int numInst;						/*number of paid instalments*/
		
		friend istream& operator>>(istream &is, Purchase &item){
			is>>item.place>>item.amount>>item.instalment;
			return is;
		}
		friend ostream&operator<<(ostream &os,Purchase &item){
			if(item.instalment!=0){
				os<<item.place<<"			"<<(item.amount/(item.instalment))<<"		"<<item.numInst<<"/"<<item.instalment<<"("<<item.amount<<" TL)"<<endl;
				return os;
			}	
			else{
				os<<item.place<<"			"<<item.amount<<endl;
				return os;
			}
		}
};
main(){
	Queue<Purchase> first,second;			/*fist and second month*/
	Purchase credit;						/*for read textfile*/
	credit.numInst=0;						
	ifstream list("Purchases.txt");
	list>>credit;
	while(!list.eof()){
		if(credit.instalment!=0){
			credit.numInst=1;
			first.insert(credit);
			credit.numInst+=1;
			second.insert(credit);
		}
		else{
			credit.numInst=0;
			first.insert(credit);
		}
		list>>credit;
	}

	string choose;										/*user's choice for first or second month*/
	
	do{
		cout<<"Enter Current,Next or Quit:";
		cin>>choose;										
		if(choose=="Current" || choose=="current"){
			cout<<"Summary Report for this month:"<<endl;
			cout<<"Place of Purchase"<<"	"<<"Amaount"<<"		"<<"Instalment"<<endl;
			Purchase temp;								/*read queues for output*/
			int total=0;								/*total paid money for first month*/
			while(!first.isEmpty()){
				temp=first.deleteQ();
				if(temp.instalment>0){
					total=total+(temp.amount/temp.instalment);
				}
				else{
					total=total+temp.amount;
				}
	
				cout<<temp;
			}
			cout<<"Total Amaount:"<<total<<endl;
	    }
	    
	    if(choose=="Next" || choose=="next"){
	    	cout<<"Summary Report for next month:"<<endl;
	    	cout<<"Place of Purchase"<<"	"<<"Amaount"<<"		"<<"Instalment"<<endl;
	    	Purchase temp1;								/*read queues for output*/
	    	int total1=0;								/*total paid money for second month*/
			while(!second.isEmpty()){
				temp1=second.deleteQ();
				total1=total1+(temp1.amount/temp1.instalment);
				cout<<temp1;
			}
			cout<<"Total Amaount:"<<total1<<endl;
		}
	}while(choose!="Quit" && choose!="quit");
	return 0;
}
