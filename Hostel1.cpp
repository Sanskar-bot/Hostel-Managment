#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

static int global_count=1;
static int global_count2=1;


//index number to value 
int snotoroom(int serialno)
{
        int roomno;
        roomno=100*((serialno/20)+1)+(serialno%20);
        return roomno+1;
}

//room number to index value
int roomtosno(int roomno)
{
        if (roomno >= 101) 
        {
         if (roomno <= 120)
          {
            return roomno - 101;
          } 
        else
        {
            int floorNumber = (roomno - 101) / 20 + 1;
            if(roomno%100==20)
             return (((roomno - 101) + (floorNumber - 1) * 20)%100+((roomno - 101) + (floorNumber - 1) * 20)/10)-1;
            else
             return (((roomno - 101) + (floorNumber - 1) * 20)%100+((roomno - 101) + (floorNumber - 1) * 20)/10);
        }
    } 
    if((roomno%100)>20) 
    {
        return -1; // Handle invalid room numbers
    }
    return 0;
}

//to check every value entered by user
int check(int A,int B)
{
    if((A/100)<=B&&(A%100)<=20)
     return 1;
    else
    return 0;
}


       

class room
{

    //student details
    private:
    string name , address , father , email, femail ;
    long enroll , phone , fphone;
    
    //room details

    public:
    int roomn,avability;
    //deafault constructor
    room()
    {
       
        roomn=(global_count2*100)+global_count;
        global_count+=1;
        if (global_count>20)
        {
            global_count-=20;
            global_count2+=1;
        }
        
       avability=0;
       name="NA";
       address="NA";
       father="NA";
       email="NA";
       femail="NA";
       enroll=0;
       phone=0;
       fphone=0;
       
        
        write();

    }


//writing Data in TXT file
    void write()
     {

     ofstream outfile("Hostel_data.txt", ios::app);

      if (outfile.is_open())
       {
         time_t now = time(0);

    
         tm* local_time = std::localtime(&now);
         outfile<<"Current Date and Time: "
              << (local_time->tm_year + 1900) << '-'
              << (local_time->tm_mon + 1) << '-'
              << local_time->tm_mday << " | "
              << local_time->tm_hour << ':'
              << local_time->tm_min << ':'
              << local_time->tm_sec << '\n';
        outfile <<"Room Number :"<<roomn<<" | Avability :"<<avability<< " | Student Name :"<<name<<" | Student's Enrollment Number :"<<enroll<<" | Student's E-mail ID:"<<email<<" | Address :"<<address<<" | Father's Name :"<<father<<" | Father's Phone Number :"<<fphone<<" | Father's E-mail ID :"<<femail <<"\n" <<endl;
        outfile.close();

       }  

       else
        {

        cout << "\nUnable to open file for appending.\n" << endl;
       }

    }

    void wrrite()
     {

     ofstream outfile("Hostel_data.txt", ios::app);

      if (outfile.is_open())
       {
         time_t now = time(0);

    
         tm* local_time = std::localtime(&now);
         outfile<<"\t\t\t\t\t*******************************************************\t\t\t\t\t\n";
         outfile<<"Current Date and Time: "
              << (local_time->tm_year + 1900) << '-'
              << (local_time->tm_mon + 1) << '-'
              << local_time->tm_mday << " | "
              << local_time->tm_hour << ':'
              << local_time->tm_min << ':'
              << local_time->tm_sec << '\n';
        outfile <<"Room Number :"<<roomn<<" | Avability :"<<avability<< " | Student Name :"<<name<<" | Student's Enrollment Number :"<<enroll<<" | Student's E-mail ID:"<<email<<" | Address :"<<address<<" | Father's Name :"<<father<<" | Father's Phone Number :"<<fphone<<" | Father's E-mail ID :"<<femail <<"\n" <<endl;
        outfile.close();

       }  

       else
        {

        cout << "\nUnable to open file for appending.\n" << endl;
        }
     }

    //Function to assign room
    void Assign()
    {
        
        avability=1;
        cin.ignore();
        cout<<" Name of the student\n";
        getline(cin,name);
        cout<<" Enrollment Number of the student\n";
         cin>>enroll;
        cout<<" Phone number of the student\n";
         cin>>phone;
         cin.ignore();
        cout<<" Address of the student\n";
         getline(cin,address);
        cout<<" E-mail id of the student\n";
         getline(cin,email);
        cout<<" father's name of the student\n";
         getline(cin,father);
        cout<<" Father's E-mail id of the student\n";
         getline(cin,femail);
        cout<<" Father's Phone Number of the student\n";
         cin>>fphone;
        wrrite();
        


    }


    //search by room number ;
    void roomsearch(int b)
    {
       
        if(roomn==b)
        {
            display();
            wrrite();
        }
        
    }


    //search  by name
    int namesearch(string b)
    {
        if(name==b)
        {
            return 1;
        }
        else 
         return 0;
    }

    //search  by enrollment
    int enrollsearch(long c)
    {
        if(enroll==c)
        {
            return 1;
        }
        else 
         return 0;
    }


    //functiom to deallocate  room 
    void deallocate()
    {
        cout<<"room is delocated sucessfully\n";
        avability=0;
        cout<<"avability is updated to 0;";
        name="NA";
        address="NA";
        father="NA";
        email="NA";
        femail="NA";
        enroll=0;
        phone=0;
        fphone=0;
        wrrite();
    }


    //function to delist the room 
    void delist()
    {
      
      avability=2;
      if(avability==2)
        cout<<"room is delisted successfully";
      name="NA";
      address="NA";
      father="NA";
      email="NA";
      femail="NA";
      enroll=0;
      phone=0;
      fphone=0;
      wrrite();
    }



    //function to Relist the room 
    void relist()
    {
      
      avability=0;
      if(avability==0)
        cout<<"Room is Relisted successfully";
     wrrite();
    }


    //function to display room status
    void display()
    {
        if(avability==1)
        {
        cout<<"Room Number :"<<roomn<<"\n";
        cout<<"\t Room Allocation successsfull \n";
        cout<<avability<<"\n";
        cout<<"\n Name of the student\n"<<name;
        cout<<"\n Enrollment Number of the student\n"<<enroll;
        cout<<"\n Phone number of the student\n"<<phone;
        cout<<"\n Address of the student\n"<<address;
        cout<<"\n E-mail id of the student\n"<<email;
        cout<<"\n father's name of the student\n"<<father;
        cout<<"\n Father's E-mail id of the student\n"<<femail;
        cout<<"\n Father's Phone Number of the student\n"<<fphone;
        }
        if(avability==0)
        {
            cout<<"Room Number :"<<roomn<<"\n";
            cout<<"\t This is Room is not allocated to anyone\t\n";
        }
        if(avability==2)
        {
            cout<<"Room Number :"<<roomn<<"\n";
            cout<<"\t This is Room is not Ready for allocation\t \n";
        }

    }

};

int main()
{


 
    int no_floor ,total,i, choice,infi=0;
    cout<<"enter the number of floors:";
    cin>>no_floor;
    room* Room=new room[20*no_floor];
    total=no_floor*20;
while(infi==0)
{
    system("clear");
    cout<<"\t ********\tMENU\t********* \t \n";
    cout<<"1.Allocate Rooms \n";
    cout<<"2.Deallocate Rooms \n";
    cout<<"3.Delist Rooms \n";
    cout<<"4.Relist Rooms \n";
    cout<<"5.Search Rooms \n";
    cout<<"6.Search Student by name \n";
    cout<<"7.Seatch Student by Enrollment nummber \n";
    cout<<"8.Quit";
    cout<<"\n\n\n Enter Your choice\n";
    cin>>choice;
     int roomallo=1;
     long desiredenroll;
     int desiredroom;
     string desiredname;
     int deallo=1,snodeallo;
     int delistr=1,snodelistr;
     int relistr=1,snorelistr;
     int XX=0;
     int YY=0;
     int breakc;
     

    
    switch(choice)
    {


    case 1:
//seat allocation feature
    
    while(roomallo!=0)
    {
        int y, choice2=0;
        system("clear");
      cout<<"\t\t*********Room Allocation************\t\n";
      cout<<"Enter the Room number You wanna allot \n";
      cout<<"0. EXIT\n";
      cin>>roomallo;
      y=roomtosno(roomallo);
       if(check(roomallo,no_floor))
    {
       if(roomallo!=0)
       {
        //switch to handle all 3 kinds of room
      switch(Room[y].avability)
      {
      case 1:
      {
        cout<<"\nRoom No."<<Room[y].roomn<<"  is already allocated to someone \n are you sure you wanna Reallocate it to someoneelse \n1.yes \n2.no";
        cin>>choice2;
        if(choice2==1)
         Room[y].avability=0;
      }
      break;

      case 2:
      {
        cout<<"\nRoom No."<<y<<"  is not ready for allocation \n are you sure you wanna List it back \n1.yes \n2.no";
        if(choice2==1)
         Room[y].avability=0;
      }
      break;

      case 0:
      {
        Room[y].Assign();
      }
      break;

      }
      }

     
    }
    
    else
     cout<<"\nNUMBER entered by you is not correct\n";
    cout<<"Enter Any Number to continue";
    cin>>breakc;
    };
    
    break;


    case 2:
//deallocate a room
    system("clear");
    while(deallo!=0)
    {
        
     cout<<"\nEnter the room number you wanna deallocate \n0. EXIT\n";
     cin>>deallo;
      if(check(deallo,no_floor))
    {
     if(deallo!=0)
     {
        snodeallo=roomtosno(deallo);
        Room[snodeallo].deallocate();
    
     };
     
    }
    
    else
     cout<<"\nnumber entered by you ,is not correct\n";
    };
    cout<<"Enter Any Number to continue";
    cin>>breakc;
     break;


     case 3:
//delist a room
    system("clear");
    while(delistr!=0)
    {
        
     cout<<"\nEnter the room number you wanna delist \n0. EXIT\n";
     cin>>delistr;
     if(check(delistr,no_floor))
    {
     if(delistr!=0)
     {
        snodelistr=roomtosno(delistr);
        cout<<snodelistr;
        Room[snodelistr].delist();
    
     };
     
    }
    
    else
     cout<<"\nnumber entered by you ,is not correct\n";
    };
    cout<<"Enter Any Number to continue";
    cin>>breakc;
     break;
    

    case 4:
//relist
     system("clear");
    while(relistr!=0)
    {
        
     cout<<"\nEnter the room number you wanna Relist \n0. EXIT\n";
     cin>>relistr;
     if(check(relistr,no_floor))
    {
     if(relistr!=0)
     {
        snorelistr=roomtosno(relistr);
        cout<<snorelistr;
        Room[snorelistr].relist();
    
     };
     
    }
    
    else
     cout<<"\nnumber entered by you ,is not correct\n"; 
    };
    cout<<"Enter Any Number to continue";
    cin>>breakc;
    break;





    case 5:
//room search
    system("clear");
    cout<<"\nEnter the room number you wanna search:";
    cin>>desiredroom;
    if(check(desiredroom,no_floor))
    {
    for(i=0;i<total;i++)
    {
        Room[i].roomsearch(desiredroom);
    }
    ;
    }
    
    else
     cout<<"\nnumber entered by you ,is not correct\n";
    cout<<"Enter Any Number to continue";
    cin>>breakc;
    break;


    case 6:
//name search
    system("clear");
    cout<<"\nEnter the Name you wanna search:";
    cin>>desiredname;
    for(i=0;i<total;i++)
    {
        if(Room[i].namesearch(desiredname)==1)
        {
         YY=i;
        cout<<YY;
        }
    }
    if(YY!=0)
    {
        Room[YY].display();
        Room[YY].wrrite();
    }
    else
     cout<<"\nNO Match\n";
    cout<<"Enter Any Number to continue";
    cin>>breakc;
    break;


    case 7:
//enrollment search
   system("clear");
    cout<<"\nEnter the Enrollment Number you wanna search:";
    cin>>desiredenroll;
    for(i=0;i<total;i++)
    {
        if((Room[i].enrollsearch(desiredenroll))==1)
        {
         XX=i;
        cout<<XX;
        }
    }
    if(XX!=0)
    {
        Room[XX].display();
        Room[XX].wrrite();
    }
    else
     cout<<"\nNO Match\n";
    cout<<"Enter Any Number to continue";
    cin>>breakc;
    break;


    case 8:

    infi=1;
    cout<<"\t*********************Thank You For Using Our Services************\t";
    break;

    }
}
    delete[] Room; // Free the memory allocated for Room
    return 0;      // Exit the program
}
;
