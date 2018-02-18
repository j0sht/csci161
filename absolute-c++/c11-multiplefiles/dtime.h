// This is the header file dtime.h.
// This is the interface for the class DigitalTime.
// Values of this type are times of day. The values are input and output
//  in 24-hour notation, as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.
#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using std::istream;
using std::ostream;

namespace DTimeTate {
    class DigitalTime {
    public:
	DigitalTime(int theHour, int theMinute);
	// Initializes the time value to 0:00 (which is midnight)
	DigitalTime();
	int getHour() const;
	int getMinute() const;
	// Changes the time to minutesAdded minutes later.
	void advance(int minutesAdded);
	// Changes the time to hoursAdded hours plus
	//  minutesAdded minutes later
	void advance(int hoursAdded, int minutesAdded);
	// Operators
	friend bool operator ==(const DigitalTime &time1,
				const DigitalTime &time2);
	friend istream& operator >>(istream& ins, DigitalTime& theObject);
	friend ostream& operator <<(ostream& outs,
				    const DigitalTime& theObject);
    private:
	int hour, minute;
    };
} // DTimeTate
#endif // DTIME_H
