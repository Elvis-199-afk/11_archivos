#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
const int MAX=80;

struct tRegistro{
	int codigo;
	char item[MAX];
	double valor;
};

void mostrar(struct tRegistro);


int SIZE=sizeof(tRegistro);
int main(){
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat",ios::in | ios::binary);
	if(archivo.is_open()){
		archivo.read((char *) &registro,SIZE);
		int cuantos=archivo.gcount();
		while(cuantos==SIZE){
			mostrar(registro);
			archivo.read((char *) &registro,SIZE);
			cuantos=archivo.gcount();
		}
	}else{
		cout<<"No se pudo abrir"<<endl;
	}
	archivo.close();
	return 0;
}
void mostrar(struct tRegistro registro){
	cout<<right<<setw(10)<<registro.codigo<<setw(20)<<" - "<<registro.item<<setw(15)<<" - "<<registro.valor<<endl;
}