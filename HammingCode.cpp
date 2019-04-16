


#include<bits/stdc++.h>
using namespace std;
int main() {
    string databits;
    cout<<"Enter data bits: ";
    cin>>databits;
    int len=databits.length();
    string codeword="";
    string errorword="";
    string correctword="";
    float prob=0.50;
    int errors=0;
    int times=len/4;
    int er[10]={0};
    int a=0;
    for(int i=0;i<len;i+=4){
     string dataword="";
     string temp="";
     for(int j=i;j<i+4;j++){
     temp+=databits.at(j);
     }
      for(int k=0;k<3;k++){
          dataword+=temp.at(k);
      }
      dataword+=" ";
      dataword+=temp.at(3);

    int p1,p2,p3;
    p1=dataword.at(0)^dataword.at(2)^dataword.at(4);
    p2=dataword.at(0)^dataword.at(1)^dataword.at(4);
    p3=dataword.at(0)^dataword.at(1)^dataword.at(2);
    dataword.at(3)=p3;
    dataword+=p2;
    dataword+=p1;
    cout<<a+1<<" Token: "<<dataword<<endl;
    codeword+=dataword;

int index=0;
for(int i =0 ; i<dataword.length() ; i++)
    {
      if(  ((float) rand() / (RAND_MAX)) <=prob )
       {
         if(dataword.at(i)=='0')
         {
          dataword.at(i)= '1';
          errors++;
          index=i;
          break;
         }

         else
         {
          dataword.at(i) = '0';
          errors++ ;
          index=i;
          break;
         }

       }
    }
    er[a]=index;
    a++;

    errorword+=dataword;
    }
   cout<<endl;
   cout<<"Sent CodeWord: "<<endl;
   cout<<codeword<<endl<<endl;
   cout<<"Received frame:"<<endl;
   cout<<errorword<<endl<<endl;
   cout<<"Errors: "<<errors<<endl;


//-------------------------------receiver end---------------------------//

int l=errorword.length();
int k=0;
for(int i=0;i<l;i+=7){
     string temp="";
     for(int j=i;j<i+7;j++){
          temp+=errorword.at(j);
     }
     cout<<"For "<<k+1 <<" token, error is at position "<<er[k]<<endl;

     if(temp.at(er[k])=='0'){
          temp.at(er[k])='1';
     }
     else{
          temp.at(er[k])='0';
     }
correctword+=temp;
 k++;
}
cout<<endl;
cout<<"AFTER CORRECTING ALL THE ERRORS:"<<endl;
cout<<correctword<<endl;
return 0;
}
