#include "LPF.h"
#include <string>


int main() {
    /*----------------------------------------------------------------------*/
    // Todo 課題4　csvファイルにLPFを適用する関数を"LPF.h"に記述し，ここで呼び出してください．
    std::string inputFile = "C:/myClion/BootCamp2024_cpp/LPF/LPF_before.csv";
    std::string outputFile = "C:/myClion/BootCamp_2024_cpp/LPF/LPF_after.csv";
    int columnIndex = 1; // LPFを適用する列
    double alpha = 0.1;  // LPF smoothing factor

    // LPFの関数
    applyLPF(inputFile, outputFile, columnIndex, alpha);

    return 0;
    /*----------------------------------------------------------------------*/
}