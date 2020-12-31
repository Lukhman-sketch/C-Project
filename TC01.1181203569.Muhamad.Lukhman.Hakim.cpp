/**********|**********|**********|
Program: TC01.1181203569.Muhamad.Lukhman.Hakim.cpp
Course: Object Oriented Programming
Year: 2019/20 Trimester 1
Name: Muhamad Lukhman Hakim Bin Mohd Nizam
ID: 1181203569
Lecture Section: TC01
Tutorial Section: TT06
Email: 1181203569@student.mmu.edu.my
Phone: 011-60572870
**********|**********|**********/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <ctime>
#include <ostream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>

void login();
void wantogo_again(); 					//function for repeat the program if uer want to continue
void update_user();
using namespace std;

class ShopItem{							//Class for shop item
	
	protected:
		char item_name[30];					
		float item_price;
		int number_of_unit;
		char company_name[30];
		int id;
		char year_publish_magazine[30];
		char newname[30];
		char main_actor_movie[30];
		char new_company[30];
		char new_extrainfo[30];
		int new_unit;
		float new_price;
		char type [30];
	
	
	public:
		void menu();
		void insert_data();        
		void update_data();
		void delete_data();	
		void sale_analysis();
	virtual	void display_all();

};

class Book: public ShopItem{
	
	private:
		string book = "Book";					//define Book type 
		char author_name_book[30];
	public:
		Book(); 							  // deafult constructor for book 
};

class Magazine: public ShopItem{
	
	private:
		string magazine = "Magazine";		//define Magazine type 
		char year_publish_magazine[30];		
	public:
		Magazine();  						// deafult constructor for magazine 
};

class Movie: public ShopItem{
	
	private:
		string movie ="Movie";			//define Movie type 
		char main_actor_movie[30];
	public:
		Movie();  						// deafult constructor for movie 
};

int main(){
ShopItem call;										//deaclare call obj for shopitem in intmain
int i;
cout << "	~~~~~~~~~~				~~~~~~~~~~\n";
cout << "	~~~~~~~~~~	ADMINISTATION PAGE	~~~~~~~~~~\n";
cout << "	~~~~~~~~~~	    -WELCOME-		~~~~~~~~~~\n";
cout << "	~~~~~~~~~~	LOGIN TO CONTINUE	~~~~~~~~~~\n";
cout << "	~~~~~~~~~~				~~~~~~~~~~\n"<<endl;

login();											//calling the login function inside int main
call.menu();										//calling the Menu function inside int main from shopitem obj call
do{
wantogo_again();									//calling the repeat program function inside int main, ask user to keyin if they want ot continue or not
}while(i<3);										//expired or terminated after 3 times 

cout<<"\nSession Expired";
}

void ShopItem::menu(){									//function for menu 
	ShopItem call;													//deaclare call obj for shopitem in intmain
	int option;
	
cout << "\n	\t\t\t~~~~~~~~~~				~~~~~~~~~~\n"<<endl;
cout << "	\t\t\t@@@@@@@@@@				@@@@@@@@@@\n"<<endl;									//INTERFACE FOR MENU 
cout << "	\t\t\t@@@@@@@@@@				@@@@@@@@@@\n";												//INTERFACE FOR MENU 
cout << "	\t\t\t@@@@@@@@@@	       MENU 		@@@@@@@@@@\n";											//INTERFACE FOR MENU 
cout << "	\t\t\t@@@@@@@@@@	 SELECT AN OPTION	@@@@@@@@@@\n";											//INTERFACE FOR MENU 
cout << "	\t\t\t@@@@@@@@@@				@@@@@@@@@@\n";											//INTERFACE FOR MENU 
cout << "	\t\t\t@@@@@@@@@@				@@@@@@@@@@\n"<<endl;											//INTERFACE FOR MENU 
cout << "	\t\t\t@@@@@@@@@@				@@@@@@@@@@\n"<<endl;											//INTERFACE FOR MENU 
cout << "	\t\t\t~~~~~~~~~~				~~~~~~~~~~\n\n"<<endl;											//INTERFACE FOR MENU 


cout << "[1]View Item 				[ENTER][1]\n";											//INTERFACE FOR MENU 
cout << "[2]Insert New Item 			[ENTER][2]\n";										//INTERFACE FOR MENU 
cout << "[3]Update Information of Item 		[ENTER][3]\n";											//INTERFACE FOR MENU 
cout << "[4]Delete Item 				[ENTER][4]\n";											//INTERFACE FOR MENU 
cout << "[5]Update Username And Password 	[ENTER][5]\n";											//INTERFACE FOR MENU 
cout << "[6]Sale Data Analysis 			[ENTER][5]\n";											//INTERFACE FOR MENU 
cout << "[7]Logout 				[ENTER][6]\n";											//INTERFACE FOR MENU 

do{

cout << "\nEnter Your Option : ";
cin  >> option;
switch(option) {
	
	case 1: 
			call.display_all();															//display all the item list
			break;
	case 2:	
			call.insert_data();															//Insert new data of item
			break;
	case 3:
			call.update_data();															//Update data of item by finding item id
			break;
	case 4:
			call.delete_data();															//Delete certain item
			break;
	case 5: 
			update_user();																//Update The username and password
			break;
			
	case 6:
			call.sale_analysis();														//search , sort data by produnt name , company name and type
			break;
				
	case 7:
			cout << "You have been logout, See you again sir. Thank you";				//logout 
			exit(0);
			break;
	default: 																			//if the user input wrong option , display invalid input 														
			cout << "\nINVALID INPUT TRY AGAIN";
			
}
}while (option > 6);
	
}												 /*menu function end here*/ 

//function for login
void login(){
	char bold = 27;
	cout << "-Please Enter Your Username And Password-" <<endl;										//display Enter Your Username And Password
		
	char username[10], password[10], stored_uname[10], stored_pswd[10];								// variable for login
	fstream pull("owner.txt",ios::in);																//open and write to text file owner.txt
	
	/*stored_uname and stored_pswd is to compare the username 
	and user password , strcmp use to compare the input 
	if the data inside the owner.txt exist than it will take the user to
	menu. if the input not same in the text file, it will display
	try again and enter the input again, so the ues can continue using the program*/
	
      	pull >> stored_uname;																		
		cout << "Enter Username : ";
		cin >> username;																			 
			while(strcmp(stored_uname,username)){												
			cout << "\nUsername not exist" << endl;																			
			cout << "Try Again\n" << endl;															
			cout << "Enter Username : ";																									
			cin >> username; 																		
			}
			
		pull >> stored_pswd;
		cout << "Enter Password : ";
		cin >> password;
			while(strcmp(stored_pswd,password)){
			cout << "\nWrong Password" << endl;
			cout << "Try Again\n" << endl;
			cout << "Enter Password : ";
			cin >> password; 	
			}
			
cout << "\nLogin Successful" << endl;
}												 /*login function end here*/ 

void update_user(){
	
	char username[10], password[10]; 
	
	fstream owner;
	fstream temp;
	
	owner.open("owner.txt", ios::in);													//open the owner.txt to write file
	temp.open("temp.txt", ios::out);													//and pass the new data to temp.txt file
	
	cin.ignore();

	while(!owner.eof()){
		owner.getline(username,10);														//get the previous data from the file
		owner.getline(password,10);
		
	if(strcmp(username,password)){														//compare the the old data
	
		
		cout << "\nNow You can enter your new username : ";								//user key in the new data
		cin.getline(username,10);														
		cout << "\nEnter your new password : ";
		cin.getline(password,10);
		temp << username<< "\t" << password;
		
	}
	else{
		
		
		temp << username<< "\t" << password;											//when the data not complete or dont have data inside the text file and error
	}																					//terminated program and save old data
}
	temp.close();
	owner.close();
	owner.open("owner.txt", ios::out);													//pause the owner.txt
	temp.open("temp.txt", ios::in);														//open and hold the new input inside temp.txt
	
	while(!temp.eof()){
		
		temp.getline(username,10);														//get the new input
		temp.getline(password,10);														//pass the new input to own.txt
		owner << username<< "\t" << password;
	}
	temp.close();																		//close both file and remove temp.txt
	owner.close();																		
	remove("temp.txt");
	cout << "------------------------------";
	cout << "\nSuccessfully update"<<endl;
	cout << "------------------------------";
	
}

void ShopItem::insert_data(){														/*inser DATA function*/
	

	int type;
	cout << "\n------------------------------";
	cout << "\n	TYPE";
	cout << "\n------------------------------";
	cout << "\n[1]Magazine 		[ENTER][1]\n";
	cout << "\n[2]Book 		[ENTER][2]\n";
	cout << "\n[3]Movie 		[ENTER][3]\n";
do{	
	cout << "\nSelect type : ";
	cin >> type;																	//user can pick what type of data to insert
	if(type == 1){
		Magazine myObj;																//call the book insert data constractor,user will key in the data there
		cout << "Successfully Update";
			
	}else if(type == 2){
		Book myObj;																//call the magazine insert data constractor, user will key in the data there																	
		cout << "Successfully Update";
		
	}else if(type == 3){
		Movie myObj;																//call the movie insert data constractor,user will key in the data there
		cout << "Successfully Update";
		
	}else{	
		cout << "\nINVALID INPUT";													//if the user give wrong input, it will display the alert  
	}
}while( type!= 1 && type!= 2 && type!= 3 );

	 
}

void wantogo_again(){
	ShopItem call;											//deaclare call obj for shopitem class in wantogo_again fucntion to take vaiable 
	char yesno;
	cout << "\nYou want to continue using the program [Y/N] : ";			
	cin >> yesno;
	
	switch(yesno){
		
		case 'y':
			
			call.menu();														//this function will loop everytime when user finish , update delete view item view sale analysis
			break;																//and insert new data 
		 default: exit(0);														//if the user pick Y , it will reapeat and bring user to the menu 
		 break;																	//call menu function inside this function
		 
	}
	
}

void ShopItem::display_all(){
	
	int line_no = 0;

	cout<<"\n\t\t\t==================================================================";
	cout<<"\n\n\t\t\t=================\tALL LIST OF THE ITEM\t==================";
	cout<<"\n\n\t\t\t==================================================================\n\n";
	cout<<"ID	   NAME           COMPANY NAME      EXTRA INFO	    TOTAL UNIT	   PRICE(RM)	       TYPE";
	cout<<"\n\n\t===================================================================================================\n";	
	string display;
	ifstream displayitem("shopitem.txt");
	char x;
	if(displayitem.is_open()){	
			do{																						//display all item, only 10 item can be shown on the kiosk																						//
			for (int i = 0; i <=9; i++)																//aks user to to see another page of item , if the item is many	
			{																						//if user pick y display next page, if user pick n it will take back to wantogo_again fucntion
			getline(displayitem,display);															
			cout << display << endl;
			}
			cout << "\nCONTINUE NEXT PAGE [Y/N] ? : ";
			cin >> x;
			if(x=='Y' || x =='y');
			
			}while(x=='Y' || x=='y');	
		
		
	}
}
Magazine::Magazine(){					//calling constractor for magazine
	
		srand((unsigned)time(0));
		id= (rand()% 999) + 2000;						//auto generate id , cannot be change by the user 
		fstream owner;
		owner.open("shopitem.txt", ios::app);	 
		cin.ignore();
		cout << "\nAuto Generate ID : "<<id;
		cout << "\nEnter magazine name : ";								//if the uesr pick magazine from insert data function it will bring the user to magazine constractor 
		cin.getline(item_name,30);										//take the input from the uesr
		cout << "Enter company name : ";								// save to the shopitem.txt file
		cin.getline(company_name,30);
		cout << "Enter year of publish [YYYY/MM]: ";
		cin.getline(year_publish_magazine,30);
		cout << "How many unit/stock do you want to add : ";
		cin>>number_of_unit;
		cout << "Set item price : RM";
		cin>>item_price;
																			
		owner<<id<<"\t|"<<item_name<<"	\t|"<<company_name<<"\t\t|"<<year_publish_magazine<<"\t\t|"<<number_of_unit<<"\t\t|RM"<<item_price<<"\t\t|"<<magazine<<"\n";
	
}
Book::Book(){					//calling constractor for book
	
		srand((unsigned)time(0));				//auto generate id , cannot be change by the user
		id = (rand()% 999) + 2000;	
		fstream owner;											//if the uesr pick Book from insert data function it will bring the user to Book constractor 
		owner.open("shopitem.txt", ios::app);	 				//take the input from the uesr
		cin.ignore();											// save to the shopitem.txt file
		cout << "\nAuto Generate ID : "<<id;
		cout << "\nEnter book name : ";
		cin.getline(item_name,30);
		cout << "Enter company name : ";
		cin.getline(company_name,30);
		cout << "Enter author name of the book : ";
		cin.getline(author_name_book,30);
		cout << "How many unit/stock do you want to add : ";
		cin>>number_of_unit;
		cout << "Set item price : RM";
		cin>>item_price;
		
		owner<<id<<"\t|"<<item_name<<"	\t|"<<company_name<<"\t\t|"<<author_name_book<<"\t\t|"<<number_of_unit<<"\t\t|RM"<<item_price<<"\t\t|"<<book<<"\n";	
}

Movie::Movie(){				//calling constractor for movie
	
		srand((unsigned)time(0));
		id = (rand()% 999) + 2000;					//auto generate id , cannot be change by the user
		fstream owner;
		owner.open("shopitem.txt", ios::app);	 					//if the uesr pick Movie from insert data function it will bring the user to Movie constractor 
		cin.ignore();													//take the input from the uesr
		cout << "Auto Generate ID : "<<id;								// save to the shopitem.txt file
		cout << "\nEnter movie name : ";
		cin.getline(item_name,30);
		cout << "Enter company name : ";
		cin.getline(company_name,30);
		cout << "Enter main actor name of the movie : ";
		cin.getline(main_actor_movie,30);
		cout << "How many unit/stock do you want to add : ";
		cin>>number_of_unit;
		cout << "Set item price : RM";
		cin>>item_price;
		
		owner<<id<<"\t|"<<item_name<<"	\t|"<<company_name<<"\t\t|"<<main_actor_movie<<"\t\t|"<<number_of_unit<<"\t\t|RM"<<item_price<<"\t\t|"<<movie<<"\n";
}

void ShopItem::update_data(){
	
	string magazine = "Magazine";	
	string book = "Book";												//update item information 
	string movie ="Movie";
  	string find;
	string line;
	ifstream read_file2("shopitem.txt");
	ifstream read_file("shopitem.txt");
	ofstream myfile;
    myfile.open("data.txt");
	ofstream temp;
	cout <<"Please enter item ID to find the item: ";						//must input item id first to verify item , if the item id not found , it will display alert
	cin >>find;
	if(read_file.is_open()){												//open file shopitem.txt
		
		
		temp.open("temp.txt");
		while(getline(read_file, line)){
			
			if(line.find(find)!=string::npos){								//if the item id(find) = item id in the file shop.txt
				
				temp << line <<endl;										//it will copy all the data file to temp.txt
				
			}
		}  	
			read_file2.close();
    		temp.close();
    		remove("shopitem.txt");
    		rename("temp.txt", "shopitem.txt");								//next it will ask the user to input new data of that specific item refer by item id 
    	
				cout << "\n==============================";	
				cout << "\n	Item ID verify !\n";								//all the data that been keyin will be in the temp.txt 
				cout << "==============================\n";						//next all the it will remove the original shopitem.txt
				cin.ignore();													//then temp.txt will be rename as shopitem.txt and be replaced the original file 
				cout << "Enter item name : ";									// with new update data
				cin.getline(item_name,30);
				cout << "Now you can insert new company name : ";
				cin.getline(new_company,30);			
				cout << "Enter new extra information : ";
				cin.getline(new_extrainfo,30);
				cout << "Update number of unit : ";
				cin >> new_unit;														
				cout << "Update price : ";
				cin >> new_price;
				cin.ignore();
				cout << "Select Type [Enter]Magazine // [Enter]Book // [Enter]Movie : ";
				cin.getline(type,30);																
																									
				ofstream myfile;																		
    			myfile.open("shopitem.txt", ios::app | ios::out);
    			myfile<<find<<"\t|"<<item_name<<"	\t|"<<new_company<<"\t\t|"<<new_extrainfo<<"\t\t|"<<new_unit<<"\t\t|RM"<<new_price<<"\t\t|"<<type<<"\n";
	}
	else{
		
		cout <<find<<" not found"<<endl;
	
	}
	myfile.close();
	
	read_file.close();

}

void ShopItem::delete_data(){
	
	string find;
	string line;					
	int deleteline;													//must input item id first to verify item , if the item id not found , it will display alert
	ifstream read_file2;
	read_file2.open("shopitem.txt");
	ofstream myfile;												//open file shopitem.txt
	myfile.open("newdata.txt");											//if the item id(find) = item id in the file shop.txt
	cout <<"Please enter item ID to find the item: ";							//it will copy all the data file to temp.txt
	cin>>find;																//
	while (getline(read_file2,line))
	{
		if(line.find(find)!=string::npos)
		{
			myfile<<line<<endl;
			cout<<"Record Deleted"<<endl;
		}
		else
		{
				cout <<find<<" not found"<<endl;
		}
	}
	myfile.close();
	read_file2.close();
	remove("shopitem.txt");
	rename("temp.txt","shopitem.txt");
	
}

void ShopItem::sale_analysis(){							//sale analysis fucntion 
										
	string find;
	string line;
	ShopItem::display_all();
	ifstream read_file("sales_analysis.txt");
	cout<<"\n\n\t\t\t=================WELCOME TO SALE ANALYSIS==================\n";
	cout<< "\nSort By Company, Item Name and Type\n";
	cout <<"\nExample sort by company name:- 	Enter the information you want to search : Marvel Inc ";
	cout <<"\nExample sort by item name:- 	Enter the information you want to search : Need for speed ";
	cout <<"\nExample sort by type:- 		Enter the information you want to search : movie \n";
	cout <<"\nEnter the information you want to search : ";
	cin >>find;
	cout<<"\n\t\t\t==================================================================";
	cout<<"\n\n\t\t\t=================\tSALE ANALYSIS\t==================";
	cout<<"\n\n\t\t\t==================================================================\n\n";
	cout<<"ID	   QUANTITY           TOTAL      COMPANY	    ITEM NAME	   TYPE	       ";
	cout<<"\n\n\===========================================================================================================\n";							
	
	if(read_file.is_open())													//search the data by company name , product type and product name
	{
		
		while(getline(read_file, line))
		{																		//if the user want to see all product sale by company name, the user must key in the company name
			if(line.find(find)!=string::npos)									// and it will display all the product that relate to the company name only
			{																	//and same goes to product type and product name , user must key in the infomation
				cout <<line<<endl;												//and it will be sort by that category only
			}
		}
	}
	else{
		
		cout <<find<<" not found"<<endl;
	
	}
}
