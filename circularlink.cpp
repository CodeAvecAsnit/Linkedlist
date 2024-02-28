#include<iostream>
using namespace std;

class node{
  public :
  int data;
  node *next;

  node(int value){
    this->next=NULL;
    this->data=value;
  }
};

class CircleLink{
  private:
  node *head;
  node *tail;

  public:
  CircleLink(){
    this->head=NULL;
    this->tail=NULL;
  }
  private:
  bool checkempty(){
    return head==NULL;
  }
  bool checkone(){
    return head!=NULL && head==head->next;
  }
  int getpos(){
    int th;
    cout<<"Enter the postion : ";
    cin>>th;
    return th;
  }

    int getdata(){
    int th;
    cout<<"Enter data : ";
    cin>>th;
    return th;
  }

  public:
  void inserttop(){
    node *newnode=new node(getdata());
    if(checkempty()){
      head=tail=newnode;
    }else{
      newnode->next=head;
      head=newnode;
    }
    tail->next=head;
  }

  void insertend(){
      node *newnode=new node(getdata());
      if(checkempty()){
        head=newnode;
      }else{
        tail->next=newnode;
      }
        tail=newnode;
        tail->next=head;
  }

  void deletetop(){
    if(checkempty()){
      cout<<"No data to delete."<<endl;
      return;
    }
    node *todel=head;
    if(checkone()){
      head=tail=NULL;
    }else{
      head=head->next;
      tail->next=head;
    }
     delete todel;
  }

  void deleteend(){
    if(checkempty()){
      cout<<"No data to delete."<<endl;
      return;
    }
    if(checkone()){
      delete head;
      head=tail=NULL;
      return;
    }else{
      node *temp=head;
      while(temp->next!=tail){
        temp=temp->next;
      }
      temp->next=head;
      delete tail;
      tail=temp;
  }
  }

  void insertat(){
    int pos=getpos();
    if(pos<1){
      cout<<"Low Indexing Error"<<endl;
      return;
    }else if(pos==1){
      inserttop();
      return;
    }else{
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        temp=temp->next;
        if(temp==head){
          cout<<"High Indexing Error"<<endl;
          return;
        }
        }
    
          node *newnode=new node(getdata());
          newnode->next=temp->next;
          temp->next=newnode;
          if(temp==tail){
            tail=newnode;
          }
        
      }
    }


  void deleteat(){
    int pos=getpos();
    if(checkempty()){
      cout<<"No data to delete"<<endl;
      return;
    }else if(pos<1){
      cout<<"Low Indexing Error"<<endl;
      return;
    }else if(pos==1){
      deletetop();
      return;
    }
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        temp=temp->next;
        if(temp==head||temp->next==head){
          cout<<"High Indexing Error"<<endl;
          return;
        }
      }
      if(temp->next==tail){
        deleteend();
      }else{
        node *todel=temp->next;
        temp->next=todel->next;
        delete todel;
      }
    }

  void display(){
   if(checkempty()){
    cout<<"No data to display"<<endl;
      return;
   }
    node *temp=head;
    do{
      cout<<temp->data<<" ";
      temp=temp->next;
    }while(temp!=head);
    cout<<endl;
   }

       ~CircleLink() { 
            deletetop();
        }
    };


int main(){
  CircleLink l;
  cout<<"Menu"<<endl;
  cout<<"Press 1 to insert data on top"<<endl;
  cout<<"Press 2 to insert data on the end"<<endl;
  cout<<"Press 3 to insert data on specified postion"<<endl;
  cout<<"Press 4 to delete the data of top"<<endl;
  cout<<"Press 5 to delete the data of end"<<endl;
  cout<<"Press 6 to delete the data of specified postion"<<endl;
  cout<<"Press 7 to display the data"<<endl;
  cout<<"Press any other key to exit"<<endl;
  int n;
  do{
    cin>>n;
    switch(n)
    {
      case 1:
      l.inserttop();
      break;

      case 2:
      l.insertend();
      break;

      case 3:
      l.insertat();
      break;

      case 4:
      l.deletetop();
      break;

      case 5:
      l.deleteend();
      break;

      case 6:
      l.deleteat();
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