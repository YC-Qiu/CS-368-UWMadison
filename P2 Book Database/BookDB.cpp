// Author:          Yucheng Qiu
// Wisc id:         yqiu56
// Description:     This file implements the functions in BookDB.h

#include "BookDB.h"
#ifndef Book_DB2
#define Book_DB2
int addBook(int bookID, int year, double rating, std::vector<Book> &db){
    for(Book &x: db){
        if(x.ID == bookID) return 1;
    }
    Book newBook = {bookID,year,rating};
    db.push_back(newBook);
    return 0;
}

int updateBook(int bookID, int year, double rating, std::vector<Book> &db){
    for(Book &x: db){
        if(x.ID == bookID){
            x.rating = rating;
            x.year = year;
            return 0;
        }
    }
    return 1;
}

int deleteBook(int bookID, std::vector<Book> &db){
    for(int i = 0; i < db.size(); i++){
        if(db[i].ID != bookID) continue;
        db.erase( db.begin() + i );
        return 0;
    }
    return 1;
}

std::vector<Book>* findBooks(int year, const std::vector<Book> &db){
    std::vector<Book> *newDB = new std::vector<Book>;
    for(Book x: db){
        if(x.year != year) continue;
        newDB->push_back(x);
    }
    return newDB;
}

double calculateAverageRating(const std::vector<Book> &db){
    if(db.size()==0) return -1.0;
    double sum = 0;
    int n = 0;
    for(Book x: db){
        n++;
        sum += x.rating;
    }
    return sum / n;
}

void print(const std::vector<Book> &db){

    for(Book x:db){
        using namespace std;
        printf("%d, %d, %g\n",x.ID,x.year,x.rating);
    }
}

bool CMP_BY_ID(Book a, Book b){
    return a.ID < b.ID ;
}

bool CMP_BY_YEAR(Book a,Book b){
    if(a.year < b.year) return true;
    else if(a.year > b.year )return false;
    else return a.ID < b.ID;
}

bool CMP_BY_Rating(Book a,Book b){
    if(a.rating < b.rating) return true;
    else if(a.rating > b.rating )return false;
    else return a.ID < b.ID;
}

int sortDB(std::vector<Book> &db, int sortingMethod){
    switch (sortingMethod){
    case 1:
        sort(db.begin(),db.end(),CMP_BY_ID);
        break;
    case 2:
        sort(db.begin(),db.end(),CMP_BY_YEAR);
        break;
    case 3:
        sort(db.begin(),db.end(),CMP_BY_Rating);
        break;
    default:
        return 1;
    }
    return 0;
}
#endif