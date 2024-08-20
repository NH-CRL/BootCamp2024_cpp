/*!
 * @file    MyConfig.h
 * @brief   グローバル変数を記述するヘッダ
 * @author  ALL CRL MEMBERS of 2021
 * @date    2021/10/28
 */

#ifndef CRLSERIAL_HPP_MYCONFIG_H
#define CRLSERIAL_HPP_MYCONFIG_H


//!メインループを終了するフラグ
bool stop_flag = false;

//!保存するデータの構造体
struct SaveData {
    double agent_x = 0.0;
    double agent_y = 0.0;
    double CurrentTime = 0.0;
};

#endif
