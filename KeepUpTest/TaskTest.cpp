#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//@author a0100789b
namespace KeepUpTest
{
	TEST_CLASS(TaskTest) {
	public:
		
		TEST_METHOD(timeDateValidity) {

			//2pm-3pm on 1/1/2014-29/2/2015
			vector<string> uInputParsed(Task::ATTR::SIZE);
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "00";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "1";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//21:15-18:29
			uInputParsed.at(Task::ATTR::STARTHOUR) = "21";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "15";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "18";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "29";
			uInputParsed.at(Task::ATTR::STARTDAY) = "2";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//2pm-3pm on 3/5/2014 - 29/8/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = "12";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "00";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "1";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "8";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//2.20-3.30pm on 1/1/2014 - 1/1/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "30";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "1";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "1";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//by 3pm 
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//4pm-10pm om 1/1/2014 - 29/2/2020
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "00";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "22";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "1";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2020";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//2.20pm - 2.30pm 29/2/2016 - 29/2/2020
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "14";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "30";
			uInputParsed.at(Task::ATTR::STARTDAY) = "29";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2016";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2020";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//2.30pm - 2.20pm 29/2/2016 - 29/2/2020
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "30";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "14";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "20";
			uInputParsed.at(Task::ATTR::STARTDAY) = "29";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2016";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsTrue(Task::isValidTime(uInputParsed));
			
			//2.20pm - 2.30pm 29/2/2016 - 29/2/2012
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "14";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "30";
			uInputParsed.at(Task::ATTR::STARTDAY) = "29";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2016";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2012";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//on 31/4/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "31";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//at 4.70pm
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "70";
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//on 14/4/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//14.50 - 15.00 on 4/4/2014 
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "50";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "4";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//14.50-15.00 on 0/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = "14";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "50";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "0";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "5";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//21:15-18:29 on 1/5/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = "21";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "15";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "18";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "29";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "5";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2015";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//16.50-25.20 on 1/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "50";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "25";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "20";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "5";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//16.50-16.62 on 32/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "50";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "16";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "62";
			uInputParsed.at(Task::ATTR::STARTDAY) = "32";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "5";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDYEAR) = Task::STRING_NOT_EXIST;
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 29/2/2016
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2016";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//by 22/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "22";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//by 29/2/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 5/13/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "5";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "13";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 0/4/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "0";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2016";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 32/4/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "32";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 3.20pm 30/4/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "20";
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "30";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//by 3.20pm 31/4/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "20";
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "31";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 3.63 2/4/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "63";
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "2";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//by 26 30/0/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = "26";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMONTH) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTYEAR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDDAY) = "30";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "0";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//30/4/2014-1/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "30";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//2/4/2014-10/6/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "2";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "10";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "6";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//30/4/2014-29/2/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "30";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//30/4/2014-29/2/2016
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "30";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "29";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "2";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2016";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//30/4/2014-1/5/2013
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "30";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2013";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//2/4/2014-3/5/2013
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "2";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "3";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2013";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//3/4/2014-5/3/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "3";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "5";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "3";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//0/4/2014-1/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "0";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//3/4/2014-1/4/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "3";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//3/12-3/13
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "3";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "12";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "3";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "13";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//2/4/2014-10/5/2013
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "2";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "10";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2013";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//2/6/2014-10/5/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "2";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "6";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "10";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//3/4/2014-10/5/2013
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "3";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "10";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2013";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//3/4/2014 - 5/9/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "3";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "9";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//0/4/2014-1/5/2014
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "0";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//31/4/2014 - 30/5/2015
			uInputParsed.at(Task::ATTR::STARTHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDHOUR) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::ENDMINUTE) = Task::STRING_NOT_EXIST;
			uInputParsed.at(Task::ATTR::STARTDAY) = "31";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "30";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "5";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2015";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//4.20 - 5.30
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "30";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));


			//4.20 - 5.10
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "10";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//5.20 - 5.20
			uInputParsed.at(Task::ATTR::STARTHOUR) = "17";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "20";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//4.20 - 5.65
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "65";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//4.40 - 5.30
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "30";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//5.20 - 5.00
			uInputParsed.at(Task::ATTR::STARTHOUR) = "17";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//4.20 - 3.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "16";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//0.20 - 25.30
			uInputParsed.at(Task::ATTR::STARTHOUR) = "0";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "20";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "25";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "30";
			uInputParsed.at(Task::ATTR::STARTDAY) = "14";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "4";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//1/2/2013 - 14/4/2014 3.40-5.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2013";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//29/2/2016 - 1/4/2016 3.40-5.00
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "00";
			uInputParsed.at(Task::ATTR::STARTDAY) = "29";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2016";
			uInputParsed.at(Task::ATTR::ENDDAY) = "1";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2016";
			Assert::IsTrue(Task::isValidTime(uInputParsed));

			//1/2/2013 - 14/4/2014 3.40-2.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "14";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2013";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//1/2/2013 - 14/4/2014 3.40-3.10
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "15";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "10";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2013";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//1/2/2015 - 14/4/2014 3.40-5.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2015";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//16/3/2014 - 14/4/2014 3.40-5.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "16";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "3";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//1/2/2014 - 14/13/2014 3.40-5.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "15";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2013";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "13";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));

			//1/2/2014 - 14/4/2014 6.40-5.50
			uInputParsed.at(Task::ATTR::STARTHOUR) = "18";
			uInputParsed.at(Task::ATTR::STARTMINUTE) = "40";
			uInputParsed.at(Task::ATTR::ENDHOUR) = "17";
			uInputParsed.at(Task::ATTR::ENDMINUTE) = "50";
			uInputParsed.at(Task::ATTR::STARTDAY) = "1";
			uInputParsed.at(Task::ATTR::STARTMONTH) = "2";
			uInputParsed.at(Task::ATTR::STARTYEAR) = "2014";
			uInputParsed.at(Task::ATTR::ENDDAY) = "14";
			uInputParsed.at(Task::ATTR::ENDMONTH) = "4";
			uInputParsed.at(Task::ATTR::ENDYEAR) = "2014";
			Assert::IsFalse(Task::isValidTime(uInputParsed));		

		}

	};
}