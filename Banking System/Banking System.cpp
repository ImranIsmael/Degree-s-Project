//Banking System	Section 12
//1. Muhammad Imran bin Ismael			1810633
//2. Muhammad Nazrul Hakim bin Zulkifli 1812737
//3. Muhammad Firdaus bin Mahasan 		1815813	

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std ;

int total,choice ;

class details
{
	private:
		string name , acc_type ;
		string acc_no, pass ;
		double amount ;
	public:
		void new_account() ;
		void set_name(string) ;
		void set_accno(string) ;
		void set_bal(double) ;
		void set_acctype(string) ;
		void set_pass(string);
		string get_name() ;
		string get_accno() ;
		double get_bal() ;
		string get_acctype() ;
		string get_pass();
		
};

details user[50] , new_user ; // Global object

void read_new() ; //Read data from file
void update(bool) ; //Update the new data into text file
void view_info() ; //Display a single account details
void existed_preview(); //Display all account details
void deposit_withdraw(int) ; //Add or substract from account balance
void account_transfer(); //Transfer balance between two accounts
bool check( string , int ); //Verify account number and password


void details::set_accno(string t)
{	
	acc_no = t ;
}

void details::set_name(string n)
{	
	name = n ;
}
void details::set_pass(string h)
{
	pass = h;	
}
void details::set_bal(double b)
{	
	amount = b ;
}

void details::set_acctype(string p)
{	
	acc_type = p ;
}

string details::get_accno()
{
	return acc_no ;
}

string details::get_name()
{
	return name ;
}
string details::get_pass()
{
	return pass;
}
string details::get_acctype()
{
	return acc_type ;
}

double details::get_bal()
{
	return amount ;
}

int main()
{
	ofstream outfile ;
	ifstream infile ;
	int i ;
	double x ;
	bool one = false ;

	read_new() ;
	cout<<"\n\n\n\n\t\t\t\t\t"<<"~~~~~~~~~~~~~~~~~~~~~~~~\n" ;
	cout<<"\t\t\t\t\t"<<"||Welcome to Bank Crupt||\n" ;
	cout<<"\t\t------------------------------------------------------------------------" << endl ;
	
	system("pause");
	system("cls");
	do
	{
		do
		{
			cout<<"\n\n\n\n\t\t\t\t\t**************************\n";
			cout<<"\t\t\t\t\t1.Create a new account\n";
			cout<<"\t\t\t\t\t2.Deposit\n";
			cout<<"\t\t\t\t\t3.Withdraw\n";
			cout<<"\t\t\t\t\t4.View account details\n";
			cout<<"\t\t\t\t\t5.Transfer\n";
			cout<<"\t\t\t\t\t6.Account Previews\n";
			cout<<"\t\t\t\t\t7.Quit\n";
			cout<<"\t\t\t\t\t**************************\n";
			cout<<"\n\n\t\t\t\t\tSelect your choices(1-6):";
			cin>>choice;
			cin.ignore() ;
			
			if (choice<1||choice>7)
			{
				cout<<"Invalid, re-enter:"<<endl;
				system("pause") ;
			}
			system("cls") ;
		}while (choice<1||choice>7) ;
		switch(choice)
		{
			case 1://Create Acc
				{
					new_user.new_account() ;
					one = true ;
					update(one) ;
					read_new() ;
					cout<<endl;
					break;
				}
			case 2://Deposit
				{
					deposit_withdraw(2) ;
					one = false ;
					update(one) ;
					cout << endl ;
					break ;
				}
			case 3://Withdraw
				{
					deposit_withdraw(3) ;
					one = false ;
					update(one) ;
					cout<<endl;
					break;
				}
			case 4://View details
				{
					view_info() ;
					cout<<endl;
					break;
				}
			case 5:
				{
					account_transfer();
					one=false;
					update(one);
					cout<<endl;
					break;
				}
			case 6://Preview all acc
				{
					existed_preview();
					break;
				}
			case 7://Quit
				{
					cout << "\n\n\t\t\t\t  ~Thank you for using our service~" << endl ;
					break;
				}
		}
	}while(choice !=7 );
	
	return 0 ;
}

void read_new()
{
	ifstream infile ;
	char s ;
	string temp ;
	int i =0 , j = 0 ;
	double k ;
	
	infile.open("file.txt") ;
	while ( infile.get(s) )
	{
		if ( s != '\t' && s != '\n' )
		{
				temp += s ;
		}
		if ( s == '\t' && j == 0 )
		{
			user[i].set_accno(temp) ;
			temp = "" ;
			j++ ;
		}
		else if ( s == '\t' && j == 1 )
		{
			user[i].set_name(temp) ;
			temp = "" ;
			j++ ;
		}
		else if ( s == '\t' && j == 2 )
		{
			user[i].set_acctype(temp) ;
			temp = "" ;
			j++ ;
		}
		else if ( s == '\t' && j == 3 )
		{
			k = atof( temp.c_str() ) ;
			user[i].set_bal(k) ;
			temp = "" ;
			j++ ;
		}
		else if ( j == 4 && s == '\n' )
		{
			user[i].set_pass(temp);
			temp = "";
			i++ ; j = 0 ;
		}
	}
	
	total = i ;
}

void view_info()
{
	int i ;
	string no1 ;
	bool flag ;

	cout << "\n\t\t\tEnter your accout number: " ;
	getline(cin,no1) ;
	
	for ( i = 0 ; i < 50 ; i++ )
	{
		if ( no1 == user[i].get_accno() )
		{
			cout << "\n\n\n\t\t\tAccount Number : " << user[i].get_accno() << endl
				 << "\t\t\tName           : " << user[i].get_name() << endl
				 << "\t\t\tAccount Type   : "<< fixed << setprecision(2) << user[i].get_acctype() << endl
				 << "\t\t\tBalance        : RM " << user[i].get_bal() << endl ;
				 
			system("pause") ;
			system("cls") ;
			flag = true ;
			break ;
		}
	}
	if ( flag == false )
	{
		cout << "\n\t\t\tAccount not found.\n" ;
		system("pause") ;
		system("cls") ;
	}
}

void existed_preview()
{
	int x;
	
	cout<< "\n\n\t\t\t~All Account Details~" << endl;
	for(x=0;x<total;x++)
	{
		cout << "\n\n\n\t\t\tAccount Number : " << user[x].get_accno() << endl
			 << "\t\t\tName           : " << user[x].get_name() << endl
			 << "\t\t\tAccount Type   : " << fixed << setprecision(2) << user[x].get_acctype() << endl
			 << "\t\t\tBalance        : RM " << user[x].get_bal() << endl ;
	}
	
	system("pause");
	system("cls");
}

void deposit_withdraw(int x)
{
	int i ;
	double a , c ;
	string no2 , pw ;
	bool no_match , pw_match ;

	cout << "\n\t\t\tEnter your account number: " ;
	cin >> no2 ;
	cout << "\n\t\t\tPassword : " ;
	cin >> pw ;
	no_match = check( no2 , 1 ) ;
	pw_match = check( pw , 2 ) ;
	if ( no_match == 1 && pw_match == 1 )
	{
		for ( i = 0 ; i < total ; i++ )
		{
			if ( no2 == user[i].get_accno() )
			{	
	   		 	if( x == 2 )
				{
					cout << "\n\t\t\tEnter the amount to be deposited : " ;
					cin >> c ;
					a = user[i].get_bal() ;
					a = a + c ;
					user[i].set_bal(a) ;
					cout << "\n\n\t\t\tAmount deposited successfully." << endl ;
					system("pause") ;
					system("cls") ;
					break ;
				}
				else if( x == 3 )
				{
					cout << "\n\t\t\tEnter the amount to be withdrawn : " ;
					cin >> c ;
					a = user[i].get_bal() ;
					if ( a == 0 )
					{
					cout << "Your account has no balance left.\n" ;
					}
					else if ( a < c )
					{
						cout << "Insufficient balance.\n" ;
					}
					else
					{
						cout << "\n\n\t\t\tRequest accepted." << endl ;
						a = a - c ;
						user[i].set_bal(a) ;
					}
					system("pause") ;
					system("cls") ;
					break ;
				}
			}
		}
	}
	else if ( no_match == 1 && pw_match == 0 )
	{
		cout << "\n\t\t\tWrong password.\n" ;
		system("pause") ;
		system("cls") ;	
	}
	if ( no_match == 0 )
	{
		cout << "\n\t\t\tAccount not found.\n" ;
		system("pause") ;
		system("cls") ;
	}
}

void account_transfer()
{
	int i, a1, x1 ;
	double a , c , x,temp ;
	string no2 , no3 , pass ;
	bool flag=false;
	bool flags=false , no_match , pw_match ;

	cout << "\n\t\t\tEnter your account number: " ;
	cin >> no2 ;
	cout << "\n\t\t\tPassword : " ;
	cin >> pass ;
	no_match = check( no2 , 1 ) ;
	pw_match = check( pass , 2 ) ;
	if ( no_match == 1 && pw_match == 1 )
	{
		cout<<  "\n\t\t\tEnter the account to transfer to:" ;
		cin >> no3 ;
		for ( i = 0 ; i < 50 ; i++ )
		{
			if ( no2 == user[i].get_accno())
			{
				a = user[i].get_bal() ;
				a1=i;
			}
			else if ( no3 == user[i].get_accno())
			{
				x=user[i].get_bal();
				x1=i;
				flags=true;
			}
		}
	
		if ( flags == true )
		{
			cout << "\n\t\t\tEnter the amount to be transfered : ";
			cin >> c ;
			temp=c;
			a= a-c;
			x= x+c;
		
			user[a1].set_bal(a) ;
			user[x1].set_bal(x) ;

			cout<<" \n\t\t\tTransfer sucessfull."<<endl;
			system("pause") ;
			system("cls") ;
		}
		else if ( flags == false)
		{
			cout << "\n\n\t\t\tThe account you wish to transfer to does not exist.\n";

			system("pause") ;
			system("cls") ;
		}
	}
	else if ( no_match == 1 && pw_match == 0 )
	{
		cout << "\n\t\t\tWrong password.\n" ;
		system("pause") ;
		system("cls") ;	
	}
	if ( no_match == 0 )
	{
		cout << "\n\t\t\tAccount not found.\n" ;
		system("pause") ;
		system("cls") ;
	}
}

void details::new_account()
{

	int x , z = 0 ;
	bool flag ;
	
	do
	{
		flag = false ;
		cout << "\n\t\t\tEnter the account number: " ;
		getline(cin,acc_no) ;
		
		for ( z = 0 ; z < 50 ; z++ )
		{
			if ( acc_no == user[z].get_accno() )
			{
				cout << "\n\t\t\tAccount number already existed. Enter a new one.\n" ;
				flag = true ;
				system("pause") ;
				system("cls") ;
				break ;
			}
		}
	}while ( flag == true ) ;
	
	cout << "\t\t\tEnter the name of account holder : " ;
	getline(cin,name);
	
	do
	{
		cout << "\t\t\tSelect the type of account you want to create:" << endl << "\t\t\t\t1.Savings\n" << "\t\t\t\t2.Current\n\t\t\t" ;
		cin >> x ;
		if ( x!=1 && x!=2 )
			cout << "\t\t\tInvalid Choice." << endl ;
	}while( x!=1 && x!=2 ) ;
	
	if ( x == 1 )
		acc_type = "Savings" ;
	else
		acc_type = "Current" ;
	cin.ignore();
	
	cout<<"\t\t\tCreate a password : ";
	getline(cin,pass);
	
	do
	{
		cout << "\t\t\tEnter the amount to be deposited ( minimum MYR 50 ) : " ;
		cin >> amount ;
		if ( amount < 50.00 )
			cout << "\t\t\tAmount not sufficient." << endl ;
	}while( amount < 50.00 ) ;
	

	
	cout << "\t\t\tAccount Created." << endl ;
	system("pause") ;
	system("cls") ;
}

bool check(string a , int x )
{	
	int i ;
	bool found = false ;
	
	if ( x == 1 )
	{
		for ( i = 0 ; i < total ; i++ )
		{
			if ( a == user[i].get_accno() )
			{
				found = true ;
			}
		}
	}
	else if ( x == 2 )
	{
		for ( i = 0 ; i < total ; i++ )
		{
			if ( a == user[i].get_pass() )
			{
				found = true ;
			}
		}
	}
	
	return found ;
}

void update(bool x)
{
	ofstream outfile ;
	outfile.open("file.txt") ;
	outfile << fixed << setprecision(2) ;
	for ( int i = 0 ; i < total  ; i++ )
	{
		outfile << user[i].get_accno() << "\t" << user[i].get_name() << "\t" << user[i].get_acctype() << "\t" << user[i].get_bal() << "\t" << user[i].get_pass() << endl ;
	}
	if ( x == true )
	{
		outfile << new_user.get_accno() << "\t" << new_user.get_name() << "\t" << new_user.get_acctype() << "\t" << new_user.get_bal() << "\t" << new_user.get_pass() <<endl ;
		total++ ;
	}
	outfile.close() ;
}

