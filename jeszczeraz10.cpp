#include <iostream>
//#include <string>

using namespace std;

class robot
{
	public:
		virtual void praca() = 0;	
};

class podajnik :public robot
{
	unsigned lp;
public:
	podajnik():lp(0){}
	podajnik(unsigned x):lp(x){}
	void praca()
	{
		cout << "\tPodajnik wykonal prace\n\n";
	}		
};
class operacja 
{
	string co;
	int ile;
	public:
		operacja():co("..."), ile(0){}
		operacja(const string& x, int y):co(x), ile(y){}
		
		friend ostream& operator << (ostream& os, const operacja& r){
			return os << "Operacja: " << r.co << " o " << r.ile	<< " jednostek.\n";
		}	
};
class robotr1 :public robot
{
	unsigned lp;
	unsigned roz;
	operacja * wsk;
public:
	robotr1():lp(0), roz(0), wsk(0){}
	robotr1(unsigned a,const operacja* b,const operacja* c):lp(a), roz(c - b > 0 ? c - b : 0 ), wsk(roz ? new operacja[roz]:0){
		for(unsigned i = 0; i < roz; i++){
				wsk[i] = b[i]; 
			}
		}
	void praca()
    {
    for(unsigned i= 0; i < roz; i++)
    cout << "Lp: " << i << " wykonal prace" << endl;
    
    //    cout << wsk[i];
    }
    friend ostream& operator << (ostream& os, const robotr1& r){
    	for(unsigned i = 0; i < r.roz; i++){
    		os << "Operacja robotr1 " << i <<" "<< r.wsk[i] << endl;
    	
		}
	return os;
	}
}; 

class robotr2 :public robotr1
{
	robotr1 lewy;
	unsigned roz;
	operacja * wsk;
public:
	robotr2():lewy(robotr1()), roz(0), wsk(0){}
	robotr2(unsigned a,const operacja* b,const operacja* c,const operacja* d,const operacja* e):robotr1(a, b, c), roz(e - d > 0 ? e - d : 0 ), wsk(roz ? new operacja[roz]:0){
		for(unsigned i = 0; i < roz; i++){
				wsk[i] = d[i]; 
			}
		}
	void praca() {
    cout << lewy ;
    for(unsigned i=0; i<roz; i++)
    cout<<wsk[i];
  }
}; 
void wykonaj(robot** a, robot** b);
int main()
{
	operacja o[] = { 
		operacja(" w lewo ", 12), operacja(" obrot ", 8), 
		operacja(" w gore ", 32), operacja(" obrot ", 10), 
		operacja(" w prawo ", 5), operacja(" w dol ", 25), 
		operacja(" obrot ", 32), operacja(" w gore ", 21), 
		operacja(" obrot ", 11), operacja(" w prawo ", 6) 
	}; 
	robotr1 b(1,o+3,o+6);
    b.praca();
	robot* linia[] = { 
		new podajnik(0), new robotr1(1, o, o+3), 
		new podajnik(2), new robotr2(3, o+2, o+5, o+3, o+6), 
		new podajnik(4), new robotr2(5, o, o+4, o+2, o+6), 
		new podajnik(6), new robotr1(7, o+7, o+10), 
		new podajnik(8) 
	}; 
	wykonaj(linia, linia+9);
	return 0;
}
void wykonaj(robot** a, robot** b){
    for(unsigned i=0; i<(b-a); i++)
    a[i]->praca();
}
