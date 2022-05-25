/*Nombre : William Alave Colque              codigo: 200460
Curso : Algoritmos y Estructura de datos
================================================================
1:Calcule la edad de una persona a la fecha, como salida debe exponer la cantidad de años,
meses y días que tiene la persona.
*/
#include<iostream>
#include<ctime>
using namespace std;

int main(){
    int fecha_nac,mes,dia;
    time_t t;
    int anio_actual,mes_actual,dia_actual;
    int mayor;
    bool band = true;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);
    anio_actual = fecha->tm_year+1900;
    mes_actual = fecha->tm_mon+1;
    dia_actual = fecha->tm_mday;
    do{
       cout<<"\nIngrese su anio  de nacimineto  "<<endl;
       cin>>fecha_nac;
       cout<<"Ingrese el  mes  "<<endl;
       cin>>mes;
       cout<<"Ingrese dia "<<endl;
       cin>>dia;
       band = true;
       if(fecha_nac<1900 || fecha_nac>anio_actual || mes< 0|| mes>12||dia<0||dia>31 ){
        cout<<"La fecha es invalida digite  nuevamente ";
        band = false;
       }
    }while(band == false);
    if(band==true){
        if(mes_actual>mes){
            mes  = (mes_actual-mes);
            fecha_nac= (anio_actual)-fecha_nac;

        }else{
            mes = 12+((mes_actual-1)-mes);
            fecha_nac = fecha_nac - (anio_actual-1);
        }
        if(dia_actual>dia){
            dia =31-(dia_actual-dia);
        }else {
            mayor = dia ;
            dia = 31-(mayor -dia_actual);
        }
        cout<<"Usted tiene "<<fecha_nac<<" Anios - "<<mes<<"Meses - y "<<dia<<"Dias ";
    }
    return 0;
}
/*================================================================
2:A través de clases y objetos implementar las diferentes operaciones de fracciones (suma,
resta, multiplicación, división y simplificación), todo esto debe tener un menú para el
manejo de esta calculadora*/

#include<iostream>

using  namespace std;

class operaciones{
    private:
    int a,b;
    public:
        operaciones(int,int);
        void suma();
        void resta();
        void multiplicacion();
        void division();
        void simplificacion();
};
operaciones::operaciones(int _a,int _b){
    a=_a;
    b=_b;
}
void operaciones::suma(){
    cout<<"La suma es "<<a+b;
}
void operaciones::resta(){
    cout<<"La resta es "<<a-b;
}void operaciones::multiplicacion(){
    cout<<"La multiplicacion es "<<a*b;
}
void operaciones::division(){
    cout<<"La division es "<<a/b;
}
void operaciones::simplificacion(){
    while(a%2==0&&b%2==0){
        a/=2;
        b/=2;
    }
    while(a%3==0&&b%3==0){
        a/=3;
        b/=3;
    }
    cout<<"La simplificacion es "<<a<<" / "<<b;
}
int  main(){
    int opc,x,y;
    cout<<"\t Menu"<<endl;
    cout<<"1.- Suma "<<endl;
    cout<<"2.- Resta "<<endl;
    cout<<"3.- Multiplicacion  "<<endl;
    cout<<"4.- Division  "<<endl;
    cout<<"5.- Simplificacion "<<endl;
    cout<<"que  operacion quiere realizar ? "<<endl;
    cin>>opc;
    cout<<"======================="<<endl;
    cout<<"Digite a: "<<endl;
    cin>>x;
    cout<<"Digite b: "<<endl;
    cin>>y;
    operaciones op1 = operaciones(x,y);
    switch(opc){
        case 1 :op1.suma();
        break;
        case 2 :op1.resta();
        break;
        case 3 :op1.multiplicacion();
        break;
        case 4 :op1.division();
        break;
        case 5 :op1.simplificacion();
        break;
        default: break;
    }
    return 0;
}
/*================================================================
3:*/A través del uso de un array implemente la suma, multiplicación, resta y división de números
de 100 dígitos, este debe tener un menú para el manejo de la aplicación.

#include<iostream>
#include<time.h>
using namespace std;

int main(){
    srand(time(NULL));
    int arr1[100],arr2[100],result[101];
    int opc,aux;
    cout<<"\t Menu"<<endl;
    cout<<"1.- Suma "<<endl;
    cout<<"2.- Resta "<<endl;
    cout<<"3.- Multiplicacion  "<<endl;
    cout<<"4.- Division  "<<endl;
    cout<<"5.- Simplificacion "<<endl;
    cout<<"que  operacion quiere realizar ? "<<endl;
    cin>>opc;
    cout<<"nro 1: \n  ";
    for(int i=0;i<100;i++){
      arr1[i]=1+rand()%(9-1+1);
      arr2[i]=1+rand()%(9-1+1);
      cout<<arr1[i];

    }
    cout<<"\nnro 2: \n  ";
    for(int i=0;i<100;i++){
      cout<<arr2[i];
    }
    cout<<"\n=============================="<<endl;
    switch(opc){
        case 1 :{
            for(int i=99;i>=0;i--) {
                aux=arr1[i]+arr2[i];
                result[i]=0;
                if(aux<=9){
                    result[i]+=(arr1[i]+arr2[i]);
                }else{
                    result[i]+=(arr1[i]+arr2[i]);
                    result[i]-=10;

                    arr1[i-1]+=1;
                }
            }
            cout<<"Resultado "<<endl;
            for(int i=0;i<100;i++){
                cout<<result[i];
            }
        };
        break;
        case 2 :{

        }
        break;
        case 3 :;
        break;
        case 4 :;
        break;
        case 5 :;
        break;
        default: break;
    }

    return 0;
}

/*================================================================
4:*/4. Implemente un algoritmo que permita determinar si una cadena de números es Fibonacci o
no, como entrada recibirá la cantidad de números a ingresar, seguidamente ingresará los
números de la serie, y como salida debe emitir un si es o no una serie Fibonacci de acuerdo a
su evaluación

#include<iostream>

using  namespace std;

void Fibonacci(int n);
int  main(){
    int n1;
    cout<<"numeros a generar "<<endl;
    cin>>n1;

    if(n1 >=0){
       Fibonacci(n1);
    }else {
        cout<<"Error no se  puede  generara  numeros  negativos ";
    }
   return 0;
}
void Fibonacci(int n){
    int a=0,b=1,c=1,aux=0;
    int arr1[n],arr2[n];
    //!array  fibonacci que se genera
    arr2[0]=1;
    for(int i=1;i<n;i++){
    c = a+b;
    arr2[i]=c;
    a=b;
    b=c;
    }
    //!pide numeros del  usuario
    for(int i=0;i<n;i++){
      cout<<"\tDigite => "<<endl;
      cin>>arr1[i];
    }
    //!compara  e imprime  los  numeros
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<"->"<<arr2[i]<<"     " ;
    if(arr1[i]!=arr2[i]){
            aux++;
        }
    }
    if(aux>0){
        cout<<"la cadena NO es Fibonacci "<<endl;
    }else{
        cout<<"FIBONACCI";
    }
}
/*========================================================
6:*/Implemente un programa en el que ingrese el tamaño de una matriz y genere una matriz
espiral.
#include<iostream>

using namespace std;

int main(){
    int mat[100][100];
    int n,m;
    cout<<"Ingrese las Filas de  la matriz"<<endl;
    cin>>n;
    cout<<"Ingrese las Columnas de  la matriz"<<endl;
    cin>>m;
    int fil,col,aux,cont,k;
        cont=1;
        for(k=0;k<m;k++)
        {
        col=k;
                for(fil=k;fil<=(m-1-k);fil++)
                {
                mat[fil][col]=cont;
                cont++;
                }
        fil=m-1-k;
                for(col=k+1;col<=n-1-k;col++)
                {
                mat[fil][col]=cont;
                cont++;
                }
        col=n-1-k;
                for(fil=m-2-k;fil>=k;fil--)
                {
                mat[fil][col]=cont;
                cont++;
                }
        fil=k;
                for(col=n-2-k;col>=k+1;col--)
                {
                mat[fil][col]=cont;
                cont++;
                }
        }
        for(int fil=0;fil<m;fil++)
        {
            for(int col=0;col<n;col++)
            {
            cout<<"\t"<<mat[fil][col];
            }
            cout<<endl;
        }
    return 0;
}

