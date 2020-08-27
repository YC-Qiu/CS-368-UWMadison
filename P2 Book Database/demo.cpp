
// Author:          Yucheng Qiu
// Wisc id:         yqiu56
// Description:     This file implements a menu for users to use the library.
#include "BookDB.h"


int main(){
    using namespace std;
    vector<Book> BookDB;
    string command = "";
    char Tcommand;
    bool CONT = true;
    while(CONT){
        cout << "> ";
        cin >> Tcommand;
        /*if(command.length()!=1){
            cout << "Error processing command"<<endl;
            continue;
        }*/
        switch (Tcommand){
        case 'p':
            /*  Print the current contents of the database: for each book in the
                database, print its ID, publication year, and rating (separated
                by commas) on a new line. If no entries are in the DB, print
                "No entries" to cout.
            */
            if(BookDB.size()==0 ) std::cout<< "No entries\n";
            else print(BookDB);
            break;
        case 'a':
            /*Add a book to the database with the given fields.*/{
            int year,id;
            double rating;
            cin >> id >> year >> rating;
            bool IF_ADD_FAIL = addBook(id,year,rating,BookDB);//If not successfully added
            if(!IF_ADD_FAIL) cout << "Book " << id << " added"<<endl;
            else cout << "Error processing command\n";}
            break;
        case 'd':
            /*Delete the book with the given ID.*/{
            int id;
            cin >> id;
            bool IF_DELE_FAIL = deleteBook(id, BookDB);
            if(!IF_DELE_FAIL)  cout << "Book " << id << " removed"<<endl;
            else cout << "Error processing command\n";}
            break;
        case 'u':
            /*Locate the book with the given ID and update the value of its year and rating.*/{
            int year,id;
            double rating;
            cin >> id >> year >> rating;
            bool IF_UPD_FAIL = updateBook(id,year,rating,BookDB);
            if(!IF_UPD_FAIL) cout << "Book " << id << " updated"<<endl;
            else cout <<"Error processing command\n";}
            break;
        case 'c':
            /* Calculate and print the average rating of all the books in the database in the format .*/{
            double avg_rat = calculateAverageRating(BookDB);
            if(avg_rat == -1.0) cout<<"Error processing command"<<endl;
            else printf("Average rating = %g\n", avg_rat);}
            break;
        case 'f':
            // Find and print all books in the database that were published in
            // the given year
            {
            int year;
            cin >> year;
            auto Books_found = findBooks(year,BookDB);
            if(Books_found->size() == 0 )std::cout<< "No entries\n";
            else print(*Books_found);
            delete Books_found;}
            break;
        case 's':{
            int sort_opt;
            cin >> sort_opt;
            int SORT_VALID = sortDB(BookDB,sort_opt);
            if(SORT_VALID == 1)
                cout << "Error processing command\n";}
            break;
        case 'q':
            CONT = false;
            cout << "quit"<< endl;
            break;
        default:
            cout << "Error processing command"<< endl;
            break;
        }
    }
    return 0;
}