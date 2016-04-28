#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class calc
{
	/* lo = Left operand, ro = right operand, op = operator 
	   ans = Correct answer, score = Score alloted for each correct answer, max_time = maximum time allowed for each level */
	int lo, ro, op, ans, flag=1, score = 0, max_time;       
	public:
		void play();   
		int eval(int, int);     // Evaluates if the answer is correct or not
		int getscore()  {return score;}    // returns score
		calc(int o)	{op = o;}    // assigns operator
};

class player
{
	char *name;
	int highscore;
	public:
		void dispData();
		void updateScore();      
		player(char *cha)
		{
			name = cha;
		}
};

int menu()
{
	int choice;
   	while (choice < 1 || choice > 5)
   	{
   	  	cout << "\t\t\t\t\t\tWelcome to MathRush!!\n\nMenu :\n1. Addition\n2. Substraction\n3. Multiplication\n4. Divide\n5. Exit\n\tChoice : ";
   	  	cin >> choice;
   	  	if (choice == 5)
   	  		exit(0);
   	}
   	return choice;
}

int main()
{
	srand(time(NULL));
	int choice; char ch='y';
	while (ch == 'y' || ch == 'Y'){
		system("cls");
	    choice = menu();
	    calc obj = calc(choice);
	    obj.play();
	    cout << "\nPlay again ? (y/n) ";
	    ch = getch();
	    if (ch != 'y' && ch != 'Y'  && ch != 'N' && ch != 'n'){
	    	cout << "\nYou have entered a wrong choice! Try again";
		}
	}
	return 0;
}

void calc :: play()          // Operator
		{
			int ansu,time_taken;
			clock_t t;
			while (flag==1)
			{
				srand(time(NULL));   // Random Seed
				switch (op)
			    	{
			    		case 1 :
			    			  {
			    		  		lo = rand() % 99 + 10;   // Generate numbers from 10 to 99 
			    		  	 	ro = rand() % 99 + 10;
			    		  	 	max_time = 5;
		    		  	     	ans = lo + ro;
						  	  } goto A;
						case 2 :
							  {
						  		int lot = rand() % 99 + 10;
						  		int rot = rand() % 99 + 10;
						  		lo = max(lot,rot);
						  		ro = min(lot,rot);
						  		max_time = 5;
						  		ans = lo - ro;
						  	  } goto A;
					    case 3 :
							  {
						  		lo = rand() % 99 + 10;
						  		ro = rand() % 9 + 2;
 						  		ans = lo * ro;
 						  		max_time = 5;
						      } goto A;
						case 4 :
							  {
						  	    int valid = 0;                                   
						  		while (!valid) {
						  		lo = rand() % 999 + 100;   // Generate numbers from 100 to 999
						  		ro = rand() % 9 + 2;
						  		if (lo % ro == 0) valid = 1;    // Checking if the answer is a whole number  
						  	    }
						  	    max_time = 5;
						  		ans = lo / ro;
						  	} goto A;
					A:
					system("cls");
					cout << "last time : " << time_taken << "\nLeft operand : " << lo << "\nRight operand : " << ro << "\nAnswer : ";
					
					// Calculating time
					t = clock(); 
					cin >> ansu;
					t = clock() - t;
					time_taken = (t)/CLOCKS_PER_SEC;
					if (!eval(ansu, time_taken)) {
			    		flag = 0; 
					}
		    		if (!flag) cout << "\nYou loose!!! \nYour score is : " << getscore();
	    		}
		}
	}
	
int calc :: eval(int ansu, int time_taken)               // Checking user input and answer, 'ansu' is user's input
{
	if (ansu == ans && time_taken <= max_time) {
		score++;
		return 1;
	}
	return 0;
}

void player :: updateScore(){                //TODO 
	highscore++;
}	

void player :: dispData(){                   //TODO  
	
}
void dispData();
