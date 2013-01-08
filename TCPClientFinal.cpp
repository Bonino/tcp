/*
 * TCPClientFinal.cpp
 * This file is part of socket
 *
 * Copyright (C) 2013 - Samuele Bonino
 *
 * socket is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * socket is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with socket; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/mylib.h"
#include "include/Address"
#include "include/TCPClient"

int main(int argc, char** argv)
{

	if(argc!=6)
	{
		printf("USAGE: TCPClient my_ip serv_ip my_port serv_port message\n");
		return (-1);
	}

	TCPClient* client;
	char* my_ip;
	char* serv_ip;
	char* message;
	int my_port, serv_port;
	
	my_ip = cpyStr(argv[1]);
	serv_ip = cpyStr(argv[2]);
	
	my_port = atoi(argv[3]);
	serv_port = atoi(argv[4]);

	message = cpyStr(argv[5]);

	client = new TCPClient(my_ip,serv_ip,my_port,serv_port);
	
	if(!client->send_str(message))
	{
		printf("Errore invio\n");
		return (-2);
	}
	printf("Messaggio inviato\n");
	printf("Ho ricevuto: %s\n", client->receive_str());
	
return 0;	
}

