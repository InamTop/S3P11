#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Office
{
    int no; //номер
    string name; //название
    string model; //Модель
    int colvo; //кол-во 
    int price; //стоимость
    int year; //год выпуска
};

void output_file(struct Office* p)
{
    ofstream fout;
    fout.open("office.txt");
    for (int i = 0; i < 7; i++) {
        fout << p[i].no << " " << p[i].name << " " << p[i].model << " " << p[i].colvo << " " << p[i].price << " " << p[i].year << endl;
    }
    fout.close();
}

void Prosmotr(Office* p)

{
    cout << "Номер/Название/Кол-во/Стоимость/Год выпуска" << endl;

    for (int i = 0; i < 7; i++)

    {
        cout << p[i].no << " " << p[i].name << " " << p[i].model << " " << p[i].colvo << " " << p[i].price << " " << p[i].year << endl;
    }
}

void Edit(struct Office* p)
{

    int i;
    cout << "n input N string for edit: ";
    cin >> i;
    cout << "no: ";
    cin >> p[i].no;
    cout << "name: ";
    cin >> p[i].name;
    cout << "gldoc: ";
    cin >> p[i].model;
    cout << "coldoc: ";
    cin >> p[i].colvo;
    cout << "decr: ";
    cin >> p[i].price;
    cout << "money: ";
    cin >> p[i].year;
    return;
}

void NewFile(Office* p)

{
    char name[20];

    cout << "Введите название нового файла:" << endl;

    cin >> name;

    ofstream tin;

    tin.open(name);

    for (int i = 0;i < 7;i++)

    {
        tin << p[i].no << endl;

        tin << p[i].name << endl;

        tin << p[i].model << endl;

        tin << p[i].colvo << endl;

        tin << p[i].price << endl;

        tin << p[i].year << endl;

        tin << " " << endl;
    }

    tin.close();
}

int TotalCost(struct Office* p)
{
    int k = 0;
    for (int i = 0; i < 7; i++)
    {
        k += p[i].price*p[i].colvo;
    }
    return k;
}

int main()

{
    setlocale(LC_ALL, "rus");
    Office* office = new Office[7];
    Prosmotr(office);
    Edit(office);
    output_file(office);

    output_file(office);
    TotalCost(office);
    delete[] office;

    office = NULL;

    return 0;
}