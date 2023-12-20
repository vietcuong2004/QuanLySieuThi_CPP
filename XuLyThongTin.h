#include "FileData.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <regex>
using namespace std;

////CÁC HÀM NHẬP THÔNG TIN
//1.Thiết lập hàm nhập tay dữ liệu hàng hóa
//sử dụng trong 1 số trường hợp thử nghiệm với 1 vài dữ liệu nhỏ
//Hoặc cập nhật thêm hàng hóa, khách hàng
void NhapTT1HH(HangHoa& HH){
	string temp; 
    int a = 0; 
    SET_COLOR(10); cout << "\nMa hang hoa: "; SET_COLOR(7); 
    string MaHH;
	cin >> MaHH; cin.ignore(); 
	HH.setMaHangHoa(MaHH);
    temp = HH.getMaHangHoa().substr(0, 2); 
    SET_COLOR(10); cout << "\nTen hang hoa: "; SET_COLOR(7);
	string TenHH; 
    getline(cin,TenHH); 
    HH.setTenHangHoa(TenHH);
    SET_COLOR(10); cout << "\nGia san pham: "; SET_COLOR(7); 
    long Gia;
	cin >> Gia; HH.setGia(Gia); 
//dùng cin nhập chuỗi string liên tiếp và getline cho chuỗi có khoảng cách
//và xét đơn vị hay xét ngày như đọc file hàng hóa, khách hàng ở trên
    int t = stoi(temp); 
    switch (t) { 
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
 	SET_COLOR(10); cout << "\nSo luong san pham: "; SET_COLOR(7); 
 	int SoLuong;
	cin >> SoLuong; cin.ignore(); 
	HH.setSoLuong(SoLuong);
	while (true) 
 	{ 
 		SET_COLOR(10); cout << "\nNgay nhap hang: (dd/mm/yyyy) "; 
		SET_COLOR(7); 
		string NgayNhap;
		cin >> NgayNhap; HH.setNgayNhap(NgayNhap); 
 		int a = 0; 
 		Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.getNgayNhap()); 
 		if (a == 0 && HH.thang <= 12){
			break;
		} 
		else BaoLoi("Nhap sai ngay");
 			
    }
    HH.TimeNgaynhap = HH.ngay + HH.nam * 30 + HH.nam * 365;
    while (true) 
 	{ 
 		SET_COLOR(10); cout << "\nHan su dung: (dd/mm/yyyy) "; 
		SET_COLOR(7); 
		string HSD;
		cin >> HSD; HH.setHSD(HSD); 
 		int a = 0; 
 		Phantichngay(HH.ngay, HH.thang, HH.nam, a, HH.getHSD()); 
 		if (a == 0 && HH.thang <= 12) 
 			break; 
 		else BaoLoi("Nhap sai ngay");
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
 		cout << "San pham thu " << (i + 1) << endl;
 		NhapTT1HH(HH[i]); //gọi các mảng hàng hóa hiện có và đưa nó vào hàm nhập 1
 	} 
 	SET_COLOR(3); 
	cout << "\nDa nhap xong!\n"; 
 	kehang(n); //trong tv graphic
	cout << "\n"; 
}

//Hàm nhập 1 khách
void NhapTT1KH(KhachHang& KH, int& pb){
	SET_COLOR(10); cout << "\nMa Khach Hang: "; SET_COLOR(7); 
	string MaKH;
	cin >> MaKH; KH.setMaKhachHang(MaKH); 
 	cin.ignore(); 
 	SET_COLOR(10); cout << "\nTen Khach Hang: "; SET_COLOR(7); 
 	string TenKH;
	getline(cin,TenKH); KH.setTenKhachHang(TenKH); 
 	SET_COLOR(10); cout << "\nSo Dien Thoai: "; SET_COLOR(7);
	string SDT; 
	cin >> SDT; KH.setSoDienThoai(SDT); 
	if (pb == 1){ 
 		SET_COLOR(10); cout << "\nDiem tich luy: "; SET_COLOR(7);
		int DTL; 
		cin >> DTL; cin.ignore(); 
		KH.setDiemTichLuy(DTL);
 	} 
	if (pb == 2){ 
 		KH.setDiemTichLuy(0); 
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
 		SET_COLOR(10); cout << "Chon STT hang hoa can xoa: "; 
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
 		SET_COLOR(10); cout << "Chon STT khach hang can xoa: "; 
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
//Hàm thêm hàng
void ThemHH(HangHoa HH[], int& N){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "Chon STT hang hoa can them: "; 
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N + 1 && i >= 1) 
 			break; 
 	} 
	for (k = N; k >= i; k--){ 
 		HH[k] = HH[k - 1];
 	} 
 	NhapTT1HH(HH[i - 1]); 
} 
//Hàm thêm khách
void ThemKH(KhachHang KH[], int& M, int& pb){ 
	int i, k; 
	while (true){ 
 		SET_COLOR(10); cout << "Chon STT khach hang can them: "; 
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
 		SET_COLOR(10); cout << "Chon STT hang hoa muon chinh sua: "; 
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
 		SET_COLOR(10); cout << "Chon STT khach hang muon chinh sua: ";
		SET_COLOR(7); cin >> i; cout << "\n"; cin.ignore(); 
 		if (i <= N && i >= 1)
 			break;
 	}
 	NhapTT1KH(KH[i - 1], pb);
	cout << "Da cap nhat xong thong tin khach hang\n"; 
}

////CÁC HÀM IN RA THÔNG TIN
//1.Hàm xuất tt 1 hàng
void XuatTT1HH(HangHoa HH){ 
 	SET_COLOR(7); 
	cout << setw(15) << left <<HH.getMaHangHoa(); 
	cout << setw(25) << left << HH.getTenHangHoa();  
	cout << setw(15) << left << HH.getGia();
	cout << setw(15) << left << HH.getSoLuong();
	cout << setw(15) << left << HH.getDonVi();
	cout << setw(20) << left << HH.getNgayNhap();
	cout << setw(20) << left << HH.getHSD() << "\n"; 
} 
//2.Hàm xuất all tt
void XuatTTHH(HangHoa HH[], int& N){
 	SET_COLOR(3); cout << "Thong tin hang hoa: \n"; 
	int n = 140; 
 	kehang(n); 
	cout << "\n"; 
	XuatTTHH_Bar(); 
 	SET_COLOR(7); 
	for (int i = 0; i < N; i++) { 
 		cout << i + 1 << "\t"; //In số thứ tự
 		XuatTT1HH(HH[i]); 
 	} 
	cout << "\n"; 
 	kehang(n); 
	cout << "\n\n\n"; 
} 

//3.Hàm xuất tt 1 KH
void XuatTT1KH(KhachHang& KH) {
	cout << setw(20) << left << KH.getMaKhachHang();
	cout << setw(30) << left <<KH.getTenKhachHang();  
	cout << setw(20) << left << KH.getSoDienThoai();
	cout << setw(15) << left << KH.getDiemTichLuy() << "\n"; 
}
//4.hàm xuất all tt khách 
void XuatTTKH(KhachHang KH[], int& N){ 
 	SET_COLOR(3); 
	cout << "\nThong tin khach hang: \n";  
	int n = 100; 
 	kehang(n);
	XuatTTKH_Bar();
 	SET_COLOR(7); 
	for (int i = 0; i < N; i++) { 
 		cout << i + 1 << "\t"; //In số thứ tự
 		XuatTT1KH(KH[i]); 
 	} 
	cout << "\n"; 
 	kehang(n); 
 	SET_COLOR(7);
}

//5.Hàm xuất 1 bill
void XuatTT1BILL(HangHoa& BILL) { 
	cout << setw(15) << left << BILL.getMaHangHoa();
	cout << setw(25) << left << BILL.getTenHangHoa();  
	cout << setw(15) << left << BILL.getGia(); 
	cout << setw(15) << left << BILL.getSoLuong();
	cout << setw(15) << left << BILL.getDonVi();
	cout << setw(20) << left << BILL.getNgayNhap();
	cout << setw(15) << left << BILL.TTP << "\n"; 
} 

//6.Hàm xuất tt all bill
void XuatTTBILL(HangHoa BILL[], int& M, int& N) {
	int n = 140; 
	int k = 0; 
 	kehang(n); 
 	XuatTTBILL_Bar();
 	SET_COLOR(7); 
	for (int i = M; i < N; i++){ 
 		cout << k + 1 << "\t"; 
 		XuatTT1BILL(BILL[i]); 
 		k++;
 	} 
	cout << "\n"; 
 	kehang(n); 
 	SET_COLOR(7); 
}



////CÁC HÀM SẮP XẾP:
//1. Sắp xếp theo mã hàng
bool compareMaHang(HangHoa a, HangHoa b) {
    return a.getMaHangHoa() < b.getMaHangHoa();
}

void SapxeptheoMaHH(HangHoa HH[], int& N){ 
	sort(HH,HH+N,compareMaHang);
}

//2. theo tên hàng
bool compareTenHang(HangHoa a, HangHoa b) {
    return a.getTenHangHoa() < b.getTenHangHoa();
}

void SapxeptheoTenHH(HangHoa HH[], int& N){ 
	sort(HH,HH+N,compareTenHang);
}

//3.theo giá hàng
bool compareGia(HangHoa a, HangHoa b) {
    return a.getGia() < b.getGia();
}

void SapxeptheoGiaHH(HangHoa HH[], int& N){ 
	sort(HH,HH+N,compareGia);
}

//4.theo số lượng hàng
bool compareSoLuong(HangHoa a, HangHoa b) {
    return a.getSoLuong() < b.getSoLuong();
}

void SapxeptheoSoluongHH(HangHoa HH[], int& N){ 
	sort(HH,HH+N,compareSoLuong);
}

//5.theo ngày nhập
bool compareNgayNhap(HangHoa a, HangHoa b) {
    return a.TimeNgaynhap < b.TimeNgaynhap;
}

void SapxeptheoNgaynhapHH(HangHoa HH[], int& N){ 
	sort(HH,HH+N,compareNgayNhap);
} 

//6.theo hạn sử dụng hàng
bool compareHSD(HangHoa a, HangHoa b) {
    return a.TimeHSD < b.TimeHSD;
}

void SapxeptheoHSDHH(HangHoa HH[], int& N){ 
	sort(HH,HH+N,compareHSD);
} 

//7.theo mã khách
bool compareMaKhachHang(KhachHang a, KhachHang b) {
    return a.getMaKhachHang() < b.getMaKhachHang();
}

void SapxeptheoMaKH(KhachHang KH[], int& M){  
	sort(KH, KH + M, compareMaKhachHang);
}

//8. theo tên khách
bool compareTenKhachHang(KhachHang a, KhachHang b) {
    return a.getTenKhachHang() < b.getTenKhachHang();
}

void SapxeptheoTenKH(KhachHang KH[], int& M){ 
	sort(KH, KH + M, compareTenKhachHang); 
}

//9. theo sdt:
bool compareSdtKhachHang(KhachHang a, KhachHang b) {
    return a.getSoDienThoai() < b.getSoDienThoai();
}

void SapxeptheoSDT(KhachHang KH[], int &M){
	sort(KH, KH + M, compareSdtKhachHang);
}


////CÁC HÀM TÌM KIẾM THÔNG TIN
//Dùng BINARY SEARCH
//Tạo 1 biến found để thể hiện số phần tử có chuỗi giống với chuỗi cần tìm
//dùng hàm find để tìm, return >=0 thì lưu tt vào mảng khách đã tạo và ++ biến found

//1. Tìm kiếm theo mã hàng
void TimKiemTheoMaHH(HangHoa HH[], string Ma, int N) {
    // Sắp xếp mảng KH theo mã khách hàng
  	SapxeptheoMaHH(HH,N);
    int left = 0;
    int right = N - 1;
    int found = 0;
    HangHoa TKHH[50]; // Số lượng phần tử tối đa trong TKKH
	regex IdStock(Ma);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string MaHH = HH[mid].getMaHangHoa();
        if (regex_search(MaHH,IdStock)){
			// Nếu tìm thấy, lưu vào mảng TKKH và cập nhật found
            TKHH[found] = HH[mid];
            found++;
        }
        // Điều chỉnh chỉ số left hoặc right dựa trên kết quả so sánh
        if (MaHH < Ma) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Xuất thông tin khách hàng tìm được
    XuatTTHH(TKHH, found);
}

//2.Theo tên hàng
void TimKiemTheoTenHH(HangHoa HH[], string Ten, int N) {
    // Sắp xếp mảng KH theo tên khách hàng
	SapxeptheoTenHH(HH,N);
    
    int found = 0;
    HangHoa TKHH[50]; 
  	regex NameStock(Ten, regex_constants::icase); // icase: không phân biệt chữ hoa thường
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        string TenHH = HH[mid].getTenHangHoa();
        // Sử dụng regex_search để kiểm tra xem Ten có tồn tại trong TenHH không
        if (regex_search(TenHH, NameStock)) {
            // Nếu tìm thấy, lưu vào mảng TKKH và cập nhật found
            TKHH[found] = HH[mid];
            found++;
        }
        // Điều chỉnh chỉ số left hoặc right dựa trên kết quả so sánh
        if (TenHH < Ten) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Xuất thông tin khách hàng tìm được
    XuatTTHH(TKHH, found);
}

//3. Theo mã khách
void TimKiemTheoMaKH(KhachHang KH[], string Ma, int M) {
    // Sắp xếp mảng KH theo mã khách hàng
  	SapxeptheoMaKH(KH,M);
    int left = 0;
    int right = M - 1;
    int found = 0;
    KhachHang TKKH[50]; // Số lượng phần tử tối đa trong TKKH
	regex IdCustom(Ma);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string MaKH = KH[mid].getMaKhachHang();
        if (regex_search(MaKH,IdCustom)){
			// Nếu tìm thấy, lưu vào mảng TKKH và cập nhật found
            TKKH[found] = KH[mid];
            found++;
        }
        // Điều chỉnh chỉ số left hoặc right dựa trên kết quả so sánh
        if (MaKH < Ma) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Xuất thông tin khách hàng tìm được
    XuatTTKH(TKKH, found);
}


//4.Theo tên khách
//void TimKiemTheoTenKH(KhachHang KH[], string Ten, int M) {
//    // Sắp xếp mảng KH theo tên khách hàng
//	SapxeptheoTenKH(KH,M);
//    
//    int found = 0;
//    KhachHang TKKH[50]; // Số lượng phần tử tối đa trong TKKH
//  	regex NameCustom(Ten, regex_constants::icase); // icase: không phân biệt chữ hoa thường
//    int left = 0;
//    int right = M - 1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        string TenKH = KH[mid].getTenKhachHang();
//        // Sử dụng regex_search để kiểm tra xem Ten có tồn tại trong TenKH không
//        if (regex_search(TenKH, NameCustom)) {
//            // Nếu tìm thấy, lưu vào mảng TKKH và cập nhật found
//            TKKH[found] = KH[mid];
//            found++;
//        }
//        // Điều chỉnh chỉ số left hoặc right dựa trên kết quả so sánh
//        if (TenKH < Ten) {
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//    // Xuất thông tin khách hàng tìm được
//    XuatTTKH(TKKH, found);
//}

void TimKiemTheoTenKH(KhachHang KH[], std::string Ten, int M) {
    regex NameCustom(Ten,regex_constants::icase); // icase: không phân biệt chữ hoa thường
    int found = 0;
    KhachHang TKKH[50]; // Số lượng phần tử tối đa trong TKKH

    for (int i = 0; i < M; ++i) {
        string TenKH = KH[i].getTenKhachHang();
        if (regex_search(TenKH, NameCustom)) {
            TKKH[found] = KH[i];
            found++;
        }
    }
    // Xuất thông tin khách hàng tìm được
    XuatTTKH(TKKH, found);
}

//5.Theo SDT khách
void TimKiemTheoSDTKH(KhachHang KH[], string SDT, int M) {
    // Sắp xếp mảng KH theo mã khách hàng
    SapxeptheoSDT(KH,M);
    int left = 0;
    int right = M - 1;
    int found = 0;
    KhachHang TKKH[50]; // Số lượng phần tử tối đa trong TKKH
	regex PhoneNumber(SDT);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string SDT_KH = KH[mid].getSoDienThoai();
        if (regex_search(SDT_KH,PhoneNumber)){
			// Nếu tìm thấy, lưu vào mảng TKKH và cập nhật found
            TKKH[found] = KH[mid];
            found++;
        }
        // Điều chỉnh chỉ số left hoặc right dựa trên kết quả so sánh
        if (SDT_KH < SDT) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Xuất thông tin khách hàng tìm được
    XuatTTKH(TKKH, found);
}


//MUA BÁN VÀ THANH TOÁN
//Các hàm liên quan

void Soluongkho(HangHoa& HH, int sl,int& checksl){ 
	if(HH.getSoLuong() >= sl){ 
 		checksl = 0;
 		int tmp = HH.getSoLuong() - sl;
 		HH.setSoLuong(tmp); 
 	} 
	else
 		checksl = 1;
}

void Soluongbill(HangHoa& BILL, float sl) 
{ 
	BILL.setSoLuong(sl); 
} 

void Tienthanhphan(HangHoa& BILL, string Ngaybill) 
{ 	
	BILL.TTP = (int)BILL.getSoLuong() * BILL.getGia(); 
	string tmp = Ngaybill.substr(0, 10);
	BILL.setNgayNhap(tmp); 
}

long TienTong(HangHoa BILL) 
{ 
	return BILL.TTP; 
} 

void thanhtoan(HangHoa BILL[], HangHoa HH[], KhachHang KH[], KhachHang KHB[], int& N, int& found1, int& found2, int y, int& z, long Tong[50], int& M, string Ngaybill, int& norcn) 
{ 
	while (true){ 
		string Masp; 
		SET_COLOR(10); 
		cout << "\nNhap ma san pham: "; 
		SET_COLOR(7); 
		cin >> Masp; 
		if ((Masp == "Q") || (Masp == "q"))
 			break; 
 		else{ 
	 		string MaHHB; 
 			int a = -1;
			for (int i = 0; i < N; i++) { 
 				MaHHB = HH[i].getMaHangHoa(); 
 				int sr = MaHHB.find(Masp); 
 				if (sr >= 0) { 
 					BILL[found2] = HH[i]; 
 					found2++; 
 					a = i; 
 				} 
 			} 
 			if (a < 0){ 
				SET_COLOR(4); 
				cout << "\nKhong tim thay san pham!!\n"; 
				SET_COLOR(7); 
 			} 
 			else{ 
 				int sl = 0; 
 				int checksl = 0; 
				y++;
 				while (true){ 
					SET_COLOR(10); 
					cout << "\nNhap so luong san pham: "; 
					SET_COLOR(7); 
					cin >> sl; cin.ignore(); 
					Soluongkho(HH[a], sl, checksl); 
					if (checksl == 0){ 
 						break; 
 					} 
 				} 
				Soluongbill(BILL[found2 - 1], sl); 
				Tienthanhphan(BILL[found2 - 1], Ngaybill);
				XuatTTBILL(BILL, found1, found2);
 			} 
 		} 
 	}
 	if (y > 0){ 
		z++;
		string yn; 
		Tong[z] = 0; 
		SET_COLOR(3); 
		cout << "\n\n\n\nHOA DON KHACH HANG: \n"; 
		XuatTTBILL(BILL, found1, found2);
		for (int i = found1; i < found2; i++) 
 			Tong[z] = Tong[z] + TienTong(BILL[i]);
 		SET_COLOR(4);
 		cout << "\nThanh tien: " << Tong[z] << "\n"; 
 		SET_COLOR(7);
 		while (true){ 
			SET_COLOR(3); 
			cout << "Ban co the thanh vien chua? (y/n) "; 
			SET_COLOR(7); 
			cin >> yn; 
			if (yn == "y" || yn == "n" || yn == "Y" || yn == "N") 
				break; 
		}
		if (yn == "n" || yn == "N"){ 
 			while (true){ 
				SET_COLOR(3); 
				cout << "Ban co muon tao the thanh vien khong? (y/n) "; 
				SET_COLOR(7); 
				cin >> yn; 
 				if (yn == "y" || yn == "n" || yn == "Y" || yn =="N") 
 					break; 
 			} 
 			if (yn == "y" || yn == "Y"){ 
				M++;
				NhapTT1KH(KH[M - 1], norcn);
//			 	KH[M - 1].getDiemTichLuy() = Tong[z] / 100; 
				KH[M-1].setDiemTichLuy(Tong[z]/100);
 			} 
 		} 
 		else{ 
			string Makh; 
			SET_COLOR(10); 
			cout << "\nNhap ma khach hang: "; 
			SET_COLOR(7); 
			cin >> Makh; 
			string MakhB; 
			int found = 0; 
			int a = -1;
			for (int i = 0; i < M; i++){ 
				MakhB = KH[i].getMaKhachHang(); 
				int sr = MakhB.find(Makh); 
				if (sr >= 0){
					KHB[found] = KH[i];
					found++; 
					a = i; 
				}
			}
			if (a < 0){ 
				SET_COLOR(4); 
				cout << "\nKhong tim thay san pham!!\n"; 
				SET_COLOR(7); 
 			} 
 			else{
 				XuatTTKH(KHB, found); 
 				if (KHB[found - 1].getDiemTichLuy() >= 1000){ 
 					while (true){ 
						string yn; 
						cin.ignore(); 
						SET_COLOR(3); 
						cout << "\nBan co muon dung diem tich luy khong? (y/n) "; 
						SET_COLOR(7); 
						cin >> yn; 
 						if (yn == "y" || yn == "n" || yn =="Y" || yn == "N") 
							break; 
 					} 
 					if (yn == "n" || yn == "N"){ 
 						int tmp1 = KHB[found - 1].getDiemTichLuy() + Tong[z] / 100; 
 						KHB[found - 1].setDiemTichLuy(tmp1);
 						int tmp2 = KHB[found - 1].getDiemTichLuy();
 						KH[a].setDiemTichLuy(tmp2); 
 						XuatTTKH(KHB, found); 
 					} 
 					else{ 
 						int n = KHB[found - 1].getDiemTichLuy() / 1000;
 						int tmp1 = KHB[found - 1].getDiemTichLuy() - n * 1000;
 						KHB[found - 1].setDiemTichLuy(tmp1);
						int tmp2 = KHB[found - 1].getDiemTichLuy() + Tong[z] / 100;  
 						KHB[found - 1].setDiemTichLuy(tmp2); 
 						SET_COLOR(3); 
 						cout << "\n\n\n\nHOA DON KHACH HANG: \n"; 
						XuatTTBILL(BILL, found1, found2);
						SET_COLOR(4); 
						cout << "\nThanh tien: " << Tong[z] - n * 1000 << "\n"; 
 						SET_COLOR(7); 
 						int tmp3 = KHB[found - 1].getDiemTichLuy();
 						KH[a].setDiemTichLuy(tmp3);
						XuatTTKH(KHB, found); 
					}
				}
				else{ 
					int tmp4 = KHB[found - 1].getDiemTichLuy() + Tong[z] / 100;
 					KHB[found - 1].setDiemTichLuy(tmp4);
					int tmp5 = KHB[found - 1].getDiemTichLuy();   
 					KH[a].setDiemTichLuy(tmp5); 
 					XuatTTKH(KHB, found); 
 				} 
 			} 
 		} 
 	} 
}
