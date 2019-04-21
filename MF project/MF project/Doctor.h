class Player
{

protected:
	
	struct node {
	string playername;
	string password;
	int score;
	struct node *next;
	};

	string playername;
	string password;
	int id;
	int score;
	int level;
	int i;
	int choice;

public:
	Player()
	{
		this->playername="";
		this->password="";
		this->score=0;
		this->level=0;
	}

	void signup()
	{
		struct node *start=NULL;
	   signup_set_credentials(&start);
	   ofstream fout;

	fout.open("users.txt",ios::app);
	fout<<this->playername<<" "<<this->password<<endl;
    fout.close();
	}


	void setPlayername()
	{
   string NAAM;
   cout<<"Enter user name"<<endl;
   cin>>NAAM;
   this->playername=NAAM;
	}

	string getplayername()
	{
		return this->playername;
	}

	int getinitialscore()
	{
		this->score=500;
		return this->score;
	}


	 void signup_set_credentials(struct node **start)
	{
		i=0;
		string Password;
L2:	    
		setPlayername();
		cout<<"Enter Your password.Length should not be less then 5 and greater then 13"<<endl;
		cin>>Password;
		while(Password.length()<5||Password.length()>13)
		{
			if(Password.length()<5)
			{
			 cout<<"Password too short."<<endl;
			 cout<<"Enter Your Password."<<endl;
			 cin>>Password;
			}

			else if(Password.length()>13)
			{
			 cout<<"Password too Long."<<endl;
			 cout<<"Enter Your Password"<<endl;
			 cin>>Password;
			}

		}
			ifstream pass;
			pass.open("users.txt");

			struct node *player_list=NULL;
			player_list=new(node);

		while(!pass.eof())
			{
				pass>>player_list->playername;
				pass>>player_list->password;
				player_list->score=0;
				player_list->next=NULL;

			   	
				if(*start==NULL)
				{
					*start=player_list;
				}

				else
                {
                   struct node *curr=*start;
                   while(curr->next!=NULL)
                   {
                     curr=curr->next;
                   }
                   curr->next=player_list;

				   if(i!=0)
				{
					if(curr->password==Password||curr->playername==this->playername)
		      {
				cout<<"Either username or password is taken"<<endl;
				goto L2;
		      }
		    }
		}

				if(i==0)
				{
				if((*start)->password==Password||(*start)->playername==this->playername)
		      {
				cout<<"Either username or password is taken"<<endl;
				goto L2;
		      }
				i++;
				}				
		}
		pass.close();
		this->password=Password;
	}

	 void setpassword()
	 {
		 cout<<"Enter Password: ";
		 cin>>this->password;
	 }

    void login()
   {
	   	  
	   struct node *start=NULL;
	   setPlayername();
	   setpassword();
	   int count=setlogin(&start);
	   	if(count==0)
		{
			cout<<"Wrong password or username entered";
			this->login();
		}

	}

	  int setlogin(struct node **start)
	   {
	   int count=0;
			ifstream pass;
			pass.open("users.txt");

			struct node *player_list=NULL;
			player_list=new(node);

		while(!pass.eof())
			{
				pass>>player_list->playername;
				pass>>player_list->password;
				player_list->score=0;
				player_list->next=NULL;

			   	
				if(*start==NULL)
				{
					*start=player_list;
				}

				else
                {
                   struct node *curr=*start;
                   while(curr->next!=NULL)
                   {
                     curr=curr->next;
                   }
                   curr->next=player_list;
                }

          if(player_list->password==this->password && player_list->playername==this->playername)
			{
				 cout<<"Login Successfull"<<endl;
				count++;
				return count;
            }

		}

	return count;
	}
	   

	virtual void addplayer(string name)
	{
	
	}

	virtual void check(string name)
	{
	
	
	}

	virtual void leaderboard(string name)
	{
	
	}

	virtual void luckydraw(string name)
	{

	}
};


