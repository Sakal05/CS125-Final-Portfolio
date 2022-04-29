/*Bus system is divided into 2 main system:
    - Admin system
    - User system
Admin system's feature:
    - Log in or Register
    - Input Bus Data (Bus's ID, Type of Bus, Departure Time, Destination, Bus availability, Seat Availability)
    - Search for BUS Data
    - Edit Bus Data
    - Delete Bus Data (delete by BUS ID. Ex: BUS ID: 0001)
User system's feature:
    - Log in or Register
    - Search for avaiblity:
        + Search by Type of bus
        + Search by Desitination
    - Book the BUS:
        + Input Destination
        + Input number of passenger
        + Departure Date
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main();

//Admin function
void bus_input();
void search_bus_data();
void edit_bus();
void delete_bus();


//User function
void bus_search();
void book_bus();

//global variable as Bool
bool stage; 

//Log in function
void login()
{
        int count;
        
        string user,pass,u,p;
        //system("clear");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
                {
                        count=1;
                        stage = true;
                        system("clear");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nLOGIN SUCCESS";
                cout<< "\nHello"<<user << "\nGlad that you make it here!"
                    << "\nWelcome to Bus System" <<endl;
                cin.get();
                cin.get();      
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                //main();
        }
}

void registr()
{

        string reguser,regpass,ru,rp;
        system("clear");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser <<' '<< regpass <<endl;
        system("clear");
        cout<<"\nRegistration Sucessful\n";
        main();

}

int main()
{
    int choice;
        cout<<"***********************************************************************\n\n";
        cout<<"                         Welcome to BUS System                         \n\n";
        cout<<"***********************************************************************\n\n";
        cout<<"1.ADMIN\n";
        cout<<"2.USER\n";
        cout<<"3.Exit\n";
        cout<<"\nEnter your role : ";
        cin>>choice;
        cout<<endl;

        switch (choice)     //first switch
        {
            
            case 1:
            //Perform log in system
            login();
            
            if (stage == true)
            {
                system("clear");
                //Display Admin's Menu
            cout<<"==================  Admin's Menu  =================="
                <<"\n1. Input New Bus Info"
                <<"\n2. Search for BUS Info"
                <<"\n3. Edit Bus Info"
                <<"\n4. Delete Bus Info" 
                <<"\nEnter your choice: " <<endl;
                switch (choice)     //Second switch
                {
                    case 1:
                    //bus_input();
                    break;
                    
                    case 2:
                    //search_bus_data();
                    break;
                    
                    case 3:
                    //

                }

            }   //end of if condition

            break;

            case 2:
            //Perform log in system
            login();

            if (stage == true)
            {
                system("clear");
                //Display Admin's Menu
            cout<<"==================  User's Menu  =================="
                <<"\n1. Search for Avaible Bus"
                <<"\n2. Book a Bus"
                <<"\n3. Exit/Log out" 
                <<"\nEnter your choice: " <<endl;
                switch (choice)     //Second switch
                {
                    case '1':
                    //bus_input();
                    break;
                }

            } 

            break;
        }
}
