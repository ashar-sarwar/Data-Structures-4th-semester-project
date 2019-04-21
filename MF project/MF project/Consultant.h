

struct quiz
{
string ques;
string ans;
struct quiz *RightChild;
struct quiz *LeftChild;
int place;

};

struct video{

string vid;
struct video *next;

}*front = NULL,*rear = NULL,*p = NULL,*np =NULL;



class Consultant:public Player
{
protected:
	
public:
	Consultant():Player()
	{
		this->score=this->getinitialscore();
	}

	void addplayer(std::string&name)
	{
	ifstream pass;
	pass.open("consultant.txt");
	struct node *consult_list=NULL;
	consult_list=new(node);
	struct node *start=NULL;
	while(!pass.eof())
	{
	            pass>>consult_list->playername;
				pass>>consult_list->score;
				consult_list->password="";
				consult_list->next=NULL;
                  
				if(start==NULL)
				{
					start=consult_list;
				}

				else
                {
                   struct node *curr=start;
                   while(curr->next!=NULL)
                   {
                     curr=curr->next;
                   }
                   curr->next=consult_list;
                }
				if(name==start->playername)
				{
				return;
				}
	}

	pass.close();
		
	ofstream fout;

	fout.open("consultant.txt",ios::app);
	fout<<name<<" "<<this->score<<endl;
    fout.close();

	}

		

int getscore(string name)
{
ifstream fin;
fin.open("consultant.txt");
string naam;
int score=0;
while(!fin.eof())
{
	fin>>naam;
	fin>>score;
	if(naam==name)
	{
		fin.close();
		break;
	}
}
return this->score=score;
}

	void check(string user)
	{
		ifstream fin;
		fin.open("consultant.txt");
		string name;
		int score;
		while(!fin.eof())
		{
		fin>>name;
		fin>>score;

		if(name==user)
		{
        fin.close();
		this->score=score;
		break;
		}

		}
	

		if(this->score>=500)
		{
			struct vertex *start=NULL;
		   infocentre();
		   this->score-=250;
		   deleteuser(user,this->score);
		}

		else
		{
			int i=0;
			int choice=0;
		    cout<<"You dont have enough money. Watch a video to earn money.\n Enter 1 to watch a video,else enter 0";
			cin>>choice;
			enqueue();
			

			while(choice)
			{
			 cout<<"\nWatched " + dequeue();
			 this->score+=100;
			 deleteuser(user,this->score);
			cout<<"\n\nEnter 1 to watch another video,else enter 0: ";
			cin>>choice;
		}
	}

	}
	
	void luckydraw(string name)
	{
		int score=getscore(name);
		cout<<score;
		if(score<1000)
		{
		cout<<"\n\nYou don't have above 1000 score which is necessary for entering draw\n";
		return;
		}
		
	ifstream fin;
	fin.open("luckydraw.txt");
	struct node *start=NULL;
	struct node *check;
	check=new(node);
	int i=0,j=0;
	while(!fin.eof())
	{
		fin>>check->playername;
		check->password="";
		check->score=0;
		check->next=NULL;

		if(start==NULL)
		{
		start=check;
		}

		else
		{
		struct node *curr=start;
		while(curr->next!=NULL)
		{
		curr=curr->next;
		}
		curr->next=check;

		if(i!=0)
		{
		if(name==curr->playername)
		{
			j++;
		break;
		}

		}

		}

		if(i==0)
		{
		if(name==start->playername)
		{
			j++;
		break;
		}
		i++;
	}
}
	fin.close();
if(j==0)
{
cout<<"You have entered in lucky draw"<<endl<<"You will be informed shorly of results";
ofstream fout;
fout.open("luckydraw.txt",ios::app);
fout<<name<<endl;
fout.close();
}

else
{
	string name;
	int k=0;
  ifstream fin;
  fin.open("luckydraw.txt");
  while(!fin.eof())
  {
  fin>>name;
  k++;
  }
  fin.close();
  if(k>5)
  {
  cout<<"\nYou have won an exiciting price. Contact our office for details. Thankyou \n";
  return;
  }
  else
  {
	  cout<<"\n\nResults will be announced soon\n\n";
       return;
  }
}


}
    string dequeue()
{

    string x;
    if(front==NULL)
    {
        cout<<"You have watched all videos";
    }
	 else
    {
        p = front;
        x = p->vid;
        front = front->next;
        delete(p);
        return(x);
    }
   
}


	void enqueue()
{
	ifstream fini;
	fini.open("videos.txt");

	while(!fini.eof())
	{
     np = new (video);
    fini>>np->vid;
    np->next = NULL;

    if(front == NULL)
    {
        front = rear = np;
        rear->next = NULL;
    }
    else
    {
        rear->next = np;
        rear = np;
        rear->next = NULL;
    }
	}
	fini.close();
}



void infocentre()
{
	srand(time(0));
	int num;
	int list[4];
	for(int i=0;i<4;i++)
	{
		list[i]=rand();	    	
	}
	i=0;
	struct quiz *start=NULL;
	ifstream fin;
	fin.open("quiz1.txt");
	string a;
	string b;
	while(!fin.eof())
	{
	
	 fin>>a;
	 fin>>b;
	insert(&start,list[i],a,b);
	i++;
	}

	
    PreorderTraversal(start);

}

void PreorderTraversal(struct quiz *start)
{
	if (start != NULL)
	{
		cout <<"Q."<< start->ques<< endl;
		cout<<"Ans."<<start->ans<<endl<<endl;
		PreorderTraversal(start->LeftChild);
		PreorderTraversal(start->RightChild);
	}
}

	void insert(struct quiz **start,int arr,string a,string b)
	{
	struct quiz *ptr=new(quiz);
	
	ptr->ques=a;
	ptr->ans=b;
	ptr->LeftChild=NULL;
	ptr->RightChild=NULL;
	ptr->place=arr;

	if (*start == NULL)
	{
		*start = ptr;
		return;
	}

	if (arr > (*start)->place)
		insert(&((*start)->RightChild), arr,a,b);


	else if(arr < (*start)->place)
		insert(&((*start)->LeftChild), arr,a,b);

}	

	void leaderboard(string name)
	{
      deleteuser(name,getscore(name));
	  struct node *start=NULL;
	  ifstream fin;
	fin.open("consultant.txt");
	string nam;
	int score;
	while(!fin.eof())
	{
		fin>>nam;
		fin>>score;
	  show(&start,nam,score);
	}
	fin.close();

	bubblesort_show(&start);
	show_users(start);

	}
	void show(struct node **start,string name,int score)
	{
	
	struct node *show=NULL;
	show=new(node);
	
		show->playername=name;
		show->score=score;
		show->password="";
		show->next=NULL;
	
		if(*start==NULL)
		{
			*start=show;
	    }

		else
		{
		struct node *curr=NULL;
			curr=*start;
		while(curr->next!=NULL)
		{
		curr=curr->next;
		}

		curr->next=show;

		}

}

	void show_users(struct node *start)
	{
	
	while(start->next!=NULL)
	{
		cout<<start->playername;
		cout<<start->score<<endl;
		start=start->next;
	}
	
	}


	void bubblesort_show(struct node **start)
{
    struct node *curr=*start;
    struct node *curri = NULL;

        while (curr->next!= NULL)
        {
            curri=curr->next;
            while(curri->next!=NULL)
            {

				if ((curr->score) > (curri->score))
            {
                swap_values(curr, curri);
                //cond=true;
            }
            curri=curri->next;
            }
            curr = curr->next;
        }

}


void swap_values(struct node *a, struct node *b)
{

     string temp;
	 temp=a->playername;
	 a->playername=b->playername;
	 b->playername=temp;

	 int tempo=0;
	  tempo=a->score;
	  a->score=b->score;
	 b->score=tempo;
}


	void deleteuser(string name,int score)
	{
     string user;

	 int i=0;  
    ifstream fin;
	ofstream fout;
	fin.open("consultant.txt");
	fout.open("tempfile.txt",ios::out);
	struct node *board=NULL;
	struct node *start=NULL; 
	board=new(node);

    while(!fin.eof())
	{
	
		fin>>board->playername;
		fin>>board->score;
		  board->password="";
          board->next=NULL;

		  if(start==NULL)
				{
					start=board;
				}

				else
                {
                   struct node *curr=start;
                   while(curr->next!=NULL)
                   {
                     curr=curr->next;
                   }
                   curr->next=board;

            if(i!=0)
		  {
		  
		    if(name==curr->playername)
	      {
		 user=curr->playername; 
		this->score=score;
		 continue;
		  }

	 else 
	 {
		 fout<<curr->playername<<" "<<curr->score<<endl;
	 }
		 
		  }

    } 

		  if(i==0)
		  {
			  i++;
		  if(name==start->playername)
	    {
		  user=start->playername;
		  this->score=score;
		  continue;
		  }

	 else 
	 {
		 fout<<start->playername<<" "<<start->score<<endl;
	 }
		  
	}
		 
   }
	
  
   
   fin.close();
   fout.close();
   remove("consultant.txt");
   rename("tempfile.txt","consultant.txt");
   addplayer(user);
   }
	
	
};