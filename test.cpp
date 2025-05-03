#include <iostream>
#include <iomanip>
#include <ctime>

// [19920104_091532]

void    display_timestamp(tm  *time)
{
    std::cout << '[' << 1900 + time->tm_year
        << std::setfill('0') << std::setw(2) << time->tm_mon + 1
        << std::setw(2) << time->tm_mday
        << '_'
        << std::setw(2) << time->tm_hour
        << std::setw(2) << time->tm_min
        << std::setw(2) << time->tm_sec
        << ']'
        << '\n';
}
int main(void)
{
    time_t time = std::time(NULL);
    tm  *time_struct = localtime(&time);

    display_timestamp(time_struct);
    // std::cout << time_struct->tm_sec << '\n';
    // std::cout << time_struct->tm_min << '\n';
    // std::cout << time_struct->tm_hour << '\n';
    // std::cout << time_struct->tm_mday << '\n';
    // std::cout << time_struct->tm_mon << '\n';
    // std::cout << time_struct->tm_year << '\n';
    // std::cout << time_struct->tm_wday << '\n';
    // std::cout << time_struct->tm_yday << '\n';
    return (0);
}