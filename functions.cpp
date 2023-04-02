#include "functions.h"


using namespace std;

void data_entry(Data* (&d), int& n){
    cout<<"write the numbers of data: ";
    cin>>n;
    d = new Data[n];
    for(int i=0; i<n;i++){
        cout<<"enetr the full name: ";
        cin >> d[i].initial.surname;
        cin >> d[i].initial.name;
        cin >> d[i].initial.patronymic;

        cout<<"enter the  adress: ";
        cin>>d[i].address.city;
        cin>>d[i].address.home;

        cout<<"enter the date: ";
        cin>>d[i].date.day;
        cin>>d[i].date.month;
        cin>>d[i].date.year;

        cout<<"___________________________________"<<endl;
    }

}
void print(Data* (&d), int n){
    for(int i=0; i < n; i++){
        cout<<"data number "<< i+1<<": "<<endl;

        cout<<"full name: "<< d[i].initial.surname << " " << d[i].initial.name  << " " <<d[i].initial.patronymic <<endl;
        cout<<"adress: "<<d[i].address.city << " " << d[i].address.home<<endl;
        cout<<"date: "<<d[i].date.day<< " " << d[i].date.month << d[i].date.year<<endl; 

        cout<<"___________________________________"<<endl;
    }
}



void data_change(Data* (&d), int n){
    int i;
    cout<< " eneter the item number(from 1 to "<<n<<")"<<endl;
    cin>>i;
    i--;
    
    system("cls");
    if(i >= 0 && i < n ){
        cout<<"enetr the full name: "<<endl;
        cin >> d[i].initial.surname;
        cin >> d[i].initial.name;
        cin >> d[i].initial.patronymic;

        cout<<"enter the  adress: "<<endl;
        cin>>d[i].address.city;
        cin>>d[i].address.home;

        cout<<"enter the date"<<endl;
        cin>>d[i].date.day;
        cin>>d[i].date.month;
        cin>>d[i].date.year;

        system("cls");

        cout<<"the data has been changed";
    }
    else{
        cout<<"incorrect number entered";
    }

}


void data_delete(Data* (&d), int& n){
    int x;
    cout<< " eneter the item number(from 1 to "<<n<<")"<<endl;
    cin>>x;
    x--;
    if(x >= 0 && x < n){


        Data* buf = new Data[n];

        copy(buf, d, n);

        --n;
        d = new Data[n];

        int q = 0;

        for(int i = 0; i <= n; i++){
            if(i != x){
                d[q] = buf[i];
                q++;
            }
        }

        system("cls");
        delete[]buf;
        cout<<"data is deleted"<<endl;
    }
    else{
        cout<<"incorrect number entered"<<endl;
    }
}


void copy(Data* (&d_n), Data* (&d_o), int n){

    for(int i = 0; i < n; i++){
        d_n[i] = d_o[i];
    }
}


void copy(Data& d_n, Data& d_o){
    d_n.initial.surname = d_o.initial.surname;
    d_n.initial.name = d_o.initial.name;
    d_n.initial.patronymic = d_o.initial.patronymic;

    d_n.date.day = d_o.date.day;
    d_n.date.month = d_o.date.month;
    d_n.date.year = d_o.date.year;

    d_n.address.city  = d_o.address.city;
    d_n.address.home = d_o.address.home;

}


void add_data(Data* (&d), int& n){
    Data* buf;
    buf = new Data[n];

    copy(buf,d,--n);

    n++;
    d = new Data[n];

    cout<<"enetr the full name: "<<endl;
    cin>>  d[n].initial.surname >> d[n].initial.name  >> d[n].initial.patronymic;

    cout<<"enter the  adress: "<<endl;
    cin>> d[n].address.city >> d[n].address.home;

    cout<<"enter the date"<<endl;
    cin>>d[n].date.day>> d[n].date.month >> d[n].date.year; 

    system("cls");

    delete[]buf;
}



void data_sort(Data* d,int n){
    Data buf;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(d[i].initial.surname > d[j].initial.surname){
                copy(buf,d[j]);
                copy(d[j], d[i]);
                copy(d[i],buf);
            }
        }
    }
    cout<<"data is sorted"<<endl;
}


void saving_data(Data* d, int n, string filename){
    ofstream record(filename, ios::out);

    if(record){
        record << "number of students: " << n << endl;

        for(int i = 0; i < n; i++){
            record << endl;
            record << "student number: " << i+1 << endl;
            record << endl;
            record << d[i].initial.surname <<" ";
            record << d[i].initial.name << " ";
            record << d[i].initial.patronymic << endl;


            record << d[i].date.day << " ";
            record << d[i].date.month << " ";
            record << d[i].date.year << endl;

            record << d[i].address.city << " ";
            record << d[i].address.home << endl;
        }

    }
    else{
        cout<<"the file did not open"<<endl;
    }

    record.close();
}