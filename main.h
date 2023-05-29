#pragma once

int reader_csv(const char* file_name);
string get_date_time(const char* SS_Time);
int merge_files(const char* file_path);
string get_d_t(const char* d_time1, const char* d_time2);
void set_station_dic(map<string, int>& stat_s);
void set_sat_dic(map<string, int> &sat_s);
void get_dt_minmax_sat(map<string, string> & sat);
void get_dt_minmax_station(map<string, string> & stat);
string second_add(string d_t);
string second_minus(string d_t);
void get_station_dt(list <string>& stations);
void parseCSV(string file, vector<vector<string>>& vec);