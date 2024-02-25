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

class circularlist{
  private:
  node *head;
  node *tail;

  public:
  circularlist(){
    this->head=NULL;
    this->tail=NULL;
  }
  bool check(){
    return head==NULL&&tail==NULL;
  }

  char getdata(){
    char th;
    cout<<"Enter data : ";
    cin>>th;
    return th;
  }

  void inserttop(){
    node *newnode=new node(getdata());
    if(check()){
        head=tail=newnode;
        tail->next=head;
        head->prev=tail;
    }else{
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
      newnode->prev=tail;
      tail->next=head;
    }
  }

  void insertlast(){
    node *newnode=new node(getdata());
    if(check()){
      head=newnode;
      tail->next=head;
      head->prev=tail;
    }else{
      tail->next=newnode;
      head->prev=newnode;
      newnode->next=head;
      newnode->prev=tail;
      tail=newnode;
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
      node *wnode=new node(getdata());
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        if(temp->next==head){
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
      cout<<"No data to display"<<endl;
      return;
    }else if(head->next==head){
      delete head;
      head=tail=NULL;
    }else{
      node *temp=head;
      head=head->next;
      delete temp;
      head->prev=tail;
      tail->next=head;

    }
  }

    void removelast(){
    if(check()){
      cout<<"No data to remove "<<endl;
    }else if(head->next==head){
      delete head;
      head=tail=NULL;
    }else{
      node *temp=tail;
      tail=tail->prev;
      delete temp;
      tail->next=head;
      head->prev=tail;
    }

  }
    void display(){
    if(check()){
      cout<<"No data to display"<<endl;
    }else{
      node *temp=head;
      do{
        cout<<temp->data;
        temp=temp->next;
      }while(temp!=head);
      cout<<endl;
    }
  }

  void yalpsid(){
    if(check()){
      cout<<"No data to display"<<endl;
    }else{
      node *temp=tail;
      do{
        cout<<temp->data;
        temp=temp->prev;
      }while(temp!=tail);
      cout<<endl;
    }
  }
};

int main(){
  circularlist l;
  l.inserttop();
  l.inserttop();
  l.inserttop();
  l.insertlast();
  l.insertlast();
  l.insertat();
  l.display();
  l.yalpsid();
}