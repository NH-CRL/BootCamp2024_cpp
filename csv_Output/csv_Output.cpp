#define PORT TEXT("COM7") // ポートを設定
#define BAUD 115200 // ボーレートを設定
#define DATA_NUM 2 // データを読み込む個数（カンマ区切りの列数）
#define End_Time 10

#include "crlserial.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//関数の前宣言
void callCsvWriter(SaveData &sd, std::ofstream &ofs, double samplingRate);

int main(){
    std::string outputFile = "C:/myClion/crlSerial_2024/csv_Output/csv_Output.csv";
    std::ofstream outFile(outputFile);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return -1;
    }


    std::cout << "#debug: crlSerial test @ VS2015" << std::endl;

    double dat[DATA_NUM]; //読み込みデータ格納用
    std::cout << "#debug: crlSerialCommunications" << std::endl;

    // シリアルポートの初期化
    crlSerial sc(PORT, BAUD);

    if (sc.check() == true) {
//        printf("#debug: open serial port [%s]: succeeded!\n", PORT);
    } else {
        printf("#error: open serial failed!\n");
        printf("#error: port: %s\n", PORT);
        return -1;
    }


    /*-----スレッドの開始-----*/
    //CSV書き込みスレッド
    std::thread csvThread(&callCsvWriter, std::ref(sd), std::ref(ofs), smp);
    std::thread udpThread(&udpConnection, std::ref(sd), std::ref(send_string), smp);
    /*---------------------*/

    /* 終了フラグが立つまでループ */
    while (!stop_flag) {
        //キー押下でループ終了
        if (kbhit() == 1) {
            std::cout << "Cancel programs" << std::endl;
            stop_flag = true;
        }
        sd.CurrentTime = GetTime(); //現在時刻の取得
        //0.01秒周期で呼び出される処理
        if (sd.CurrentTime >= CalculatedTime + smp) {
            //計算した時間を更新
            CalculatedTime = GetTime();
            //ジョイスティックの入力をJoyStickDataの中に格納
            JoystickData[0] = -js.get_axis(1);
            JoystickData[1] = js.get_axis(0);

            //エージェントの位置を計算する処理
            agc.CalcDynamics(JoystickData[0], JoystickData[1]);//x軸，y軸の値を渡してダイナミクスを計算
            sd.agent_x = agc.GetxPosition();
            sd.agent_y = agc.GetyPosition();
            apos_x = agc.GetxPosition();
            apos_y = agc.GetyPosition();
            //std::cout << "position x:" << agc.GetxPosition() << " position y:" << agc.GetyPosition() << std::endl;//デバッグ位置表示
            //for文で各ターゲットの座標ををAgc.Hitcheckに渡して距離を計算
            for (size_t i = 0; i < target_num; i++) {
                colision_flag[i] = agc.HitCheck(tpos_x[i], tpos_y[i]);
            }
            //ゴール判定
            if (agc.GoalCheck()) {
                std::cout << "Goal!!!" << std::endl;
            }
            //送信する文字列を作成
            send_string = con_cha(target_num, apos_x, apos_y, agc.GetGoalPosition(), tpos_x, tpos_y, colision_flag);
            std::cout << send_string << std::endl;
//            std::cout << js.get_axis(0) << "," << js.get_axis(1) << "," << js.get_axis(2) << "," << js.get_axis(3)
//                      << std::endl;
        }
    }
    csvThread.join();//CSVスレッドの終了待機
    udpThread.join();//UDPスレッドの終了待機
    return 0;
}

//一定周期でcsvWriterを呼び出すスレッド(stop_flagが立つと終了)
void callCsvWriter(SaveData &sd, std::ofstream &ofs, double samplingRate) {
    static double WroteTime = 0.0;
    while (!stop_flag) {
        sd.CurrentTime = GetTime();
        if (sd.CurrentTime >= WroteTime + samplingRate) {
            WroteTime = GetTime();
            csvWrite(&sd, ofs);//CSVに書き込む関数
        }
    }
}