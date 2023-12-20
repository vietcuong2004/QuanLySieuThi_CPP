#include "FileData.h"
#include "Graphic.h"
#include <string>

//1.Thiết lập hàm nhập tay dữ liệu hàng hóa
//sử dụng trong 1 số trường hợp thử nghiệm với 1 vài dữ liệu nhỏ
//Hoặc cập nhật thêm hàng hóa, khách hàng
void NhapTT1HH(HangHoa& HH){
	string temp; 
    int a = 0; 
    SET_COLOR(10); cout << "\nMa hang hoa: "; SET_COLOR(7); cin >> HH.Ma; cin.ignore(); 
    temp = HH.Ma.substr(0, 2); 
    SET_COLOR(10); cout << "\nTen hang hoa: "; SET_COLOR(7); 
    getline(cin, HH.Ten); 
    SET_COLOR(10); cout << "\nGia san pham: "; SET_COLOR(7); cin >> HH.Gia; 
//dùng cin nhập chuỗi string liên tiếp và getline cho chuỗi có khoảng cách
//và xét đơn vị hay xét ngày như đọc file hàng hóa, khách hàng ở trên
    int t = stoi(temp); 
    switch (t) 
    { 
	case 21:
	    HH.Donvi = "Kg"; 
	 	break; 
	case 22:
	 	HH.Donvi = "Cai"; 
	 	break; 
	case 10:
	 	HH.Donvi = "Hop"; 
	 	break; 
	case 11:
	 	HH.Donvi = "Chai"; 
	 	break; 
	case 20:
	 	HH.Donvi = "Thung"; 
	 	break; 
	default: 
	 	HH.Donvi = "San Pham"; 
	 	break; 
 	} 
 	SET_COLOR(10); cout << "\nSo luong san pham: "; SET_COLOR(7); cin >> HH.SL; cin.ignore(); 
	while (true) 
 	{ 
 		SET_COLOR(10); cout << "\nNgay nhap hang: (dd/mm/yyyy) "; 
		SET_COLOR(7); cin >> HH.Ngaynhap; 
 		int a = 0; 
 		Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.Ngaynhap); 
 		if (a == 0 && HH.thang <= 12) 
 			break;
    }
    HH.TimeNgaynhap = HH.ngay + HH.nam * 30 + HH.nam * 365;
    while (true) 
 	{ 
 		SET_COLOR(10); cout << "\nHan su dung: (dd/mm/yyyy) "; 
		SET_COLOR(7); cin >> HH.HSD; 
 		int a = 0; 
 		Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.HSD); 
 		if (a == 0 && HH.thang <= 12) 
 			break; 
 	} 
	HH.TimeHSD = HH.ngay + HH.nam * 30 + HH.nam * 365; 
}
//Hàm nhập hết tt hàng
void NhapTTHH(HangHoa HH[], int& N) {
	int n = 50; 
    SET_COLOR(3); 
    cout << "\nNhap thong tin hang hoa\n\n"; cin.ignore(); 
	for (int i = 0; i < N; i++) { 
 		kehang(n); //graphic
 		cout << "\n"; 
 		SET_COLOR(3); 
 		cout << "sam pham thu " << (i + 1) << endl;
 		NhapTT1HH(HH[i]); //gọi các mảng hàng hóa hiện có và đưa nó vào hàm nhập 1
 	} 
 	SET_COLOR(3); 
	cout << "\nDa nhap xong!\n"; 
 	kehang(n); //trong tv graphic
	cout << "\n"; 
}

//Hàm nhập 1 khách
void NhapTT1KH(KhachHang& KH, int& pb){
	SET_COLOR(10); cout << "\nMa Khach Hang: "; SET_COLOR(7); cin >> KH.MaKhachHang; 
 	cin.ignore(); 
 	SET_COLOR(10); cout << "\nTen Khach Hang: "; SET_COLOR(7); 
	getline(cin, KH.getTenKhachHang()); 
 	SET_COLOR(10); cout << "\nSo Dien Thoai: "; SET_COLOR(7); cin >> KH.getSoDienThoai(); 
	if (pb == 1){ 
 		SET_COLOR(10); cout << "\nDiem tich luy: "; SET_COLOR(7); 
		cin >> KH.DiemTichLuy; cin.ignore(); 
 	} 
	if (pb == 2){ 
 		KH.DiemTichLuy = 0; 
 	}
}
//dùng hàm này ở 2 trường hợp, 
//Nếu thêm KH thì cần nhập các tt KH có điểm tích lũy = 0
//Nếu chỉnh sửa khách hàng thì đc nhập điểm tích lũy
//Biến pb để phân biệt 2 TH

//2.Hàm xóa và thêm thông tin
//Hàm xóa hàng
void XoaHH(HangHoa HH[], int& N){ 
	int i, k; 
	while (true) 
 	{ 
 	//Nhập vị trí(số thứ tự) cần xóa
 		SET_COLOR(10); cout << "chon vi tri hang hoa can xoa: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1) 
 			break; 
 	} 
	if (i != N){ 
 		for (k = i - 1; k < N - 1; k++){ 
 			HH[k] = HH[k + 1]; 
 		} 
 	} 
} 
//hàm xóa khách
void XoaKH(KhachHang KH[], int& M){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri khach hang can xoa: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= M && i >= 1) 
 			break; 
 	} 
	if (i != M){ 
 		for (k = i - 1; k < M - 1; k++){ 
 			KH[k] = KH[k + 1]; 
 		} 
 	} 
	cout << "Da xoa thong tin khach hang\n";
}
//Hàng thêm hàng
void ThemHH(HangHoa HH[], int& N){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri thu tu hang hoa can them: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N + 1 && i >= 1) 
 			break; 
 	} 
	for (k = N; k >= i; k--){ 
 		HH[k] = HH[k - 1];
 	} 
 	NhapTT1HH(HH[i - 1]); 
} 
//Hàng thêm khách
void ThemKH(KhachHang KH[], int& M, int& pb){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri thu tu khach hang can them: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= M + 1 && i >= 1) 
 			break; 
 	} 
	if (i != (M + 1)){
		for (k = M; k >= i; k--){ 
 			KH[k] = KH[k - 1];
 		} 
	}
	NhapTT1KH(KH[i-1],pb); // biến pb để pb 2 trường hợp nhập khách hàng
}

//3.Cập nhật thông tin
//Chỉnh sửa tt đã nhập sai hoặc có sự cố cần thay đổi thông tin

//Cập nhật hàng hóa
void CapNhatHH(HangHoa HH[], int& N){ 
	int i;
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri hang hoa muon chinh sua: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1) 
 			break; 
 	} 
 	NhapTT1HH(HH[i - 1]); 
}

//Cập nhật khách hàng
void CapNhatKH(KhachHang KH[], int& N, int& pb) // biến pb để phân biệt 2 trường hợp nhập KH 
{ 
	int i;
	while (true){ 
 		SET_COLOR(10); cout << "chon vi tri khach hang muon chinh sua: ";
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1)
 			break;
 	}
 	NhapTT1KH(KH[i - 1], pb);
	cout << "Da cap nhat xong thong tin khach hang\n"; 
}

