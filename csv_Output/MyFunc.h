#define PORT TEXT("COM8")   //ポート指定
#define BAUD 115200         //ボーレート指定
#define DATA_NUM 3          //データwp読み込む個数の指定

#include <fstream>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "CRLSerial.hpp"
#include "crljoystick.hpp"

/*----クラスのインスタンス化----*/
//crlSerial sc(PORT, BAUD);//crlSerialクラスのインスタンス化
/*--------------------------*/
/*!
 * @brief	getchを行う関数
 * @return	読み込んだ文字
 * */
int getch() {
#ifdef _WINDOWS
    return _getch();
#elif defined(__APPLE__) || defined(__linux__)
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

/*!
 * @brief	_kbhitを行う関数
 * @retval	true	キー押下
 * @retval	false	何もなし
 * */
int kbhit() {
#ifdef _WINDOWS
    return _kbhit();
#elif defined(__APPLE__) || defined(__linux__)
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
#endif
}


/*!
 * @brief	時間を取得する関数
 * @return	現在の時間[sec]
 * */
double GetTime() {
    /* 初回起動時のみ初期時間を記録する */
    static bool first_flag = true;  //初回起動フラグ
    static std::chrono::system_clock::time_point start, now;
    if (first_flag) {
        start = std::chrono::system_clock::now();
        first_flag = false;
    }
    now = std::chrono::system_clock::now(); //現在の時間を取得

    return static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(now - start).count() * 0.001 *
                               0.001 * 0.001);  //経過時間を計算
}

/*!
 * @brief	CSVの書き込みを行う関数
 * @param[in] sd	保存用データの構造体（ポインタ）
 * */
void csvWrite(SaveData *sd, std::ofstream &ofs) {
    //  CSVの書き込みを行うスレッド
    //  書き込むデータは，時間，エージェントのx軸の位置，エージェントのy軸の位置
    //  スレッドの周期は0.01[sec]に設定
    //  終了フラグが立ったら，スレッドを終了
    //ファイルにMyConfigの値を書き込み
    ofs << sd->CurrentTime << "," << sd->agent_x << "," << sd->agent_y << "," << std::endl;
}

/*!
 * @brief	ジョイスティックの値を取得する関数
 * @return	ジョイスティックの値（ポインタ）
 * */

double *GetJoyStick(double* data) {
    //TODO 課題1
    //  ジョイスティックをの値を取得してください．
    if (sc.check() == true) {
        sc.read_sci(DATA_NUM, data);
        //printf("#debug: dat[0] %f, dat[1] %f, dat[2] %f\n", data[0], data[1], data[2]);
    }

    return nullptr;
}