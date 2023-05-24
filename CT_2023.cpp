#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <map>

#include "main.h"
#include <format>


//#include <boost/date_time/posix_time/posix_time.hpp>
//#include <boost/thread.hpp>

const char* file_path = "DATA_Files\\CSV_Facility2Constellation\\";
const char* file_name = "Facility-Anadyr1.csv";
const char* SS_Time = "13 Jun 2027 23:51:33.468";

using namespace std;

//addr: maxodrom.ru (31.31.196.25)
//base: u0632405_CT_2023
//user: u0632405_max
//Pass: jL2wJ8wE4syH7gM1

//13 Jun 2027 23:51:33.468    14 Jun 2027 00:00:01.000     507.532


int main()
{
    char result[100];
    strcpy_s(result, file_path);
    strcat_s(result, file_name);
    //const char* all_path = strcat(file_path, file_name);
    //file_name = "DATA_Files\\CSV_Facility2Constellation\\Facility-Anadyr1.csv";

    //ifstream f("DATA_Files\\Facility2Constellation\\Facility-Anadyr1.txt");
    //string s;
    //for (int c = 1; getline(f, s) && c <= 100; ++c) {
    //    if (c > 10 && c <= 100) cout << s << std::endl;
    //}
    //f.close();

    //reader_csv(result);



    cout << get_date_time(SS_Time);

    return 0;
}

int reader_csv(const char* file_name)

{
    string fi = file_name;
    ifstream work_file(fi);
    string line;
    char delimiter = ',';

    getline(work_file, line);
    // Прочитали все строчки
    while (getline(work_file, line))
    {
        stringstream stream(line); // Преобразование строки в поток
        string Iter, Name, Access, Start_Time, Stop_Time, Duration;
        
        // Извлечение всех значений в этой строке
        getline(stream, Iter, delimiter);
        getline(stream, Name, delimiter);
        getline(stream, Access, delimiter);
        getline(stream, Start_Time, delimiter);
        getline(stream, Stop_Time, delimiter);
        getline(stream, Duration, delimiter);



        //cout << "Iter: " << Iter << "  Name: " << Name << "   Access num: " << Access << "   Start: " << Start_Time << "   Stop: " << Stop_Time << "   Duration: " << Duration << endl;
        cout << Iter << "   " << Name << "  " << Access << "    " << Start_Time << "    " << Stop_Time << "     " << Duration << endl;

    }
    work_file.close();
    return 0;
    
}

char get_date_time(const char* SS_Time)
{
    const char* m = SS_Time;
    char s;
    string day, month, year, hour, min, sec, millis;

    map<string, int> months{
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    //format("a = {:02}", a)
    for (int a = 0; a != 2; a++) 
    {
        //s = a[m];
        day.append(1, m[a]);
    }
    for (int a = 3; a != 6; a++)
    {
        //s = a[m];
        month.append(1, m[a]);
        
    }
    for (int a = 7; a != 11; a++)
    {
        //s = a[m];
        year.append(1, m[a]);
    }
    for (int a = 12; a != 14; a++)
    {
        //s = a[m];
        hour.append(1, m[a]);
    }
    for (int a = 15; a != 17; a++)
    {
        //s = a[m];
        min.append(1, m[a]);
    }
    for (int a = 18; a != 20; a++)
    {
        //s = a[m];
        sec.append(1, m[a]);
    }
    for (int a = 21; a != 24; a++)
    {
        //s = a[m];
        millis.append(1, m[a]);
    }
    
    cout << day << " ";
    if (months[month] < 10)
    {
        cout << 0 << months[month] << " ";
    }
    else 
        cout << months[month] << " ";
    //cout << setw(2) << setfill('0') << month_e << " ";

    cout << year << " ";
    cout << hour << " ";
    cout << min << " ";
    cout << sec << " ";
    cout << millis;

    //printf(dt);
    //printf(a[1]);
    //struct std::tm when;
    //std::time(s);
    //string s = ;

    return 0;

}

