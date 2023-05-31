#include "ClientSocket.h"
#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    cout<<"running....\n";

    ServerSocket server ( 30000 );
    ClientSocket client_socket ( "192.168.0.13", 30000 );
    try{
        while ( true )
        {

        ServerSocket new_sock;
        server.accept ( new_sock );

        try
            {
            while ( true ){
                string data;
                string reply1;
                string reply2;
                string reply3;
                vector<string> data_processing;


                new_sock >> data;
                cout<<data<<"\n";

                string separator = ",";
                int cur_position = 0;
                int position;

                while ((position = data.find(separator, cur_position)) != string::npos) {
                    int len = position - cur_position;
                    string result = data.substr(cur_position, len);
                    //std::cout << result << std::endl;
                    data_processing.push_back(result);
                    cur_position = position + 1;
                }
                string result = data.substr(cur_position);
                data_processing.push_back(result);

                // data_processing.push_back(data.substr(0,2));
                // data_processing.push_back(data.substr(2,2)); // 이부분은 내일 포맷 받고.
                client_socket << data_processing[0];
                client_socket >> reply1;
                if(reply1 =="okay"){
                    client_socket <<data_processing[1];
                    client_socket >> reply3;
                    if(reply3 == "No"){
                        reply2 = "이 책은 불가능합니다.";
                    }
                    else if(reply3 == "okay"){
                        reply2 = "이 책은 가능합니다.";    
                    }
                }
                // if(data == "No"){
                //     client_socket <<data;
                //     client_socket >> reply1;
                //     reply2 = "승인";
                // }
                new_sock << reply2;
                }
            }
        catch ( SocketException& ) {}

        }
        }
    catch ( SocketException& e )
        {
        cout << "Exception was caught:" << e.description() << "\nExiting.\n";
        }

  return 0;

}