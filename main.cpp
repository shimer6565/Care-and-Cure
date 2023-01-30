#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<iomanip>
using namespace std;
//admin login
class Hospital
{
 private:
 string username,password;
 public:
 Hospital()
 {
 username="\0";
 password="\0";
 }
 LogIn();
 string getus()
 {
 return username;
 }
};
string convert(char* a, int size)
{
 string s = a;
 return s;
}
int Hospital::LogIn()
{
 system("Color 0A");
 string ch_username="admin",ch_password="1234";

 cout<<"\n\n\n\n\n\n\n\n"<<setw(88)<<"LOGIN\n"<<setw(88)<<"-------";
 cout<<"\n\n\n\n"<<setw(88)<<"ENTER USERNAME:\t";
 cin>>username;
 cout<<"\n\n"<<setw(88)<<"ENTER PASSWORD:\t";
 char pass[32];
 int i = 0;
 char a;
 for(i=0;;)
 {
 a=getch();

if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
 {
 pass[i]=a;
 ++i;
 cout<<"*";
 }
 if(a=='\b'&&i>=1)
 {
 cout<<"\b \b";
 --i;
 }
 if(a=='\r')
 {
 pass[i]='\0';
 break;
 }
 }
 int a_size = sizeof(pass) / sizeof(char);
 password = convert(pass,a_size);
 if(username==ch_username &&
password==ch_password)
 {
 return 1;
 }
 else
 {
 return 0;
 }
}
//the features common to both doctors and patients
class person
{
 char name[90];
 int age;
 char address[100];
 char gender[9];
 long int phno;
 Hospital H;
 public:
 void getperson()
 {
 cout<<"ENTER NAME : ";
 fflush(stdin);
 gets(name);
 cout<<"ENTER AGE : ";
 cin>>age;
 cout<<"ENTER ADDRESS : ";
 fflush(stdin);
 gets(address);
 cout<<"ENTER GENDER : ";
 fflush(stdin);
 gets(gender);
 cout<<"ENTER PHONE NUMBER : ";
 cin>>phno;
 }
 void display_person()
 {
 cout<<"NAME : ";
 puts(name);
 cout<<"AGE : "<<age<<endl;
 cout<<"ADDRESS : ";
 puts(address);
 cout<<"GENDER : ";
 puts(gender);
 cout<<"PHONE NUMBER : "<<phno<<endl;
 }
};
//doctor has a specialization
class specialization
{
 string speclz;
 public:
 specialization()
 {
 cout<<"ENTER SPECIALIZATION : ";
 fflush(stdin);
 cin>>speclz;
 }
 void splz()
 {
 cout<<speclz;
 }
};
//doctor derives from person
class doctor:public person
{
 int docid;
 char qualifications[20];
 int experience;
 public:
 doctor()
 {
 }
 void getdetailsdoc()
 {
 getperson();
 specialization s;
 cout<<"ENTER ID : ";
 cin>>docid;
 cout<<"ENTER QUALIFICATIONS : ";
 fflush(stdin);
 gets(qualifications);
 cout<<"ENTER EXPERIENCE : ";
 cin>>experience;
 }
 void display_doc()
 {
 cout<<"ID : "<<docid<<endl;
 display_person();
 cout<<"QUALIFICATIONS :";
 puts(qualifications);
 cout<<"EXPERIENCE : "<<experience<<endl;
 //cout<<"SPECIALIZATION : ";
 //cout<<specialization::display_spl();
 }
 int getdocid();
}d;
int doctor::getdocid()//returning the id of the doctor
{
 return docid;
}
//patients from our hospital can only purchase
class medicine
{
int quantity[10];
string type = {"OTC"};
int x, menu2[10];
 double amount[10];
 public:
 string medicineName[10]={"Probiotics","Vitamin C","Vitamin D","Women'S Multivate","Paracetamol","Zyr Cold", "Allegra","Burnex","Telma","Nitravet"};
 double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
 void order();
 void order_list();
 medicine(){}
};
//patient heirarchically derives from person and medicine
class patient:public person,public medicine
{
 int pid;
 char disease[50];
 char symptom[30];
 char blood[10];
 public:
 patient()
 {
 }
 void getdetailspat()
 {
 int flag;
 cout<<"ENTER ID : ";
 cin>>pid;
 getperson();
 cout <<"BLOOD GROUP : ";
 again:
 cin>>blood;

if((strcmp(blood,"A+")==0)||(strcmp(blood,"a+")==0)||(strcmp(blood,"A-")==0)||(strcmp(blood,"a-")==0)||

(strcmp(blood,"B+")==0)||(strcmp(blood,"b+")==0)||(strcmp(blood,"B-")==0)||(strcmp(blood,"b-")==0)||

(strcmp(blood,"O+")==0)||(strcmp(blood,"o+")==0)||(strcmp(blood,"O-")==0)||(strcmp(blood,"o-")==0)||

(strcmp(blood,"AB+")==0)||(strcmp(blood,"ab+")==0)||(strcmp(blood,"AB-")==0)||(strcmp(blood,"ab-")==0))
 flag=1;
 if(flag==0)
 {
 cout<<"\nInvalid input!Enter a valid Blood Group :";
 goto again;
 }
 cout<<"ENTER DISEASE : ";
 fflush(stdin);
 gets(disease);
 cout<<"ENTER SYMPTOMS : ";
 fflush(stdin);
 gets(symptom);
 }
 void display_pat()
 {
 cout<<"ID : "<<pid<<endl;
 display_person();
 cout<<"BLOOD : ";
 puts(blood);
 cout<<"DISEASE : ";
 puts(disease);
 cout<<"SYMPTOMS : ";
 puts(symptom);
 }
 int getpid();
}p;
//returning the id of the patient
int patient::getpid()
{
 return pid;
}
void clr()
{
 system("cls");
}
void medicine::order() //function to order
{
system("cls");
int i,z;
int fl;
 int choice, price,None;
 //int quantity;
cout <<"\nAdd Order Details\n";
cout
<<"_____________________________________ \n\n";

cout<<"****************************************************************************\n";
cout<<"|DRUGS ID"<<"\tDRUGS TYPE"<<"\t\tDRUGS NAME"<<" DRUGS PRICE(RM)|"<<endl;
cout<<"****************************************************************************\n";
 cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"Probiotics"<<" RM 2.00"<<endl;
 cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<" VitaminC"<<" RM 3.00"<<endl;
 cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<" VitaminD"<<" RM 1.00"<<endl;
 cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"Women'S Multivate"<<" RM 4.00"<<endl;
 cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"Paracetamol "<<" RM 1.00"<<endl;
 cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<" Zyr Cold"<<" RM 5.00"<<endl;
 cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<" Allegra"<<" RM 7.00"<<endl;
 cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"Burnex"<<" RM 4.00"<<endl;
 cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<" Telma"<<" RM 3.00"<<endl;
 cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"Nitravet"<<" RM 5.00"<<endl;
 cout<<" "<<endl;
 int id;
cout<< "Enter Customer ID: ";
cin>> id;
ifstream f("patient.dat",ios::binary | ios::in);
 while(f.read((char*)&p,sizeof(p)))
 {
 if(id == p.getpid())
 {
 fl=1;
 system("pause");
 break;
 }
 else
 fl=0;
 }
 if(fl==0)
 {
 cout<<"\nRECORD NOT FOUND!!\n\n";
 return;
 }
 f.close();
 if(fl==1)
{
 cout << "How many medicines would you like to order? : "<< endl;
 cin >> x;
 if (x >10)
 {
 cout << "The number of medicines exceeds the maximum number of medicines !";
 system("pause");
 }
 else
 {
 for (i=0; i<x; i++)
 {
 cout << "Please enter your selection : "<<endl;
 cin>> menu2[i];
 z=(menu2[i] -1);
 cout<<"Medicine Name:"<<medicineName[z]<<endl;
 cout<<"How many medicine do you want: ";
 cin>>quantity[i];
 amount[i] = quantity[i] * Medicine[z];
 cout << "The amount You need to pay is: Rs "<< amount[i]<<endl;
 }

cout<<"==========================================================================="<<endl;
 cout<<"Order Taken Successfully"<<endl;
 cout<<"\nTo Pay The Bill"<<endl;
cout<<"==========================================================================="<<endl;
 system ("PAUSE");
 clr();
 order_list();
 }
 }
}
void medicine::order_list()
{
 int i,billamt;
 clr();
 float total;
 cout<<"\n";

cout<<"==============================================================================="<<endl;
 cout<<"| Here is the Order list|\n";

cout<<"==============================================================================="<<endl;
p.display_pat();
cout<<"_________________________________________________________________________________"<<endl;
cout<<"```````````````````````````````````````````````````````````````````````````````"<<endl;
cout<<"| Medicine Type |Medicine Name | Quantity | Total Price|"<<endl;
cout<<"=======++==================++================++===============++==============="<<endl;
for (i=0;i<x;i++)
{
cout<<"\t"<< type<<" \t\t";
cout<<medicineName[menu2[i]-1]<<"\t\t ";
cout<<quantity[i]<<"\t\t";
cout<<"Rs"<<amount[i]<<endl;

cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

cout<<"````````````````````````````````````````````````````````````````````````````````"<<endl;

cout<<"_________________________________________________________________________________"<<
endl;
total = amount[0]+ amount[1]+amount[2]+ amount[3]+ amount[4]+ amount[5]+amount[6]+ amount[7]+ amount[8]+ amount[9];
cout<<"TOTAL BILL AMOUNT :Rs "<<total;
cout<<"\n";
cout<<"PAY THE CORRECTAMOUNT : Rs ";
cin>>billamt;
cout<<"\nTransaction processed\nThank You!!\n";
cout<<"\n_________________________________________________________________________________\n";
}
//to add doctor’s details
void append()
{
 fstream f;
 f.open("doctor.dat",ios::binary | ios::app);
 d.getdetailsdoc();
 f.write((char*)&d, sizeof(doctor));
 f.close();
}
//to sort all the doctor’s details using doctor’s ID
void Sort(doctor *T, int n)
{
 for(int i=0;i<n-1;i++)
 {
 for(int j =0;j<n-1-i;j++)
 {
 if(T[j].getdocid() > T[j+1].getdocid())
 {
 doctor tmp = T[j];
 T[j] = T[j+1];
 T[j+1] = tmp;
 }
 }
 }
}
void sorting()
{
 doctor doc[100];
 int i=0;
 ifstream f;
 f.open("doctor.dat",ios::binary | ios::in);
 while(f.read((char*)&d,sizeof(d)) && !f.eof())
 {
 doc[i]=d;
 i++;
 }
 f.close();
 Sort(doc,i);
 ofstream fl;
 fl.open("doctor.dat",ios::binary | ios::out);
 for(int j=0;j<i;j++)
 {
 fl.write((char *)&doc[j],sizeof(doc[j]));
 }
 fl.close();
}
//to display the details of all the doctors
void display()
{
 clr();
 sorting();
 ifstream f;
 f.open("doctor.dat",ios::binary | ios::in);
 int record=0;
 while(f.read((char*)&d,sizeof(d)))
 {
 cout<<endl;
 record++;
 cout<<"RECORD "<<record<<endl;
 cout<<"---------"<<endl<<endl;
 d.display_doc();
 }
 f.close();
 cout<<"\n\n\nTotal no. of records :"<<record<<endl<<endl<<endl<<endl;
}
//to search for a particular record
void searchdoc()
{
 cout<<"\n\n";
 int ch,id,fl;
 fl=0;
 while(1)
 {
 clr();
 cout<<"\n\nSEARCH"<<endl<<"-----"<<endl;
 cout<<"1.ID\n2.Back\n";
 cout<<"\nEnter ur choice : ";
 cin>>ch;
 if(ch==1)
 {
 cout<<"\nEnter the Id to be searched : ";
 cin>>id;
 ifstream f;
 f.open("doctor.dat",ios::binary | ios::in);
 while(f.read((char*)&d,sizeof(d)))
 {
 if(id == d.getdocid())
 {
 clr();
 d.display_doc();
 fl=1;
 system("pause");
 clr();
 break;
 }
 else
 fl=0;
 }
 if(fl==0)
 {
 cout<<"\nRECORD NOT FOUND!!\n\n";
 system("pause");
 }
 f.close();
 }
 else if(ch==2)
 {
 return;
 }
 else
 {
 if(fl==0)
 {
 cout<<"\nRECORD NOT FOUND!!\n\n";
 system("pause");
 }
 cout<<"\n\n";
 return;
 }
 }
}
//to delete a doctor’s record
void deletedoc()
{
 int n;
 int fl=0;
 ifstream fin("doctor.dat",ios::binary | ios::in);
 ofstream fout("new.dat",ios::app | ios::out);
 clr();
 cout<<"Enter the doctor's to be deleted : ";
 cin>>n;
 while(fin.read((char*)&d,sizeof(d)))
 {
 if(n==d.getdocid())
 {
 fl=1;
 cout<<"Deleted Record!!\n";
 }
 else
 {
 fout.write((char*)&d,sizeof(d));
 }
 }
 fin.close();
 fout.close();
 clr();
 remove("doctor.dat");
 rename("new.dat","doctor.dat");
 if(fl==0)//id not found
 cout<<"\nId not found!!\n";
}
//to add a patient’s record
void appendpat()
{
 fstream f;
 f.open("patient.dat",ios::binary | ios::app);
 p.getdetailspat();
 f.write((char*)&p, sizeof(p));
 f.close();
}
void Sortpat(patient *T, int n)
{
 for(int i=0;i<n-1;i++)
 {
 for(int j =0;j<n-1-i;j++)
 {
 if(T[j].getpid() > T[j+1].getpid())
 {
 patient tmp = T[j];
 T[j] = T[j+1];
 T[j+1] = tmp;
 }
 }
 }
}
void sortingpat()
{
 patient pat[100];
 int i=0;
 ifstream f;
 f.open("patient.dat",ios::binary | ios::in);
 while(f.read((char*)&p,sizeof(p)) && !f.eof())
 {
 pat[i]=p;
 i++;
 }
 f.close();
 Sortpat(pat,i);
 ofstream fl;
 fl.open("patient.dat",ios::binary | ios::out);
 for(int j=0;j<i;j++)
 {
 fl.write((char *)&pat[j],sizeof(pat[j]));
 }
 fl.close();
}
void displaypat()
{
 clr();
 ifstream f;
 f.open("patient.dat",ios::binary | ios::in);
 int record=0;
 while(f.read((char*)&p,sizeof(p)))
 {
 cout<<endl;
 record++;
 cout<<"RECORD "<<record<<endl;
 cout<<"---------"<<endl;
 p.display_pat();
 }
 f.close();
 cout<<"\n\n\nTotal no. of records :"<<record<<endl<<endl;
}
// to search for a patient’s record
void searchpat()
{
 cout<<"\n\n";
 int ch,id,fl;
 fl=0;
 while(1)
 {
 clr();
 cout<<"\n\nSEARCH"<<endl<<"-----"<<endl;
 cout<<"1.ID\n2.Back\n";
 cout<<"\n\nEnter ur choice : ";
 cin>>ch;
 if(ch==1)
 {
 cout<<"\n\nEnter the Id to be searched : ";
 cin>>id;
 ifstream f("patient.dat",ios::binary | ios::in);
 while(f.read((char*)&p,sizeof(p)))
 {
 if(id == p.getpid())
 {
 clr();
 p.display_pat();
 fl=1;
 system("pause");
 clr();
 break;
 }
 else
 fl=0;
 }
 if(fl==0)
 cout<<"RECORD NOT FOUND!!\n\n";
 f.close();
 }
 else if(ch==2)
 {
 return;
 }
 else
 {
 if(fl==0)
 cout<<"RECORD NOT FOUND!!\n\n";
 cout<<"\n\n";
 return;
 }
 }
}
//to delete a particular patient’s record
void deletepat()
{
 int n;
 int fl=0;
 ifstream fin("patient.dat",ios::binary | ios::in);
 ofstream fout("patient2.dat",ios::app | ios::out);
 clr();
 cout<<"\n\nEnter the patient's ID to be deleted : ";
 cin>>n;
 while(fin.read((char*)&p,sizeof(p)))
 {
 if(n==p.getpid())
 {
 fl=1;
 cout<<"Deleted Record!!\n";
 }
 else
 {
 fout.write((char*)&p,sizeof(p));
 }
 }
 fin.close();
 fout.close();
 clr();
 remove("patient.dat");
 rename("patient2.dat","patient.dat");
 if(fl==0)//id not found
 cout<<"\nId not found!!\n";
}
//patient to access pharmacy
void pharm()
{
 medicine medicine;
 medicine.order();
 cout<<endl;
}
//------------------------------------------------------------------------------------------
int main()
{
 int ch1,ch2,ch3,ch4;
 system("cls");
 cout<<"\n\n";
 Hospital l1;
 int loggedin=l1.LogIn();
 while(!loggedin)
 {
 clr();
 system("Color 0C");
 cout<<"\n\n\n\n\n\n\n"<<setw(95)<<"\tLOGIN FAILED!\n\n\n" ;
 cout<<setw(105)<<"PLEASE RE-ENTER CREDENTIALS!\n\n\n\n\n\n";
 system("pause");
 clr();
 loggedin=l1.LogIn();
 }
 clr();
 if(loggedin)
 {
 system("Color 0B");

cout<<"\n\n\n\n\n\n\n"<<setw(92)<<"WELCOME ,"<<l1.getus()<<" !\n\n\n\n\n\n\n\n\n";
 system("pause");
 while(1)
 {
 clr();
 xy:
 system("Color 0B");

cout<<"\n\n\n\n\n\n"<<setw(110)<<"WELCOME TO WECARE HOSPITAL ,KOCHI\n\n\n";
 cout<<"\n\n\n"<<setw(90)<<"1. MENU"<<"\n\n";
 cout<<"\n\n\n"<<setw(91)<<"2. LOGOUT"<<"\n\n\n\n";
 cout<<"Enter Your Choice :";
 cin>>ch1;
 cout<<"\n\n\n";
 system("cls");
 if(ch1==1)
 {
 doc:
 system("cls");

cout<<"\n\n\n\n\n\n\n\n\n\n\n"<<setw(101)<<"1.ENTER INTO THE DOCTORS' DATABASE"<<endl<<endl<<endl<<endl;
cout<<setw(107)<<"2. ENTER INTO THE PATIENTS' DATABASE\n\n "<<endl<<endl;
cout<<setw(80)<<"3. BACK\n\n\n\n\n\n\n"<<endl<<endl;
cout<<"Please Enter Your choice :"<<" ";
cin>>ch2;
 while(1)
 {
 clr();
 switch(ch2)
 {
 case 1: clr();

cout<<"\n\n\n\n\n\n\n"<<setw(100)<<"WELCOME TO THE DOCTORS' DATABASE!"<<"\n\n\n\n\n\n";
 cout<<setw(86)<<"1. ADD DOCTOR"<<endl<<endl;
 cout<<setw(82)<<"2. SEARCH"<<endl<<endl;
 cout<<setw(91)<<"3. DELETE A RECORD"<<endl<<endl;
 cout<<setw(104)<<"4. VIEW DETAILS OF ALL DOCTORS "<<endl<<endl;
 cout<<setw(80)<<"5. BACK"<<"\n\n\n\n\n\n\n";
 cout<<"Please Enter your choice :"<<" ";
 cin>>ch3;
 switch(ch3)
 {
 case 1:
{
 system("cls");
 cout<<"DOCTOR'S DETAILS\n";
 cout<<"------------------\n\n";
 append();
 break;
 }
 case 2:
 searchdoc();
cout<<"\n";
 break;
 case 3: deletedoc();
 system("pause");
break;
 case 4: display();
 system("pause");
 break;
 case 5:
 system("cls");
goto doc;
break;
 default:
 cout<<"invalid";
 }
 break;
 case 2:

cout<<"\n\n\n\n\n\n\n"<<setw(100)<<"WELCOME TO THE PATIENTS' DATABASE!"<<"\n\n\n\n\n\n";
 cout<<setw(87)<<"1. ADD PATIENT"<<endl<<endl;
 cout<<setw(82)<<"2. SEARCH"<<endl<<endl;
 cout<<setw(91)<<"3. DELETE A RECORD"<<endl<<endl;
 cout<<setw(85)<<"4. MEDICINES"<<endl<<endl;
 cout<<setw(105)<<"5. VIEW DETAILS OF ALL PATIENTS "<<endl<<endl;
 cout<<setw(80)<<"6. BACK"<<"\n\n\n\n\n\n\n";
 cout<<"Please Enter your choice :"<<" ";
 cin>>ch4;
 switch(ch4)
 {
 case 1: system("cls");
 cout<<"PATIENT'S DETAILS\n";
 cout<<"------------------\n\n";
 appendpat();
break;
 case 2: searchpat();
 cout<<"\n";
 break;
 case 3: deletepat();
 system("pause");
 break;
 case 4: pharm();
 system("pause");
 break;
 case 5:
 displaypat();
 system("pause");
break;
 case 6: system("cls");
 goto doc;
 break;
 default:
 cout<<"invalid";
 break;
 }
 break;
 case 3:goto xy;
 default:cout<<"\nInvalid choice!\n";
 }
 }
 }
 else if(ch1==2)
 {
 system("Color 0A");

cout<<"\n\n\n\n\n\n\n\n\n"<<setw(110)<<"SUCCESSFU LLY LOGGED OUT...................\n\n\n\n\n\n\n";
 exit(0);
 }
 else
 {
 cout<<"\n\n\t\t\tWrong Input!!!!!!"<<endl;
 system("pause");
 clr();
 }
 }
 }
 return 0;
}
