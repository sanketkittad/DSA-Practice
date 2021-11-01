#include<iostream>
class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle();
        Rectangle(int l,int b);
        int area();
        int perimeter();
        int getlength();
        void setlength(int l);
        ~Rectangle();
};
Rectangle::Rectangle(){
    length=1;
    breadth=1;
}
Rectangle::Rectangle(int l,int b){
    length=l;
    breadth=b;
}
int Rectangle::area(){
    return length*breadth;
}
int Rectangle::perimeter(){
    return 2*(length+breadth);
}
int Rectangle::getlength(){
    return length;
}
void Rectangle::setlength(int l){
    length=l;
}
Rectangle::~Rectangle(){

}
int main(){
    Rectangle r(void);
    Rectangle k(10,5);
    std::cout<<"Area k: "<<k.area()<<" Perimeter k: "<<k.perimeter()<<'\n';
    std::cout<<k.getlength()<<'\n';
    k.setlength(20);
    std::cout<<"Area k: "<<k.area()<<" Perimeter k: "<<k.perimeter()<<'\n';
    
    return 0;
}