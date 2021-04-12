// Shekhar Sharma
// Restaurant Management
//Header Files Used

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

class restaurant                   //Class Resturant Declared
{
	private:

	  char nm[25];
	  float rating;
	  char cuisine[25];
	  float price_per_person;
	  char location[20];
	  char fuctionality;


	public:


	  int id;

	  void getdata(int x)          //function to get data from the user

	  {
		  id=x;



	       cout<<"enter name :  ";
	       gets(nm);

	       cout<<"enter rating :  ";
	       cin>>rating;


	       cout<<"1. Italian"<<endl;
	       cout<<"2. Chinese"<<endl;
	       cout<<"3. Indian"<<endl;
	       cout<<"4. Barbique"<<endl;

	       int a;
	       cout<<endl;


	       cout<<"Enter a choice for cuisine :  ";
	       cin>>a;

	      switch(a)
		{

		      case 1: strcpy(cuisine,"Italian");
				     break;
		      case 2: strcpy(cuisine,"Chinese");
				     break;
		      case 3: strcpy(cuisine,"Indian");
				     break;
		      case 4: strcpy(cuisine,"Barbique");
				      break;
		      default :cout<<"\n Wrong Entry";
		}

	    cout<<endl;


	cout<<"Enter the price per person : ";
	cin>>price_per_person;
	cout<<"\nEnter the location : ";
	gets(location);
	cout<<"\nIs it functional?(y/n) :";
	cin>>fuctionality;
 }


 void showdata()
 {
	cout<<"id is "<<id<<endl;

	cout<<"name is ";

	 puts(nm);

	cout<<"rating is ";

	 cout<<rating<<endl;

	cout<<"cuisine is ";

	 puts(cuisine);

	cout<<"Price per person is ";

	 cout<<price_per_person<<endl;

	cout<<"Location is";

	 puts(location);

	cout<<"Functionality ";

	 cout<<fuctionality<<endl;

	cout<<endl;
 }


 char * retnm()                       //function to return name

 {
	return nm;
 }


 int retid()                       //function to return id
 {
	return id;
 }


 float retrating()                //function to return ratings
 {
	return rating;
 }


 char * retcuisine()               //function to return cuisine
 {
	return cuisine;
 }

 float retpriceperperson()        //function to return price per person
 {
	return price_per_person;
 }

  char * retlocation()              //function to return location
 {
	return location;
 }

 char retfunc()                  //function to return fuctionality
 {
	return fuctionality;
 }

}r1,r2;



 int check(int z)  //function to check duplicate records
 {

		ifstream f1;
		f1.open("restaurant.dat",ios::binary|ios::in);


		while(f1.read((char*)&r2,sizeof(r2)))
		{
		  if(r2.retid()==z)

		  {

			 cout<<"record already exist try for another";
			 return 0;
		  }
		 }
		 return 1;

}

 void create()    //function to create records in the file
 {
	int z;
	cout<<"enter id : ";
	cin>>z;
	ofstream f1;

	int res = check(z);

	if(res==1)
	{
	 f1.open("restaurant.dat",ios::binary|ios::out|ios::app);


	 r1.getdata(z);
	 f1.write((char*)&r1,sizeof(r1));
	}

	cout<<endl;
	f1.close();
 }


  void showrecords()  //function to show records of the file
 {
		

		ifstream f1;

		int i=2;

		f1.open("restaurant.dat",ios::binary|ios::in);

		

		cout<<" id name cuisine functionality\n";
		while(f1.read((char*)&r1,sizeof(r1)))
		{
			

			cout<<r1.retid();

		

			cout<<r1.retnm();

			

			cout<<r1.retcuisine();

			

			cout<<r1.retfunc();

			i++;
		 }cout<<endl;

		 f1.close();
 }


 void Delete()    //function to delete records in the file
 {

	ifstream f1;
	 f1.open("restaurant.dat",ios::binary|ios::out);
	 ofstream f2;
	 int n;
	 cout<<"Enter the id of the resturant to be deleted : ";
	 cin>>n;
	 f2.open("temp.dat",ios::binary|ios::out);

	  int found=0;
	  while(!f1.eof())
	  {
		 f1.read((char*)&r1,sizeof(r1));
			if(n==r1.retid())

			{
			  found=1;
			  r1.showdata();
			  cout<<"Record deleted";
			}
			else
			{
			  f2.write((char*)&r2,sizeof(r2));
			}
	  }

	  if(found==0)

	  {
	     cout<<" Record not found";
	  }

	  f1.close();
	  f2.close();
	  remove("restaurant.dat");
	  rename("temp.dat","restaurant.dat");
	  cout<<endl;
 }


  void countrating()    //function to count no of records having the user given rating

 {
	int cnt=0;
	float r;
	ifstream f1;
	 f1.open("restaurant.dat",ios::binary|ios::in);
	 cout<<"Enter the desired rating on which resturants have to be counted : ";
	 cin>>r;
	 while(f1.read((char*)&r1,sizeof(r1)))
	 {

		if(r1.retrating()==r)

		cnt++;
	 }
	f1.close();
	cout<<" Number of restaurants of desired ratings : "<<cnt<<endl;
 }


 void countcuisine()    //function to count no of records having the user given cuisine

 {
	int cnt=0;
	char c[20];
	ifstream f1;
	f1.open("restaurant.dat",ios::binary|ios::in);
	cout<<"Enter the desired cuisine on which resturants have to be counted";
	cout<<endl;


	 cout<<"1. Italian"<<endl;
	 cout<<"2. Chinese"<<endl;
	 cout<<"3. Indian"<<endl;
	 cout<<"4. Barbique"<<endl;

	 int a;
	 cout<<"Enter a choice for cuisine :";

	 cin>>a;


	 switch(a)


	 {

		case 1:    strcpy(c,"Italian");
				  break;
		case 2:    strcpy(c,"Chinese");
				  break;
		case 3:    strcpy(c,"Indian");
				  break;
		case 4:    strcpy(c,"Barbique");
				  break;
		default :   cout<<"\n Wrong Entry";
	 }


	 while(f1.read((char*)&r1,sizeof(r1)))
	 {

		if(strcmpi(c,r1.retcuisine())==0)

		cnt++;
	 }
	 f1.close();
	 cout<<"Number of restaurants of desired cuisine :"<<cnt<<endl;
 }


	void countname()    //function to count no of records having the user given name

 {
	int cnt=0;
	char n[25];
	ifstream f1;
	f1.open("restaurant.dat",ios::binary|ios::in);
	cout<<"Enter the desired name on which resturants have to be counted : ";
	cout<<endl;

	gets(n);


	 while(f1.read((char*)&r1,sizeof(r1)))
	 {

		if(strcmpi(n,r1.retnm())==0)

		cnt++;
	 }
	 f1.close();
	 cout<<"Number of restaurants of desired name :"<<cnt<<endl;
 }


	void countpriceperperson()    //function to count no of records having the user given price per person

 {
	int cnt=0;
	int p;
	ifstream f1;
	f1.open("restaurant.dat",ios::binary|ios::in);
	cout<<"Enter the desired price per person on which resturants have to be counted : ";
	cin>>p;
	cout<<endl;

	 while(f1.read((char*)&r1,sizeof(r1)))
	 {

		if(r1.retpriceperperson()==p)

		cnt++;
	 }
	 f1.close();
	 cout<<"Number of resturants of desired price per person : "<<cnt<<endl;
 }



void display_particular(int id)    //To display a particular id

{

       ifstream f1;

       f1.open("restaurant.dat",ios::in);

	  int q=0;

	  while(f1.read((char*)&r1,sizeof(r1)))

	   {
	     if(id==r1.retid())

	     {
		r1.showdata();
		q=1;
	     }
	   }

	   if(q==1)
	   {
	     cout<<"\nNo Restaurant found by the id you entered \n";
	   }

       f1.close();
}



void countlocation() /*Fuction to count number of
		       records having the user location */
 {
	    int cnt=0;

	    char loc[20];

	    ifstream f1;

	    f1.open("restaurant.dat",ios::binary|ios::in);

	    cout<<"Enter the desired location on which restaurants have to be counted :  ";

	    gets(loc);

	    while(f1.read((char*)&r1,sizeof(r1)))

	    {
		 if(strcmp(loc,r1.retlocation())==0)

		    cnt++;
	    }

	    f1.close();

	    cout<<"Number of restaurants of desired location = "<<cnt<<endl;
  }


void editid() //Function to edit an existing record//

{
      int id1;

      cout<<"Enter id : ";

      cin>>id1;

      ifstream f1;

      ofstream f2;

      f1.open("restaurant.dat",ios::binary|ios::in);

      f2.open("temp.dat",ios::binary|ios::out);

      while(f1.read((char*)&r1,sizeof(r1)))

       {
	  if(id1==r1.retid())

	   {

	       display_particular(id1);

	       cout<<"\nUpdate the record "<<endl;

	       r1.getdata(id1);

	       f2.write((char*)&r2,sizeof(r2));

	   }

	 else

	     f2.write((char*)&r1,sizeof(r1));

      }

   f1.close();

   f2.close();

   remove("restaurant.dat");

   rename("temp.dat","restaurant.dat");

}


void searchrating()/* Function to search records having the
		      user given rating */
 {
	float r;

	ifstream f1;

	f1.open("restaurant.dat",ios::binary|ios::in);

	cout<<"Enter the desired rating on which restaurants have to be searched :  ";

	cin>>r;

	cout<<endl;

	int q=0;

	while(f1.read((char*)&r1,sizeof(r1)))
	{
	      if(r1.retrating()==r)
		{
		   r1.showdata();
		   q=1;
		}
	}

	if(q==0)
	{
	     cout<<"No restaurant found : "<<endl;
	}

	f1.close();
 }



void searchcuisine()  /*Function to search recoreds
			having the user given cuisine */
{
      char c[20];

      ifstream f1;

      f1.open("restaurants.dat",ios::binary|ios::in);



      cout<<"Enter the desired cuisine on which restaurants have to be searched :  ";

      cout<<endl;

      cout<<"1.Italian"<<endl;
      cout<<"2.Chinese"<<endl;
      cout<<"3.Indian"<<endl;
      cout<<"4.Barbique"<<endl;

      int a;

      cout<<endl;

      cout<<"Enter a choice for cuisine : ";

      cin>>a;

      switch(a)

      {
	 case 1 : strcpy(c,"Italian");
		  break;
	 case 2 : strcpy(c,"Chinese");
		  break;
	 case 3 : strcpy(c,"Indian");
		  break;
	 case 4 : strcpy(c,"Barbique");
		  break;
	 default : cout<<"Wrong entry ";
     }
     cout<<endl;

     int q=0;

     while(f1.read((char*)&r1,sizeof(r1)))
     {
	if(strcmp(c,r1.retcuisine())==0)
	  {
	      r1.showdata();
	      q=1;
	  }
     }

     if(q==0)
     {
	cout<<"No Restaurant found : "<<endl;
     }
     f1.close();

}



void searchname() /*function to search records having the user given name */

{
    char c[20];

    ifstream f1;

    f1.open("restaurant.dat",ios::binary|ios::in);

    cout<<"Enter the desired name on which restaurants have to be searched : ";

    gets(c);

    int q=0;

    cout<<endl;

    while(f1.read((char*)&r1,sizeof(r1)))

      {
	 if(strcmp(c,r1.retnm())==0)

	   {
	      r1.showdata();
	      q=1;
	   }
      }

      if(q==0)
      {
	 cout<<"No Restaurant found "<<endl;
  f1.close();

}




void searchlocation() /*function to serach records
			having the user given location*/
{
   char c[20];

   ifstream f1;

   f1.open("restaurant.data",ios::binary|ios::in);

   int q=0;

   cout<<"Enter the desired location on which restaurants have to be searched : ";

   gets(c);

   cout<<endl;

     while(f1.read((char*)&r1,sizeof(r1)))
      {
	 if(strcmp(c,r1.retlocation())==0)
	  {
	     r1.showdata();
	     q=1;
	  }
      }

     if(q==0)
     {
	 cout<<"No Restaurant found : "<<endl;
     }
     f1.close();
}



void searchfunc()  /*Function to search records
		     having the user given functionality */
{
  char c;

  ifstream f1;

  f1.open("restaurant.dat",ios::binary|ios::in);

  int q=0;

  cout<<"Enter the desired functionality on which restaurants have to be searched : ";

  cin>>c;

  cout<<endl;

    while(f1.read((char*)&r1,sizeof(r1)))
    {
      if(c==r1.retfunc())

	{
	    r1.showdata();
	    q=1;
	}
    }

    if(q==0)
    {
       cout<<"No restaurant found " <<endl;
    f1.close();
 }



void searchppp()      /*function to search records having the
			user given price per person */
{

      float r;

      ifstream f1;

      f1.open("restaurant.dat",ios::binary|ios::in);

      int q=0;

      cout<<"Enter the desired price per person on which restaurants have to be searched : ";

      cin>>r;

      cout<<endl;

      while(f1.read((char*)&r1,sizeof(r1)))

      {
	   if(r1.retpriceperperson()==r)

	   {
		 r1.showdata();
		 q=1;
	   }
      }

     if(q==0)
     {
	 cout<<"No Restaurant found  "<<endl;
     }

  f1.close();

}


void main()
{
	clrscr();
	char ans;
	int ch;

	do

	{

	     cout<<"\n1.  Create a file restaurant ";
	     cout<<"\n2.  Display record of the particular restaurant ";
	     cout<<"\n3.  Count number of restaurants based on rating ";
	     cout<<"\n4.  Count number of restaurants based on cuisine";
	     cout<<"\n5.  Count number of restaurants based on price per person" ;
	     cout<<"\n6.  Count number of restaurants based on name ";
	     cout<<"\n7.  Count number of restaurants based on location ";
	     cout<<"\n8.  Edit details of a restaurants based on user given id ";
	     cout<<"\n9.  Search restaurants on the basis of rating ";
	     cout<<"\n10. Search restaurants on the basis of cuisine ";
	     cout<<"\n11. Search restaurants on the basis of name ";
	     cout<<"\n13. Search restaurants on the bais of functionality";
	     cout<<"\n14. Search restaurants on the basis of price per person ";
	     cout<<"\n15. Display records of all the restaurants" ;
	     cout<<"\n16. Delete a record of restaurants "<<endl;
	     cout<<"\n Enter the choice : ";

	     cin>>ch;
	     cout<<endl;

	       switch(ch)
		{
		   case 1 : create();
			     break;

		   case 2  :
			       int id;
			       cout<<"Enter the id of the restaurants :";
			       cin>>id;
			       display_particular(id);


				break;

		   case 3  : countrating();
			      break;

		   case 4   : countcuisine();
			      break;

		   case 5   : countpriceperperson();
			      break;

		   case 6   : countname();
			      break;

		   case 7   : countlocation();
			      break;

		   case 8   : editid();
			      break;

		   case 9   : searchrating();
			      break;

		   case 10  : searchcuisine();
			      break;

		   case 11  : searchname();
			      break;

		   case 12  : searchlocation();
			      break;

		   case 13  : searchfunc();
			      break;

		   case 14  : searchppp();
			      break;

		   case 15  : showrecords();
			      break;

		   case 16  : Delete();
			      break;

		   default : cout<<"Wrong Choice ";

	      }

	     cout<<"Do you want to continue ? ";
	     cin>>ans;
	}while(ans=='y' || ans=='Y');


}


