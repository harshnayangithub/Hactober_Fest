#include <iostream>
using namespace std;

class publication
{
private:
    string title;
    float price;

public:
    publication()
    {
        title = "";
        price = 0.0;
    }
    publication(string title, float price)
    {
        this->title = title;
        this->price = price;
    }

    void getdata()
    {
        cout << "enter the title and price: ";
        cin >> title >> price;
    }

    void putdata()
    {
        try
        {
            if (title.length() < 3)
                throw title;
            cout << "title: " << title << endl;
        }
        catch (string s)
        {
            cout << "invalid title\n";
            title = "";
            cout<<"title :"<<title<<endl;
        }
        try
        {
            if (price < 0.0)
                throw price;
            cout << "price: " << price << endl;
        }
        catch (float f)
        {
            cout << "invalid price\n";
            price = 0.0;
            cout<<"price :"<<price<<endl;
        }
    }
};

class book : public publication
{
private:
    int pages;

public:
    book():publication(){
        pages = 0;
    }

    book(string title, float price, int pages):publication(title, price){
        this->pages=pages;
    }

    void getdata(){
        publication::getdata();
        cout<<"enter the no. of pages in the book: ";
        cin>>pages;
    }

    void putdata(){
        publication::putdata();
        try{
            if (pages<0)
            {
                throw pages;
            }
            cout<<"no. of pages: "<<pages<<endl;
        }
        catch(int p){
            cout<<"invalid pages\n";
            pages = 0;
            cout<<"pages : "<<pages<<endl;
        }
    }
};

class tape : public publication
{
private:
    float playtime;

public:
    tape():publication(){
        playtime = 0.0;
    }

    tape(string title, float price, float playtime):publication(title, price){
        this->playtime=playtime;
    }

    void getdata(){
        publication::getdata();
        cout<<"enter the playtime: ";
        cin>>playtime;
    }

    void putdata(){
        publication::putdata();
        try{
            if (playtime<0.0)
            {
                throw playtime;
            }
            cout<<"playtime: "<<playtime<<endl;
        }
        catch(float t){
            cout<<"invalid playtime\n";
            playtime = 0.0;
            cout<<"playtime: "<<playtime<<endl;
        }
    }
};

int main(){
    book b;
    cout<<"\n\tbook\n";
    b.getdata();
    tape t;
    cout<<"\n\ttape\n";
    t.getdata();
    cout<<"\n\tbook\n";
    b.putdata();
    cout<<"\n\ttape\n";
    t.putdata();

    return 0;
}