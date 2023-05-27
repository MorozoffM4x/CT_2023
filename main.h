#pragma once

int reader_csv(const char* file_name);
string get_date_time(const char* SS_Time);
int merge_files(const char* file_path);
string get_d_t(const char* d_time1, const char* d_time2);
string get_d_t_min_station(void);
string get_d_t_max_station(void);
string get_d_t_min_sat(void);
string get_d_t_max_sat(void);
void set_station_dic(map<string, int>& stat_s);
void set_sat_dic(map<string, int> &sat_s);