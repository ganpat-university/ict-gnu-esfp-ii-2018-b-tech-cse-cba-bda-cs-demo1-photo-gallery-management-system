#include<iostream>
#include<cstring>
#include<string.h>
#include<iomanip>
#include<fstream>
#include<ctime>
#include<stdlib.h>
using namespace std;

struct customer{
      int photo_id;
      char photo_name[100];
      char date_clicked[100];
      int photo_size;
      int no_of_copy_needed;
      char album_needed[100];
      char frame_needed[100];
      char photographer_name[100];
      char photo_type[100];
      int d;
      int m;
      int y;
}obj_customer[15];

class gallery
{
public:
    int input()
    {
        ifstream file1,file2,file3,file4,file5,file6,file7,file8,file9,file10,file11,file12;
        file1.open("photo_id.txt");
        file2.open("photo_name.txt");
        file3.open("photo_size.txt");
        file4.open("no_of_copy_needed.txt");
        file5.open("photo_type.txt");
        file6.open("date_clicked.txt");
        file7.open("album_needed.txt");
        file8.open("frame_needed.txt");
        file9.open("photographer_name.txt");
        file10.open("delivery_date.txt");
        file11.open("delivery_month.txt");
        file12.open("delivery_year.txt");

        choose: //for goto statement
        int enter;
        cout<<"ENTER 1 TO ENTER DATA MANUALLY \nENTER 2 TO GET DATA FROM DATABASE\nCHOOSE : ";
        cin>>enter;

        if (enter==1) //condition for entering data manually
        {
            for(int i=1;i<=15;i++)
            {
               cout<<"For Customer No."<<i<<endl;
               cout<<"Enter Photo ID : ";
               cin>>obj_customer[i].photo_id;
               cout<<"Enter Photo Name : ";
               cin>>obj_customer[i].photo_name;
               cout<<"Enter Photo size(MB) : ";
               cin>>obj_customer[i].photo_size;
               cout<<"Enter No. Photo Copy Needed : ";
               cin>>obj_customer[i].no_of_copy_needed;
               cout<<"Enter Photo type(school,family,group) : ";
               cin>>obj_customer[i].photo_type;
               cout<<"Enter Photo Clicked Date : ";
               cin>>obj_customer[i].date_clicked;
               cout<<"Do Album Needed?(yes/no) : ";
               cin>>obj_customer[i].album_needed;
               cout<<"Do Frame Needed?(yes/no) : ";
               cin>>obj_customer[i].frame_needed;
               cout<<"Enter Photographer Name : ";
               cin>>obj_customer[i].photographer_name;
               cout<<"Enter Photo Delivery Date  (DD/MM/YYYY) /n DD:";
               cin>>obj_customer[i].d;
               cout<<" /n MM";
               cin>>obj_customer[i].m;
               cout<<" /n YYYY";
               cin>>obj_customer[i].y;

            }
        }

        else if (enter==2) //condition to get data from database
         {
            for(int i=1;i<=15;i++)
            {
               file1>>obj_customer[i].photo_id;
               file2>>obj_customer[i].photo_name;
               file3>>obj_customer[i].photo_size;
               file4>>obj_customer[i].no_of_copy_needed;
               file5>>obj_customer[i].photo_type;
               file6>>obj_customer[i].date_clicked;
               file7>>obj_customer[i].album_needed;
               file8>>obj_customer[i].frame_needed;
               file9>>obj_customer[i].photographer_name;
               file10>>obj_customer[i].d;
               file11>>obj_customer[i].m;
               file12>>obj_customer[i].y;
            }
         }

         else
         {
             cout<<"Choose Correct Option !"<<endl;
             goto choose;
         }

        file1.close();
        file2.close();
        file3.close();
        file4.close();
        file5.close();
        file6.close();
        file7.close();
        file8.close();
        file9.close();
        file10.close();
        file11.close();
        file12.close();
    }

    int head()
    {
        cout<<"\n\t\t\t***********************************";
	cout<<"\n\t\t\t* Photo Gallery Management System *";
	cout<<"\n\t\t\t***********************************";
	cout<<"\n\t\t\t\tMade By:";
	cout<<" CS-7,8,9";
	cout<<"\n\n\t\t\t    Press any key to continue!!\n\n\n";
	getchar();
    }

    int show()
    {
        goback: //for goto statement
        cout<<"\n\t\t\t***********************************";
	    cout<<"\n\t\t\t* ----------MAIN MENU------------ *";
	    cout<<"\n\t\t\t***********************************\n";
        cout<<"1. Display all the customers who require photo_album. \n2. Display all the attributes of all those photos whose size is less than 500Mb. \n3. Display all the photos whose delivery_date is before next seven days.\n4. Display all the photos names which fall under the category of family photo_type. ";
        cout<<"\n5. Display all the attributes of all those photos whose are clicked by the photographer named 'John'. \n6. Display all the photos whose no_of_copies_needed is greater than 50. \n7. Display all the photos names which are clicked today. \n8. Display all the attributes of all the photos sorted in descending order as per photo_id latest to earliest. \n9. Display All Attributes."<<endl;
        int menu_choice;
        cout<<"Enter Choice : ";
        cin>>menu_choice;
        cout<<endl;

       switch(menu_choice)
      {
    case 1:
           for(int i=1;i<=15;i++)
         if (strcmp(obj_customer[i].album_needed,"yes")==0)
         {
            cout<<"Customer"<<i<<endl;
         }
              break;

    case 2:
           for(int i=1;i<=15;i++)
            if(obj_customer[i].photo_size<500)
           {
                cout<<"Customer"<<i<<" Photo ID: ";
                cout<<obj_customer[i].photo_id<<endl;
                cout<<"Customer"<<i<<" Photo Name: ";
                cout<<obj_customer[i].photo_name<<endl;
                cout<<"Customer"<<i<<" Photo Size: ";
                cout<<obj_customer[i].photo_size<<"MB"<<endl;
                cout<<"Customer"<<i<<" No. of Photo Copy needed: ";
                cout<<obj_customer[i].no_of_copy_needed<<endl;
                cout<<"Customer"<<i<<" Photo Type: ";
                cout<<obj_customer[i].photo_type<<endl;
                cout<<"Customer"<<i<<" Photo Clicked On: ";
                cout<<obj_customer[i].date_clicked<<endl;
                cout<<"Customer"<<i<<" Album Needed: ";
                cout<<obj_customer[i].album_needed<<endl;
                cout<<"Customer"<<i<<" Frame Needed: ";
                cout<<obj_customer[i].frame_needed<<endl;
                cout<<"Customer"<<i<<" Photographer Name: ";
                cout<<obj_customer[i].photographer_name<<endl;
                cout<<"Customer"<<i<<" Delivery Date (DD/MM/YYYY)";
                cout<<obj_customer[i].d<<"/"<<obj_customer[i].m<<"/"<<obj_customer[i].y<<endl<<endl;
           }
             break;

    case 3:

      {

int pd,pm,py,nd,nm,ny,sd,sm,sy,i;//p is for present date, s is for after seven days date,n is for present year exact days

cout<<" ENTER TODAY,S DATE (DD/MM/YYYY) \n DD ";
cin>> pd;
cout<<" MM ";
cin>> pm;
cout<<" YYYY ";
cin>> py;

if(py%4==0 & pm==02)
{
    if(pm==02)
    {
       nd=29;
    }
    else if(pm==04 | pm==03 | pm==6 |pm==9 |pm==11)
    {
        nd=30;
    }
    else
    {
        nd=31;
    }

}
else{ if(pm==02)
    {
       nd=28;
    }
    else if(pm==04  | pm==6 |pm==9 |pm==11)
    {
        nd=30;
    }
    else
    {
        nd=31;
    }
    }

if(pd+7 > nd)
{   if(pm==12 )
    {   sm=01;
        sy=py+1;
        sd=pd+7-nd;
    }
    else{
    sd =pd+7-nd;
    sm=pm+1;
    sy=py;
    }

}
else
    {sd=pd+7;
    sm=pm;sy=py;
    }
cout<<"\n Date after seven days is: "<<sd <<"/"<<sm  <<"/"<<sy<<endl;

for(i=1;i<=15;i++)
{
    if(obj_customer[i].y<=sy)
    {
        if(obj_customer[i].m<sm)
        {

            if(obj_customer[i].d > sd)
    {
      cout<<obj_customer[i].photo_name<<endl;
    }
        }
    }
    else
    {
        cout<<"\n NO DELIVERY DATE IS BEFORE NEXT SEVEN DAYS\n";
        break;
    }
    }
        }

        break;


    case 4:
           for(int i=1;i<=15;i++)
         if (strcmp(obj_customer[i].photo_type,"family")==0)
         {
            cout<<obj_customer[i].photo_name<<endl;
         }
             break;

    case 5:
           for(int i=1;i<=15;i++)
         if (strcmp(obj_customer[i].photographer_name,"john")==0)
         {
            cout<<"Customer"<<i<<" Photo ID: ";
            cout<<obj_customer[i].photo_id<<endl;
            cout<<"Customer"<<i<<" Photo Name: ";
            cout<<obj_customer[i].photo_name<<endl;
            cout<<"Customer"<<i<<" Photo Size: ";
            cout<<obj_customer[i].photo_size<<"MB"<<endl;
            cout<<"Customer"<<i<<" No. of Photo Copy needed: ";
            cout<<obj_customer[i].no_of_copy_needed<<endl;
            cout<<"Customer"<<i<<" Photo Type: ";
            cout<<obj_customer[i].photo_type<<endl;
            cout<<"Customer"<<i<<" Photo Clicked On: ";
            cout<<obj_customer[i].date_clicked<<endl;
            cout<<"Customer"<<i<<" Album Needed: ";
            cout<<obj_customer[i].album_needed<<endl;
            cout<<"Customer"<<i<<" Frame Needed: ";
            cout<<obj_customer[i].frame_needed<<endl;
            cout<<"Customer"<<i<<" Photographer Name: ";
            cout<<obj_customer[i].photographer_name<<endl;
            cout<<"Customer"<<i<<" Delivery Date (DD/MM/YYYY)";
            cout<<obj_customer[i].d<<"/"<<obj_customer[i].m<<"/"<<obj_customer[i].y<<endl<<endl;
         }
             break;

    case 6:
             for(int i=1;i<=15;i++)
             if(obj_customer[i].photo_size<500)
             {
                 cout<<obj_customer[i].photo_name<<endl;
             }
             break;

    case 7:
       // cout<<"Enter Today's Date(dd/mm/yyyy): ";
        //char todaysdate[100];
        //cin>>todaysdate;
        {
            ofstream file13;
            file13.open("todaysdate.txt");

            const int MAXLEN = 80;
            char todaysdate[MAXLEN];
            time_t t = time(0);
            strftime(todaysdate, MAXLEN, "%d/%m/%Y", localtime(&t)); //function to fetch current system date.
            file13<<todaysdate;
            file13.close();


               for(int i=1;i<=15;i++)
               {
                  if (strcmp(todaysdate,obj_customer[i].date_clicked)==0)
                     {
                        cout<<" Photo Clicked Today: ";
                        cout<<obj_customer[i].photo_name<<"(Customer"<<i<<")"<<endl;
                     }
               }
             }

             break;

    case 8:


        int temp;
        for(int i=1;i<=15;i++)
        {
        for(int j=i+1;j<=15;j++)
        {
            if(obj_customer[i].photo_id<obj_customer[j].photo_id)
            {
                temp=obj_customer[i].photo_id;
                obj_customer[i].photo_id=obj_customer[j].photo_id;
                obj_customer[j].photo_id=temp;
            }
        }
    }


            for(int i=1;i<=15;i++)
         {
            cout<<" Photo ID: ";
            cout<<obj_customer[i].photo_id<<endl;
            cout<<" Photo Name: ";
            cout<<obj_customer[obj_customer[i].photo_id].photo_name<<endl;
            cout<<" Photo Size: ";
            cout<<obj_customer[obj_customer[i].photo_id].photo_size<<"MB"<<endl;
            cout<<" No. of Photo Copy needed: ";
            cout<<obj_customer[obj_customer[i].photo_id].no_of_copy_needed<<endl;
            cout<<" Photo Type: ";
            cout<<obj_customer[obj_customer[i].photo_id].photo_type<<endl;
            cout<<" Photo Clicked On: ";
            cout<<obj_customer[obj_customer[i].photo_id].date_clicked<<endl;
            cout<<" Album Needed: ";
            cout<<obj_customer[obj_customer[i].photo_id].album_needed<<endl;
            cout<<" Frame Needed: ";
            cout<<obj_customer[obj_customer[i].photo_id].frame_needed<<endl;
            cout<<" Photographer Name: ";
            cout<<obj_customer[obj_customer[i].photo_id].photographer_name<<endl;
            cout<<"Customer"<<i<<" Delivery Date(DD/MM/YYYY): ";
            cout<<obj_customer[obj_customer[i].photo_id].d<<"/"<<obj_customer[obj_customer[i].photo_id].m<<"/"<<obj_customer[obj_customer[i].photo_id].y<<endl<<endl;
         }

             break;




             case 9:
         for(int i=1;i<=15;i++)
         {
            cout<<"Customer"<<i<<" Photo ID: ";
            cout<<obj_customer[i].photo_id<<endl;
            cout<<"Customer"<<i<<" Photo Name: ";
            cout<<obj_customer[i].photo_name<<endl;
            cout<<"Customer"<<i<<" Photo Size: ";
            cout<<obj_customer[i].photo_size<<"MB"<<endl;
            cout<<"Customer"<<i<<" No. of Photo Copy needed: ";
            cout<<obj_customer[i].no_of_copy_needed<<endl;
            cout<<"Customer"<<i<<" Photo Type: ";
            cout<<obj_customer[i].photo_type<<endl;
            cout<<"Customer"<<i<<" Photo Clicked On: ";
            cout<<obj_customer[i].date_clicked<<endl;
            cout<<"Customer"<<i<<" Album Needed: ";
            cout<<obj_customer[i].album_needed<<endl;
            cout<<"Customer"<<i<<" Frame Needed: ";
            cout<<obj_customer[i].frame_needed<<endl;
            cout<<"Customer"<<i<<" Photographer Name: ";
            cout<<obj_customer[i].photographer_name<<endl;
            cout<<"Customer"<<i<<" Delivery Date (DD/MM/YYYY): ";
            cout<<obj_customer[i].d<<"/"<<obj_customer[i].m<<"/"<<obj_customer[i].y<<endl<<endl;
            }

               break;

      }

      cout<<"\nEnter 1 To Go Back To Main Menu \nEnter 2 For Exit\nChoose: ";
      int goback;
      cin>>goback;
      if(goback==1)
        goto goback;
      if(goback==2)
        exit(0);
      else
        return 0;
    }
};

int main()
{
   gallery ob;
   ob.head();
   ob.input();
   ob.show();
}
