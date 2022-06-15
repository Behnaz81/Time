#include<iostream>
#include<string>
using namespace std;

class Time
{
	int minute;
	int hour;

public:
	Time(int m, int h);
	Time(int h);
	void setTime(int m, int h);
	void changeTime(int m, int h);
	int compare(Time);
	string timeOfDay();
	void printTime();

	int getMin() { return minute; }
	int getHour() { return hour; }
};

void Time::printTime()
{
	cout.width(2);
	cout.fill('0');
	cout << hour << ":";
	cout.width(2);
	cout.fill('0');
	cout << minute;
}

Time::Time(int m, int h)
{
	setTime(m, h);
}

Time::Time(int h)
{
	setTime(0, h);
}

void Time::setTime(int m, int h)
{
	if (m < 0 || h < 0 || m>59 || h>23)
	{
		//cout << "Invalid!\n";
       abort();
	}
		
	hour = h;
	minute = m;
}

string Time::timeOfDay()
{
	if (hour < 12 && hour >= 0)
		return "Morning";
	else if (hour == 12 && minute == 0)
		return "Noon";
	else if (hour > 12 && hour < 17)
		return "Afternoon";
	else if (hour >= 17 && hour < 20)
		return "Evening";
	return "Night";
}

int Time::compare(Time t)
{
	if (t.hour > hour) // this < t
	{
		return -1;
	}
	else if (t.hour < hour)
		return 1;
	else
	{
		if (minute < t.minute)
			return -1;
		else if (minute > t.minute)
			return 1;
		else
			return 0;
	}
}

void Time::changeTime(int m, int h)
{
	setTime(m, h);
}

int main()
{
	Time time1(59,11);
	Time time2(12);
	Time time3(1,12);
	Time time4(59,16);
	Time time5(17);
	Time time6(59,19);
	Time time7(20);
	Time time8(59,23);

	cout << "Times of Day:\n";
	time1.printTime();
	cout << endl;
	cout << time1.timeOfDay() << endl;
	time2.printTime();
	cout << endl;
	cout << time2.timeOfDay() << endl;
	time3.printTime();
	cout << endl;
	cout << time3.timeOfDay() << endl;
	time4.printTime();
	cout << endl;
	cout << time4.timeOfDay() << endl;
	time5.printTime();
	cout << endl;
	cout << time5.timeOfDay() << endl;
	time6.printTime();
	cout << endl;
	cout << time6.timeOfDay() << endl;
	time7.printTime();
	cout << endl;
	cout << time7.timeOfDay() << endl;
	time8.printTime();
	cout << endl;
	cout << time8.timeOfDay() << endl << endl;

	cout << "Compare Time: (==:0, <:-1, >:1)\n";
	time1.printTime();
	cout << " ? ";
	time2.printTime();
	cout<<'\n'<<time1.compare(time2) << endl;
	time4.printTime();
	cout << " ? ";
	time3.printTime();
	cout << '\n'<<time4.compare(time3) << endl;
	Time time9(17);
	time5.printTime();
	cout << " ? ";
	time9.printTime();
	cout << '\n' << time5.compare(time9) << endl;

	cout << endl << "Change Time:\nBefore: ";
	time1.printTime();
	time1.changeTime(12, 3);
	cout << "\nAfter: ";
	time1.printTime();

	//Time time4(1, 60);  //error
	//Time time5(-1, 34);  //error
	//Time time6(2, -2);   //error

	return 0;
}
