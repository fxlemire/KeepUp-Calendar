#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeepUpTest
{
	TEST_CLASS(UtilityTest) {
	public:
		//@author A0121007A
		TEST_METHOD(isContained) {
			string s = "This is an image.";
			string key = " is ";
			Assert::IsTrue(Utility::isContained(key, s));

			s = "This was a poster.";
			key = " is ";
			Assert::IsFalse(Utility::isContained(key, s));
		}

	};
}