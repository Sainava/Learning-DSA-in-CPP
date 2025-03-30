#include<iostream>
using namespace std;

class date{
    int day;
    int month;
    int year;
    public:
    date(int day,int month,int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void showdate(){
        cout << "Date is : " << day << "/" << month << "/" << year << endl;
    }

    date& operator++(){
        day++;
        if(day>30){
            day=1;
            month++;
            if(month>12){
                month=1;
                year++;
            }
        }
        return *this;
    }

    date& operator-(date &temp){
        //     (this->day)--;
        //     if(this->day<1){
        //         this->day=30;
        //         (this->month)--;
        //         if(this->month<1){
        //             this->month=12;
        //             this->year--;
        //         }
        //     }
        // return *this;

          (day)--;
            if(day<1){
                day=30;
                (month)--;
                if(month<1){
                    month=12;
                    year--;
                }
            }
        return *this;
    }
};

int main(){
   date d(26,11,2024);
   d.showdate();
   ++d;
    d.showdate();
    date d1(1,1,2024);
    d-d1;
    d.showdate();
    d-d1;
    d.showdate();

    return 0;
}