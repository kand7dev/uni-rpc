 //author: ΒΙΚΤΩΡ ΡΟΜΑΝΙΟΥΚ //


 To run the Makefile.ask1 exec this command -> make CFLAGS+="-I/usr/include/tirpc -ltirpc" RPCGENFLAGS+="-N" -f Makefile.ask1

 To test the application, start 3 or more separate terminals
 Terminal 1 exec - ./ask1_client localhost  (This is our socket host - rpc client)
 Terminal 2 exec - ./ask1_server (This is our rpc server)
 Terminal 3,4,x exec - /socket_client localhost 65530 (This is our socket client)
 Our program supports multiple clients at once. Feel free to try it out!


