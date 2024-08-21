// csv入力
#include <iostream>
#include <fstream>
#include <string>

int main() {
    /*----------------------------------------------------------------------*/
    //Todo 課題2 csvファイルを読み込んで，ターミナルに表示してください．
    // 読み込むcsvファイルは"LPF_before.csv"とします．
    // G:\共有ドライブ\Research\スタートアップ・ブートキャンプ\配布\基礎課題関係
    // にあるので，ダウンロードして使ってください．
    std::string inputFile = "C:/myClion/BootCamp2024_cpp/LPF/LPF_before.csv";/*読み込むcsvファイル名*/
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
    return 0;
    /*----------------------------------------------------------------------*/
}