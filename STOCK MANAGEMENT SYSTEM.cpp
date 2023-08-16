#include <iostream>
#include <string.h>
using namespace std;

struct itemEntry {
    float unit_price;
    int copies, product_id;
    char company[30], name[80];
};

class store {
public:
    int numItem;
    itemEntry database[100];

    store() {
        numItem = 0;
    }

    void insertItem(char itemName[], char company[], int pid, int c, float p);
    void deleteItem(char itemName[], int pid);
    itemEntry* search(char itemName[], int pid);
    void updateItem(char itemName[], int pid, int total, float price);
};

void store::insertItem(char itemName[], char company[], int pid, int c, float p) {
    strcpy(database[numItem].name, itemName);
    strcpy(database[numItem].company, company);
    database[numItem].product_id = pid;
    database[numItem].copies = c;
    database[numItem].unit_price = p;
    cout << "\n\t\t ITEM INSERTED SUCCESSFULLY \n";
    numItem++;
}

void store::deleteItem(char itemName[], int pid) {
    for (int i = 0; i < numItem; i++) {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid)) {
            for (int j = i; j < numItem - 1; j++) {
                database[j] = database[j + 1];
            }
            numItem--;
            cout << "\n\t\t ITEM DELETED SUCCESSFULLY \n";
            return;
        }
    }
    cout << "\n\t\t ITEM NOT FOUND \n";
}

itemEntry* store::search(char itemName[], int pid) {
    for (int i = 0; i < numItem; i++) {
        if ((strcmp(itemName, database[i].name) == 0) && (database[i].product_id == pid)) {
            return &database[i];
        }
    }
    return NULL;
}

void store::updateItem(char itemName[], int pid, int total, float p) {
    itemEntry* item = search(itemName, pid);
    if (item != NULL) {
        item->copies += total;
        item->unit_price = p;
        cout << "\n\t\t ITEM UPDATED SUCCESSFULLY \n";
    } else {
        cout << "\n\t\t ITEM NOT FOUND \n";
    }
}

int main() {
    store sto;
    char name[80], company[30];
    int product_id, copies, unit_price, option;
    do {
        cout << "\n\t\t WELCOME TO STOCK MANAGEMENT SYSTEM !!!";
        cout << "\n\t\t\t CONTROL PANNEL";
        cout << "\n\t\t\t 1 Add Items";
        cout << "\n\t\t\t 2 Delete Item Records";
        cout << "\n\t\t\t 3 Search Items";
        cout << "\n\t\t\t 4 Update Items";
        cout << "\n\t\t\t 5 Exit";
        cout << "\n\t\t enter your choice:(1-5)";
        cin >> option;
        switch (option) {
            case 1:
                cin.ignore();
                cout << "\n\t\t\t Enter Name of item:";
                cin.getline(name, 80);
                cout << "\n\t\t\t company:";
                cin.getline(company, 30);
                cout << "\n\t\t\t Enter product ID:";
                cin >> product_id;
                cout << "\n\t\t\t No of copies:";
                cin >> copies;
                cout << "\n\t\t\t Unit price per item:";
                cin >> unit_price;
                sto.insertItem(name, company, product_id, copies, unit_price);
                break;

            case 2:
                cin.ignore();
                cout << "\n\t\t\t Enter name of item:";
                cin.getline(name, 80);
                cout << "\n\t\t\t enter product ID:";
                cin >> product_id;
                sto.deleteItem(name, product_id);
                break;

            case 3:
                cin.ignore();
                cout << "\n\t\t\t enter name of item:";
                cin.getline(name, 80);
                cout << "\n\t\t\t enter product ID:";
                cin >> product_id;
                itemEntry* test;
                test = sto.search(name, product_id);
                if (test != NULL) {
                    cout << "\n\t\t Searching...";
                    cout << "\n\t\t\t   ITEM FOUND" << "\n\t\t\t Item Name:" << test->name
                         << "\n\t\t\t Company Name:" << test->company << "\n\t\t\t product ID:" << test->product_id
                         << "\n\t\t\t Number of copies available:" << test->copies << "\n\t\t\t unit price"
                         << test->unit_price << endl;
                } else
                    cout << "\n\t\t\t ITEM NOT FOUND" << endl;
                break;

            case 4:
                cin.ignore();
                cout << "\n\t\t\t enter details for update -";
                cout << "\n\t\t\t enter product ID:";
                cin >> product_id;
                cout << "\n\t\t\t enter total new entry:";
                cin >> copies;
                cout << "\n\t\t\t enter new price:";
                cin >> unit_price;
                sto.updateItem(name, product_id, copies, unit_price);
                break;
        }
    } while (option != 5);

    return 0;
}
