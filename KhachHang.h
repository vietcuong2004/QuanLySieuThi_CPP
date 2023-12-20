#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>

using namespace std;

class KhachHang{
	private: 	
		string TenKhachHang; 
		string SoDienThoai; 	
		string MaKhachHang; 
		int DiemTichLuy; 
	public:
		// Constructor
		KhachHang(); 
		
		// Lấy thông tin của Khách hàng:
		string getTenKhachHang();
		string getSoDienThoai();
		string getMaKhachHang();
		int getDiemTichLuy();
		
		// Sửa thông tin khách hàng:
		void setTenKhachHang(string);
		void setDiemTichLuy(int);
		void setSoDienThoai(string);
		void setMaKhachHang(string);
};

#endif