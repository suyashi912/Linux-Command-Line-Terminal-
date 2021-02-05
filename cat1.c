#include <string.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>

extern int errno; 
int main(int argc, char *argv[])
{
	int index = 0; 
	int c = 2, c1 = 2; 
	if(argv[1]!=NULL && strcmp("-n", argv[1]) == 0)
	{
		while(argv[c]!=NULL)
		{
				FILE *f = fopen(argv[c], "r"); 
			if( f == NULL)
			{
				printf("cat: %s\n", strerror(errno));  
			}
			else
			{
				char s[300]; 
				while(fgets(s, sizeof(s), f))
				{
					index++;
					printf("	%d  %s", index , s); 
				}
			}
				c++;
				index = 0; 

		}

		
	}
	else if(argv[1]!=NULL && strcmp("-E", argv[1]) == 0)
	{
		while(argv[c1]!=NULL)
		{
				FILE *f = fopen(argv[c1], "r"); 
			if( f == NULL)
			{
				printf("cat: %s\n", strerror(errno));
			}
			else
			{
				char s[300]; 
				while(fgets(s, sizeof(s), f))
				{
				char *s1 = "ok"; 
				s[strlen(s)-1] = '$';
				printf("%s \n",s); 
				
				}
			}
				c1++; 
		}
		
	}
	else
	{
		printf("cat: Invalid arguments\n");
	}
	return 0; 
}
