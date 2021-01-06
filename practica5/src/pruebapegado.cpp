/*
  Orden para ejecutar:
  ./bin/pruebapegado ./datos/imagenes/banderas/espana_reshigh.ppm ./datos/imagenes/aviones/avion2.ppm ./datos/imagenes/aviones/mascara_avion2.pgm ./espana_avion2_blending.ppm 0 0 1
 */

#include "imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// tipo: 0 opaco, 1 blending
// If imagen de fondo
// Ir imagen resultante
// I2 imagen a pegar
Imagen Pega(const Imagen &If, const Imagen &I2, const Imagen &mascara, int posi, int posj, int tipopegado){
	Imagen Ir = If;

	for (int i = 0; i < If.num_filas(); i++)
		for (int j = 0; j < If.num_cols(); j++)
			if (i+posi >= 0 && i+posi < Ir.num_filas() && j+posj >= 0 && j+posj < Ir.num_cols()){
				if (mascara(i,j).transp != 0){
					if (tipopegado == 0)
						Ir(i+posi, j+posj) = I2(i,j);
					else{
						Ir(i+posi, j+posj).r = (Ir(i+posi, j+posj).r + I2(i+posi, j+posj).r)/2;
						Ir(i+posi, j+posj).g = (Ir(i+posi, j+posj).g + I2(i+posi, j+posj).g)/2;
						Ir(i+posi, j+posj).b = (Ir(i+posi, j+posj).b + I2(i+posi, j+posj).b)/2;
					}
				}
			}

	return Ir;
};

int main(int argc, char * argv[]){
  if (argc!=8){
    cout<<"Los parametros son :" << endl;
    cout<<"1.-La imagen de fondo" << endl;
    cout<<"2.-La imagen a pegar" << endl;
    cout<<"3.-La máscara de la imagen a pegar" << endl;
    cout<<"4.-El nombre de la imagen de salida" << endl;
    cout<<"5.-La fila donde pegar" << endl;
    cout<<"6.-La columna donde pegar" << endl;
    cout<<"7.- 0: Pegado Opaco 1: Pegado Blending" << endl;
    return 0;
  }
  Imagen I,Ip;
  I.LeerImagen(argv[1]);
  Ip.LeerImagen(argv[2],argv[3]);
  int i,j;
  i=atoi(argv[5]); j=atoi(argv[6]);

  Tipo_Pegado tp=OPACO; //variable de tipo Tipo_Pegado que es un enumerado con los valores OPACO y 	BLENDING
  int au= atoi(argv[7]);
  if (au!=0)
    tp=BLENDING;


  I.PutImagen(i,j,Ip,tp);
  I.EscribirImagen(argv[4]);

}
