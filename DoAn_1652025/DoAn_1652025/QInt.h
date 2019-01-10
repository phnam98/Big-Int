#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#define MAX 128
#pragma warning(disable : 4996)

struct QInt
{
	char sign;//dấu, nếu số âm thì sign=-1
	char dodai;//chiều dài
	char arrbit[MAX];//lưu các chữ số
};

void khoiTaoQInt(QInt &n);				 //Khởi tạo số QInt
void chuoiThanhQInt(char *str, QInt &n); //Chuyển một chuỗi kí tự thành số nguyên lớn
void taoQInt(QInt &n);				     //Hàm đọc số nguyên lớn từ bàn phím
void inQInt(QInt &n);					 //Hàm in số nguyên lớn ra màn hình
int soSanhKo(QInt &a, QInt &b);			 //Hàm so sánh 2 số nguyên lớn không xét dấu
int soSanh(QInt &a, QInt &b);			 //Hàm so sánh 2 số nguyên lớn, nếu a>b trả về 1, a=b trả về 0, a<b trả về -1
void congKo(QInt &s, QInt &a, QInt &b);  //Hàm cộng không xét dấu
void cong(QInt &s, QInt &a, QInt &b);    //Hàm cộng có xét dấu
void truKo(QInt &s, QInt &a, QInt &b);   //Hàm trừ không xét dấu
void tru(QInt &s, QInt &a, QInt &b);     //Hàm trừ có xét dấu
void nhan(QInt &r, QInt &a, QInt &b);    //Hàm nhân hai số nguyên lớn
void chia(QInt &r, QInt a, QInt b);      //Hàm phép chia số nguyên lớn
void ShowBit(bool* a);					 //Hàm hiển thị bit
bool* decToBin(QInt a);					 //Hàm chuyển QInt sang dạng nhị phân
QInt Div2(QInt a, int &du);				 //Hàm chia 2 hỗ trợ cho hàm chuyển
void binToHex(bool* a, char h[]);		 //Hàm chuyển bin sang dạng thập lục phân
_int64 binToDec(bool* a);				 //Hàm chuyển bin sang dạng thâp phân
bool* and(bool* x, bool* y);			 //Hàm AND
bool* or (bool *x, bool*y);				 //Hàm OR
bool* xor(bool *x, bool *y);			 //Hàm XOR
bool* not(bool* x);						 //Hàm NOT
bool* shiftleft(bool* x, int j);		 //Hàm dịch trái
bool* shiftright(bool* x, int j);		 //Hàm dịch phải
void HexToBin(char a[], char b[], int length);   //Nhị phân sang thập lục phân
void changeHexaBit(char a, char b[], int vitri); //Hàm hỗ trợ hàm đổi

#endif
