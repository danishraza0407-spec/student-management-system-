#include<iostream>
#include<fstream>
using namespace std ;
class student
{
    private:
    char name[100];
    int roll_no ;
    int marks ;
    public:
    void getdata()
    {
        
        cout<<"enter the roll no. :";
        cin>>roll_no;
        cin.ignore();
        cout<<"enter the name of student :"<<endl;
        cin.getline(name,100);
        cout<<"enter the total marks :";
        cin>>marks;
    }
    void display()
    {
        cout<<"your roll no. :"<<roll_no<<endl;
        cout<<"your name is :"<<name<<endl;
        cout<<"total marks is :"<<marks<<endl;
    }
    int get()
    {
        return roll_no;
    }
};
void addstudent();
void showall();
void search(int a);
int main()
{
    int n;   
    do
    {
        cout<<"\n\n ------welcome to student data------\n\n";
        cout<<"1. add the new student "<<endl;
        cout<<"2. show the all studet "<<endl;
        cout<<"3. find the student using roll number "<<endl;
        cout<<"4. exit"<<endl;
        cout<<"enter the number when you want :";
        cin>>n;
        switch(n)
        {
            case 1:
                addstudent();
                break;
            case 2:
                showall();
                break;
            case 3:
                int x;
                cout<<"enter the roll number :";
                cin>>x;
                search(x);
                break;
            default:
                cout<<"enter valid number " ;       
        }

    } while (n != 4);
    
    return 0;
}
void addstudent()
{
    student s;
    ofstream out("student.dat",ios :: binary | ios :: app);
    s.getdata();
    out.write((char*)&s ,sizeof(s));
    out.close();
    cout<<"---student add successfully-----"<<endl;

}
void showall()
{
    student s;
    ifstream in("student.dat",ios ::binary);
    while(in.read((char*)&s ,sizeof(s)))
    {
        s.display();
    }
    in.close();
}
void search(int a)
{
    student s;  
    ifstream in("student.dat",ios :: binary);
    bool found = false;
    while(in.read((char*)&s , sizeof(s)))
    {
        if(s.get()==a)
        {
            s.display();
            found = true;
            break;

        }

    }
    in.close();   
    if(!found)
    {
        cout<<"not data is found";
    }
    
}