#include <iostream>
#include <string>
#include <fstream>

using namespace std;

static int global_count=1;
static int global_count2=1;

class room
{

    //student details
    private:
    string name , address , father , email, femail ;
    long enroll , phone , fphone;
    
    //room details
    int roomn,avability;

 
    public:
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

    }
    //Function to assign room
    void Assign()
    {
        
        avability=1;

        cout<<" Name of the student\n";
        cin>>name;
        cout<<" Enrollment Number of the student\n";
        cin>>enroll;
        cout<<" Phone number of the student\n";
        cin>>phone;
        cout<<" Address of the student\n";
        cin>>address;
        cout<<" E-mail id of the student\n";
        cin>>email;
        cout<<" father's name of the student\n";
        cin>>father;
        cout<<" Father's E-mail id of the student\n";
        cin>>femail;
        cout<<" Father's Phone Number of the student\n";
        cin>>fphone;


    }


    //search by room number ;
    void roomsearch(int b)
    {
        if(roomn==b)
        {
            display();
        }
    }


    //search  by name
    void namesearch(string b)
    {
        if(name==b)
        {
            display();
        }
    }

    //search  by enrollment
    void enrollsearch(long c)
    {
        if(enroll==c)
        {
            display();
        }
    }


    //functiom to deallocate  room 
    void deallocate()
    {
        cout<<"room is delocated sucessfully";
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
    }


    //function to delist the room 
    void delist()
    {
      cout<<"room is delisted successfully";
      avability=2;
      name="NA";
      address="NA";
      father="NA";
      email="NA";
      femail="NA";
      enroll=0;
      phone=0;
      fphone=0;
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
    int no_floor ,total,i;
    cout<<"enter the number of floors";
    cin>>no_floor;
    room* Room=new room[20*no_floor];
    total=no_floor*20;

//room search
    int desiredroom;
    cout<<"enter the room number you wanna search";
    cin>>desiredroom;
    for(i=0;i<=total;i++)
    {
        Room[i].roomsearch(desiredroom);
    }

//name search
    string desiredname;
    cout<<"enter the Name you wanna search";
    cin>>desiredname;
    for(i=0;i<=total;i++)
    {
        Room[i].namesearch(desiredname);
    }

//enrollment search
    long desiredenroll;
    cout<<"enter the Name you wanna search";
    cin>>desiredenroll;
    for(i=0;i<=total;i++)
    {
        Room[i].enrollsearch(desiredenroll);
    }


   //Room[2].display();

    return 0;
}
