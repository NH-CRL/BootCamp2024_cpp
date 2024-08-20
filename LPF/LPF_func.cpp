#include "LPF.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// LPFを適用するための関数
void applyLPF(const std::string& inputFile, const std::string& outputFile, int columnIndex, double alpha) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> header;

    // Read header line
    if (std::getline(inFile, line)) {
        header.push_back(line);
        outFile << line << std::endl; // Write header to output file
    }

    // Read and process data
    std::vector<std::vector<std::string>> data;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string item;
        std::vector<std::string> row;
        while (std::getline(ss, item, ',')) {
            row.push_back(item);
        }
        data.push_back(row);
    }

    // Apply LPF
    if (data.empty() || columnIndex < 1 || columnIndex >= data[0].size()) {
        std::cerr << "Invalid column index or empty data." << std::endl;
        return;
    }

    double previousValue = std::stod(data[0][columnIndex]);

    for (size_t i = 0; i < data.size(); ++i) {
        double currentValue = std::stod(data[i][columnIndex]);
        double filteredValue = alpha * currentValue + (1 - alpha) * previousValue;
        previousValue = filteredValue;
        data[i][columnIndex] = std::to_string(filteredValue);
    }

    // Write processed data to output file
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) outFile << ",";
            outFile << row[i];
        }
        outFile << std::endl;
    }
}