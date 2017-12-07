#include "stdafx.h"
#include "TestUtility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//@author A0121007A
void TestUtility::checkVectorEquality(vector<string> expected, vector<string> actual) {
	for (int i = 0; i < expected.size(); i++) {
		Assert::AreEqual(expected[i], actual[i]);
	}
}

void TestUtility::clearVector(vector<string> v1) {
	v1.clear();
	v1.resize(Task::ATTR::SIZE);
}

void TestUtility::clearVectors(vector<string> v1, vector<string> v2) {
	v1.clear();
	v2.clear();
	v1.resize(Task::ATTR::SIZE);
	v2.resize(Task::ATTR::SIZE);
}
