/* P1:
 * File: p1calendar.cpp
 * ------------------
 * This file implements the p1calendar.h interface
 */

#include <string>
#include <iostream>
#include "CSC3002OJActive/assignment2/lib.h"
#include "CSC3002OJActive/assignment2/p1calendar.h"

using namespace std;

Month stringToMonth(string s)
{
   if (s == "JANUARY") {
      return JANUARY;
   }
   if (s == "FEBRUARY") {
      return FEBRUARY;
   }
   if (s == "MARCH") {
      return MARCH;
   }
   if (s == "APRIL") {
      return APRIL;
   }
   if (s == "MAY") {
      return MAY;
   }
   if (s == "JUNE") {
      return JUNE;
   }
   if (s == "JULY") {
      return JULY;
   }
   if (s == "AUGUST") {
      return AUGUST;
   }
   if (s == "SEPTEMBER") {
      return SEPTEMBER;
   }
   if (s == "OCTOBER") {
      return OCTOBER;
   }
   if (s == "NOVEMBER") {
      return NOVEMBER;
   }
   if (s == "DECEMBER") {
      return DECEMBER;
   }
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month) {
   switch (month) {
      case JANUARY: return "JANUARY"; 
      case FEBRUARY: return "FEBRUARY"; 
      case MARCH: return "MARCH"; 
      case APRIL: return "APRIL"; 
      case MAY: return "MAY"; 
      case JUNE: return "JUNE"; 
      case JULY: return "JULY"; 
      case AUGUST: return "AUGUST"; 
      case SEPTEMBER: return "SEPTEMBER"; 
      case OCTOBER: return "OCTOBER"; 
      case NOVEMBER: return "NOVEMBER"; 
      case DECEMBER: return "DECEMBER"; 
      default: return "???";
   }
}

Month operator++(Month &month, int)
{
   Month old = month;
   if (month == JANUARY) {
      month = FEBRUARY; 
   }
   else if (month == FEBRUARY) {
      month = MARCH; 
   }
   else if (month == MARCH) {
      month = APRIL;  
   }
   else if (month == APRIL) {
      month = MAY;  
   }
   else if (month == MAY) {
      month = JUNE; 
   }
   else if (month == JUNE) {
      month = JULY; 
   }
   else if (month == JULY) {
      month = AUGUST; 
   }
   else if (month == AUGUST) {
      month = SEPTEMBER; 
   }
   else if (month == SEPTEMBER) {
      month = OCTOBER; 
   }
   else if (month == OCTOBER) {
      month = NOVEMBER; 
   }
   else if (month == NOVEMBER) {
      month = DECEMBER; 
   }
   return old;
}


/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date()
{
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year)
{
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year)
{
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 * In this implementation of the Date class, the day and the month are
 * not stored explicitly but must instead be computed from the dayInYear
 * field.
 */

int Date::getDay() {
   return day;
}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth() {
   return month;
}

int Date::getYear() {
   return year;
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */

string Date::toString()
{
   string monthAbbreviation;
   if (month == JANUARY) {
      monthAbbreviation = "Jan"; 
   }
   if (month == FEBRUARY) {
      monthAbbreviation = "Feb"; 
   }
   if (month == MARCH) {
      monthAbbreviation = "Mar"; 
   }
   if (month == APRIL) {
      monthAbbreviation = "Apr"; 
   }
   if (month == MAY) {
      monthAbbreviation = "May"; 
   }
   if (month == JUNE) {
      monthAbbreviation = "Jun"; 
   }
   if (month == JULY) {
      monthAbbreviation = "Jul"; 
   }
   if (month == AUGUST) {
      monthAbbreviation = "Aug"; 
   }
   if (month == SEPTEMBER) {
      monthAbbreviation = "Sep"; 
   }
   if (month == OCTOBER) {
      monthAbbreviation = "Oct"; 
   }
   if (month == NOVEMBER) {
      monthAbbreviation = "Nov"; 
   }
   if (month == DECEMBER) {
      monthAbbreviation = "Dec"; 
   }
   string result = (integerToString(getDay()) + ("-") + (monthAbbreviation) + ("-") + integerToString(getYear()));
   return result;
   
}

void Date::initDate(int dd, Month mm, int yyyy)
{
   day = dd;
   month = mm;
   year = yyyy;
}

Date operator+(Date date, int delta)
{
   Date result;

   // Get the index of date.
   int prevYear = date.getYear();
   Month prevMonth = date.getMonth();
   int prevDay = date.getDay();
   int indexYear = 0;
   int indexMonth = 0;
   int indexDay = 0;
   int index = 0;

   for (int i = 0; i <= prevYear - 1; i++) {
      if (isLeapYear(i) == true) {
         indexYear = indexYear + 366;
      } else {
         indexYear = indexYear + 365;
      }
   }
   if (prevMonth != JANUARY) {
      for (Month i = JANUARY; i <= prevMonth - 1; i++) {
         indexMonth = indexMonth + daysInMonth(i, prevYear);
      }
   }
   indexDay = prevDay;
   index = indexYear + indexMonth + indexDay;

   // Change the index.
   index = index + delta;

   // Match the index with the date.
   int currYear = 0;
   Month currMonth = JANUARY;
   int currDay = 0;
   int accuIndex = 0;

   for (int i = 0; i <= 3000; i++) {
      if (isLeapYear(currYear) == true) {
         if (accuIndex + 366 < index) {
            currYear = currYear + 1;
            accuIndex = accuIndex + 366;
         }
      } else {
         if (accuIndex + 365 < index) {
            currYear = currYear + 1;
            accuIndex = accuIndex + 365;
      }
      }
   }
   for (Month i = JANUARY; i <= DECEMBER; i = Month(i + 1)) {
      int residualIndex = index - accuIndex;
      if (daysInMonth(i, currYear) < residualIndex) {
         currMonth = Month(currMonth + 1);
         accuIndex = accuIndex + daysInMonth(i, currYear);
      } else {
         break;
      }
   }
   currDay = index - accuIndex;

   // Return the result.
   result = Date(currDay, currMonth, currYear);
   return result;
}

Date operator-(Date date, int delta)
{
   Date result;

   // Get the index of date.
   int prevYear = date.getYear();
   Month prevMonth = date.getMonth();
   int prevDay = date.getDay();
   int indexYear = 0;
   int indexMonth = 0;
   int indexDay = 0;
   int index = 0;

   for (int i = 0; i <= prevYear - 1; i++) {
      if (isLeapYear(i) == true) {
         indexYear = indexYear + 366;
      } else {
         indexYear = indexYear + 365;
      }
   }
   if (prevMonth != JANUARY) {
      for (Month i = JANUARY; i <= prevMonth - 1; i++) {
         indexMonth = indexMonth + daysInMonth(i, prevYear);
      }
   }
   indexDay = prevDay;
   index = indexYear + indexMonth + indexDay;

   // Change the index.
   index = index - delta;

   // Match the index with the date.
   int currYear = 0;
   Month currMonth = JANUARY;
   int currDay = 0;
   int accuIndex = 0;

   for (int i = 0; i <= 3000; i++) {
      if (isLeapYear(currYear) == true) {
         if (accuIndex + 366 < index) {
            currYear = currYear + 1;
            accuIndex = accuIndex + 366;
         }
      } else {
         if (accuIndex + 365 < index) {
            currYear = currYear + 1;
            accuIndex = accuIndex + 365;
      }
      }
   }
   for (Month i = JANUARY; i <= DECEMBER; i = Month(i + 1)) {
      int residualIndex = index - accuIndex;
      if (daysInMonth(i, currYear) < residualIndex) {
         currMonth = Month(currMonth + 1);
         accuIndex = accuIndex + daysInMonth(i, currYear);
      } else {
         break;
      }
   }
   currDay = index - accuIndex;

   // Return the result.
   result = Date(currDay, currMonth, currYear);
   return result;
}

int operator-(Date d1, Date d2)
{
   int difference;

   // Get the index of date d1.
   int d1Year = d1.getYear();
   Month d1Month = d1.getMonth();
   int d1Day = d1.getDay();
   int d1IndexYear = 0;
   int d1IndexMonth = 0;
   int d1IndexDay = 0;
   int d1Index = 0;

   for (int i = 0; i <= d1Year - 1; i++) {
      if (isLeapYear(i) == true) {
         d1IndexYear = d1IndexYear + 366;
      } else {
         d1IndexYear = d1IndexYear + 365;
      }
   }
   if (d1Month != JANUARY) {
      for (Month i = JANUARY; i <= d1Month - 1; i++) {
         d1IndexMonth = d1IndexMonth + daysInMonth(i, d1Year);
      }
   }
   d1IndexDay = d1Day;
   d1Index = d1IndexYear + d1IndexMonth + d1IndexDay;


   // Get the index of date d2.
   int d2Year = d2.getYear();
   Month d2Month = d2.getMonth();
   int d2Day = d2.getDay();
   int d2IndexYear = 0;
   int d2IndexMonth = 0;
   int d2IndexDay = 0;
   int d2Index = 0;

   for (int i = 0; i <= d2Year - 1; i++) {
      if (isLeapYear(i) == true) {
         d2IndexYear = d2IndexYear + 366;
      } else {
         d2IndexYear = d2IndexYear + 365;
      }
   }
   if (d2Month != JANUARY) {
      for (Month i = JANUARY; i <= d2Month - 1; i++) {
         d2IndexMonth = d2IndexMonth + daysInMonth(i, d2Year);
      }
   }
   d2IndexDay = d2Day;
   d2Index = d2IndexYear + d2IndexMonth + d2IndexDay;

   // Compute the difference.
   difference = d1Index - d2Index;

   // Reture the result.
   return difference;
}

Date &operator+=(Date &date, int delta)
{
   Date result;
   result = operator+(date, delta);
   return result;
}

Date &operator-=(Date &date, int delta)
{
   Date result;
   result = operator-(date, delta);
   return result;
}

Date operator++(Date &date)
{
   date = operator+(date, 1);
   return date;
}

Date operator++(Date &date, int)
{
   Date old = date;
   date = operator+(date, 1);
   return old;
}

Date operator--(Date &date)
{
   date = operator-(date, 1);
   return date;
}

Date operator--(Date &date, int)
{
   Date old = date;
   date = operator-(date, 1);
   return old;
}

bool operator==(Date d1, Date d2)
{
   return (d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear());
}

bool operator!=(Date d1, Date d2)
{
   return (!(d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear()));
}

bool operator<(Date d1, Date d2)
{
   bool result = false;
   if (d1.getYear() < d2.getYear()) {
      result = true;
   }
   else if (d1.getYear() == d2.getYear()) {
      if (d1.getMonth() < d2.getMonth()) {
         result = true;
      }
      else if (d1.getMonth() == d2.getMonth()) {
         if (d1.getDay() < d2.getDay()) {
            result = true;
         }
      }
   }
   return result;
}

bool operator<=(Date d1, Date d2)
{
   bool result = false;
   if (d1.getYear() < d2.getYear()) {
      result = true;
   }
   else if (d1.getYear() == d2.getYear()) {
      if (d1.getMonth() < d2.getMonth()) {
         result = true;
      }
      else if (d1.getMonth() == d2.getMonth()) {
         if (d1.getDay() <= d2.getDay()) {
            result = true;
         }
      }
   }
   return result;
}

bool operator>(Date d1, Date d2)
{
   bool result = false;
   if (d1.getYear() > d2.getYear()) {
      result = true;
   }
   else if (d1.getYear() == d2.getYear()) {
      if (d1.getMonth() > d2.getMonth()) {
         result = true;
      }
      else if (d1.getMonth() == d2.getMonth()) {
         if (d1.getDay() > d2.getDay()) {
            result = true;
         }
      }
   }
   return result;
}

bool operator>=(Date d1, Date d2)
{
   bool result = false;
   if (d1.getYear() > d2.getYear()) {
      result = true;
   }
   else if (d1.getYear() == d2.getYear()) {
      if (d1.getMonth() > d2.getMonth()) {
         result = true;
      }
      else if (d1.getMonth() == d2.getMonth()) {
         if (d1.getDay() >= d2.getDay()) {
            result = true;
         }
      }
   }
   return result;
}

std::ostream &operator<<(std::ostream &os, Date date){
   string stringDate = date.toString();
   return os << stringDate;
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year)
{
   int result = 0;
   if (month == JANUARY) {
      result = 31; 
   }
   if (month == FEBRUARY) {
      result = 28; 
   }
   if (month == MARCH) {
      result = 31; 
   }
   if (month == APRIL) {
      result = 30; 
   }
   if (month == MAY) {
      result = 31; 
   }
   if (month == JUNE) {
      result = 30; 
   }
   if (month == JULY) {
      result = 31; 
   }
   if (month == AUGUST) {
      result = 31; 
   }
   if (month == SEPTEMBER) {
      result = 30; 
   }
   if (month == OCTOBER) {
      result = 31; 
   }
   if (month == NOVEMBER) {
      result = 30; 
   }
   if (month == DECEMBER) {
      result = 31; 
   }
   if (month == FEBRUARY && isLeapYear(year) == true) {
      result = 29;
   }
   return result;
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year)
{
   bool result = false;
   if (year % 100 == 0) {
      if (year % 400 == 0) {
         result = true;
      }
   } else {
      if (year % 4 == 0) {
         result = true;
      }
   }
   return result;
}


/* DO NOT modify this main() part */
int main()
{
   int id = 3;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
   }
}
