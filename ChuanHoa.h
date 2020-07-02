#pragma once
#include "CTDL.h"
#include <conio.h>
#include <time.h>
#include "GiaoDien.h"
void chuanHoaChu(string &a) {
	//Xu ly khoang trang dau, cuoi
	while (a[0] == ' ') {
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1] == ' ') {
		a.erase(a.begin() + a.length() - 1);
	}
	//Xu ly khoang trang giua
	for (int i = 0; i<a.length(); i++) {
		if (a[i] == ' ' && a[i + 1] == ' ') {
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	//Xu ly Ki Tu
	if (a[0] >= 97 && a[0] <= 122) {
		a[0] -= 32;
	}
	for (int i = 1; i<a.length(); i++) {
		if (a[i] == ' ') {
			i++;
			if (a[i] >= 97 && a[i] <= 122) {
				a[i] -= 32;
			}
		}
		else {
			if (a[i] >= 65 && a[i] <= 90) {
				a[i] += 32;
			}
		}
	}
}
int ktChuoi(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') return 1;
	}
	return 0;
}
//------Xu Ly Vat Tu
vatTu* khoiTaoNodeVatTu() {
	vatTu *p = new vatTu;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
void them1VT(tree &t, vatTu *p) {
	if (t == NULL) {
		t = p;
	}
	else {
		if (p->maVT > t->maVT) {
			them1VT(t->pRight, p);
		}
		else if (p->maVT < t->maVT) {
			them1VT(t->pLeft, p);
		}
	}
}
//------Hoa Don
HOA_DON *khoiTaoNodeHD() {
	HOA_DON *p = new HOA_DON;
	p->pNext = NULL;
	return p;
}
void them1HD(HOA_DON *&pHead, HOA_DON *p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		for (HOA_DON *k = pHead; k != NULL; k = k->pNext) {
			if (k->pNext == NULL) {
				k->pNext = p;
				break;
			}
		}
	}
}
//------Chi Tiet Hoa Don
CHI_TIET_HOA_DON *khoiTaoNodeCTHD() {
	CHI_TIET_HOA_DON *p = new CHI_TIET_HOA_DON;
	p->pNext = NULL;
	return p;
}
void them1CTHD(CHI_TIET_HOA_DON *&pHead, CHI_TIET_HOA_DON *p) {
	if (pHead == NULL) {
		pHead = p;
	}
	else {
		for (CHI_TIET_HOA_DON *k = pHead; k != NULL; k = k->pNext) {
			if (k->pNext == NULL) {
				k->pNext = p;
				break;
			}
		}
	}
}
//------Ngay Thang Nam
void layNgayThangHT(NGAY_THANG &d)
{
	tm today;
	time_t ltime;
	time(&ltime);
	localtime_s(&today, &ltime);
	d.ngay = today.tm_mday;
	d.thang = today.tm_mon + 1;
	d.nam = today.tm_year + 1900;
}
//NGAY_THANG nhapNgayThang(string a) {
//	NGAY_THANG ngayThang;
//	
//	return ngayThang;
//}
bool namNhuan(int year){
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
int ngayHopLe(NGAY_THANG nt){
	if (nt.nam > 2050 || nt.nam < 2000)
		return 2; //Sai nam
	if (nt.thang < 1 || nt.thang > 12)
		return 1; //Sai thang
	if (nt.ngay < 1 || nt.ngay > 31)
		return 0; //Sai ngay
	//Thang 2 nam nhuan
	if (nt.thang == 2){
		if (namNhuan(nt.nam)){
			if (nt.ngay > 29)
				return 0;
		}
		else{
			if (nt.ngay > 28){
				return 0;
			}
		}
	}
	if ((nt.thang == 4 || nt.thang == 6 || nt.thang == 9 || nt.thang == 11) && (nt.ngay > 30)){
		return 0;
	}
	return 3; //Dung format
}
void xuatNgayThang(NGAY_THANG nt)
{
	cout << nt.ngay << "/" << nt.thang << "/" << nt.nam << endl;
}
// Tinh Ngay
int tinhNgay(NGAY_THANG dt)
{
	if (dt.thang < 3) {
		dt.nam--;
		dt.thang += 12;
	}
	return 365 * dt.nam + dt.nam / 4 - dt.nam / 10 + dt.nam / 400 + (153 * dt.thang - 457) / 5 + dt.ngay - 306;
}