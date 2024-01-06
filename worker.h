#ifndef WORKER_H
#define WORKER_H

#include<iostream>
using namespace std;

class worker{
	private:
		const int price=5;
		string check;
	public:
	    worker();
	    int getPrice();
		void swCheck();
		string getCheck();	
};

int worker::getPrice(){
	return price;
}

string worker::getCheck(){
	return check;
}

void worker::swCheck(){
	if(check=="free"){
		check="busy";
	}
	else{
		check="free";
	}
}

worker::worker(){
	check="free";
}



#endif