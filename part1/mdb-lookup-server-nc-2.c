
/*
 * mdb-lookup-server-nc-2.c
 * create multiple instances of mdb-lookup-server using netcat and system calls
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char **argv)
{

char port[6];    //port number can be up to 65xxx digits plut '\0' , so 6 bytes in total
printf("port number: ");
memset(port,'0',6);
while(fgets(port,sizeof(port),stdin)!=NULL)  //read port number from stdin. newline char copied and '\0' appended by default
{
	
//might need to remove newline char from port

//hitting enter (newline) should prompt user again

pid_t mypid = 0;

if(port[0]=='\n') 

{printf("port number: ");
	while(((mypid=waitpid((pid_t)-1, NULL, WNOHANG)) != -1) && (mypid!= 0))
	{
	fprintf(stderr, "[pid=%d] ", (int)mypid);
	fprintf(stderr, "mdb-lookup-server terminated\n");
	}	
       
	continue;}

/*unnecessary since we are using port number from stdin
    if (argc != 2) {
	fprintf(stderr, "usage: %s <port>\n", argv[0]);
	exit(1);
    }
*/


    pid_t pid = fork();
    if (pid < 0) {
	die("fork failed");
    } else if (pid == 0) {
	// child process
	fprintf(stderr, "[pid=%d] ", (int)getpid());
	fprintf(stderr, "mdb-lookup-server started on port %s with child process id %d \n", port,(int)getpid());
	execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", 
		port, (char *)0);
	
	die("execl failed");
    } else {
	// parent process
	
	while(((pid=waitpid((pid_t)-1, NULL, WNOHANG)) != -1) && (pid!= 0))
	{
	fprintf(stderr, "[pid=%d] ", (int)pid);
	fprintf(stderr, "mdb-lookup-server terminated\n");
	}	
	
	if ((pid=waitpid((pid_t)-1, NULL, WNOHANG)) == -1)
		
	    die("waitpid failed"); 
	
	if(pid==0){sleep(1); printf("port number: "); memset(port,'0',6); continue;} //if no child immediately available restart loop
	
	//o/w pid == value and thus one of the child processes has changed status, print them below
	
    }

sleep(1); 
printf("port number: ");
memset(port,'0',6);   //rest port to blank

}

    return 0;
}


