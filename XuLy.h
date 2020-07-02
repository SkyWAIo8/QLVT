#pragma once
#include "DocGhiFile.h"
int cao = 22, x = 50, y = 15, z = 3;
//==========VAT TU==========
//------Them Vat Tu
//vatTu* khoiTaoNodeVatTu();
void themVatTu(DS_VAT_TU &dsVT);
//void them1VT(tree &t, vatTu *p);
int taoMaVT(tree t);
bool ktTrungMaVT(tree t, int ma);
//------Xuat Danh Sach Vat Tu
void chuyenCaySangMang(tree t, vatTu *ds[], int &nds);
void hoanVi2VT(vatTu *a, vatTu *b);
void sapXepDSVatTu(vatTu *ds[], int &nds);
void xuatDSVatTu(vatTu *ds[], int &nds);
void giaiPhongDSVatTu(vatTu *ds[], int &nds);
//------Xoa Vat Tu
void xoaVatTu(DS_VAT_TU &dsVT);
int ktMaVT(tree t, int ma);
void xoa1VT(tree &t, int ma);
void nodeTheMang(tree &t, vatTu *&x);
//------Sua Vat Tu
void suaVatTu(DS_VAT_TU &dsVT);
void sua1VT(tree t, int ma);

//==========NHAN VIEN==========
//------Them DS Nhan Vien
void themNhanVien(DS_NHAN_VIEN &dsNV);
string taoMaNV(DS_NHAN_VIEN dsNV);
int ktTrungMaNV(string a, DS_NHAN_VIEN dsNV);
//------Xuat DS Nhan Vien
void hoanVi2NV(nhanVien *a, nhanVien *b);
void sapXepDSNhanVien(DS_NHAN_VIEN &dsNV);
void xuatDSNhanVien(DS_NHAN_VIEN dsNV);
//------Xoa Nhan Vien
void xoaNhanVien(DS_NHAN_VIEN &sNV);
//int ktMaNV(string a, DS_NHAN_VIEN dsNV);
//------Sua Nhan Vien
void suaNhanVien(DS_NHAN_VIEN dsNV);
//==========LAP HOA DON==========
void lapHoaDon(DS_NHAN_VIEN &dsNV, DS_VAT_TU &dsVT);
//void them1HD(HOA_DON *&pHead, HOA_DON *p);
//HOA_DON *khoiTaoNodeHD();
nhanVien *ktMaNV(string a, DS_NHAN_VIEN dsNV);
bool ktTrungSoHD(HOA_DON *pHead, string ma);
string taoSoHD(DS_HOA_DON dsHD);
//------Chi Tiet Hoa Don
//void lapChiTietHD(DS_VAT_TU &dsVT, HOA_DON *hD)
//void them1CTHD(CHI_TIET_HOA_DON *&pHead, CHI_TIET_HOA_DON *p);
//CHI_TIET_HOA_DON *khoiTaoNodeCTHD();
vatTu *ktMaVTNode(tree t, int b);
//-----In Hoa Don
void inHoaDon(DS_NHAN_VIEN dsNV);
hoaDon *ktSoHD(DS_NHAN_VIEN dsNV, string sHD);
//------Thong Ke Hoa Don Theo Khoang Thoi Gian
void thongKeHD(DS_NHAN_VIEN dsNV);
NGAY_THANG nhapKTNgay(string a, int p);
void timHDTK(DS_NHAN_VIEN dsNV, hoaDon *dstemp[], nhanVien *dsNVtemp[], int &nhd, NGAY_THANG day1, NGAY_THANG day2);
float tinhGiaTriHD(hoaDon *q);
//==============================================
//------Menu
void menu() {
	//------Khai Bao Bien
	DS_VAT_TU dsVT;
	DS_NHAN_VIEN dsNV;
	bool Flag = true;
	//------Load File
	docFileDSVatTu(dsVT);
	docFileDSNhanVien(dsNV);
	//------Xu Ly Menu
	do {
		system("cls");
		cout << "\t\t======MENU======" << endl;
		cout << "1.Them Vat Tu" << endl;
		cout << "2.Xuat DS Vat Tu Tang Dan Theo Ten" << endl;
		cout << "3.Xoa Vat Tu" << endl;
		cout << "4.Sua Vat Tu" << endl;
		cout << "5.Them Nhan Vien" << endl;
		cout << "6.Xuat DS Nhan Vien Tang Dan Theo Ten, Ho" << endl;
		cout << "7.Xoa Nhan Vien" << endl;
		cout << "8.Sua Nhan Vien" << endl;
		cout << "9.Lap Hoa Don" << endl;
		cout << "10.In Hoa Don" << endl;
		cout << "11.Thong Ke Hoa Don Theo Khoang Thoi Gian" << endl;
		//cout << "12.In Hoa Don" << endl;
		//cout << "13.In Hoa Don" << endl;
		cout << "0.Thoat" << endl;
		gotoxy(45, 1); cout << "|"; cout << "\t\t======THONG BAO======";
		gotoxy(45, 2); cout << "|";
		gotoxy(45, 3); cout << "|";
		gotoxy(45, 4); cout << "|";
		gotoxy(45, 5); cout << "|";
		gotoxy(45, 6); cout << "|";
		gotoxy(45, 7); cout << "|";
		gotoxy(45, 8); cout << "|";
		gotoxy(45, 9); cout << "|";
		gotoxy(45, 10); cout << "|";
		gotoxy(45, 11); cout << "|";
		gotoxy(45, 12); cout << "|";
		gotoxy(45, 13); cout << "|";
		gotoxy(45, 14); cout << "|";
		gotoxy(45, 15); cout << "|";
		gotoxy(45, 16); cout << "|";
		gotoxy(1, 17);
		cout << "____________________________________________|__________________________________________________";
		int luaChon;
		gotoxy(1, 18);
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		switch (luaChon) {
		case 1: {
			themVatTu(dsVT);
			gotoxy(x, y); system("pause");
			break;
		}
		case 2: {
			vatTu *ds[100];
			int nds = 0;
			chuyenCaySangMang(dsVT.TREE, ds, nds);
			sapXepDSVatTu(ds, nds);
			xuatDSVatTu(ds, nds);
			giaiPhongDSVatTu(ds, nds);
			gotoxy(x, y); system("pause");
			break;
		}
		case 3: {
			xoaVatTu(dsVT);
			gotoxy(x, y); system("pause");
			break;
		}
		case 4: {
			suaVatTu(dsVT);
			gotoxy(x, y); system("pause");
			break;
		}
		case 5: {
			if (dsNV.sl == 500) {
				gotoxy(x, z); cout << "                                           ";
				gotoxy(x, z);
				cout << "Them NV khong thanh cong! Data full!" << endl;
				gotoxy(x, y); system("pause");
			}
			else {
				themNhanVien(dsNV);
				gotoxy(x, y); system("pause");
			}
			break;
		}
		case 6: {
			sapXepDSNhanVien(dsNV);
			xuatDSNhanVien(dsNV);
			gotoxy(x, y); system("pause");
			break;
		}
		case 7: {
			if (dsNV.sl == 0) {
				gotoxy(x, z); cout << "                                           ";
				gotoxy(x, z);
				cout << "Xoa khong thanh cong! Data None!" << endl;
				gotoxy(x, y); system("pause");
			}
			else {
				xoaNhanVien(dsNV);
				gotoxy(x, y); system("pause");
			}
			break;
		}
		case 8: {
			if (dsNV.sl == 0) {
				gotoxy(x, z); cout << "                                           ";
				gotoxy(x, z);
				cout << "Data None!" << endl;
				gotoxy(x, y); system("pause");
			}
			else {
				suaNhanVien(dsNV);
				gotoxy(x, y); system("pause");
			}
			break;
		}
		case 9: {
			lapHoaDon(dsNV, dsVT);
			gotoxy(x, y); system("pause");
			break;
		}
		case 10: {
			inHoaDon(dsNV);
			gotoxy(x, y); system("pause");
			break;
		}
		case 11: {
			thongKeHD(dsNV);
			gotoxy(x, y); system("pause");
			break;
		}
		case 0: {
			Flag = false;
			break;
		}
		}
	} while (Flag == true);
	//Xoa trang file
	ofstream fileOut;
	fileOut.open("dsVT.txt", ios_base::out);
	fileOut.close();
	fileOut.open("dsNV.txt", ios_base::out);
	fileOut.close();
	//Ghi file
	ghiFileDSVatTu(dsVT.TREE);
	ghiFileDSNhanVien(dsNV);
}
//==========VAT TU==========
//------Them Vat Tu
void themVatTu(DS_VAT_TU &dsVT) {
	vatTu *p = khoiTaoNodeVatTu();
	cin.ignore();
	cout << "Nhap Ten Vat Tu: ";
	getline(cin, p->tenVT);
	cout << "Nhap Don vi tinh Vat Tu: ";
	getline(cin, p->donViTinh);
	cout << "Nhap So luong ton Vat Tu: ";
	cin >> p->soLuongTon;
	p->kt = false;
	chuanHoaChu(p->tenVT);
	chuanHoaChu(p->donViTinh);
	p->maVT = taoMaVT(dsVT.TREE);
	them1VT(dsVT.TREE, p);
	dsVT.sl++;
	gotoxy(x, z); cout << "                                           ";
	gotoxy(x, z);
	cout << "Them Nhan Vien thanh cong!" << endl;
}
int taoMaVT(tree t) {
	int ma; //100-999
	do {
		ma = rand() % (999 - 100 + 1) + 100;
	} while (ktTrungMaVT(t, ma) == true);
	return ma;
}
bool ktTrungMaVT(tree t, int ma) {
	if (t == NULL) {
		return 0;
	}
	else {
		if (t->maVT == ma) {
			return 1;
		}
		else if (t->maVT < ma) {
			ktTrungMaVT(t->pRight, ma);
		}
		else {
			ktTrungMaVT(t->pLeft, ma);
		}
	}
}
//------Xuat Danh Sach Vat Tu
//Chuyen cay sang mang
void chuyenCaySangMang(tree t, vatTu *ds[], int &nds) {
	if (t != NULL) {
		//data
		ds[nds] = new vatTu;
		ds[nds]->maVT = t->maVT;
		ds[nds]->tenVT = t->tenVT;
		ds[nds]->donViTinh = t->donViTinh;
		ds[nds]->soLuongTon = t->soLuongTon;
		nds++;
		chuyenCaySangMang(t->pLeft, ds, nds);
		chuyenCaySangMang(t->pRight, ds, nds);
	}
}
//Sap xep danh sanh VT
void hoanVi2VT(vatTu *a, vatTu *b) {
	vatTu *temp = new vatTu;
	temp->maVT = a->maVT;
	temp->tenVT = a->tenVT;
	temp->donViTinh = a->donViTinh;
	temp->soLuongTon = a->soLuongTon;
	//
	a->maVT = b->maVT;
	a->tenVT = b->tenVT;
	a->donViTinh = b->donViTinh;
	a->soLuongTon = b->soLuongTon;
	//
	b->maVT = temp->maVT;
	b->tenVT = temp->tenVT;
	b->donViTinh = temp->donViTinh;
	b->soLuongTon = temp->soLuongTon;
	delete temp;
}
void sapXepDSVatTu(vatTu *ds[], int &nds) {
	for (int i = 0; i<nds - 1; i++) {
		for (int j = i + 1; j<nds; j++) {
			if (ds[i]->tenVT > ds[j]->tenVT) {
				hoanVi2VT(ds[i], ds[j]);
			}
		}
	}
}
//Xuat danh sach VT
void xuatDSVatTu(vatTu *ds[], int &nds) {
	gotoxy(30, cao);
	cout << "======DANH SACH VAT TU======" << endl;
	gotoxy(0, cao + 1);
	cout << "__________________________________________________________________________________" << endl;
	gotoxy(83, cao + 2); cout << "|";
	gotoxy(2, cao + 3);
	cout << "STT";
	gotoxy(10, cao + 3);
	cout << "Ma Vat Tu";
	gotoxy(30, cao + 3);
	cout << "Ten Vat Tu";
	gotoxy(50, cao + 3);
	cout << "Don Vi Tinh";
	gotoxy(70, cao + 3);
	cout << "So Luong Ton";
	gotoxy(83, cao + 3); cout << "|" << endl;
	cout << "__________________________________________________________________________________|" << endl;
	gotoxy(83, cao + 5); cout << "|" << endl;
	for (int i = 0; i<nds; i++) {
		gotoxy(2, cao + 6 + i);
		cout << i + 1;
		gotoxy(10, cao + 6 + i);
		cout << ds[i]->maVT;
		gotoxy(30, cao + 6 + i);
		cout << ds[i]->tenVT;
		gotoxy(50, cao + 6 + i);
		cout << ds[i]->donViTinh;
		gotoxy(70, cao + 6 + i);
		cout << ds[i]->soLuongTon;
		gotoxy(83, cao + 6 + i); cout << "|" << endl;
	}
	cout << "__________________________________________________________________________________|" << endl;
}
//Gia phong
void giaiPhongDSVatTu(vatTu *ds[], int &nds) {
	for (int i = 0; i<nds; i++) {
		delete ds[i];
	}
}
//------Xoa Vat Tu
void xoaVatTu(DS_VAT_TU &dsVT) {
	cout << "Vat Tu da lap Hoa Don thi khong the xoa." << endl;
	int a;
	cout << "Nhap Ma Vat Tu: ";
	cin >> a;
	bool kt = ktMaVT(dsVT.TREE, a);
	if (kt == true) {
		//Xoa
		xoa1VT(dsVT.TREE, a);
		dsVT.sl--;
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Xoa Vat Tu Thanh Cong!" << endl;
	}
	else {
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Ma Vat Tu Khong Ton Tai Hoac Da Lap Hoa Don!" << endl;
	}
}
int ktMaVT(tree t, int ma) {
	if (t == NULL) {
		return 0;
	}
	else {
		if (t->maVT == ma) {
			//KT chua lap hoa don
			if (t->kt == false) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else if (t->maVT < ma) {
			ktMaVT(t->pRight, ma);
		}
		else {
			ktMaVT(t->pLeft, ma);
		}
	}
}
void xoa1VT(tree &t, int ma) {
	if (t != NULL) {
		if (t->maVT == ma) {
			vatTu *x = t; //x se luu node can giai phong
			if (t->pLeft == NULL) {
				t = t->pRight;
			}
			else if (t->pRight == NULL) {
				t = t->pLeft;
			}
			else if (t->pLeft != NULL && t->pRight != NULL) {
				//tim node the mang: trai cung cay con phai
				nodeTheMang(t->pRight, x);
			}
			delete x;
		}
		else if (t->maVT < ma) {
			xoa1VT(t->pRight, ma);
		}
		else if (t->maVT > ma) {
			xoa1VT(t->pLeft, ma);
		}
	}
}
void nodeTheMang(tree &t, vatTu *&x) {
	if (t->pLeft != NULL) {
		nodeTheMang(t->pLeft, x);
	}
	//trai cung
	else {
		hoanVi2VT(t, x);
		x = t; //x se luu node nay sao do giai phong
		t = t->pRight;
	}
}
//------Sua Vat Tu
void suaVatTu(DS_VAT_TU &dsVT) {
	int a;
	cout << "Nhap Ma Vat Tu Can Sua: ";
	cin >> a;
	bool kt = ktTrungMaVT(dsVT.TREE, a);
	if (kt == true) {
		sua1VT(dsVT.TREE, a);
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Da sua thong tin Vat Tu!" << endl;
	}
	else {
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Ma Vat Tu khong ton tai!" << endl;
	}
}
void sua1VT(tree t, int ma) {
	if (t != NULL) {
		if (t->maVT == ma) {
			cin.ignore();
			cout << "Nhap Ten Vat Tu: ";
			getline(cin, t->tenVT);
			cout << "Nhap Don vi tinh Vat Tu: ";
			getline(cin, t->donViTinh);
			cout << "Nhap So luong ton Vat Tu: ";
			cin >> t->soLuongTon;
			chuanHoaChu(t->tenVT);
			chuanHoaChu(t->donViTinh);
		}
		else if (t->maVT > ma) {
			sua1VT(t->pLeft, ma);
		}
		else if (t->maVT < ma) {
			sua1VT(t->pRight, ma);
		}
	}
}

//==========NHAN VIEN==========
//------Them Nhan Vien
void themNhanVien(DS_NHAN_VIEN &dsNV) {
	NHAN_VIEN *p = new NHAN_VIEN;
	p->maNV = taoMaNV(dsNV);
	cin.ignore();
	do{
		cout << "Nhap Ho Nhan Vien: ";
		getline(cin, p->hoNV);
	} while (ktChuoi(p->hoNV) == 0);
	do {
		cout << "Nhap Ten Nhan Vien: ";
		getline(cin, p->tenNV);
	} while (ktChuoi(p->tenNV) == 0);
	cout << "Nhap Phai Nhan Vien: ";
	getline(cin, p->phaiNV);
	chuanHoaChu(p->hoNV);
	chuanHoaChu(p->tenNV);
	chuanHoaChu(p->phaiNV);
	//DSHD????????????????????????????????????????????????
	dsNV.ds[dsNV.sl] = p;
	dsNV.sl++;
	gotoxy(x, z); cout << "                                           ";
	gotoxy(x, z);
	cout << "Them Nhan Vien thanh cong!" << endl;
}
string taoMaNV(DS_NHAN_VIEN dsNV) {
	string a = "NV0000";
	do {
		for (int i = 2; i<a.length(); i++) {
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (ktTrungMaNV(a, dsNV) >= 0);
	return a;
}
int ktTrungMaNV(string a, DS_NHAN_VIEN dsNV) {
	for (int i = 0; i<dsNV.sl; i++) {
		if (dsNV.ds[i]->maNV == a) {
			return i;
		}
	}
	return -1;
}
//------Xuat DS Nhan Vien
//Sap xep danh sanh NV
void hoanVi2NV(nhanVien *a, nhanVien *b) {
	nhanVien *temp = new nhanVien;
	temp->maNV = a->maNV;
	temp->hoNV = a->hoNV;
	temp->tenNV = a->tenNV;
	temp->phaiNV = a->phaiNV;
	temp->dshd = a->dshd;
	//
	a->maNV = b->maNV;
	a->hoNV = b->hoNV;
	a->tenNV = b->tenNV;
	a->phaiNV = b->phaiNV;
	a->dshd = b->dshd;
	//
	b->maNV = temp->maNV;
	b->hoNV = temp->hoNV;
	b->tenNV = temp->tenNV;
	b->phaiNV = temp->phaiNV;
	b->dshd = temp->dshd;
	delete temp;
}
void sapXepDSNhanVien(DS_NHAN_VIEN &dsNV) {
	for (int i = 0; i<dsNV.sl - 1; i++) {
		for (int j = i + 1; j<dsNV.sl; j++) {
			if (dsNV.ds[i]->tenNV > dsNV.ds[j]->tenNV) {
				hoanVi2NV(dsNV.ds[i], dsNV.ds[j]);
			}
			else if (dsNV.ds[i]->tenNV == dsNV.ds[j]->tenNV) {
				if (dsNV.ds[i]->hoNV > dsNV.ds[j]->hoNV) {
					hoanVi2NV(dsNV.ds[i], dsNV.ds[j]);
				}
			}
		}
	}
}
void xuatDSNhanVien(DS_NHAN_VIEN dsNV) {
	gotoxy(30, cao);
	cout << "======DANH SACH NHAN VIEN======" << endl;
	gotoxy(0, cao + 1);
	cout << "__________________________________________________________________________________" << endl;
	gotoxy(83, cao + 2); cout << "|";
	gotoxy(2, cao + 3);
	cout << "STT";
	gotoxy(10, cao + 3);
	cout << "Ma Nhan Vien";
	gotoxy(30, cao + 3);
	cout << "Ho";
	gotoxy(50, cao + 3);
	cout << "Ten";
	gotoxy(70, cao + 3);
	cout << "Phai";
	gotoxy(83, cao + 3); cout << "|" << endl;
	cout << "__________________________________________________________________________________|" << endl;
	gotoxy(83, cao + 5); cout << "|" << endl;
	for (int i = 0; i<dsNV.sl; i++) {
		gotoxy(2, cao + 6 + i);
		cout << i + 1;
		gotoxy(10, cao + 6 + i);
		cout << dsNV.ds[i]->maNV;
		gotoxy(30, cao + 6 + i);
		cout << dsNV.ds[i]->hoNV;
		gotoxy(50, cao + 6 + i);
		cout << dsNV.ds[i]->tenNV;
		gotoxy(70, cao + 6 + i);
		cout << dsNV.ds[i]->phaiNV;
		gotoxy(83, cao + 6 + i); cout << "|" << endl;
	}
	cout << "__________________________________________________________________________________|" << endl;
}
//------Xoa Nhan Vien
void xoaNhanVien(DS_NHAN_VIEN &dsNV) {
	string a;
	cout << "Nhap Ma Nhan Vien (NV****): ";
	cin >> a;
	//chuanHoaChu(a);
	//------
	int viTri = ktTrungMaNV(a, dsNV);
	//------Xoa
	//Doi
	if (viTri < 0) {
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Nhan Vien khong ton tai!" << endl;
	}
	else {
		for (int i = viTri; i<dsNV.sl - 1; i++) {
			dsNV.ds[i]->maNV = dsNV.ds[i + 1]->maNV;
			dsNV.ds[i]->hoNV = dsNV.ds[i + 1]->hoNV;
			dsNV.ds[i]->tenNV = dsNV.ds[i + 1]->tenNV;
			dsNV.ds[i]->phaiNV = dsNV.ds[i + 1]->phaiNV;
			//dsNV.ds[i]->kt = dsNV.ds[i+1]->kt;
			//DSHD????????????????????????????????????????????????
		}
		//Giam so luong
		//NHAN_VIEN *temp = dsNV.ds[dsNV.sl - 1];
		delete dsNV.ds[dsNV.sl-1];
		dsNV.sl--;
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Da xoa thanh cong!" << endl;
	}
}
//------Sua Nhan Vien
void suaNhanVien(DS_NHAN_VIEN dsNV) {
	string a;
	cout << "Nhap Ma Nhan Vien can sua(NV****): ";
	cin >> a;
	//------KT ma Nhan Vien
	int viTri = ktTrungMaNV(a, dsNV);
	if (viTri < 0) {
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Ma Nhan Vien khong ton tai!" << endl;
	}
	else {
		//------Sua
		cout << "\t\t======Sua Nhan Vien " << a << "======" << endl;
		cout << "Nhap Ho Nhan Vien: ";
		cin.ignore();
		getline(cin, dsNV.ds[viTri]->hoNV);
		cout << "Nhap Ten Nhan Vien: ";
		getline(cin, dsNV.ds[viTri]->tenNV);
		cout << "Nhap Phai Nhan Vien: ";
		getline(cin, dsNV.ds[viTri]->phaiNV);
		chuanHoaChu(dsNV.ds[viTri]->hoNV);
		chuanHoaChu(dsNV.ds[viTri]->tenNV);
		chuanHoaChu(dsNV.ds[viTri]->phaiNV);
		cout << "\t\t================================" << endl;
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Da thay doi thong tin Nhan Vien!" << endl;
	}
}
//==========LAP HOA DON ==========
void lapHoaDon(DS_NHAN_VIEN &dsNV, DS_VAT_TU &dsVT) {
	string a;
	cout << "Nhap Ma Nhan Vien Lap hoa don(NV****): ";
	cin >> a;
	nhanVien *temp = ktMaNV(a, dsNV); //Lay ve NV
	if (temp == NULL) {
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Ma Nhan Vien khong ton tai!" << endl;
	}
	else {
		//xu ly lap hoa don
		HOA_DON *p = khoiTaoNodeHD();
		bool nhap, ktw = true;
		while (ktw == true) {
			gotoxy(20, cao + 3); cout << "              ";
			gotoxy(30, cao);
			cout << "\t\t======LAP HOA DON======" << endl;
			cout << "1.Hoa Don Nhap" << endl;
			cout << "2.Hoa Don Xuat" << endl;
			int xn;
			cout << "Nhap loai hoa don: ";
			cin >> xn;
			switch (xn) {
			case 1: {
				cout << "Loai hoan don: Nhap" << endl;
				nhap = true;
				p->loaiHD = 'N';
				ktw = false;
				break;
			}
			case 2: {
				cout << "Loai hoan don: Xuat" << endl;
				nhap = false;
				p->loaiHD = 'X';
				ktw = false;
				break;
			}
			}
		}
		//
		p->soHD = taoSoHD(temp->dshd);
		cout << "So Hoa Don: " << p->soHD << endl;
		cin.ignore();
		cout << "Ngay lap hoa don: ";
		layNgayThangHT(p->ngayLapHD);
		xuatNgayThang(p->ngayLapHD);
		//------Them HD vao ds Hoa Don
		temp->dshd.sl++;
		them1HD(temp->dshd.pHead, p);
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "Lap Hoa don thanh cong!" << endl;
		//------Lap Chi tiet Hoa don
		bool ktw1 = true;
		while (ktw1 == true) {
			gotoxy(30, cao + 7);
			cout << "\t\t------Chi Tiet Hoa Don------" << endl;
			int b;
			cout << "Nhap Ma Vat Tu: ";
			cin >> b;
			vatTu *temp1 = ktMaVTNode(dsVT.TREE, b);
			if (temp1 == NULL) {
				gotoxy(x, z); cout << "                                           ";
				gotoxy(x, z);
				cout << "Ma Vat Tu khong ton tai!" << endl;
			}
			else {
				CHI_TIET_HOA_DON *p1 = khoiTaoNodeCTHD();
				p1->maVatTu = b;
				cout << "Nhap So luong: ";
				cin >> p1->soLuong;
				cout << "Nhap Don gia: ";
				cin >> p1->donGia;
				cout << "Nhap VAT(%): ";
				cin >> p1->VAT;
				if (p->loaiHD == 'N') {
					temp1->soLuongTon = temp1->soLuongTon + p1->soLuong;
					temp1->kt = true;
					them1CTHD(p->dscthd.pHead, p1);
					p->dscthd.sl++;
					gotoxy(x, z); cout << "                                           ";
					gotoxy(x, z);
					cout << "Lap Chi tiet Hoa Don thanh cong!" << endl;
				}
				else if (p->loaiHD == 'X') {
					if (temp1->soLuongTon < p1->soLuong)
					{
						gotoxy(x, z); cout << "                                           ";
						gotoxy(x, z);
						cout << "So Luong Ton la: " << temp1->soLuongTon << " .Khong du de Xuat!" << endl;
					}
					else {
						temp1->soLuongTon = temp1->soLuongTon - p1->soLuong;
						temp1->kt = true;
						them1CTHD(p->dscthd.pHead, p1);
						p->dscthd.sl++;
						gotoxy(x, z); cout << "                                           ";
						gotoxy(x, z);
						cout << "Lap Chi tiet Hoa Don thanh cong!" << endl;
					}
				}
			}
			bool ktw2 = true;
			while (ktw2 == true) {
				gotoxy(x, z + 1); cout << "                      " << endl;
				gotoxy(x, z + 2); cout << "                      " << endl;
				gotoxy(x, z + 3); cout << "                      " << endl;
				gotoxy(x, z + 1);
				int nhapcthd;
				cout << "1.Nhap Tiep";
				gotoxy(x, z + 2);
				cout << "2.Thoat";
				cin.ignore();
				gotoxy(x, z + 3);
				cout << ">>>>>>";
				cin >> nhapcthd;
				switch (nhapcthd) {
				case 1: {
					gotoxy(1, cao + 8); cout << "                      " << endl;
					gotoxy(1, cao + 9); cout << "                      " << endl;
					gotoxy(1, cao + 10); cout << "                      " << endl;
					gotoxy(1, cao + 11); cout << "                      " << endl;
					gotoxy(1, cao + 12); cout << "                      " << endl;
					gotoxy(1, cao + 13); cout << "                      " << endl;
					gotoxy(1, cao + 14); cout << "                      " << endl;
					gotoxy(1, cao + 15); cout << "                      " << endl;
					ktw2 = false;
					break;
				}
				case 2: {
					ktw1 = false;
					ktw2 = false;
					break;
				}
				}
			}
		}
	}
}
nhanVien *ktMaNV(string a, DS_NHAN_VIEN dsNV) {
	for (int i = 0; i<dsNV.sl; i++) {
		if (dsNV.ds[i]->maNV == a) {
			return dsNV.ds[i];
		}
	}
	return NULL;
}
bool ktTrungSoHD(HOA_DON *pHead, string ma) {
	for (HOA_DON *k = pHead; k != NULL; k = k->pNext) {
		if (k->soHD == ma) {
			return true;
		}
	}
	return false;
}
string taoSoHD(DS_HOA_DON dsHD) {
	string a = "HD0000";
	do {
		for (int i = 2; i<a.length(); i++) {
			a[i] = rand() % (57 - 48 + 1) + 48;
		}
	} while (ktTrungSoHD(dsHD.pHead, a) == true);
	return a;
}
//------Chi Tiet Hoa Don
vatTu *ktMaVTNode(tree t, int b){
	if(t == NULL){
		return NULL;
	}
	else{
		if(t->maVT == b){
			return t;
		}
		else if(t->maVT < b){
			ktMaVTNode(t->pRight, b);
		}
		else{
			ktMaVTNode(t->pLeft, b);
		}
	}
}
//-----In Hoa Don
void inHoaDon(DS_NHAN_VIEN dsNV) {
	string sHD;
	cout << "Nhap So Hoa Don(HD****): ";
	cin >> sHD;
	hoaDon *temp = ktSoHD(dsNV, sHD);
	if (temp == NULL) {
		gotoxy(x, z); cout << "                                           ";
		gotoxy(x, z);
		cout << "So Hoa Don khong ton tai!" << endl;
	}
	else {
		gotoxy(30, cao);
		cout << "======HOA DON SO "<<temp->soHD<<"======" << endl;
		gotoxy(0, cao + 1);
		cout << "\t\t\t_______________________________________" << endl;
		gotoxy(2, cao + 3);
		cout << "Ngay lap: "; xuatNgayThang(temp->ngayLapHD);
		gotoxy(30, cao + 3);
		cout << "Loai: " << temp->loaiHD << endl;
		gotoxy(0, cao + 4);
		cout << "__________________________________________________________________________________" << endl;
		gotoxy(83, cao + 5); cout << "|";
		gotoxy(2, cao + 6);
		cout << "STT";
		gotoxy(10, cao + 6);
		cout << "Ma Vat Tu";
		gotoxy(30, cao + 6);
		cout << "So Luong";
		gotoxy(50, cao + 6);
		cout << "Don Gia";
		gotoxy(70, cao + 6);
		cout << "VAT(%)";
		gotoxy(83, cao + 6); cout << "|" << endl;
		cout << "__________________________________________________________________________________|" << endl;
		gotoxy(83, cao + 8); cout << "|" << endl;
		int i = 0;
		for (CHI_TIET_HOA_DON *p = temp->dscthd.pHead; p != NULL; p = p->pNext) {
			gotoxy(2, cao + 9 + i);
			cout << i + 1;
			gotoxy(10, cao + 9 + i);
			cout << p->maVatTu;
			gotoxy(30, cao + 9 + i);
			cout << p->soLuong;
			gotoxy(50, cao + 9 + i);
			cout << p->donGia;
			gotoxy(70, cao + 9 + i);
			cout << p->VAT;
			gotoxy(83, cao + 9 + i); cout << "|" << endl;
			i++;
		}
		cout << "__________________________________________________________________________________|" << endl;
	}
}
hoaDon *ktSoHD(DS_NHAN_VIEN dsNV, string sHD){
	for (int i = 0; i<dsNV.sl; i++) {
		for (hoaDon *k = dsNV.ds[i]->dshd.pHead; k != NULL; k = k->pNext) {
			if (k->soHD == sHD) {
				return k;
			}
		}
	}
	return NULL;
}
//------Thong Ke Hoa Don Theo Khoang Thoi Gian
void thongKeHD(DS_NHAN_VIEN dsNV) {
	NGAY_THANG ngayDau = nhapKTNgay("Tu ngay:  ", 19);
	NGAY_THANG ngayCuoi = nhapKTNgay("Den ngay: ", 20);
	hoaDon *dsHDtemp[100];
	nhanVien *dsNVtemp[100];
	int nhd = 0;
	timHDTK(dsNV, dsHDtemp, dsNVtemp, nhd, ngayDau, ngayCuoi);
	//In Bang Liet Ke
	gotoxy(10, cao);
	cout << "======BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN======" << endl;
	gotoxy(0, cao + 1);
	cout << "\t\t\t_______________________________________" << endl;
	gotoxy(2, cao + 3);
	cout << "Tu ngay: "; xuatNgayThang(ngayDau);
	gotoxy(30, cao + 3);
	cout << "Den ngay: "; xuatNgayThang(ngayCuoi);
	gotoxy(0, cao + 4);
	cout << "____________________________________________________________________________________________" << endl;
	gotoxy(93, cao + 5); cout << "|";
	gotoxy(2, cao + 6);
	cout << "STT";
	gotoxy(10, cao + 6);
	cout << "So HD";
	gotoxy(23, cao + 6);
	cout << "Ngay Lap";
	gotoxy(40, cao + 6);
	cout << "Loai HD";
	gotoxy(55, cao + 6);
	cout << "Ho va Ten NV Lap";
	gotoxy(80, cao + 6);
	cout << "Tri Gia HD";
	gotoxy(93, cao + 6); cout << "|" << endl;
	cout << "____________________________________________________________________________________________|" << endl;
	gotoxy(93, cao + 8); cout << "|" << endl;
	int i = 0;
	for (int i = 0; i < nhd; i++){
		gotoxy(2, cao + 9 + i);
		cout << i + 1;
		gotoxy(10, cao + 9 + i);
		cout << dsHDtemp[i]->soHD;
		gotoxy(23, cao + 9 + i);
		xuatNgayThang(dsHDtemp[i]->ngayLapHD);
		gotoxy(40, cao + 9 + i);
		cout << dsHDtemp[i]->loaiHD;
		gotoxy(55, cao + 9 + i);
		cout << dsNVtemp[i]->hoNV << " " << dsNVtemp[i]->tenNV;
		gotoxy(80, cao + 9 + i);
		cout << tinhGiaTriHD(dsHDtemp[i]);
		gotoxy(93, cao + 9 + i); cout << "|" << endl;
	}
	cout << "____________________________________________________________________________________________|" << endl;
}
NGAY_THANG nhapKTNgay(string a, int p) {
	NGAY_THANG day;
	bool wngay = true;
	while (wngay == true) {
		gotoxy(1, p); cout << "                                                                     ";
		gotoxy(1, p);
		cout << a;
		cin >> day.ngay;
		gotoxy(14, p); cout << "/";
		cin >> day.thang;
		gotoxy(18, p); cout << "/";
		cin >> day.nam;
		int ktD = ngayHopLe(day);
		switch (ktD) {
		case 3: {
			gotoxy(x, z); cout << "                                           ";
			gotoxy(x, z);
			cout << "Dung Format. Tiep tuc nhap ngay!" << endl;
			wngay = false;
			break;
		}
		case 2: {
			gotoxy(x, z); cout << "                                           ";
			gotoxy(x, z);
			cout << "Sai Nam. Vui long nhap lai!" << endl;
			break;
		}
		case 1: {
			gotoxy(x, z); cout << "                                           ";
			gotoxy(x, z);
			cout << "Sai Thang. Vui long nhap lai!" << endl;
			break;
		}
		case 0: {
			gotoxy(x, z); cout << "                                           ";
			gotoxy(x, z);
			cout << "Sai Ngay. Vui long nhap lai!" << endl;
			break;
		}
		}
	}
	return day;
}
//Duyet tim trong khoang thoi gian
void timHDTK(DS_NHAN_VIEN dsNV, hoaDon *dsHDtemp[], nhanVien *dsNVtemp[], int &nhd, NGAY_THANG day1, NGAY_THANG day2) {
	for (int i = 0; i<dsNV.sl; i++) {
		for (hoaDon *k = dsNV.ds[i]->dshd.pHead; k != NULL; k = k->pNext) {
			if (tinhNgay(k->ngayLapHD) >= tinhNgay(day1) && tinhNgay(k->ngayLapHD) <= tinhNgay(day2)) {
				dsHDtemp[nhd] = k;
				dsNVtemp[nhd] = dsNV.ds[i];
				nhd++;
			}
		}
	}
}
float tinhGiaTriHD(hoaDon *q) {
	float sum = 0;
	for (CHI_TIET_HOA_DON *p = q->dscthd.pHead; p != NULL; p = p->pNext) {
		sum = sum + p->soLuong*p->donGia - p->soLuong*p->donGia*p->VAT/100;
	}
	return sum;
}
//------In 10 Vat Tu Co Doanh Thu Cao Nhat Trong Khoang Thoi Gian
//------Thong Ke Doanh Thu Trong Khoang Tung Thang Thuoc 1 Nam
