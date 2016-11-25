/*
Program No  : 2
Developed By: Paarth Bhasin
Date        : 01-May-2013
*/


PROGRAM:

#include<iostream.h>
#include<conio.h>
int checkpalindrome(long int);
int checkprime(long int);
void main()
{
 clrscr();
 long int n;
 char ch;
 
 do
 {
  cout<<endl;
	 do
  {
   cout<<"Enter a positive number: ";
   cin>>n;
  }while(n<0);
  cout<<endl;
  if(checkpalindrome(n)==1 && checkprime(n)==0)
  	 cout<<"The number is a palindrome number but not a prime number."<<endl;
  else if(checkpalindrome(n)==1 && checkprime(n)==1)
	 cout<<"The number is both, a palindrome number as well as a prime number. That is, it is a palindromic prime number or palprime number."<<endl;
  else if(checkpalindrome(n)==0 && checkprime(n)==0)
	 cout<<"The number is neither a palindrome number nor a prime number."<<endl;
  else if(checkpalindrome(n)==0 && checkprime(n)==1)
	 cout<<"The number is prime number but not a palindrome number."<<endl;
  cout<<endl;
  cout<<"Continue?(y/n): ";
  cin>>ch;
 }while(ch=='y');
  getch();
}
int checkpalindrome(long int n)
{
 long int r, p=0, a;
 a=n;
 do
 {
  r=(n%10);
  p=(p*10)+r;
  n=(n/10);
 }while(n>0);
 if(p==a)
  return 1;
 else
  return 0;
}
int checkprime(long int n)
{long int flag=0;

  for(long int i=2; i<=n/2; i++)
  {
   if(n%i==0)
    flag++;
  }

 if(!flag)
  return 1;
 else if (flag)
  return 0;
}
