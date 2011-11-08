This file should contain:

  - John Terzis
  - jt2514
  - 5









    1 30609 30384 30358 ?           -1 Sl   13598   0:16 gnome-terminal
30609 30614 30384 30358 ?           -1 S    13598   0:00  \_ gnome-pty-helper
30609 30615 30615 30615 pts/31    2422 Ss   13598   0:00  \_ bash
30615  2422  2422 30615 pts/31    2422 S+   13598   0:00  |   \_ ./mdb-lookup-server-nc-2 2161
 2422  2427  2422 30615 pts/31    2422 S+   13598   0:00  |       \_ /bin/sh ./mdb-lookup-server-nc.sh 2161
 2427  2431  2422 30615 pts/31    2422 S+   13598   0:00  |           \_ cat mypipe-<30615>
 2427  2432  2422 30615 pts/31    2422 S+   13598   0:00  |           \_ nc -l 2161
 2427  2433  2422 30615 pts/31    2422 S+   13598   0:00  |           \_ /bin/sh ./mdb-lookup-cs3157 mdb-cs3157
 2433  2434  2422 30615 pts/31    2422 S+   13598   0:00  |               \_ /home/jae/cs3157-pub/bin/mdb-lookup /home/jae/cs3157-pub/bin/mdb-cs3157
30609  4240  4240  4240 pts/20    4240 Ss+  13598   0:00  \_ bash
 

Shell Scripts
 \_ /bin/sh ./mdb-lookup-cs3157 mdb-cs3157
\_ /bin/sh ./mdb-lookup-server-nc.sh 2161


