#include "207layer.h"


int cmpe207_listen(int sockfd, int backlog)
{
	char* msg = "server";

	int current_state = CB[sockfd].tcp_state;

//error checking: check sockfd IN USE, in CLOSED state
	if(!CB[sockfd].sock_in_use)
		die("listen(): socket not in use.");
	if(!check_state(sockfd, "CLOSED"))
		die("listen(): not in CLOSED state.");

	CB[sockfd].queue_size = backlog;

	CB[sockfd].tcp_state = get_tcp_state(current_state, 0 , msg);

	current_state = CB[sockfd].tcp_state;

	printf("listen: current state = %s\n", (char *)get_state_name(current_state));
}

