#include<iostream>
#include<Windows.h>
#include<iomanip>
using namespace std;

int mau1 = 3; // Aqua
int mau2 = 14; // Light yellow
int mau3 = 7; // White
int mau4 = 10; // Red


//0 (Black), 1 (Blue), 2 (Green)
//3 (Aqua), 4 (Red), 5 (Purple),
//6 (Yellow), 7 (White), 8 (Gray), 
//9 (Light Blue), 10 (Light Green), 11 (Light Aqua), 
//12 (Light Red), 13 (Light Purple), 14 (Light Yellow), 15 (Light White). 

// Tạo màu cho Console:
void SET_COLOR(int color){
	
	WORD wColor;
	
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)){
  		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
  		SetConsoleTextAttribute(hStdOut, wColor);
 	}
}

// Kẻ đường thẳng:
void kehang(int& n){
	SET_COLOR(14);
	for (int i = 0; i < n; i++){
  		cout << "_";
 	}
 	cout << "\n";
}

// In ra Menu chính của chương trình
void MenuBar(){ 
 	SET_COLOR(mau1); 
 	cout << "\nCHUONG TRINH QUAN LY SIEU THI\n\n"; 
 	SET_COLOR(mau2); 
 	cout <<"*************************MENU***************************\n"; 
	cout << "**"; SET_COLOR(mau3); 
	cout << " 1. Nhap thong tin hang hoa.                        ";
	SET_COLOR(mau2); cout << "**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 2. Upload file thong tin. 			      "; 
	SET_COLOR(mau2); cout << "**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 3. Hien thi thong tin hang hoa trong sieu thi.     "; 
	SET_COLOR(mau2); cout <<"**\n";		 
 	cout << "**"; SET_COLOR(mau3);		 
	cout << " 4. Hien thi thong tin khach hang trong sieu thi.   "; 
	SET_COLOR(mau2); cout <<"**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 5. Cap nhat thong tin hang hoa. 		      "; 
	SET_COLOR(mau2); cout <<"**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 6. Cap nhat thong tin khach hang. 		      "; 
	SET_COLOR(mau2); cout <<"**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 7. Xoa thong tin hang hoa. 			      "; 
	SET_COLOR(mau2); cout << "**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 8. Xoa thong tin khach hang. 		      "; 
	SET_COLOR(mau2); cout << "**\n";		 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 9. Them mot mat hang.                              "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 10. Them mot khach hang. 	                      "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 11. Tim kiem hang hoa. 			      "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 12. Tim kiem khach hang. 			      "; 
	SET_COLOR(mau2); cout <<"**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 13. Sap xep thong tin hang hoa. 	              "; 
	SET_COLOR(mau2); cout << "**\n"; 
	cout << "**"; SET_COLOR(mau3); 
	cout << " 14. Sap xep thong tin khach hang.                  "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 15. Thanh toan bill khach hang. 		      "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 16. Lich su 					      "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 17. Xuat file 			              "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout << "**"; SET_COLOR(mau3); 
	cout << " 0. Thoat 					      "; 
	SET_COLOR(mau2); cout << "**\n"; 
 	cout <<"********************************************************\n";
}

// In ra Menu Upload File:
void MenuUpLoadFile(){
	SET_COLOR(mau1);
   	cout << "\nLOAI UPLOAD FILE\n";
   	SET_COLOR(mau2);
	cout << "*************************MENU**************************\n";
   	cout << "**"; 
	SET_COLOR(mau3); 
	cout << "  1. Upload file hang hoa.                         ";
	SET_COLOR(mau2); 	cout << "**\n";
   	cout << "**"; SET_COLOR(mau3); cout << "  2. Upload file khach hang.                       ";
   	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; SET_COLOR(mau3); 
	cout << "  3. Upload file lich su mua hang.                 ";
   	SET_COLOR(mau2); 
	cout << "**\n";
	cout << "*******************************************************\n";
}

// In ra Menu Tìm kiếm hàng hóa:
void MenuTimKiemHangHoa(){
	SET_COLOR(mau1); cout << "\nLOAI TIM KIEM\n";
	SET_COLOR(mau2); cout << "*************************MENU**************************\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  1. Tim kiem theo Ma hang hoa.                    ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  2. Tim kiem theo Ten hang hoa.                   ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "*******************************************************\n";
}

// In ra Menu Tìm kiếm khách hàng:
void MenuTimKiemKhachHang(){
	SET_COLOR(mau1); cout << "\nLOAI TIM KIEM\n";
	SET_COLOR(mau2); cout << "*************************MENU**************************\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  1. Tim kiem theo Ma khach hang.                  ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  2. Tim kiem theo Ten khach hang.                 ";
	SET_COLOR(mau2); cout << "**\n";
  	cout << "**"; 
	SET_COLOR(mau3); cout << "  3. Tim kiem theo SDT khach hang.                 ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "*******************************************************\n";
}

// Menu Sắp xếp hàng hóa:
void MenuSapXepHangHoa(){
	SET_COLOR(mau1); cout << "\nLOAI SAP XEP\n";
	SET_COLOR(mau2); cout << "*************************MENU**************************\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  1. Sap xep theo Ma hang hoa.                     ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**";
	SET_COLOR(mau3); cout << "  2. Sap xep theo Ten hang hoa.                    ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  3. Sap xep theo Gia hang hoa.                    ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  4. Sap xep theo So luong hang hoa.               ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  5. Sap xep theo Ngay nhap hang hoa.              ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  6. Sap xep theo HSD hang hoa.                    ";
	SET_COLOR(mau2); cout<< "**\n";
	cout << "*******************************************************\n";
}

// Menu sắp xếp khách hàng:
void MenuSapXepKhachHang(){
	SET_COLOR(mau1); cout << "\nLOAI SAP XEP\n";
	SET_COLOR(mau2); cout << "*************************MENU**************************\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  1. Sap xep theo Ma khach hang.                   ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  2. Sap xep theo Ten khach hang.                  ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "*******************************************************\n";
}

// Menu Xuất file:
void MenuXuatFile(){
	SET_COLOR(mau1); cout << "\nLOAI XUAT FILE\n";
	SET_COLOR(mau2); cout << "*************************MENU**************************\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  1. Xuat file hang hoa.                           ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  2. Xuat file khach hang.                         ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; SET_COLOR(mau3); cout << "  3. Xuat file bill.                               ";
	SET_COLOR(mau2); cout << "**\n"; 
	cout << "**"; 
	SET_COLOR(mau3); cout << "  4. Xuat file lich su mua hang.                   ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "*******************************************************\n";
}

// In Menu Lịch sử:
void MenuLichSu(){
	SET_COLOR(mau1); cout << "\nLICH SU\n";
	SET_COLOR(mau2); cout << "*************************MENU**************************\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  1. Hien thi thong tin lich su.                   ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "**"; 
	SET_COLOR(mau3); cout << "  2. Xoa thong tin lich su.                        ";
	SET_COLOR(mau2); cout << "**\n";
	cout << "*******************************************************\n";
}

//Thanh Xuất thông tin hàng hóa:
void XuatTTHH_Bar(){
	SET_COLOR(3); 
	cout << "\nSTT\t";
	cout << setw(15) << left << "Ma hang hoa" ;
	cout << setw(25) << left  << "Ten san pham";
	cout << setw(15) << left << "Gia";
	cout << setw(15) << left <<  "So luong";
	cout << setw(15) << left << "Don vi";
	cout << setw(20) << left << "Ngay nhap";
	cout << "HSD\n";
}

// Thanh xuất thông tin khách hàng
void XuatTTKH_Bar(){
	SET_COLOR(3); 
	cout << "\n"; 
	cout << "\nSTT\t";
	cout << setw(20) << left << "Ma khach hang";
	cout << setw(30) << left << "Ten khach hang"; 
	cout << setw(20) << left << "So dien thoai";
	cout << "Diem tich luy\n"; 
}

//Thanh xuất thông tin hóa đơn:
void XuatTTBILL_Bar(){
	SET_COLOR(3); 
	cout << "\n"; 
	cout << "\nSTT\t";
	cout << setw(15) << left << "Ma hang hoa";
	cout << setw(25) << left << "Ten san pham";
	cout << setw(15) << left << "Gia";
	cout << setw(15) << left << "So luong";
	cout << setw(15) << left << "Don vi";
	cout << setw(20) << left << "Ngay mua hang";
	cout << "Thanh tien\n"; 
}