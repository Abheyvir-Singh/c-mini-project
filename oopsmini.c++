#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    int id;
    string name;
    string author;
    bool issued;

public:
    // Constructor
    Book()
    {
        id = 0;
        name = "";
        author = "";
        issued = false;
    }

    // Function to add book details
    void addBook()
    {
        cout << "\nEnter Book ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Book Name: ";
        getline(cin, name);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;
    }

    // Function to display book details
    void displayBook()
    {
        cout << "\nBook ID: " << id;
        cout << "\nBook Name: " << name;
        cout << "\nAuthor: " << author;

        if (issued == false)
            cout << "\nStatus: Available\n";
        else
            cout << "\nStatus: Issued\n";
    }

    // Getter function for Book ID
    int getId()
    {
        return id;
    }

    // Function to search book
    string getName()
    {
        return name;
    }

    // Function to check book status
    bool isIssued()
    {
        return issued;
    }

    // Function to issue book
    void issueBook()
    {
        issued = true;
    }

    // Function to return book
    void returnBook()
    {
        issued = false;
    }
};


class Library
{
private:
    Book books[100];
    int totalBooks;

public:
    Library()
    {
        totalBooks = 0;
    }

    // Add a new book
    void addNewBook()
    {
        if (totalBooks < 100)
        {
            books[totalBooks].addBook();
            totalBooks++;

            cout << "\nBook added successfully!\n";
        }
        else
        {
            cout << "\nLibrary is full!\n";
        }
    }

    // Display all books
    void displayAllBooks()
    {
        if (totalBooks == 0)
        {
            cout << "\nNo books available!\n";
            return;
        }

        cout << "\n----- BOOK LIST -----\n";

        for (int i = 0; i < totalBooks; i++)
        {
            books[i].displayBook();
            cout << "---------------------\n";
        }
    }

    // Search a book using ID
    void searchBook()
    {
        int searchId;
        bool found = false;

        cout << "\nEnter Book ID to search: ";
        cin >> searchId;

        for (int i = 0; i < totalBooks; i++)
        {
            if (books[i].getId() == searchId)
            {
                books[i].displayBook();
                found = true;
                break;
            }
        }

        if (found == false)
        {
            cout << "\nBook not found!\n";
        }
    }

    // Issue a book
    void issueBook()
    {
        int searchId;
        bool found = false;

        cout << "\nEnter Book ID to issue: ";
        cin >> searchId;

        for (int i = 0; i < totalBooks; i++)
        {
            if (books[i].getId() == searchId)
            {
                found = true;

                if (books[i].isIssued() == false)
                {
                    books[i].issueBook();
                    cout << "\nBook issued successfully!\n";
                }
                else
                {
                    cout << "\nThis book is already issued!\n";
                }

                break;
            }
        }

        if (found == false)
        {
            cout << "\nBook not found!\n";
        }
    }

    // Return a book
    void returnBook()
    {
        int searchId;
        bool found = false;

        cout << "\nEnter Book ID to return: ";
        cin >> searchId;

        for (int i = 0; i < totalBooks; i++)
        {
            if (books[i].getId() == searchId)
            {
                found = true;

                if (books[i].isIssued() == true)
                {
                    books[i].returnBook();
                    cout << "\nBook returned successfully!\n";
                }
                else
                {
                    cout << "\nThis book was not issued!\n";
                }

                break;
            }
        }

        if (found == false)
        {
            cout << "\nBook not found!\n";
        }
    }
};


int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n\n===== SMART LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                library.addNewBook();
                break;

            case 2:
                library.displayAllBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                cout << "\nThank you for using the Library Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
