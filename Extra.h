#include <iostream>
#include <string>
#include <math.h>
#include "FileData.h"
using namespace std;

// Xác định năm nhuận
int nhuan(int a) { 
	if (a % 400 == 0) 
	 	return 1;
	else
	if ((a % 4 == 0) && (a % 100 != 0)) 
		return 1;
		else
		return 0;
} 

// giá trị của a là dấu hiệu để báo lỗi về ngày trong năm
// a = 0 là không lỗi , có lỗi thì a = 1
// Vì dữ liệu nhập của time là dd/mm/yyyy nên dùng hàm substr để tách lấy dữ liệu 

void Phantichngay(int& day, int& month, int& year, int& a, string Ngay){ 
	// Xem chuỗi nhập vào đã ở dạng ngày tháng năm hay chưa
	// Dùng xử lý ngoại lệ để bắt lỗi invalid_argument khi dùng stoi
	try{
		string temp1, temp2, temp3; 
		temp1 = Ngay.substr(0, 2);
		temp2 = Ngay.substr(3, 2); 
		temp3 = Ngay.substr(6, 4); 
		day = stoi(temp1); 
		month = stoi(temp2); 
		year = stoi(temp3); 
	}
	catch (const std::invalid_argument& e) {
        a = 1; return;
    }
    catch (const std::out_of_range& e) {
        a = 1; return;
    }
    
    // Nếu nhập 18122023 (không có dấu '/') cũng coi là sai định dạng:
    if (Ngay[2] != '/' || Ngay[5] != '/'){
    	a = 1; return;
	}
	
    // Khi đã nhập đúng định dạng ngày tháng rồi thì thực hiện phân tích ngày, tháng:
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) 
		if (day > 31) 
			a = 1; 
		else a = 0; 
	else
	 	if ((month == 2) && (nhuan(year) == 1)) 
	 		if (day > 29) 
	 			a = 1; 
	 		else
	 			a = 0; 
	 	else
	 		if (month == 2) 
	 			if (day > 28) a = 1; 
	 			else a = 0; 
	 	else
	 			if (day > 30) a = 1; 
	 			else a = 0; 
}

// Thông báo lỗi:
void BaoLoi(string ThongBao){
	SET_COLOR(4); cout << "\n[ERROR] ";
	cout << ThongBao << "\n";
	SET_COLOR(7);
}
