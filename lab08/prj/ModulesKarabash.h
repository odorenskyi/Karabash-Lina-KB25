#ifndef MODULESKARABASH_H
#define MODULESKARABASH_H

#include <string>

double s_calculation(double x, double y, double z);
void bonus_znuzhka (double summa);
double faren_v_cels (double faren);
int processNumber(int N);
int vowelsCountInFile(std::string outputFileName, std::string ukrWord);
bool findWordInPoem(std::string outputFileName, std::string ukrWord);
int consonantsCountInFile(std::string inputFileName, std::string ukrWord);
bool timestampInFile(std::string inputFileName);
double sCalculationResInFile(const std::string& outputFileName, float x, float y, float z);
bool decimalToBinary(std::string outputFileName, unsigned int number);
bool authorInfo(std::string outputFileName);

#endif
