#include <iostream>
#include <string>

using namespace std;

int convert_to_sec(string hhmmss);
string convert_time(int sec);
string formating(int t);
void main_menu();
void menu_with_convert_time();
void menu_with_convert_to_sec();

int main()
{
    while(true)
    {
        main_menu();
    }
    return 0;
}

string convert_time(int sec)
{
    int h = sec/3600;
    int m = (sec - (h*3600))/60;
    int s = sec-(h*3600)-(m*60);
    string res = formating(h)+ ':' + formating(m) + ':' + formating(s);
    return res;
}

string formating(int t)
{
    if (t<10)
    {
        return "0"+ to_string(t);
    }
    else
    {
        return to_string(t);
    }
}

int convert_to_sec(string hhmmss)
{
    int h = ((hhmmss[0]-'0')*10+hhmmss[1]-'0')*3600;
    int m = ((hhmmss[3]-'0')*10+hhmmss[4]-'0')*60;
    int s = (hhmmss[6]-'0')*10+hhmmss[7]-'0';
    return h+m+s;
}

void main_menu()
{
    system("clear");
    int nav;
    cout << "Конверация времени.\n" << "[1] Перевести секунды во время ЧЧ:ММ:СС\n" << "[2] Перевести время ЧЧ:ММ:СС в секунды\n[1/2?]";
    cin >> nav;
    switch(nav)
    {
        case 1:
        {
            menu_with_convert_time();
        }
        break;
        
        case 2:
        {
            menu_with_convert_to_sec();
        }
        break;

        default:
            cout << "Завершение программы\n" << endl;
            exit(0);
    }
}

void menu_with_convert_time()
{
    bool isContinue = true;
    char n;

    while(isContinue)
    {
        system("clear");
        int sec;
        cout << "Введите количество секунд: " << endl;
        cin >> sec;
        cout << convert_time(sec) << endl;
        cout << "Заново? [y/n]" << endl;
        cin >> n;
        if (n == 'n')
            isContinue = false;
    }
}

void menu_with_convert_to_sec()
{
    bool isContinue = true;
    char n;

    while(isContinue)
    {
        system("clear");
        string hhmmss;
        cout << "Введите время в формате ЧЧ:ММ:СС: " << endl;
        cin >> hhmmss;
        cout << convert_to_sec(hhmmss) << endl;
        cout << "Заново? [y/n]" << endl;
        cin >> n;
        if (n == 'n')
            isContinue = false;
    }
}

void interface_for_convert(string greetings)
{
    bool isContinue = true;
    char n;

    while(isContinue)
    {
        system("clear");
        string var;
        cout << greetings << endl;
        cin >> var;
        cout << convert_to_sec(var) << endl;
        cout << "Заново? [y/n]" << endl;
        cin >> n;
        if (n == 'n')
            isContinue = false;
    }
}