// This is the implementation file dtime.cpp of the class DigitalTime.
// The interface for the class DigitalTime is in the header file dtime.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
#include "dtime.h"

namespace { // Specifies unnamed namespcase
    // Names defined in the unnamed namespace are local to the
    //  compilation unit. So, these helping functions are local
    //  to the file dtime.cpp
    int digitToInt(char c) {
	return (static_cast<int>(c) - static_cast<int>('0'));
    }

    // Uses iostream, cctype, and cstdlib:
    void readMinute(int& theMinute) {
	char c1, c2;
	cin >> c1 >> c2;
	if (!(isdigit(c1) && isdigit(c2))) {
	    cout << "Error: illegal input to readMinute\n";
	    exit(1);
	}
	theMinute = digitToInt(c1)*10 + digitToInt(c2);
	if (theMinute < 0 || theMinute > 59) {
	    cout << "Error: illegal input to readMinute\n";
	    exit(1);
	}
    }

    // Uses iostream, cctype, and cstdlib
    void readHour(int& theHour) {
	char c1, c2;
	cin >> c1 >> c2;
	if (!(isdigit(c1) && (isdigit(c2) || c2 == ':'))) {
	    cout << "Error: illegal input to readHour\n";
	    exit(1);
	}
	if (isdigit(c1) && c2 == ':') {
	    theHour = digitToInt(c1);
	} else { // (isdigit(c1) && isdigit(c2))
	    theHour = digitToInt(c1)*10 +
		digitToInt(c2);
	    cin >> c2; // discard ':'
	    if (c2 != ':') {
		cout << "Error: illegal input to readHour\n";
		exit(1);
	    }
	}
	if (theHour == 24)
	    theHour = 0; // Standardize midnight as 0:00
	if (theHour < 0 || theHour > 23) {
	    cout << "Error: illeagal input to readHour\n";
	    exit(1);
	}
    }
} // unnamed namespace

namespace DTimeTate {
    // Uses iostream
    ostream& operator <<(ostream& outs, const DigitalTime& theObject) {
	outs << theObject.hour << ':';
	if (theObject.minute < 10)
	    outs << '0';
	outs << theObject.minute;
	return outs;
    }

    // Uses iostream
    istream& operator >>(istream& ins, DigitalTime& theObject) {
	// Within the compilation unit (in this case dtime.cpp),
	//  you can use names in the unnamed namespace w/o qualification
        readHour(theObject.hour);
        readMinute(theObject.minute);
	return ins;
    }

    // Uses iostream and cstdlib
    DigitalTime::DigitalTime(int theHour, int theMinute) {
	if (theHour < 0 || theHour > 24 ||
	    theMinute < 0 || theMinute > 59) {
	    cout << "Illegal argument to DigitalTime constructor.\n";
	    exit(1);
	} else {
	    hour = theHour;
	    minute = theMinute;
	}
	if (hour == 24)
	    hour = 0; // Standardize midnight as 0:00
    }

    DigitalTime::DigitalTime() {
	hour = minute = 0;
    }

    int DigitalTime::getHour() const {
	return hour;
    }

    int DigitalTime::getMinute() const {
	return minute;
    }

    void DigitalTime::advance(int minutesAdded) {
	int grossMinutes = minute + minutesAdded;
	minute = grossMinutes % 60;
	int hourAdjustment = grossMinutes / 60;
	hour = (hour + hourAdjustment) % 24;
    }

    void DigitalTime::advance(int hoursAdded, int minutesAdded) {
	hour = (hour + hoursAdded) % 24;
	advance(minutesAdded);
    }

    bool operator ==(const DigitalTime& time1, const DigitalTime& time2) {
	return (time1.hour == time2.hour && time1.minute == time2.minute);
    }
} // DTimeTate
