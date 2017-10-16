#include<bits/stdc++.h>
using namespace std;
class khachhang{
	private :
		char hoten[30];
		char diachi[30];
		float chisocu;
		float chisomoi;
	public :
		void nhap();
		void xuat();
		float chiso();
		float sotien();
		char hoten1();
};
void khachhang::nhap(){
	cin.ignore(1);
	cout<<"Nhap ho ten khach hang: ";
	cin.getline(hoten,30);
	cout<<"Nhap dia chi: ";
	cin.getline(diachi,30);
	cout<<"Nhap chi so cu va moi : ";
	cin>>chisocu>>chisomoi;
	cout<<endl;
}
void khachhang::xuat(){
	cout<<"Ten khach hang la: "<<hoten<<endl;
	cout<<"Dia chi: "<<diachi<<endl;
	cout<<"Chi so cu: "<<chisocu<<endl;
	cout<<"Chi so moi: "<<chisomoi<<endl;
}
float khachhang::chiso(){
	return chisocu-chisomoi;
}
float khachhang::sotien(){
	if(chiso()<=100)
		return chiso()*2;
	if(chiso()>100&&chiso()<=200)
		return chiso()*3;
	if(chiso()>200)
		return chiso()*5;
}
char khachhang::hoten1(){
	return hoten[0];
}
int main(){
	khachhang ds[50];
	int n;
	cout<<"Nhap so luong khach hang: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap khach hang thu "<<i+1<<": "<<endl;
		ds[i].nhap();
	}
	float max=ds[0].sotien();
	for(int i=1;i<n;i++)
		if(max<ds[i].sotien())
			max=ds[i].sotien();
	cout<<"Nhung khach hang co so tien phai tra cao nhat: "<<endl;
	for(int i=0;i<n;i++)
		if(max==ds[i].sotien())
			ds[i].xuat();
	khachhang tam;
	for(int i=0;i<n-1;i++)
		for(int j=i;j<n;j++)
			if(ds[i].hoten1()>ds[j].hoten1()){
				tam=ds[i];
				ds[i]=ds[j];
				ds[j]=tam;
			}
	for(int i=0;i<n;i++)
		ds[i].xuat();
	return 0;
}
