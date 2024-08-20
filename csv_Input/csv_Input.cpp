// csv入力
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFile = "C:/myClion/crlSerial_2024/LPF/LPF_before.csv";/*読み込むcsvファイル名*/
    std::ifstream inFile(inputFile);/*csvファイルからinFileという入力ファイルストリームを作成*/

    // csvファイルが開かれていないか確認
    if (!inFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return -1;
    }

    // csvの内容を表示
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
}