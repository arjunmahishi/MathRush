#if !defined( _math_h )
#include <math.h>
#endif


using namespace std;

char threeD[15][5][8]=  { 
				{ {"  #####"}, {"  #   #"},{"  #   #"},{"  #   #"},{"  #####"} },
				{ {"    #  "}, {"    #  "},{"     # "},{"     # "},{"     # "} },
				{ {"  #####"}, {"      #"},{"  #####"},{"  #    "},{"  #####"} },
                       		{ {"  #####"}, {"      #"},{"  #####"},{"      #"},{"  #####"} },
                       		{ {"  #   #"}, {"  #   #"},{"  #####"},{"      #"},{"      #"} },
                       		{ {"  #####"}, {"  #    "},{"  #####"},{"      #"},{"  #####"} },
                       		{ {"  #####"}, {"  #    "},{"  #####"},{"  #   #"},{"  #####"} },
                       		{ {"  #####"}, {"     # "},{"    #  "},{"   #   "},{"  #    "} },
                       		{ {"  #####"}, {"  #   #"},{"  #####"},{"  #   #"},{"  #####"} },
                       		{ {"  #####"}, {"  #   #"},{"  #####"},{"      #"},{"  #####"} },
                       		{ {"       "}, {"       "},{"  #####"},{"  #####"},{"       "} },
                       		{ {"    #  "}, {"    #  "},{"  #####"},{"    #  "},{"    #  "} },
                       		{ {"       "}, {"       "},{"  #####"},{"       "},{"       "} },
                      		{ {"  #   #"}, {"   # # "},{"    #  "},{"   # # "},{"  #   #"} },
                       		{ {"       "}, {"    0  "},{"  #####"},{"    #  "},{"       "} }
			 };
 
char threeD2[7][5][8];
int e;
int counter (int );
void operand(int );
void store(int);
void operate(int );

void printExp(int lo,int ope, int ro)
	{
		srand(time(NULL));
		int i,j,k;
		operand(lo);
		operate(ope);
		operand(ro);
		operate(0);
		for(i=0;i<5;i++)    // printing the expression
		{
			for(k=0;k<7;k++)
			{
				for(j=0;j<8;j++)
				{
					cout  << threeD2[k][i][j];
				}
				cout<<" ";
			}
			cout<< "\n";
		}
		e = 0;
	}   // end of printExp
  
void store(int arg)
   {
	  int i,j;
      for(i=0;i<5;i++)
   		{
   	  		for(j=0;j<8;j++)
   	    		{
   	    			threeD2[e][i][j] = threeD[arg][i][j];
				}
   		} 
   
	}	

int counter(int arg)
	{ 
		int c=0; 
		while(arg!=0)
			{
				c++;
				arg=arg/10;
			}
		return c-1;
    }


void operand(int arg) {
 	int c,d;
 	c=counter(arg);
 	while(c+1!=0)
 		{ 
	    	e++;
   			d=arg/pow(10,c);
   			store(d);
      		arg=arg%(int)(pow(10,c));
      	    c--;    	
   		} 
}

void operate(int a)
{  int i,j;
   e++;
     for(i=0;i<5;i++){
     	for(j=0;j<8;j++){
   	    	threeD2[e][i][j] = threeD[10+a][i][j];
		}	
	 }
}




 

