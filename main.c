/*
 * File:   main.c
 * Author: Takumi
 *
 * Created on 2018/12/22, 18:24
 */


#include <xc.h>

#define _XTAL_FREQ  8000000  // delay用(クロック8MHzで動作時)

// コンフィギュレーション1の設定
#pragma config FOSC = INTOSC  // 内部クロックを使用
#pragma config WDTE = OFF // ウォッチドッグタイマ無し
#pragma config PWRTE = ON  // 電源ONから64ms後にプログラム開始
#pragma config MCLRE = OFF  // 外部リセット信号は使用せずにデジタル入力(RA5ピン)
#pragma config CP = OFF  // プログラムメモリを保護しない
#pragma config CPD = OFF  // データメモリを保護しない
#pragma config BOREN = ON  // 電源電圧降下常時監視機能ON
//#pragma config CLKOUTEM = OFF  // CLKOUTピンをRA6ピンで使用
#pragma config IESO = OFF  // 外部・内部クロックの切り替えでの起動なし
#pragma config FCMEN = OFF  // 外部クロック監視しない

// コンフィギュレーション2の設定
#pragma config WRT = OFF  // Flashメモリを保護しない
#pragma config PLLEN = OFF  // 動作クロックを32MHzでは動作させない
#pragma config STVREN = ON  // スタックがオーバフローあアンダーフローしたらリセットする
#pragma config BORV = HI  // 電源電圧降下常時監視電圧(2.5V)設定
#pragma config LVP = OFF  // 低電圧プログラミング機能使用しない

// 指定した時間だけウェイトする(10ms単位)
void Wait(unsigned int num)
{
    int i;
    
    for (i = 0; i < num; i++) {
        __delay_ms(10);
    }
}

void main(void) {
    OSCCON = 0b01110010;  // 内部クロックは8MHz
    ANSELA = 0b00000000;  // AN0-AN4は使用しない、全てデジタルI/Oとする
    ANSELB = 0b00000000;  // AN5-AN11は使用しない、全てデジタルI/Oとする
    TRISA = 0b00000000;  // ピン(RA)は全て出力に割当てる(RA5は入力のみ)
    TRISB = 0b00000000;  // ピン(RB)は全て出力に割当てる
    PORTA = 0b00000000;  // RA出力ピンの初期化(LOW)
    PORTB = 0b00000000;  // RB出力ピンの初期化
    
    while (1) {
        RA2 = 1;
        Wait(100);
        RA2 = 0;
        Wait(100);
    }
    return;
}
