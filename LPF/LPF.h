#ifndef LPF_H
#define LPF_H

#include <string>
#include "LPF.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Todo 課題4 LPFを適用する関数を作成してください．
/*----------------------------------------------------------------------*/
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

    // ヘッダ行の読み込み
    if (std::getline(inFile, line)) {
        header.push_back(line);
        outFile << line << std::endl; // 出力ファイルにヘッダを書き込み
    }

    // dataというvectorに入力用csvファイルのデータを格納
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

    // エラー確認
    if (data.empty() || columnIndex < 1 || columnIndex >= data[0].size()) {
        std::cerr << "Invalid column index or empty data." << std::endl;
        return;
    }

    // dataにLPFを適用
    double previousValue = std::stod(data[0][columnIndex]);
    for (size_t i = 0; i < data.size(); ++i) {
        double currentValue = std::stod(data[i][columnIndex]);
        double filteredValue = alpha * currentValue + (1 - alpha) * previousValue;
        previousValue = filteredValue;
        data[i][columnIndex] = std::to_string(filteredValue);
    }

    // 出力用csvファイルにLPF後のdataを書き込み
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) outFile << ",";
            outFile << row[i];
        }
        outFile << std::endl;
    }
}
/*----------------------------------------------------------------------*/
#endif
