#include <iostream>
#include <string>

//CLASS và OBJECT 
//CLASS là khái niệm chung chung
//OBJECT là cái cụ thể của định nghĩa
//Ví dụ class: Phụ nữ thì object là: cô giáo Thảo, Emi Fukada,...
//Ví dụ class: Đồ chơi thì object là: còng tay, roi da,...

class Phu_nu
{

// Dữ liệu của class gồm:
// Property: thuộc tính.
// Thuộc tính phải thê hiện được dữ liệu của đối tượng.

// Method: phương thức.
// Là hàm (function).
// Thể hiện hành vi đối tượng.

// Những chỉ định quyền truy cập: Access modifier:
public: // Được phép truy cập từ bên ngoài class.
	std::string ho_ten; // Property
	
	//Explicit (Tường minh) có thể viết tường minh
	// Định nghĩa lại hàm khởi tạo
	Phu_nu() // Không cần khai báo kiểu trả về
	{

	}
	// Contructor: Hàm tạo
	// Có thể khởi tạo giá trị mặc định 
	// Khi đó không cần truyền tham số bên dưới
	// Nếu có truyền bên dưới thì sẽ bị thay thế
	// Default parameter: Tham số mặc định
	Phu_nu(std::string ht, bool z) // Ví dụ GTMD: bool = true
	{
		ho_ten = ht;
		con_zin = z;
	}

	// Khai báo nhanh trong C++
	Phu_nu(std::string ht, bool z) 
		:ho_ten(ht), con_zin(z)
	{}

	// Code đạt chuẩn hơn nữa
	Phu_nu(const std::string &ht, bool z) // ht = "Emi Fukada"
//ht = "Emi": copy chuỗi kí tự  **Giảm tốc độ
//&ht = "Emi": sử dụng luôn chuỗi kí tự **dễ thay đổi dữ liệu gốc
// Vì thế cần thêm từ khóa "const"
		:ho_ten(ht), con_zin(z)
	{}
	
	//Destructor (hàm hủy): Được gọi tự động khi hủy đối tượng
	~Phu_nu()
	{
		std::cout << "Chia tay" << ho_ten << std::endl;
	}
	void trang_diem()   // Method
	{

	}

	// Đa hình
	std::string choi_nhac_cu(std::string nhac_cu)
	{
		return "AAAAA";
	}

	void va_zin() // Write
	{
		con_zin = true;
	}

	void show_hang() // Read
	{
		std::cout << ho_ten << " " << (con_zin ? "con zin" : "mat zin") << std::endl;
	}

private: // Chỉ bên trong class được sử dụng.
	bool con_zin;

};

// Tính kế thừa
// Kế thừa toàn bộ của hàm phụ nữ
// Tuy nhiên không kế thừa Contructor, Destructor,...
// Cần định nghĩa lại Contructor,...
class Gai_ngoan : public Phu_nu // Kế thừa public
{
	// Định nghĩa lại hàm đã được định nghĩa// Over writing
	std::string choi_nhac_cu(std::string nhac_cu)
	{
		return "ooooo";
	}
};
class Gai_hu : private Phu_nu // Kế thừa private // phủ private
{
	std::string choi_nhac_cu(std::string nhac_cu)
	{
		return "uuuuu";
	}
};

// private -> protected
// private kế thừa nhưng ko thể truy xuất // bảo vệ tuyệt đối
// protected có thể truy xuất với các class trích xuất

// Đa kế thừa
// kế thừa hình thoi, nên tránh kiểu này
class Banh_beo : public Gai_ngoan, public Gai_hu
{

};

// Kế thừa multi-level inheritance (kế thừa đa mức)
class Gai_di_tour : public Gai_hu
{

};

int main()
{
	// Contructor (hàm khởi tạo) tự động gọi ra khi khởi tạo đối tượng
	// Ví dụ: lệnh "new"
	// Được định nghĩa ngầm định (Implicit)

	Phu_nu thao; // Cấp phát tĩnh.
    
	// Cấp phát động hay dùng hơn.
	Phu_nu* Emi_Fukada = new Phu_nu;
	// Liên quan đến Heap,Stack: phân vùng bộ nhớ ảo.

	//Có thể định nghĩa class trong hàm.
	class Dan_ong
	{

	} *vu = new Dan_ong;

	// Cấu trúc: Oblect->Property
	Emi_Fukada->ho_ten = "Emi Fukada";
	//Emi_Fukada->con_zin = true; //Lỗi.
	// Private không được truy cập và sửa đổi.

	// Cấu trúc: Object->Method
	Emi_Fukada->choi_nhac_cu("ken");

	// Khai báo khi sử dụng Contructor
	Phu_nu* Emi = new Phu_nu("Emi Fukada", true);

	// Hủy object
	delete Emi_Fukada;

	Emi_Fukada->va_zin();
	Emi_Fukada->show_hang();

	Phu_nu* Emi_Fukada = new Gai_hu("Emi", false);
	// thêm từ khóa virtual trước Method: choi_nhac_cu
	return 0;
}