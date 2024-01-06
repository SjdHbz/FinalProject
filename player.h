#ifndef PLAYER_H
#define PLAYER_H
#include "worker.h"
#include<iostream>

class player{
	private:
		int workerNum,coin,time,greenLand;
	public:
	    player();	
	    int newWorker();
	    int getWorkerNum();
	    void coinChange(int);
	    int newGreenLand();
};

int player::newGreenLand(){      //1 means new green land is added
	if(coin>=3){                 //-1 means there is no enough coin to add worker
		greenLand++;
		coin-=3;
		return 1;
	}
	else{
		return -1;
	}
}

void player::coinChange(int a){
	coin+=a;
}

int player::getWorkerNum(){
	return workerNum;
}

int player::newWorker(){      //1 means new worker is added 
	if(coin>=5){              //-1 means there is no enough coin to add worker
		workerNum++;
		coin-=5;
		return 1;
	}
	else{
		return -1;
	}
	
}

player::player(){
	workerNum=1;
	coin=10;
	greenLand=1;
	time=180;
}




#endif