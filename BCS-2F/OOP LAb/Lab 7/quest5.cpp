#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;


class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    virtual void checkOut() {
        cout << title << " has been checked out." << endl;
    }

    virtual void returnItem() {
        cout << title << " has been returned." << endl;
    }

   
    bool matchesTitle(const string& searchTerm) {
        return title == searchTerm;
    }

   
    virtual bool matchesAuthor(const string& searchTerm) {
        return false; 
    }

  
    virtual bool matchesIssueNumber(int issueNumber) {
        return false; 
    }
};


class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo(); 
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    bool matchesAuthor(const string& searchTerm) override {
        return author == searchTerm; 
    }
};


class DVD : public Media {
private:
    string director;
    double duration; 
    string rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, double dur, string rat)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override {
        Media::displayInfo(); 
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};


class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo(); 
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};


class Magazine : public Media {
private:
    int issueNumber;
    string frequency;

public:
    Magazine(string t, string pubDate, string id, string pub, int issue, string freq)
        : Media(t, pubDate, id, pub), issueNumber(issue), frequency(freq) {}

    void displayInfo() override {
        Media::displayInfo(); 
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Frequency: " << frequency << endl;
    }

    bool matchesIssueNumber(int issueNum) override {
        return issueNumber == issueNum; 
    }
};


void searchMediaByTitle(Media* media, const string& searchTerm) {
    if (media->matchesTitle(searchTerm)) {
        media->displayInfo();
    }
}


void searchMediaByAuthor(Media* media, const string& searchTerm) {
    if (media->matchesAuthor(searchTerm)) {
        media->displayInfo();
    }
}


void searchMediaByIssueNumber(Media* media, int issueNumber) {
    if (media->matchesIssueNumber(issueNumber)) {
        media->displayInfo();
    }
}


int main() {
 
    Book book("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD cd("Abbey Road", "1969", "C001", "Apple Records", "The Beatles", 17, "Rock");
    Magazine magazine("National Geographic", "2021", "M001", "National Geographic Society", 2021, "Monthly");

   
    cout << "Media Information:" << endl;
    book.displayInfo();
    cout << endl;
    dvd.displayInfo();
    cout << endl;
    cd.displayInfo();
    cout << endl;
    magazine.displayInfo();
    cout << endl;


    book.checkOut();
    book.returnItem();
    dvd.checkOut();
    dvd.returnItem();


    cout << "\nSearching for media by title 'The Great Gatsby':" << endl;
    searchMediaByTitle(&book, "The Great Gatsby");


    cout << "\nSearching for media by author 'F. Scott Fitzgerald':" << endl;
    searchMediaByAuthor(&book, "F. Scott Fitzgerald");

 
    cout << "\nSearching for magazine by issue number 2021:" << endl;
    searchMediaByIssueNumber(&magazine, 2021);

    return 0;
}