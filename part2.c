#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <pwd.h>
extern int errno; 
void cdhelp(); 
void pwdhelp(); 
int main()
{
	char command[200]; 
	char *token; 
	char temp[200]; 
	char *s[20];
	int count = 1;
	int hisCount = 0; 
	char e[] = "exit"; 
	int pid; 
	int *status; 
	char cwd1[200]; 
	char fileplace[200]; 
	char tempplace[200]; 
	struct passwd *pass = getpwuid(getuid()); 

	char user[100] ; 
	user[0] = '\0'; 
	strcat(user, "/"); 
	strcat(user,strtok(pass->pw_dir,"/" )); 
	strcat(user, "/"); 
	strcat(user, strtok(NULL,"/" )); 
	char s3[200]; 

	if(pass == NULL)
	{
		printf("Error accessing home directory: %s", strerror(errno));
		return 0; 
	}

	if(getcwd(cwd1, sizeof(cwd1))==NULL)
	{
		perror("Error"); 
		return 0; 
	}

	strcpy(fileplace, cwd1); 
	strcpy(tempplace, cwd1); 
	strcat(fileplace, "/history.txt"); 
	strcat(tempplace, "/temp.txt");
	strcpy(temp, cwd1); 
	FILE *f = fopen(fileplace, "a+");
	//printf("%s\n", fileplace);
	if(f==NULL)
	{
		printf("Not able to create file");
	}
	else
	{
		while(fgets(s3, sizeof(s3), f))
{
	hisCount++; 

}

	}

	fclose(f); 
	do{

		fgets(command, 200, stdin); 
		count = 0; 
		f = fopen(fileplace, "a");
		command[strlen(command)-1] = '\0'; 
		if(command[0]!='\0')
		{
			fprintf(f, "%s\n", command);
			hisCount++;
		}
		fclose(f); 

		for(token = strtok(command, " "); token!=NULL; token = strtok(NULL, " "))
		{

			 	s[count++] = token; 

		}
		
		s[count] = NULL;


		if(s[0]!=NULL && strcmp(s[0], "cd") == 0)
	{
		int ch = -1; 
		char cwd[200]; 
		struct stat status; 
		if(s[1]==NULL || s[1]!=NULL && strcmp(s[1], "~") == 0)
	{
		ch = chdir(user); 
		if(ch==-1)
				{
					printf("Error while changing directory: %s", strerror(errno)); 
				}
				else if(ch==0)
					printf("%s\n", user);

	}
	
		else if(s[1]!=NULL && strcmp(s[1], "-L") == 0)
		{
			if(s[2]!=NULL && strcmp(s[2], "..") == 0)
			{

					if(getcwd(cwd, sizeof(cwd)) == NULL)
					{
						perror("getcwd() error"); 
					} 
					else
					{
						if(strcmp(cwd, temp) == 0)
						{
							ch = chdir(s[2]); 
							if(ch == -1)
							{
								printf("Error while changing directory: %s\n", strerror(errno));
							}
							else
							{
								getcwd(cwd, sizeof(cwd)); 
								printf("%s\n", cwd);
								strcpy(temp, cwd); 
							}
						}
						else
						{
							printf("%s\n", cwd);
						}
						
					}
			}
			else if(s[2]!=NULL )
			{
				getcwd(cwd, sizeof(cwd)); 
				strcat(cwd, "/"); 
				strcat(cwd, s[2]); 
				strcpy(temp, cwd); 
				int a = lstat(temp, &status); 
				//printf("%d\n", a);
				if(a==0)
				{
					//printf("%d\n", S_ISLNK(status.st_mode)); 
						if(S_ISLNK(status.st_mode) == 1)
					{
						ch = chdir(temp); 
					if(ch==-1)
					{
						perror("Error while changing directory"); 
					}
					else
						printf("%s\n", cwd);

					}
					
					else 
					{
						ch = chdir(s[2]);
						if(ch == -1)
					{
						printf("Error while changing directory: %s\n", strerror(errno));
					}
					else if( ch == 0)
					{

						if(getcwd(cwd, sizeof(cwd)) == NULL)
						{
							perror("getcwd() error"); 
						} 
						else
							{printf("%s\n", cwd);
							strcpy(temp, cwd);
							}
					}
					}
				}
				else
				{
					perror("Error"); 
				}
			}
			else
			{
				printf("Invalid arguments \n");
			}
				
		}
		else if(s[1]!=NULL && strcmp(s[1], "-P") == 0)
		{
			 
			if(s[2]!=NULL && strcmp(s[2], "..") == 0)
			{

				ch = chdir(".."); 
				if(ch==-1)
				{
					printf("Error while changing directory"); 
				}
				else if(ch==0)
				{
					cwd[1000];
					if(getcwd(cwd, sizeof(cwd)) == NULL)
				{
					perror("getcwd() error"); 
				} 
				else
				{
					printf("%s\n", cwd);
					strcpy(temp, cwd); 
				}
			}
		}
			else if(s[2]!=NULL )
			{
				ch = chdir(s[2]); 
				if(ch==-1)
				{
					perror("Error while changing directory "); 
				}
				else if(ch==0)
			{
					char cwd[1000];
					if(getcwd(cwd, sizeof(cwd)) == NULL)
				{
					perror("getcwd() error"); 
				} 
				else
				{
					printf("%s\n", cwd);
					strcpy(temp, cwd); 
				}
			}
		}
		else
		{
			printf("Invalid arguments\n");
		}
	}

	else if(s[1]!=NULL && strcmp(s[1], "--help")==0 )
	{
		cdhelp(); 
	}
	else {
		printf("Invalid arguments\n"); 
	}
}

		if(s[0]!=NULL && strcmp(s[0], "echo")==0)
		{
			char q[200]; 
			q[0] = '\0'; 

			if(s[1]!=NULL && strcmp("-n", s[1]) == 0)
				{
					if(s[2] == NULL)
					{
						printf("\n");
					}
					else
					{
						char *q1 = s[2]+1; 
						strcpy(q, q1 ); 
						if(count == 3)
						{
							q[strlen(q)-1] = '\0'; 
							printf("%s ",q);
						}
						
						else 
						{
						for(int i=3; i<count-1; i++)
						{	strcat(q, " "); 
							strcat(q, s[i]); 
						}
						q1 = s[count-1]; 
						q1[strlen(q1)-1] = '\0'; 
						strcat(q, " ");
						strcat(q, q1);  
						printf("%s ",q );
					}
					
				}
			}
			else if(s[1]!=NULL && strcmp("-E", s[1]) == 0)
			{
				if(s[2] == NULL)
					{
						printf("\n");
					}
					else
					{
						char *q1 = s[2]+1; 
						strcpy(q, q1 ); 
						if(count == 3)
						{
							q[strlen(q)-1] = '\0'; 
							printf("%s\n",q);
						}
						
						else 
						{ 
						for(int i=3; i<count-1; i++)
						{	strcat(q, " "); 
							strcat(q, s[i]); 
						}
						q1 = s[count-1]; 
						q1[strlen(q1)-1] = '\0';
						strcat(q, " "); 
						strcat(q, q1); 
						printf("%s\n",q );
					}
					
				}

			}
			else
			{
				printf("echo: Invalid arguments.\n");
			}

		}



if(s[0]!=NULL && strcmp(s[0], "pwd") == 0)
{
	char cwd[200]; 
	if(s[1]==NULL || (s[1]!=NULL && strcmp(s[1], "-L")==0))
	{
		printf("%s\n", temp);
	}
	else if(s[1]!=NULL && strcmp(s[1], "-P")==0)
	{
		if(getcwd(cwd, sizeof(cwd)) == NULL)
				{
					perror("getcwd() error"); 
				} 
				else
				{
					printf("%s\n", cwd);
	}
}
	else if(s[1]!=NULL && strcmp(s[1], "--help")==0 )
	{
		pwdhelp(); 
	}
	else
	{
		printf("Invalid arguments\n");
	}
}

		if(s[0]!=NULL && strcmp(s[0], "history")==0)
		{
			int p = hisCount; 
			int lineno = 1; 
			char s1[200]; 
			if(s[1]!=NULL && strcmp(s[1], "-c") == 0)
			{
				FILE *f = fopen(fileplace, "w"); 
				hisCount = 0; 
				fclose(f); 
			}

			else if(s[1]!=NULL && strcmp(s[1], "-d") == 0)
			{
				int del = 1;
				if(s[2]!=NULL)
					p = atoi(s[2]);
				if(p>hisCount)
				printf("history: %d: history position out of range", p);
				else
				{ 
					FILE *f = fopen(fileplace, "r");
					FILE *tempo = fopen(tempplace, "w"); 
					while(fgets(s1, sizeof(s1), f))
					{
						if(del!= p)
						{
							s1[strlen(s1)-1] = '\0'; 
							fprintf(tempo, "%s\n", s1); 
						}
						del++; 
					}
					fclose(f); 
					fclose(tempo); 
					remove(fileplace); 
					rename(tempplace, fileplace); 
					FILE *f1 = fopen(fileplace, "r"); 
					hisCount = hisCount - 1;  
					
					while(fgets(s1, sizeof(s1), f1))
					{
							printf(" %d\t%s", lineno++, s1); 
					}
					fclose(f1); 

			}
		}
			else if(s[1]==NULL)
			{
				int p1 = 1; 
				if(s[1]!=NULL)
				{
					p = atoi(s[1]); 
					if(p>hisCount)
						p = hisCount; 
				}
				else 
					p = hisCount; 
					
				FILE *f = fopen(fileplace, "r");
					while(fgets(s1, sizeof(s1), f))
					{
						if(p1>hisCount-p)
						{
							printf(" %d\t%s", p1++, s1);  
						}
						else
						p1++; 
					}
					fclose(f);
			}
			else
			{
				printf("Invalid arguments\n");
			}
	}
		
		if(s[0]!=NULL && strcmp(s[0], "exit")==0)
		{
			exit(0); 
		}

		if(s[0]!=NULL && strcmp(s[0], "ls")==0)
		{
			 pid = fork(); 
			if(pid<0)
			{
				printf("fork %s\n", strerror(errno));
			}
			else if (pid == 0 )
			{
				
				strcat(cwd1, "/"); 
				strcat(cwd1, "ls1"); 
				s[0] = cwd1; 
				execv(s[0], s); 
				perror("execv()"); 
				exit(1); 
			}
			else
			{
				waitpid(pid, status, 0);
			}

		}

		if(s[0]!=NULL && strcmp(s[0], "cat")==0)
		{
			pid = fork(); 
			if(pid<0)
			{
				printf("fork %s\n", strerror(errno));
			}
			else if(pid == 0)
			{
				strcat(cwd1, "/"); 
				strcat(cwd1, "cat1"); 
				s[0] = cwd1;
				execv(s[0], s); 
				perror("execv()"); 
				exit(1); 
			}
	
			else
			{
				waitpid(pid, status, 0); 
			}

		}

		if(s[0]!=NULL && strcmp(s[0], "date")==0)
		{
			pid = fork(); 
			if(pid<0)
			{
				printf("fork %s\n", strerror(errno));
			}
			else if(pid == 0)
			{
				strcat(cwd1, "/"); 
				strcat(cwd1, "date1"); 
				s[0] = cwd1;  
				execv(s[0], s); 
				perror("execv()"); 
				exit(1); 
			}
	
			else
			{
				waitpid(pid, status, 0); 
			}
		}

		if(s[0]!=NULL && strcmp(s[0], "rm")==0)
		{
		
			pid = fork(); 
			if(pid<0)
			{

				printf("fork %s\n", strerror(errno));

			}
			else if(pid == 0)
			{
				strcat(cwd1, "/"); 
				strcat(cwd1, "rm1"); 
				s[0] = cwd1; 
				execv(s[0], s); 
				perror("execv()"); 
				exit(1); 

			}
			else
			{

				waitpid(pid, status, 0); 

			}
	
		}

		if(s[0]!=NULL && strcmp(s[0], "mkdir")==0)
		{	

			pid = fork(); 
			if(pid<0)
			{
				printf("fork %s\n", strerror(errno));
			}

			else if(pid == 0)
			{
				strcat(cwd1, "/"); 
				strcat(cwd1, "mkdir1"); 
				s[0] = cwd1; 
				execv(s[0], s); 
				perror("execv()"); 
				exit(1); 
			}

			else
			{
				waitpid(pid, status, 0); 
			}
			
		}

	}
	while( s[0]!="exit"); 

	return 0; 
}

void cdhelp()
{
	printf("cd: cd [-L|[-P [-e]] [-@]] [dir]\n"); 
    printf("Change the shell working directory.\n\n"); 
    printf("Change the current directory to DIR.  The default DIR is the value of the\nHOME shell variable.\n\n" );
    printf("The variable CDPATH defines the search path for the directory containing\nDIR.  Alternative directory names in CDPATH are separated by a colon (:).\nA null directory name is the same as the current directory.  If DIR begins\nwith a slash (/), then CDPATH is not used.\n\n " );
    printf(" If the directory is not found, and the shell option `cdable_vars' is set,\nthe word is assumed to be  a variable name.  If that variable has a value,\nits value is used for DIR.\n\n" );
    printf("Options:\n" );
    printf("  -L	force symbolic links to be followed: resolve symbolic\nlinks in DIR after processing instances of `..'\n" );
    printf("  -P	use the physical directory structure without following\nsymbolic links: resolve symbolic links in DIR before\nprocessing instances of `..'\n" );
    printf("  -e	if the -P option is supplied, and the current working\ndirectory cannot be determined successfully, exit with\na non-zero status\n" );
    printf("  -@	on systems that support it, present a file with extended\nattributes as a directory containing the file attributes\n" );
    printf("  The default is to follow symbolic links, as if `-L' were specified.\n`..' is processed by removing the immediately previous pathname component\nback to a slash or the beginning of DIR.\n\n" );
    printf("  Exit Status:\n"); 
    printf("  Returns 0 if the directory is changed, and if $PWD is set successfully when\n-P is used; non-zero otherwise.\n" ); 

}
void pwdhelp()
{
    printf( "%s", "pwd: pwd [-LP]\nPrint the name of the current working directory.\n\nOptions:\n-L   print the value of $PWD if it names the current working\ndirectory\n-P	print the physical directory, without any symbolic links\n\nBy default, `pwd' behaves as if `-L' were specified.\n\nExit Status:\nReturns 0 unless an invalid option is given or the current directory\ncannot be read.\n"); 

}