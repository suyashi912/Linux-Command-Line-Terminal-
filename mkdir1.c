#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

extern int errno; 
int main(int argc, char *argv[])
{
	int create = -1; 
	int c1 = 2, c2 = 2; 
	char *p1, *p2, delim[200]; 
	if(argv[1]!=NULL && strcmp(argv[1], "-v") == 0)
	{
		
		while(argv[c1]!=NULL)
		{
			p1 = argv[c1]; 
			delim[0] = '\0';  
			while(p1[strlen(p1)-1] == '\\')
			{	
				p1[strlen(p1)-1] = '\0'; 
				strcat(delim, p1);
				strcat(delim, " "); 
				c1++; 
				p1 = argv[c1]; 
			}
			if(p1!=NULL)
			{
				strcat(delim, p1);
				c1++; 
			}

		create = mkdir(delim, 0755); 
		if(create == 0)
		{
			printf("mkdir : created directory '%s' \n", delim);
		}
		else
		{
			printf("mkdir: %s\n",strerror(errno) );
			
		}
	}

	}
	else if(argv[1]!=NULL && strcmp(argv[1], "-p") == 0)
	{
		char cwd[1000]; 
		getcwd(cwd, sizeof(cwd)); 
		
		while(argv[c2]!=NULL)
		{

		char *ptr = argv[c2]; 
		int create; 
		int count =0; 
		int r=1; 
		int chd =0; 
		char s[100][10];
		p2 = argv[c2]; 
		delim[0] = '\0';  
			while(p2[strlen(p2)-1] == '\\')
			{	
				p2[strlen(p2)-1] = '\0'; 
				strcat(delim, p2);
				strcat(delim, " "); 
				c2++; 
				p2 = argv[c2]; 
			}
			if(p2!=NULL)
			{
				strcat(delim, p1);
				c2++; 
			} 
		for(char *token = strtok(ptr, "/"); token!=NULL; token = strtok(NULL, "/"))
		{
			 strcpy(s[count], token); 
			 count++; 
		}
		create = mkdir(s[0], 0755); 
		if(create == 0 || errno == EEXIST )
		{
			while((create == 0 || errno == EEXIST )&& r<count && chd == 0 )
		{
			 chd = chdir(s[r-1]); 
			if(chd == 0)
			{
				create = mkdir(s[r], 0755); 
			}
			else
			{
				printf("Error: %s\n", strerror(errno));
				break; 
			}
			r++; 
			
		}
	}
		chdir(cwd); 

		}
		

	}
	else
	{
		printf("mkdir: Invalid arguments\n");
	}
	return 0;
}
