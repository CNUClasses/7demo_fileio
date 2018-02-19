#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <ctype.h>

#include "fileio.h"

using namespace std;

//if myString does not contain a string rep of number returns o
//if int not large enough has undefined behaviour, very fragile
int stringToInt(string &myString) {
	//get rid of spaces
	while(myString.size() && isspace(myString.front())) 
		myString.erase(myString.begin());
	//if empty say so
	if (myString[0] == '\0')
		return UNINITIALIZED;
	
	return atoi(myString.c_str());
}

int readFileIntoVector(std::vector<Data> &allData, const std::string &filename) {

	ifstream myfile;
	myfile.open(filename.c_str());
	if (!myfile.is_open())
		return COULD_NOT_OPEN_FILE;
	
	std::string line;
	std::string token;
	Data myData;
	stringstream ss;

	while (!myfile.eof()) {
		getline(myfile, line); //get a line from the file 
		ss.str(line);

		//get rid of the old values
		myData.clear();

		//get the name
		getline(ss, myData.name, CHAR_TO_SEARCH_FOR);

		//get age (if empty string then missing value)
		getline(ss, token, CHAR_TO_SEARCH_FOR);
		myData.age = stringToInt(token);

		//get tshirtsize
		getline(ss, myData.tshirt, CHAR_TO_SEARCH_FOR);
		
		//finally add to array
		allData.push_back(myData);

		//clear stream so it will work for next read
		ss.clear();
	}
	return SUCCESS;
}

int writeDataToFile(std::vector<Data> &allData,const std::string filename) {
	ofstream myfile;
	myfile.open(filename.c_str());
	if (!myfile.is_open())
		return COULD_NOT_OPEN_FILE;

	string mydata;
	for (int var = 0; var < allData.size(); ++var) {
		mydata = allData[var].name + "," + to_string(allData[var].age) + "," + allData[var].tshirt;
		myfile<<mydata<<std::endl;
	}

	if (myfile.is_open())
		myfile.close();

	return SUCCESS;
}

