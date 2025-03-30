#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(9);
    v.push_back(13);
    v.push_back(7);
    v.push_back(76);

    cout << "searching for 13: " << binary_search(v.begin(),v.end(),13) << endl;

    cout << "Before sorting: "<<endl;
    cout<< "lower bound of 13-->"<< lower_bound(v.begin(),v.end(),13)-v.begin()<<endl;// Lower bound: Returns an iterator pointing to the first element in the range [first, last) that is not less than (i.e., greater than or equal to) the given value.
    cout<< "upper bound of 13-->"<< upper_bound(v.begin(),v.end(),13)-v.begin()<<endl;// upper_bound:Returns an iterator pointing to the first element in the range [first, last) that is greater than the given value.

    cout <<"Sorting is based on intro-sort which is combination of 3 sorts: Quick Sort ,Heap Sort and Insertion Sort";
    sort(v.begin(),v.end());

    cout << "After sorting: "<<endl;
    cout<< "lower bound of 13-->"<< lower_bound(v.begin(),v.end(),13)-v.begin()<<endl;
    cout<< "upper bound of 13-->"<< upper_bound(v.begin(),v.end(),13)-v.begin()<<endl;

    int a=3;
    int b=4;

    cout<< "max-->"<< max(a,b)<<endl;;
    cout<<"min--->"<<min(a,b)<<endl;

    swap(a,b);

    cout<< "value in a-->"<< a<<endl;

    string s="abcd";
    reverse(s.begin(),s.end());
    cout<< "String--->" << s<<endl;

    rotate(v.begin(),v.begin()+1,v.begin()+3);//brings element form position v.begin()+1 to 1 less than v.begin()+3 to the beginning of the vector
    cout<< "After rotate: "<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
}