#include <iostream>
#include <string>
using namespace std;
static int global_count=0;
class room
{
    //student details
    private:
    string name , address , father , email, femail ;
    long roll_no , phone , fphone;
    
    //room details
    int roomn,avability;

 
    public:
    //deafault constructor
    room()
    {
        if (global_count<=20)
        {
          global_count+=1;
          roomn=global_count;
        }
        if (global_count>=20)
        {
          global_count=100+(global_count-20);
          roomn=global_count;
        }
        avability=0;
       

    }

};

int main()
{
    room a;
    return 0;
}
