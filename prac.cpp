#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item{
    public: 
    int code;
    string name;
    float cost;
    int qty;
    
    Item(){
        code = 0;
        name = "";
        cost = 0.0;
        qty = 0;
    }
    Item(int code, string name, float cost, int qty){
        this->code = code;
        this->name = name;
        this->cost = cost;
        this->qty = qty;
    }
    
    void display()const {
        cout<<"item code: "<<code<<"\nitem Name: "<<name<<"\nitem cost: "<<cost<<"\nqty: "<<qty<<endl;
    }
};

class Record{
    private:
    vector<Item> items;
    public:
    void insertandsortitem(){
        Item newitem;
        cout << "Enter Item Code: ";
        cin >> newitem.code;
        cout << "Enter Item Name: ";
        cin >> newitem.name;
        cout << "Enter Item Cost: ";
        cin >> newitem.cost;
        cout << "Enter Item Quantity: ";
        cin >> newitem.qty;

        items.push_back(newitem);

        sort(items.begin(), items.end(), [](const Item &a, const Item &b){
            return a.code<b.code;
        });

        cout<<"item added and sorted successfully"<<endl;
    }

    void searchitembycode(){
        int searchcode;
        cout<<"enter the code to search: ";
        cin>>searchcode;

        auto it = lower_bound(items.begin(), items.end(), searchcode, [](const Item &a, int value){
            return a.code<value;
        });
        if (it != items.end() && it->code == searchcode)
        {
            cout<<"item found\n";
            it->display();
        }
        else{
            cout<<"item not found\n";
        }
    }

    void searchitembyname(){
        string searchname;
        cout<<"enter the name to search: ";
        cin>>searchname;

        auto it = find_if(items.begin(), items.end(), [&searchname](const Item &a){
            return a.name == searchname;
        });
        if (it != items.end())
        {
            cout<<"item found\n";
            it->display();
        }
        else{
            cout<<"item not found\n";
        }
    }

    void displayallitems() const{
        cout<<"all items: \n";
        for (const auto &item : items)
        {
            item.display();
        }  
    }

};

int main() {
    Record record;
    int choice;
    do{
        cout<<"1 insert and sort item\n2 search item using code\n3 search item using name\n 4 display all items\n0 exit\n\n";
        cout<<"enter choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice){
            case 1:
            record.insertandsortitem();
            break;
            case 2:
            record.searchitembycode();
            break;
            case 3:
            record.searchitembyname();
            break;
            case 4:
            record.displayallitems();
            break;
            case 0:
            cout<<"\texiting\n";
            break;
            default:
            cout<<"enter valid choice\n";
        }
    }while(choice!=0);
    

    return 0;
}