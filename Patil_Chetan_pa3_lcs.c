//LCS problem for two strings


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

    printf("%d",argc);
	if(argc!=3)   //./a.out is counted as first argument
	{
        printf("Please Enter Two String Arguments Through Commnad Line!");
        return 0;
	}
    else
    {
			char s1[100];
			char s2[100];

			//copying commandline arguments to the local strings s1 and s2

			strcpy(s1,argv[1]);
			strcpy(s2,argv[2]);


		    printf("\n\nYou have entered s1: %s and s2: %s",s1, s2);



		    int m,n;

		    m=strlen(s1);  //length of first string
		    n=strlen(s2);  //length of second string

		    if(m>100 || n>100) //error handling on lengths of strings
		    {
		    	printf("\nLengths of inpute strings can not be greater than 100!");
		    	return 0;
		    }
		    else
		    {
				    //Initializing Matrix C and Matrix b

				    int c[m+1][n+1];    //2-d array to store length of common subsequence
				    char b[m+1][n+1];   //2-d array to store directins L=LEFT,  U=UPPER,   D=DIAGONAL

				    int i=0; int j=0; int k=0;

				    for(i=0;i<=m;i++)      //initialize first column to zeros
				    {
				    	c[i][0]=0;
				    	b[i][0]='\0';

				    	
				    }

				    for(j=0;j<=n;j++)	 //Initialize first row to zeros
				    {
				    	c[0][j]=0;
				    	b[0][j]='\0';
				    	
				    }

				   
				    //Calculating Matrix C and Matrix b (Core Logic)

				    printf("\n\n");
				    for(i=1;i<=m;i++)
				    {
				    	for(j=1;j<=n;j++)
				    	{
				    		if(s1[i-1]==s2[j-1])
				    		{
				    			c[i][j]=c[i-1][j-1]+1;
				    			b[i][j]='D';
				    		}
				    		else
				    		{
				    			if(c[i-1][j]>=c[i][j-1])
				    			{		
				    				c[i][j]=c[i-1][j];
				    				b[i][j]='U';
				    			}
				    			else
				    			{
				    				c[i][j]=c[i][j-1];
				    				b[i][j]='L';
				    			}
				    		}
				    	}
				    }


				    //Printing the Matrix C with b

				    char LCS[100];
				    int p=c[m][n];
				   

				    for(i=0;i<=m;i++)
				    {	printf("\n");
				    	for(j=0;j<=n;j++)
				    		printf("\t%d[%c]",c[i][j],b[i][j]);
				    }


				    //Backtracing the Longest Common Subsequence between given strings s1 and s2
				    
				    i=m;j=n;k=p;
				    LCS[p]='\0';
				    printf("\n\n");
				    while(i!=0 && j!=0)
				    {
				    		if(b[i][j]=='U')
				    		{
				    			i=i-1;
				    		}
				    		else if(b[i][j]=='L')
				    		{	j=j-1;
				    		}
				    		else
				    		{
								i=i-1;
				    			j=j-1;
				    			LCS[k-1]=s1[i];    //storing the common characters
				    			k=k-1;
				    		}
				    }
				    		
				 
				    printf("\n\nLength of Longest Common Subsequence: %d",p);
				    printf("\nLongest Common Subsequence: %s",LCS);
				    printf("\n\n");
				    return 0;
		    }

		    return 0;
	}

}