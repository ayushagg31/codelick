#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define pi 3.1415
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   char str[80];
   cin>>str;
   const char s[2] = "e";
   char *token;
   int i=0;
   char x[3][10];
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      strcpy(x[i],token);
      //cout<<x[i];
      //printf( " %s\n", token );
      i++;
      token = strtok(NULL, s);
   }
   char var1[10]; //= x[0];
   char var2[10];// = x[1];
   char var3[10];
   strcpy(var1,x[0]);
   strcpy(var2,x[1]);
   strcpy(var3,x[2]);// = x[2];
   float r = atof(var1);
   float sx = atof(var2);
   float h = atof(var3);
   float Area;
		Area = pi*r*(sqrt((h*h)+(r*r)));
	//	cout<<Area<<"\n";
		float final = Area * sx;
		int saver = final;
		if((final-saver)>0)
			cout<<saver+1;
		else
			cout<<saver;
		cout<<endl;
   
   }
   return(0);
}