#!/bin/bash
#Give shell permission to execute your script using chmod cmd
chmod a+x mdb-lookup-server-nc.sh
#Reference process id with $$
pid=$$
#mypipe is a named pipe
mkfifo mypipe-$pid 
cat mypipe-$pid | nc -l $1 | /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > mypipe-$pid

#once user connecting to our server's port hits ctrl-c, pipe exits loop
#delete mypipe at this point manually
rm mypipe
