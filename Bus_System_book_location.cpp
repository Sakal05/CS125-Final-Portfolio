#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main();

// global variables
char choice;
string validation;

class a //
{
    int seat_ava, numseat, totalseat;
    int i=0, j;
    int t, r; //for input temporary data into array processing
    int notFound = 0;
    bool stageAdmin, stageUser, rightbus;
    char choice;
    string tempdata[20];


public:
    void AddNewBus();       // add a new bus with its details
    void CheckDataByID();   // find bus data by inputting bus id
    void CheckDataByDest(); // find bus data by inputting travel destination
    void AdminSystem();     // for admins
    void UserSystem();      // for users (costumers)
    void booking_bus_des();
    void Admin_login_menu();
    void Admin_login();
    void Admin_registr();
    void User_login_menu();
    void User_login();
    void User_registr();
};

// declare class object
a aobject;

struct bus // structure to group data types for a new bus
{
    string busid;
    string driver;
    string arrival;
    string departure;
    string to;
    string busid_found;

} busdata;

void a::Admin_login_menu()
{
    cout << "1. Log in" << endl
         << "2. Register" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        Admin_login();
        break;
        
    case '2':
        Admin_registr();
        cout << "Please log in" << endl;
        Admin_login();
        break;
    default:
    {
        cout << "Wrong input" <<endl;

        break;
        
    }
    }
}

// Admin Log in and Registration
void a::Admin_login()
{
    int count;

    string Auser, Apass, Au, Ap;
    // system("clear");
    cout << "Please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> Auser;
    cout << "PASSWORD :";
    cin >> Apass;

    ifstream inputA("Admin_registration_account.txt");
    while (inputA >> Au >> Ap)
    {
        if (Au == Auser && Ap == Apass)
        {
            count = 1;
            stageAdmin = true;
            system("clear");
        }
    }
    inputA.close();
    if (stageAdmin == true)
    {
        cout << "\nLOGIN SUCCESS";
        cout << "\nHello" << Auser << "\nGlad that you are here!"
             << "\nWelcome to Bus System" << endl;
        cin.get();
        cin.get();
    }
    else
    {
        cout << "\nLOGIN ERROR.\nPlease check your username and password again\n";
       
    }
}

void a::Admin_registr()
{

    string Areguser, Aregpass, Aru, Arp;
    system("clear");
    cout << "Enter the Admin username :";
    cin >> Areguser;
    cout << "\nEnter the Admin password :";
    cin >> Aregpass;

    ofstream Areg("Admin_registration_account.txt", ios::app);
    Areg << Areguser << ' ' << Aregpass << endl;
    system("clear");
    cout << "\nRegistration Sucessful\n";
    //main();
}

void a::User_login_menu()
{
    cout << "1. Log in as User" << endl
         << "2. Register as User" << endl;
        //add case 3 to go back
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case '1':
        User_login();
        break;
        
    case '2':
        User_registr();
        cout << "Please log in" << endl;
        User_login();
        break;
    default:
    {
        cout << "Wrong input" <<endl;

        break;
        
    }
    }
}

// User Log in and Registration
void a::User_login()
{
    int count;

    string Uuser, Upass, Uu, Up;
    // system("clear");
    cout << "Please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> Uuser;
    cout << "PASSWORD :";
    cin >> Upass;

    ifstream input("User_registration.txt");
    while (input >> Uu >> Up)
    {
        if (Uu == Uuser && Up == Upass)
        {
            count = 1;
            stageUser = true;
            system("clear");
        }
    }
    input.close();
    if (stageUser == true)
    {
        cout << "\nLOGIN SUCCESS";
        cout << "\nHello" << Uuser << "\nGlad that you are here!"
             << "\nWelcome to Bus System" << endl;
        cin.get();
        cin.get();
    }
    else
    {
        cout << "\nLOGIN ERROR.\nPlease check your username and password again\n";
       
    }
}

void a::User_registr()
{

    string Ureguser, Uregpass, Uru, Urp;
    system("clear");
    cout << "Enter the username :";
    cin >> Ureguser;
    cout << "\nEnter the password :";
    cin >> Uregpass;

    ofstream Ureg("User_registration.txt", ios::app);
    Ureg << Ureguser << ' ' << Uregpass << endl;
    system("clear");
    cout << "\nRegistration Sucessful\n";
    //main();
}

void a::AddNewBus() // not working for C to continue. if cannot fix, move it back to admin case 1
{
    ofstream f1("bus.txt", ios::app);

    for (i = 0; choice != 'f' && choice != 'F'; i++)
    {

        if ((choice == 'c') || (choice == 'C') || (choice == '1'))
        {
            cout << "\nEnter The Following Information\n" << endl;
            cout << "\tBus ID: ";
            getline(cin, busdata.busid);
            
            cout << "\tDriver's Name: ";
            getline(cin, busdata.driver);
            cout << "\tArrival Time: ";
            getline(cin, busdata.arrival);
            cout << "\tDeparture Time: ";
            getline(cin, busdata.departure);
            cout << "\tFrom: Phnom Penh" << endl;
            cout << "\tTo: ";
            getline(cin, busdata.to);

            f1 << busdata.busid << endl
               << busdata.driver << endl
               << busdata.arrival << endl
               << busdata.departure << endl
               << busdata.to << endl;

            cout << "Do You Want Enter More Bus's Data?\n";
            cout << "Press C To Continue Or F To Finish: ";
            choice = getchar();
            cin.clear();
        }
    }
    f1.close();

    cin.clear();
    cin.ignore(100, '\n');
}

void a::CheckDataByID()
{
    string find;
    ifstream f2("bus.txt");

    cout << "Enter A Bus's ID: ";
    getline(cin, find);
    cout << endl;

    for (j = 0; (j < i) || (!f2.eof()); j++)
    {

        getline(f2, busdata.busid);

        if (busdata.busid == find)
        {
            notFound = 1;
            cout << "Bus ID: " << busdata.busid << endl;

            getline(f2, busdata.driver);
            cout << "Driver's Name: " << busdata.driver << endl;
            getline(f2, busdata.arrival);
            cout << "Arrival Time: " << busdata.arrival << endl;
            getline(f2, busdata.departure);
            cout << "Departure Time: " << busdata.departure << endl;
            cout << "From: Phnom Penh" << endl;
            getline(f2, busdata.to);
            cout << "To: " << busdata.to << endl
                 << endl;
        }
    }

    if (notFound == 0)
    {
        cout << "No Record Found" << endl;
    }
    f2.close();

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::CheckDataByDest()
{
    string find;
    ifstream f2("bus.txt");

    cout << "Enter Your Travel Destination: ";
    getline(cin, find);
    cout << endl;

    for (j = 0; (j < i) || (!f2.eof()); j++)
    {
        getline(f2, busdata.busid);
        getline(f2, busdata.driver);
        getline(f2, busdata.arrival);
        getline(f2, busdata.departure);
        getline(f2, busdata.to);

        if (busdata.to == find)
        {
            notFound = 1;

            cout << "Bus ID: " << busdata.busid << endl;
            cout << "Driver's Name: " << busdata.driver << endl;
            cout << "Arrival Time: " << busdata.arrival << endl;
            cout << "Departure Time: " << busdata.departure << endl;
            cout << "From: Phnom Penh" << endl;
            cout << "To: " << busdata.to << endl;
        }
    }

    if (notFound == 0)
    {
        cout << "No Record Found" << endl;
    }
    f2.close();

    cin.clear();
    cin.ignore(100, '\n');
    system("pause");
    system("cls");
}

void a::booking_bus_des()
{
    string find, lookforbus;
    
    ifstream f2("bus.txt");
    cout << "\n\t\t======= Booking ========" <<endl;
    cout << "\n\nEnter Your Travel Destination: ";
   
    getline(cin, find);
   
    
    //show avaible bus(s)
    
    for (j = 0; (j < i) || (!f2.eof()); )
        {
            
            getline(f2, busdata.busid);
            getline(f2, busdata.driver);
            getline(f2, busdata.arrival);
            getline(f2, busdata.departure);
            getline(f2, busdata.to);

            if (busdata.to == find)
            {
                //notFound = 1;
                
                cout << "\n --> " << busdata.busid;
                j++;
                tempdata[t] = busdata.busid;
                t++; 
            }     
             
        }   //end of for loop
    

  
    cout <<endl;
     //book a bus
    //create an array, take all bus that all that location store in array, compare look for bus to busid found in that array
    do {
    cout << "\nChoose which bus you want to book: ";
    cin >> lookforbus;
    for (r=0; r<t; r++)
    {
        if (tempdata[r] == lookforbus)
        {
            rightbus = true;
            break;
        }
        else 
        {
            rightbus = false;
        }
    }

    if (rightbus == true)
    {
        int seat;
        totalseat = (seat=32*j);
        cout << "\nYour are on the right bus." <<endl;
        seatava:
        cout << "\nNumber of seat avaible: " << totalseat << endl;
        cout << "\nPlease choose number seat you wanna book: ";
        cin >> numseat;

        if ( numseat > totalseat)
        {
            cout << "Sorry, no more seat is available." <<endl;
        }
        else 
        {
            totalseat -= numseat;
            cout << "Book Succesfully.";
            cout << "Choose 'Y' to continue booking, Choose 'N' return to User Menu" << endl; 
            cin >> choice;
            switch (choice)
            {
                case 'Y':
                case 'y':
                goto seatava;
                break;
                case 'N':
                case 'n':
                UserSystem();
                break;
            }
        }
    }

    else 
    {
        cout << "Your are on the wrong bus." <<endl;
        
    }
    cin.clear();
       }//end while loop
    while (true);

       

    
    f2.close();

    cin.clear();
    cin.ignore(100, '\n');
    system("read");
    system("clear");
}

void a::AdminSystem()
{
    aobject.Admin_login_menu();
    if (stageAdmin == true)

    {
    do
    {
        cout << "\nAdmin System:\n\n"
                "\t[1] Add A New Bus's Data\n"
                "\t[2] Check Database\n"
                "\t[3] Update Database\n"
                "\t[4] Delete Database\n"
                "\t[B] Back To The MAIN MENU\n"
                "\nYour Choice: ";
        getline(cin, validation); // accept entered input as validation variable
        system("cls");

        if (validation.size() == 1) // accept validation with only 1 character
        {
            choice = validation[0]; // let role equal to the inputted validation

            switch (choice)
            {
            case '1':
            {
                aobject.AddNewBus();
            }
                continue;

            case '2':
            {
                aobject.CheckDataByID();
            }
                continue;

            case '3':
                cout << "\n\n";
                cin.clear();
                cin.ignore(100, '\n');
                system("pause");
                break;

            case 'B':
            case 'b':
                main();
                break;

            default:
                cout << "\nSorry, invalid input.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

        else
        {
            cout << "\nSorry, invalid input.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);
    } //end of if condition

    else {
        AdminSystem();
    }
}   //end of funciton

void a::UserSystem()
{

    aobject.User_login_menu();
    if (stageUser == true)
    {
    do
    {   
        
        cout << "\nUser System:\n\n"
                "\t[1] Search For Available Buses\n"
                "\t[2] Book A Bus\n"
                "\t[B] Back To The MAIN MENU\n"
                "\nYour Choice: ";
        getline(cin, validation); // accept entered input as validation variable
        system("cls");

        if (validation.size() == 1) // accept validation with only 1 character
        {
            choice = validation[0]; // let role equal to the inputted validation

            switch (choice)
            {
            case '1':
            {
                while (true)
                {
                    cout << "\nSelect Your Searching Method:\n"
                            "\t[1] By Bus ID\n"
                            "\t[2] By Your Destination\n"
                            "\t[B] Back to User System\n"
                            "\nYour Choice: ";
                    getline(cin, validation); // accept entered input as validation variable
                    system("cls");

                    if (validation.size() > 0 && validation.size() < 2) // accept validation with only 1 character
                    {
                        choice = validation[0]; // let role equal to the inputted validation

                        switch (choice)
                        {
                        case '1':
                        {
                            aobject.CheckDataByID();
                        }
                            continue;

                        case '2':
                        {
                            aobject.CheckDataByDest();
                        }
                            continue;

                        case 'B': // not working. if cannot fix, remove case 'b' & 'B'
                        case 'b':
                            break;

                        default:
                            cout << "\nSorry, invalid input.\n\n";
                            system("pause");
                            system("cls");
                            break;
                        }
                    }

                    else
                    {
                        cout << "\nSorry, invalid input.\n\n";
                        system("pause");
                        system("cls");
                    }
                }
                cin.clear();
                cin.ignore(100, '\n');
                system("pause");
                break;
            }
                continue;

            case '2':
                booking_bus_des();
                cin.clear();
                cin.ignore(100, '\n');
                system("read");
                break;

            case 'b':
            case 'B':
                main();
                break;

            default:
                cout << "\nSorry, invalid input.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

        else
        {
            std::cout << "\nSorry, invalid input.\n\n";
            system("pause");
            system("cls");
        }
    } while (true);
    }   //end of if condition
    else{
        UserSystem();
    }
}   //end of usersystem function



int main()
{
    do
    {
        cout << "\nMAIN MENU\n\n"
                "\nPlease select your role:\n\n"
                "\t[1] Admin\n"
                "\t[2] User\n"
                "\t[E] Exit\n"
                "\nYour Choice: ";
        getline(cin, validation); // accept entered input as validation variable
        system("cls");

        if (validation.size() == 1) // accept validation with only 1 character
        {
            choice = validation[0]; // let role equal to the inputted validation

            switch (choice)
            {
            case '1':
                aobject.AdminSystem();
                cin.clear();
                cin.ignore(100, '\n');
                system("pause");
                break;

            case '2':
                aobject.UserSystem();
                cin.clear();
                cin.ignore(100, '\n');
                system("pause");
                break;

            case 'E':
            case 'e':
                cout << "< You Have Successfully Logged Out Of The System >\n"
                     << "< Thank You And Please Visit Us Again! >\n"
                     << "< Created By Layheng Hok & Sakal Samnang >\n";
                exit(0);
                break;

            default:
                cout << "\nSorry, invalid input.\n\n";
                system("pause");
                system("cls");
                break;
            }
        }

        else
        {
            cout << "\nSorry, invalid input.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);

    return 0;
}