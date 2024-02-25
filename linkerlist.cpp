#include<iostream>
using namespace std;

class node{
  public:
  char data;
  node *next;

  node(char a){
    this->data=a;
    this->next=NULL;
  }

};

class linker{
  private:
  node *head;

  public:
  linker(){
    this->head=NULL;
  }

  bool check(){
    return head==NULL;
  }

  char getdata(){
    cout<<"Enter data : ";
    char a;
    cin>>a;
    return a;
  }


  void insertop(){
    node *newnode=new node(getdata());
    if(check()){
      head=newnode;
    }else{
          newnode->next=head;
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
      temp->next=newnode;
    }
  }

  void removetop(){
    if(check()){
      cout<<"No data to remove"<<endl;
    }else{
      node *temp=head;
      head=head->next;
      delete temp;
    }
  }

  void removelast(){
    node *temp=head;
    if(check()){
      cout<<"No data to remove"<<endl;
    }else if(head->next==NULL){
      delete head;
      head=NULL;
      }else{
      while(temp->next->next!=NULL){
        temp=temp->next;
      }
      delete temp->next;
      temp->next=NULL;
    }
  }

  void see_data(){
    node *see=head;
    if(check()){
      cout<<" NO data to display"<<endl;
    }else{
    while(see!=NULL){
      cout<<see->data;
      see=see->next;
    }
  }
  }


  void removeat(){
    node *temp=head;
    int pos;
    cout<<"Enter where you want to delete at : ";
    cin>>pos;
    cout<<endl;
    if(check()||pos<1){
      cout<<"No data to remove"<<endl;
    }else if(pos==1){
        removetop();
    }else{
      for(int i=1;i<(pos-1);++i){
        if(temp->next==NULL){
          cout<<"The indexing doesnot match"<<endl;
          return;
        }else{
          temp=temp->next;
        }
      }
        node *todel=temp->next;
        temp->next=temp->next->next;
        cout<<todel->data<<" was deleted"<<endl;
        delete todel;
    }

  }

  void insertat(){
    int pos;
    cout<<"Enter the position you want to enter the data at : ";
    cin>>pos;
    if(pos<1){
      cout<<"Indexing error"<<endl;
    }else if(pos==1){
        insertop();
    }else{
      node *newnode=new node(getdata());
      node *temp=head;
      for(int i=1;i<(pos-1);++i){
        if(temp->next==NULL){
          cout<<"Indexing error"<<endl;
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

  void serach(){
    char s=getdata();
    node *temp=head;
    while(temp!=NULL){
      if(temp->data==s){
        cout<<s<<" was found in the linked list"<<endl;
        return;
      }
    }
    cout<<"The data doesnt exists"<<endl;

  }
};

int main(){
  linker l;
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
    l.insertop();
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
    l.see_data();
    break;
    case 8: 
    l.serach();
    break;
    default:
    n=9;
    }
  }while(n!=9);
  return 0;

}
