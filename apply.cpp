#include<bits/stdc++.h>
using namespace std;

//Pairity checking

int a_length(char array[])
{
    int count = 0 ;
    for(int i = 0 ; array[i]!= NULL; i++)
    {

        count++;
    }
    return count ;
}

void pairitycheck(){
char data [100] ;
    cout<<"This is a program for even parity checking."<< endl ;
    cout<<"Enter the data : "<<endl ;
    cin>>data ;
    int length= a_length(data) ;
    int count =0;
    for (int i =0; i<length; i++)
    {
        if (data[i]== '1')
        {
            count++;
        }
    }
    int c=length +1;
    if(count%2 == 0)
    {
        for(int i=c, j=c-1; i >0; i--, j--)
        {
            data [ i ] = data [ j ] ;
        }
        data[0] = '1';
        cout<<"After adding '1' at the front of the data : "<<endl ;
        cout<<data<<endl ;
    }
    else
    {
        for(int i=c, j=c-1; i >0; i--, j--)
        {
            data[i] = data [j] ;
        }
        data [ 0 ] = '0' ;
        cout<<"After adding '0' at the front of the data : "<<endl ;
        cout<<data<<endl ;
    }
}


//CRC part

class CRC
{
public:
int nf, ng, frame[20], gen[10], temp[20], b;
char a;
int* divide(int n, int g, int temp[10], int gen[10]) {
for(int i=0; i<n; i++)
{
if(gen[0]==temp[i])
{
for(int j=0, k=i; j<g+1; j++, k++)
{
if(temp[k]^gen[j]==1)
temp[k]=1;
else
temp[k]=0;
}
}
}
return temp;
}
void input()
{
cout<<"Enter length of your frame:";
cin>>nf;
cout<<"Enter your frame:";
for(int i=0; i<nf; i++)
{
cin>>frame[i];
temp[i]=frame[i];
}
cout<<"Enter length of your generator:"; cin>>ng;
cout<<"Enter your generator:";
for(int i=0; i<ng; i++)
{
cin>>gen[i];
}
ng--;
for(int i=0; i<ng; i++)
{
temp[nf+i]=0;
}
}
void sender_side()
{
int* sender;
sender = divide(nf,ng,temp,gen);
cout<<endl<<"-----Senders Side-----\n"<<"CRC:";
for(int i=0; i<ng; i++)
{
frame[nf+i]=sender[nf+i];
cout<<sender[nf+i]<<' ';
}
cout<<endl<<"Transmitted frame:";
for(int i=0; i<nf+ng; i++)
cout<<frame[i]<<' ';
cout<<endl;
}
int receiver_side()
{
int* receiver;
cout<<"\n-----Receivers Side-----\n"<<"Received message:";
for(int i=0; i<nf+ng; i++)
cout<<frame[i]<<' ';
cout<<endl;
cout<<"Enter which bit you want to change(from 0-"<<nf+ng<<")-";
cin>>b;
if(frame[b]==1)
frame[b]=0;
else
frame[b]=1;
receiver = divide(nf,ng,frame,gen);
cout<<"Error:";
for(int i=0; i<nf+ng; i++)
{
if(receiver[i]!=0)
{
cout<<"Error Detected!!"<<endl;
return 0;
}
}
cout<<"No error detected!"<<endl;
}
};


void crc_checking(){
CRC o;
o.input();
o.sender_side();
o.receiver_side();
}


//Humming code

vector<int> generateHammingCode(vector<int> msgBits, int m, int r)
{
	vector<int> hammingCode(r + m);
	for (int i = 0; i < r; ++i){
		hammingCode[pow(2, i) - 1] = -1;
	}
	int j = 0;
	for (int i = 0; i < (r + m); i++) {
		if (hammingCode[i] != -1) {
			hammingCode[i] = msgBits[j];
			j++;
		}
	}

	for (int i = 0; i < (r + m); i++){
		if (hammingCode[i] != -1)
			continue;
		int x = log2(i + 1);
		int one_count = 0;
		for (int j = i + 2;
			j <= (r + m); ++j) {

			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1) {
					one_count++;
				}
			}
		}
		if (one_count % 2 == 0) {
			hammingCode[i] = 0;
		}
		else {
			hammingCode[i] = 1;
		}
	}
	return hammingCode;
}
void findHammingCode(vector<int>& msgBit)
{
	int m = msgBit.size();
	int r = 1;
	while (pow(2, r) < (m + r + 1)) {
		r++;
	}
	vector<int> ans = generateHammingCode(msgBit, m, r);
	cout << "Message bits are: ";
	for (int i = 0; i < msgBit.size(); i++)
		cout << msgBit[i] << " ";

	cout << "\nHamming code is: ";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}


void hummingcode(){
vector<int> msgBit;
	int a, i, n;
	cout<<"Enter the size of the message: ";
	cin>>n;
	cout<<"Enter the message: ";
	for(i=0;i<n;i++){
        cin>>a;
         msgBit.push_back(a);
	}
	findHammingCode(msgBit);
}



int main()
{
    int option, option2, option3;

    cout<<"                          Secure your data                 ";
    cout<<"\n\n";
    cout<<"_______________________________________________";
    cout<<"\n";
    cout<<"|              Choose an option               |";
    cout<<"\n";
    cout<<"|                                             |";
    cout<<"\n";
    cout<<"|     1. Check your data                      |";
    cout<<"\n";
    cout<<"|                                             |";
    cout<<"\n";
    cout<<"|     2. Exit                                 |";
    cout<<"\n";
    cout<<"|_____________________________________________|";
    cout<<"\n\n";
    cout<<"Enter an option: ";
    cin>>option;
    if(option==2)
    {
        cout<<"\n\n\n";
        cout<<"             'Thank you for using our product!'";
        cout<<"\n\n\n";
        return 0;
    }
    else if(option==1)
    {
        cout<<"\n\n";
        cout<<"_______________________________________________";
        cout<<"\n";
        cout<<"|   Do you want to secure your data?          |";
        cout<<"\n";
        cout<<"|                                             |";
        cout<<"\n";
        cout<<"|     1. Yes                                  |";
        cout<<"\n";
        cout<<"|                                             |";
        cout<<"\n";
        cout<<"|     2. NO                                   |";
        cout<<"\n";
        cout<<"|_____________________________________________|";
        cout<<"\n\n";
        cout<<"Enter an option: ";
        cin>>option2;
        cout<<"\n\n";
        if(option2==2)
        {
            cout<<"\n";
            cout<<"             Thank you for using our product!";
            cout<<"\n\n";
        }
        else if(option2==1)
        {
            cout<<"____________________________________________________";
            cout<<"\n";
            cout<<"|Which Error checking system you want to prefere?  |";
            cout<<"\n";
            cout<<"|                                                  |";
            cout<<"\n";
            cout<<"|     1. Pairity Check                             |";
            cout<<"\n";
            cout<<"|                                                  |";
            cout<<"\n";
            cout<<"|     2. Cyclic Redundency Check                   |";
            cout<<"\n";
            cout<<"|                                                  |";
            cout<<"\n";
            cout<<"|     3. Humming code                              |";
            cout<<"\n";
            cout<<"|                                                  |";
            cout<<"\n";
            cout<<"|     4. Exit                                      |";
            cout<<"\n";
            cout<<"|__________________________________________________|";
            cout<<"\n\n";
            cout<<"Enter your option: ";
            cin>>option3;
            cout<<"\n\n";
            if(option3==4){
                cout<<"          Thank you for using our product!";
                cout<<"\n\n";
            }
            else if(option3==1){
                pairitycheck();
                cout<<"\n";
                cout<<"Your Data is ok!";
                cout<<"\n\n";
            }
            else if(option3==2){
                crc_checking();
                cout<<"\n";
            }
            else if(option3==3){
                hummingcode();
                cout<<"\n\n";
            }
            else{
                cout<<"\n";
                cout<<"        Wrong option! Please try again";
                cout<<"\n\n\n";
            }

        }
        else
        {
            cout<<"             Wrong option! try again";
            cout<<"\n\n\n";
            return 1;
        }
    }

    else
    {
        cout<<"\n\n\n";
        cout<<"             Wrong option! try again";
        cout<<"\n\n\n";
        return 1;
    }
}
