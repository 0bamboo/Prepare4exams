#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <errno.h>
#include <netinet/in.h>

int		sockfd, max_fd;
int		count = 0;
struct	sockaddr_in servaddr, cli;
int		idx[700000];
char	*msgs[700000];
char	buf_read[7001], buf_write[42];
fd_set	curr, cpy_read, cpy_write;

