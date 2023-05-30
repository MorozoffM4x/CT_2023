#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <map>
#include <list>
#include <iterator>
#include <vector>;
#include <boost/filesystem.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/format.hpp>
#include <omp.h>
#include <chrono>



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
int g_nNumberOfThreads;


string satellite = "DATA_Files\\Russia2Constellation.csv";
string facility = "DATA_Files\\Facility2Constellation.csv";
map<string, int> sattelites_memory;
map<string, int> sattelites_flags;
map<string, int> stations_sat;
map<string, int> stations_memory;
string dt_min_stat;
string dt_max_stat;
map<string, string> dt_minmax_sat;
map<string, string> dt_minmax_stat;
list <string> stations;
list <string> sattelites;
vector<vector<string>> Russia2Constellation; 
vector<vector<string>> Facility2Constellation;

string d_t = "2020-12-12 00:00:00.000";
string d_t2 = "2027-06-01 04:20:46.789";

boost::posix_time::time_duration diff;
boost::posix_time::time_duration sec_fin;

//addr: maxodrom.ru (31.31.196.25)
//base: u0632405_CT_2023
//user: u0632405_max
//Pass: jL2wJ8wE4syH7gM1

//13 Jun 2027 23:51:33.468    14 Jun 2027 00:00:01.000     507.532


int main()
{
    clock_t start, end;
    int cores_count = thread::hardware_concurrency(); //Узнаем к-во ядер
    cout << cores_count << " Cores in use." << endl;
    g_nNumberOfThreads = cores_count;
    //char result[100];
    //strcpy_s(result, file_path);
    //strcat_s(result, file_name);

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

    //------------Инициализируем переменные------------//
    start = clock();
    parseCSV(satellite, Russia2Constellation);
    end = clock();
    time_taken(start, end);
    start = clock();
    parseCSV(facility, Facility2Constellation);
    end = clock();
    time_taken(start, end);
    start = clock();
    get_dt_minmax_sat(dt_minmax_sat);
    end = clock();
    time_taken(start, end);
    start = clock();
    get_dt_minmax_station(dt_minmax_stat);
    end = clock();
    time_taken(start, end);
    start = clock();
    set_sat_dic(sattelites_memory);
    end = clock();
    time_taken(start, end);
    start = clock();
    set_sat_dic(sattelites_flags);
    end = clock();
    time_taken(start, end);
    start = clock();
    set_station_dic(stations_sat);
    end = clock();
    time_taken(start, end);
    start = clock();
    set_station_dic(stations_memory);
    end = clock();
    time_taken(start, end);
    //map <string, string>::iterator it;
    //for (it = sattelites_memory.begin(); it != sattelites_memory.end(); ++it)
    //{
    //    cout << "Страна: " << (*it).first << endl;
    //    cout << "Столица: " << (*it).second << endl;
    //}
    //cout << sattelites_memory["Name_sat"] << endl;
    //cout << sattelites_flags["Name_sat"] << endl;
    //set_station_dic(stations_sat);
    //set_station_dic(stations_memory);

    //get_dt_minmax_sat(dt_minmax_sat);
    //// 
    //cout << dt_minmax_sat["dt_min_stat"] << endl;
    //cout << dt_minmax_sat["dt_max_stat"] << endl;
    
    //-----------------------------------------------------------//
    //get_dt_minmax_station(dt_minmax_stat);
    //cout << dt_minmax_stat["dt_min_stat"] << endl;
    //copy(stations.begin(), stations.end(), ostream_iterator<string>(cout, " "));
    //cout << endl;

    // 
    //for (vector<vector<string>>::iterator row = Russia2Constellation.begin(); row != Russia2Constellation.end(); ++row) {
    //    for (vector<string>::iterator col = row->begin(); col != row->end(); ++col) {

    //        cout << *col;
    //    }
    //}
    //for (size_t i = 0; i < Russia2Constellation.size(); ++i)  {
    //    
    //    cout << Russia2Constellation[i][4];
    //}
    //cout << Russia2Constellation[3][4];
    //cout << endl;
    // 
    //--------------------Основной цикл--------------------------//

    for (dt_minmax_sat["dt_min_sat"]; dt_minmax_sat["dt_min_sat"] != dt_minmax_stat["dt_max_stat"]; dt_minmax_sat["dt_min_sat"] = second_add(dt_minmax_sat["dt_min_sat"]))
    {
        //auto iter = sattelites_flags.begin();
        //while(iter != sattelites_flags.end())
        //{
        //    string sattel = iter->first;
        //    cout << iter->first; //sattel;
        //    get_sattelites_dt(110101, sattelites);
        //}
        start = clock();
        get_sattelites_dt("110101", sattelites);
        //get_station_dt(stations);
        //ptime TimeNow(time_from_string(dt_minmax_sat["dt_min_sat"]));
        cout << time_from_string(dt_minmax_sat["dt_min_sat"]) << "  ";
        copy(sattelites.begin(), sattelites.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
        end = clock();
        time_taken(start, end);
    }
    
    //-----------------------------------------------------------//
 
    //cout << second_add(d_t);
    
    //for (auto& elem : sattelites)
    //{
    //    std::cout << elem.first << " " << elem.second << " " << endl;
    //}
    //for (auto& elem : stations)
    //{
    //    std::cout << elem.first << " " << elem.second << " " << endl;
    //}
    //cout << dt_max_sat << endl;

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

void get_dt_minmax_station(map<string, string> & stat)
{
    cout << "Create minmax station time..." << endl;
    stat["dt_min_stat"] = "2200-01-01 00:00:00.000";
    stat["dt_max_stat"] = "2020-12-12 00:00:00.000";

    
    omp_set_num_threads(g_nNumberOfThreads);
    #pragma omp critical
    #pragma omp parallel for
    for (int i = 0; i < Facility2Constellation.size(); ++i) {
        string Start_Time, Stop_Time;
        Start_Time = Facility2Constellation[i][4];
        Stop_Time = Facility2Constellation[i][5];
        ptime TimeTemp(time_from_string(Stop_Time));
        ptime TimeTemp2(time_from_string(Start_Time));
        ptime TimeFinal(time_from_string(stat["dt_max_stat"]));
        ptime TimeFinal2(time_from_string(stat["dt_min_stat"]));

        if (TimeTemp > TimeFinal)
        {
            stat["dt_max_stat"] = Stop_Time;
        }
        if (TimeTemp2 < TimeFinal2)
        {
            stat["dt_min_stat"] = Start_Time;
        }
    }
    
    //cout << stat["dt_min_stat"] << endl;
    //cout << stat["dt_max_stat"] << endl;
    cout << "Done" << endl;
}

//void get_dt_minmax_sat(map<string, string> &sat)
//{
//    sat["dt_min_sat"] = "2200-01-01 00:00:00.000";
//    sat["dt_max_sat"] = "2020-12-12 00:00:00.000";
//    ifstream work_file("DATA_Files\\Russia2Constellation.csv");
//    string line;
//    char delimiter = ',';
//    getline(work_file, line);
//
//    while (getline(work_file, line))
//    {
//        stringstream stream(line);
//        string Iter, Name_station, Name_sat, Access, Start_Time, Stop_Time;
//        getline(stream, Iter, delimiter);
//        getline(stream, Name_station, delimiter);
//        getline(stream, Name_sat, delimiter);
//        getline(stream, Access, delimiter);
//        getline(stream, Start_Time, delimiter);
//        getline(stream, Stop_Time, delimiter);
//        
//        ptime TimeTemp(time_from_string(Stop_Time)); 
//        ptime TimeTemp2(time_from_string(Start_Time));
//        ptime TimeFinal(time_from_string(sat["dt_max_sat"]));
//        ptime TimeFinal2(time_from_string(sat["dt_min_sat"]));
//        
//        if (TimeTemp > TimeFinal)
//        {
//            sat["dt_max_sat"] = Stop_Time;
//        }
//        if (TimeTemp2 < TimeFinal2)
//        {
//            sat["dt_min_sat"] = Start_Time;
//        }
//    }
//    cout << sat["dt_min_sat"] << endl;
//    cout << sat["dt_max_sat"] << endl;
//    
//    work_file.close();
//}
void get_dt_minmax_sat(map<string, string>& sat)
{
    cout << "Create minmax sat time..." << endl;
    sat["dt_min_sat"] = "2200-01-01 00:00:00.000";
    sat["dt_max_sat"] = "2020-12-12 00:00:00.000";

        
        omp_set_num_threads(g_nNumberOfThreads);
#pragma omp parallel for
        for (int i = 0; i < Russia2Constellation.size(); ++i) {
            string Start_Time, Stop_Time;
            Start_Time = Russia2Constellation[i][4];
            Stop_Time = Russia2Constellation[i][5];
            ptime TimeTemp(time_from_string(Stop_Time));
            ptime TimeTemp2(time_from_string(Start_Time));
            ptime TimeFinal(time_from_string(sat["dt_max_sat"]));
            ptime TimeFinal2(time_from_string(sat["dt_min_sat"]));

            if (TimeTemp > TimeFinal)
            {
              sat["dt_max_sat"] = Stop_Time;
            }
            if (TimeTemp2 < TimeFinal2)
            {
               sat["dt_min_sat"] = Start_Time;
            }
        }
        cout << "Done" << endl;
}
void set_station_dic(map<string, int>& stat_s)
{
    cout << "Create station list..." << endl;
    string Name_stat;
    for (size_t i = 0; i < Facility2Constellation.size(); ++i) {

        Name_stat = Facility2Constellation[i][1];

        if (!stat_s.count(Name_stat))
        {
            stat_s[Name_stat] = 0;
            //cout << Name_stat << endl;
        }
    }
    cout << "Done" << endl;
}
void set_sat_dic(map<string, int> &sat_s)
{
    cout << "Create sat list..." << endl;
    string Name_sat;
    for (size_t i = 0; i < Russia2Constellation.size(); ++i) {

        Name_sat = Russia2Constellation[i][2];
        
        if (!sat_s.count(Name_sat))
        {
            sat_s[Name_sat] = 0;
            //cout << Name_sat << endl;
        }
    }
    cout << "Done" << endl;
}
void get_station_dt(list <string> &stations)
{
    stations.clear();
    string Name_stat, Start_Time, Stop_Time;
    for (size_t i = 0; i < Russia2Constellation.size(); ++i) {

        Name_stat = Russia2Constellation[i][2];
        Start_Time = Russia2Constellation[i][4];
        Stop_Time = Russia2Constellation[i][5];

        ptime TimeStart(time_from_string(Start_Time));
        ptime TimeStop(time_from_string(Stop_Time));
        ptime TimeNow(time_from_string(dt_minmax_stat["dt_min_stat"]));

        if (TimeNow > TimeStart && TimeNow < TimeStop)
        {
            stations.push_back(Name_stat);
        }
    }
    //ifstream work_file("DATA_Files\\Russia2Constellation.csv");
    //string line;
    //
    //char delimiter = ',';
    //getline(work_file, line);
    //// Прочитали все строчки
    //while (getline(work_file, line))
    //{
    //    stringstream stream(line);
    //    string Iter, Name_station, Name_sat, Access, Start_Time, Stop_Time;
    //    getline(stream, Iter, delimiter);
    //    getline(stream, Name_station, delimiter);
    //    getline(stream, Name_sat, delimiter);
    //    getline(stream, Access, delimiter);
    //    getline(stream, Start_Time, delimiter);
    //    getline(stream, Stop_Time, delimiter);
    //
    //    ptime TimeStart(time_from_string(Start_Time));
    //    ptime TimeStop(time_from_string(Stop_Time));
    //    ptime TimeNow(time_from_string(dt_minmax_stat["dt_min_stat"]));
    //
    //    if (TimeNow > TimeStart && TimeNow < TimeStop)
    //    {
    //        stations.push_back(Name_sat);
    //    }
    //}
    //work_file.close();
    ////return stations;
}
void get_sattelites_dt(string sattel, list <string> &sattelites)
{
    sattelites.clear();
 
    omp_set_num_threads(g_nNumberOfThreads);
    #pragma omp parallel for
        for (int i = 0; i < Facility2Constellation.size(); ++i)
        {
            string Name_stat, Start_Time, Stop_Time, Name_sat;

            Name_stat = Facility2Constellation[i][1];
            Name_sat = Facility2Constellation[i][2];
            Start_Time = Facility2Constellation[i][4];
            Stop_Time = Facility2Constellation[i][5];

            ptime TimeStart(time_from_string(Start_Time));
            ptime TimeStop(time_from_string(Stop_Time));
            ptime TimeNow(time_from_string(dt_minmax_sat["dt_min_sat"]));

            if (TimeNow >= TimeStart && TimeNow <= TimeStop && Name_sat == sattel)
            {
                sattelites.push_back(Name_stat);
            }
        }
    

}

string second_add(string d_t)
{
    ptime TimeFirst(time_from_string(d_t)+seconds(1));
    string m = to_simple_string(TimeFirst);
    //cout << m << endl;
    //for (int c = 5; c != 0; c--)
    //{
    //    ptime TimeFirst(time_from_string(m) + seconds(1));
    //    m = to_simple_string(TimeFirst);
    //    cout << m << endl;
    //}

    return m;
}
string second_minus(string d_t)
{
    ptime TimeFirst(time_from_string(d_t) - seconds(1));
    string m = to_simple_string(TimeFirst);
    return m;
}
//void parseCSV(vector<vector<string>> & Russia2Constellation)
//{
//    ifstream data("DATA_Files\\Russia2Constellation.csv");
//    string line;
//    while (getline(data, line))
//    {
//        stringstream lineStream(line);
//        string cell;
//        vector<string> parsedRow;
//        while (getline(lineStream, cell, ','))
//        {
//            parsedRow.push_back(cell);
//        }
//        Russia2Constellation.push_back(parsedRow);
//    }
//}
void parseCSV(string file, vector<vector<string>>& vec)
{
    cout << "Csv Parsing..." << endl;
    ifstream work_file(file);
    string line;

    char delimiter = ',';
    getline(work_file, line);
    // Прочитали все строчки
    while (getline(work_file, line))
    {
        vector<string> parsedRow;
        stringstream stream(line);
        string Iter, Name_station, Name_sat, Access, Start_Time, Stop_Time;
        getline(stream, Iter, delimiter);
        getline(stream, Name_station, delimiter);
        getline(stream, Name_sat, delimiter);
        getline(stream, Access, delimiter);
        getline(stream, Start_Time, delimiter);
        getline(stream, Stop_Time, delimiter);
        parsedRow.push_back(Iter);
        parsedRow.push_back(Name_station);
        parsedRow.push_back(Name_sat);
        parsedRow.push_back(Access);
        parsedRow.push_back(Start_Time);
        parsedRow.push_back(Stop_Time);

        vec.push_back(parsedRow);
    }
    work_file.close();
    cout << "Done" << endl;
}
void time_taken(double start, double end)
{
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}


// Если станция занята спутником, то достиг ли он предела видимости и не равна ли память нулю.
// Если нет, то спутнику минус 32 Мбайта (зоркий) или 128 Мбайт (киносат), станции плюс 32 Мбайта (зоркий) или 128 Мбайт (киносат).
// Если станция не занята, то выбор спутника.
// Выбрать спутник по условию:
// 
// ------------Флаги: 0 - свободен, 1 - фото, 2 - сливает--------------//
//  Выбрать свободный спутник с максимальным объемом.
//  Если спутники есть, то проверить их занятость.
//  Проверить достижение минимума занятости.
//  Если да, то киносат иначе зоркий.
//  Если нет, то выбрать с максимальным объемом.
// 
// 
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