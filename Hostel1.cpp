#include <iostream>
#include <string>
using namespace std;
static int global_count=100;
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
        if (global_count<=120)
        {
          global_count+=1;
          roomn=global_count;
        }
        if (global_count>=120)
        {
          global_count=100+(global_count-120);
          roomn=global_count;
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
    int no_floor , no_room;
    cout<<"enter the number room on each floor ";
    cin>>no_room;
    cout<<"enter the number of floors";
    cin>>no_floor;
    room* Room=new room[no_room*no_floor];
    Room[2].display();
    return 0;
}
