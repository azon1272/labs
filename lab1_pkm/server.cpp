#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>
#include <sstream> 
using namespace std;
/*
1. Обчислення мінімального, максимального та середього арифм значення.

*/
class calculating
{
public:
    string calcul(string input)
    {
        string out ="";
        int min;
        int max;
        int count =0;
        //string res[1024]; 
        string result;
        string temp="";
        float mid;
        int summ=0;
        for (int i =0; i<=input.length();i++)
        {
            if (input[i]==' '|| input[i]=='\0')
            {
                count++;
            }
        }
        int *numb_arr = new int[count];
        count = 0;
        for (int i =0; i<=input.length();i++)
        {
            if (input[i]==' '|| input[i]=='\0')
            {
                //cout<<'u';
                temp+='\0';
                numb_arr[count] = atoi(temp.c_str());
                //cout<<numb_arr[0];
                cout<<numb_arr[count];
                cout<<"+++\n";
                temp ="";
                count++;
            }
            else
            {
                temp+=input[i];
              //  cout<<'x';
            }
        }
        //cout<<"=========================\n";
        min = numb_arr[0];
        max = numb_arr[0];
        for (int j=0;j<count;j++)
        {
            cout<<"lol";
            if (min>= numb_arr[j])
            {
                min = numb_arr[j];
                cout<<"Min = ";
                cout<<min;
                cout<<'\n';
            }
            if (max<=numb_arr[j])
            {
                max = numb_arr[j];
            }
            summ += numb_arr[j];
         //   count++;
        }
        mid = summ/count;
        //cout << min;
        result = IntToString(min);
        result+=" "+IntToString(max)+" "+IntToString(mid);
        cout<<result;
        //sprintf(result,"%d",min);
        //result = itoa(min,res,10);
        //sprintf(result, "%d", min);
        return result+'\n';
        //string [] split = input.Split(new Char [] {' ', ',', '.', ':', '\t' });
    }
    std::string IntToString ( int number )
    {
      std::ostringstream oss;

      // Works just like cout
      oss<< number;

      // Return the underlying string
      return oss.str();
    }
};

int main()
{

    int sock;
    int socknext;
    struct sockaddr_in addr;
    struct sockaddr_in addrnext;
    char buf[1024];
    //cout<<buf;
    int bytes_read;
    calculating a;
    char mesgmy[1024];
    char keyy[]="im immortal \n";
    bool oneb=true;
    string answer;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    socknext = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
    {
        perror("socket");
    } 
    addr.sin_family = AF_INET;
    addr.sin_port =htons(3488);
    inet_aton("127.0.0.1", &addr.sin_addr); 
    addr.sin_addr.s_addr =inet_addr ("127.0.0.1");
    addrnext.sin_family = AF_INET;
    inet_aton("127.0.0.1", &addrnext.sin_addr); 
    addrnext.sin_port = htons(3435);
    addrnext.sin_addr.s_addr =inet_addr("127.0.0.1");
    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
    }


    while(1)
    {
        bytes_read=0;
        bytes_read = recv(sock, buf, 1024, 0);
        buf[bytes_read] = '\0';
        answer = a.calcul(buf);
        copy(answer.begin(), answer.end(), mesgmy);
        mesgmy[answer.size()] = '\0';
        sleep(1);    
        connect(socknext, (struct sockaddr *)&addrnext, sizeof(addrnext));
        send(socknext,mesgmy, sizeof(mesgmy), 0);
    }
    close(sock);
    return 0;
} 

