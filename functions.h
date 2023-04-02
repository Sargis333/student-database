#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct initial {
    string surname;
    string name;
    string patronymic;
};

struct birth_date {
    int day;
    int month;
    int year;
};

struct address{
    string city;
    char home;
};

struct Data{
    initial initial;
    birth_date date;
    address address;
};


void data_entry(Data* (&d), int& n);
void print(Data* (&d), int n);
void data_change(Data* (&d), int n);
void data_delete(Data* (&d), int& n);
void copy(Data* (&d_n), Data* (&d_o), int n);
void copy(Data& d_n, Data& d_o);
void add_data(Data* (&d), int &n);
void data_sort(Data* d, int n);
void saving_data(Data* d, int n, string filename);