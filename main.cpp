#include "functions.h"

int start;
void menu(){
    cout<<"select an action: "<<endl;
    cout<<"(0) exiting the program "<<endl;
    cout<<"(1) data entry "<<endl;
    cout<<"(2) print"<<endl;    
    cout<<"(3) change  "<<endl;
    cout<<"(4) delete "<<endl;
    cout<<"(5) add "<<endl;
    cout<<"(6) sorting  "<<endl;
    cout<<"(7) save "<<endl;
    cout<<"your choice: ";
    cin>>start;
}

void main(){

    menu();

    
    int amount_data = 0;
    string filename;
    
    Data* d = new Data[amount_data];

    while(start != 0){
        switch (start) {
        case 1:
            system("cls");

            data_entry(d, amount_data);

            system("pause");
            system("cls");
            menu();
            break;

        case 2:
            system("cls");

            if (amount_data != 0) {
                print(d, amount_data);
            }
            else {
                cout << "the database is empty" << endl;
            }

            system("pause");
            system("cls");
            menu();
            break;
        case 3:
            system("cls");

            if (amount_data != 0) {
                data_change(d, amount_data);
            }
            else {
                cout << "the database is empty" << endl;
            }

            system("pause");
            system("cls");
            menu();
            break;
        case 4:
            system("cls");

            if (amount_data != 0) {
                data_delete(d, amount_data);
            }
            else {
                cout << "the database is empty" << endl;
            }

            system("pause");
            system("cls");
            menu();
            break;
        case 5:
            system("cls");


            if (amount_data != 0) {
                add_data(d, amount_data);
                amount_data++;
            }
            else {
                cout << "the database is empty" << endl;
            }

            system("pause");
            system("cls");
            menu();
            break;
        case 6:
            system("cls");

            if (amount_data != 0) {
                data_sort(d, amount_data);
            }
            else {
                cout << "the database is empty" << endl;
            }

            system("pause");
            system("cls");
            menu();
            break;
        case 7:
            system("cls");

            cout << "enter file name: ";
            cin >> filename;

            if (amount_data != 0) {
                saving_data(d, amount_data, filename);
            }
            else {
                cout << "the database is empty" << endl;
            }

            system("pause");
            system("cls");
            menu();
            break;

        default:
            cout << "the action number is entered incorrectly" << endl;
            system("pause");
            system("cls");
            menu();
            break;
        }
    }
}