// TCP server code for chatting application 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include<pthread.h>

#define MAX 100
#define PORT 8080

// func to chat between client and server

static void *read_thread(int connfd)
{
	// read the buffer and print the data                   
	// edit
	int flag =1;


	char buff[MAX];
	memset(buff, '\0', MAX);
//	memset(len, '\0', sizeof(len));

	// read the length of data recieved and store in len buffer
	//int len;
/*
	if((read(connfd, len, sizeof(len))) == -1 )
	{
		printf("failed to read the length\n");
	}
*/
	/*
	   if(*len < MAX)
	   {
	   printf("the length of data recieved = %d\n", *len);
	   }
	 *len = 0;
	 */

	// read the msg and store it in buffer
	if((read(connfd, buff, MAX)) == -1)
	{
		printf("failed to read from client \n");
		//free(len);
		close(connfd);
		//infi_flag = 0;
		exit(0);
		//printf("exiting...\n");
	}
/*
	// if recieved empty buffer switch to write mode
	if(strlen(buff) == 1)
	{
		flag = 0;
		break;
	}

	// if we write bye to buffer the chat is ended
	if(! strncmp("bye", buff, 3))
	{
		printf("Chat exited...!\n");
		free(len);
		close(connfd);
		exit(0);
	}
*/

	printf("Client : %s\n", buff);
	//read the buffer and print end
	//edit
}

static void *write_thread(int connfd)
{

	printf("\nServer : ");
	char buff[MAX];
	memset(buff, '\0', sizeof(buff));

	// take input and store in buffer
	int i=0, flag =1;
	while((buff[i++] = getchar()) != '\n')
		;
	buff[i] = '\0';


	// claculate buffer length and write 
	//bufflen = i-1;
	//printf("bufflen = %d\n", bufflen);

	//	*len = bufflen;
/*
	if((write(connfd, len, sizeof(len))) == -1)
	{
		printf("failed to write length\n");
	}
*/
	/*
	 *len = 0;
	// if msg is more than buffer size print error msg and clear buffer
	if(bufflen > MAX)
	{
	printf("msg size exceeded...!\n");
	memset(buff, '\0', MAX);
	}
	*/

	// write the msg stored in buffer
	if((write(connfd, buff, sizeof(buff))) == -1)
	{
		printf("failed to write \n");
//		free(len);
		close(connfd);
		//infi_flag = 0;
		exit(0);
		//printf("exiting...\n");
	}

	// if buffer is empty switch to read mode
/*	if(strlen(buff) == 1)
	{
		flag = 1;
		break;
	}
*/
	// if we write bye to buffer the chat is ended
/*	if(! strncmp("bye", buff, 3))
	{
		printf("Chat exited...!\n");
		free(len);
		close(connfd);
		exit(0);
	}
*/
}

void chat_func(int connfd)
{	
	int current_size = 0;

	char buff[MAX];
	//int len;
	//int *len;

	/*
	   len = (int *)malloc(sizeof(int));

	   if (len == NULL)
	   {
	   printf("failed to allocate memory..\n");
	   close(connfd);
	   exit(0);
	   }
	   */
	int flag = 1;
	int infi_flag = 1;

	printf("\n************ TCP Server *************\n");

	printf("Chat rules : \n 1) Send an empty message when you are done sending messages.\n 2) send 'bye' to exit the chat.\n\n ");


	while(infi_flag) 
	{
		while(flag == 1)
		{       /*
			// read the buffer and print the data 			


			memset(buff, '\0', MAX);
			memset(len, '\0', sizeof(len));

			// read the length of data recieved and store in len buffer
			//int len;

			if((read(connfd, len, sizeof(len))) == -1 )
			{
			printf("failed to read the length\n");
			}

			if(*len < MAX)
			{
			printf("the length of data recieved = %d\n", *len);
			}
			 *len = 0;

			// read the msg and store it in buffer
			if((read(connfd, buff, MAX)) == -1)
			{
			printf("failed to read from client \n");
			free(len);
			close(connfd);
			//infi_flag = 0;
			exit(0);
			//printf("exiting...\n");
			}

			// if recieved empty buffer switch to write mode
			if(strlen(buff) == 1)
			{
			flag = 0;
			break;
			}

			// if we write bye to buffer the chat is ended
			if(! strncmp("bye", buff, 3))
			{
			printf("Chat exited...!\n");
			free(len);
			close(connfd);
			exit(0);
			}


			printf("Client : %s\n", buff);

			}
		// while end read mode
		*/

		// while start of write mode
		while(flag == 0)
		{	
			/*
			   memset(buff, '\0', sizeof(buff));

			   printf("\nServer : ");

			   int bufflen;

			// take input and store in buffer
			int i=0;
			while((buff[i++] = getchar()) != '\n')
			;	
			buff[i] = '\0';


			// claculate buffer length and write 
			bufflen = i-1;
			//printf("bufflen = %d\n", bufflen);

			 *len = bufflen;

			 if((write(connfd, len, sizeof(len))) == -1)
			 {
			 printf("failed to write length\n");
			 }

			 *len = 0;

			// if msg is more than buffer size print error msg and clear buffer
			if(bufflen > MAX)
			{
			printf("msg size exceeded...!\n");
			memset(buff, '\0', MAX);
			}	

			// write the msg stored in buffer
			if((write(connfd, buff, sizeof(buff))) == -1)
			{
			printf("failed to write \n");
			free(len);
			close(connfd);
			//infi_flag = 0;
			exit(0);
			//printf("exiting...\n");
			}

			// if buffer is empty switch to read mode
			if(strlen(buff) == 1)
			{
			flag = 1;
			break;
			}

			// if we write bye to buffer the chat is ended
			if(! strncmp("bye", buff, 3))
			{
			printf("Chat exited...!\n");
			free(len);
			close(connfd);
			exit(0);
			}
			*/
		}
	}
//	free(len);
}


int main()
{
	int sockfd, connfd;
	socklen_t len;	
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		printf("socket creation failed...\n");
		close(sockfd);
		exit(0);
	}
	else
		printf("Socket successfully created..\n");

	memset(&servaddr, '\0', sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	// long integer from host byte order to network byte order.
	servaddr.sin_port = htons(PORT);	// short integer from host byte order to network byte order.

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		close(sockfd);
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// server listens
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		close(sockfd);
		exit(0);
	}
	else
		printf("Server listening..\n");

	len = sizeof(cli);

	// Accept the data from client
	connfd = accept(sockfd, (struct sockaddr*)&cli, &len);

	if (connfd < 0) {

		printf("server accept failed...\n");
		close(sockfd);
		exit(0);
	}
	else
		printf("server accepted the client...\n");
	// Function to chat between client and server
	chat_func(connfd);

	// After chatting close the socket
	close(sockfd);
}

}
