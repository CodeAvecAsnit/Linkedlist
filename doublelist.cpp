#include<iostream>
using namespace std;

class node{
  public:
  char data;
  node *next;
  node *prev;

  node(char value){
    this->data=value;
    this->next=NULL;
    this->prev=NULL;
  }
};

class doublelist{
  private:
  node *head;

  public:
  doublelist(){
    this->head=NULL;
  }

  char getdata(){
    char value;
    cout<<"Enter the data : ";
    cin>>value;
    return value;
  }

  bool check(){
    return head==NULL;
  }

  void inserttop(){
    node *newnode=new node(getdata());
    if(check()){
      head=newnode;
    }else{
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
    }
  }

  void insertlast(){
    node *newnode=new node(getdata());
    if(check()){
      head=newnode;
    }else{
      node *temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      newnode->prev=temp;
      temp->next=newnode;
    }
  }

  void insertat(){
    cout<<"Enter the postion : ";
    int pos;
    cin>>pos;
    if(pos<1){
      cout<<"Indexing error"<<endl;
      return;
    }else if(pos==1){
      inserttop();
      }else{
        cout<<"Template 1"<<endl;
      node *wnode=new node(getdata());
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        if(temp->next==NULL){
          cout<<"High indexing error"<<endl;
          delete wnode;
          return;
        }else{
          temp=temp->next;
        }
      }
      wnode->prev=temp;
      wnode->next=temp->next;
      wnode->next->prev=wnode;
      temp->next=wnode;
    }
  }

  void removetop(){
    if(check()){
      cout<<"No data to remove"<<endl;
    }else{
      node *temp=head;
      head=head->next;
      head->prev=NULL;
      delete temp;
    }
  }

  void removeend(){
    if(check()){
      cout<<"No data to remove"<<endl;
    }else{
      node *temp=head;
      while(temp->next->next!=NULL){
        temp=temp->next;
      }
      delete temp->next;
      temp->next=NULL;
    }
  }

  void removeat(){
    cout<<"Enter the postion to delete : ";
    int pos;
    cin>>pos;
    if(check()){
      cout<<"No data to delete"<<endl;
    }else if(pos<1){
      cout<<"The position does not exits"<<endl;
    }else if(pos==1){
      removetop();
    }else{
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        if(temp->next==NULL){
          cout<<"Indexing doesnot match"<<endl;
          return;
        }else{
          temp=temp->next;
        }
      }
      node *todel=temp->next;
      todel->next->prev=todel->prev;
      temp->next=todel->next;
      delete todel;

    }
  }

  void display(){
    if(check()){
      cout<<"No data to display"<<endl;
    }else{
      node *temo=head;
      while(temo!=NULL){
        cout<<temo->data;
        temo=temo->next;
      }
      cout<<endl;
    }
  }
};

int main(){
  doublelist l;
  l.inserttop();
  l.inserttop();
  l.inserttop();
  l.insertlast();
  l.insertlast();
  l.insertat();
  l.display();
  l.removeat();
  l.display();
  return 0;
}