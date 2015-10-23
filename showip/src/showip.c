#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

void
showip(const char* hostname, short port)
{
    struct addrinfo hints, *res, *p;
    char ipstr[INET6_ADDRSTRLEN];
    int status;

    /* set hints */
    memset(&hints, 0, sizeof hints);
    hints.ai_family   = AF_UNSPEC;   /* unspecified, so we can get ipv4 and ipv6 */
    hints.ai_socktype = SOCK_STREAM; /* TCP */


    if((status = getaddrinfo(hostname, NULL, &hints, &res)) != 0)
    {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        return;
    }

    printf("IP Addresses for %s\n", hostname);

    for(p = res; p != NULL; p = p->ai_next)
    {
        void* addr;
        char* ipver;

        /* get the pointer to the address itself */
        /* NOTE: Different fields for IPv4 and IPv6 */
        if(p->ai_family == AF_INET)
        {
            struct sockaddr_in* ipv4 = (struct sockaddr_in*) p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else
        {
            struct sockaddr_in6* ipv6 = (struct sockaddr_in6*) p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        /* convert IP to string and print it */
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }

    /* clean up */
    freeaddrinfo(res);
}
