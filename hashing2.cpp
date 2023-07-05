/*
Store the following words in a hash table using modulo division method. Let the array size be the next prime 
number greater than the number of elements to be hashed.
best, true, hill, dove, van, good, egg, lap
If integer values from 0 to 25 are assigned for all the lower case letters, compute the sum of these integer
values for every word and then perform modulo division Use linear probing to resolve collision. Later, read the
element to be searched from the user and perform the lookup.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    cout<<"Enter the eight elements to be hashed one by one."<<endl;
	string arr[11];
	int j;
	for(int k=0;k<11;k++){
		arr[k]="9999";
	}
	
	for (j=0;j<8;j++){
		string text;
        cout<<"Enter element : ";
		cin>>text;
		int i=0;
		int sum=0;
		for (i=0;i<text.length();i++){
			int temp,temp1;
			temp=text[i];
			temp1=temp-97;
			cout<<text[i]<<" = "<<temp1<<", ";
			sum+=temp1;
		}
		cout<<"\nSum= "<<sum;
		int address=sum%11;
		cout<<"\nThe address for "<<text<<" is "<<address<<endl;
		cout<<endl;

		while (1>0){
			if (arr[address]!="9999"){ //meaning not empty
				address++;
				if (address>=11){
					address=address%11;
				}	
			}
			else{
				arr[address]=text;
				break;
			}	
		}
	}
    cout<<"The hashed table containing 11 elements is : "<<endl;
	for (int i1=0;i1<11;i1++){
		cout<<arr[i1]<<" ";
	}	
}
