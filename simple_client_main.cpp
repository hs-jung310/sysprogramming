#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, int argv[] )
{
  try
    {

      ClientSocket client_socket ( "192.168.125.213", 30000 );

      std::string reply;
      while(true){
        try
        { 
          std::string temp;
          std :: cin >> temp;
          client_socket << temp; // "Test message.";
          client_socket >> reply;
        }
        catch ( SocketException& ) {break;}

        std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
          
      }

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}