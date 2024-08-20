#ifndef LPF_H
#define LPF_H

#include <string>

void applyLPF(const std::string& inputFile, const std::string& outputFile, int columnIndex, double alpha);

#endif
