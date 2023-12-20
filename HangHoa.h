#ifndef HANGHOA_H
#define HANGHOA_H

#include <iostream>
#include <string>

using namespace std;

class HangHoa{
	private: 
		string MaHangHoa; 
		string TenHangHoa; 
		long Gia; 
		int SoLuong; 
		string DonVi; 
		string NgayNhap; //Nhập theo kiểu string: 12/11/2023
		string HSD; 
	public:
		int ngay, thang, nam; //Dùng để kiểm tra ngày hợp lệ hay không.
		long TimeNgaynhap; // Dùng để sắp xếp hàng hóa theo ngày nhập, tính từ ngày 00/00/0000
		long TimeHSD;  //Dùng để sắp xếp hàng hóa theo hạn sử dụng
		long TTP; // Tiền tổng thành phần từng hàng khi thanh toán
		
		//Constructor
		HangHoa(); 	
		
		// Lấy thông tin hàng hóa:
		string getMaHangHoa();
		string getTenHangHoa();
		long getGia();
		int getSoLuong();
		string getDonVi();
		string getNgayNhap();
		string getHSD();
		
		// Sửa thông tin hàng hóa:
		void setMaHangHoa(string);
		void setTenHangHoa(string);
		void setGia(long);
		void setSoLuong(int);
		void setDonVi(string);
		void setNgayNhap(string);
		void setHSD(string);
};

#endif