//@author A0121007A
/*
Some utility methods useful for the testing
*/
#pragma once
class TestUtility {
public:
	
	static void checkVectorEquality(vector<string> expected, vector<string> actual);
	static void clearVector(vector<string> v1);
	static void clearVectors(vector<string> v1, vector<string> v2);
};

