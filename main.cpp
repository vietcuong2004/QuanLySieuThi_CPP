#include <iostream>
#include "Graphic.h" //Các hàm in ra các khung menu
#include "KhachHang.h"
#include "HangHoa.h"
#include "FileData.h" //Các phương thức thiết lập nên file
#include "XuLyThongTin.h" // Các hàm thiết lập, xử lý thông tin khách hàng, hàng hóa

using namespace std;

int main(){
	// Khai báo các biến
	int N = 0; // Số lượng hàng hóa
	int q; // lựa chọn chức năng
	int M = 0; // Số lượng khách hàng
	int found2 = 0;
	int found1 = 0;
	int z = -1;
	long Tong[50];
	int norcn = 0; //Biến dùng để phân biệt các trường hợp trong code
	HangHoa BILL[100];
	HangHoa HH[100];
	KhachHang KHB[100];
	KhachHang KH[100];
	
	// Thực hiện các chức năng:
	while (true){
		MenuBar();
		SET_COLOR(mau4);
  		cout << "\nNhap muc lua chon: ";
  		SET_COLOR(mau3);
  		cin >> q;
  		cout << "\n";
 		if (q == 0)
			break;
 		switch (q){
 			//1. Tính năng nhập tay thông tin 1 hàng hóa
			case 1:
			{
   				SET_COLOR(mau4);
   				cout << "Nhap so hang hoa: ";
   				SET_COLOR(mau3);
   				cin >> N; cout << "\n";
   				NhapTTHH(HH, N);
   				system("pause");
   				system("cls");
  			}
			break;
 			
 			// 2.Tính năng upload file
			case 2:
			{
				int uf; //Lựa chọn loại upload file
   				MenuUpLoadFile();
   				SET_COLOR(mau4);
   				cout << "\nChon loai file upload: ";
   				SET_COLOR(mau3);
   				cin >> uf; cin.ignore(); 
				string filename;
   				SET_COLOR(mau4);
   				cout << "Nhap filename: ";
   				SET_COLOR(mau3);
   				cin >> filename; cout << "\n";
  
				switch (uf)
   				{
   					case 1: fileHH(HH, N, filename); break; //Upload file hàng hóa
					case 2: fileKH(KH, M, filename); break; // Upload file khách hàng
					case 3: fileLS(BILL, found2, filename); break; // Upload file Lịch sử
					default: BaoLoi("Khong co tinh nang nay"); break;
   				}
   				system("pause");
   				system("cls");
  			}
  			break;
 
 			// 3.Hiển thị thông tin hàng hóa:
			case 3: XuatTTHH(HH, N);
 			system("pause");
   			system("cls");
   			break;
   			
 			// 4.Hiển thị thông tin khách hàng
			case 4: XuatTTKH(KH, M);
			system("pause");
   			system("cls");
			break;
 			
 			// 5.Cập nhật thông tin 1 hàng hóa
			case 5: CapNhatHH(HH, N);
			system("pause");
   			system("cls");
			break;
 			
 			// 6.Cập nhật thông tin 1 khách hàng
			case 6: norcn = 1; CapNhatKH(KH, M, norcn); 
			system("pause");
   			system("cls");
			break;
  			
  			// 7.Xóa 1 hàng hóa:
  			case 7: XoaHH(HH, N); N = N - 1; 
			system("pause");
   			system("cls");  
			break;
			
			// 8.Xóa 1 khách hàng 
			case 8: XoaKH(KH, M); M = M - 1; 
			system("pause");
   			system("cls");
			break;
 			
 			// 9.Thêm 1 Hàng Hóa:
			case 9: ThemHH(HH, N); N = N + 1; 
			system("pause");
   			system("cls");
			break;
 			
 			// 10.Thêm 1 Khách hàng
			case 10: norcn = 2; ThemKH(KH, M, norcn); M = M + 1; 
			SET_COLOR(11); cout << "\nThem khach hang thanh cong!!\n"; SET_COLOR(7);
			system("pause");
   			system("cls");
			break;
 			
 			// 11.Tìm kiếm hàng hóa:
			case 11:
  			{
				int tk; // Chọn loại tìm kiếm
  				MenuTimKiemHangHoa();
   				SET_COLOR(mau4); cout << "\nChon loai tim kiem: ";
   				SET_COLOR(mau3); cin >> tk; cin.ignore();
  
				switch (tk){
					// Tìm kiếm theo mã hàng hóa
					case 1:{
						string strMa;
    					cout << "\nNhap Ma can tim: ";
    					cin >> strMa;
    					TimKiemTheoMaHH(HH, strMa, N);
						break;
   					}
  					// Tìm kiếm theo tên hàng hóa
					case 2:{
    					string strten;
    					cout << "\nNhap Ten can tim: "; 
   						getline(cin, strten);
   						TimKiemTheoTenHH(HH, strten, N);
  						break;
  					}
  					// Thông báo không có tính năng này
					default: BaoLoi("Khong co tinh nang nay"); break;
  				}	
				system("pause");
   				system("cls");		
 			}
			break;

			//Tìm kiếm Khách hàng:
			case 12:{
				int tk;
				MenuTimKiemKhachHang(); 
				SET_COLOR(mau4); cout << "\nChon loai tim kiem: ";
				SET_COLOR(mau3); cin >> tk; cin.ignore();
				switch (tk){
 					// Tìm kiếm theo mã khách:
					case 1:{ 
						string strMa;
   						cout << "\nNhap Ma can tim: "; cin >> strMa;
   						TimKiemTheoMaKH(KH, strMa, M);  
						break;
  					}
					// Tìm kiếm theo tên khách:
					case 2:{
						string strten;
   						cout << "\nNhap Ten can tim: ";
   						getline(cin, strten);
   						TimKiemTheoTenKH(KH, strten, M); 
	     				break;
   					}
  					// Tìm kiếm theo số điện thoại
					case 3:{
						string strsdt;
    					cout << "\nNhap SDT can tim: ";
    					cin >> strsdt;
    					TimKiemTheoSDTKH(KH, strsdt, M);   
						break;
   					} 
   					// Thông báo không có tính năng này
					default: BaoLoi("Khong co tinh nang nay"); break;
   				}
   				system("pause");
   				system("cls");
			}
            break;
 
 			// 13. Sắp xếp hàng hóa
			case 13:{
				int sx;
				MenuSapXepHangHoa();
   				SET_COLOR(mau4); cout << "\nchon loai sap xep: ";
   				SET_COLOR(mau3); cin >> sx;
   				switch (sx){ 
					case 1: SapxeptheoMaHH(HH, N); XuatTTHH(HH, N); break;
					case 2: SapxeptheoTenHH(HH, N); XuatTTHH(HH, N); break;
					case 3: SapxeptheoGiaHH(HH, N); XuatTTHH(HH, N); break;
					case 4: SapxeptheoSoluongHH(HH, N); XuatTTHH(HH, N); break;
 					case 5: SapxeptheoNgaynhapHH(HH, N); XuatTTHH(HH, N); break;
					case 6: SapxeptheoHSDHH(HH, N);XuatTTHH(HH, N); break;
 					default: BaoLoi("Khong co tinh nang nay"); break;
  				}
  				system("pause");
   				system("cls");
 			}
			break;

			//14. Sắp xếp khách hàng
			case 14:{ 
				int sx;
				MenuSapXepKhachHang();
				SET_COLOR(mau4); cout << "\nChon loai sap xep: ";
  				SET_COLOR(mau3); cin >> sx;
  				switch (sx){
					case 1: SapxeptheoMaKH(KH, M); XuatTTKH(KH, M); break;
					case 2: SapxeptheoTenKH(KH, M); XuatTTKH(KH, M);break;
					default: BaoLoi("Khong co tinh nang nay"); break;
   				}
   				system("pause");
   				system("cls");
  			}
			break;
			
			// 15. Thanh toán hóa đơn cho khách 
			case 15:{
   				cin.ignore();
				string Ngaybill;  
				int y, day, month, year;
   				found1 = found2;  
				while (true){   
					char temp[5];
    				SET_COLOR(3); cout << "\nNgay mua hang (dd/mm/yyyy): "; 
					SET_COLOR(7); cin >> Ngaybill;
    				//Kiểm tra xem nhập ngày hợp lệ chưa, nếu đúng thì thoát khỏi vòng lặp nhập ngày
					int a = 0; // a=0 tức là không có lỗi
    				Phantichngay(day, month, year, a, Ngaybill);
    				if (a == 1){
    					BaoLoi("Nhap sai dinh dang ngay thang!");
					}
   					else if (a == 0 && month <= 12){
   						break;
					}
     					
   				}
   				SET_COLOR(12); cout << "Nhan [Q] or [q] de ket thuc mua san pham\n";   
   				y = 0;
   				norcn = 2;
   				thanhtoan(BILL, HH, KH, KHB, N, found1, found2, y, z,Tong, M, Ngaybill, norcn);
				system("pause");
   				system("cls");
  			}
			break;
			
			// Lịch sử các mặt hàng được mua của siêu thị
 			case 16: {  
				int ls;
				MenuLichSu();
				SET_COLOR(mau4); cout << "\nMoi chon muc: ";
   				SET_COLOR(mau3); cin >> ls; cin.ignore();  
				switch (ls){
					//Hiển thị lịch sử
   					case 1:{
   						int begin = 0;
    					XuatTTBILL(BILL, begin, found2);
   					}
					break;
					//Xóa lịch sử: 
					case 2:{
   						string yn;   
						while (true){
     						SET_COLOR(3);
     						cout<< "Ban co chac muon xoa lich su khong? (y/n) ";
     						SET_COLOR(7); cin >> yn;
    						if (yn == "y" || yn == "n" || yn == "Y" || yn == "N") break;
    					}					
   						if (yn == "y" || yn == "Y"){
   							    found1 = 0;
   							    SET_COLOR(9); cout << "\nDa xoa lich su thanh cong!!!\n";
   								found2 = 0; 
								break;
						   }
						else{
    						SET_COLOR(9); cout << "\nLich su chua duoc xoa!!!\n";
						}
   					}
					break; 
					default: BaoLoi("Khong co tinh nang nay"); break;
   				}
   				system("pause");
   				system("cls");
  			}
			break;
			
			// 17.Xuất file:	
			case 17:{
				int xf;
				MenuXuatFile();
				SET_COLOR(mau4); cout << "\nChon loai xuat file: ";
				SET_COLOR(mau3); cin >> xf; cin.ignore();
				string filename;
  				SET_COLOR(mau4);
  				cout << "Nhap filename: ";
  				SET_COLOR(mau3); cin >> filename; cout << "\n"; 
				switch (xf){ 
					case 1: XuatfileHH(HH, N, filename); break;
 					case 2: XuatfileKH(KH, M, filename); break;
 					case 3: XuatfileBILL(BILL, found1, found2, filename); break;
  					case 4:{  
						int begin = 0;
   						XuatfileBILL(BILL, begin, found2, filename);
  					}
						break; 
					default: BaoLoi("Khong co tinh nang nay"); break;
  				}
  				system("pause");
   				system("cls");
 			}
			break;
		// Hết các tính năng

 		// Chọn sai tính năng, chương trình không có
		default: BaoLoi("Khong co tinh nang nay"); 
		system("pause");
   		system("cls");
		break;
  		}
 	}

	return 0;
}