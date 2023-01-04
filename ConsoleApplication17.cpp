#include <iostream>
#include <algorithm>

using namespace std;

struct Time {
	int hours;
	int minutes;
};

int main() {
	Time start, end, interval;
	char action;

	cout << "Enter time (hh:mm): ";
	cin >> start.hours >> start.minutes;

	cout << "Enter action (+/-): ";
	cin >> action;

	cout << "Enter time interval (hh:mm): ";
	cin >> interval.hours >> interval.minutes;

	// add or subtract the time interval
	if (action == '+') {
		end.hours = start.hours + interval.hours;
		end.minutes = start.minutes + interval.minutes;
	}
	else if (action == '-') {
		end.hours = start.hours - interval.hours;
		end.minutes = start.minutes - interval.minutes;
	}

	// handle cases where minutes or hours go over or under the 24-hour limit
	if (end.minutes >= 60) {
		end.hours += end.minutes / 60;
		end.minutes = end.minutes % 60;
	}
	else if (end.minutes < 0) {
		end.hours -= (abs(end.minutes) / 60) + 1;
		end.minutes = 60 - (abs(end.minutes) % 60);
	}
	if (end.hours >= 24) {
		end.hours = end.hours % 24;
	}
	else if (end.hours < 0) {
		end.hours = 24 - (abs(end.hours) % 24);
	}

	cout << "End time: " << end.hours << ":" << end.minutes << endl;

	// calculate the time interval between start and end
	int interval_hours, interval_minutes;
	if (end.hours > start.hours) {
		interval_hours = end.hours - start.hours;
	}
	else {
		interval_hours = start.hours - end.hours;
	}
	if (end.minutes > start.minutes) {
		interval_minutes = end.minutes - start.minutes;
	}
	else {
		interval_minutes = start.minutes - end.minutes;
	}

	cout << "Time interval: " << interval_hours << ":" << interval_minutes << endl;

	return 0;
}