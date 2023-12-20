#ifndef FILEDATA_H
#define FILEDATA_H

#include <iostream>
#include <string>
#include <fstream>
#include "KhachHang.h"
#include "HangHoa.h"
#include "KhachHang.h"
#include "Extra.h"


using namespace std;

//1. file hàng hóa
// hàm giúp lấy dữ liệu từ file từng dòng tương ứng với từng hàng
void file1HH(HangHoa& HH, string Ma, string Ten, string Gia, string SL, string Ngaynhap, string HSD, int& m){ 
	HH.setMaHangHoa(Ma);
	int a = 0; 
	int b = 0; 
	string temp; 
	temp = HH.getMaHangHoa().substr(0, 2); // quy định 2 mã số đầu để suy ra đơn vị của các mặt hàng
	int t = stoi(temp); 
	switch (t){ 
	case 21:
		HH.setDonVi("Kg"); 
		break; 
	case 22:
	 	HH.setDonVi("Cai"); 
	 	break; 
	case 10:
	 	HH.setDonVi("Hop");
	 	break; 
	case 11:
	 	HH.setDonVi("Chai"); 
	 	break; 
	case 20:
	 	HH.setDonVi("Thung"); 
	 	break; 
	default: 
	 	HH.setDonVi("San pham"); 
	 	break; 
	 } 
	HH.setTenHangHoa(Ten);
	HH.setSoLuong(stoi(SL)); 
	HH.setGia(stoi(Gia));
	HH.setNgayNhap(Ngaynhap); 
 	Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.getNgayNhap()); 
	if (a == 1 || HH.thang > 12) 
 		m = 1; 
	HH.TimeNgaynhap = HH.ngay + HH.thang * 30 + HH.nam * 365; // Tính toán để sắp xếp theo Ngày nhập
	HH.setHSD(HSD);
 	Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.getHSD()); 
	if (a == 1 || HH.thang > 12) 
 		b = 1; 
	if (m || b) m=1;
	HH.TimeHSD = HH.ngay + HH.thang * 30 + HH.nam * 365; //Tính toán để sắp xếp theo hạn sử dụng
}

//Hàm giúp lấy toàn bộ dữ liệu file
void fileHH(HangHoa HH[], int& N, string filename){
	fstream f;
 	f.open(filename, ios::in); // đọc file
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	string str; 
	N = 0; 
 	getline(f, str); //đọc từng hàm của file, dữ liệu từ f sẽ lưu vào str
	int q = 0; 
	while (!f.eof())//nếu xuống cuối dòng thì dừng đọc file
	{ 
		string t[20]; 
		string tmp = ""; 
		int cnt = 0; 
		getline(f, str); 
		for (int i = 0; i < str.size(); i++){ 
			if (str[i] == '\t') { t[cnt] = tmp; tmp = ""; cnt++; }  
			else{ 
		 		tmp += str[i]; 
		 	} 
		} 
		t[cnt] = tmp; 
		int m = 0; 
		file1HH(HH[N], t[1], t[2], t[3], t[4], t[5], t[6], m); 
		if (m == 1){ 
			q = 1; 
		 	break; 
		} 
		N++; //tăng số hàng lên 1
	} 
	if (q == 1){ 
		cout << "Loi file do nhap ngay sai tai hang " << N + 1 <<endl;
		N = 0; 
	} 
	else { 
		cout << "Da upload file thanh cong!\n"; 
	} 
	f.close(); 
} 

//2.file khách hàng
//Hàm thiết lập thông tin
void file1KH(KhachHang& KH, string Ma, string Ten, string SDT, string DTL){
	KH.setMaKhachHang(Ma); 
	KH.setTenKhachHang(Ten);
	KH.setSoDienThoai(SDT); 
	KH.setDiemTichLuy(stoi(DTL)); // chuyển điểm về dạng số
}
//Hàm đọc dữ liệu file khách hàng
//tương tự như cách thức đọc của file hàng hóa
void fileKH(KhachHang KH[], int& M, string filename){
	fstream f;
 	f.open(filename, ios::in); 
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	else { cout << "Da upload file thanh cong\n"; } 
	string str; 
	M = 0; 
 	getline(f, str); 
	int q = 0; 
	while (!f.eof()) 
	{ 
		string t[20]; 
		string tmp = ""; 
		int cnt = 0; 
		getline(f, str); 
		for (int i = 0; i < str.size(); i++){ 
			if (str[i] == '\t') { t[cnt] = tmp; tmp = ""; cnt++; } 
			else{ 
 				tmp += str[i]; 
 			} 
 		} 
		t[cnt] = tmp; 
		int m = 0; 
		file1KH(KH[M], t[1], t[2], t[3], t[4]); 
		M++; // tăng số khách lên 1
 	} 
 	f.close();
}

//3.file lịch sử hàng đã mua
//Hàm thiết lập 
void file1LS(HangHoa& BILL, string Ma, string Ten, string Gia, string SL, string Ngaynhap, string TTP, int& m){
	BILL.setMaHangHoa(Ma);
	int a = 0; 
	int b = 0; 
	string temp; 
	temp = BILL.getMaHangHoa().substr(0, 2); 
	int t = stoi(temp); 
	switch (t) { 
		case 21:
			BILL.setDonVi("Kg"); 
			break; 
		case 22:
	 		BILL.setDonVi("Cai"); 
	 		break; 
		case 10:
	 		BILL.setDonVi("Hop");
	 		break; 
		case 11:
	 		BILL.setDonVi("Chai"); 
	 		break; 
		case 20:
	 		BILL.setDonVi("Thung"); 
	 		break; 
		default: 
	 		BILL.setDonVi("San pham"); 
	 		break; 
 	} 
	BILL.setTenHangHoa(Ten); 
	BILL.setSoLuong(stoi(SL));
	BILL.setGia(stoi(Gia));
	BILL.setNgayNhap(Ngaynhap); 
	Phantichngay(BILL.ngay, BILL.thang, BILL.nam, a, BILL.getNgayNhap()); 
	if (a == 1 || BILL.thang > 12) 
 		m = 1; 
	BILL.TimeNgaynhap = BILL.ngay + BILL.thang * 30 + BILL.nam * 365;
	BILL.TTP = stoi(TTP);
}
//Tương tự như hàm đọc file của hàng hóa cũng như khách hàng
//Ta có hàm đọc file Lịch sử
void fileLS(HangHoa BILL[], int& found2, string filename){
	fstream f;
    f.open(filename, ios::in); 
    if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
    string str; 
    getline(f, str); 
    int q = 0; 
    while (!f.eof()) 
    { 
		string t[10]; 
		string tmp = ""; 
		int cnt = 0; 
		getline(f, str); 
		for (int i = 0; i < str.size(); i++){ 
			if (str[i] == '\t') { t[cnt] = tmp; tmp = ""; cnt++; } 
			else{ 
 				tmp += str[i]; 
 			} 
 		} 
 		t[cnt] = tmp; 
 		int m = 0; 
 		file1LS(BILL[found2], t[1], t[2], t[3], t[4], t[5], t[6], m); 
 		if (m == 1) 
		{ 
 			q = 1;
 			break; 
 		} 
 		found2++; 
 	} 
	if (q == 1){ 
 		cout << "loi file!!!\n"; 
 		found2 = 0; 
 	} 
 	else cout << "Da upload file thanh cong\n";
 	f.close(); 
}


//Các hàm xuất file
//xuất file hàng hóa
void Xuatfile1HH(HangHoa& HH, string& Ma, string& Ten, string& Gia, string& SL, string& Donvi, string& Ngaynhap, string& HSD){ 
	Ma = HH.getMaHangHoa(); 
	Ten = HH.getTenHangHoa(); 
	Gia = to_string(HH.getGia()); 
	SL = to_string(HH.getSoLuong()); 
	Donvi = HH.getDonVi(); 
	Ngaynhap = HH.getNgayNhap(); 
	HSD = HH.getHSD(); 
}

void XuatfileHH(HangHoa HH[], int& N,string filename) 
{ 
	fstream f;
	string Ma, Ten, Gia, SL, Donvi, Ngaynhap, HSD; 
 	f.open(filename, ios::out); 
	if (f.fail()){ cout << "Khong the mo file!!!" << endl; return; }
	f << "STT\tMa hang hoa\tTen hang hoa\tGia\tSo luong\tDon vi\tNgay nhap\tHSD" << endl; 
	for (int i = 0; i < N; i++){ 
 		Xuatfile1HH(HH[i], Ma, Ten, Gia, SL, Donvi, Ngaynhap, HSD); 
 		f << i+1 << "\t" << Ma << "\t" << Ten << "\t" << Gia << "\t"<< SL << "\t" << Donvi << "\t" << Ngaynhap << "\t" << HSD << endl; 
 	} 
 	f.close(); 
}

//Xuất file khách hàng
void Xuatfile1KH(KhachHang& KH, string& Ma, string& Ten, string& SDT, string& DTL){ 
	Ma = KH.getMaKhachHang(); 
	Ten = KH.getTenKhachHang(); 
	SDT = KH.getSoDienThoai(); 
	DTL = to_string(KH.getDiemTichLuy()); 
}

void XuatfileKH(KhachHang KH[], int& M, string filename){ 
	fstream f;
	string Ma, Ten, SDT, DTL; 
 	f.open(filename, ios::out); 
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	f << "STT\tMa khach hang\tTen khach hang\tSDT\tDiem tich luy" <<endl;
	for (int i = 0; i < M; i++){ 
 	Xuatfile1KH(KH[i], Ma, Ten, SDT, DTL); 
 	f << i + 1 << "\t" << Ma << "\t" << Ten << "\t" << SDT <<"\t" << DTL << endl; 
 	} 
 	f.close(); 
} 

//Xuất bill 
void Xuatfile1BILL(HangHoa& BILL, string& Ma, string& Ten, string& Gia, string& SL, string& Donvi, string& Ngaynhap, string& TTP){ 
	Ma = BILL.getMaHangHoa(); 
	Ten = BILL.getTenHangHoa(); 
	Gia = to_string(BILL.getGia()); 
	SL = to_string(BILL.getSoLuong());
	Donvi = BILL.getDonVi(); 
	Ngaynhap = BILL.getNgayNhap(); 
	TTP = to_string(BILL.TTP); 
}

void XuatfileBILL(HangHoa BILL[],int& found1, int& found2, string filename){ 
	fstream f;
	string Ma, Ten, Gia, SL, Donvi, Ngaynhap, TTP; 
	f.open(filename, ios::out); 
	if (f.fail()) { cout << "Khong the mo file!!!" << endl; return; }
	f << "STT\tMa hang hoa\tTen hang hoa\tGia\tSo luong\tDon vi\tNgay mua hang\tThanh tien" << endl; 
	int count = -1;
	for (int i = found1; i < found2; i++){ 
 		count++; 
 		Xuatfile1BILL(BILL[i], Ma, Ten, Gia, SL, Donvi, Ngaynhap, TTP);
 		f << count + 1 << "\t" << Ma << "\t" << Ten << "\t" << Gia << "\t" << SL << "\t" << Donvi << "\t" << Ngaynhap << "\t" << TTP <<endl;
 	} 
 	f.close(); 
}

#endif