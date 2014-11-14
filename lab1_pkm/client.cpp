#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <iostream>
#include <cstdio>
#include <arpa/inet.h>
using namespace std;
class myclass
{
   public:
   void sending()
   {
	struct sockaddr_in addr;
	int sock;
        char ms[]="\n";
        char msg1[1024];
        cout<<"Задайте повідомлення  ";
        gets(msg1);
        cout<<msg1;
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(3488);
        //addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        inet_aton("127.0.0.1", &addr.sin_addr);//server_address
        addr.sin_addr.s_addr =inet_addr("127.0.0.1");//server_address
        connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        send(sock, msg1, sizeof(msg1), 0);
        send(sock, ms, sizeof(ms), 0);
        shutdown(sock, 3);
        cout<<"\n"<<"що відпарвлено "<<msg1<<"\n";
   }
        
};
class mynext
{
	public:
	void lis()
        {
	    char buf[1024];
	    int bytes_read;
            int socknext;
            int i=0;
            socknext = socket(AF_INET, SOCK_DGRAM, 0);
           if(socknext < 0)
 	   {
     		perror("socket");
           } 
 	  struct sockaddr_in addrnext;
          inet_aton("127.0.0.1", &addrnext.sin_addr);//client
          addrnext.sin_family = AF_INET;
          addrnext.sin_port = htons(3435);
          addrnext.sin_addr.s_addr = inet_addr("127.0.0.1");//client
           if(bind(socknext, (struct sockaddr *)&addrnext, sizeof(addrnext)) < 0)
    	   {
        		perror("bind");
           }
          while(i!=1)
          {
      	  	bytes_read = recv(socknext, buf, 1024, 0);
          	buf[bytes_read] = '\0';
          	cout<<buf;
                i++;
          }
          shutdown(socknext, 3);
	}
          
        
};
   int main()
  {
  
    	myclass b;
    	b.sending();
    	mynext n;
    	n. lis();
    return 0;
}
