#include"CVector.h"

int main()
{
    //    Vector<int> v6;
    //    v6.push_back(100);
    //    v6.push_back(102);
    //    v6.push_back(102);
    //    v6.pop_back();
    //    v6.pop_back();
    //    v6.pop_back();
    //    v6.pop_back();
    //    cout<<" front = "<<v6.front()<<endl;
    //    cout<<" back = "<<v6.back()<<endl;

    //    assert(v6.size() == 1);
    //    assert(v6[0] == 100);
    //    v6.push_back(101);
    //    assert(v6.size() == 2);
    //    assert(v6[1] == 1001);

    //    cout<<" last = "<<v6.back()<<endl;
    //    v6.pop_back();
    //    cout<<" last = "<<v6.back()<<endl;

    //    Vector<A>v7;

    //    A obj1;
    //    obj1.val = 4;
    //    obj1.val2 = 5;
    //    v7.push_back(obj1);
    //    cout<<" value = "<<v7.back().val<<" value2 = "<<v7.back().val2<<endl;
    //    cout<<" value = "<<v7[0].val <<" value2 = "<<v7[1].val2<<endl;

    //    vector<int> org_vec;

    //    org_vec.pop_back();
    //    cout<<" expected val = "<<org_vec.back()<<endl;

    //    org_vec.erase(it);
    //    org_vec.print_vec();

    // Test case for Insert functionality
    Vector<int> test_vec1;
    test_vec1.push_back(120);
    test_vec1.push_back(130);

    auto it = test_vec1.begin();
    test_vec1.insert(it, 200);
    assert(test_vec1[0] == 200);
    it++;
    test_vec1.insert(it, 300);
    assert(test_vec1[0] == 200);
    assert(test_vec1[1] == 300);
    assert(test_vec1[2] == 120);
    assert(test_vec1[3] == 130);

    //    test_vec1.print_vec();


    cout << "SUCCESS\n";
}

