#ifndef ANIMALS_H
#define ANIMALS_H

class animal{              //animal the parent class
	private:
		int price,time,meatPrice;
	public:
        //animal();
		void setPrice(int);
		void setTime(int);
		void setMeatPrice(int);
        int GetPrice();
        int GetTime();
        int GetMeatPrice();
};

void animal::setTime(int t){
	time=t;
}

void animal::setPrice(int p){
	price=p;
}

void animal::setMeatPrice(int m){
	meatPrice=m;
}

int animal::GetTime(){
	return time;
}

int animal::GetPrice(){
	return price;
}

int animal::GetMeatPrice(){
	return meatPrice;
}                                //animal the parent class


class chicken: public animal{      //chicken class
	private:
		int eggPrice;
	public:
		chicken();
	    int getEggPrice();
		int getPrice();
		int getTime();
		int getMeatPrice();	
};

int chicken::getTime(){
    return GetTime();
}

int chicken::getPrice(){
    return GetPrice();
}

int chicken::getMeatPrice(){
    return GetMeatPrice();
}

chicken::chicken(){
	eggPrice=3;
	setPrice(3);
	setTime(20);
	setMeatPrice(2);
}

int chicken::getEggPrice(){
	return eggPrice;
}                                     //chicken class

class sheap: public animal{           //sheap class
	private:
		const int milkPrice=3;
	public:
		sheap();
		int getMeatPrice();
		int getTime();
		int getPrice();
	    int getMilkPrice();	
};

int sheap::getPrice(){
    return GetPrice();
}

int sheap::getTime(){
    return GetTime();
}

sheap::sheap(){
	setPrice(5);
	setMeatPrice(4);
	setTime(15);
}

int sheap::getMeatPrice(){
    return GetMeatPrice();
}

int sheap::getMilkPrice(){
	return milkPrice;
}
                                     //sheap class
                                     
                                     
class cow:public animal{             //cow class
	private:
		const int milkPrice=5;
	public:
		cow();
	    int getMeatPrice();
		int getTime();
		int getPrice();
	    int getMilkPrice();	
};      

int cow::getPrice(){
    return GetPrice();
}

int cow::getTime(){
    return GetTime();
}


int cow::getMeatPrice(){
    return GetMeatPrice();
}

int cow::getMilkPrice(){
	return milkPrice;
}

cow::cow(){
	setPrice(7);
	setMeatPrice(5);
	setTime(20);
}                               
                                //cow class     
#endif
