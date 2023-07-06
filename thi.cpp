#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Medicine{
	public:
		string name; //Ten thuoc
		char *manufacturer; //Nha san xuat
		int py; //Publishing year
		string dosage; //Lieu luong
		string side_effects; //Tác dung phu
		
		//Ham tao
		Medicine(){
			name = "";
			manufacturer = NULL; //Luu ý
			py = 0;
			dosage = "";
			side_effects = "";
		}
		
		//Ham huy
		~Medicine(){
			if(manufacturer != NULL){
				delete[] manufacturer; //Xóa bo nho dem di, vi Chuoi = Mangr kiTu nên khi delete dùng dau []
			}
		}
		
		//Ham tao có tham so
		Medicine(string name, const char *manufacturer, int py, string dosage, string side_effects){ //const: hangSo k duoc thay doi
			this->name = name;
			this->manufacturer = new char[strlen(manufacturer) +1]; //[chua do dai cua chuoi]
			strcpy(this->manufacturer, manufacturer); //Sao chep manufacturer vào this->manufacturer
			
			this->py = py;
			this->dosage = dosage;
			this->side_effects = side_effects;
		}
		
		//Ham copy
    	Medicine(const Medicine& other){
    	    this->name = other.name;
//    	    this->manufacturer = other.manufacturer;

			this->manufacturer = new char[strlen(manufacturer) +1];
			strcpy(this->manufacturer, other.manufacturer);

    	    this->py = other.py;
    	    this->dosage = other.dosage;
    	    this->side_effects = other.side_effects;
    	}
		
		//Toan tu gan
    	Medicine& operator = (Medicine& other){
    	    if(this != &other){
    	        name = other.name;
    	    	manufacturer = other.manufacturer;
    	    	py = other.py;
    	    	dosage = other.dosage;
    	    	side_effects = other.side_effects;
    	    }
    	    return *this;
    	}

    	// Toan tu so sanh ==
    	bool operator == (Medicine& other){
    		return name==other.name && manufacturer==other.manufacturer &&
    				py==other.py && dosage==other.dosage && side_effects==other.side_effects;
    	}
    	
    	//Toan tu nhap
    	friend istream& operator>>(istream& is, Medicine& m){
    		cout<<"Nhap name: "; is>>m.name;
    		
    		cout<<"Nhap manufacturer: ";
    		char manufac[100];
    		is>>manufac;
    		m.manufacturer = new char[strlen(manufac) +1];
			strcpy(m.manufacturer, manufac);
			
    		cout<<"Nhap py: "; is>>m.py;
    		
    		fflush(stdin);
    		cout<<"Nhap dosage: ";
    		getline(is, m.dosage);
    		
    		fflush(stdin);
    		cout<<"Nhap side_effects: ";
    		getline(is, m.side_effects);
    		
    	    return is;
    	}
		
		//Toan tu xuat
    	friend ostream& operator<<(ostream& os, Medicine& m){
    		cout<<"\nNhap name: "; os<<m.name;
    		cout<<"\nNhap manufacturer: "; os<<m.manufacturer;
    		cout<<"\nNhap py: "; os<<m.py;
    		cout<<"\nNhap dosage: "; os<<m.dosage;
    		cout<<"\nNhap side_effects: "; os<<m.side_effects;
    		
    	    return os;
    	}
    	
    	//Ham nhap
    	void Nhap(){
    		cout<<"Nhap name: "; cin>>name;
    		cout<<"Nhap manufacturer: "; cin>>manufacturer;
    		cout<<"Nhap py: "; cin>>py;
    		
    		fflush(stdin);
    		cout<<"Nhap dosage: ";
    		getline(cin, dosage);
    		
    		fflush(stdin);
    		cout<<"Nhap side_effects: ";
    		getline(cin, side_effects);
		}
		
		//Ham xuat
    	void Xuat(){
    		cout<<"Nhap name: "<<name;
    		cout<<"Nhap manufacturer: "<<manufacturer;
    		cout<<"Nhap py: "<<py;
    		cout<<"Nhap dosage: "<<dosage;
    		cout<<"Nhap side_effects: "<<side_effects;
		}
};

int main(){
	Medicine m;
	cin>>m;
	cout<<m;

	return 0;
}

