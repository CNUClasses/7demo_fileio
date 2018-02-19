/*
 * utilities.h
 *
 *  Created on: Sep 17, 2013
 *      Author: lynn
 */

#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <vector>
#include "../../7demo_main/includes/constants.h"

const char CHAR_TO_SEARCH_FOR = ',';

/*
 * populates vector from a CSV file
 * returns: COULD_NOT_OPEN_FILE
 * 			SUCCESS
 */
int readFileIntoVector(std::vector<Data> &allData, const std::string &filename);

/*
 * write vector to a CSV file
 * returns: COULD_NOT_OPEN_FILE
 * 			SUCCESS
 */
int writeDataToFile(std::vector<Data> &allData,const std::string filename);

#endif /* FILEIO_H_ */
