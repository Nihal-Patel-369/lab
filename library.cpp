#include <iostream>
using namespace std;

class Book{
    protected:
        int bookId;
        string name;
        string author;
        bool isIssued;

    public:
        Book(){
            this->bookId=0;
            this->name="";
            this->author="";
            this->isIssued=false;
        }

    void createBook(int bookId, string name, string author){
        this->bookId=bookId;
        this->name=name;
        this->author=author;

        cout<<"\n=================================\n";
        cout<<"Book added succesfully.";
        cout<<"\n=================================\n\n";
    }

    void getBook(){
        cout<<"=================================\n";
        cout<<"Book ID: "<<this->bookId<<endl;
        cout<<"Book Name: "<<this->name<<endl;
        cout<<"Book Author: "<<this->author<<endl;
        cout<<"Available: "<<((isIssued==true)?"No":"Yes");
        cout<<"\n================================\n\n";
    }

    int getId(){
        return this->bookId;
    }

    bool getIssueStatus(){
        return this->isIssued;
    }
};

class IssuedBook:public Book{
    private:
        string issuedTo;
        string issueDate;

    public:
       void issueBook(){
            cin.ignore();

            cout<<"Enter Borrower's Name: ";
            getline(cin, issuedTo);

            cout<<"Enter Issue Date: ";
            getline(cin, issueDate);
            
            this->isIssued=true;

            cout<<"\n=================================\n";
            cout<<"Book issued successfully.";
            cout<<"\n=================================\n\n";

        }

        void returnBook(){
            if(isIssued==false){
                cout<<"This book is not issued.\n";
            }else{
                isIssued=false;
                issuedTo="";
                issueDate="";
                cout<<"\n=================================\n";
                cout<<"Book returned successfully.";
                cout<<"\n=================================\n\n";
            }
        }

};

int main() {

    int choice;
    int bookCounter=0;
    IssuedBook library[5];
    
    do{
        cout<<"1. Add book."<<endl;
        cout<<"2. View all books."<<endl;
        cout<<"3. Issue book."<<endl;
        cout<<"4. Return book."<<endl;
        cout<<"5. Exit."<<endl;
        cout<<"Enter your choice(1-5): ";
        cin>>choice;
        
        switch(choice){
            case 1:{
                int bookId;
                string name, author;

                cout<<"Enter Book ID: ";
                cin>>bookId;

                cin.ignore();

                cout<<"Enter Book Name: ";
                getline(cin, name);

                cout<<"Enter Author Name: ";
                getline(cin, author);

                library[bookCounter].createBook(bookId, name, author);
                bookCounter++;

                break;
            }
            case 2:{

                for(int i=0;i<bookCounter;i++){
                    library[i].getBook();
                }

                break;
            }
            case 3:{

                int bookId;
                bool flag=false;

                cout<<"Enter Book ID: ";
                cin>>bookId;

                for(int i=0;i<bookCounter;i++){
                    if(library[i].getId()==bookId){
                        flag=true;
                        if(library[i].getIssueStatus()==true){
                            cout<<"\nBook already issued\n\n.";
                            break;
                        }
                        else{
                            library[i].issueBook();
                        }
                    }
                    
                }
                if(flag==false){
                    cout<<"Book not found."<<endl;
                }
                
                break;
            }
            case 4:{

                int bookId;
                bool flag=false;

                cout<<"Enter Book ID: ";
                cin>>bookId;

                for(int i=0;i<bookCounter;i++){
                    if(library[i].getId()==bookId){
                        flag=true;
                        library[i].returnBook();
                    }
                }
                if(flag==false){
                    cout<<"Book not found."<<endl;
                }

                break;
            }
            case 5:{
                cout<<"Thank You. Visit Again.";
                break;
            }
        }

    }while(choice!=5);
    

    return 0;
}