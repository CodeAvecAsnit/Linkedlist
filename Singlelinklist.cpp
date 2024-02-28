#include<iostream>
using namespace std;

class node{
  public:
  node *next;
  int data;

  node(int d){
    this->data=d;
  }
};
class link{
  private:
  node *head;

  public:
  link(){
    this->head=NULL;
  }
  private:
  bool checkone(){
    return head->next==NULL;
  }
  bool checkempty(){
    return head==NULL;
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
      head=newnode;
    }else{
      newnode->next=head;
      head=newnode;
    }
  }

  void insertend(){
    node *newnode=new node(getdata());
    if(checkempty()){
      head=newnode;
    }else{
      node *temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=newnode;
    }
  }

  void insertat(){
    int pos;
    cout<<"Enter the position to enter the data : ";
    cin>>pos;
    if(pos<1){
      cout<<"Low Indexing Error"<<endl;
    }else if(pos==1){
      inserttop();
    }else{
      node *temp=head;
      for(int i=1;i<pos-1;++i){
        temp=temp->next;
        if(temp==NULL){
          cout<<"High Indexing Error"<<endl;
          return;
        }
      }
    
    node *newnode=new node(getdata());
    newnode->next=temp->next;
    node *todel=temp->next;
    delete todel;
    temp->next=newnode;

    }
  }

  void deletetop(){
    if(checkempty()){
       cout<<"No data to delete"<<endl;
    }else{
      node *todel=head;
      head=head->next;
      delete todel;
    }
  }

  void deleteend(){
       if(checkempty()){
       cout<<"No data to delete"<<endl;
    }else if(checkone()){
      delete head;
      head=NULL;
    }else{
      node *temp=head;
      while(temp->next->next!=NULL){
        temp=temp->next;
      }
      delete temp->next;
      temp->next=NULL;
    }
  }

  void deleteat(){
    int pos;
    cout<<"Enter the postion : ";
    cin>>pos;
    if(checkempty()){
      cout<<"No data to delete"<<endl;
      return;
    }else if(pos<1){
      cout<<"Low Indexing Error"<<endl;
    }else if(pos==1){
        deletetop();
    }else{
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        temp=temp->next;
        if(temp==NULL){
          cout<<"Error indexing out of bounds"<<endl;
          return;
        }
      }
      if(temp->next==NULL){
        deleteend();
      }else{
        node *todel=temp->next;
        temp->next=temp->next->next;
        delete todel;
      }
    }
  }

  void display(){
    if(checkempty()){
      cout<<"No data to display"<<endl;
    }else{
      node *temp=head;
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
      }
      cout<<endl;

    }
  }
};

int main(){
  link l;
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