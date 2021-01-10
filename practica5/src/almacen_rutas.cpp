#include "almacen_rutas.h"

void Almacen_Rutas::InsertarRuta(const Ruta &r){
	rutas.emplace( r.getCodigo(), r);
};

Ruta Almacen_Rutas::GetRuta(string code){
	return rutas.at(code);
};

Almacen_Rutas Almacen_Rutas::GetRutas_Con_Punto(Punto p){
	
	Almacen_Rutas rutas_con_p;

	for (map<string,Ruta,less<string>>::iterator it = rutas.begin(); it != rutas.end(); ++it){
		if ( (*it).second.existePunto(p) ){
			rutas_con_p.InsertarRuta( (*it).second );
		}
	}

	return rutas_con_p;
};

Almacen_Rutas& Almacen_Rutas::operator=(const Almacen_Rutas &otro){
	rutas = otro.rutas;
	return *this;
};


ostream & operator<<(ostream & os, const Almacen_Rutas &r){
	for (map<string,Ruta,less<string>>::const_iterator it = r.rutas.cbegin(); it != r.rutas.cend(); ++it)
		os << (*it).second << endl;

	return os;
};

istream & operator>>(istream &is, Almacen_Rutas &r){
	Almacen_Rutas rlocal;
	
	//leemos el comentario
	if (is.peek() == '#'){
		string a;
		getline(is,a);
	}	
	
	Ruta ruta;
		
	while (is >> ruta){
		rlocal.InsertarRuta(ruta);
		ruta = Ruta();
	}

	r = rlocal;
	
	return is;
};
