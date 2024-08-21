#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>  // _kbhit()を使うため．Windows向け

/*----------------------------------------------------------------------*/
//Todo 課題3 "crlserial2024.hpp"というヘッダファイルをインクルードして使ってください．
#include "crlserial2024.hpp"
/*----------------------------------------------------------------------*/

#define PORT TEXT("COM8") // ポートを設定
#define BAUD 115200 // ボーレートを設定
#define DATA_NUM 8 // データを読み込む個数（カンマ区切りの列数）を設定

int main() {
    /*----------------------------------------------------------------------*/
    //Todo 課題3 コントローラーの入力をシリアルポートから受け取り，それをcsvに書き込んでください．

    /*csv保存先*/
    std::string outputFile = "C:/myClion/BootCamp2024_cpp/csv_Output/csv_Output.csv";
    /*ヘッダー行*/
    std::string header = "入力1,入力2,入力3";

    std::string dat[DATA_NUM]; //読み込みデータ格納用


    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return -1;
    }

    // シリアルポートの初期化
    crlSerial sc(PORT, BAUD);

    //
    // !!! ボーレートの設定をmbed側でやっておく必要あり !!!
    //  以下をmbedプログラムに追加
    //
    //  pc.baud(115200);
    //

    if (sc.check() == true) {
//        printf("#debug: open serial port [%s]: succeeded!\n", PORT);
    } else {
        printf("#error: open serial failed!\n");
        printf("#error: port: %s\n", PORT);
        return -2;
    }

    /*シリアルポートから受け取ったデータをvectorに格納*/
    std::vector<std::vector<std::string>> data;
    bool stop_flag;
    while (!stop_flag) {
        if (sc.check() == true) {
            sc.read_sci(DATA_NUM, dat);

            /*シリアルポートから受け取ったデータの表示*/
            for (int i=0; i < DATA_NUM; i++){
                std::cout << dat[i];
                if(i != DATA_NUM - 1){
                    printf(",");
                } else {
                    printf("\n");
                }
            }

            std::vector<std::string> row( std::begin(dat), std::end(dat) );
            data.push_back(row);
        }
        //キー押下でループ終了
        if (_kbhit() == 1) {
            std::cout << "Cancel programs" << std::endl;
            stop_flag = true;
        }
    }

    outFile << header << std::endl; /*ヘッダー行の追加*/
    // dataをcsvファイルに出力
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) outFile << ",";
            outFile << row[i];
        }
        outFile << std::endl;
    }
    return 0;
    /*----------------------------------------------------------------------*/
}
