#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
extern int errno; 
int main(int argc, char *argv[])
{
	if(argv[1]!=NULL && strcmp(argv[1], "-u") == 0)
	{
		time_t t = time(NULL); 
		if(t == -1)
		{
			printf("%s\n", "Error occured");
		}
		struct tm *utc = gmtime(&t); 
		if(utc == NULL)
		{
			printf("%s\n", "Error occured");
		}
		printf("%s", asctime(utc));

	}
	else if (argv[1]!=NULL && strcmp(argv[1], "-r") == 0)
	{
		struct dirent **dir; 
		char path[100] ; 
		struct stat s1; 
		char name[100]; 
		getcwd(path, sizeof(path)) ; 
		strcat(path, "/"); 
		strcat(path, argv[2]); 
		int ck = stat(path, &s1); 
		if(ck == 0)
		{
			time_t t = s1.st_mtime; 
			struct tm *lc = localtime(&t); 
			printf("%s",asctime(lc) );
		}
		else
		{
			printf("date: %s \n", strerror(errno));
		}
		
			
		}
	else
	{
		printf("date: Invalid arguments\n");
	}
	return 0;

}

		
		
		