
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#define h_addr h_addr_list[0] /* for backward compatibility */

/* ΒΙΚΤΩΡ ΡΟΜΑΝΙΟΥΚ 713242017024 ΕΡΓ1 */

// To start exec - ./socket_client localhost 65530

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int size;
    float a;
    float data;
    int operation;
    int sockfd, portno, n, t, done;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    float mo;
    float *minmax;
    float *minmaxres; // TEST
    float *ayres;

    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("ERROR OPENING SOCKET");
    }
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("Trying to connect...\n");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }

    printf("Connected!");
    printf("What's your desired operation? : 1 - FIND MO\n 2 - MIX_MAX\n 3 - aY \n");
    scanf("%d", &operation);
    if (operation >= 4 || operation < 0)
    {
        printf("You entered wrong operation. Default operation is 1 - FIND MO\n");
        operation = 1;
        send(sockfd, &operation, sizeof(operation), 0);
    }
    else
        send(sockfd, &operation, sizeof(operation), 0);
    printf("What's your Array size? : ");
    scanf("%d", &size);
    printf("What's your A ? \n");
    scanf("%f", &a);
    send(sockfd, &size, sizeof(size), 0);
    send(sockfd, &a, sizeof(a), 0);
    printf("\nEnter your data \n");
    done = 0;
    do
    {
        for (int i = 0; i < size; i++)
        {
            scanf("%f", &data);
            send(sockfd, &data, sizeof(data), 0);
        }
        send(sockfd, &minmax, sizeof(minmax), 0);
        done = 1;
    } while (!done);
    if (operation == 1)
    {
        recv(sockfd, &mo, sizeof(mo), 0);
        printf("Your Result is %f", mo);
    }
    if (operation == 2)
    {
        minmaxres = (float *)malloc(2 * sizeof(float));
        for (int i = 0; i < 2; i++)
        {
            recv(sockfd, &minmaxres[i], sizeof(minmaxres) * 2, 0);
        }
        printf("MIN IS : %f\n", minmaxres[0]);
        printf("MAX IS : %f\n", minmaxres[1]);
    }
    if (operation == 3)
    {
        ayres = (float *)malloc(size * sizeof(float));
        for (int i = 0; i < size; i++)
        {
            recv(sockfd, &ayres[i], sizeof(ayres) * size, 0);
            printf("VALUE [%d] IS : %f\n", i, ayres[i]);
        }
    }
    return 0;
}
