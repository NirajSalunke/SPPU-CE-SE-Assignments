/*
Imagine a publishing company which does marketing for book
and audio cassette versions.

Create a class publication that stores the title (a string) and price (type float) of publications.

From this class derive two classes: book which adds a page
count (type int) and tape which adds a playing time in minutes
(type float).

Write a program that instantiates the book and
tape class, allows user to enter data and displays the data
members.

If an exception is caught, replace all the data
member values with zero values.
*/
#include <iostream>
#include <vector>
using namespace std;

class Company
{
public:
    string title;
    float price;
    Company()
    {
        // cout << "Constructor of Compay of called" << endl;
    }
    ~Company()
    {
        // cout << "Constructor of Compay of called" << endl;
    }
};

class Book : public Company
{
public:
    int page_count;
    Book()
    {
    }
    Book(string name, float pri, int pc)
    {
        this->title = name;
        this->price = pri;
        this->page_count = pc;
    }
    ~Book()
    {
    }
};
class Tape : public Company
{
public:
    float play_time;
    Tape()
    {
    }
    Tape(string name, float pri, float pt)
    {
        this->title = name;
        this->price = pri;
        this->play_time = pt;
    }
    ~Tape()
    {
    }
};

int main()
{
    vector<Book> books;
    vector<Tape> tapes;
    int choice;
    while (true)
    {

        cout << "Menu" << endl;
        cout << "1. Create Book" << endl;
        cout << "2. Create Tape" << endl;
        cout << "3. Display all Books" << endl;
        cout << "4. Display all Tapes" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 5)
        {
            cout << "Exiting.. " << endl;
            return 0;
        }
        else if (choice == 1)
        {
            Book b;
            cout << "Enter the title of Book: " << endl;
            cin >> b.title;
            cout << "Enter the Price of the Book: " << endl;
            cin >> b.price;
            cout << "Enter the Page count of the Book:  " << endl;
            cin >> b.page_count;
            books.push_back(b);
        }
        else if (choice == 2)
        {
            Tape b;
            cout << "Enter the title of Audio Cassette: " << endl;
            cin >> b.title;
            cout << "Enter the Price of the Audio Cassette: " << endl;
            cin >> b.price;
            cout << "Enter the Play time  of the Audio Cassette:  " << endl;
            cin >> b.play_time;
            tapes.push_back(b);
        }
        else if (choice == 3)
        {
            if (books.size())
            {
                for (int i = 0; i < books.size(); i++)
                {
                    cout << "------------------------------" << endl;
                    cout << "Book Name: " << books[i].title << endl;
                    cout << "Book Price: " << books[i].price << endl;
                    cout << "Book page count: " << books[i].page_count << endl;
                    cout << "------------------------------" << endl;
                }
            }
            else
            {
                cout << "No Books in Company currently" << endl;
            }
        }
        else if (choice == 4)
        {
            if (tapes.size())
            {
                for (int i = 0; i < tapes.size(); i++)
                {
                    cout << "------------------------------" << endl;
                    cout << "Tape Name: " << tapes[i].title << endl;
                    cout << "Tape Price: " << tapes[i].price << endl;
                    cout << "Tape Play time in minutes: " << tapes[i].play_time << endl;
                    cout << "------------------------------" << endl;
                }
            }
            else
            {
                cout << "No Tapes in the Company currently" << endl;
            }
        }
    }
    return 0;
}