#include "KhachHang.h"

// Constructor
KhachHang::KhachHang(){
	TenKhachHang = "Unknown";
	SoDienThoai = "Unknown";
}

// Lấy thông tin khách:
string KhachHang::getTenKhachHang(){
	return this->TenKhachHang;
}

string KhachHang::getSoDienThoai(){
	return this->SoDienThoai;
}

string KhachHang::getMaKhachHang(){
	return this->MaKhachHang;
}

int KhachHang::getDiemTichLuy(){
	return this->DiemTichLuy;
}

// Sửa thông tin khách:
void KhachHang::setDiemTichLuy(int value){
	this->DiemTichLuy = value;
}

void KhachHang::setTenKhachHang(string Ten){
	this->TenKhachHang = Ten;
}

void KhachHang::setSoDienThoai(string SDT){
	this->SoDienThoai = SDT;
}

void KhachHang::setMaKhachHang(string MaKH){
	this->MaKhachHang = MaKH;
}
