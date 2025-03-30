#include<iostream>
#include<cstring>

using namespace std;
class Hero{
    public :
    int health;
    int attack;
    char *name ;
    string power;
    Hero(){
        cout << "Constructor called"<<endl;
        name =new char[100];
    }
    Hero(const Hero &temp){
        cout << "Copy Constructor called"<<endl;
        char * ch=new char[strlen(temp.name)+1];
        //ch=temp.name;
        strcpy(ch,temp.name);
        this->name=ch;
        this->health=temp.health;
        this->attack=temp.attack;
        this->power=temp.power;

    }

    
    void setvalues(char *name,int health,int attack,string power){
        this->health=health;
        this->attack=attack;
        strcpy(this->name,name);
        //this->name=name;
        this->power=power;
    }
    void print(){
        cout <<endl;
        cout << "[ Name : " << name << " ";
        cout << "Health : " << health << " ";
        cout << "power : " << power << " ";
        cout << "Attack : " << attack << " ]"<<endl;
    }
    


};
int main(){
   cout <<"THe size of the class is:"<< sizeof(Hero)<< endl;
   Hero h1;
   char name[70]="Batman";
   h1.setvalues(name,100,20,"Laser Eyes");
    //h1.print();
    //Hero h2(h1);
    Hero h2=h1;
    //h2.print();
    h1.name[0]='S';
    h1.power[0]='Z';
   // h1.print();
   // h2.print();

    // Hero * b=new Hero();
    // b->setvalues("Superman",100,30,"Flying");
    // b->print();
    return 0;
}