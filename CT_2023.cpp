#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <map>
#include <boost/filesystem.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/format.hpp>

using namespace boost::filesystem;
using namespace boost::posix_time;
using namespace std;

#include "main.h"
#include <format>
#include <filesystem>

const char* file_path = "DATA_Files\\CSV_Facility2Constellation\\";
const char* file_name = "Facility-Anadyr1.csv";
const char* SS_Time = "13 Jun 2027 23:51:33.468";
const char* SS2_Time = "14 Jun 2027 00:00:01.000";

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

    //reader_csv(result); //чтение csv
    merge_files(file_path);

    cout << get_date_time(SS_Time)<<endl; //Получение строки нужного формата с датой и временем

    boost::posix_time::time_duration diff;
    
    ptime xTimeStr(time_from_string(get_date_time(SS_Time)));
    ptime xTimeStr2(time_from_string(get_date_time(SS2_Time)));
    cout << xTimeStr << endl;
    cout << xTimeStr2 << endl;
    diff = xTimeStr2 - xTimeStr;

    cout << diff << endl; //Выводит разницу времени

    long milliseconds = diff.total_milliseconds();
    cout << milliseconds << endl; //Выводит разницу времени в милисекундах

    boost::format output("%.3f");
    output % (milliseconds / 1000.0);
    std::cout << output << std::endl; //Выводит разницу времени в секундах

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

string get_date_time(const char* SS_Time)
{
    const char* m = SS_Time;
    char s;
    string day, month, year, date_time_final, mnth, time;

    map<string, int> months{
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    
    for (int a = 0; a != 2; a++) 
    {
        day.append(1, m[a]);
    }
    for (int a = 3; a != 6; a++)
    {
        month.append(1, m[a]);
    }
    if (months[month] < 10)
    {
        mnth = "0";
        mnth.append(to_string(months[month]));
    }
    else
        mnth = to_string(months[month]);

    for (int a = 7; a != 11; a++)
    {
        year.append(1, m[a]);
    }
    for (int a = 12; a != 24; a++)
    {
        time.append(1, m[a]);
    }

    date_time_final.append(year);
    date_time_final.append("-");
    date_time_final.append(mnth);
    date_time_final.append("-");
    date_time_final.append(day);
    date_time_final.append(" ");
    date_time_final.append(time);

    return date_time_final;

}


int merge_files(const char* file_path)
{
    string path = file_path;
    cout << file_path << endl;
    return 0;
}