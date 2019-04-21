// MF project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>  
using namespace std;
#include"Doctor.h"
#include"Consultant.h"
#include"Physician.h"
#include"Surgeon.h"

int main()
{

L1:
	int n=0;
cout<<"=================================Welcome to Doctor Simulation Game==================================\n\n";
cout<<"Enter 1 to signup\n";
cout<<"Enter 2 to login\n";
cout<<"Enter 3 to exit\n\n";

cin>>n;

switch(n)
{
case 1:
	{
	Player *p1=new Player();
	p1->signup();
	cout<<"Thankyou for signing up\n";
	goto L1;
	break;
    }

case 2:
	{
	Player *p1=new Player();

	p1->login();
	//string a=p1->getplayername();
	//cout<<a;
L2:
	cout<<"Enter 1 to see links about a consultant\n";
	//cout<<"Enter 2 to see links about a surgeon\n";
	//cout<<"Enter 3 to see links about a physician\n";
	cout<<"Enter 2 to logout";

    int k=0;
	cin>>k;
	

	switch(k)
	{
	case 1:
		{
		Player *c1=new Consultant();
		c1->addplayer(p1->getplayername());
L3:
		cout<<"\n\nEnter 1 to view links\n";
		cout<<"Enter 2 to view leaderboard\n";
		cout<<"Enter 3 to enter lucky draw\n";
		cout<<"Enter 4 to go back";

		int j=0;
		cin>>j;

		switch(j)
		{
		case 1:
			c1->check(p1->getplayername());
			goto L3;
			break;

		case 2:
			c1->leaderboard(p1->getplayername());
				goto L3;
			break;

		
		case 3:
			c1->luckydraw(p1->getplayername());
				goto L3;
			break;

		case 4:
			goto L2;
			break;
		}

		break;
	}

	case 2:
		goto L1;
		break;
	}

	break;
}

}
}
