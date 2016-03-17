#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Die.h"
#include "LoadedDie.h"


using namespace std;


int main()		
	{
		srand (time(NULL));
		int a=0;
		
		cout<<"would you like to roll the dice N times? If so press 1. If not press 0 to continue to roll both dice one time \n";
		cin>>a;
		if (a == 1)
		{
			 
	int y,z =0;
		cout<<"how many times would you like to roll the dice \n";
		cin>>z;
		cout<<"rolling the Die "<< z <<" times"<<endl;
		cout<<"rolling the Loaded Die "<< z <<" times\n"<<endl;
	int array[6];
	
	for (int l = 0; l < 6; l++)
		{
			 array[l]=0;
		}
	
	for (int i = 0; i < z; i++)
		{
			int x=0;
		Die dice;
			dice.set_sides(6);
			x =dice.die_roll();
			
			

	if (x == 1)
		 	{
		 		array[0]= array[0] + 1;
		 	}
	else if(x == 2)
		 	{
		 		array[1]= array[1] + 1;
		 	}
	else if(x == 3)
		 	{
		 		array[2]= array[2] + 1;
		 	}
	else if(x == 4)
		 	{
		 		array[3]= array[3] + 1;
		 	}
	else if(x == 5)
		 	{
		 		array[4]= array[4] + 1;
		 	}
	else if(x == 6)
		 	{
		 		array[5]= array[5] + 1;
		 	}
	}	
 	
	for(int u=0; u<6; u++)
		 {
		 	cout<<"you rolled a "<<u+1<<" "<< array[u]<<" time/s\n";
		 }
 			cout<<endl;
 			int loaded_array[6];
	
	for (int l = 0; l < 6; l++)
		{
			 loaded_array[l]=0;
		}
			 
			 
		for (int i = 0; i < z; i++)
		{		int k=0;
				loaded_die dice2;
				dice2.set_sides(6);
				k= dice2.loaded_roll();


			if (k == 1)
		 	{
		 		loaded_array[0]= loaded_array[0] + 1;
		 	}
			else if(k == 2)
		 	{
		 		loaded_array[1]= loaded_array[1] + 1;
		 	}
			else if(k == 3)
		 	{
		 		loaded_array[2]= loaded_array[2] + 1;
		 	}
			else if(k == 4)
		 	{
		 		loaded_array[3]= loaded_array[3] + 1;
		 	}
			else if(k == 5)
		 	{
		 		loaded_array[4]= loaded_array[4] + 1;
		 	}
			else if(k == 6)
			{
		 		loaded_array[5]= loaded_array[5] + 1;
		 	}
		}

		for(int u=0; u<6; u++)
		 	{
		 		cout<<"you rolled a "<<u+1<<" "<< loaded_array[u]<<" time/s\n";
		 	}
	
		






		}
		
		else if(a==0)
		{
			
			Die dice;
				dice.set_sides(6);
				dice.die_roll();
				
					
		
			loaded_die dice2;
				dice2.set_sides(6);
				dice2.loaded_roll();
		}
		

}
		
