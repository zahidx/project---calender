#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
 
//prototype declaration of function
int month(int n, int year);
void calender(int year, int row);
void calender_print(int starting, int year);
void add_reminder(int starting, int year);
void update_reminder(int starting, int year);
void delete_reminder(int starting, int year);
void reminder_of_month();
bool star_print(string month,int date);
void lowercase(string& str);
 
 
 
string months[12]= {"january","february","march","april","may","june","july","august","september","october","november","december"};
int dates[30][30];
 
struct reminder
{
    string title;
    string description;
    int date;
    string month;
};
 
list<reminder>reminderlist;
 
 
//function define**********
int month(int n, int year)
{
    if(n==0 || n==2 || n==4 || n==6 || n==7 || n==9 || n==11)
    {
        return 31;
    }
 
    else if(n==1)
    {
      if(year%4==0)
      {
        return 29;
      }
      else
      {
        return 28;
      }
    }
 
    else
    {
        return 30;
    }
}
 
 
void calender(int year, int row)
{
    int i,j;
    for(i=0; i<row; i++)
    {
       for(j=0; j<month(i,year); j++)//month function calling in this line.
       {
            dates[i][j]=j+1;
       }
    }
 
}
 
 
void calender_print(int starting, int year)
{
    cout<<endl <<"\t\t------"<<year<<"------" <<endl;
    string week_days[7]={ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
 
    int counter;
    for(int i=0; i<12; i++)
    {
        counter=0;
        if(starting==7)
        {
            starting=0;
        }
 
        cout<<endl<<"\t\t-----" <<months[i] <<"-----"<<endl;
 
        int m;
        for(m=0; m<7; m++)
        {
            cout<<week_days[m] <<"\t";
        }
        cout<<endl;
 
        for(int j=0; j<6; j++)
        {
            for(int k=0; k<7; k++)
            {
                if(j==0 && k<starting)
                {
                    cout<<"  \t";
                }
                else if(j==0 && k>= starting)
                {
                    if(star_print(months[i],dates[i][counter])==true)
                    {
                        cout<<"*"<<dates[i][counter]<<" \t";
                        counter++;
                    }
                    else
                        {
                            cout<<dates[i][counter]<<"  \t";
                            counter++;
                        }
                }
                else if(j>0)
                    {
                        if(month(i,year)>counter)
                        {
                            if(dates[i][j]<10)
                            {
                                if(star_print(months[i],dates[i][counter])==true)
                                {
                                    cout<<"*"<<dates[i][counter]<<" \t";
                                    counter++;
                                }
                                else
                                {
                                    cout<<dates[i][counter]<<"  \t";
                                    counter++;
                                }
                            }
                            else
                            {
                                if(star_print(months[i],dates[i][counter])==true)
                                {
                                    cout<<"*"<<dates[i][counter]<<"\t";
                                    counter++;
                                }
                                else
                                {
                                    cout<<dates[i][counter]<<" \t";
                                    counter++;
                                }
 
                            }
                        starting = k+1;
                        }
                            else
                                break;
                    }
 
                }
                cout<<endl;
        }
            cout<<endl;
    }
}
 
 
 
void add_reminder(int starting, int year)
{
    cout <<endl <<"----ADD Reminder----" <<endl;
    reminder rem;
    cout<<"Reminder Title: ";
    getline(cin, rem.title);
    cout<<"Reminder Description: ";
    getline(cin, rem.description);
    cout<<"Date: ";
    cin>>rem.date;
    cin.ignore();
    cout<<"Month name: ";
    string month;
    getline(cin, month);
    lowercase(month);//calling function for lowercase convert
    rem.month=month;
    reminderlist.push_back(rem);
    calender_print(starting, year);
 
}
 
void update_reminder(int starting, int year)
{
    cout<<endl <<"----UPDATE Reminder----" <<endl;
    if(reminderlist.empty()==true)
    {
        cout <<endl <<"NO REMINDER LISTED" <<endl;
        return;
    }
    string little, lmonth, ldescription;
    int ldate;
    cout<<"Reminder Title: ";
    getline(cin, little);
    cout<<"Date: ";
    cin>>ldate;
    cin.ignore();
    cout<<"Month: ";
    getline(cin, lmonth);
    lowercase(lmonth);
    for (list<reminder>::iterator it=reminderlist.begin() ; it != reminderlist.end(); ++it)
    {
        if(little==it->title)
           {
                      if(ldate==it->date)
                        {
                            if(lmonth==it->month)
                            {
                                int option;
                                do
                                {
                                    cout <<endl<<"Choose what to update" <<endl <<endl <<"1.Edit Title" <<endl;
                                    cout<<"2.Edit Description" <<endl<<"3.Edit Date"  <<endl <<"4.Edit Month"  <<endl <<"**0.Exit**" <<endl <<"Input: ";
                                    cin>>option;
                                    cin.ignore();
                                    if(option==1)
                                        {
                                            cout <<endl<<"New Reminder Title: ";
                                            getline(cin, little);
                                            it->title=little;
                                        }
                                        else if(option==2)
                                        {
                                                cout <<endl<<"New Description: ";
                                                getline(cin, ldescription);
                                                it->description=ldescription;
 
                                        }
                                        else if(option==3)
                                        {
                                                cout <<endl<<"New Date: ";
                                                cin>>ldate;
                                                cin.ignore();
                                                it->date=ldate;
                                        }
                                        else if(option==4)
                                        {
                                            cout <<endl<<"New Month: ";
                                            getline(cin, lmonth);
                                            it->month=lmonth;
                                        }
                                        else if(option>4 || option<0)
                                        {
                                             cout <<endl<<"WRONG INPUT"  <<endl;
                                        }
 
                                }while(option!=0);
                            }
                            else
                            {
                                    cout  <<endl <<"MONTH NOT MATCHED" <<endl;
                                    return;
                            }
 
 
                        }
                        else
                        {
                                cout <<endl <<"DATE NOT MATCHED"  <<endl;
                                return;
                        }
           }
           else
           {
            cout<<endl <<"TITLE NOT MATCHED" <<endl;
            return;
           }
 
    }
    calender_print(starting, year);
}
 
 
void delete_reminder(int starting, int year)
{
    cout<<endl <<"----DELETE Reminder----"<<endl;
    if(reminderlist.empty()==true)
    {
        cout <<endl <<"NO REMINDER LISTED" <<endl;
        return;
    }
    string ltitle, lmonth; int ldate;
    cout<<"Reminder Title: ";
    getline(cin, ltitle);
    cout<<"Date: ";
    cin>>ldate;
    cin.ignore();
    cout<<"Month: ";
    getline(cin, lmonth);
    lowercase(lmonth);
 
    bool erased = 0;
    for(list<reminder>::iterator it=reminderlist.begin(); it!=reminderlist.end(); it++)
    {
        if(ltitle==it->title)
            {
                if(ldate==it->date)
                {
                    if(lmonth==it->month)
                    {
                        reminderlist.erase(it);
                        cout<<"Reminder Deleted!!"<<endl;
                        erased = 1;
                        break;
                    }
 
                }
            }
    }
 
    if(!erased)
    {
        cout<<endl <<"TITLE NOT MATCHED" <<endl ;
        return;
    }
    calender_print(starting, year);
}
 
void reminder_of_month()
{
    if(reminderlist.empty()==true)
    {
        cout<<endl <<"NO REMINDER LISTED" <<endl;
        return;
    }
 
    string lmonth;
    cout<<"Month: ";
    getline(cin, lmonth);
    lowercase(lmonth);
    cout<<endl <<"Reminders of "<<lmonth <<endl <<"--------------------------";
    for(list<reminder>::iterator it=reminderlist.begin(); it!=reminderlist.end(); it++)
    {
        if(lmonth==it->month)
        {
            cout<<"Reminder Title: "<<it->title<<endl;
            cout<<"Description: "<<it->description<<endl;
            cout<<"Date: "<<it->date<<endl;
            cout<<"Month: "<<it->month<<endl;
        }
        else
            cout<<lmonth<<"is not valid";
 
        cout<<endl;
    }
}
 
bool star_print(string lmonth, int ldate)
{
    if(reminderlist.empty()==true)
        return false;
 
    for(list<reminder>::iterator it=reminderlist.begin(); it!=reminderlist.end();)
    {
        if(it->month==lmonth && it->date==ldate)
        {
            return true;
        }
        else
            ++it;
    }
}
 
void lowercase(string& str)
{
    int length = str.length();
    for (int i = 0; i < length; i++) {
        int c = str[i];
 
         if (isupper(c))
            str[i] = tolower(c);
    }
}
 
//main function define
int main()
{
    int year;
    string dayStart;
    cout<<"Please enter year= ";
    cin>>year;
 
    cout<<"First day of the year: ";
    cin>>dayStart;
 
    lowercase(dayStart);//calling function for lowercase covert.
 
 
    string days[7]= { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    int starting;
 
    for(int i=0; i<7; i++)
    {
        if(dayStart == days[i])
        {
             starting= i;
        }
    }
 
    //calling function
    calender(year, 12);
    calender_print(starting, year);
 
    //for option select
    int select_option;
    do
    {
        cout <<endl <<endl <<"1.Add Reminder " <<endl  <<"2.Update Reminder." <<endl <<"3.Delete a specific reminder. " <<endl <<"4.View all the reminders of a specific month" <<endl;
        cout<<"*press 0 for Exit*" <<endl;
        cout<<endl <<"Input the numbers to perform the action: ";
        cin>>select_option;
        cin.ignore();
 
        if(select_option==1)
        {
 
            add_reminder(starting, year);
        }
 
        else if(select_option==2)
        {
            update_reminder(starting, year);
        }
 
        else if (select_option == 3)
        {
            delete_reminder(starting, year);
        }
 
        else if(select_option == 4)
        {
            reminder_of_month();
        }
 
        else if(select_option == 0)
        {
            return 0;
        }
 
        else if(select_option <0 || select_option>4)
        {
            cout <<endl <<"WRONG INPUT";
        }
 
    }
    while(select_option!=0);
}
