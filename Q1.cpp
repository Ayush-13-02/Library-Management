#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
#include <ctime>
#include<Windows.h>
using namespace std;
int t,nnn;
int digit_num(int n){
    int digit = 0;
    while(n){
        digit++;
        n/=10;
    }
    return digit;
}
void replaces(char* s,char c)
{
	for(int i=0;;i++)
	{
		if(s[i]!=c)
		cout<<s[i];
		else
		break;
	}
}
void alb()
{
	cout<<endl<<"\t=========================================================================================="<<endl;
	cout<<"\t||\t\t\t| |     ==== ||\\\\  ||\\\\   ====   ||\\\\ \\\\  //  \t\t\t||"<<endl;
	cout<<"\t||\t\t\t| |____  ||  ||-   ||-   //__\\\\  ||-   \\\\// \t\t\t||" <<endl;
	cout<<"\t||\t\t\t/_____/ ==== ||//  ||\\\\ //    \\\\ ||\\\\   //  \t\t\t||"<<endl;
	cout<<"\t=========================================================================================="<<endl;
}
class Students{
    public:
    char stud_admnum[6];
    char student_name[30];
    char stud_class[15];
    int num_of_book_issused;
    void get_data(){
        come1:
        cout<<"\tEnter Student Admission number (Max 5 digit): ";
        cin>>ws;
        cin.getline(stud_admnum,5);
        strcat(stud_admnum,"a");
        cout<<"\tEnter Student Name : ";
        cin>>ws;
        cin.getline(student_name,29);
        strcat(student_name,"1");
        cout<<"\tEnter Student class : ";
        cin>>ws;
        cin.getline(stud_class,14);
        strcat(stud_class,"1");
        cout<<"\tNo. of book issued : ";
        cin>>num_of_book_issused;
    }
    void showdata();
    void store_data();
    int view_filedata();
    int search_student(char* num);
    void modify(char* s,int n,int t);
    int delete_stud(char* num);
};
Students s;
int Students::delete_stud(char* num)
{
	ifstream ifs;
    ofstream ifso;
    ifs.open("student.dat",ios::in|ios::binary);
    ifso.open("bois.dat",ios::out|ios::binary);
    int flag = 0;
    while(!ifs.eof())
    {
    	ifs.read((char*)this,sizeof(*this));
    	if(ifs)
    	{
    		if(strcmp(num,stud_admnum)!=0)
    		{
    			ifso.write((char*)this,sizeof(*this));
			}
			else
			{
				flag = 1;
			}
		}
	}
	ifs.close();
	ifso.close();
	remove("student.dat");
	rename("bois.dat","student.dat");
	return flag;
}
void Students::modify(char* s,int n,int t=0)
{
	ifstream ifs;
    ofstream ifso;
    ifs.open("student.dat",ios::in|ios::binary);
    ifso.open("stud.dat",ios::out|ios::binary);
    char s1[30],c;
    int n1;
    while(!ifs.eof())
    {
    	ifs.read((char*)this,sizeof(*this));
    	if(ifs)
    	{
    		if(strcmp(s,stud_admnum)==0)
    		{
                if(n==1)
                {
                	cout<<"\tEnter the Modified Admission number : ";
                	cin>>s1;
                	strcat(s1,"a");
                	strcpy(stud_admnum,s1);
				}
                else if(n==2)
                {
                	cout<<"\tEnter the Modified Student Name : ";
                	cin>>s1;
                	strcat(s1,"1");
                	strcpy(student_name,s1);
				}
                else if(n==3)
                {
                	cout<<"\tEnter the Modified class : ";
                	cin>>s1;
                	strcat(s1,"1");
                	strcpy(stud_class,s1);
				}
				else if(n==4)
                {
                	if(t==0)
					{
                	    cout<<"\tEnter the Modified No. of book Issued : ";
                	    cin>>n1;
                	    num_of_book_issused = n1;
					}
                	else if(t==2)
                	{
                		n1 = num_of_book_issused;
                		n1++;
                		num_of_book_issused = n1;
					}
					else if(t==1)
					{
						n1 = num_of_book_issused;
                		n1--;
                		num_of_book_issused = n1;
					}
				}
				ifso.write((char*)this,sizeof(*this));
			}
			else
			{
				ifso.write((char*)this,sizeof(*this));
			}
		}
	}
	ifs.close();
	ifso.close();
	remove("student.dat");
	rename("stud.dat","student.dat");
}
void Students::showdata(){
	char s[30],s1[15],s2[6];
	int tt=1;
    cout<<"\t";
    strcpy(s2,stud_admnum);
    for(int i=0;i<18;i++)
    {
    	if(s2[i]!='a'&&tt)
    	cout<<s2[i];
    	else{
    		tt=0;
    		cout<<" ";
		}
	}
	tt=1;
    strcpy(s,student_name);
    for(int i=0;i<32;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else{
    		tt=0;
    		cout<<" ";
		}
	}
    strcpy(s1,stud_class);tt=1;
    for(int i=0;i<17;i++)
    {
    	if(s1[i]!='1'&&tt)
    	cout<<s1[i];
    	else{
    		tt=0;
    		cout<<" ";
		}
	}
	cout<<num_of_book_issused<<endl;
}
void Students::store_data(){
    ofstream file;
    file.open("student.dat",ios::app|ios::binary);
    file.write((char*)this,sizeof(*this));
}
int Students::view_filedata(){
    ifstream file1;
    file1.open("student.dat",ios::in|ios::binary);
    if(!file1){
    cout<<"\tFile is not found"<<endl;
    return 0;}
    else{
        file1.read((char*)this,sizeof(*this));
        while(!file1.eof()){
            showdata();
            file1.read((char*)this,sizeof(*this));
        }
        return 1;
    }
}
int Students::search_student(char* num)
{
    ifstream ifb;
    ifb.open("student.dat",ios::in|ios::binary);
    int flag = 0;
    char s[40];
    while(!ifb.eof())
    {
        ifb.read((char*)this,sizeof(*this));
        if(ifb){
            if((strcmp(num,stud_admnum))==0)
            {
            	cout<<endl;
            	strcpy(s,stud_admnum);
                cout<<"\tAdmission No.: ";replaces(s,'a');cout<<endl;
                strcpy(s,student_name);
                cout<<"\tStudent Name : ";replaces(s,'1');cout<<endl;
                strcpy(s,stud_class);
                cout<<"\tClass : ";replaces(s,'1');cout<<endl;
                cout<<"\tNumber of book issued : "<<num_of_book_issused<<endl;
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}
class Passward{
    char passward[20];
    public:
    char* repass(){return passward;}
    void set_passward()
    {
        ofstream ips;
        ips.open("passward.dat",ios::out|ios::binary);
        cout<<"\tSet Passward : ";
        cin>>ws;
        cin.getline(passward,20);
        ips.write((char*)this,sizeof(*this));
        ips.close();
    }
    void change_passward();
};
Passward p;
void Passward::change_passward()
{
	ppp:
    system("cls");
    alb();
    char p[20];
    cout<<"\tEnter old passward : ";
    cin>>ws;
    cin.getline(p,20);
    ifstream ips;
    ofstream ipo;
    ips.open("passward.dat",ios::in|ios::binary);
    ipo.open("pass.dat",ios::out|ios::binary);
    ips.read((char*)this,sizeof(*this));
    if(strcmp(p,passward)==0){
    	ppp1:
        cout<<"\tEnter New passward : ";
        cin>>ws;
        cin.getline(p,20);
        char p1[20];
        cout<<"\tConfirm the Passward : ";
        cin>>ws;
        cin.getline(p1,20);
        if(strcmp(p,p1)==0)
        {
            strcpy(passward,p1);
            ipo.write((char*)this,sizeof(*this));
            ips.close();
            ipo.close();
            remove("passward.dat");
            rename("pass.dat","passward.dat");
            cout<<"\t***Passward Change Successfully***"<<endl;
        }
        else
        {
        	cout<<"\tPassward don't matchPlz try again"<<endl;
        	goto ppp1;
		}
    }
    else
    {
    	cout<<"\tWrong Passward Plz try again"<<endl;
    	goto ppp;
	}
}
class Books{
    public:
    char book_id[6];
    char Book_name[40];
    char author_name[40];
    int Copy_available;
    char Edition[15];
    int book_search(char* num,int t);
    void showdatab();
    void get_datab()
    {
        string s;
        cout<<"\tEnter the book id (4-digit): ";
        cin>>ws;
        cin.getline(book_id,5);
        strcat(book_id,"a");
        cout<<"\tEnter the Book name : ";
        cin>>ws;
        cin.getline(Book_name,39);
        strcat(Book_name,"1");
        cout<<"\tEnter the Author name : ";
        cin>>ws;
        cin.getline(author_name,39);
        strcat(author_name,"1");
        cout<<"\tEnter the Copy Available : ";
        cin>>Copy_available;
        cout<<"\tEnter the Book Edition (as Sixteenth): ";
        cin>>ws;
        cin.getline(Edition,14);
        strcat(Edition,"1");
    }
    
    void store_datab();
    int view_filedatab();
    void modifyb(char* s,int n,int t);
    int delete_book(char* s);
};
Books b;
class Book_iss{
	public:
	char stud_adm_noi[6];
	char stud_namei[30];
	char classi[15];
	char book_idi[6];
	char Book_namei[30];
    char author_namei[30];
    int date;
    int mths;
    int year;
	void showdatabi();
	void view_filedatabi();
	int delete_filei(char* num,char* num1,int t1);
	int bookiss_search(char* num,char* num1);
};
Book_iss bi;
int Book_iss::bookiss_search(char* num,char*num1)
{
	ifstream ifs;
	ifs.open("bookiss.dat",ios::in|ios::binary);
	int flag = 0;
	while(!ifs.eof())
	{
		ifs.read((char*)this,sizeof(*this));
		if(ifs)
		{
			if(strcmp(num,stud_adm_noi)==0)
			{
				if(strcmp(num1,book_idi)==0)
				{
					flag = 1;
					return flag;
				}
			}
		}
	}
	ifs.close();
	return flag;
}
int Books::delete_book(char* s)
{
	ifstream ifs;
    ofstream ifso;
    ifs.open("book.dat",ios::in|ios::binary);
    ifso.open("bois.dat",ios::out|ios::binary);
    int flag = 0;
    while(!ifs.eof())
    {
    	ifs.read((char*)this,sizeof(*this));
    	if(ifs)
    	{
    		if(strcmp(s,book_id)!=0)
    		{
    			ifso.write((char*)this,sizeof(*this));
			}
			else
			{
				flag = 1;
			}
		}
	}
	ifs.close();
	ifso.close();
	remove("book.dat");
	rename("bois.dat","book.dat");
	return flag;
}
void Books::modifyb(char* s,int n,int t=0)
{
	ifstream ifs;
    ofstream ifso;
    ifs.open("book.dat",ios::in|ios::binary);
    ifso.open("stud.dat",ios::out|ios::binary);
    char s1[30],c;
    int n1;
    while(!ifs.eof())
    {
    	ifs.read((char*)this,sizeof(*this));
    	if(ifs)
    	{
    		if(strcmp(s,book_id)==0)
    		{
                if(n==1)
                {
                	cout<<"\tEnter the Modified Book id : ";
                	cin>>s1;
                	strcat(s1,"a");
                	strcpy(book_id,s1);
				}
                else if(n==2)
                {
                	cout<<"\tEnter the Modified Book Name : ";
                	cin>>s1;
                	strcat(s1,"1");
                	strcpy(Book_name,s1);
				}
                else if(n==3)
                {
                	cout<<"\tEnter the Modified Author name : ";
                	cin>>s1;
                	strcat(s1,"1");
                	strcpy(author_name,s1);
				}
				else if(n==4)
                {
                	if(t==0)
					{
                	    cout<<"\tEnter the Modified Copy available : ";
                	    cin>>n1;
                	    Copy_available = n1;
					}
                	else if(t==2)
                	{
                		n1 = Copy_available;
                		n1++;
                		Copy_available = n1;
					}
					else if(t==1)
					{
						n1 = Copy_available;
                		n1--;
                		Copy_available = n1;
					}
				}
				ifso.write((char*)this,sizeof(*this));
			}
			else
			{
				ifso.write((char*)this,sizeof(*this));
			}
		}
	}
	ifs.close();
	ifso.close();
	remove("book.dat");
	rename("stud.dat","book.dat");
}
void Book_iss::showdatabi(){
	char s[33];
	int tt=1;
	cout<<"\t";
	strcpy(s,stud_adm_noi);
	for(int i=0;i<18;i++)
    {
    	if(s[i]!='a'&&tt)
    	cout<<s[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	tt=1;
	strcpy(s,stud_namei);
	for(int i=0;i<32;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	tt=1;
	strcpy(s,classi);
	for(int i=0;i<16;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	tt=1;
	strcpy(s,book_idi);
	for(int i=0;i<10;i++)
    {
    	if(s[i]!='a'&&tt)
    	cout<<s[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	tt=1;
	strcpy(s,Book_namei);
	for(int i=0;i<32;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	tt=1;
	strcpy(s,author_namei);
	for(int i=0;i<32;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	cout<<date<<"/"<<mths<<"/"<<year<<" ";
	cout<<endl;
	tt=1;
}
void Book_iss::view_filedatabi()
{
	ifstream ifbi;
	ifbi.open("bookiss.dat",ios::in|ios::binary);
	if(!ifbi){
    cout<<"\t\tFile is not found"<<endl;
    }
    else{
        ifbi.read((char*)this,sizeof(*this));
        while(!ifbi.eof()){
            bi.showdatabi();
            ifbi.read((char*)this,sizeof(*this));
        }
    }
}
int Book_iss::delete_filei(char* num,char* num1, int t1 = 1)
{
	time_t t=time(NULL);
    tm* tptr = localtime(&t);
	ifstream ifs;
    ofstream ifso;
    ifs.open("bookiss.dat",ios::in|ios::binary);
    ifso.open("bois.dat",ios::out|ios::binary);
    int flag = 0;
    while(!ifs.eof())
    {
    	ifs.read((char*)this,sizeof(*this));
    	if(ifs)
    	{
    		if(strcmp(num,stud_adm_noi)!=0)
    		{
    			ifso.write((char*)this,sizeof(*this));
			}
			else
			{
				if(strcmp(num1,book_idi)!=0)
				{
					ifso.write((char*)this,sizeof(*this));
				}
				else
				{
					if(t1==1)
					{
						int d1 = date;
    			        int m1  = mths;
    			        int y1 = year;
			            int d = tptr->tm_mday;	
				        int m = (tptr->tm_mon)+1;
				        int y = (tptr->tm_year)+1900;
				        int D = (y-y1)*365+(m-m1)*30+(d-d1);
				        if(D > 15)
				        {    
				    	   char c;
					       cout<<"\tLate Charge : "<<D-15<<endl;
					       cout<<"Late Charge Paid Enter(y/n) : ";cin>>c;
					       if(c=='y'||c=='Y')
					       {
					    	  flag = 1;
						   }
						   else
						   {
							  remove("bois.dat");
							  flag  = 2;
							  return flag;
					  	   }
				        }
				        else
				        flag = 1;
					}
				}
		    }	
		}
	}
	ifs.close();
	ifso.close();
	remove("bookiss.dat");
	rename("bois.dat","bookiss.dat");
	return flag;
}
void Books::showdatab()
{
	char s[40],s1[15],s2[6];
	int tt = 1;
	cout<<"\t";
    strcpy(s2,book_id);
    for(int i=0;i<10;i++)
    {
    	if(s2[i]!='a'&&tt)
    	cout<<s2[i];
    	else
    	{
    		tt=0;cout<<" ";
		}
	}
	tt=1;
    strcpy(s,Book_name);
    for(int i=0;i<42;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else {
    		tt=0;cout<<" ";
		}
	}
	strcpy(s,author_name);tt=1;
    for(int i=0;i<32;i++)
    {
    	if(s[i]!='1'&&tt)
    	cout<<s[i];
    	else {
    		tt=0;cout<<" ";
		}
	}
	cout<<Copy_available<<"            ";
	strcpy(s1,Edition);tt=1;
    for(int i=0;i<18;i++)
    {
    	if(s1[i]!='1'&&tt)
    	cout<<s1[i];
    	else {
    		tt=0;cout<<" ";
		}
	}
	cout<<endl;
}
void Books::store_datab(){
    ofstream file;
    file.open("book.dat",ios::app|ios::binary);
    file.write((char*)this,sizeof(*this));
}
int Books::view_filedatab(){
    ifstream file1;
    file1.open("book.dat",ios::in|ios::binary);
    if(!file1){
    cout<<"\t\tFile is not found"<<endl;
    return 0;}
    else{
        file1.read((char*)this,sizeof(*this));
        while(!file1.eof()){
            showdatab();
            file1.read((char*)this,sizeof(*this));
        }
        return 1;
    }
}
int Books::book_search(char* num,int t=1)
{
    ifstream ifb;
    ifb.open("book.dat",ios::in|ios::binary);
    int flag = 0;
    char s[40];
    while(!ifb.eof())
    {
        ifb.read((char*)this,sizeof(*this));
        if(ifb){
            if((strcmp(num,book_id))==0)
            {
            	cout<<endl;
            	strcpy(s,book_id);
            	strcpy(bi.book_idi,s);
                cout<<"\tBook id : ";replaces(s,'a');cout<<endl;
                strcpy(s,Book_name);
                strcpy(bi.Book_namei,s);
                cout<<"\tBook Name : ";replaces(s,'1');cout<<endl;
                strcpy(s,author_name);
                strcpy(bi.author_namei,s);
                cout<<"\tAuthor of book : ";replaces(s,'1');cout<<endl;
                int n = Copy_available;
                if(n||t)
                cout<<"\tCopy available : "<<n<<endl;
                else
                {
                	cout<<"\tCopy Not available"<<endl;
                	return flag;
				}
                strcpy(s,Edition);
                cout<<"\tEdition of book : ";replaces(s,'1');cout<<endl;
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}
void book_list()
{
    system("cls");
    alb();
    cout<<endl<<"                                                       BOOK LIST     "<<endl;
    cout<<"\t======================================================================================================================="<<endl;
    cout<<"\tBook id   Book Name                                Author Name           No. of Copy available  Book Edition"<<endl;
    cout<<"\t========================================================================================================================"<<endl;
    b.view_filedatab();
}
void main_menu();
void switch_main_menu(int c);
void student_menu();
void switch_studemenu(int c);
void adminstrator_menu();
void switch_admin_menu(int c);
void create_student_record();
void display_all_stud();
void display_spec_stud();
void modify_stud_rec();
void delete_stud_rec();
void create_book();
void display_spec_book();
void modify_book();
void delete_book();
void book_issue();
void book_deposit();
void delete_stud_rec()
{
	system("cls");
	alb();
	cout<<endl<<endl<<"\tDelete Student Record"<<endl;
	char num[6];
	cout<<"\t Enter the student admission number : ";
	cin>>num;
	strcat(num,"a");
	int flag;
	flag = s.delete_stud(num);
	if(flag)
	cout<<endl<<"\tDeleted Successfully"<<endl;
	else
	cout<<endl<<"\tStudent already not present"<<endl;
}
void delete_book()
{
	system("cls");
	alb();
	cout<<endl<<endl<<"\tDelete Book Record"<<endl;
	char num[6];
	cout<<"\t Enter the Book id : ";
	cin>>num;
	strcat(num,"a");
	int flag;
	flag = b.delete_book(num);
	if(flag)
	cout<<endl<<"\tDeleted Successfully"<<endl;
	else
	cout<<endl<<"\tBook already not present"<<endl;
}
void create_student_record()
{
	coome3:
    system("cls");
    alb();
    s.get_data();
    s.store_data();
    cout<<endl<<"\t***Student record Successfully Recorded***"<<endl<<endl;
    cout<<"If you Want store more record Enter(y/n) : ";
    char c;cin>>c;
    if(c=='y'||c=='Y')
    goto coome3;
}
void display_all_stud()
{
    system("cls");
    alb();
    cout<<endl<<"\t                            STUDENT LIST     "<<endl;
    cout<<"\t=============================================================================="<<endl;
    cout<<"\tAdmission no.    Student Name                     Class     No. of book Issued"<<endl;
    cout<<"\t=============================================================================="<<endl;
    s.view_filedata();
}
void display_spec_stud(){
	system("cls");
	alb();
	char s1[6];
	cout<<endl<<endl<<"\t\tEnter the Admission Number : ";
	cin>>s1;
	strcat(s1,"a");
	int n = s.search_student(s1);
	if(!n){
		cout<<"\tThis student in not in record"<<endl;
	}
}
void display_spec_book()
{
	coome4:
	system("cls");
	alb();
	char s[6];
	cout<<endl<<endl<<endl<<"\t\t\tEnter the Book id : ";
	cin>>s;
	strcat(s,"a");
	int n = b.book_search(s);
	if(!n)
	{
		cout<<"\t\tBook not found"<<endl<<endl;
		cout<<"If you Want check other book Enter(y/n) : ";
        char c;cin>>c;
        if(c=='y'||c=='Y')
        goto coome4;
	}
}
void book_issue()
{
	coome2:
	system("cls");
	alb();
	cout<<"\tBOOK ISUE...."<<endl<<endl;
	time_t t=time(NULL);
    tm* tptr = localtime(&t);
    int flag = 0;
    char num[6],num1[6];
    cout<<"\t\tEnter your Admission number : ";cin>>num;
    strcat(num,"a");
    char a[6],b1[35],c[35];
    ifstream ifs;
    ifs.open("student.dat",ios::in|ios::binary);
    while(!ifs.eof())
    {
        ifs.read((char*)&s,sizeof(s));
        if(ifs){
            if(strcmp(num,s.stud_admnum)==0)
            {
            	strcpy(a,s.stud_admnum);
            	strcpy(b1,s.student_name);
            	strcpy(c,s.stud_class);
            	if(s.num_of_book_issused<3)
				{
                   book_list();
                   cout<<endl<<"\t\tChoice book id which you want issued : ";cin>>num1;
                   strcat(num1,"a");
                   if(!bi.bookiss_search(num,num1))
                   {
                   	  int n = b.book_search(num1,0);
                      if(!n)
                      cout<<"\tBook are not found"<<endl;
                      else{
                      	   ofstream ifb;
                      	   strcpy(bi.stud_adm_noi,a);
            	           strcpy(bi.stud_namei,b1);
            	           strcpy(bi.classi,c);
                	       bi.date = tptr->tm_mday;
                	       bi.mths = (tptr->tm_mon)+1;
                	       bi.year = (tptr->tm_year)+1900;
                	       ifb.open("bookiss.dat",ios::app|ios::binary);
                	       ifb.write((char*)&bi,sizeof(bi));
                	       cout<<endl<<"\t***This Book is Successfully Issue***"<<endl<<endl;
                	       cout<<"\tNotice:"<<endl<<"\tWrite the current date backside of your book and Submit within 15 days...."<<endl<<"\tFine Rs. 1 for each day after 15 days period."<<endl<<endl;
                	       ifb.close();
				        }
                      flag = 1;
				   }
				   else
				   {
				   	  cout<<"\tYou already issue this book"<<endl;
				   	  cout<<"\tIf you Want more book Issue Enter(y/n) : ";
                      char c;cin>>c;
                      if(c=='y'||c=='Y')
                      goto coome2;
                      return ;
				   }
                }
                else
                {
                	cout<<"\tYou Cannot issue more than 3 book before submitted other"<<endl;
                	return ;
				}
            }
        }
    }
    ifs.close();
    if(!flag){
    	cout<<"\t***You are not registered in Library Student Recored Plz First Registered***"<<endl;
	}
	else
	{
		s.modify(num,4,2);
		b.modifyb(num1,4,1);
		cout<<"\tIf you Want more book Issue Enter(y/n) : ";
        char c;cin>>c;
        if(c=='y'||c=='Y')
        goto coome2;
	}
}
void modify_book()
{
	coome6:
	system("cls");
	alb();
	char c[6];
	int n1;
	cout<<endl<<endl<<"***Modify Book Record***"<<endl<<endl;
	cout<<"\tEnter the Book id : ";
	cin>>c;
	strcat(c,"a");
	cout<<"\t01. For Modify Book id"<<endl;
	cout<<"\t02. For Modify Book Name"<<endl;
	cout<<"\t03. For Modify Author Name"<<endl;
	cout<<"\t04. For Modify Copy available"<<endl;
	cout<<"\tEnter choice : ";cin>>n1;
	b.modifyb(c,n1);
	cout<<endl<<"\t\t\tModified Successfully"<<endl;
	cout<<"If you Want Modified more record Enter(y/n) : ";
    char c1;cin>>c1;
    if(c1=='y'||c1=='Y')
    goto coome6;
}
void modify_stud_rec()
{
	coome5:
	system("cls");
	alb();
	char c[6];
	int n1;
	cout<<endl<<endl<<"\tModify Student Record"<<endl;
	cout<<"\tEnter the admission number of student : ";
	cin>>c;
	strcat(c,"a");
	cout<<"\t01. For Modify Admission Number"<<endl;
	cout<<"\t02. For Modify Student Name"<<endl;
	cout<<"\t03. For Modify Student Class"<<endl;
	cout<<"\t04. For Modify No. of book issued"<<endl;
	cout<<"\tEnter choice : ";cin>>n1;
	switch(n1)
	{
		case 1:
			s.modify(c,1);
			break;
		case 2:
			s.modify(c,2);
			break;
		case 3:
			s.modify(c,3);
			break;
		case 4:
			s.modify(c,4);
			break;
	}
	cout<<endl<<"\t\t\tModified Successfully"<<endl;
	cout<<"If you Want Modified more record Enter(y/n) : ";
    char c1;cin>>c1;
    if(c1=='y'||c1=='Y')
    goto coome5;
}
void Issue_book_record()
{
	system("cls");
	alb();
	cout<<endl<<endl<<"\t\t\t \t\tBOOK ISSUE RECORD"<<endl;
	cout<<"\t=========================================================================================================================================================="<<endl;
	cout<<"\tAdmission no.     Student Name                    Class           Book id    Book Name                      Author                          DD/MM/YYYY"<<endl;
	cout<<"\t=========================================================================================================================================================="<<endl;
	bi.view_filedatabi();
}
void book_deposit()
{
	coome1:
	system("cls");
	alb();
	cout<<endl<<endl<<"                          BOOK DEPOSIT"<<endl<<endl;
	int flag = 0;
	char num[6],num1[6];
	cout<<"\t Enter the Admission Number  : "; cin>>num;
	strcat(num,"a");
	cout<<"\t Enter the Book id  : "; cin>>num1;
	strcat(num1,"a");
	flag = bi.delete_filei(num,num1);
	if(flag)
	{
		if(flag==2)
		{
			cout<<"\tBook not Deposited"<<endl;
		}
		else
		{
			cout<<"\t***Book Deposit Successfully***"<<endl;
		    s.modify(num,4,1);
		    b.modifyb(num1,4,2);
		}
	}
	else{
		cout<<"\t***Not issued any book on your account***"<<endl<<endl;
	}
	cout<<"If you Want deposit more more Enter(y/n) : ";
    char c;cin>>c;
    if(c=='y'||c=='Y')
    goto coome1;
}
void create_book()
{
	coome:
    system("cls");
    alb();
    b.get_datab();
    b.store_datab();
    cout<<endl<<"\t******Book is successfully added****** "<<endl<<endl;
    cout<<"If you Want more book Enter(y/n) : ";
    char c;cin>>c;
    if(c=='y'||c=='Y')
    goto coome;
}

void switch_admin_menu(int c)
{
    switch (c)
    {
    case 1:
        create_student_record();
        break;
    case 2:
        display_all_stud();
        break;
    case 3:
        display_spec_stud();
        break;
    case 4:
        modify_stud_rec();
        break;
    case 5:
        delete_stud_rec();
        break;
    case 6:
        create_book();
        break;
    case 7:
        book_list();
        break;
    case 8: 
        display_spec_book();
        break;
    case 9:
        modify_book();
        break;
    case 10:
        delete_book();
        break;
    case 11:
    	 Issue_book_record();
    	 break;
    case 12:
        p.change_passward();
        break;
    case 13:
        main_menu();
        break;
    case 14:
        exit(0);
        break;
    }
    
}
bool ShowPass()
{
	system("cls");
	alb();
	for(int i=0;i<5;i++)
	cout<<endl;
	cout<<"\t\t\tEnter Passward : ";
    char pa[20],ch;
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode =0;
    GetConsoleMode(hStdin,&mode);
    SetConsoleMode(hStdin,mode&(~ENABLE_ECHO_INPUT));
     cin>>ws;
     cin.getline(pa,20);
    ifstream ips;
    ips.open("passward.dat",ios::in|ios::binary);
    ips.read((char*)&p,sizeof(p));
    ips.close();
    if(strcmp(pa,p.repass())==0){
    	return true;}
    return false;
}
void adminstrator_menu()
{
    come3:
    if(t)
    {
    	 nnn = ShowPass();
    	 t=0;
	}
    if(nnn){
    system("cls");
    alb();
    int choice;
    cout<<endl<<endl<<"\tADMINSTRATOR MENU :"<<endl;
    cout<<"\t==========================================="<<endl<<endl;
    cout<<"\t01. CREATE STUDENT RECORD"<<endl<<endl;
    cout<<"\t02. DISPLAY ALL STUDENTS RECORD"<<endl<<endl;
    cout<<"\t03. DISPLAY SPECIFIC STUDENT RECORD"<<endl<<endl;
    cout<<"\t04. MODIFY STUDENT RECORD"<<endl<<endl;
    cout<<"\t05. DELETE STUDENT RECORD"<<endl<<endl;
    cout<<"\t06. CREATE BOOK"<<endl<<endl;
    cout<<"\t07. DISPLAY ALL BOOKS"<<endl<<endl;
    cout<<"\t08. DISPLAY SPECIFIC BOOK"<<endl<<endl;
    cout<<"\t09. MODIFY BOOK"<<endl<<endl;
    cout<<"\t10. DELETE BOOK"<<endl<<endl;
    cout<<"\t11. BOOK ISSUE RECORD"<<endl<<endl;
    cout<<"\t12. CHANGE PASSWARD"<<endl<<endl;
    cout<<"\t13. BACK TO MAIN MENU"<<endl<<endl;
    cout<<"\t14. EXIT"<<endl<<endl;
    cout<<"\tPlease Enter your choice (1-14) : ";
    cin>>choice;
    cout<<endl<<"\t==========================================="<<endl<<endl;
    switch_admin_menu(choice);}
    else{
        cout<<"\t***Wrong Passward for try again press any key : ***"<<endl;
        getchar();
        goto come3;
    }
}
void switch_studemenu(int c)
{
    switch (c)
    {
    case 1:
        book_issue();
        break;
    case 2:
        book_deposit();
        break;
    case 3:
        book_list();
        break;
    case 4:
        main_menu();
        break;
    case 5:
        exit(0);
        break;
    }
    
}
void student_menu()
{
    system("cls");
    alb();
    int choice;
    cout<<endl<<"\tSTUDENT MENU :"<<endl;
    cout<<"\t==========================================="<<endl<<endl;
    cout<<"\t01. BOOK ISSUE"<<endl<<endl;
    cout<<"\t02. BOOK DEPOSIT"<<endl<<endl;
    cout<<"\t03. BOOK LIST"<<endl<<endl;
    cout<<"\t04. MAIN MENU"<<endl<<endl;
    cout<<"\t05. EXIT"<<endl<<endl;
    cout<<"\tPlease select Your Choice (1-5) : ";
    cin>>choice;
    cout<<endl<<"\t==========================================="<<endl<<endl;
    switch_studemenu(choice);
}
void adminstrator_menu();
void switch_main_menu(int c){
    switch (c)
    {
    case 1:
        student_menu();
        break;
    case 2:
        adminstrator_menu();
        break;
    case 3:
         exit(0);
        break;
    }
}
void main_menu()
{
    system("cls");
    alb();
    int choice;
    cout<<endl<<"\tMain Menu"<<endl;
    cout<<"\t=========================================="<<endl<<endl;;
    cout<<"\t01. STUDENT MENU"<<endl<<endl;;
    cout<<"\t02. ADMINISTRATOR MENU"<<endl<<endl;;
    cout<<"\t03. EXIT"<<endl<<endl;;
    cout<<"\tPlease select your option (1-3) : ";
    cin>>choice;
    cout<<endl<<"\t=========================================="<<endl;
    switch_main_menu(choice);
}
using namespace std;
int main(){
	t=1;
	int c = 1;
    while(1)
    {
        switch(c)
        {
        	case 1: main_menu();break;
        	case 2: adminstrator_menu();break;
        	case 3: student_menu();break;
		}
        cout<<endl<<"\t=============================================================================================================="<<endl;
        cout<<"\tPress 1. Back to main menu \n\tPress 2. Back to adminstratormenu\n\tPress 3. Back to Student menu: ";
        cin>>c;
    }
}