#ifndef A7_DATE_HPP
#define A7_DATE_HPP

typedef struct r_date range;

class Date {

public:

	Date(){}
	void set_day(int day_) {this->day = day_;}
	bool have_interference(range first , range second);

private:

    int day;

};

struct r_date{
	Date start;
	Date end;
};

#endif