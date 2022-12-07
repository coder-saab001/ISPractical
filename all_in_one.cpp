/*
program using cease Cypher
#include<bits/stdc++.h>
using namespace std;

string decode(string input, int shift, vector<char> &store){
	string ans="";
	int size = input.length();
	for(int i=0; i<size; i++){
		int x = input[i] - 'a';
		
		int decodedIndex = (x - shift + 26)%26;
		
		ans += store[decodedIndex];
	}
	return ans;
}
string encode(string input, int shift, vector<char> &store){
	//temporary variable to store the encoded ans
	string ans="";
	int size = input.length();
	for(int i=0; i<size; i++){
		//considering alphabet a as 0, b as 1 and so on
		int x = input[i] - 'a';
		
		//Adding the shift to the curent string to find the approiate mapped character
		//Doing modulo 26 if it goes out the range of alphabets to make cyclic conversion
		//adding 26 so that negative shifts can also be handled;
		int encodedIndex = (x+shift +26)%26;
		
		ans += store[encodedIndex];
	}
	return ans;
}

int main(){
	vector<char> store;
	char temp = 'a';
	//storing data in vector to map char with integer values as index
	for(int i=0; i<26; i++){
		store.push_back(temp++);
	}
	string input;
	int shift;
	cout<<"Input the string to encode: ";
	cin>>input;
	cout<<"Enter the shift to be done: ";
	cin>>shift;
	
	//Function to encode the string using Ceaser Cypher 
	string encoded = encode(input,shift,store);
	cout<<"encoded String using Ceaser Cypher:- "<<encoded;
	
	//Function to decode the string using Ceaser Cypher
	string decoded = decode(encoded,shift, store);
	cout<<"\nDecoded String using Ceaser Cypher:- "<<decoded;
}
*/


/*
Delfi Helman

#include<bits/stdc++.h>
using namespace std;

int modularExponentiation(int a, int b, int c){
	vector<int> arr;
	while(b>0){
		arr.push_back(b%2);
		b = b/2;
	};
	reverse(arr.begin(),arr.end());
	vector<int> store;
	store.push_back(a);
	for(int i=1; i<arr.size(); i++){
		int cal;
		if(arr[i]==0){
			cal = (store[i-1]*store[i-1])%c;
		}
		else{
			cal = (((store[i-1]*store[i-1])%c)*a)%c;
		}
		store.push_back(cal);
	}
	return store[store.size()-1];
}

int main(){
	int q;
	cout<<"Enter any prime number: ";
	cin>>q;
	
	//find primitive root of prime number q;
	int alpha;
	for(int i=1; i<q; i++){
		vector<int> store(q,0);
		bool flag = false;
		for(int j=1; j<q; j++){
			int cal = modularExponentiation(i,j,q);
			if(store[cal]==0){
				store[cal]++;
			}
			else{
				flag = true;
				break;
			}
		}
		if(flag==false){
			alpha = i;
			break;
		}	
	}
	
	cout<<"Primitive root of prime number "<<q<<": "<<alpha;
	
	int Xa, Xb, Ya, Yb;
	cout<<"\nInput the private key of user a: ";
	cin>>Xa;
	cout<<"Input the private key of user b: ";
	cin>>Xb;
	
	Ya = modularExponentiation(alpha, Xa, q);
	Yb = modularExponentiation(alpha, Xb, q);
	
	//generating key for both users;
	int ka = modularExponentiation(Yb, Xa, q);
	int kb = modularExponentiation(Ya, Xb, q);
	
	cout<<"Key for user a: "<<ka;
	cout<<"\nKey for user b: "<<kb;
}

*/

/*
Hill cipher   
#include<bits/stdc++.h>
using namespace std;

//multiplying matrix
string encrypt(vector<vector<int>> KeyMat, vector<int> plainTextMat)
{
    int result = 0;
    string output = "";
    
    for(int i=0; i < KeyMat.size(); i++){
    	result = 0;
    	for(int j = 0; j < KeyMat.size(); j++){
    		result += KeyMat[i][j]*plainTextMat[j];
		}
		result %= 26;
		output += char(result + 65);
	}
	return output;
}

int main()
{
	string plainText, cipherText, key;
	int keyLen, ptLen;
	
	cout<<"Enter plain text: ";
	cin>>plainText;
	
	cout<<"Enter Key: ";
	cin>>key;
	
	ptLen = plainText.length();
	keyLen = key.length();
	
	int n = ceil(sqrt(keyLen));
	
	for(int i = keyLen; i<n*n; i++)
		key += "X";
		
	vector<vector<int>> KeyMat(n, vector<int>(n));	
	int k = 0;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			KeyMat[i][j] = int(key[k++] - 'A');
	
	while(ptLen%n !=0)
		plainText += "X";
		
	k = 0;
	for(int i=0; i<ptLen; i += n)
	{
		vector<int> plainTextMat(n);
		for(int i=0; i<n; i++)
			plainTextMat[i] = int(plainText[k++] - 'A');	
		
		cipherText += encrypt(KeyMat, plainTextMat);	
	}
	cout<<"Cipher Text: "<<cipherText<<endl;
}

*/

/*
keyword cypher 

#include<bits/stdc++.h>
using namespace std;

string decrypt(string input, int encryptions[]){
	string ans="";
	
	for(int i=0; i<input.size(); i++){
		for(int j=0; j<26; j++){
			if(encryptions[j] == (int)input[i]){
				ans += (char)(j + 'a');
				break;
			}
		}
	}
	return ans;
}

string encrypt(string input, int encryptions[]){
	
	string ans="";
	for(int i=0; i<input.size(); i++){
		int idx = input[i]-'a';
		ans += (char)encryptions[idx];
	}
	return ans;

}

int main(){
	string keyword;
	cout<<"Input key for the keyword cipher: ";
	cin>>keyword;
	string input;
	cout<<"Input plain text to encrypt: ";
	cin>>input;
	int arr[26] = {0};
	int encryptions[26]={0};
	int count=0;
	for(int i=0; i<26; i++){
		arr[i]=0;
		encryptions[i] = 0;
	}
	for(int i=0; i<keyword.size(); i++){
		if(arr[keyword[i] - 'a']==0){
			arr[keyword[i] - 'a']++;
			encryptions[count] = (int)keyword[i];
			count++;
		}
	}
	
	
	cout<<endl;
	for(int i=0; i<26; i++){
		if(arr[i]==0){
			encryptions[count]= i + 'a';
			count++;
		}
	}
	
	string encrypted = encrypt(input,encryptions);
	
	string decrypted = decrypt(encrypted,encryptions);
	cout<<"Cipher Text: "<<encrypted;
	cout<<endl<<endl<<"Original plain text after decryption: "<<decrypted;
	return 0;
}
*/

/*
MD5
#include<bits/stdc++.h>
#include "valarray"
using namespace std;
typedef long long ll;

struct Buffer {
	ll A, B, C, D;
};

string add_string(string s, int len)// function to add substring to string
{
	string output = "";
	
	for(int i=0; i<len; i++)
		output += s;
	return output;	
}

//encryption function 
struct Buffer encrypt(ll A, ll B, ll C, ll D, ll func, string msg_block, valarray<ll> keys)
{
	Buffer buffer;
	ll func_value;
	ll output=0;
	for(int i=0; i<16; i++)// for each function it runs 16 times
	{
		if(func == 1)
			func_value = (B & C) | (~B & ~D);
		if(func == 2)
			func_value = (B & D) | (C & ~D);	
		if(func == 3)
			func_value = (B^C)^D;
		if(func == 4)	
			func_value = C^(B|(~D));
		
		output += func_value + A;// adding function value to A
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += stoll(msg_block.substr(i*32, 32), 0, 2);// adding message blocks
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += keys[i];// adding key block
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output = ((output << 3)|(output >> (32 - 3)))&(ll(pow(2,32)) - 1); // left rotate S bits, S = 3
		
		output += B;// adding B
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		//rearranging
		A = D;
		D = C;
		C = B;
		B = output;		
	}
	buffer.A = A;
	buffer.B = B;
	buffer.C = C;
	buffer.D = D;
	return buffer;
}

//generating 64 keys
valarray<ll> calcKs()
{
    double s, pwr;
    int i;
    valarray<ll> k(64);

    pwr = pow( 2, 32);
    for (i=0; i<64; i++) {
        s = fabs(sin(1+i));
        k[i] = (ll)( s * pwr );
    }
    return k;
}

int main()
{
	//binary_msg is the final input in binary form to the encryption algorithm
	string msg, binary_msg;
	ll blocks = 0;
	
	cout<<"Enter the message "<<endl;
	cin>>msg;
	
	valarray<ll> keys = calcKs();
	blocks += floor((msg.length()*8)/512);
	ll remain_len = msg.length()*8 - floor((msg.length()*8)/512)*512;
	
	for(int i=0; i<msg.length(); i++)
		binary_msg +=  bitset<8> (int(msg[i])).to_string();
	
	if(remain_len <= 447)
	{
		blocks++;
		binary_msg += "1";
		binary_msg += add_string("0", 447-remain_len);
		binary_msg += bitset<64> (msg.length()).to_string();
	}
	else
	{
		blocks+=2;
		binary_msg += "1";
		binary_msg += add_string("0", 511-remain_len);
		binary_msg += bitset<448> (0).to_string();
		binary_msg += bitset<64> (msg.length()).to_string();
	}
	
	//buffer initialization
	ll A = 0x67425301;
	ll B = 0xEDFCBA45;
    ll C = 0x98CBADFE;
    ll D = 0x13DCE476;
	Buffer x ;
	
	
	for(int i=1; i<=blocks; i++)
	{
		string msg_block = binary_msg.substr((i-1)*512, 512);
		
		x = encrypt(A, B, C, D, 1, msg_block, keys[slice(0, 16, 1)]);
		x = encrypt(x.A, x.B, x.C, x.D, 2, msg_block, keys[slice(15, 32, 1)]);
		x = encrypt(x.A, x.B, x.C, x.D, 3, msg_block, keys[slice(31, 48, 1)]);
		x = encrypt(x.A, x.B, x.C, x.D, 4, msg_block, keys[slice(47, 64, 1)]);
	}	
	
	cout<<"Hashed Value: ";
	cout<<hex<<x.A;
	cout<<hex<<x.B;
	cout<<hex<<x.C;
	cout<<hex<<x.D;
	
}

*/

/*

playfair
#include<bits/stdc++.h>

using namespace std;

int main(){
	string plaintext,key;
	cout<<"Enter Plain Text: ";
	getline(cin,plaintext);
	cout<<"Enter Key: ";
	getline(cin,key);
	set<char> s;
	
	//Creating 5X5 matrix	
	vector< vector<char> > matrix(5,vector<char>(5));
	int r=0,c=0;
	for(int i=0;i<key.length();i++){
		if(key[i]=='j')continue;
		if(s.find(key[i])!=s.end()){
			continue;
		}
		s.insert(key[i]);
		matrix[r][c]=key[i];
		c++;
		if(c>=5){
			r++;
			c=c%5;	
		}
	}
	
	//Removing j from transformedPlainText text as we are taking i and j as same char in 5X5 matrix
	for(int i=0;i<plaintext.length();i++){
		if(plaintext[i]=='j'){
			plaintext[i]='i';
		}
	}
	
	//Handling same continuous characters
	
	string tempplain="";
	for(int i=0;i<plaintext.length();i++){
		if(plaintext[i]==' ')continue;
		if(tempplain.length()==0){
			tempplain+=plaintext[i];
		}else{
			if(tempplain[tempplain.length()-1]==plaintext[i]){
				if(plaintext[i]=='x'){
					tempplain+='a';
				}else{
					tempplain+='x';
				}
			}else{
				tempplain+=plaintext[i];
			}
		}
	}
	
	
	char x='a';
	while(true){
		while(s.find(x)!=s.end() || x=='j'){
			x++;
		}
		s.insert(x);
		matrix[r][c]=x;
		c++;
		if(c>=5){
			r++;
			c=c%5;	
		}
		if(r>=5)break;
	}
	
	//Storing row,col of each character for effiecient access
	cout<<"\n5X5 Matrix \n\n";
	map<char,pair<int,int> > m;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			m[matrix[i][j]]={i,j};
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//Removing spaces from transformedPlainText text
	string transformedPlainText="";
	for(int i=0;i<plaintext.length();i++){
		if(plaintext[i]==' ')continue;
		transformedPlainText+=plaintext[i];
	}
	
	//Making the length of palin text even	
	if(transformedPlainText.length()%2!=0){
		transformedPlainText+='z';
	}
	
	//PlayFair Cipher Algorithm
	string cipherText="";
	for(int i=0;i<transformedPlainText.length()-1;i+=2){
		char x=transformedPlainText[i],y=transformedPlainText[i+1];
		pair<int,int> p1=m[x],p2=m[y];
		if(p1.first==p2.first){
			cipherText+=(matrix[p1.first][(p1.second+1)%5]);
			cipherText+=(matrix[p1.first][(p2.second+1)%5]);
		}else if(p1.second==p2.second){
			cipherText+=(matrix[(p1.first+1)%5][p1.second]);
			cipherText+=(matrix[(p2.first+1)%5][p2.second]);
		}else{
			cipherText+=(matrix[p1.first][p2.second]);
			cipherText+=(matrix[p2.first][p1.second]);
		}
	}
	
	cout<<"\nPlain Text: "<<transformedPlainText<<"\n\n";
	cout<<"Key: "<<key<<"\n\n";
	cout<<"Ciphered Text: "<<cipherText<<"\n\n";
}

*/

/*
Rc4

#include<bits/stdc++.h>
using namespace std;

void changeS(int s[8], int t[8]){
	int j=0;
	cout<<"\n\nS updation: \n";
	for(int i=0; i<8; i++){
		j = (j + s[i] + t[i])%8;
		swap(s[i],s[j]);
		cout<<"Interation "<<i+1<<": ";
		for(int i=0; i<8; i++){
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
}

void ksa(int s[8], int key[4], int t[8]){
	int i=0,j=0,n=0;
	cout<<"\n\nKey updation: \n";
	for(int i=1; i<=4; i++){
		j = (j+s[i])%8;
		swap(s[i],s[j]);
		int x = (s[i]+s[j])%8;
		key[i-1] = s[x];
		cout<<"Interation "<<i<<": ";
		for(int i=0; i<4; i++){
			cout<<key[i]<<" ";
		}
		cout<<endl;
	}
}

vector<int> encrypt(int pt[4], int key[4]){
	vector<int> ct;
	for(int i=0; i<4; i++){
		ct.push_back(pt[i]^key[i]);
	}
	return ct;
}

int main(){
	int s[8];
	cout<<"\t\t\t\tRc4\n\n\n\n";
	cout<<"Input 8 bit array S: ";
	for(int i=0; i<8; i++){
		cin>>s[i];
	}
	int key[4];
	cout<<"Input 4 bit array key: ";
	for(int i=0; i<4; i++){
		cin>>key[i];
	}
	int pt[4];
	cout<<"Input plain text: ";
	for(int i=0; i<4; i++){
		cin>>pt[i];
	}
	int t[8];
	int k=0;
	for(int i=0; i<8; i++){
		t[i] = key[k%4];
		k++;
	}
	changeS(s,t);
	cout<<"\nChanged S after 8 iterations: ";
	for(int i=0; i<8; i++){
		cout<<s[i]<<" ";
	}
	ksa(s,key,t);
	cout<<"\nUpdated Key: ";
	for(int i=0; i<4; i++){
		cout<<key[i]<<" ";
	}
	vector<int> ct = encrypt(pt,key);
	cout<<"\nCipher Text: ";
	for(auto it:ct){
		cout<<it<<" ";
	}
}

*/

/*
RSA
#include<bits/stdc++.h>
using namespace std;

long long int modularExponentiation(long long int a, long long int b, long long int c){
	vector<long long int> arr;
	while(b>0){
		arr.push_back(b%2);
		b = b/2;
	};
	reverse(arr.begin(),arr.end());
	vector<long long int> store;
	store.push_back(a);
	for(int i=1; i<arr.size(); i++){
		long long int cal;
		if(arr[i]==0){
			cal = (store[i-1]*store[i-1])%c;
		}
		else{
			cal = (((store[i-1]*store[i-1])%c)*a)%c;
		}
		store.push_back(cal);
	}
	return store[store.size()-1];
}

int main(){
	long long int p,q;
	cout<<"Enter prime number 1: ";
	cin>>p;
	cout<<"Enter prime number 2: ";
	cin>>q;
	
	long long int n = p*q;
	
	long long int phi = (p-1)*(q-1);
	
//	find the encrypted key such that gcd(e,phi) = 1 and 1<e<phi;
	long long int encrypt;
	for(long long int i=2; i<phi; i++){
		if(__gcd(i,phi)==1){
			encrypt = i;
			break;
		}
	}
//	find decryption key using the formula (decrypt * encrypt)mod phi= 1;
	long long int decrypt=1;
	while(true){
		if((decrypt*encrypt)%phi == 1)
			break;
		else
			decrypt++;
	}
	long long int msg;
	cout<<"Enter the msg to be encypted: ";
	cin>>msg;
	
	long long int ct = modularExponentiation(msg,encrypt,n);
	cout<<"This is the ciphered msg using RSA algo: "<<ct;
	
	long long int decoded = modularExponentiation(ct,decrypt,n);
	cout<<"\nDecrypted text usng private in RSA to get back original message: "<<decoded;
}


*/

/*
SHA
#include<bits/stdc++.h>
#include "valarray"
using namespace std;
typedef long long ll;

struct Buffer {
	ll A, B, C, D, E;
};

vector<string> msg_chunk_array;

string add_string(string s, int len)// function to add substring to string
{
	string output = "";
	
	for(int i=0; i<len; i++)
		output += s;
	return output;	
}

//encryption function 
struct Buffer encrypt(Buffer x, ll func, string msg_block, ll key)
{
	Buffer buffer;
	ll func_value;
	ll output=0;
	ll A = x.A;
	ll B = x.B;
	ll C = x.C;
	ll D = x.D;
	ll E = x.E;
	
	
	for(int i=0; i<20; i++)// for each function it runs 20 times
	{
		if(func == 1)
			func_value = (B | C) & (~B | D);
		if(func == 2 || func == 4)
			func_value = B^(C^D);	
		if(func == 3)
			func_value = (C) & (B | D) & (C | D);
		
		output += func_value + E; // adding function value
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		E = D;
		D = C;
		C = ((B << 30)|(B >> (2)))&(ll(pow(2,32)) - 1);
		B = A;
		A = ((A << 5)|(A >> (27)))&(ll(pow(2,32)) - 1);
		
		output += A;// adding A
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += stoll(msg_chunk_array[(func - 1)*16 + i], 0, 2);	//adding message bits
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		output += key; // adding key
		output = stoll(bitset<32> (output).to_string(), 0, 2);// reforming it to 32 bits
		
		A = output;	
	}
	x.A = A;
	x.B = B;
	x.C = C;
	x.D = D;
	x.E = E;
	return x;
}


int main()
{
	//binary_msg is the final input in binary form to the encryption algorithm
	string msg, binary_msg;
	ll blocks = 0;
	
	cout<<"Enter the message "<<endl;
	cin>>msg;
	
	blocks += floor((msg.length()*8)/512);
	ll remain_len = msg.length()*8 - floor((msg.length()*8)/512)*512;
	
	for(int i=0; i<msg.length(); i++)
		binary_msg +=  bitset<8> (int(msg[i])).to_string();
	
	if(remain_len <= 447)
	{
		blocks++;
		binary_msg += "1";
		binary_msg += add_string("0", 447-remain_len);
		binary_msg += bitset<64> (msg.length()).to_string();
	}
	else
	{
		blocks+=2;
		binary_msg += "1";
		binary_msg += add_string("0", 511-remain_len);
		binary_msg += bitset<448> (0).to_string();
		binary_msg += bitset<64> (msg.length()).to_string();
	}
	
	//buffer initialization
	ll A = 0x67425301;
	ll B = 0xEDFCBA45;
    ll C = 0x98CBADFE;
    ll D = 0x13DCE476;
    ll E = 0xC3D2E1F0;
        
	Buffer x ;
	x.A = A;
	x.B = B;
	x.C = C;
	x.D = D;
	x.E = E;
	


	for(int i=1; i<=blocks; i++)
	{
		string msg_block = binary_msg.substr((i-1)*512, 512);
		msg_chunk_array.clear();
		
		//16 32 bit message words from 512 bit block
		for(int i=0; i<80; i++)
		{
			if(i<16)
				msg_chunk_array.push_back(msg_block.substr((i)*32, 32));
			else
				msg_chunk_array.push_back((bitset<32> (string(msg_chunk_array[i-16])) ^ bitset<32> (string(msg_chunk_array[i-14])) 
				^ bitset<32> (string(msg_chunk_array[i-8])) ^ bitset<32> (string(msg_chunk_array[i-3]))).to_string());	
		}
		
		x = encrypt(x, 1, msg_block, 0x5A827999);// 0  <= i <= 19
		x = encrypt(x, 2, msg_block, 0x6ED9EBA1);// 20 <= i <= 39
		x = encrypt(x, 3, msg_block, 0x8F1BBCDC);// 40 <= i <= 59
		x = encrypt(x, 4, msg_block, 0xCA62C16D);// 60 <= i <= 79
	}	
	
	x.A ^= A;
	x.B ^= B;
	x.C ^= C;
	x.D ^= D;
	x.E ^= E;
	
	cout<<"Hashed Value: ";
	cout<<hex<<x.A;
	cout<<hex<<x.B;
	cout<<hex<<x.C;
	cout<<hex<<x.D;
	cout<<hex<<x.E;
	
}


*/

/*
vernam cypher

#include<bits/stdc++.h>
using namespace std;

string decode(string cipherText, string key, int arr[]){
	string plainText = "";
	for(int i=0; i<cipherText.size(); i++){
		
		plainText += (arr[i] ^ key[i]-'a')%26 + 'a';
	}
	return plainText;
}
string encode(string plainText, string key, int arr[]){
	string cipherText = "";
	for(int i=0; i<plainText.size(); i++){
		int x = plainText[i]-'a' ^ key[i]-'a';
		arr[i] = x;
		cipherText += (x)%26 +'a';
	}
	return cipherText;
}

int main(){
	string plainText, key, cipherText;
	cout<<"Input the plainText: ";
	cin>>plainText;
	cout<<"Input the Key equal to the length of plaintext: ";
	cin>>key;
	while(key.size()!=plainText.size()){
		cout<<"\nInvalid key please enter size equal to the plainText: ";
		cin>>key;
	}
	int arr[plainText.size()] = {0};
	cipherText = encode(plainText,key,arr);
	
	cout<<"This is the cipher text using Vernam cipher: "<<cipherText;
	
	
	string decodedString = decode(cipherText, key,arr);
	cout<<"\nThis is the plainText obtained via decryption: "<<decodedString;
	
}

*/

/*
vignere
#include<bits/stdc++.h>
using namespace std;

string decode(string cipherText, string key, int table[26][26]){
	string transformedKey = "";
	for(int i=0; i<cipherText.size(); i++){
		transformedKey += key[i%key.size()];
	}
	string plainText = "";
	for(int i=0; i<cipherText.size(); i++){
		int index=0;
		for(int j=0; j<26; j++){
			if(table[transformedKey[i]-'a'][j]==cipherText[i]-'a'){
				index = j;
				break;
			}
		}
		plainText +=  (char)index + 'a';
	}
	return plainText; 
}

string encode(string plainText, string key, int table[26][26]){
	string transformedKey = "";
	for(int i=0; i<plainText.size(); i++){
		transformedKey += key[i%key.size()];
	}
	string cipherText="";
	for(int i=0; i<plainText.size(); i++){
		cipherText += table[transformedKey[i]-'a'][plainText[i]-'a'] + 'a';
	}
	return cipherText;
}

int main(){
	int table[26][26];
	for(int i=0; i<26; i++){
		for(int j=0; j<26; j++){
			table[i][j] = (i+j)%26;
		}
	}
	
	string plainText,key;
	cout<<"Input the plainText: ";
	cin>>plainText;
	cout<<"Input the key: ";
	cin>>key;
	string cipherText = encode(plainText, key, table);
	cout<<"This is the cipher text using vigenere cipher: "<<cipherText;
	string decoded = decode(cipherText, key, table);
	cout<<"\nRetriving plain text after decryption of cipher text: "<<decoded;
}


*/