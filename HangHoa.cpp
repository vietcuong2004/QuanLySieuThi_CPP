#include "HangHoa.h"

//Constructor:
HangHoa::HangHoa(){
	this->MaHangHoa = "Unknown"; 
	this->TenHangHoa = "Unknown"; 
	this->Gia = 0; 
	this->SoLuong = 0; 
	this->DonVi = "Unknown"; 
	this->NgayNhap = "Unknown"; 
	this->HSD = "Unknown"; 
	this->ngay = 0; 
	this->thang = 0; 
	this->nam = 0;	
	this->TimeNgaynhap = 0; 
	this->TimeHSD = 0; 
	this->TTP = 0;
}

// Lấy thông tin hàng hóa:
string HangHoa::getMaHangHoa(){
	return this->MaHangHoa;
}

string HangHoa::getTenHangHoa(){
	return this->TenHangHoa;
}

long HangHoa::getGia(){
	return this->Gia;
}

int HangHoa::getSoLuong(){
	return this->SoLuong;
}

string HangHoa::getDonVi(){
	return this->DonVi;
}

string HangHoa::getNgayNhap(){
	return this->NgayNhap;
}

string HangHoa::getHSD(){
	return this->HSD;
}

// Sửa thông tin hàng hóa:
void HangHoa::setMaHangHoa(string MaHH){
	this->MaHangHoa = MaHH;
}

void HangHoa::setTenHangHoa(string TenHH){
	this->TenHangHoa = TenHH;
}

void HangHoa::setGia(long Gia){
	this->Gia = Gia;
}

void HangHoa::setSoLuong(int SoLuong){
	this->SoLuong = SoLuong;
}

void HangHoa::setDonVi(string DonVi){
	this->DonVi = DonVi;
}

void HangHoa::setNgayNhap(string NgayNhap){
	this->NgayNhap = NgayNhap;
}
void HangHoa::setHSD(string HSD){
	this->HSD = HSD;
}