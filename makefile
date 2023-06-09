# Makefile for the socket programming example
#

simple_server_objects = ServerSocket.o Socket.o simple_server_main.o
simple_client_objects = ClientSocket.o Socket.o simple_client_main.o
main_server_objects = ServerSocket.o ClientSocket.o Socket.o main_server.o


all : simple_server simple_client main_server

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects)


simple_client: $(simple_client_objects)
	g++ -o simple_client $(simple_client_objects)

main_server: $(main_server_objects)
	g++ -o main_server $(main_server_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
simple_server_main: simple_server_main.cpp
simple_client_main: simple_client_main.cpp
main_server: main_server.cpp


clean:
	rm -f *.o simple_server simple_client main_server