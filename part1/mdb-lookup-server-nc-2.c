
/*
 * mdb-lookup-server-nc-1.c
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

while(fgets(port,sizeof(port),stdin)!=NULL)  //read port number from stdin. newline char copied and '\0' appended by default
{
	
//might need to remove newline char from port



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
	fprintf(stderr, "mdb-lookup-server started on port %s\n", port);
	execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", 
		port, (char *)0);
	die("execl failed");
    } else {
	// parent process
	if (waitpid(pid,
		    NULL, // no status
		    0) // no options
		!= pid)
	    die("waitpid failed");

	fprintf(stderr, "[pid=%d] ", (int)pid);
	fprintf(stderr, "mdb-lookup-server terminated\n");
    }

printf("port number: ");


}

    return 0;
}


