#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>

 //Classes Definition
 class Book
 {int Bookno;
 char Bookname[100];
 char Author[100];
 char Publisher[100];

 public:
 char status;

 void EnterBook()
 {status='F';
 cout<<"\n\n\n\t\t\tEnter The Book Number ";
 cin>>Bookno;
 cout<<"\n\t\t\tEnter Book Name";
 gets(Bookname);
 cout<<"\n\t\t\tEnter  The  Author ";
 gets(Author);
 cout<<"\n\t\t\tEnter  The Publisher";
 gets(Publisher);

 }

 void DisplayBook()
 {
   cout<<"\n\n\t\t\tBook Number :"<<Bookno;
   cout<<"\n\t\t\tBook Name   :"<<Bookname;
   cout<<"\n\t\t\tAuthor      :"<<Author;
   cout<<"\n\t\t\tPublisher   :"<<Publisher;
   if(status=='T')
   cout<<"\n\t\t\tStatus      :Issued";
   else
   cout<<"\n\t\t\tStatus      :Available";
}
 int GetBook()
 {
  return(Bookno);
  }




}b;


 class Issue
 {
  public:
  int Admin;
  int Bookid;

  void DisplayIssue()
  {cout<<"\n"<<Admin;
  cout<<"\n"<<Bookid;
  }

 }i;





class Student
{

 char Studentname[100];

 char Clas[100];
 int Admno;

 public:
 char status;
 void EnterStudent()
 {
 cout<<"\n\n\n\t\t\tEnter The  Admission Number ";
 cin>>Admno;
 cout<<"\n\t\t\tEnter Student Name";
 gets(Studentname);
 cout<<"\n\t\t\tEnter  The  Class ";
 gets(Clas);
 status='F';
 }

 void DisplayStudent()
 {
   cout<<"\n\n\n\t\t\tAdmission Number "<<Admno;
   cout<<"\n\t\t\tStudent Name   "<<Studentname;
   cout<<"\n\t\t\tClass      "<<Clas;
   if(status=='F')
   cout<<"\n\t\t\tStatus      :No Books Are Issued";
   else
   cout<<"\n\t\t\tStatus      :Book Issued";
   }

 int GetStudent()
 {
  return(Admno);
  }

 }s;


 void IssueDisplay()
 { ifstream infile("issue",ios::binary);
 while(infile.read((char*)&i,sizeof(i)))
   i.DisplayIssue();

 }

 class Teacher
 {

 char Teachername[100];

 char Clas[100];
 int id;
 public:
 char status;

 void EnterTeacher()
 {
 cout<<"\n\n\n\t\t\tEnter The  Teacher id ";
 cin>>id;
 cout<<"\n\t\t\tEnter Teacher Name";
 gets(Teachername);
 status='F';

 }

 void DisplayTeacher()
  {
   cout<<"\n\n\t\t\tTeacher Id "<<id;
   cout<<"\n\t\t\tTeacher Name   "<<Teachername;
   if(status=='T')
   cout<<"\n\t\t\tStatus      :Issued";
   else
   cout<<"\n\t\t\tStatus      :Available";

   }
   int GetTeacher()
 {
  return(id);
  }

 }t;

 //Classes Definition Ends Here



 //Function Definition Begins Here



 //Add Functions

 void addbook()
 {  int n,j;

ofstream out("Book",ios::binary);
 cout<<"\n\n\t\t\tEnter The Number Of Books";
 cin>>n;
  for(j=1;j<=n;j++)
  {

    b.EnterBook();
    out.write((char*)&b,sizeof(b));
 }

 }


void addStudent()
 { int n,j;
 cout<<"\n\n\t\t\tEnter The Number Of Students";
 cin>>n;
 ofstream out("Student",ios::binary);
  for(j=1;j<=n;j++)
 {

    s.EnterStudent();
    out.write((char*)&s,sizeof(s));
 }
 }


 void addTeacher()
 {
  int n,j;
 cout<<"\n\n\t\t\tEnter The Number Of Teachers";
 cin>>n;
   ofstream out("Teacher",ios::binary);
  for(j=1;j<=n;j++)
 {

    t.EnterTeacher();
    out.write((char*)&t,sizeof(t));
 }



}
//Add Functions End Here

//Update Functions Begin Here


void UpdateBook()
{
  ofstream out("Book",ios::binary|ios::app);
    b.EnterBook();
    out.write((char*)&b,sizeof(b));



}

void UpdateStudent()
{
  ofstream out("Student",ios::binary|ios::app);
    s.EnterStudent();
    out.write((char*)&s,sizeof(s));
    getch();


}

void UpdateTeacher()
{
     ofstream out("Teacher",ios::binary|ios::app);
    t.EnterTeacher();
    out.write((char*)&t,sizeof(t));
    getch();


}


//Update Functions End Here


//Search Functions Begin Here


void SearchBook()
{int bno,f=0;
clrscr();
cout<<"\n\n\t\t\tEnter The Rollno of Book To Be Searched";
cin>>bno;
ifstream infile("Book",ios::binary);

while(infile.read((char*)&b,sizeof(b)))
{
if(b.GetBook()==bno)
 {cout<<"\n\n\t\t\tBook Details";
 cout<<"\n\t\t\t_______________";
 f=1 ;
 b.DisplayBook();
 }
}

if(f==0)
{cout<<"\n\n\t\t\tRecord not found." ;
}

infile.close();
getch();

}

void SearchStudent()
{int rno,f=0;
clrscr();
cout<<"\n\n\t\t\tEnter The Rollno of Student To Be Searched";
cin>>rno;
ifstream infile("Student",ios::binary);

while(infile.read((char*)&s,sizeof(s)))
{
if(s.GetStudent()==rno)
 {cout<<"\n\t\t\tStudent Details";
 cout<<" \n\t\t\t_______________";
 f=1 ;
 s.DisplayStudent();
 }
}

if(f==0)
{cout<<"\n\n\t\t\tRecord not found." ;
}

infile.close();
getch();

}

void SearchTeacher()
{int rno,f=0;
clrscr();
cout<<"\n\n\t\t\tEnter The ID of Teacher To Be Searched";
cin>>rno;
ifstream infile("Teacher",ios::binary);

while(infile.read((char*)&t,sizeof(t)))
{
if(t.GetTeacher()==rno)
 {cout<<"\n\n\t\t\tTeacher Details";
 cout<<" \n\t\t\t_______________";
 f=1 ;
 t.DisplayTeacher();
 }
}

if(f==0)
{cout<<"\n\t\t\tRecord not found." ;
}

infile.close();
getch();

}


// Search Functions End Here

//Display Function Begin Here

void BookDisplay()
{clrscr();
ifstream infile("Book",ios::binary);
 while(infile.read((char*)&b,sizeof(b)))
   b.DisplayBook();
  getch();

  }

  void StudentDisplay()
{clrscr();
ifstream infile("Student",ios::binary);
 while(infile.read((char*)&s,sizeof(s)))
   s.DisplayStudent();
  getch();

}

void TeacherDisplay()
{clrscr();
 ifstream infile("Teacher",ios::binary);
 while(infile.read((char*)&t,sizeof(t)))
   t.DisplayTeacher();
   getch();

  }
 //Display Functions Ends Here



 void StudentIssue()
 { clrscr();
 int adm,bs,pos=0,founds,foundb;
 char confirm,conf;

fstream infile("Student",ios::binary|ios::out|ios::in);
fstream in("Book",ios::binary|ios::out|ios::in);
ofstream out("issue",ios::binary);



start:
clrscr();
cout<<"\n\n\t\t\tEnter Your Admission Number";
cin>>adm;
infile.seekg(0);
in.seekg(0);
out.seekp(0);

 while(infile.read((char*)&s,sizeof(s)))
  {
     if(s.GetStudent()==adm)
       { founds='y';
	 break;
       }
}
     if(founds!='y')
     {cout<<"\nInvalid Admission Number";
      cout<<"\nDo YOu Want To Retry   ";
      cin>>conf;
     }
     if(conf=='Y'||conf=='y')
     goto start;


    if(founds=='y')
     { cout<<"\nAre You:(Y/N)";
       s.DisplayStudent();
       cin>>confirm;
       clrscr();
     }




    if(confirm=='Y'||confirm=='y')
    { cout<<"\nEnter The Name Book That You Want Issue";
      cin>>bs;

	   while(in.read((char*)&b,sizeof(b)))
	       if(b.GetBook()==bs)
		{
		 foundb='y';
		 break;
		}


    if(foundb=='y')
       {
	if(b.status=='F')
	{
	i.Bookid=b.GetBook();
	i.Admin=s.GetStudent();
	pos=in.tellg();
	int ps=infile.tellg();
	in.seekg(pos-303);
	infile.seekg(ps-sizeof(s));
	b.status='T';
	s.status='T';
	infile.write((char*)&s,sizeof(s));
	in.write((char*)&b,sizeof(b));
	b.DisplayBook();
	out.write((char*)&i,sizeof(i));
	cout<<"Successfully Issued";
	getch();
	}

      else
      {

     cout<<"\nThis Has Already Been Issued        ";
     cout<<"\nDo YOu Want To Issue Another Book   ";
     cin>>conf;

     if(conf=='Y'||conf=='y')
     goto start;




     }
     }
      else
      {cout<<"\n\t\t\tThe Book Doesn't Exist";
      cout<<"\n\t\t\tDo YOu Want To Issue Another Book   ";
     cin>>conf;

     if(conf=='Y'||conf=='y')
     goto start;
     }
      }


      else
      goto start;
    }
void TeacherIssue()
 {
 int adm,bs,pos=0,founds,foundb;
 char confirm,conf;
  clrscr();
fstream infile("Teacher",ios::binary|ios::out|ios::in);
fstream in("Book",ios::binary|ios::out|ios::in);
ofstream out("issue",ios::binary);



start:
clrscr();
cout<<"\n\t\t\tEnter Your Teacher Id:";
cin>>adm;
infile.seekg(0);
in.seekg(0);
out.seekp(0);

 while(infile.read((char*)&t,sizeof(t)))
  {
     if(t.GetTeacher()==adm)
       { founds='y';
	 break;
       }
}
     if(founds!='y')
     {cout<<"\n\t\t\tInvalid Admission Number";
      cout<<"\n\t\t\tDo YOu Want To Retry   ";
      cin>>conf;

     if(conf=='Y'||conf=='y')
     goto start;
      }




    if(founds=='y')
     { cout<<"\n\t\t\tAre You:(Y/N)";
       t.DisplayTeacher();
       cin>>confirm;
       clrscr();
     }




    if(confirm=='Y'||confirm=='y')
    {

     cout<<"\n\t\t\tEnter The Name Book That You Want Issue";
      cin>>bs;

	   while(in.read((char*)&b,sizeof(b)))
	       if(b.GetBook()==bs)
		{
		 foundb='y';
		 break;
		}


    if(foundb=='y')
       {
	if(b.status=='F')
	{
	i.Bookid=b.GetBook();
	i.Admin=t.GetTeacher();
	pos=in.tellg();
	int ps=infile.tellg();
	in.seekg(pos-303);
	infile.seekg(ps-sizeof(t));
	b.status='T';
	t.status='T';
	infile.write((char*)&t,sizeof(t));
	in.write((char*)&b,sizeof(b));
	b.DisplayBook();
	out.write((char*)&i,sizeof(i));
	cout<<"\n\nSuccessfully Issued";
	}

      else
      {

     cout<<"\n\t\t\tThis Has Already Been Issued        ";
     cout<<"\n\t\t\tDo YOu Want To Issue Another Book   ";
     cin>>conf;

     if(conf=='Y'||conf=='y')
     goto start;




     }
     }
      else
      {cout<<"\n\t\t\tThe Book Doesn't Exist";
      cout<<"\n\t\t\tDo YOu Want To Issue Another Book   ";
     cin>>conf;

     if(conf=='Y'||conf=='y')
     goto start;
     }
      }


      else
      goto start;
    }


 void StudentReturn()
 {
    int adm,bs,pos=0,founds,foundb;
    char confirm,conf;
     clrscr();
    fstream infile("Student",ios::binary|ios::out|ios::in);
    fstream in("Book",ios::binary|ios::out|ios::in);
    fstream out("issue",ios::binary|ios::out|ios::in);



start:
clrscr();
cout<<"\n\t\t\tEnter Your Admission Number";
cin>>adm;
infile.seekg(0);
in.seekg(0);
out.seekp(0);
infile.read((char*)&s,sizeof(s));


 while(!infile.eof())
  {
     if(s.GetStudent()==adm)
       { founds='y';
	 break;
       }
 }




    if(founds=='y')
     { cout<<"\n\t\t\tAre You:(Y/N)";
       s.DisplayStudent();
       cin>>confirm;
       clrscr();
     }

     else
     {cout<<"\n\t\t\tInvalid Admission Number";
      cout<<"\n\t\t\tDo YOu Want To Retry   ";
      cin>>conf;
     }

     if(conf=='Y'||conf=='y')
     goto start;



    if(confirm=='Y'||confirm=='y')
     {

     if(s.status=='T')
      {
	while(out.read((char*)&i,sizeof(i)))
	{if(i.Admin==s.GetStudent())
	break;
	}

       while(in.read((char*)&b,sizeof(b)))
       { if(i.Bookid==b.GetBook())
       break;
       }
	pos=in.tellg();
	int ps=infile.tellg();
	in.seekg(pos-303);
	infile.seekg(ps-sizeof(s));
	b.status='F';
	s.status='F';
	infile.write((char*)&s,sizeof(s));
	in.write((char*)&b,sizeof(b));
	b.DisplayBook();
	cout<<"\n\t\t\tSuccessfully Returned";


      }
    }


}
void TeacherReturn()
 {
    int adm,bs,pos=0,founds,foundb;
    char confirm,conf;

    fstream infile("Teacher",ios::binary|ios::out|ios::in);
    fstream in("Book",ios::binary|ios::out|ios::in);
    fstream out("issue",ios::binary|ios::out|ios::in);



start:
clrscr();
cout<<"\n\n\t\t\tEnter Your Teacher Id:";
cin>>adm;
infile.seekg(0);
in.seekg(0);
out.seekp(0);

 infile.read((char*)&t,sizeof(t));

 while(!infile.eof())
  {if(t.GetTeacher()==adm)
       { founds='y';
	 break;
       }
   }





    if(founds=='y')
     { cout<<"\n\t\t\tAre You:(Y/N)";
       t.DisplayTeacher();
       cin>>confirm;
       clrscr();
     }

     else
     {cout<<"\n\t\t\tInvalid Admission Number";
      cout<<"\n\t\t\tDo YOu Want To Retry   ";
      cin>>conf;
     }


     if(conf=='Y'||conf=='y')
     goto start;

    if(confirm=='Y'||confirm=='y')
     {

     if(t.status=='T')
      {
	while(out.read((char*)&i,sizeof(i)))
	{if(i.Admin==t.GetTeacher())
	break;
	}

       while(in.read((char*)&b,sizeof(b)))
       { if(i.Bookid==b.GetBook())
       break;
       }
	pos=in.tellg();
	int ps=infile.tellg();
	in.seekg(pos-303);
	infile.seekg(ps-sizeof(s));
	b.status='F';
	t.status='F';
	infile.write((char*)&t,sizeof(t));
	in.write((char*)&b,sizeof(b));
	b.DisplayBook();
	cout<<"\n\t\t\tSuccessfully Returned";


      }
    }

}
//Delete Functions Begin Here
void BookDelete()
 {
   fstream infile("Book",ios::binary|ios::in|ios::out);
   fstream outfile("Temporary",ios::binary|ios::in|ios::out);
   char found='f';
   char confirm;
   int rno;
   cout<<"\n\n\t\t\tEnter The Book Number To be Deleted:";
   cin>>rno;
   while(infile.read((char*)&b,sizeof(b)))
   {
     if(b.GetBook()==rno)
      {
       b.DisplayBook();
       found='t';
       cout<<"\n\n\t\t\tAre you sure you want to Delete The Record:";
       cin>>(confirm);
       if(confirm=='n')
       outfile.write((char*)&b,sizeof(b));
      }
   else
   outfile.write((char*)&b,sizeof(b));
   }

   if(found=='f')
   cout<<"\n\n\t\t\tBook Not Found";
   infile.close();
   outfile.close();
   remove("Book");
   rename("Temporary","Book");
   getch();
   }

 void StudentDelete()
 {
   fstream infile("Student",ios::binary|ios::in|ios::out);
   fstream outfile("Temporary",ios::binary|ios::in|ios::out);
   char found='f';
   char confirm;
   int rno;
   cout<<"\n\n\t\t\tEnter The Admisssion NUmber To be Deleted";
   cin>>rno;
   while(infile.read((char*)&s,sizeof(s)))
   {
     if(s.GetStudent()==rno)
      {
       s.DisplayStudent();
       found='t';
       cout<<"\n\n\t\t\tAre you sure you want to delete\n";
       cin>>(confirm);
       if(confirm=='n')
       outfile.write((char*)&s,sizeof(s));
      }
   else
   outfile.write((char*)&s,sizeof(s));
   }

   if(found=='f')
   cout<<"\n\n\t\t\tStudent Not Found";
   infile.close();
   outfile.close();
   remove("Student");
   rename("Temporary","Student");
   getch();
   }
void TeacherDelete()
{
   fstream infile("Teacher",ios::binary|ios::in|ios::out);
   fstream outfile("Temporary",ios::binary|ios::in|ios::out);
   char found='f';
   char confirm;
   int rno;
   cout<<"\n\n\t\t\tEnter The Teacher Id To be Deleted";
   cin>>rno;
   while(infile.read((char*)&t,sizeof(t)))
   {
     if(t.GetTeacher()==rno)
      {
       t.DisplayTeacher();
       found='t';
       cout<<"\n\n\t\t\tAre you sure you want to delete\n";
       cin>>(confirm);
       if(confirm=='n')
       outfile.write((char*)&t,sizeof(t));
      }
   else
   outfile.write((char*)&t,sizeof(t));
   }

   if(found=='f')
   cout<<"\n\n\t\t\tStudent Not Found";
   infile.close();
   outfile.close();
   remove("Teacher");
   rename("Temporary","Teacher");
   getch();
   }

 void book()
 { clrscr();
 int ch;
 cout<<"\n\n\t\t\t1.Add \n\t\t\t2.Update \n\t\t\t3.Search \n\t\t\t4.Display \n\t\t\t5.Delete A Record";
 cout<<"\n\t\t\tEnter Your Choice";
 cin>>ch;
 clrscr();
 switch(ch)
 {
 case 1:
 addbook();
 break;

case 2:
UpdateBook();
break;

case 3:
SearchBook();
break;

case 4:
BookDisplay();
break;

case 5:
BookDelete();
break;

default:
cout<<"Invalid Option";

 }
}

void student()
 {int ch;
  clrscr();

 cout<<"\n\n\t\t\t1.Add \n\t\t\t2.Update \n\t\t\t3.Search \n\t\t\t4.Display \n\t\t\t5.Issue Book \n\t\t\t6.Return Book ";
 cout<<"\n\n\t\t\t7.Delete A Record";
 cout<<"\nEnter Your Choice";
 cin>>ch;
 clrscr();
 switch(ch)
 {
 case 1:
 addStudent();
 break;

case 2:
UpdateStudent();
break;

case 3:
SearchStudent();
break;

case 4:
StudentDisplay();
break;

case 5:
StudentIssue();
break;

case 6:
StudentReturn();

case 7:
StudentDelete();

default:
cout<<"\n\t\t\tInvalid Option" ;

 }


}


 void teacher()
 {
 int ch;
 cout<<"\n\n\n\t\t\t1.Add \n\t\t\t2.Update \n\t\t\t3.Search \n\t\t\t4.Display  \n\t\t\t5.Issue A Book \n\t\t\t6.Return A Book \n\t\t\t7.Delete A Record";
 cout<<"\n\t\t\tEnter Your Choice";
 cin>>ch;
 switch(ch)
 {
 case 1:
 addTeacher();
 break;

 case 2:
 UpdateTeacher();
 break;

case 3:
SearchTeacher();
break;

case 4:
TeacherDisplay();
break;

case 5:
TeacherIssue();
break;

case 6:
TeacherReturn();
break;

case 7:
TeacherDelete();
break;

default:
cout<<"\n\t\t\tInvalid Option";

 }
 }



void main()
{
clrscr();
int ch;
char cho;

do
{
cout<<"\n\n\t\t\t1.Book \n\t\t\t2.Student \n\t\t\t3.Teacher \n\t\t\t4.Exit" ;
cout<<"\n\t\t\tEnter Your Choice";
cin>>ch;
clrscr();
switch(ch)
{
case 1:
book();
break;

case 2:
student();
break;

case 3:
teacher();
break;

case 4:
break;

default:
cout<<"\n\nInvalid Option";
}
clrscr();
cout<<"\n\nDo You Want To Continue";
cin>>cho;
clrscr();
}while(cho=='y'||cho=='Y');
getch();
}