PART 2 DESCRIPTION 

1.  Internal commands 

a.  history → 

-   This command is used to print the history of commands written by the user. 

-   My code prints all the past commands written by the user on the terminal until he clears it using -c flag. 

-   I am storing the entire history on a txt file and appending it in every instance of command entered by the user. 

Flags used -

1.  '-c'

-   This flag clears the history from the text file. 

-   When this flag is invoked I open the file in "w" mode due to which it creates a new file and overwrites data on it. Hence this flag clears the previous history. 

2.  '-d'

-   This flag is used to delete a particular line of history. 

-   We have to specify a number beside it to clear that history line. 

-   In my code I am creating a next text file and writing the lines of the history text file onto it except the deleted command. Then I am renaming the new file and deleting the old one.

3.  history 

-   This command is used to print the entire history stored in the history text file. 

Test cases

![](https://lh4.googleusercontent.com/6OLRCSPJJanzYUCQIwsiwmE-leiuAgvwpjtevYJi1Wcr0HHKSN313yCg8s14jOKUyygSJVUzWQn5s5WHt-oBDAJrrbf61Qcu2iIpZW1hpK9pnHm3bbVYNt0d3uxdM8Ntf9yXz9jm)

The -d flag above deletes the line at the second position in history.

![](https://lh3.googleusercontent.com/Oe12dUmYgeA1rmr9wo-ILqUx9xqamNhu-govxfcQr_jNF4zNDF7lZ9e4kUeT-EO1ALpkT1KM67ge2uE5qcg-64KW96pm-H1iRAn9VP98yG5B2eOsNkD_TsXHbRtWYixBcnq0Httb)

The -c flag clears the entire history.

![](https://lh4.googleusercontent.com/3r4OfUl6JW2JFNPMIJiY9ycNhd7ZIjRZsABNFPujV_WWMzNnH7IorCbBY394S5XIs4o1nGmL97FlFbo-I9ztm5WZSc-W9D7OSOiGr17rRPqNcQbq_uXxTvL_jt2nJXX18EAtAFZl)

History command displays the entire history stored in the file. 

Error handling and corner cases 

1.  If the line number to be deleted is more than than the total lines in history, then an error message is printed using the strerror() function. ![](https://lh5.googleusercontent.com/jbK_aGuq1igQceMfWd20dPQs-wKsawvi5EFUEJh83M_BVLv53ZU31Um_dIB1Dm26y0e8bdBBIt-OTU9PILOiD6Es3JeuvR6fIg_4YTKO_rMhSAtPEQIZFABhNrK9Ua2SWQ6h4QL-)

2.  In case the correct arguments / correct number of arguments aren't entered by the user then it displays an error message of invalid arguments. 

![](https://lh3.googleusercontent.com/HyVCdRxqkbHhgCESBprDbO5YoMeExJ00b7FqBed220YffDGmkxBk5ikz60gWx43p7u-Tvj2nSvR0zMUt4UMDTsGbwVnYljTG-28EPhKP8EXuJh12VJXLQUfEMR4fUGOVWNBqcaaS)

b.  pwd -

 This command is used to print the current directory in which the user is working at the moment. 

Flags used 

1.  '-P' - 

-   This is used to display the physical path ignoring any symlinks present in it. It avoids the links. 

-   In my code I use getcwd() function to get the physical path of the current working directory. 

2.  '-L' - 

-   It does not remove the symlinks. It displays the logical path of the current working directory. 

-   In my code I have stored the logical path I got from cwd in a temporary string and I display it whenever this flag is invoked. 

3.  pwd - it functions the same as -L flag 

4.  '--help'

This flag is used to display the manpages of pwd.

Test Cases

![](https://lh4.googleusercontent.com/0XHrxur0d0Bf-jdHCS33WE4rMbHUHD2mODdEOSM2nE1ct8obrO_1CW5IvM17mQ_fuJoM1X_zsov8Ma6Issy9sIOkKMkuUVDsT4hM30dApZZbhKQyt2AAS-xriHAEhVtAdFJp4WHk)

Here we can see that pwd -L prints the logical path i.e the one with the symlink '~p' while -P just displays the logical path.

![](https://lh3.googleusercontent.com/Va2UQkVrhal6GhclB_fD8iWQtGOCHB46BqVuz-7HgSvz21AdyKjV0XkhBgC_Cd2A69Ku6HV9MMkBNNbUx5Fr6Ah3T2y-xfF_bvn4KPhB8-aegk8PneX79_DcNBZUA80OjpujO41L)

It displays the help section for the pwd command.

Error handling and corner cases 

1.  In case the correct arguments / correct number of arguments aren't entered by the user then it displays error message of invalid arguments. 

![](https://lh5.googleusercontent.com/6fDW6uWyTf_G3zBSW6YCrQAZnfC2WLzAI9CDKgcpZLQuyLxzBDyOnCf1ZCiWEcUuowQjHh8feF5BGr7FFA7v8aHu-_h4KOUDYHOLpHGhFCTvt8M2CKAqYXIVd8GopB3TPZlZsBla)

c.  cd - This command is used to change the current working directory of user. 

Flags used 

1.  '-P' - 

-   It avoids the symbolic links and only considers the absolute physical path.

-   It resolves symbolic links. 

-   In my code I just specify the path to the directory that we want to navigate to in chdir() function. It takes us the the required directory. 

2.  '-L' - 

-   The symbolic links are followed in this case. I have stored the symbolic link in a temporary array and change it as and when required. 

3.  cd ~ - it takes the user to its home directory

4.  cd - it has the same functionality as cd ~

5.  '--help' - this command displays the man pages/help section for cwd

Test cases 

![](https://lh3.googleusercontent.com/u_gHtn0lK65708NUH_lt2uAeL2g6vnZuRTc5CRspX5-4iSw_itgbBONhlFQn3YwrX6dswMXpkABokJeWOXUW57kEN4mjhNavotmIdBzb7k7EHUfEgYbyQ48HuN00LEqCTphB5MKo)

This is the --help function used to display the help section of cd. 

![](https://lh6.googleusercontent.com/ViutI4K9CFHhPzQgH_IQL5wn2B4ly3hmvmFZpYR_xHbT1uC8y_j9PXKO8e8VCLB-de1rGdgZ3RPfD6SymI2XXSFlwkSQpiuMHqFoOAec-_sItGwrJWDnrDmlwmD307TNmUPgNlmn)

In the above test case ~p is a symbolic link inside u. We can see that -L gives us the logical path while -P takes us to the physical paths after removing the symbolic links.

Error handling and corner cases 

1.  It displays an error when it cannot find a file or directory to which it can go to . 

![](https://lh3.googleusercontent.com/c9NJYtQpOoin-DGHi_-eVRJWTJvbIrCurbZIZxV9CFlC7wDtGZzFWkQ5yZb4JJpLweL_BCpPY0zq6OJZUEczAIe377_f5i0koHoWtEtykrdG1UGLotDoLSVFXWkyWnEK6LopO3Ba)

2.  In case the correct arguments / correct number of arguments aren't entered by the user then it displays error message of invalid arguments. 

![](https://lh3.googleusercontent.com/heiTAlTvx9AqLMUNcdN8LW8NjI6j-B6QjKKKwG2qh2j2PcLfEfqiw6IrWCvJkqYOH3ThPT9qfjRCbiqlzg9HoXlJXA6unQD9aSjMMl1RQ1VNBJGXLjVumvZglp-DSx8CFu9yoahy)

d.  echo → This command displays the arguments specifies to it on the terminal 

Flags used - 

1.  '-n' → 

-   This flag is used to print the argument without appending a new line. 

-   In my code I read the argument word by word. I remove the quotes and concatenate them together. I then print them without appending a line to them 

2.  '-E' → 

-   This is the default flag which is used to ignore the escape characters / backslash - escaped character.

-   In my code I read the argument word by word. I remove the quotes and concatenate them together. I then print them 

-   while suppressing the backslash characters.

Test cases

![](https://lh4.googleusercontent.com/_7HC8ixwrMldndPmMs4nYskrDvvApHrrpYs3p6LAag-luyM47Btzl6pr_2jSHZWnSV1HJaqucYtSn8fZsUqMyJlIDrJkjYG00wuqsRBal2JdAzdC9FVDE-TT3Zzfjq7Jybxci62l)

Above is a basic test case for echo

Error handling and corner cases 

1.  In case the correct arguments / correct number of arguments aren't entered by the user then it displays error message of invalid arguments. 

![](https://lh4.googleusercontent.com/YmMlt7WjNq76P1-GF3bFVYpnxID0ug8-4qffEmMbFbmbwu94azdo5V3Y23qoFhHBFUASEG0vI0x8VLdo5l0agCQTZxhTGcsaBRlYXwXOrulpgNK5oEV4gBq6k9NzGSKJ5r_B470d)

2.  It can handle space separated message to be echoed within quotes without any problem. 

![](https://lh3.googleusercontent.com/nUACiloR5x89rz9RFXHngYAimR85305HAr6m9A5gd6QtFmRLiWzlY4nS7dvDUP5eOgyRvJlQad27vybuHtE2NrnWbwerqFoQTaSobJl0ByhUwTsdLQKvE9mAfNWjVrPaOLHywH1r)

![](https://lh3.googleusercontent.com/Uqi3Ky00LLZtEfHgjApowJlH5hN61WX1p65fwc9oPVAjbMV38nLodyI41DB5St7x-BRKi3dO3KPXqjUuvzqvQcktt1eq6FllpOqlslvguZbwIeEgv7FhVG0x5c6gXn9KgmmibFKc)

e.  exit

This command is used to exit from a program.

2\. External commands 

a.  cat → It is used to print the details of files on the terminal or to concatenate files together. 

Flags used - 

1.  '-n'

This flag numbers the lines in the output. I just take a counter in my code and increase it by  1 after printing each line. 

2.  '-E'

This flag is used to append a $ character at the end of each line. In my code I print each line followed by $ character. 

Test cases 

![](https://lh4.googleusercontent.com/UKjX0CgKjzT3UGLi5xcd0nSvVGX-hRCBf3CViZOv5rmV7LjlbdY2LufN7SbvaqJeQjOFWD_5AYgvLd8ndDG7Q7F4tyonoW2WyHaEb0r580FLAnfImKpkQacQGoNFho0yaI6AZAMe)

Using -n flag  of cat command 

![](https://lh6.googleusercontent.com/lv_GFzvuW_JtKjlj4Chi2oB8hHPmjcXER6pxdc6QnXbCUnMfgUBSJMjFrFFmLMP8mR_pER8slQJoGhxUiOZqLPJjvf4yWXluwYxSbmdZlwykk6vBkQUZRY7aF55MheZS9ukevXuf)

Using -E flag of cat command

Error handling and corner cases

1.  If the user enters wrong arguments then an error message is displayed saying "Invalid arguments"

![](https://lh6.googleusercontent.com/n1FjEz63H8yh3Fi_Oz_jnAOQ_iFdKxUyMWASnkpNho8RcWbxujrNMgaZ1cp8K83-Sy8GVzo6ypeH4gU3YV2GsceQPiCpepppynp8p1VRLPEgtqBFhqqA5MBIIzcB2nkzJE8yOV0t)

2.  The code handles multiple files. We can display the data of multiple files one after another using cat command 

![](https://lh3.googleusercontent.com/rNkQuuR4iWK64c--qU6fOQOBbF4iLqfVmg5uFAESrCT074fN5d9zyMTQl5e_s2JB4RtKLpHF1Nx-TtQ3VsU5WV-m8wxRc5QGVN_sOLp9iFbR2BF-b4s2Cpjq-m44SxGKxc1PfJ-W)

3.  In case the file from which we want cat to read data doesnt exists it displays an error message using the strerror() function that takes errno as the parameter.

![](https://lh3.googleusercontent.com/sjkSfRKQRDJS_uHkoDoAMaGVsbDh-1qhTqvK4LjeJkiW7828motdb4bImMTF8oyBEVDjKveXITHz83Jt2LjTmZfQmhKGPQ0ib3uJKqG6xykkWAADVQC7Cvk2fJNFLoZbgJQnbQ1l)

b.  Ls → It is used to print the content of the directory on the terminal. 

Flags used 

1.  '-a'-

-   This is the -a flag to display hidden files. 

-   I have used schdir() to get the names of the files and sort them using alphasort. 

-   I display all the file names row wise without ignoring the files that begin with '.'. 

2.  '-U'

-   This flag is used to display the contents of the directory in an unsorted order i.e in the order in which they are stored in the directory. 

3.  '-1'

-   This is used to display one file in each line. 

-   I have used schdir() to get the names of the files and sort them using alphasort. 

-   I display all the file names in subsequent row while also ignoring the files that begin with '.'.

4.  '-s'

-   This is the -s command that displays the size allocated to each file in blocks. 

-   I have used schdir() to get the names of the files and sort them using alphasort. 

-   I display all the file names and file size row wise while also ignoring the files that begin with '.'.

5.  '-i'

-   This is the -i flag that shows the index number of each file 

-   I have used schdir() to get the names of the files and sort them using alphasort. 

-   I display all the file names and index numbers row wise while also ignoring the files that begin with '.'.

Test cases 

I am calling each of the 5 above ls flags on my desktop and the obtain the following output -

![](https://lh3.googleusercontent.com/xe2DmVF7IKzKW5W6ed-9Fkie-eDhK5BJPNNJBSRabzaUqHlxuXkuuVpwmC_4fnzA9ZG9IVO4aKudFZLP5Y7hCz4mfKgpOQUu04rl8W2oBXkRqIX3i9DFY40P0TpM-iUwn6DyXSo3)

This is the -i flag that shows the index number of each file

![](https://lh4.googleusercontent.com/blTpObL_S4KDFsgkuxOvVJuLUZ5g7dqC13tKcuYXfiBwVBcFwnLrFePMEQ_mgCKcgcd_ynBIIAvmU9uSGqJ5Qq5HGwTibp-QNS0_m04h2Q72GZ9SdHO8eE4im5Qiq-XHi6Z5K9mI)

This is the -s command that displays the size allocated to each file in blocks.

![](https://lh6.googleusercontent.com/_oPw-ZboiT59sA0HJsJjil8v-KKL3uVmB5rfyPYToXmYLqUr53lAl9TvmbRf8sZxWzcbGSP7UJknjzXOUysmpZwblywdUOT1tR4uBFXJAFeBAiGVwKelLIw0HLnIZjvsXJq_fDnP)

This is the -U flag to display the files in their natural order in which it is present in the directory. ![](https://lh4.googleusercontent.com/7y_CfSvI2Xjj-UW3tBCDRNmDX1kuNldwpvTpEU_Kj2untEif6yZNkt7QJWKOv0ZmMfy4ATCyDHnEivWgxid4ZXiVEFo6p3-AzWPKYXKn849Yv1nBIkILmD9Ts--ZljLQ9Vo9wrDU) This is the -a flag to display hidden files.

![](https://lh3.googleusercontent.com/FBpyZRz2Sfs9602I-Ye6iadObLcDklQYF2b706ww5kDJpEej8kQ46pMuaSvhxhgFng1xWLEwWErssbCBSvT0UproTcUy2FwXyTtGveP53Hdo3TLIDdi-t5Dx4nVuB_PzdPnQv3jD)

This is the -1 flag that displays the flags row wise.

ERROR HANDLING AND CORNER CASES 

1.  If the user enters wrong arguments then an error message is displayed saying "Invalid arguments"

![](https://lh5.googleusercontent.com/JpRCZ4zwFBfrcHtdececzJyZGoEpPsMbQq7c1-QCE6lM8AKoj-bGFy_-vIMD21ByhdYwW3FZsn199ln8go9y2o73b8ox0UQtkL1CcMZ2AXBm4mxOmXFmYb61W0-OfsJLPoLJnzY7)

2.  If the file on which we call ls does not exist in that directory, then an error message is shown that no such file or directory exists. 

This is done by using the strerror() function which takes errno as its parameter. 

![](https://lh6.googleusercontent.com/wC-3v9MwqI6tbEqFuAyNHhd1euMvPqH5hx1ETByyG5JJsckOaArFVk57jI-O9T0LjHYbI6b0k0OonsiWrs6hc9PMDr-9LhEZrwO6ZdJ0gmweB8OjBwmgbcTV6f2_Efp6iTCsRaSc)

c.  date - This is used to access various formats and kinds of dates. Using it we can set the date and time of a system or print dates and time etc. 

Flags used 

1.  '-u' - 

-   This flag is used to print the UTC i.e the Coordinated universal time. 

-   For this command I used the time.h header files which contains function gmtime() to get the UTC time. 

2.  '-r'

-   This flag takes a file as its argument.

-   It prints the last modification date of the file stored in the system. It prints the time and date in the timeline of the location. 

-   For eg in my case it prints the IST time. 

-   Here again I am using the time.h header file. I am also using the stat struct that stores the time of the last modification of the file. 

Test Cases 

![](https://lh3.googleusercontent.com/OBVo6QxBK690uwbnsq66i-F065vuwd5pyUXgtJZyuYHe8MYJjeUFFDzAmaHeW5iOZW9gu9ojcSDQZ1ckG0tlLMFNn-AF5WqHYVokuseDv1MjU6t2SqkXSyOfmZjx55moUedpGzdi)

Error handling and corner cases 

1.  In case the file entered with the command -r which prints the local time of last modification, then error is printed using errno value passed in strerror() function. 

![](https://lh4.googleusercontent.com/JebmUHmxm37lHpXZqLxZvkSp2EeRA4SPSWfwp7hUjdqCSdG6jdOh43lxScTdiJNlPGVdAlP8x2iB4mi5_E0KJzVRwvyhuHSuzUgJHiIxwIGdns3UDh3uwA1LDgVqMlPryIMracFh)

2.  In case the user doesn't enter atleast two arguments (minimum) or doesn't enter the correct flag then the "invalid arguments " error is displayed. 

![](https://lh4.googleusercontent.com/Iwz2fVnWejFmB3SBbqrb2lBDeHKVQafPdKv-QPaHaNUthpAtCzO2OBOIMGuqIkGI3WWnFmTPceQxNS3hXiUIVH8THPyIhPeP3HV3_cO3LUcpYRmNeCeas5HzU7l_bhAtVPI9I0ul)

3.  In case the utc time fails to be displayed in -u flag , then we print an error message.

d.  rm → This command is used to remove specific files from the system. 

Flags  - 

1) '-i' →

-   This flag prompts the user for a "yes" or "no" before deleting the file. If the user enters "yes" or "y" then the file is removed from the system.

Implementation - 

-   In my code the if statement first checks if the flag '-i' is selected by the user or not. 

-   If yes, then it checks the arguments. The while loop takes the arguments till it encounters a null argument and stops. We can thus take multiple files or a single file with spaces in it. 

-   The code then prompts the user about whether to delete the file or not.

-   If the user enters "yes" or "y", it tries to remove the file. In case the file does not exist or is a non empty directory it shows an error. 

-   If the user says no, then it ignores the rm command and moves to the next argument. 

-   In case the user enters "yes" for non-existent file names or non empty directories, it prints the error message instead of deleting them . 

-   These error messages are printed using strerror() function which takes in errno as the parameter. Errno is set whenever an error is encountered.

 2) -v → This flag provides a verbose of the fact that a given file / directory is removed from the system. In case the file does not exist or the directory isn't empty it displays an error message. 

Implementation -

-   The if statement within the code firstly checks if the flag is '-v' or not. This flag basically gives the user a written statement about the file he wants to remove. 

-   Again while loop takes the arguments till it encounters a null argument and stops. We can thus take multiple files or a single file with spaces in it or both. 

-   The code then tries to delete all the specified files and prints the delete message or error message on by one. 

-   In case the user enters non-existent file names or non empty directories, it prints the error message instead of deleting them . 

-   These error messages are printed using strerror() function which takes in errno as the parameter. Errno is set whenever an error is encountered.

Test cases

![](https://lh3.googleusercontent.com/TK_WSLHDIURUgaiZc3CBi0-niqNLZWc_xqgCMqouJgVFEinGyS_KZfzSd9EB9zu2FPHkQeUp6Og8saUFLn_Rc0ZBgd3-WGVVeihS15eFgU5_xEZjJToIE28-wyEz8NWV_vMu1GeE)

![](https://lh4.googleusercontent.com/Y6ZTL-YFH2JvC0GQkEtABFyEFYbaLW65SPui4aRqCH4mMZgxb7j9rweqglr-Lg5lqfB77qW5057luvTWprkDG4JS_1SaK3hNvl45lemg-XsdjwWKfUzSU9aKzt0AS9YD4YSCVVDW)

Error and corner case handling 

1.  When the name of the file contains spaces in it.

I have used  '\' as the delimiter to consider spaces . A file named "q w" can also be written as q\ w and would be considered a single file with a space in it.

It shows that the file 'q w' has been deleted. 

![](https://lh4.googleusercontent.com/rwJchjqAMJbMPzhT2HzJ5K6VhLVR1PV8lWvA9-6TmFMm_HRtX1-q9ZH4UCWPY1obiO96u6Ge5nmaYNElrAeEc39BwwnfFZWwZLHGYhUwTQcUeqfTqPQVD8uTsGKsVVEbMmzz7CTk)

-i  prompts the user asking him whether to  delete the file or not. Since I have written 'n', it won't be deleted. 

![](https://lh5.googleusercontent.com/5QbZZd1meSbjl7sg8pLKWm-_dZ1S9G_6Oko-IqfFeWxX-Y258Fwg9_1KIzCPa96j-N6ae21N8erTHKCYmzKGWfd7wRImi2xLVMw9ii9MeE96K0kPOquceHELJ7PNFbXNABEsTU0S)

2.  The rm command doesn't remove non empty directories. Hence it prints an error message whenever it encounters such problems. 

![](https://lh6.googleusercontent.com/JcHjpB694VpXSNi-bPT-7fPCyhEeFDXvnp9m74p7pxlmV2CAXyMNkdCq1tEYFZc-Zml2DfqOVJ2AcboIT2Yepz6h4MIyGRee3hsN3XvZcJzDJSaKJZLGGp4g-PWF2oT28HoQKidj)![](https://lh3.googleusercontent.com/eFLdINXvUocf_oHSXvA7ndjHfxNVlE_vf68CIzd2-gCyFHIaQSpjRwE7dO93xVbRToj27GaApQOlho3CEyuGCAnNwjF5WFSgNwK5-JLvy1TLUOCYfkaJv6fvOw9rCT5xuzADcj5r)

3.  In the case when the file / directory that the user enters doesn't exist, then it gives the following error. 

![](https://lh5.googleusercontent.com/pvD7UwCLKkPCLM6o-QW2UQ7JcgM55BinHEcApCR717qlyL2Bt1h6uGr2YEzhhpUjddTOWindPOVJnF-uPdnpMqMVmbgKK1NyDDZkGpJ1P9T7RCjXg_o7qQXOWsbSlJCds1E6UjMV)

![](https://lh5.googleusercontent.com/zl2WAj6VAwJ0M-8AlszLs0bZpcrvy99ooTzxTcem97aXiUyUwk5UJxfTEYO20z_AVoiBkO0rKhDQ5Ph8O-sWxEJWv59ooUg1bBVY_6DgsiGWm9AtK6q0LShE-xD1DVkTVJzVxv4P)

4.  I have handled the commands in such a way that they can take multiple files to be deleted - 

![](https://lh3.googleusercontent.com/KdRi7-Mwlj3oLQtBknyd-03bKD1gECxHTGXbx8Vwb_NYwOlYCxxa5gGtqZmwPTYS-ck8iCrCobwumBKwmRPmOfF0byaN-zDCgsjUbKlNmU6EiPJinOkbndyNZvnLZkPl2o3UCGc9)

e.  mkdir - It is used to make directories in the system. 

Flags used 

1.  '-v'

-   This flag prints a message every time a directory is created. If the directory already exists, it also prints that. 

-   I have used the c function mkdir() to create directories 

-   I have handled the multiple file condition as well as the file name with spaces in it. 

2.  '-p'

-   This flag is used to make directories recursively one within the other. The outer directory is called the parent directory. 

-   In case the parent directory already exists it doesn't display any error. 

-   I have used the c function mkdir() to create directories. After creating the parent directory I go into it using chdir() and create a new directory in it and so on. 

-   At the end I return back to the parent directory in which I was actually present at the beginning.

Test case

![](https://lh4.googleusercontent.com/KVZVMUVMxdJxV74ag_Z865GP5BHD924R8Okh1Df39JJFefG1AM8gzIROx0Q2knD7ott2VSquKmysP3hn-qsqCnm8_m79aDnEisO6EzQJEYY7S_9V6uOmsNWipUCBS7fUGKbZFzjE)

It shows the various cases of -v and -p flags. 

It also shows the error messages when the directory already exists or when the arguments aren't valid.

Error handling and corner cases

1.  When the name of the file contains spaces in it.

I have used  '\' as the delimiter to consider spaces . A file named "q w" can also be written as q\ w and would be considered a single file with a space in it.

I have also handled multiple file case. Hence the user can enter more than one file.

![](https://lh4.googleusercontent.com/QSn7ZVxKvMK3kOo41V7kAxx-3GgwdMAvM6ACmS1Rrus28eUEsSVcbQc7xk6E003YcT9arq4Sn3X3J4AdGpu_hBVB1tppoaHfzMTIpfakWlTQXa0e1ZULgA7aCdcpWUGs0JS1DsuU)

![](https://lh5.googleusercontent.com/tsRsvrkBTPKtEvvvGCSAkj3Oc9Bv4liiprdEdHlnmIfsxd4wZ_WUQ2I6cP8HmoKX1ocf1PAXYbkLH1nhmiHFS-Vy4VOvn5-ySdYzbyWdONJ68dmi6jS2MIlSTieEHn3j3dqI0ECi)

![](https://lh6.googleusercontent.com/69oVZuWset0oKoDS8H2E-XOsAOQ45EStW6_aDYTmVunf9S1lMKVVIY5WvAhh6Cvkhrn_kUScUPSSSH2vBr3zIr7I3v_JnsVikbWGQbBuoSLmMhPwYi4zfXp4KH5cxLqF6KXi1o-1)

2.  In case the directory already exists, mkdir gives a warning that the file already exists. In case of -p if the parent directory exists, it doesnt give an error and uses that directory itself.

![](https://lh5.googleusercontent.com/CRbMdTqTtZOSGYJexYMl5mvPTnnfKHt9R3645UPEdAkYRaes3UOBsdXJTGXayEKsOYi9rv4HjWIW55GXAexae-LUsD5AQCTdTyzTvQcvxywMrPDZLts3D-IypaVsG7Bkl_i8ZgOz)

3.  In case the user doesn't enter the correct set of arguments  or doesn't enter the correct flag then the "invalid arguments " error is displayed.

![](https://lh4.googleusercontent.com/j4cymZRNyzyEI02yDn4MyIDncXxwTroSRc2o0PzoVEQP0szIEyQoowwU_cWgq8hMzKxxhrdoGAGjf-C49CWirvrcu2eZYxhdpFYJMOUlWsjzmO1i3Mhe5ybJPDc0R96emoaCufcF)
