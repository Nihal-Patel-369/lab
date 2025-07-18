#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo;
    string dueDate;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
        this->issuedTo = "";
        this->dueDate = "";
    }

    int getId() {
        return id;
    }

    void display() {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author;
        if (isIssued) {
            cout << " [Issued to: " << issuedTo << ", Due Date: " << dueDate << "]";
        }
        cout << endl;
    }

    void issueBook(string studentName, string dueDate) {
        if (!isIssued) {
            isIssued = true;
            issuedTo = studentName;
            this->dueDate = dueDate;
            cout << "Book issued successfully to " << studentName << "!\n";
        } else {
            cout << "Book already issued to " << issuedTo << ".\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            issuedTo = "";
            dueDate = "";
            cout << "Book returned successfully.\n";
        } else {
            cout << "Book was not issued.\n";
        }
    }

    bool matchesId(int bookId) {
        return id == bookId;
    }
};

// Global book list
vector<Book> library;

void addBook() {
    int id;
    string title, author;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);

    Book newBook(id, title, author);
    library.push_back(newBook);
    cout << "Book added successfully!\n";
}

void displayBooks() {
    cout << "\n--- Book List ---\n";
    for (Book &b : library) {
        b.display();
    }
}

void issueBook() {
    int id;
    string studentName, dueDate;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    cin.ignore();
    for (Book &b : library) {
        if (b.matchesId(id)) {
            cout << "Enter student name: ";
            getline(cin, studentName);
            cout << "Enter due date (DD/MM/YYYY): ";
            getline(cin, dueDate);
            b.issueBook(studentName, dueDate);
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (Book &b : library) {
        if (b.matchesId(id)) {
            b.returnBook();
            return;
        }
    }
    cout << "Book not found!\n";
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (Book &b : library) {
        if (b.matchesId(id)) {
            b.display();
            return;
        }
    }
    cout << "Book not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Search Book\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: searchBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
