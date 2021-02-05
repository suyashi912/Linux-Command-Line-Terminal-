#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
extern int errno;

int main(int argc, char *argv[])
{
	int c1 = 2; 
	int chk = -1; 
	int count =2;
	char delim[200] = "", *p1, *p2;  
	if(strcmp(argv[1], "-i") == 0)
	{

		while(argv[count]!=NULL)
		{
			p2 = argv[count]; 
			delim[0] = '\0';  
			while(p2[strlen(p2)-1] == '\\')
			{	
				p2[strlen(p2)-1] = '\0'; 
				strcat(delim, p2);
				strcat(delim, " "); 
				count++; 
				p2 = argv[count]; 
			}
			if(p2!=NULL)
			{
				strcat(delim, p2);

				count++; 
			}
			printf("rm: remove regular file '%s'?\n ", delim);
			char prompt[10]; 
			chk = -1; 
			fgets( prompt, sizeof(prompt), stdin); 
			prompt[strlen(prompt) - 1] = '\0'; 
			if(strcmp(prompt, "y") == 0 || strcmp(prompt, "yes") == 0)
			{
				chk = remove(delim); 
			if(chk == 0 )
			{
				printf("\n");
			}
			else
			{
				printf("rm: %s\n", strerror(errno)); 
			}
			}
		}
		
		
	}
	else if(strcmp(argv[1], "-v") == 0)
	{
	
		while(argv[c1]!= NULL)
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
			if(remove(delim) == 0)
			{
			 
				printf("removed '%s '\n", delim);
			}
			else
			{
				printf("rm: %s: %s\n", delim, strerror(errno));
			}
		}
		
	}
	else
	{
		printf("cat: Invalid arguments\n");
	}
	return 0;
}