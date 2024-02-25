#include<iostream>
using namespace std;

class node{

  public:
  char data;
  node *next;

  node(char value){
    this->data=value;
    this->next=NULL;
  }
};

class circlinkedlist{
  private:
  node *head;
  node *tail;

  public:
  circlinkedlist(){
    this->head=NULL;
    this->tail=NULL;
  }


  bool check(){
    return head==NULL;
  }

  char getdata(){
    cout<<"Enter data : ";
    char n;
    cin>>n;
    return n;
  }


  void inserttop(){
    node *newnode=new node(getdata());
    if(check()){
      head=tail=newnode;
      tail->next=head;
    }else{
      newnode->next=head;
      head=newnode;
      tail->next=head;
    }
  }

  void insertlast(){
    node *newnode=new node(getdata());
    if(check()){
      head=tail=newnode;
      tail->next=newnode;
    }else{
      tail->next=newnode;
      newnode->next=head;
      tail=newnode;
    }
  }

  void display(){
    node *temp=head;
      if(check()){
        cout<<"No data to display"<<endl;
      }else{
        do{
          cout<<temp->data;
          temp=temp->next;
        }while(temp!=head);
      }
      cout<<endl;
}

void removetop(){
  if(check()){
    cout<<"No data to remove"<<endl;
  }else if(head->next==head){
        delete head;
        head=NULL;
        tail=NULL;
        }else{
    node *temp=head;
    head=head->next;
    delete temp;
    tail->next=head;
  }
}


void insertat(){
  cout<<"Enter the postion to enter the data : ";
  int pos;
  cin>>pos;
  node *newnode=new node(getdata());
  if(pos<1){
    cout<<"Indexing error"<<endl;
    delete newnode;
    return;
  }else if(pos==1){
        if(check()){
      head=tail=newnode;
      tail->next=head;
    }else{
      newnode->next=head;
      head=newnode;
    }
  }else{
    node *temp=head;
    for(int i=1;i<(pos-1);++i){
        if(temp->next==head){
          cout<<"High Indexing Error"<<endl;
          delete newnode;
          return;
        }else{
          temp=temp->next;
        }
    }
      newnode->next=temp->next;
      temp->next=newnode;
  }
}


  void removeat(){
    cout<<"Enter the postion to remove"<<endl;
    int pos;
    cin>>pos;
    if(check()){
      cout<<"No data to remove"<<endl;
    }else if(pos==1){
      removetop();
    }else{
      node *temp=head;
      for(int i=1;i<pos-1;++i){
        if(temp->next==head){
          cout<<"High Indexing error"<<endl;
          return;
        }else{
          temp=temp->next;
        }
      }
      if(temp->next==tail){
        removelast();
      }else{
        node *todel=temp->next;
        temp->next=temp->next->next;
        delete todel;
      }

    }
  }
void removelast(){
  if(check()){
    cout<<"No data to remove"<<endl;
  }else if(head->next==head){
        delete head;
        head=NULL;
        tail=NULL;
        }else{
    node *temp=head;
    while(temp->next!=tail){
      temp=temp->next;
    }
    delete temp->next;
    tail=temp;
    tail->next=head;
  }
}
};

int main(){
circlinkedlist l;
cout<<"Menu"<<endl;
  cout<<"Press 1 to insert data at the top"<<endl;
  cout<<"Press 2 to insert data at the end"<<endl;
  cout<<"Press 3 to insert data at certain position"<<endl;
  cout<<"Press 4 to delete the top data"<<endl;
  cout<<"Press 5 to delete the end data"<<endl;
  cout<<"Press 6 to delete the data"<<endl;
  cout<<"Press 7 to view the data"<<endl;
  cout<<"Press 8 to search the data"<<endl;
  cout<<"Press any other key to exit"<<endl;
  int n=0;
  do{
    cin>>n;
    switch (n)
    {
    case 1: 
    l.inserttop();
    break;
    case 2:
    l.insertlast();
    break;
    case 3: 
    l.insertat();
    break;
    case 4:
    l.removetop();
    break;
    case 5:
    l.removelast();
    break;
    case 6:
    l.removeat();
    break;
    case 7:
    l.display();
    break;
    default:
    n=9;
    }
  }while(n!=9);
  return 0;

}
