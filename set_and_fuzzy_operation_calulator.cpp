#include<bits/stdc++.h>
using namespace std;
//global variables (For Decoration)
char decor = 175;
int ch;
char fiv = 155;
//global variables (Set Operations variables.......... )
set<int>ms; // Set A
vector<int>v; //Set B
vector<int>w; //external use
//global variables. (Fuzzy Set operations variables.........)
vector<float>f1; //Fuzzy Set A
vector<float>f2; //Fuzzy Set B


//---------------------------------------------------------------SET FUNCTIONS---------------------------------------------------------------------
void Universal() //Universal setting values..
{
     int n,m;
    cout<<decor<<" Enter The Total Number of Elements in Given Universal Set : ";
    cin>>n;
    int val;
    cout<<decor<<" Universal SET : ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        ms.insert({val});
    }
    cout<<decor<<" Enter The Total Number of Elements in Given Set A : ";
    cin>>m;
    cout<<decor<<" SET A : ";
    for(int i=0;i<m;i++)
    {
        cin>>val;
        v.push_back(val);
    }
}
void Uni_print(set<int>&ms,vector<int>&v) //Printing universal values and Set A
{
    cout<<"<-------------------------SET OPERATION------------------>\n\n";
    cout<<decor<<" Universal SET : ";
    set<int>::iterator it;
    cout<<"[";
    for(it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    cout<<endl;
    cout<<decor<<" SET A : ";
    cout<<"[";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    cout<<"]";
    cout<<endl;
}
void sets_values()  //setting the values of two given set A and B
{
    int n,m;
    cout<<decor<<" Enter The Total Number of Elements in Given Set A : ";
    cin>>n;
    int val;
    cout<<decor<<" SET A : ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        ms.insert({val});
    }
    cout<<decor<<" Enter The Total Number of Elements in Given Set B : ";
    cin>>m;
    cout<<decor<<" SET B : ";
    for(int i=0;i<m;i++)
    {
        cin>>val;
        v.push_back(val);
    }
}
void printVal(set<int>&ms,vector<int>&v) //printing values of SET A and SET B
{
    cout<<"<-------------------------SET OPERATION------------------>\n\n";
    cout<<decor<<" SET A : ";
    set<int>::iterator it;
    cout<<"[";
    for(it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    cout<<endl;
    cout<<decor<<" SET B : ";
    cout<<"[";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    cout<<"]";
    cout<<endl;
}
void union_set(set<int>&ms,vector<int>&v)  //union operation..
{

    for(int i=0;i<v.size();i++)
    {
    if(ms.find(v[i])==ms.end())
    {
        ms.insert({v[i]});
    }
    }
    cout<<decor<<" A UNION B : ";
    set<int>::iterator it;
    cout<<"[";
    for(it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    cout<<endl<<endl;
    v.clear();
    ms.clear();

}
void intersection_set(set<int>&ms,vector<int>&v) //Intersection of SET A and SET B
{
    set<int>interMS;
    for(int i=0;i<v.size();i++)
    {
    if(ms.find(v[i])!=ms.end())
    {
        interMS.insert({v[i]});
    }
    }
    if(interMS.empty()){
         cout<<decor<<" A INTERSECTION B : "<<fiv<<" (NULL)";
    }
    else{
    cout<<decor<<" A INTERSECTION B : ";
    set<int>::iterator it;
    cout<<"[";
    for(it=interMS.begin();it!=interMS.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    }
    cout<<endl<<endl;
    v.clear();
    ms.clear();
    interMS.clear();
}
void diff_A(set<int>&ms,vector<int>&v) //A-B
{
    for(int i=0;i<v.size();i++)
    {
    if(ms.find(v[i])!=ms.end())
    {
       ms.erase({v[i]});
    }
    }
    if(ms.empty())
    {
    cout<<"A - B : "<<fiv<<" (NULL)";
    }
    else{
    set<int>::iterator it;
    cout<<"A - B : ";
    cout<<"[";
    for(it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    }
    cout<<endl<<endl;
    v.clear();
    ms.clear();
}
void diff_B(set<int>&ms,vector<int>&v)
{
    set<int>interMS;
    for(int i=0;i<v.size();i++)
    {
    if(ms.find(v[i])==ms.end())
    {
            interMS.insert({v[i]});
    }
    }
    if(interMS.empty())
    {
          cout<<"B - A : "<<fiv<<" (NULL)";
    }
    else{
    cout<<"B - A : ";
    set<int>::iterator it;
    cout<<"[";
    for(it=interMS.begin();it!=interMS.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    }
    cout<<endl<<endl;
    v.clear();
    ms.clear();
    interMS.clear();
}
void difference_opt() //difference operation on A and B sets.
{
    cout<<decor<<" Select The Option :----------------:>\n"<<"  1. A - B\n"<<"  2. B - A\n  3. Exit"<<endl;
    cout<<decor<<" Enter Your Option : ";
    cin>>ch;
    switch(ch)
    {
    case 1:
       cout<<decor<<" DIFFERENCE OF ";
        diff_A(ms,v);
    break;
    case 2:
      cout<<decor<<" DIFFERENCE OF ";
        diff_B(ms,v);
    break;
    case 3:
            cout<<"<<<<<<<<----------Exit------>>>>>>>>>\n\n";
            break;
    default:
         cout<<"-------------Invalid Option--------------\n";
    break;
    }

}
void Complement(set<int>&ms,vector<int>&v) //complementing the value.
{
    char dot = 39;
    for(int i=0;i<v.size();i++)
    {
    if(ms.find(v[i])!=ms.end())
    {
       ms.erase({v[i]});
    }
    }
    cout<<decor<<" COMPLEMENT OF SET\n";
    cout<<decor<<" A"<<dot<<" : ";
    set<int>::iterator it;
    cout<<"[";
    for(it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<",";
    }
    cout<<"]";
    cout<<endl<<endl;
    v.clear();
    ms.clear();
}
void product_set()   //setting the products values
{
    int n,m;
    cout<<decor<<" Enter The Total Number of Elements in Given Set A : ";
    cin>>n;
    int val;
    cout<<decor<<" SET A : ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    cout<<decor<<" Enter The Total Number of Elements in Given Set B : ";
    cin>>m;
    cout<<decor<<" SET B : ";
    for(int i=0;i<m;i++)
    {
        cin>>val;
        w.push_back(val);
    }
    cout<<"<-------------------------SET OPERATION------------------>\n\n";
    cout<<decor<<" SET A : ";
    cout<<"[";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    cout<<"]";
    cout<<endl;
    cout<<decor<<" SET B : ";
    cout<<"[";
    for(int i=0;i<w.size();i++)
    {
        cout<<w[i]<<",";
    }
    cout<<"]";
    cout<<endl;
}
void product_opt(vector<int>&v,vector<int>&w)  //Products of two SET A and SET B
{
    set<pair<int,int>>pms;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<w.size();j++){
            pms.insert({v[i],w[j]});
        }
    }
    cout<<decor<<" PRODUCTS OF TWO SETS\n";
    cout<<decor<<" A X B : ";
    set<pair<int,int>>::iterator it;
    cout<<"{ ";
    for(it=pms.begin();it!=pms.end();it++)
    {
          cout<<"( "<<it->first<<","<<it->second<<" )";
    }
    cout<<" }";
    //----------------------------AXB-------------------
    pms.clear();
     for(int i=0;i<w.size();i++)
    {
        for(int j=0;j<v.size();j++){
            pms.insert({w[i],v[j]});
        }
    }
    cout<<endl;
    cout<<decor<<" B X A : ";
    set<pair<int,int>>::iterator itr;
    cout<<"{ ";
    for(itr=pms.begin();itr!=pms.end();itr++)
    {
        cout<<"( "<<itr->first<<","<<itr->second<<" )";
    }
    cout<<" }";
    cout<<endl<<endl;
    v.clear();
    pms.clear();
    w.clear();
}
//---------------------------------------------------------END-OFF-----------------------------------------------------------------
//----------------------------------------------------------FUZZY SET FUNCTIONS----------------------------------------------------


void fuzzy_value() //setting the value of fuzzy set A and B.
{
    int n;
    cout<<decor<<" Enter The Total Number of Elements in Given Set A And Set B : ";
    cin>>n;
    float val;
    cout<<decor<<" Enter The Membership Function Of FUZZY SET A : ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        f1.push_back({val});
    }
       cout<<decor<<" Enter The Membership Function Of FUZZY SET B : ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        f2.push_back(val);
    }
}
void print_fuzzy(vector<float>&f1,vector<float>&f2) //printing values of SET A and SET B
{
    cout<<"<-------------------------FUZZY SET OPERATION------------------>\n\n";
    cout<<decor<<" FUZZY SET A : ";
    cout<<"{";
    for(int i=0;i<f1.size();i++)
    {
        cout<<"( "<<i+1<<","<<f1[i]<<" )";
    }
    cout<<"}";
    cout<<endl;
    cout<<decor<<" FUZZY SET B : ";
    cout<<"{";
    for(int i=0;i<f2.size();i++)
    {
        cout<<"( "<<i+1<<","<<f2[i]<<" )";
    }
    cout<<"}";
    cout<<endl;
}
void fuzzy_union(vector<float>&f1,vector<float>&f2) //union operation of fuzzy set
{
    vector<float>ans;
    for(int i=0;i<f1.size();i++)
    {
        ans.push_back(max(f1[i],f2[i]));  //union operation
    }
    cout<<decor<<" UNION OF FUZZY SET A AND FUZZY SET B : ";
    cout<<"{";
    for(int i=0;i<ans.size();i++)
    {
        cout<<"( "<<i+1<<","<<ans[i]<<" )";
    }
    cout<<"}";
    cout<<endl<<endl;
    f1.clear();
    f2.clear();
    ans.clear();
}
void  fuzzy_intersect(vector<float>&f1,vector<float>&f2) //intersection operation of fuzzy set
{
    vector<float>ans;
    for(int i=0;i<f1.size();i++)
    {
        ans.push_back(min(f1[i],f2[i]));  //union operation
    }
    cout<<decor<<" INTERSECTION OF FUZZY SET A AND FUZZY SET B : ";
    cout<<"{";
    for(int i=0;i<ans.size();i++)
    {
        cout<<"( "<<i+1<<","<<ans[i]<<" )";
    }
    cout<<"}";
    cout<<endl<<endl;
    f1.clear();
    f2.clear();
    ans.clear();
}
void  fuzzy_complement(vector<float>&f1,vector<float>&f2) //Complements of Fuzzy set
{
    char dot=39;
    for(int i=0;i<f1.size();i++)
    {
        f1[i] = (1-f1[i]);
        f2[i] = (1-f2[i]);
    }
    cout<<decor<<" COMPLEMENT OF TWO FUZZY SETS\n";
    cout<<decor<<" A"<<dot<<" : ";
    for(int i=0;i<f1.size();i++)
    {
        cout<<"( "<<i+1<<","<<f1[i]<<" )";
    }
    cout<<"}";
    cout<<endl;
    cout<<decor<<" B"<<dot<<" : ";
    for(int i=0;i<f2.size();i++)
    {
        cout<<"( "<<i+1<<","<<f2[i]<<" )";
    }
    cout<<"}";
    cout<<endl<<endl;
    f1.clear();
    f2.clear();
}
//---------------------------------------------------------------END-OFF----------------------------------------------------------------------
//-----------------------------------------------------------MAIN FUNCTION--------------------------------------------------------------------
int main()
{
    char cor = 174;
    cout<<"\n\n-------------------------------"<<decor<<" SET OPEARTIONS AND FUZZY SET OPERATIONS "<<cor<<"---------------------------------------";
    cout<<endl<<endl<<endl;
    do{ //OUTER SWITCH BLOCK
    cout<<decor<<" Select The Option :----------------:>\n"<<"  1. Set Operation\n"<<"  2. Fuzzy Set Operation\n  3. Exit"<<endl;
    cout<<decor<<" Enter Your Option : ";
    cin>>ch;
    switch(ch) //OUTER SWITCH BLOCK
    {
    case 1:
        do{   //INNER DO-WHILE LOOP
        cout<<decor<<" Select The Option :---------------------:>\n"<<"  1. Union Operation"<<"\n  2. Intersection Operation\n  3. Difference Operation\n  4. Complement of Given Set\n  5. Product of Two Sets\n  6. Exit"<<endl;
        cout<<decor<<" Enter Your Option : ";
        cin>>ch;
        switch(ch){   //INNER SWITCH BLOCK
        case 1:
            sets_values();
            printVal(ms,v);
            union_set(ms,v);
            break;
        case 2:
            sets_values();
            printVal(ms,v);
            intersection_set(ms,v);
            break;
        case 3:
             sets_values();
            printVal(ms,v);
            difference_opt();
            break;
        case 4:
            Universal();
            Uni_print(ms,v);
            Complement(ms,v);
            break;
        case 5:
            product_set();
            product_opt(v,w);
            break;
        case 6:
            cout<<"<<<<<<<<----------Exit------>>>>>>>>>\n\n";
            break;
        default:
        cout<<"-------------Invalid Option--------------\n";
        break;
        }
        }while(ch!=6); //END OF DO-WHILE LOOP
        break;
    case 2:
        cout<<"\t\t"<<decor<<" NOTE -----> Range Of Values Of Membership Function Is The Unit Interval [0,1].\n\n";
        do{ //Inner do-while Loop
            cout<<decor<<" Select The Option :----------------:>\n"<<"  1. Union Operation\n"<<"  2. Intersection Operation\n  3. Complement of Given Set\n  4. Exit"<<endl;
            cout<<decor<<" Enter Your Option : ";
            cin>>ch;
            switch(ch) //INNER SWITCH BLOCK
            {
            case 1:
                fuzzy_value();
                print_fuzzy(f1,f2);
                fuzzy_union(f1,f2);
                break;
            case 2:
                fuzzy_value();
                print_fuzzy(f1,f2);
                fuzzy_intersect(f1,f2);
                break;
            case 3:
                fuzzy_value();
                print_fuzzy(f1,f2);
                fuzzy_complement(f1,f2);
                break;
            case 4:
                cout<<"<<<<<<<<----------Exit------>>>>>>>>>\n\n";
                break;
            default:
                cout<<"-------------Invalid Option--------------\n";
                break;
            }
        }while(ch!=4); //END OF INNER LOOP
        break;
    case 3:
        cout<<"<<<<<<<<----------Exit------>>>>>>>>>\n\n";
        break;
    default:
        cout<<"-------------Invalid Option--------------\n";
        break;
    }

}while(ch!=3); //END OF OUTER LOOP
cout<<"\t\t\t\t\t\t\t\t\t"<<decor<<" Developed By PRUTHVI TIRMAL.."<<endl<<endl;  //@Developer
return 0;
}
