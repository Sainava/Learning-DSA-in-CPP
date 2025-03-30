#include<iostream>
#include<string>


using namespace std;

class Hero{
    private:
        char level;
        int health;
       

    
        
    
    public:
        char * name;
        static int time;
    Hero(){
        // health=69;
        // level='Z';
        cout << "Default constructor called" << endl;
        name=new char[100];
    }
    Hero(int health ){
       cout << "this -> "<< this << endl;
       this->health=health;
    }
    Hero(char level){
        this->level=level;
    }
    Hero(int health,char level){    
        this->health=health;
        this->level=level;
    }

    Hero(Hero &temp){
        char *ch=new char(strlen(name)+1);
        strcpy(ch,temp.name);
        this->name=ch;
        cout << "Copy constructor called" << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }
    

        int  gethealth(){
            return health;
        }

        char getlevel(){
            return level;
        }

        void sethealth(int h){
            health=h;
        }

        void setlevel(char l){
            level=l;    
        }

        void setname(char name[]){
            strcpy(this->name,name);
        }

        void print(){
            cout <<endl;
            cout << "[ Name: "<< this->name <<" ";
            cout << "HEALTH  : "<< this->health<<" ";
            cout<< "Level: "<< this->level<<" ]";
            cout << endl;
        }

    ~Hero(){
        cout << "Destructor called" << endl;
        
    }
 
  
};

int Hero::time=0;


int main(){

        cout <<Hero:: time <<endl;

        Hero a ;
           a.time=10;
        cout <<a.time<< endl;
     

        Hero b;
        Hero::time=20;
        cout <<b.time<< endl;








    // //static 
    // Hero a;

    // //dynamic
    // Hero *b=new Hero();
    // //Manually call destructor
    // delete b;




    // cout <<"Before: "<<endl;
    // Hero hero1;
    // hero1.sethealth(69);
    // hero1.setlevel('S');
    // char name[7]="Batman";
    // hero1.setname(name);
    // hero1.print();

    // Hero herop2(hero1);
    // herop2.print();

    // cout << "After: "<<endl;
    // hero1.name[0]='S';
    // hero1.print();
    // herop2.print();



    // Hero R(56);
    // R.print();

    // Hero S(R);
    // S.print();



        // Hero h1('p');
        // cout << "HEALTH  : "<< h1.gethealth()<<endl;
        // cout<<"Level: "<< h1.getlevel()<<endl;
        // cout <<"Address of h1 "<< &h1 << endl;



    // Hero *a=new Hero;
    // (*a).sethealth(100);
    // a->setlevel('A');

    // cout<< "HEALTH  : "<< (*a).gethealth()<<endl;
    // cout<< "Level: "<< a->getlevel()<<endl;


    
    // Hero h1;   
    // h1.sethealth(70);
    // h1.setlevel('A');
   
    // cout<< "HEALTH  : "<< h1.gethealth()<<endl;
    // cout<< "Level: "<< h1.getlevel()<<endl;
    // cout << "The size of the object is : " << sizeof(h1) << endl;

}