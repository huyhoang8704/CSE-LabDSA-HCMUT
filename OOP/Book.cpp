#include <bits/stdc++.h>
using namespace std;



class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book():title(nullptr) , authors(nullptr), publishingYear(0) {}

    Book(const char* title, const char* authors, int publishingYear):publishingYear(publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        if (title != nullptr) {
            this->title = new char[strlen(title) + 1];
            strcpy(this->title, title);  // copy
        }
        
        if (authors != nullptr) {
            this->authors = new char[strlen(authors) + 1];
            strcpy(this->authors, authors);
        }
    }
    // copy constructor
    Book(const Book &book) : title(nullptr), authors(nullptr), publishingYear(book.publishingYear)
    {
        if (book.title != nullptr) {
            this->title = new char[strlen(book.title) + 1];
            strcpy(this->title, book.title);
        }
        
        if (book.authors != nullptr) {
            this->authors = new char[strlen(book.authors) + 1];
            strcpy(this->authors, book.authors);
        }
    }
    
    void setTitle(const char* title)
    {
        this ->title = new char[strlen(title) + 1];
        int i=0;
        while(title[i]){
            this->title[i] = title[i];
            i++;
        }
        this->title[i]= '\0';

    }

    void setAuthors(const char* authors)
    {
        this->authors = new char[strlen(authors) + 1];
        int i=0; 
        while(authors[i]){
            this->authors[i] = authors[i];
            i++;
        }
        this->authors[i] = '\0';

    }

    void setPublishingYear(int publishingYear)
    {
        this ->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        return title;
    }

    char* getAuthors() const
    {
        return authors;
    }

    int getPublishingYear() const
    {
        return publishingYear;
    }

    ~Book()
    {
        delete[] title;
        delete [] authors;
        publishingYear =0;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};

int main(){
    Book book1("Giai tich 1","Nguyen Dinh Huy",2000);
Book book2 = book1;
book2.printBook();
}