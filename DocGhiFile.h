#pragma once
#include "ChuanHoa.h"
//------Doc Ghi File DS Vat Tu
void docFileDSVatTu(DS_VAT_TU &dsVT) {
	ifstream fileIn;
	fileIn.open("dsVT.txt", ios_base::in);
	if (!fileIn) {
		cout << "Khong tim thay file dsVT.txt" << endl;
		system("pause");
	}
	while (fileIn.eof() != true) {
		vatTu *x = khoiTaoNodeVatTu();
		fileIn.ignore();
		fileIn >> x->maVT;
		fileIn.ignore();
		getline(fileIn, x->tenVT, ',');
		getline(fileIn, x->donViTinh, ',');
		fileIn >> x->soLuongTon;
		fileIn.ignore();
		fileIn >> x->kt;
		them1VT(dsVT.TREE, x);
		dsVT.sl++;
	}
	fileIn.close();
}

void ghiFileDSVatTu(tree t) {
	ofstream fileOut;
	fileOut.open("dsVT.txt", ios_base::app | ios_base::out);
	if (t != NULL) {
		ghiFileDSVatTu(t->pLeft);
		fileOut <<"\n"<< t->maVT << ',';
		fileOut << t->tenVT << ',';
		fileOut << t->donViTinh << ',';
		fileOut << t->soLuongTon << ',';
		fileOut << t->kt;
		ghiFileDSVatTu(t->pRight);
	}
	fileOut.close();
}
//------Doc Ghi File DS Nhan Vien
void docFileDSNhanVien(DS_NHAN_VIEN &dsNV) {
	ifstream fileIn;
	fileIn.open("dsNV.txt", ios_base::in);
	if (!fileIn) {
		cout << "Khong tim thay file dsNV.txt" << endl;
		system("pause");
	}
	dsNV.ds[dsNV.sl] = new NHAN_VIEN;
	string fg;
	getline(fileIn, fg, ',');
	if (fg == "/") return;
	while (fileIn.eof() != true) {
		loadNV:
			NHAN_VIEN *q = new NHAN_VIEN;
			getline(fileIn, q->maNV, ',');
			getline(fileIn, q->hoNV, ',');
			getline(fileIn, q->tenNV, ',');
			getline(fileIn, q->phaiNV, '\n');
			q->dshd.pHead = NULL;
			getline(fileIn, fg, ',');
			if (fg == "#") {
				dsNV.ds[dsNV.sl] = q;
				dsNV.sl++;
				continue;
			}
			if (fg == "$") {
				dsNV.ds[dsNV.sl] = q;
				dsNV.sl++;
				break;
			}
		loadHD:
			HOA_DON *p = khoiTaoNodeHD();
			getline(fileIn, p->soHD, ',');
			fileIn >> p->ngayLapHD.ngay;
			fileIn.ignore();// bo '/'
			fileIn >> p->ngayLapHD.thang;
			fileIn.ignore();// bo '/'
			fileIn >> p->ngayLapHD.nam;
			fileIn.ignore();// bo ','
			fileIn >> p->loaiHD;
			fileIn.ignore();
			//
			getline(fileIn, fg, ',');
			if (fg == "-") {
				them1HD(q->dshd.pHead, p);
				goto loadHD;
			}
			if (fg == "#") {
				them1HD(q->dshd.pHead, p);
				dsNV.ds[dsNV.sl] = q;
				dsNV.sl++;
				goto loadNV;
			}
			if (fg == "$") {
				them1HD(q->dshd.pHead, p);
				dsNV.ds[dsNV.sl] = q;
				dsNV.sl++;
				break;
			}
		loadCTHD:
			CHI_TIET_HOA_DON *p1 = khoiTaoNodeCTHD();
			fileIn >> p1->maVatTu;
			fileIn.ignore();
			fileIn >> p1->soLuong;
			fileIn.ignore();
			fileIn >> p1->donGia;
			fileIn.ignore();
			fileIn >> p1->VAT;
			fileIn.ignore();
			//
			getline(fileIn, fg, ',');
			them1CTHD(p->dscthd.pHead, p1);
			if (fg == "+") {
				goto loadCTHD;
			}
			if (fg == "-") {
				them1HD(q->dshd.pHead, p);
				goto loadHD;
			}
			if (fg == "#") {
				them1HD(q->dshd.pHead, p);
				dsNV.ds[dsNV.sl] = q;
				dsNV.sl++;
				goto loadNV;
			}
			if (fg == "$") {
				them1HD(q->dshd.pHead, p);
				dsNV.ds[dsNV.sl] = q;
				dsNV.sl++;
				break;
			}
	}
	fileIn.close();
	return;
}
void ghiFileDSNhanVien(DS_NHAN_VIEN dsNV) {
	ofstream fileOut;
	fileOut.open("dsNV.txt", ios_base::app | ios_base::out);
	for (int i = 0; i < dsNV.sl; i++) {
		fileOut << "#,";
		fileOut << dsNV.ds[i]->maNV << ",";
		fileOut << dsNV.ds[i]->hoNV << ",";
		fileOut << dsNV.ds[i]->tenNV << ",";
		fileOut << dsNV.ds[i]->phaiNV << "\n";
		for (hoaDon *k = dsNV.ds[i]->dshd.pHead; k != NULL; k = k->pNext) {
			fileOut << "-,";
			fileOut << k->soHD << ",";
			fileOut << k->ngayLapHD.ngay << "/" << k->ngayLapHD.thang << "/" << k->ngayLapHD.nam << ",";
			fileOut << k->loaiHD << "\n";
			for (CHI_TIET_HOA_DON *p = k->dscthd.pHead; p != NULL; p = p->pNext) {
				fileOut << "+,";
				fileOut << p->maVatTu << ",";
				fileOut << p->soLuong << ",";
				fileOut << p->donGia << ",";
				fileOut << p->VAT << "\n";
			}
		}
	}
	fileOut << "$,";
}