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

const char* file_path = "DATA_Files\\";
const char* file_name = "Facility2Constellation.csv";
const char* SS_Time = "13 Jun 2027 23:51:33.468";
const char* SS2_Time = "14 Jun 2027 00:00:01.000";

map<string, int> sattelites;
map<string, int> stations;
//undefined sattel_s = &sattelites;

boost::posix_time::time_duration diff;

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
    //merge_files(file_path);
    set_sat_dic(sattelites);
    set_station_dic(stations);

    for (auto& elem : sattelites)
    {
        std::cout << elem.first << " " << elem.second << " " << endl;
    }
    for (auto& elem : stations)
    {
        std::cout << elem.first << " " << elem.second << " " << endl;
    }

    //cout << get_date_time(SS_Time)<<endl; //Получение строки нужного формата с датой и временем

    
    


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
        string Iter, Name_station, Name_sat, Access, Start_Time, Stop_Time, Duration, Duration_bit; //Start Time,Stop Time,Duration,Duration_bit
        
        // Извлечение всех значений в этой строке
        getline(stream, Iter, delimiter);
        getline(stream, Name_station, delimiter);
        getline(stream, Name_sat, delimiter);
        getline(stream, Access, delimiter);
        getline(stream, Start_Time, delimiter);
        getline(stream, Stop_Time, delimiter);
        getline(stream, Duration, delimiter);
        getline(stream, Duration_bit, delimiter);

        ptime TimeStart(time_from_string(Start_Time));
        ptime TimeStop(time_from_string(Stop_Time));

        diff = TimeStop - TimeStart;
        long milliseconds = diff.total_milliseconds();

        boost::format output("%.3f");
        output % (milliseconds / 1000.0);

        cout << Iter << "   " << Name_station << "  " << Name_sat << "    " << Access << "    " << TimeStart << "    " << TimeStop << "     " << output << "     " << Duration_bit << endl;

    }
    work_file.close();
    return 0;
    
}

string get_date_time(const char* SS_Time)
{
    const char* m = SS_Time;
    //char s;
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
    //string pathh = file_path;
    string pathh = "L\"";
    pathh.append(file_path);
    pathh.append("\"");
    // 
    wstring widestr = std::wstring(pathh.begin(), pathh.end());
    const wchar_t* widecstr = widestr.c_str();

    wpath p{widecstr};
    wcout << p.wstring() << '\n';


    //wstring ws = p.wstring();
    //string s(p.begin(), p.end());
    //cout << s << endl;
    //path p(pathh);


    //for (auto i = directory_iterator(p); i != directory_iterator(); i++)
    //{
    //    if (!is_directory(i->path())) //we eliminate directories
    //    {
    //        cout << i->path().filename().string() << endl;
    //    }
    //    else
    //    continue;
    //}

    //string path = file_path;
    //cout << file_path << endl;
    return 0;
}
string get_d_t(const char* d_time1, const char* d_time2)
{
    ptime xTimeStr(time_from_string(d_time1));
    ptime xTimeStr2(time_from_string(d_time2));
    cout << xTimeStr << endl;
    cout << xTimeStr2 << endl;
    diff = xTimeStr2 - xTimeStr;

    cout << diff << endl; //Выводит разницу времени

    long milliseconds = diff.total_milliseconds();
    cout << milliseconds << endl; //Выводит разницу времени в милисекундах

    boost::format output("%.3f");
    output % (milliseconds / 1000.0);
    
    return output.str();
}
string get_d_t_min_station()
{
    string result;

    return result;
}
string get_d_t_max_station()
{
    string result;

    return result;
}
string get_d_t_min_sat()
{
    string result;

    return result;
}
string get_d_t_max_sat()
{
    string result;

    return result;
}
void set_station_dic(map<string, int>& stat_s)
{

    //string fi = "Russia2Constellation.csv";
    ifstream work_file("DATA_Files\\Facility2Constellation.csv");
    string line;
    char delimiter = ',';

    getline(work_file, line);
    // Прочитали все строчки
    while (getline(work_file, line))
    {
        stringstream stream(line); // Преобразование строки в поток
        string Iter, Name_station; //Start Time,Stop Time,Duration,Duration_bit

        // Извлечение всех значений в этой строке
        getline(stream, Iter, delimiter);
        getline(stream, Name_station, delimiter);

        //cout << Iter << "   " << Name_station << "  " << Name_sat << endl;
        if (!stat_s.count(Name_station))
        {
            stat_s[Name_station] = 0;
        }

    }
    work_file.close();
}
void set_sat_dic(map<string, int> &sat_s)
{

    //string fi = "Russia2Constellation.csv";
    ifstream work_file("DATA_Files\\Russia2Constellation.csv");
    string line;
    char delimiter = ',';

    getline(work_file, line);
    // Прочитали все строчки
    while (getline(work_file, line))
    {
        stringstream stream(line); // Преобразование строки в поток
        string Iter, Name_station, Name_sat; //Start Time,Stop Time,Duration,Duration_bit
        
        // Извлечение всех значений в этой строке
        getline(stream, Iter, delimiter);
        getline(stream, Name_station, delimiter);
        getline(stream, Name_sat, delimiter);

        //cout << Iter << "   " << Name_station << "  " << Name_sat << endl;
        if (!sat_s.count(Name_sat))
        {
            sat_s[Name_sat] = 0;
        }

    }
    work_file.close();
}
// поиск минимальной даты
// поиск максимальной даты
// создать словарь спутников
// создать словарь станций
// найти какие станции в это время какие спутники видят
// прочитать и запомнить из result.csv номер итерации 
// проверить в словаре наличие номера спутника у станции, если зоркий, то только с него сливаем до появления Кино, если Кино, то сливаем с него до конца
// проверить спутники на условия заполнения или съёмки
// если время слива или фото началось, то записать в result.csv итерацию
// проверить память спутника
// проверить наличие станций в момент времени для передачи максимального объема
// сравнить сколько секунд может принять станция и отдать спутник
// если спутник снимает, то мем_ и тотал_мем увеличивается на 1 сек
// если спутник передает, то мем_ уменьшается на 1 сек, а мем_ст_тот увеличивается на 1 сек
// проверить приоритет Kinosat_110101 .. Kinosat_110510 - Киноспутник (высокий приоритет); Kinosat_110601 .. Kinosat_112010 - Зоркий (низкий приоритет)
// если в момент времени у Кино достаточно данных для передачи, то Зоркий прерывается.
// для каждого видимого спутника: если память заполнена на достаточное кол-во секунд для передачи в диапазоне видимости, то передавать. выставить номер спутника в словарь станции
// если спутник слил фото, то проверить на возможность фото
// если время слива или фото закончилось, то записать в result.csv под нужной итерацией
// каждый час сохранять состояние всех станций и спутников в control.csv
// цикл с 5 строки

//---------------------------------------------------------------//

// нужны словари: mem_sat, mem_sat_total, mem_station_total
// нужны функции: sec_add(), find_min_max_datetime(), time_range_sat(), time_range_station()
// result.csv, control.csv

//---------------------------------------------------------------//