#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}


int main() {
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(8081); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0) {
		printf("cannot listen\n"); 
		exit(0); 
	}
	len = sizeof(cli);
	connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n");
}

// typedef struct s_client {
//     int         fd;
//     int         id;
//     struct s_client *next;
// }               t_client;

// t_client    *g_clients = NULL;
// int         sock_fd, g_id = 0;
// fd_set      curr_sock, cpy_read, cpy_write;
// char msg[42];
// char str[42 * 4096], tmp[42 * 4096], buf[42 * 4096 + 42];

// void fatal() {
//     write(2, "Fatal error\n", strlen("Fatal error\n"));
//     close(sock_fd);
//     exit(1);
// }

// int     push_client(int fd) {
//     t_client *tmp = g_clients;
//     t_client *new = NULL;
//     if (!(new = calloc(1, sizeof(t_client))))
//         fatal();
//     new->id = g_id++;
//     new->fd = fd;
//     new->next = NULL;
//     if (!g_clients)
//         g_clients = new;
//     else {
//         while (tmp && tmp->next)
//             tmp = tmp->next;
//         tmp->next = new;
//     }
//     return (new->id);
// }

// int get_id(int fd) {
//     t_client *tmp = g_clients;
//     while (tmp) {
//         if (tmp->fd == fd)
//             return tmp->id;
//         tmp = tmp->next;
//     }
//     return (-1);
// }

// int get_max_fd() {
//     int max = sock_fd;
//     t_client *tmp = g_clients;
//     while (tmp) {
//         if (tmp->fd > max)
//             max = tmp->fd;
//         tmp = tmp->next;
//     }
//     return max;
// }

// int     remove_client(int fd) {
//     t_client *tmp = g_clients;
//     t_client *del = NULL;
//     int id = get_id(fd);
//     if (tmp && tmp->fd == fd) {
//         g_clients = tmp->next;
//         free(tmp);
//     } else {
//         while (tmp && tmp->next && tmp->next->fd != fd)
//             tmp = tmp->next;
//         del = tmp->next;
//         tmp->next = tmp->next->next;
//         free(del);
//     }
//     return (id);
// }

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
//         exit(1);
//     }
//     // starting the server
// 	struct sockaddr_in servaddr;
//     uint16_t port = atoi(argv[1]);
//     bzero(&servaddr, sizeof(servaddr));
//     servaddr.sin_family = AF_INET;
//     servaddr.sin_addr.s_addr = htonl(2130706433);
//     servaddr.sin_port = htons(port);

//     if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
//         fatal();
//     if (bind(sock_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
//         fatal();
//     if (listen(sock_fd, 0) != 0)
//         fatal();
//     FD_ZERO(&curr_sock);
//     FD_SET(sock_fd, &curr_sock);
//     bzero(&str, sizeof(str));
//     bzero(&tmp, sizeof(tmp));
//     bzero(&buf, sizeof(buf));
//     while (1) {
//         cpy_read = cpy_write = curr_sock;
//         if (select(get_max_fd() + 1, &cpy_read, &cpy_write, NULL, NULL) < 0)
//             continue;
//     }
// }