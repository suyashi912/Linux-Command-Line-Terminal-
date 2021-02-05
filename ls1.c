#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h> 
#include <errno.h>
extern int errno;

int main(int argc, char const *argv[])
{

	int c =0; 

	if(argv[1]!=NULL && strcmp(argv[1], "-a")==0)
	{
		struct dirent **dir; 
		char path[100] ; 
		struct stat s1; 
		char name[100]; 
		int q1 = 0; 
		c = scandir(argv[2], &dir, NULL, alphasort); 
		if( c == -1)
	{
		printf("ls : %s\n", strerror(errno));
		return 0; 
	}
		else if(c==0)
		{
			printf("No files found" );
		}
		else
		{
			for(int i=0; i<c; i++)
			{
				strcat(path, "/"); 
				strcpy(name, dir[i]->d_name);
				strcat(path, name);  
				memset(path, '\0', sizeof(path));
				getcwd(path, sizeof(path)) ; 
				strcat(path, "/"); 
				strcat(path, argv[2]); 
				printf("%12s\t ", dir[i]->d_name);
				q1++; 
				if(q1==5)
				{
					printf("\n");
					q1 = 0;
				}
				
			}
		
	}
	}
	else if (argv[1]!=NULL && strcmp(argv[1], "-i") == 0)
{
	struct dirent **dir; 
	char path[100] ; 
	struct stat s1; 
	char name[100]; 
	int q = 0; 
	int ck = -1; 
	c = scandir(argv[2], &dir, NULL, alphasort); 
	if( c == -1)
	{
		printf("ls : %s\n", strerror(errno));
		return 0; 
	}
	else if(c==0)
	{
		printf("No files found" );
	}
	else
	{
		for(int i=0; i<c; i++)
		{
			strcat(path, "/"); 
			strcpy(name, dir[i]->d_name);
			strcat(path, name);  
			 ck = stat(path, &s1); 
			memset(path, '\0', sizeof(path));
			getcwd(path, sizeof(path)) ; 
			strcat(path, "/"); 
			strcat(path, argv[2]); 
			if(name[0] == '.')
				continue; 
			printf("%7ld    %10s\t", s1.st_ino, dir[i]->d_name);
			q++; 
			if(q==3)
			{
				printf("\n");
				q=0; 
			}
			
		}
	
	}
}

else if(argv[1]!=NULL && strcmp(argv[1], "-s") == 0)
{
	struct dirent **dir; 
	char path[100] ; 
	struct stat s1; 
	char name[100];  
	int q = 0; 
	int ck = -1; 
	c = scandir(argv[2], &dir, NULL, alphasort); 
	//printf("%d\n", c);
	if( c == -1)
	{
		printf("ls : %s\n", strerror(errno));
		return 0; 
	}
	else if(c==0)
	{
		printf("No files found" );
	}
	else
	{
		for(int i=0; i<c; i++)
		{
			strcat(path, "/"); 
			strcpy(name, dir[i]->d_name); 
			strcat(path, name); 
			ck = stat(path, &s1); 
			memset(path, '\0', sizeof(path));
			getcwd(path, sizeof(path)) ; 
			strcat(path, "/"); 
			strcat(path, argv[2]); 
			if(name[0] == '.')
				continue; 
			printf("%5ld    %12s\t",  s1.st_blocks/2, dir[i]->d_name);
			q++; 
			if(q==3)
			{
				printf("\n");
				q=0; 
			}
			
		}
	
	}
}
else if (argv[1]!=NULL && strcmp(argv[1], "-U") == 0)
{
	struct dirent **dir; 
	char path[100] ; 
	struct stat s1; 
	char name[100]; 
	int q1 = 0; 
	c = scandir(argv[2], &dir, NULL, NULL);
	if( c == -1)
	{
		printf("ls : %s\n", strerror(errno));
		return 0; 
	}
	else if(c==0)
	{
		printf("No files found" );
	}
	else
	{
		for(int i=0; i<c; i++)
		{

			strcpy(name, dir[i]->d_name); 
			if(name[0] == '.')
				continue; 
			printf("%12s\t", dir[i]->d_name);
			q1++; 
			if(q1 == 5)
			{
				printf("\n");
				q1 = 0; 
			}
			
		}
	
	}
}
else if (strcmp(argv[1], "-1") == 0)
{
	struct dirent **dir; 
	char path[100] ; 
	struct stat s1; 
	char name[100]; 
	int c = scandir(argv[2], &dir, NULL,alphasort);
	if( c == -1)
	{
		printf("ls : %s\n", strerror(errno));
		return 0; 
	}
	else if(c==0)
	{
		printf("No files found" );
	}
	else
	{
		for(int i=0; i<c; i++)
		{

			//getcwd(path, sizeof(path)) ; 
			//strcat(path, "/"); 
			//strcat(path, dir[i]->d_name);
			strcpy(name, dir[i]->d_name);  
			memset(path, '\0', sizeof(path));
			if(name[0] == '.')
				continue; 
			printf("%1s\n", dir[i]-> d_name);
			
		}
	
	}
	
}
else 
{
	
	printf("ls: Invalid arguments\n");

}

return 0; 
}

