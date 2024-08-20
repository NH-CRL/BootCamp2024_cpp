#include "LPF.h"
#include <string>


int main() {
    std::string inputFile = "C:/myClion/crlSerial_2024/LPF/LPF_before.csv";
    std::string outputFile = "C:/myClion/crlSerial_2024/LPF/LPF_after.csv";
    int columnIndex = 1; // LPFを適用する列
    double alpha = 0.1;  // LPF smoothing factor

    // LPFの関数
    applyLPF(inputFile, outputFile, columnIndex, alpha);



    return 0;
}