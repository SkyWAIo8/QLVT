#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;
typedef unsigned int uint;
//------Ngay Thang
struct ngayThang
{
	uint ngay;
	uint thang;
	uint nam;
};
typedef struct ngayThang NGAY_THANG;
//------Danh Sach Vat Tu
struct vatTu {
	//Data
	int maVT;
	string tenVT;
	string donViTinh;
	float soLuongTon;
	bool kt; //true: VT da lap hoa don	- false: VT chua lap hoa don
			 //Pointer
	vatTu *pLeft;
	vatTu *pRight;
};
typedef struct vatTu* tree;
struct dsVatTu {
	tree TREE = NULL;
	int sl = 0;
};
typedef struct dsVatTu DS_VAT_TU;

//------Danh Sach Chi Tiet Hoa Don
struct chiTietHoaDon {
	//Data
	int maVatTu;
	float soLuong;
	int donGia;
	float VAT;
	//Pointer
	chiTietHoaDon *pNext;
};
typedef struct chiTietHoaDon CHI_TIET_HOA_DON;
struct dsChiTietHD {
	CHI_TIET_HOA_DON *pHead = NULL;
	int sl = 0;
};
typedef struct dsChiTietHD DS_CHI_TIET_HD;

//------Danh Sach Hoa Don
struct hoaDon {
	//Data
	string soHD;
	NGAY_THANG ngayLapHD;
	char loaiHD;
	//*dscthd
	DS_CHI_TIET_HD dscthd;
	//Pointer
	hoaDon *pNext;
};
typedef struct hoaDon HOA_DON;
struct dsHoaDon {
	HOA_DON *pHead = NULL;
	int sl = 0;
};
typedef struct dsHoaDon DS_HOA_DON;

//------Danh Sach Nhan Vien
struct nhanVien {
	string maNV;
	string hoNV;
	string tenNV;
	string phaiNV;
	//bool kt; //true: NV da lap hoa don	- false: NV chua lap hoa don
	//*dshd
	DS_HOA_DON dshd;
};
typedef struct nhanVien NHAN_VIEN;
struct dsNhanVien {
	NHAN_VIEN *ds[500];
	int sl = 0;
};
typedef struct dsNhanVien DS_NHAN_VIEN;